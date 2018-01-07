#include "privatechat.h"
#include "ui_privatechat.h"
#include "network.h"

#include <QTcpSocket>

PrivateChat::PrivateChat(QString username, QString anotherUser, QTcpSocket * socket, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrivateChat),
    nextBlockSize(0)
{
    ui->setupUi(this);
    thisSocket = socket;

    qDebug() << "///username : " << username;
    qDebug() << "///anotherUser : " << anotherUser;

    this->username = username;
    this->anotherUsername = anotherUser;

    QString title = "Private message to " + anotherUser;
    this->setWindowTitle(title);
    QString logMessage = "Send private message to " + anotherUser + " :";
    ui->text_send->setText(logMessage);
}

PrivateChat::~PrivateChat()
{
    delete ui;
}

void PrivateChat::on_sendButton_clicked()
{
    sendCommandToServer(sendPrivateMessage);
    ui->messageLineEdit->clear();
    this->close();
}

void PrivateChat::sendCommandToServer(int command) {
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);

    if (command == sendPrivateMessage) {
        out << quint16(0)
            << command
            << username
            << anotherUsername
            << ui->messageLineEdit->text();
    }

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    thisSocket->write(arrBlock);
    qDebug() << command << " sended to server";
}

//void PrivateChat::readyRead() {
//    QDataStream in(thisSocket);
//    in.setVersion(QDataStream::Qt_4_2);
//    while(true) {
//        if (!nextBlockSize) {
//            if (thisSocket->bytesAvailable() < (int)sizeof(quint16)) {
//                break;
//            }
//            in >> nextBlockSize;
//        }
//        if (thisSocket->bytesAvailable() < nextBlockSize) {
//            break;
//        }

//        int command;
//        in >> command;

//        if (command == receivePrivateMessage) {
//            qDebug() << "receivePrivateMessage was received!";
//            QString message;
//            in >> message >> anotherUsername;
//            PrivateChat chat(username, anotherUsername, thisSocket);
//            chat.exec();
//        }

//        nextBlockSize = 0;
//        qDebug() << "message from server was readed";
//    }
//}
