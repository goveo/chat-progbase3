#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "network.h"
#include "dialog.h"
#include "settings.h"
#include "profile.h"
#include "contacts.h"
#include "privatechat.h"
#include "changeip.h"

//#include <QTcpServer>
#include <QTcpSocket>
#include <QTime>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include <QCloseEvent>

MainWindow::MainWindow(const QString strHost, int nPort, QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow), nextBlockSize(0)
{
    ui->setupUi(this);
    this->setWindowTitle("Client");

    thisSocket = new QTcpSocket(this);

    serverIp = strHost;
    serverPort = nPort;

    qDebug() << "serverIp : " << serverIp;
    qDebug() << "serverPort : " << serverPort;
    thisSocket->connectToHost(serverIp, serverPort);

    connect(thisSocket, SIGNAL(connected()), SLOT(slotConnected()));
    connect(thisSocket, SIGNAL(readyRead()), SLOT(slotReadyRead()));
    connect(thisSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slotError(QAbstractSocket::SocketError)));

    messageBox = new QTextEdit;
    messageBox = this->findChild<QTextEdit*>("textEdit");
    inputLine = new QLineEdit;
    inputLine = this->findChild<QLineEdit*>("messageLineEdit");

    ui->sendButton->setEnabled(false);

    QLabel * ipLabel = this->findChild<QLabel*>("ipLabel");
    QString textIp = serverIp + ":" + QString::number(serverPort);
    ipLabel->setText(textIp);

    messageBox->setReadOnly(true);
    resetCheck = false;
}

MainWindow::~MainWindow() {
    qDebug() << "exit";
    delete inputLine;
    delete messageBox;
    delete ui;
}

void MainWindow::slotReadyRead() {
    QDataStream in(thisSocket);
    in.setVersion(QDataStream::Qt_4_2);
    while(true) {
        if (!nextBlockSize) {
            if (thisSocket->bytesAvailable() < (int)sizeof(quint16)) {
                break;
            }
            in >> nextBlockSize;
        }
        if (thisSocket->bytesAvailable() < nextBlockSize) {
            break;
        }

        QString messageText;
        int command;
        in >> command;

        switch (command) {
            case setUsernameToWidget: {
                in >> usernamesList;
                ui->usersOnlineWidget->clear();
                for (int index = 0; index < usernamesList.size(); index++) {
                    if (usernamesList.at(index) != "" || usernamesList.at(index) != NULL) {
                        ui->usersOnlineWidget->addItem(usernamesList.at(index));
                    }
                }
                qDebug() << "usernames recieved";
                break;
            }
            case sendUserInfo: {
                in >> messageText;
                messageBox->append(messageText);
                break;
            }
            case getMyInfoFromDatabase: {
                in >> userInfo.name
                   >> userInfo.age
                   >> userInfo.country
                   >> userInfo.info
                   >> userInfo.phone
                   >> userInfo.email;
                qDebug() << userInfo.age
                         << userInfo.country
                         << userInfo.info
                         << userInfo.name
                         << userInfo.phone
                         << userInfo.email;
                break;
            }
            case getUserInfoFromDatabase: {
                in >> anotherUserInfo.name
                   >> anotherUserInfo.age
                   >> anotherUserInfo.country
                   >> anotherUserInfo.info
                   >> anotherUserInfo.phone
                   >> anotherUserInfo.email;
                qDebug() << "anotherUserInfo : "
                         << anotherUserInfo.age
                         << anotherUserInfo.country
                         << anotherUserInfo.info
                         << anotherUserInfo.name
                         << anotherUserInfo.phone
                         << anotherUserInfo.email;
                break;
            }
            case sendMessage: {
                in >> messageText;
                messageBox->append(messageText);
                break;
            }
            case getContactsFromDatabase: {
                in >> contactsList >> requestedContactsByMeList >> requestedContactsList;
                for (int index = 0; index < contactsList.size(); index++) {
                    qDebug() << "contactsList : " << contactsList.at(index);
                }
                break;
            }
            case openPrivateChat: {
                qDebug() << "openPrivateChat";
                in >> messageText >> privateChatUser;
                qDebug() << "messageText : " << messageText;
                qDebug() << "user.username : " << user.username;
                qDebug() << "privateChatUser : " << privateChatUser;

                PrivateChat chat(user.username, privateChatUser, thisSocket);
                chat.exec();
                break;
            }
            case privateChatUserIsOffline: {
                QString anotherUser;
                in >> anotherUser;
                QString message = "Can't open chat, " + anotherUser + " is offline.";
                messageBox->append(message);
                break;
            }
            case receivePrivateMessage: {
                qDebug() << "receivePrivateMessage was received!";
                in >> messageText >> privateChatUser;
                qDebug() << "private message from mainwindow" << messageText;
                messageBox->append(messageText);
                break;
            }
            case setLogMessage: {
                QString message;
                in >> message;
                messageBox->append(message);
                break;
            }
            case changePassword: {
                QString message;
                in >> message;
                messageBox->append(message);
                break;
            }
            default : {
                nextBlockSize = 0;
                break;
            }
        }

        nextBlockSize = 0;
        qDebug() << "message from server was readed, command = " << command;
    }
}

