#ifndef CONTACTS_H
#define CONTACTS_H

#include <QDialog>
#include <QListWidgetItem>
#include <QTcpSocket>

namespace Ui {
class Contacts;
}

class Contacts : public QDialog
{
    Q_OBJECT

public:
    explicit Contacts(QTcpSocket * _thisSocket, QWidget *parent = 0);
    void setContacts(QList<QString> contactsList);
    QListWidgetItem * getSelectedContact();
    bool isAccepted();
    ~Contacts();

private slots:
    void on_friendsListWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_friendsListWidget_itemPressed(QListWidgetItem *item);

    void on_Contacts_rejected();

private:
    Ui::Contacts *ui;
    QList<QString> contactsList;
    QListWidgetItem * selectedContact;
    QTcpSocket * thisSocket;
    bool accepted;
};

#endif // CONTACTS_H
