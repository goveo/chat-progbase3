#include "settings.h"
#include "ui_settings.h"
#include "network.h"
#include "mainwindow.h"

Settings::Settings(QTcpSocket * socket, QString _username, QString _password, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    thisSocket = socket;
    username = _username;
    password = _password;

    this->setWindowTitle("Settings");

    infoTextEdit = this->findChild<QTextEdit*>("infoTextEdit");
    nameLineEdit = this->findChild<QLineEdit*>("fullnameLineEdit");
    ageSpinBox = this->findChild<QSpinBox*>("ageSpinBox");
    countryLineEdit = this->findChild<QLineEdit*>("countryLineEdit");
    phoneLineEdit = this->findChild<QLineEdit*>("phoneLineEdit");
    emailLineEdit = this->findChild<QLineEdit*>("emailLineEdit");

    QRegExp phoneRx ("[0-9]{0,255}");
    QRegExp emailRx ("[A-Za-z0-9.@]{0,255}");
    QRegExp countryRx ("[A-Za-z]{0,255}");
    QRegExp nameRx ("[A-Za-z ]{0,255}");
    ui->phoneLineEdit->setValidator(new QRegExpValidator(phoneRx, this));
    ui->emailLineEdit->setValidator(new QRegExpValidator(emailRx, this));
    ui->countryLineEdit->setValidator(new QRegExpValidator(countryRx, this));
    ui->fullnameLineEdit->setValidator(new QRegExpValidator(nameRx, this));

}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_buttonBox_accepted()
{
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);

    out << quint16(0)
        << sendUserInfo
        << username
        << nameLineEdit->text()
        << ageSpinBox->value()
        << countryLineEdit->text()
        << infoTextEdit->toPlainText()
        << ui->phoneLineEdit->text()
        << ui->emailLineEdit->text();

    qDebug() << "ui->phoneLineEdit->text()" << ui->phoneLineEdit->text();
    qDebug() << "ui->emailLineEdit->text();" << ui->emailLineEdit->text();

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    thisSocket->write(arrBlock);
    qDebug() << " sendUserInfo sended to server";
}

void Settings::on_Settings_rejected()
{
//    sendToServer(getUserInfoFromDatabase);
}

void Settings::sendToServer(int command) {
    qDebug() << "'Settings :: sendUserToServer'";
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);

    if (command == changePassword) {
        out << quint16(0) << command << username << newPassword;
    }

    if (command == setLogMessage) {
        out << quint16(0) << command << username << logMessage;
    }


    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    thisSocket->write(arrBlock);
}

void Settings::setInfo(UserInfo _userInfo) {
    this->userInfo = _userInfo;
    infoTextEdit->setText(userInfo.info);
    nameLineEdit->setText(userInfo.name);
    ageSpinBox->setValue(userInfo.age);
    countryLineEdit->setText(userInfo.country);
    phoneLineEdit->setText(userInfo.phone);
    emailLineEdit->setText(userInfo.email);
}


void Settings::on_changePassButton_clicked()
{
    oldPassword = ui->changePassLine->text();
    newPassword = ui->changePassLine2->text();
    if (oldPassword == password) {
        sendToServer(changePassword);
        Settings::close();
    } else {
//        logMessage = "Error: old password is incorrect";
//        sendToServer(setLogMessage);
        ui->errorLabel->setText("Invalid password");
    }
}

void Settings::on_changePassLine_textChanged()
{
    ui->errorLabel->clear();
}