void MainWindow::slotError(QAbstractSocket::SocketError err) {
    QString strError =
        "[ERROR : " + (err == QAbstractSocket::HostNotFoundError ?
                     "The host was not found]" :
                     err == QAbstractSocket::RemoteHostClosedError ?
                     "The remote host is closed]" :
                     err == QAbstractSocket::ConnectionRefusedError ?
                     "The connection was refused]" :
                     QString(thisSocket->errorString())
                    );
    messageBox->append(strError);
}

void MainWindow::sendCommandToServer(int command) {
    qDebug() << "slotSendToServer(int command) started ; \n\n command = " << command << "\n";
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    fillStreamClient(command, &out, user);

    if (command == sendMessage) {
        QString messageText = this->inputLine->text();
        this->inputLine->setText("");
        out << quint16(0) << command << user.username << messageText;
    }
    if (command == deleteContactFromDatabase) {
        qDebug() << "deleteContactFromDatabase sended";
        out << quint16(0) << command << user.username << deletedContact;
    }

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    thisSocket->write(arrBlock);

    qDebug() << "message sended to server";
}

void MainWindow::slotConnected() {
    messageBox->append("[You connected to chat]");
    sendCommandToServer(getMyInfoFromDatabase);
}

void MainWindow::on_sendButton_clicked() {
    if (ui->messageLineEdit->text() != "") {
        sendCommandToServer(sendMessage);
    }
}

void MainWindow::on_messageLineEdit_returnPressed() {
    if (ui->messageLineEdit->text() != "") {
        sendCommandToServer(sendMessage);
    }
}

void MainWindow::setUser(User temp) {
    user = temp;
    QLabel * usernameLabel = this->findChild<QLabel*>("usernameLabel");
    usernameLabel->setText(user.username);
    sendCommandToServer(setName);
}

void MainWindow::on_settingsButton_clicked()
{
    qDebug() << "settingsButton_clicked";
    Settings st(thisSocket, user.username, user.password);
    st.setInfo(userInfo);
    st.exec();
}

void MainWindow::on_settingsButton_pressed()
{
    qDebug() << "settingsButton_pressed";
    sendCommandToServer(getMyInfoFromDatabase);
}

