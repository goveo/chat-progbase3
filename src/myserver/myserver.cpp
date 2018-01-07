#include <QTcpServer>
#include <QMessageBox>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QTcpSocket>
#include <QTime>
#include <QFile>

#include "myserver.h"
#include "network.h"
#include "database.h"

MyServer::MyServer(int nPort, QWidget* pwgt) : QWidget(pwgt), nextBlockSize(0)
{
    thisServer = new QTcpServer(this);
    if (!thisServer->listen(QHostAddress::AnyIPv4, nPort)) {
        QMessageBox::critical(0,
                              "Server Error",
                              "Unable to start the server:"
                              + thisServer->errorString()
                             );
        thisServer->close();
        return;
    }
    connect(thisServer, SIGNAL(newConnection()), this, SLOT(slotNewConnection())); //connect signal newConnection to slot

    offlineSocket = (QTcpSocket*)sender();

    textBox = new QTextEdit;                                                       // set textBox
    textBox->setReadOnly(true);

    db.newDatabase();
    db.createUserTable();                                                          //CREATE A DATABASE AND ALL TABLES
    db.createInfoTable();
    db.createContactsTable();

    qDebug() << "server is started!";

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(new QLabel("<H1>Server</H1>"));
    pvbxLayout->addWidget(textBox);
    setLayout(pvbxLayout);
    textBox->append("Server started!");
}

void MyServer::slotNewConnection()
{
    while (thisServer->hasPendingConnections()) {
        QTcpSocket* pClientSocket = thisServer->nextPendingConnection();
        connect(pClientSocket, SIGNAL(readyRead()), this, SLOT(slotReadClient()));
        connect(pClientSocket, SIGNAL(disconnected()), this, SLOT(slotClientDisconnected()));
        clientsList.push_back(pClientSocket);
        QString username = "";
        usernamesList.push_back(username);
    }
}

void MyServer::slotClientDisconnected()
{
    QTcpSocket * pClientSocket = static_cast<QTcpSocket*>(QObject::sender());
    int index = clientsList.indexOf(pClientSocket);
    if (usernamesList.at(index) != "") {
        QString message = "[" + QTime::currentTime().toString() + "] " + usernamesList.at(index) + " disconnected";
        broadcast(sendMessage, message);
        textBox->append(message);
    }
    clientsList.removeAt(index);                            //remove from list
    usernamesList.removeAt(index);
    broadcast(setUsernameToWidget, "");
}

