#ifndef PRIVATECHAT_H
#define PRIVATECHAT_H

#include <QDialog>
#include <QTcpSocket>

namespace Ui {
class PrivateChat;
}

class PrivateChat : public QDialog
{
    Q_OBJECT

public:
    explicit PrivateChat(QString username, QString anotherUser, QTcpSocket * socket, QWidget *parent = 0);
    void sendCommandToServer(int command);
    ~PrivateChat();

private slots:
    void on_sendButton_clicked();

private:
    Ui::PrivateChat *ui;
    QTcpSocket * thisSocket;
    QString username;
    QString anotherUsername;
    quint16 nextBlockSize;
};

#endif // PRIVATECHAT_H
