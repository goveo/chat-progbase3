#include "database.h"
#include "network.h"
#include <string>
#include <QString>
#include <QFile>

#include <QTcpServer>
#include <QMessageBox>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QTcpSocket>
#include <QTime>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>

const QString DRIVER("QSQLITE");

bool database::driverAvailable() {
    if(!QSqlDatabase::isDriverAvailable(DRIVER)) {
        qDebug() << "sqlite not available";
        return false;
    }
    return true;
}

bool database::newDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
    db.setDatabaseName("/home/brusentsov/progbase3/src/myserver/database.sqlite3");
    if(!db.open()) {
        qDebug() << "ERROR: " << db.lastError();
        return false;
    }
    return true;
}

bool database::createUserTable() {
    QSqlQuery query("CREATE TABLE users (username STRING PRIMARY KEY, password TEXT)");
    if(!query.isActive()) {
        qWarning() << "ERROR: " << query.lastError().text();
        return false;
    }
    return true;
}

bool database::createInfoTable() {
    QSqlQuery query("CREATE TABLE info (username STRING PRIMARY KEY, name TEXT, age NUMBER, country TEXT, info TEXT, phone TEXT, email TEXT)");
    if(!query.isActive()) {
        qWarning() << "ERROR: " << query.lastError().text();
        return false;
    }
    return true;
}

bool database::createContactsTable() {
    QSqlQuery query("CREATE TABLE contacts (username TEXT, contact TEXT)");
    if(!query.isActive()) {
        qWarning() << "ERROR: " << query.lastError().text();
        return false;
    }
    return true;
}

bool database::setUsernameAndPassword(QString username, QString password) {
    QSqlQuery query;

    QString command = "INSERT INTO users (username, password) VALUES ('%1', '%2');";
    command = command.arg(username)
                     .arg(password);

    qDebug() << "command : " << command;

    if(!query.exec(command) || username == "" || password == "") {
        qWarning() << "ERROR SET USERNAME: " << query.lastError().text();
        return false;
    }
    return true;
}

bool database::checkUsernameUnique(QString username, QString password) {
    QString command = "SELECT password FROM users WHERE username = '%1'";
    command = command.arg(username);
    qDebug() << "command : " << command;
    bool login = false;
    QSqlQuery query(command);

    query.exec();
    query.next();
    qDebug() << "value :" << query.value(0).toString();
    QString dbPassword = query.value(0).toString();
    qDebug() << "username :" << username;
    qDebug() << "password :" << password;
    qDebug() << "db : " << dbPassword;

    if (password == dbPassword) {
        login = true;
    } else {
        login = false;
    }

    qDebug() << "login : " << login;
    return login;
}

bool database::singIn(QString username, QString password) {
    return setUsernameAndPassword(username, password);
}

bool database::addUserInfo(QString username, QString name, int age, QString country, QString info, QString phone, QString email) {
    QSqlQuery query;

    QString command = "INSERT INTO info (username, name, age, country, info, phone, email) VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7');";
    command = command.arg(username)
                     .arg(name)
                     .arg(age)
                     .arg(country)
                     .arg(info)
                     .arg(phone)
                     .arg(email);

    qDebug() << "database : " << command;
    query.exec(command);

    QString command2 = "UPDATE info SET name = '%1', age = '%2', country = '%3', info = '%4', phone = '%5', email = '%6' WHERE username = '%7'";
    command2 = command2.arg(name)
                       .arg(age)
                       .arg(country)
                       .arg(info)
                       .arg(phone)
                       .arg(email)
                       .arg(username);

    if(!query.exec(command2)) {
        qWarning() << "ERROR SET INFO!: " << query.lastError().text();
        return false;
    }

    return true;
}

bool database::getUserInfo(QString username, UserInfo * usrInf) {
    QString command = "SELECT name, age, country, info, phone, email FROM info WHERE username = '%1'";
    command = command.arg(username);
    qDebug() << "db/command : " << command;
    QSqlQuery query(command);
    if(!query.exec()) {
        qWarning() << "ERROR GET INFO!: " << query.lastError().text();
        return false;
    }
    query.next();
    usrInf->name = query.value(0).toString();
    usrInf->age = query.value(1).toInt();
    usrInf->country = query.value(2).toString();
    usrInf->info = query.value(3).toString();
    usrInf->phone = query.value(4).toString();
    usrInf->email = query.value(5).toString();
    return true;
}

bool database::addContact(QString username, QString contact) {
    QSqlQuery query;

    QString command = "INSERT INTO contacts (username, contact) VALUES ('%1', '%2');";
    command = command.arg(username)
                     .arg(contact);

    qDebug() << "command : " << command;

    if(!query.exec(command)) {
        qWarning() << "ERROR SET FRIEND: " << query.lastError().text();
        return false;
    }
    return true;
}

bool database::isContacts(QString username, QString contact) {
    QSqlQuery query;

    QString command = "SELECT username, contact FROM contacts WHERE username = '%1' AND contact = '%2'";
    command = command.arg(username)
                     .arg(contact);

    qDebug() << "command : " << command;

    query.prepare(command);
    if (!query.exec() || !query.first()) {
       qDebug() << "/////ERROR";
       qDebug() << query.lastError().text();
    }
    else if (query.value(0) == 0) {
        qDebug() << "/////query1.value(0) == 0";
    }
    else {
        return true;
    }
    return false;
}

QList<QString> database::getContacts(QString username) {
    QSqlQuery query1;
    QList<QString> contacts;

    QString command = "SELECT contact FROM contacts WHERE username = '%1'";
    command = command.arg(username);

    qDebug() << "command : " << command;

    query1.prepare(command);
    if (!query1.exec() || !query1.first()) {
       qDebug() << "/////ERROR";
       qDebug() << query1.lastError().text();
    }
    else if (query1.value(0) == 0) {
        qDebug() << "/////query1.value(0) == 0";
    }
    else {
        qDebug() << "/////at least one corresponding record was found";
        contacts.push_back(query1.value(0).toString());
        while (query1.next()) {
            contacts.push_back(query1.value(0).toString());
        }
    }

    return contacts;
}

QList<QString> database::getRequests(QString contact) {
    QSqlQuery query1;
    QList<QString> contacts;

    QString command = "SELECT username FROM contacts WHERE contact = '%1'";
    command = command.arg(contact);

    qDebug() << "command : " << command;

    query1.prepare(command);
    if (!query1.exec() || !query1.first()) {
       qDebug() << "/////ERROR";
       qDebug() << query1.lastError().text();
    }
    else if (query1.value(0) == 0) {
        qDebug() << "/////query1.value(0) == 0";
    }
    else {
        qDebug() << "/////at least one corresponding record was found";
        contacts.push_back(query1.value(0).toString());
        while (query1.next()) {
            contacts.push_back(query1.value(0).toString());
        }
    }
    return contacts;
}

bool database::deleteContact(QString username, QString contact) {
    QSqlQuery query;

    QString command = "DELETE FROM contacts WHERE contact='%1' AND username='%2'";
    command = command.arg(contact)
                     .arg(username);

    qDebug() << "command : " << command;

    if(!query.exec(command)) {
        qWarning() << "ERROR deleteContact: " << query.lastError().text();
        return false;
    }
    return true;
}

bool database::changePassword(QString username, QString newPassword) {
    QSqlQuery query;
    QString command = "UPDATE users SET password = '%1' WHERE username = '%2'";
    command = command.arg(newPassword)
                     .arg(username);

    qDebug() << "command : " << command;

    if(!query.exec(command)) {
        qWarning() << "ERROR SET INFO!: " << query.lastError().text();
        return false;
    }

    return true;
}
