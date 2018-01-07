#include "changeip.h"
#include "ui_changeip.h"
#include "network.h"
#include <QDebug>
#include <QFile>

ChangeIp::ChangeIp(QString ip, int port, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeIp)
{
    ui->setupUi(this);
    this->setWindowTitle("Change ip");
    this->ip = ip;
    QString portText = QString::number(port);
    QString ipText = this->ip + ":" + portText;
    ui->ipLabel->setText(ipText);

    resetCheck = false;

    QRegExp rx ("[0-9]{0,5}");                                     //set regular expression
    ui->portLineEdit->setValidator(new QRegExpValidator (rx, this));
}

ChangeIp::~ChangeIp() {
    delete ui;
}


bool ChangeIp::getResetCheck() {
    return resetCheck;
}

void ChangeIp::on_changeServerButton_clicked() {
    resetCheck = true;
    ip = ui->ipLineEdit->text();
    QString port = ui->portLineEdit->text();
    qDebug() << "ui->portLineEdit->text() : " << ui->portLineEdit->text();

    QStringList ips = ip.split(".");
    for (int i = 0; i < ips.size(); i++) {
        QString ip = ips.at(i);
        if (ip.toInt() > 255) {
            qDebug() << "Error";
            resetCheck = false;
            break;
        }
    }
    this->port = port.toInt();
    if (this->port < 1024 || this->port > 65535 || port == "" || ips.size() < 3) {
        resetCheck = false;
    }

    if (resetCheck == true) {
        QString ipText = this->ip + ":" + port;
        qDebug() << "ipText : " << ipText;
        // need write to file on client
        writeIpToFile(ipText);
        this->close();
    } else {
        ui->errorLabel->setText("Invalid ip address");
    }
}

QString ChangeIp::getIp() {
    return ip;
}

int ChangeIp::getPort() {
    return port;
}
