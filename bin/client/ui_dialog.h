/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *passwordLineEdit;
    QLineEdit *usernameLineEdit;
    QLabel *text_username;
    QLabel *text_password;
    QLabel *text_info;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QPushButton *loginButton;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *text_currIp;
    QLabel *ipLabel;
    QLabel *errorLabel;
    QPushButton *pushButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(274, 250);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        Dialog->setMinimumSize(QSize(272, 250));
        Dialog->setMaximumSize(QSize(274, 250));
        Dialog->setBaseSize(QSize(274, 250));
        gridLayoutWidget = new QWidget(Dialog);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 60, 231, 111));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        passwordLineEdit = new QLineEdit(gridLayoutWidget);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passwordLineEdit, 1, 1, 1, 1);

        usernameLineEdit = new QLineEdit(gridLayoutWidget);
        usernameLineEdit->setObjectName(QStringLiteral("usernameLineEdit"));
        usernameLineEdit->setMaxLength(13);

        gridLayout->addWidget(usernameLineEdit, 0, 1, 1, 1);

        text_username = new QLabel(gridLayoutWidget);
        text_username->setObjectName(QStringLiteral("text_username"));

        gridLayout->addWidget(text_username, 0, 0, 1, 1);

        text_password = new QLabel(gridLayoutWidget);
        text_password->setObjectName(QStringLiteral("text_password"));

        gridLayout->addWidget(text_password, 1, 0, 1, 1);

        text_info = new QLabel(Dialog);
        text_info->setObjectName(QStringLiteral("text_info"));
        text_info->setGeometry(QRect(20, 160, 141, 21));
        horizontalLayoutWidget = new QWidget(Dialog);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 170, 232, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        checkBox = new QCheckBox(horizontalLayoutWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        QFont font;
        font.setPointSize(9);
        checkBox->setFont(font);

        horizontalLayout->addWidget(checkBox);

        loginButton = new QPushButton(horizontalLayoutWidget);
        loginButton->setObjectName(QStringLiteral("loginButton"));

        horizontalLayout->addWidget(loginButton);

        horizontalLayoutWidget_2 = new QWidget(Dialog);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(20, 30, 231, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        text_currIp = new QLabel(horizontalLayoutWidget_2);
        text_currIp->setObjectName(QStringLiteral("text_currIp"));
        text_currIp->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(text_currIp);

        ipLabel = new QLabel(horizontalLayoutWidget_2);
        ipLabel->setObjectName(QStringLiteral("ipLabel"));
        ipLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(ipLabel);

        errorLabel = new QLabel(Dialog);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));
        errorLabel->setGeometry(QRect(20, 10, 231, 21));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setWeight(75);
        errorLabel->setFont(font1);
        errorLabel->setAlignment(Qt::AlignCenter);
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(170, 210, 82, 25));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMinimumSize(QSize(82, 0));
        pushButton->setBaseSize(QSize(82, 0));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        text_username->setText(QApplication::translate("Dialog", "username :", Q_NULLPTR));
        text_password->setText(QApplication::translate("Dialog", "password :", Q_NULLPTR));
        text_info->setText(QString());
        checkBox->setText(QApplication::translate("Dialog", "don't have an account", Q_NULLPTR));
        loginButton->setText(QApplication::translate("Dialog", "Log in", Q_NULLPTR));
        text_currIp->setText(QApplication::translate("Dialog", "current ip:", Q_NULLPTR));
        ipLabel->setText(QString());
        errorLabel->setText(QString());
        pushButton->setText(QApplication::translate("Dialog", "Change ip", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
