#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QTextEdit>
#include <QSpinBox>
#include <QTcpSocket>
#include "network.h"

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QTcpSocket * socket, QString _username, QString _password, QWidget *parent = 0);
    void setInfo(UserInfo _userInfo);
    ~Settings();

private slots:

    void on_buttonBox_accepted();

    void on_Settings_rejected();

    void on_changePassButton_clicked();

    void on_changePassLine_textChanged();

public slots:
    void sendToServer(int command);

private:
    Ui::Settings *ui;
    QTcpSocket * thisSocket;
    QTextEdit * infoTextEdit;
    QLineEdit * nameLineEdit;
    QLineEdit * countryLineEdit;
    QLineEdit * phoneLineEdit;
    QLineEdit * emailLineEdit;
    QSpinBox * ageSpinBox;
    QString username;
    QString password;
    QString oldPassword;
    QString newPassword;
    QString logMessage;
    UserInfo userInfo;
    quint16 nextBlockSize;
};

#endif // SETTINGS_H
