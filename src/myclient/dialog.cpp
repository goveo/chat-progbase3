#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "network.h"
#include "changeip.h"

Dialog::Dialog(const QString& strHost, int nPort, QWidget *parent) :
    QDialog(parent), ui(new Ui::Dialog), nextBlockSize(0)
{
    ui->setupUi(this);

    serverIp = strHost;
    serverPort = nPort;

    resetCheck = false;

    dialogSocket = new QTcpSocket(this);
    dialogSocket->connectToHost(serverIp, serverPort);

    connect(dialogSocket, SIGNAL(connected()), SLOT(slotConnected()));
    connect(dialogSocket, SIGNAL(readyRead()), SLOT(readInfoFromServer()));
    connect(dialogSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slotError()));

    errorLabel = this->findChild<QLabel*>("errorLabel");

    isUserUnique = false;

    loginStatus = false;
    _finished = false;

    QString ipText = strHost + ":" + QString::number(nPort);
    ui->ipLabel->setText(ipText);

    QRegExp rx ("[A-Za-z0-9_]{0,255}");                                     //set regular expression
    ui->usernameLineEdit->setValidator (new QRegExpValidator (rx, this));
    ui->passwordLineEdit->setValidator (new QRegExpValidator (rx, this));

    ui->passwordLineEdit->setFocus();
    ui->usernameLineEdit->setFocus();
}

Dialog::~Dialog() {
    delete ui;
}

void Dialog::slotError() {
    ui->errorLabel->setText("Server is offline");
}

void Dialog::slotConnected() {
    qDebug() << "connected with server";
}

void Dialog::on_loginButton_clicked() {
    qDebug() << "clicked";
    QLineEdit * usernameEdit = Dialog::findChild<QLineEdit*>("usernameLineEdit");
    QLineEdit * passwordEdit = Dialog::findChild<QLineEdit*>("passwordLineEdit");
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();
    qDebug() << "username : " << username;
    qDebug() << "password : " << password;
    sendToServer(getOnlineUsers);
    user.username = username;
    user.password = password;

    if (username == "" || password == "") {
        errorLabel->setText("Some fields are empty!");
    } else if (!ui->checkBox->isChecked()) {
        sendToServer(sendUserToServer);
    } else {
        sendToServer(sendUserToServerSignup);
    }

    qDebug() << "sended to server";
}

void Dialog::openDialog() {
    Dialog::setWindowTitle("Log in");
    Dialog::exec();
    qDebug() << "\n\nloginStatus : " << loginStatus << "\n";
}

void Dialog::closeDialog() {
    Dialog::accept();
}

void Dialog::sendToServer(int command) {
    qDebug() << "'sendUserToServer'";
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);

    out << quint16(0) << command << user.username << user.password;

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    dialogSocket->write(arrBlock);

    qDebug() << "message sended to server";
}

void Dialog::readInfoFromServer() {
    QDataStream in(dialogSocket);
    in.setVersion(QDataStream::Qt_4_2);
    while(true) {
        if (!nextBlockSize) {
            if (dialogSocket->bytesAvailable() < (int)sizeof(quint16)) {
                break;
            }
            in >> nextBlockSize;
        }
        if (dialogSocket->bytesAvailable() < nextBlockSize) {
            break;
        }

        int command;
        QString message;
        in >> command >> message;

        if (command == database_logined) {
            if (isUserUnique == true) {
                loginStatus = true;
                _finished = true;
                this->closeDialog();
            }
        }
        if (command == database_wrongPassword) {
            errorLabel->setText("Wrong username or password!");
            qDebug() << "database_wrongPassword message setted";
        }
        if (command == getOnlineUsers) {
            QList<QString> users;
            in >> users;
            qDebug() << "usersize : " << users.size();
            for (int i = 0; i < users.size(); i++) {
                qDebug() << "user #" << i << " " << users.at(i);
            }
            if (checkUserUnique(users, user.username) == true) {
                isUserUnique = true;
            } else {
                ui->errorLabel->setText("You are already logined");
                isUserUnique = false;
            }
            usersOnline = users;
            qDebug() << "isUserUnique : " << isUserUnique;
        }
        nextBlockSize = 0;
        qDebug() << "message from server was readed";
    }
}

void Dialog::setUser(User temp) {
    user = temp;
}

User Dialog::getUser() {
    return user;
}

void Dialog::on_checkBox_clicked() {
    if (ui->checkBox->isChecked()) {
        ui->loginButton->setText("Sign up");
    } else {
        ui->loginButton->setText("Login");
    }
}

void Dialog::on_Dialog_rejected() {
    loginStatus = false;
    _finished = true;
}

bool Dialog::checkUserUnique(QList<QString> users, QString user) {
    for (int i = 0; i < users.size(); i++) {
        if (users.at(i) == user) {
            return false;
        }
    }
    return true;
}

void Dialog::on_loginButton_pressed() {
    qDebug() << "pressed";
}

bool Dialog::finished() {
    return _finished;
}

bool Dialog::isLogined() {
    return loginStatus;
}

void Dialog::on_pushButton_clicked()
{
    ChangeIp changeIp(serverIp, serverPort);
    changeIp.exec();

    if (changeIp.close()) {
        resetCheck = changeIp.getResetCheck();
        serverIp = changeIp.getIp();
        serverPort = changeIp.getPort();
        if (resetCheck == true) {
            qDebug() << "//////serverIp = " << serverIp;
            qDebug() << "//////serverPort = " << serverPort;
            this->close();
        }
        qDebug() << "resetCheck = " << resetCheck;
    }
}

bool Dialog::getResetCheck() {
    return resetCheck;
}

QString Dialog::getIp() {
    return serverIp;
}

int Dialog::getPort() {
    return serverPort;
}
