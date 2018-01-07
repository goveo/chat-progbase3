#ifndef MYSERVER_H
#define MYSERVER_H

#include <QWidget>
#include <QList>
#include "network.h"
#include "database.h"

class QTcpServer;
class QTextEdit;
class QTcpSocket;

class MyServer : public QWidget {
Q_OBJECT
private:
    QTcpServer * thisServer;
    QTextEdit * textBox;
    quint16 nextBlockSize;
    QList<QTcpSocket*> clientsList;
    QList<QString> usernamesList;
    QList<QString> contactsList;
    QList<QString> requestedContactsList;
    QList<QString> requestedContactsByMeList;
    QString contact;
    database db;
    QString thisUser;
    QString anotherUser;
    QTcpSocket * offlineSocket;
    QString privateUser;

    void sendToClient(QTcpSocket* pSocket, const QString& str, int command);
    void sendUserInfoToClient(QTcpSocket* pSocket,
                              int command,
                              QString name,
                              int age,
                              QString country,
                              QString info,
                              QString phone,
                              QString email
                             );

public:
    MyServer(int nPort, QWidget* pwgt = 0);
    void broadcast(int command, QString str);
    QTcpSocket * findSocketByUsername(QString username);
    bool checkIsUserOnline(QString username);
    QList<QString> getContactsList(QString username);

public slots:
    virtual void slotNewConnection();
    void slotReadClient();
    void slotClientDisconnected();
};
#endif  //MYSERVER_H
