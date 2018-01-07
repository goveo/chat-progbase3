#include "contacts.h"
#include "ui_contacts.h"
#include <QDebug>
#include "network.h"

Contacts::Contacts(QTcpSocket * _thisSocket, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Contacts)
{
    ui->setupUi(this);
    this->setWindowTitle("Contacts");
    thisSocket = _thisSocket;
}

void Contacts::setContacts(QList<QString> _contactsList)
{
    contactsList = _contactsList;
    for (int index = 0; index < contactsList.size(); index++) {
        qDebug() << "contactsList in contacts: " << contactsList.at(index);
    }
    for (int index = 0; index < contactsList.size(); index++) {
        ui->friendsListWidget->addItem(contactsList.at(index));
    }
}

QListWidgetItem *Contacts::getSelectedContact()
{
    return selectedContact;
}

bool Contacts::isAccepted()
{
    return accepted;
}

Contacts::~Contacts()
{
    delete ui;
}

void Contacts::on_friendsListWidget_itemDoubleClicked(QListWidgetItem *item)
{
    Contacts::close();
    selectedContact = item;
    accepted = true;
}


void Contacts::on_friendsListWidget_itemPressed(QListWidgetItem *item)
{
    item->setSelected(false);
    QString username = item->text();
    qDebug() << "username : " << username;
    int command = getUserInfoFromDatabase;
    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out << quint16(0) << command << username;
    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));
    thisSocket->write(arrBlock);
}

void Contacts::on_Contacts_rejected()
{
    qDebug() << "rejected";
    accepted = false;
}