void MyServer::slotReadClient()
{
    QTcpSocket* pClientSocket = (QTcpSocket*)sender();
    QDataStream in(pClientSocket);
    in.setVersion(QDataStream::Qt_4_2);
    while(true) {
        if (!nextBlockSize) {
            if (pClientSocket->bytesAvailable() < (int)sizeof(quint16)) {    //need to read all bytes
                break;
            }
            in >> nextBlockSize;
        }
        if (pClientSocket->bytesAvailable() < nextBlockSize) {       //need to read all bytes
            break;
        }

        int command;
        QString username;
        in >> command >> username;                                      //recieve a command
        qDebug() << "command = " << command;

        switch (command) {
            case setName: {
                QString password;
                in >> password;
                if (username != "") {
                    db.setUsernameAndPassword(username, password);
                    QTcpSocket * pClientSocket = static_cast<QTcpSocket*>(QObject::sender());   //set username to list
                    int index = clientsList.indexOf(pClientSocket);
                    usernamesList.removeAt(index);
                    usernamesList.insert(index, username);
                    qDebug() << "Username and password was setted";
                }
                break;
            }
            case sendMessage: {
                QString messageText;
                in >> messageText;
                QString strMessage = "[" + QTime::currentTime().toString() + "] " + username + ": " + messageText;
                qDebug()<< "strMessage : " << strMessage;
                textBox->append(strMessage);
                broadcast(sendMessage, strMessage);
                break;
            }
            case userConnected: {
                QString message = "[" + QTime::currentTime().toString() + "]" + " " + username + " connected to room!";
                broadcast(setUsernameToWidget, "");
                textBox->append(message);
                broadcast(sendMessage, message);

                UserInfo userInfo;
                if (db.getUserInfo(username, &userInfo) == true) {
                    if (userInfo.name == "") {
                        message = "[Hello.]\n[Looks like you just registered.]\n[Go to settings and fill your profile.]";
                        sendToClient(pClientSocket, message, setLogMessage);
                    }
                }


                break;
            }
            case sendUserToServer: {
                QString password;
                in >> password;
                QString message;
                if (db.checkUsernameUnique(username, password) == true) {
                    message = "login";
                    qDebug() << "db answered 'login'";
                    sendToClient(pClientSocket, message, database_logined);
                } else {
                    message = "wrongUsernameOrPassword";
                    qDebug() << "db answered 'wrongUsernameOrPassword'";
                    sendToClient(pClientSocket, message, database_wrongPassword);
                }
                break;
            }
            case sendUserToServerSignup: {
                QString password;
                in >> password;
                QString message;
                if (db.singIn(username, password) == true) {
                    message = "login";
                    qDebug() << "db answered 'login'";
                    sendToClient(pClientSocket, message, database_logined);
                } else {
                    message = "wrongUsernameOrPassword";
                    qDebug() << "db answered 'wrongUsernameOrPassword'";
                    sendToClient(pClientSocket, message, database_wrongUsername);
                }
                break;
            }
            case sendUserInfo: {
                QString message = "[Settings saved]";
                QString name;
                int age;
                QString country;
                QString info;
                QString phone;
                QString email;
                in >> name >> age >> country >> info >> phone >> email;
                if (db.addUserInfo(username, name, age, country, info, phone, email) == true) {
                    qDebug() << "////////////////////////////////db answered addUserInfo";
                    sendToClient(pClientSocket, message, command);
                }
                break;
            }
            case getMyInfoFromDatabase: {
                UserInfo userInfo;
                if (db.getUserInfo(username, &userInfo) == true) {
                    qDebug() << "db answered 'info getted'";
                    sendUserInfoToClient(pClientSocket,
                                         command,
                                         userInfo.name,
                                         userInfo.age,
                                         userInfo.country,
                                         userInfo.info,
                                         userInfo.phone,
                                         userInfo.email
                                        );
                }
                qDebug() << "db answered 'INFO NOT GETTED'";
                break;
            }
            case getUserInfoFromDatabase: {
                UserInfo userInfo;
                if (db.getUserInfo(username, &userInfo) == true) {
                    qDebug() << "db answered 'info getted'";
                    sendUserInfoToClient(pClientSocket,
                                         command,
                                         userInfo.name,
                                         userInfo.age,
                                         userInfo.country,
                                         userInfo.info,
                                         userInfo.phone,
                                         userInfo.email
                                        );
                }
                qDebug() << "db answered 'INFO NOT GETTED'";
                break;
            }
            case getContactsFromDatabase: {
                contactsList = getContactsList(username);
                sendToClient(pClientSocket, "", command);
                break;
            }
            case deleteContactFromDatabase: {
                QString contact;
                in >> contact;
                db.deleteContact(username, contact);
                db.deleteContact(contact, username);
                break;
            }
            case getOnlineUsers: {
                QString password;
                in >> password;
                sendToClient(pClientSocket, "", command);
                for (int i = 0; i < usernamesList.size(); i++) {
                    qDebug() << "user #" << i << " " << usernamesList.at(i);
                }
                break;
            }
            case sendPrivateMessage: {
                QString message;
                thisUser = username;
                in >> anotherUser >> message;

                QTcpSocket * anotherUserSocket = findSocketByUsername(anotherUser);
                privateUser = thisUser;
                QString strMessage = "[" + QTime::currentTime().toString() + "] " + thisUser + " <private to " + anotherUser + ">: " + message;
                sendToClient(pClientSocket, strMessage, receivePrivateMessage);
                privateUser = anotherUser;
                strMessage = "[" + QTime::currentTime().toString() + "] " + "<private from> " + thisUser + ": " + message;
                sendToClient(anotherUserSocket, strMessage, receivePrivateMessage);

                QString serverLogMessage = username + " sended to " + anotherUser + " private message : " + strMessage;
                textBox->append(serverLogMessage);
                qDebug() << serverLogMessage;
                break;
            }
            case openPrivateChat: {
                thisUser = username;
                in >> anotherUser;
                if (checkIsUserOnline(anotherUser) == false) {
                    sendToClient(pClientSocket, "", privateChatUserIsOffline);
                    qDebug() << "privateChatUserIsOffline 1 sended";
                } else {
                    privateUser = anotherUser;
                    sendToClient(pClientSocket, "You was invited by" + thisUser + " to private chat ", openPrivateChat);
                    qDebug() << "openPrivateChat sended";

                    qDebug() << "thisUser : " << thisUser;
                    qDebug() << "anotherUser : " << anotherUser;
                }
                break;
            }
            case setLogMessage: {
                QString message;
                in >> message;
                sendToClient(pClientSocket, message, command);
                break;
            }
            case changePassword: {
                QString newPassword;
                in >> newPassword;
                if (db.changePassword(username, newPassword) == true) {
                    sendToClient(pClientSocket, "Password changed!", command);
                }
                break;
            }
            case sendContactRequest: {
                QString contactUsername;
                in >> contactUsername;
                if (db.addContact(username, contactUsername) == true) {
                     qDebug() << "db answered 'contacts added'";
                }
                QString message;
                if (requestedContactsList.contains(contactUsername)) {
                    message = "[" + username + " accepted your invite to contacts]";
                } else if (contactsList.contains(contactUsername)){
                    message = "[" + username + " deleted you from contacts]";
                } else {
                    message = "[" + username + " want add you to contacts]";
                }
                QTcpSocket * contactSocket = findSocketByUsername(contactUsername);
                sendToClient(contactSocket, message, setLogMessage);
                break;
            }
            default : {
                nextBlockSize = 0;
            }

        }
        nextBlockSize = 0;
    }
}

