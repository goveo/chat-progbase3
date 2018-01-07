#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "network.h"
#include "mainwindow.h"
#include "QLabel"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(const QString& strHost, int nPort, QWidget *parent = 0);
    void openDialog();
    void closeDialog();
    bool finished();
    bool isLogined();
    void sendToServer(int command);
    void setUser(User temp);
    User getUser();
    bool checkUserUnique(QList<QString> users, QString user);
    bool getResetCheck();
    QString getIp();
    int getPort();

    ~Dialog();

private slots:
    void on_loginButton_clicked();
    void slotConnected();
    void slotError();
    void readInfoFromServer();
    void on_checkBox_clicked();

    void on_Dialog_rejected();

    void on_loginButton_pressed();

    void on_pushButton_clicked();

private:
    Ui::Dialog * ui;
    bool _finished;
    bool isUserUnique;
    QTcpSocket * dialogSocket;
    quint16 nextBlockSize;
    bool loginStatus;
    User user;
    QLabel * errorLabel;
    QList<QString> usersOnline;

    QString serverIp;
    int serverPort;
    bool resetCheck;
};

#endif // DIALOG_H
