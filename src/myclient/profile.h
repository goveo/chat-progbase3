#ifndef PROFILE_H
#define PROFILE_H

#include <QDialog>
#include <QTcpSocket>
#include "network.h"

namespace Ui {
class Profile;
}

class Profile : public QDialog
{
    Q_OBJECT

public:
    explicit Profile(QString _myUsername,
                     QString _username,
                     QString name,
                     int age,
                     QString country,
                     QString info,
                     QString phone,
                     QString email,
                     QTcpSocket * socket,
                     QList<QString> contactsList,
                     bool isOnline,
                     QString command,
                     QWidget *parent = 0
                    );
    bool isNotDeletedFromContacts();
    bool isAccepted();
    void sendCommandToServer(int command);
    ~Profile();

private slots:
    void on_addToFriendsButton_clicked();

    void on_privateChatButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::Profile *ui;
    UserInfo userInfo;
    QString username;
    QString myUsername;
    QTcpSocket * thisSocket;
    bool removeFromContacts;
    bool accepted;
    bool isContact;
};

#endif // PROFILE_H
