/********************************************************************************
** Form generated from reading UI file 'contacts.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTS_H
#define UI_CONTACTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Contacts
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *contactsLayout;
    QLabel *text_yourContacts;
    QListWidget *friendsListWidget;

    void setupUi(QDialog *Contacts)
    {
        if (Contacts->objectName().isEmpty())
            Contacts->setObjectName(QStringLiteral("Contacts"));
        Contacts->resize(220, 250);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Contacts->sizePolicy().hasHeightForWidth());
        Contacts->setSizePolicy(sizePolicy);
        Contacts->setMinimumSize(QSize(220, 250));
        Contacts->setMaximumSize(QSize(220, 250));
        Contacts->setSizeIncrement(QSize(220, 250));
        Contacts->setBaseSize(QSize(220, 250));
        verticalLayoutWidget = new QWidget(Contacts);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 20, 160, 211));
        contactsLayout = new QVBoxLayout(verticalLayoutWidget);
        contactsLayout->setObjectName(QStringLiteral("contactsLayout"));
        contactsLayout->setContentsMargins(0, 0, 0, 0);
        text_yourContacts = new QLabel(verticalLayoutWidget);
        text_yourContacts->setObjectName(QStringLiteral("text_yourContacts"));
        text_yourContacts->setAlignment(Qt::AlignCenter);

        contactsLayout->addWidget(text_yourContacts);

        friendsListWidget = new QListWidget(verticalLayoutWidget);
        friendsListWidget->setObjectName(QStringLiteral("friendsListWidget"));

        contactsLayout->addWidget(friendsListWidget);


        retranslateUi(Contacts);

        QMetaObject::connectSlotsByName(Contacts);
    } // setupUi

    void retranslateUi(QDialog *Contacts)
    {
        Contacts->setWindowTitle(QApplication::translate("Contacts", "Dialog", Q_NULLPTR));
        text_yourContacts->setText(QApplication::translate("Contacts", "Your contacts :", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Contacts: public Ui_Contacts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTS_H
