#include "profile.h"
#include "ui_profile.h"
#include "network.h"
#include "privatechat.h"

Profile::Profile(QString _myUsername,
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
//                 QList<QString> requstedList,
//                 QList<QString> requstedByMeList,
                 QWidget *parent
                ) :
    QDialog(parent), ui(new Ui::Profile)
{

    qDebug() << "_myUsername : " << _myUsername;
    qDebug() << "_username : " << _username;
    ui->setupUi(this);
    ui->privateChatButton->setDisabled(true);

    thisSocket = socket;
    removeFromContacts = false;
    isContact = false;

    username = _username;
    myUsername = _myUsername;
    userInfo.name = name;
    userInfo.age = age;
    userInfo.country = country;
    userInfo.info = info;
    userInfo.phone = phone;
    userInfo.email = email;

    QString title = username + "\'s profile";

    for (int i = 0; i < contactsList.size(); i++) {
        if (contactsList.at(i) == username) {
            isContact = true;
            removeFromContacts = true;
            ui->privateChatButton->setEnabled(true);
        }
    }

    if (removeFromContacts == true) {
        ui->addToFriendsButton->setText("Delete contact");
    } else {
        if (command == "requestedByMe") {
            ui->addToFriendsButton->setEnabled(false);
            ui->addToFriendsButton->setText("Request sended");
        }
        if (command == "requestedMe") {
            ui->addToFriendsButton->setEnabled(true);
            ui->addToFriendsButton->setText("Accept contact");
        }
        if (command == "isNotContact") {
            ui->addToFriendsButton->setEnabled(true);
            ui->addToFriendsButton->setText("Add contact");
        }
    }

    QString ageNumber = QString::number(userInfo.age);

    ui->nameLabel->setText(userInfo.name);
    ui->ageLabel->setText(ageNumber);
    ui->countryLabel->setText(userInfo.country);
    ui->infoText->setText(userInfo.info);
    ui->phoneLabel->setText(userInfo.phone);
    ui->emailLabel->setText(userInfo.email);

    if (isContact == false && username != myUsername) {
        ui->text_email->setEnabled(false);
        ui->text_phone->setEnabled(false);

        ui->phoneLabel->clear();
        ui->emailLabel->clear();
    }

    if (username == myUsername) {
        ui->addToFriendsButton->setEnabled(false);
        ui->privateChatButton->setEnabled(false);
        title += " (it's you)";
        this->setWindowTitle(title);
        return;
    }

    if (isOnline == true) {
        title += " (online)";
    } else {
        title += " (offline)";
    }

    if (isOnline == false && isContact == true) {
        ui->addToFriendsButton->setEnabled(false);
        ui->privateChatButton->setEnabled(false);
    }
    this->setWindowTitle(title);
}

Profile::~Profile()
{
    delete ui;
}

void Profile::on_addToFriendsButton_clicked()
{
    sendCommandToServer(sendContactRequest);
//    sendCommandToServer(addContactToDatabase);

    if (removeFromContacts == false) {
        ui->addToFriendsButton->setText("Delete contact");
        removeFromContacts = true;
    } else {
        ui->addToFriendsButton->setText("Add contact");
        removeFromContacts = false;
    }
    accepted = true;
    Profile::accept();
}

bool Profile::isNotDeletedFromContacts() {
    return removeFromContacts;
}

bool Profile::isAccepted()
{
    return accepted;
}

void Profile::on_privateChatButton_clicked()
{
    sendCommandToServer(openPrivateChat);
    Profile::accept();
}

void Profile::sendCommandToServer(int command) {
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);

    out << quint16(0) << command << myUsername << username;

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    thisSocket->write(arrBlock);
    qDebug() << command << " sended to server";
}

void Profile::on_pushButton_clicked()
{
    Profile::close();
}
