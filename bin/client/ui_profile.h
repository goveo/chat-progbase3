/********************************************************************************
** Form generated from reading UI file 'profile.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILE_H
#define UI_PROFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Profile
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *text_name;
    QLabel *text_age;
    QLabel *text_country;
    QLabel *nameLabel;
    QLabel *ageLabel;
    QLabel *countryLabel;
    QLabel *text_info;
    QTextBrowser *infoText;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *addToFriendsButton;
    QPushButton *privateChatButton;
    QFrame *line;
    QLabel *text_publicInfo;
    QFrame *line_2;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *text_phone;
    QLabel *text_email;
    QLabel *phoneLabel;
    QLabel *emailLabel;
    QLabel *label;
    QPushButton *pushButton;
    QFrame *line_3;

    void setupUi(QDialog *Profile)
    {
        if (Profile->objectName().isEmpty())
            Profile->setObjectName(QStringLiteral("Profile"));
        Profile->resize(505, 280);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Profile->sizePolicy().hasHeightForWidth());
        Profile->setSizePolicy(sizePolicy);
        Profile->setMinimumSize(QSize(505, 250));
        Profile->setMaximumSize(QSize(505, 280));
        Profile->setBaseSize(QSize(505, 280));
        formLayoutWidget = new QWidget(Profile);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 50, 221, 91));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        text_name = new QLabel(formLayoutWidget);
        text_name->setObjectName(QStringLiteral("text_name"));

        formLayout->setWidget(0, QFormLayout::LabelRole, text_name);

        text_age = new QLabel(formLayoutWidget);
        text_age->setObjectName(QStringLiteral("text_age"));

        formLayout->setWidget(1, QFormLayout::LabelRole, text_age);

        text_country = new QLabel(formLayoutWidget);
        text_country->setObjectName(QStringLiteral("text_country"));

        formLayout->setWidget(2, QFormLayout::LabelRole, text_country);

        nameLabel = new QLabel(formLayoutWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameLabel);

        ageLabel = new QLabel(formLayoutWidget);
        ageLabel->setObjectName(QStringLiteral("ageLabel"));

        formLayout->setWidget(1, QFormLayout::FieldRole, ageLabel);

        countryLabel = new QLabel(formLayoutWidget);
        countryLabel->setObjectName(QStringLiteral("countryLabel"));

        formLayout->setWidget(2, QFormLayout::FieldRole, countryLabel);

        text_info = new QLabel(formLayoutWidget);
        text_info->setObjectName(QStringLiteral("text_info"));

        formLayout->setWidget(3, QFormLayout::LabelRole, text_info);

        infoText = new QTextBrowser(Profile);
        infoText->setObjectName(QStringLiteral("infoText"));
        infoText->setGeometry(QRect(20, 140, 221, 101));
        verticalLayoutWidget = new QWidget(Profile);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(290, 20, 191, 81));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        addToFriendsButton = new QPushButton(verticalLayoutWidget);
        addToFriendsButton->setObjectName(QStringLiteral("addToFriendsButton"));

        verticalLayout->addWidget(addToFriendsButton);

        privateChatButton = new QPushButton(verticalLayoutWidget);
        privateChatButton->setObjectName(QStringLiteral("privateChatButton"));

        verticalLayout->addWidget(privateChatButton);

        line = new QFrame(Profile);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(245, 0, 31, 281));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        text_publicInfo = new QLabel(Profile);
        text_publicInfo->setObjectName(QStringLiteral("text_publicInfo"));
        text_publicInfo->setGeometry(QRect(90, 20, 91, 21));
        line_2 = new QFrame(Profile);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(260, 120, 251, 31));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        formLayoutWidget_2 = new QWidget(Profile);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(290, 170, 191, 42));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        text_phone = new QLabel(formLayoutWidget_2);
        text_phone->setObjectName(QStringLiteral("text_phone"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, text_phone);

        text_email = new QLabel(formLayoutWidget_2);
        text_email->setObjectName(QStringLiteral("text_email"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, text_email);

        phoneLabel = new QLabel(formLayoutWidget_2);
        phoneLabel->setObjectName(QStringLiteral("phoneLabel"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, phoneLabel);

        emailLabel = new QLabel(formLayoutWidget_2);
        emailLabel->setObjectName(QStringLiteral("emailLabel"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, emailLabel);

        label = new QLabel(Profile);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(340, 150, 91, 17));
        pushButton = new QPushButton(Profile);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(390, 240, 89, 25));
        line_3 = new QFrame(Profile);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(260, 210, 251, 31));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        retranslateUi(Profile);

        QMetaObject::connectSlotsByName(Profile);
    } // setupUi

    void retranslateUi(QDialog *Profile)
    {
        Profile->setWindowTitle(QApplication::translate("Profile", "Dialog", Q_NULLPTR));
        text_name->setText(QApplication::translate("Profile", "name :", Q_NULLPTR));
        text_age->setText(QApplication::translate("Profile", "age :", Q_NULLPTR));
        text_country->setText(QApplication::translate("Profile", "country :", Q_NULLPTR));
        nameLabel->setText(QString());
        ageLabel->setText(QString());
        countryLabel->setText(QString());
        text_info->setText(QApplication::translate("Profile", "info :", Q_NULLPTR));
        addToFriendsButton->setText(QApplication::translate("Profile", "Add contact", Q_NULLPTR));
        privateChatButton->setText(QApplication::translate("Profile", "Send private message", Q_NULLPTR));
        text_publicInfo->setText(QApplication::translate("Profile", "Public info :", Q_NULLPTR));
        text_phone->setText(QApplication::translate("Profile", "phone :", Q_NULLPTR));
        text_email->setText(QApplication::translate("Profile", "email", Q_NULLPTR));
        phoneLabel->setText(QString());
        emailLabel->setText(QString());
        label->setText(QApplication::translate("Profile", "Private info:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Profile", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Profile: public Ui_Profile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILE_H
