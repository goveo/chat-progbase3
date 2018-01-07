/********************************************************************************
** Form generated from reading UI file 'privatechat.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRIVATECHAT_H
#define UI_PRIVATECHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrivateChat
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *text_message;
    QLineEdit *messageLineEdit;
    QPushButton *sendButton;
    QLabel *text_send;

    void setupUi(QDialog *PrivateChat)
    {
        if (PrivateChat->objectName().isEmpty())
            PrivateChat->setObjectName(QStringLiteral("PrivateChat"));
        PrivateChat->setWindowModality(Qt::WindowModal);
        PrivateChat->resize(420, 150);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(100);
        sizePolicy.setVerticalStretch(100);
        sizePolicy.setHeightForWidth(PrivateChat->sizePolicy().hasHeightForWidth());
        PrivateChat->setSizePolicy(sizePolicy);
        PrivateChat->setMinimumSize(QSize(420, 150));
        PrivateChat->setMaximumSize(QSize(420, 150));
        PrivateChat->setBaseSize(QSize(420, 150));
        widget = new QWidget(PrivateChat);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 50, 379, 41));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        text_message = new QLabel(widget);
        text_message->setObjectName(QStringLiteral("text_message"));

        horizontalLayout->addWidget(text_message);

        messageLineEdit = new QLineEdit(widget);
        messageLineEdit->setObjectName(QStringLiteral("messageLineEdit"));

        horizontalLayout->addWidget(messageLineEdit);

        sendButton = new QPushButton(widget);
        sendButton->setObjectName(QStringLiteral("sendButton"));

        horizontalLayout->addWidget(sendButton);

        text_send = new QLabel(PrivateChat);
        text_send->setObjectName(QStringLiteral("text_send"));
        text_send->setGeometry(QRect(30, 20, 361, 20));

        retranslateUi(PrivateChat);

        QMetaObject::connectSlotsByName(PrivateChat);
    } // setupUi

    void retranslateUi(QDialog *PrivateChat)
    {
        PrivateChat->setWindowTitle(QApplication::translate("PrivateChat", "Dialog", Q_NULLPTR));
        text_message->setText(QApplication::translate("PrivateChat", "Message :", Q_NULLPTR));
        sendButton->setText(QApplication::translate("PrivateChat", "Send", Q_NULLPTR));
        text_send->setText(QApplication::translate("PrivateChat", "Send private message to ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PrivateChat: public Ui_PrivateChat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRIVATECHAT_H