void MyServer::sendToClient(QTcpSocket* pSocket, const QString& str, int command)
{
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_2);

    out << quint16(0) << command;

    if (command == setUsernameToWidget) {
        out << usernamesList;
    } else if (command == getContactsFromDatabase) {
        out << contactsList << requestedContactsByMeList << requestedContactsList;
    } else if (command == getOnlineUsers) {
        out << str << usernamesList;
    } else if (command == receivePrivateMessage) {
        out << str << privateUser;
    } else if (command == openPrivateChat) {
        out << str << privateUser;
    } else if (command == privateChatUserIsOffline) {
        out << anotherUser;
    } else if (command == changePassword) {
        out << str;
    } else {
        out << str;
    }

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    pSocket->write(arrBlock);
}

void MyServer::broadcast(int command, QString str) {                         //send message to all clients
    for (int i = 0; i < clientsList.size(); ++i) {
        sendToClient(clientsList.at(i), str, command);
    }
}

void MyServer::sendUserInfoToClient(QTcpSocket* pSocket,
                                    int command,
                                    QString name,
                                    int age,
                                    QString country,
                                    QString info,
                                    QString phone,
                                    QString email
                                   )
{
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_2);
    out << quint16(0) << command << name << age << country << info << phone << email;
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    pSocket->write(arrBlock);
}

QTcpSocket * MyServer::findSocketByUsername(QString username) {
    int index = usernamesList.indexOf(username);
    qDebug() << "index : " << index;
    qDebug() << "clientsList.size() : " << clientsList.size();
    QTcpSocket * anotherUser;
    if (index >= clientsList.size() || index < 0) {
        return offlineSocket;
    } else {
        anotherUser = clientsList.at(index);
    }
    return anotherUser;
}

bool MyServer::checkIsUserOnline(QString username) {
    int index = usernamesList.indexOf(username);
    if (index == -1) {
        return false;
    }
    return true;
}

QList<QString> MyServer::getContactsList(QString username) {
    QList<QString> contacts;
    requestedContactsByMeList = db.getContacts(username);
    requestedContactsList = db.getRequests(username);

    QList<QString> toRemove;

    for (int i = 0; i < requestedContactsList.size(); i++) {
        for (int j = 0; j < requestedContactsByMeList.size(); j++) {
            if (requestedContactsList.at(i) == requestedContactsByMeList.at(j)) {
                contacts.push_back(requestedContactsList.at(i));
                toRemove.push_back(requestedContactsList.at(i));
            }
        }
    }

    for (int i = 0; i < toRemove.size(); i++) {
        requestedContactsList.removeOne(toRemove.at(i));
        requestedContactsByMeList.removeOne(toRemove.at(i));
    }

    return contacts;
}