void MainWindow::on_usersOnlineWidget_itemDoubleClicked(QListWidgetItem *item)
{
    qDebug() << "item doubleclicked";
//    qDebug() << "anotheruser : " << anotherUserInfo.name << anotherUserInfo.age;
    item->setSelected(false);
    QString username = item->text();

    QString command;
    if (isRequestedByMe(username) == true) {
        command = "requestedByMe";
    } else if (isRequestedMe(username) == true) {
        command = "requestedMe";
    } else {
        command = "isNotContact";
    }

    bool isOnline = checkIsUserOnline(username);

    Profile profile(user.username,
                    username,
                    anotherUserInfo.name,
                    anotherUserInfo.age,
                    anotherUserInfo.country,
                    anotherUserInfo.info,
                    anotherUserInfo.phone,
                    anotherUserInfo.email,
                    thisSocket,
                    contactsList,
                    isOnline,
                    command
                   );
    profile.exec();
    if (profile.close()) {
        if (profile.isAccepted() == true) {
            if (profile.isNotDeletedFromContacts() == false) {
                deletedContact = username;
                sendCommandToServer(deleteContactFromDatabase);
                deletedContact = "";
            }
        }
    }
}

void MainWindow::on_usersOnlineWidget_itemPressed(QListWidgetItem *item)
{
    sendCommandToServer(getContactsFromDatabase);
    item->setSelected(false);
    contact = item->text();
    qDebug() << "username : " << contact;
    int command = getUserInfoFromDatabase;
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out << quint16(0) << command << contact;
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    thisSocket->write(arrBlock);
}

void MainWindow::on_contactsButton_pressed()
{
    sendCommandToServer(getContactsFromDatabase);
    qDebug() << "contacts pressed";
}

void MainWindow::on_contactsButton_released()
{
    Contacts contacts(thisSocket);
    contacts.setContacts(contactsList);
    contacts.exec();
    qDebug() << "released";
    if (contacts.close()) {
        qDebug() << "contacts.isAccepted() : " << contacts.isAccepted();
        if (contacts.isAccepted() == true) {
            QListWidgetItem * selectedContact = contacts.getSelectedContact();
            QString username = selectedContact->text();
            qDebug() << "anotheruser : " << anotherUserInfo.name << anotherUserInfo.age;

            QString command;
            if (isRequestedByMe(username) == true) {
                command = "requestedByMe";
            } else if (isRequestedMe(username) == true) {
                command = "requestedMe";
            } else {
                command = "isNotContact";
            }

            bool isOnline = checkIsUserOnline(username);
            Profile profile(user.username,
                            username,
                            anotherUserInfo.name,
                            anotherUserInfo.age,
                            anotherUserInfo.country,
                            anotherUserInfo.info,
                            anotherUserInfo.phone,
                            anotherUserInfo.email,
                            thisSocket,
                            contactsList,
                            isOnline,
                            command
                           );
            profile.exec();
            if (profile.close()) {
                if (profile.isNotDeletedFromContacts() == false) {
                    deletedContact = username;
                    sendCommandToServer(deleteContactFromDatabase);
                    deletedContact = "";
                }
            }
        }
    }
}

void MainWindow::on_messageLineEdit_textChanged(const QString &text)
{
    if (text == "") {
        ui->sendButton->setEnabled(false);
    } else {
        ui->sendButton->setEnabled(true);
    }
}

void MainWindow::on_changeIpButton_clicked()
{
    ChangeIp changeIp(serverIp, serverPort);
    changeIp.exec();

    if (changeIp.close()) {
        resetCheck = changeIp.getResetCheck();
        if (resetCheck == true) {
            this->close();
        }
        qDebug() << "resetCheck = " << resetCheck;
    }
}

bool MainWindow::isRequestedByMe(QString username) {
    for (int i = 0; i < requestedContactsByMeList.size(); i++) {
        if (username == requestedContactsByMeList.at(i)) {
            return true;
        }
    }
    return false;
}

bool MainWindow::isRequestedMe(QString username) {
    for (int i = 0; i < requestedContactsList.size(); i++) {
        if (username == requestedContactsList.at(i)) {
            return true;
        }
    }
    return false;
}


void MainWindow::on_MainWindow_destroyed()
{
    qDebug() << "application closed";
}

bool MainWindow::getResetCheck() {
    return resetCheck;
}

bool MainWindow::checkIsUserOnline(QString username) {
    int index = usernamesList.indexOf(username);
    if (index == -1) {
        return false;
    }
    return true;
}
