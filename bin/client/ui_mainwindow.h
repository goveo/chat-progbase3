/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_5;
    QPushButton *changeIpButton;
    QPushButton *contactsButton;
    QPushButton *settingsButton;
    QLabel *text_message;
    QLabel *usernameLabel;
    QLineEdit *messageLineEdit;
    QVBoxLayout *verticalLayout;
    QLabel *ipLabel;
    QTextEdit *textEdit;
    QPushButton *sendButton;
    QFrame *line;
    QListWidget *usersOnlineWidget;
    QLabel *text_usersOnline;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(505, 280);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        changeIpButton = new QPushButton(centralWidget);
        changeIpButton->setObjectName(QStringLiteral("changeIpButton"));

        verticalLayout_5->addWidget(changeIpButton);

        contactsButton = new QPushButton(centralWidget);
        contactsButton->setObjectName(QStringLiteral("contactsButton"));

        verticalLayout_5->addWidget(contactsButton);

        settingsButton = new QPushButton(centralWidget);
        settingsButton->setObjectName(QStringLiteral("settingsButton"));

        verticalLayout_5->addWidget(settingsButton);


        gridLayout->addLayout(verticalLayout_5, 4, 1, 1, 1);

        text_message = new QLabel(centralWidget);
        text_message->setObjectName(QStringLiteral("text_message"));

        gridLayout->addWidget(text_message, 9, 1, 1, 1);

        usernameLabel = new QLabel(centralWidget);
        usernameLabel->setObjectName(QStringLiteral("usernameLabel"));
        usernameLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(usernameLabel, 2, 1, 1, 1);

        messageLineEdit = new QLineEdit(centralWidget);
        messageLineEdit->setObjectName(QStringLiteral("messageLineEdit"));

        gridLayout->addWidget(messageLineEdit, 9, 2, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        ipLabel = new QLabel(centralWidget);
        ipLabel->setObjectName(QStringLiteral("ipLabel"));
        ipLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(ipLabel);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);


        gridLayout->addLayout(verticalLayout, 2, 2, 6, 2);

        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));

        gridLayout->addWidget(sendButton, 9, 3, 1, 1);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 3, 1, 1, 1);

        usersOnlineWidget = new QListWidget(centralWidget);
        usersOnlineWidget->setObjectName(QStringLiteral("usersOnlineWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(usersOnlineWidget->sizePolicy().hasHeightForWidth());
        usersOnlineWidget->setSizePolicy(sizePolicy);
        usersOnlineWidget->setMinimumSize(QSize(0, 0));
        usersOnlineWidget->setMaximumSize(QSize(100, 10000000));

        gridLayout->addWidget(usersOnlineWidget, 6, 1, 1, 1);

        text_usersOnline = new QLabel(centralWidget);
        text_usersOnline->setObjectName(QStringLiteral("text_usersOnline"));
        text_usersOnline->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(text_usersOnline, 5, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        changeIpButton->setText(QApplication::translate("MainWindow", "Change ip", Q_NULLPTR));
        contactsButton->setText(QApplication::translate("MainWindow", "Contacts", Q_NULLPTR));
        settingsButton->setText(QApplication::translate("MainWindow", "Settings", Q_NULLPTR));
        text_message->setText(QApplication::translate("MainWindow", "     Message :", Q_NULLPTR));
        usernameLabel->setText(QApplication::translate("MainWindow", "username", Q_NULLPTR));
        ipLabel->setText(QApplication::translate("MainWindow", ">>>IP_HERE<<<", Q_NULLPTR));
        sendButton->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
        text_usersOnline->setText(QApplication::translate("MainWindow", "users online:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
