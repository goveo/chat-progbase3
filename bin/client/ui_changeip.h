/********************************************************************************
** Form generated from reading UI file 'changeip.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEIP_H
#define UI_CHANGEIP_H

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

class Ui_ChangeIp
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *text_current;
    QLabel *ipLabel;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *text_connect;
    QLineEdit *ipLineEdit;
    QLabel *text_dots;
    QLineEdit *portLineEdit;
    QPushButton *changeServerButton;
    QLabel *errorLabel;

    void setupUi(QDialog *ChangeIp)
    {
        if (ChangeIp->objectName().isEmpty())
            ChangeIp->setObjectName(QStringLiteral("ChangeIp"));
        ChangeIp->resize(340, 190);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChangeIp->sizePolicy().hasHeightForWidth());
        ChangeIp->setSizePolicy(sizePolicy);
        ChangeIp->setMinimumSize(QSize(340, 190));
        ChangeIp->setMaximumSize(QSize(340, 190));
        ChangeIp->setBaseSize(QSize(340, 190));
        horizontalLayoutWidget = new QWidget(ChangeIp);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(49, 30, 251, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        text_current = new QLabel(horizontalLayoutWidget);
        text_current->setObjectName(QStringLiteral("text_current"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(text_current->sizePolicy().hasHeightForWidth());
        text_current->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(text_current);

        ipLabel = new QLabel(horizontalLayoutWidget);
        ipLabel->setObjectName(QStringLiteral("ipLabel"));
        ipLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(ipLabel);

        horizontalLayoutWidget_2 = new QWidget(ChangeIp);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(30, 80, 285, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        text_connect = new QLabel(horizontalLayoutWidget_2);
        text_connect->setObjectName(QStringLiteral("text_connect"));

        horizontalLayout_2->addWidget(text_connect);

        ipLineEdit = new QLineEdit(horizontalLayoutWidget_2);
        ipLineEdit->setObjectName(QStringLiteral("ipLineEdit"));
        sizePolicy.setHeightForWidth(ipLineEdit->sizePolicy().hasHeightForWidth());
        ipLineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(ipLineEdit);

        text_dots = new QLabel(horizontalLayoutWidget_2);
        text_dots->setObjectName(QStringLiteral("text_dots"));

        horizontalLayout_2->addWidget(text_dots);

        portLineEdit = new QLineEdit(horizontalLayoutWidget_2);
        portLineEdit->setObjectName(QStringLiteral("portLineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(portLineEdit->sizePolicy().hasHeightForWidth());
        portLineEdit->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(portLineEdit);

        changeServerButton = new QPushButton(ChangeIp);
        changeServerButton->setObjectName(QStringLiteral("changeServerButton"));
        changeServerButton->setGeometry(QRect(210, 160, 111, 25));
        errorLabel = new QLabel(ChangeIp);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));
        errorLabel->setGeometry(QRect(30, 120, 281, 31));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        errorLabel->setFont(font);

        retranslateUi(ChangeIp);

        QMetaObject::connectSlotsByName(ChangeIp);
    } // setupUi

    void retranslateUi(QDialog *ChangeIp)
    {
        ChangeIp->setWindowTitle(QApplication::translate("ChangeIp", "Dialog", Q_NULLPTR));
        text_current->setText(QApplication::translate("ChangeIp", "Current ip :", Q_NULLPTR));
        ipLabel->setText(QString());
        text_connect->setText(QApplication::translate("ChangeIp", "Connect :", Q_NULLPTR));
        ipLineEdit->setInputMask(QString());
        ipLineEdit->setText(QString());
        text_dots->setText(QApplication::translate("ChangeIp", ":", Q_NULLPTR));
        changeServerButton->setText(QApplication::translate("ChangeIp", "Change server", Q_NULLPTR));
        errorLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChangeIp: public Ui_ChangeIp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEIP_H
