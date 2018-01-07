#include "network.h"

#include <QTcpServer>
#include <QTcpSocket>
#include <QTime>
#include <QDebug>

void fillStreamClient(int command, QDataStream * out, User user) {
    //out->setVersion(QDataStream::Qt_4_2);
    if (command == setName) {                                              // set data into database
        *out << quint16(0) << command << user.username << user.password;   // give command to server
        qDebug() << "'setName' command sended";
    }

    if (command == sendMessage) {                                          //send message
        qDebug() << "'sendMessage' command sended";
    }

    if (command == userConnected) {
        *out << quint16(0) << command << user.username;
        qDebug() << "'userConnected' command sended";
    }

    if (command == checkInDatabase) {
        *out << quint16(0) << command << user.username << user.password;
        qDebug() << "'checkInDatabase' command sended";
    }

    if (command == getMyInfoFromDatabase) {
        *out << quint16(0) << command << user.username;
        qDebug() << "'getInfoFromDatabase' command sended";
    }

    if (command == getContactsFromDatabase) {
        *out << quint16(0) << command << user.username;
        qDebug() << "'getContactsFromDatabase' command sended";
    }
}

QString readIpFromFile() {
    QString filename = "ip.txt";
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream in(&file);
        return in.readLine();
    }
//    file.close();
    return "error";
}

void writeIpToFile(QString ipText) {
    QString filename = "ip.txt";
    QFile file(filename);
    file.resize(0);
    QTextStream stream(&file);
    if (file.open(QIODevice::ReadWrite)) {
        stream << ipText << endl;
    } else {
        stream << "127.0.0.1:2323";
    }
//    file.close();
}
