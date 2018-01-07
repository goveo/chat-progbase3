#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTcpSocket>
#include <QMainWindow>
#include <QTextEdit>
#include <QLineEdit>
#include "network.h"
#include "settings.h"
#include "privatechat.h"
#include <QListWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const QString strHost, int nPort, QWidget *parent = 0);
    void setUser(User temp);
    void sendCommandToServer(int command);
    QString getUsername() { return user.username; }
    bool getResetCheck();
    bool checkIsUserOnline(QString username);
    ~MainWindow();

public slots:
    void slotReadyRead();

private slots:

    void slotError(QAbstractSocket::SocketError);
    void slotConnected();

    void on_sendButton_clicked();
    void on_messageLineEdit_returnPressed();

    void on_settingsButton_clicked();
    void on_settingsButton_pressed();

    void on_usersOnlineWidget_itemDoubleClicked(QListWidgetItem *item);
    void on_usersOnlineWidget_itemPressed(QListWidgetItem *item);

    void on_contactsButton_pressed();
    void on_contactsButton_released();

    void on_messageLineEdit_textChanged(const QString &text);

    void on_changeIpButton_clicked();

    bool isRequestedByMe(QString username);
    bool isRequestedMe(QString username);

    void on_MainWindow_destroyed();


private:
    Ui::MainWindow *ui;
    QTcpSocket* thisSocket;
    QTextEdit*  messageBox;
    QLineEdit*  inputLine;
    quint16     nextBlockSize;
    bool resetCheck;
    QList<QString> usernamesList;
    QList<QString> contactsList;
    QList<QString> requestedContactsList;
    QList<QString> requestedContactsByMeList;

    User user;
    UserInfo anotherUserInfo;
    UserInfo userInfo;
    QString deletedContact;
    QString contact;
    QString privateChatUser;

    int serverPort;
    QString serverIp;
};

#endif // MAINWINDOW_H
