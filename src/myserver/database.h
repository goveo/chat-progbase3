#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <QString>
#include "network.h"

class database
{
public:
    bool driverAvailable();
    bool newDatabase();

    bool createUserTable();
    bool createInfoTable();
    bool createContactsTable();

    bool setUsernameAndPassword(QString username, QString password);
    bool checkUsernameUnique(QString username, QString password);
    bool singIn(QString username, QString password);

    bool addContact(QString username, QString contact);
    QList<QString> getContacts(QString username);
    QList<QString> getRequests(QString contact);
    bool isContacts(QString username, QString contact);
    bool deleteContact(QString username, QString contact);

    bool addUserInfo(QString username, QString name, int age, QString country, QString info, QString phone, QString email);
    bool getUserInfo(QString username, UserInfo * usrInf);

    bool changePassword(QString username, QString newPassword);
};

#endif // DATABASE_H
