#ifndef NETWORK_H
#define NETWORK_H

#include <QString>
#include <QtCore/QCoreApplication>
#include <QDataStream>
#include <QByteArray>
#include <QFile>
#include <QString>
#include <QHash>
#include <QDebug>

enum A : int {
    sendMessage,
    setName,
    userConnected,
    setUsernameToWidget,
    checkInDatabase,
    sendUserToServer,
    sendUserToServerSignup,
    database_logined,
    database_wrongUsername,
    database_wrongPassword,
    sendUserInfo,
    getMyInfoFromDatabase,
    getUserInfoFromDatabase,
    addContactToDatabase,
    getContactsFromDatabase,
    deleteContactFromDatabase,
    getOnlineUsers,
    sendPrivateMessage,
    receivePrivateMessage,
    openPrivateChat,
    privateChatUserIsOffline,
    changePassword,
    setLogMessage,
    sendContactRequest
    //another comands
};

struct User {
    QString username;
    QString password;
};

struct UserInfo {
    QString name;
    int age;
    QString country;
    QString info;
    QString phone;
    QString email;
};

void fillStreamClient(int command, QDataStream * out, User user);
QString readIpFromFile();
void writeIpToFile(QString ipText);

#endif // NETWORK_H
