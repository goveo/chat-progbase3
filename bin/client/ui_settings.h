/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *text_age;
    QSpinBox *ageSpinBox;
    QLabel *text_country;
    QLabel *text_info;
    QLabel *text_fullname;
    QLineEdit *fullnameLineEdit;
    QLineEdit *countryLineEdit;
    QTextEdit *infoTextEdit;
    QFrame *line;
    QFrame *line_2;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *text_phone;
    QLineEdit *phoneLineEdit;
    QLabel *text_email;
    QLineEdit *emailLineEdit;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_3;
    QLabel *text_oldpass;
    QLineEdit *changePassLine;
    QLineEdit *changePassLine2;
    QLabel *text_newpass;
    QLabel *text_publicinfo;
    QLabel *text_publicinfo_2;
    QLabel *text_publicinfo_3;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *errorLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *changePassButton;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QStringLiteral("Settings"));
        Settings->resize(505, 300);
        Settings->setMinimumSize(QSize(505, 300));
        Settings->setMaximumSize(QSize(505, 300));
        Settings->setBaseSize(QSize(505, 300));
        buttonBox = new QDialogButtonBox(Settings);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(320, 260, 171, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(Settings);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 40, 221, 121));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        text_age = new QLabel(formLayoutWidget);
        text_age->setObjectName(QStringLiteral("text_age"));

        formLayout->setWidget(1, QFormLayout::LabelRole, text_age);

        ageSpinBox = new QSpinBox(formLayoutWidget);
        ageSpinBox->setObjectName(QStringLiteral("ageSpinBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, ageSpinBox);

        text_country = new QLabel(formLayoutWidget);
        text_country->setObjectName(QStringLiteral("text_country"));

        formLayout->setWidget(2, QFormLayout::LabelRole, text_country);

        text_info = new QLabel(formLayoutWidget);
        text_info->setObjectName(QStringLiteral("text_info"));

        formLayout->setWidget(3, QFormLayout::LabelRole, text_info);

        text_fullname = new QLabel(formLayoutWidget);
        text_fullname->setObjectName(QStringLiteral("text_fullname"));

        formLayout->setWidget(0, QFormLayout::LabelRole, text_fullname);

        fullnameLineEdit = new QLineEdit(formLayoutWidget);
        fullnameLineEdit->setObjectName(QStringLiteral("fullnameLineEdit"));
        fullnameLineEdit->setMaxLength(16);

        formLayout->setWidget(0, QFormLayout::FieldRole, fullnameLineEdit);

        countryLineEdit = new QLineEdit(formLayoutWidget);
        countryLineEdit->setObjectName(QStringLiteral("countryLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, countryLineEdit);

        infoTextEdit = new QTextEdit(Settings);
        infoTextEdit->setObjectName(QStringLiteral("infoTextEdit"));
        infoTextEdit->setGeometry(QRect(10, 160, 221, 111));
        line = new QFrame(Settings);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(230, -10, 21, 321));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(Settings);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(240, 150, 261, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        formLayoutWidget_2 = new QWidget(Settings);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(250, 190, 251, 64));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        text_phone = new QLabel(formLayoutWidget_2);
        text_phone->setObjectName(QStringLiteral("text_phone"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, text_phone);

        phoneLineEdit = new QLineEdit(formLayoutWidget_2);
        phoneLineEdit->setObjectName(QStringLiteral("phoneLineEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, phoneLineEdit);

        text_email = new QLabel(formLayoutWidget_2);
        text_email->setObjectName(QStringLiteral("text_email"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, text_email);

        emailLineEdit = new QLineEdit(formLayoutWidget_2);
        emailLineEdit->setObjectName(QStringLiteral("emailLineEdit"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, emailLineEdit);

        formLayoutWidget_3 = new QWidget(Settings);
        formLayoutWidget_3->setObjectName(QStringLiteral("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(250, 40, 251, 61));
        formLayout_3 = new QFormLayout(formLayoutWidget_3);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        text_oldpass = new QLabel(formLayoutWidget_3);
        text_oldpass->setObjectName(QStringLiteral("text_oldpass"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, text_oldpass);

        changePassLine = new QLineEdit(formLayoutWidget_3);
        changePassLine->setObjectName(QStringLiteral("changePassLine"));
        changePassLine->setEchoMode(QLineEdit::Password);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, changePassLine);

        changePassLine2 = new QLineEdit(formLayoutWidget_3);
        changePassLine2->setObjectName(QStringLiteral("changePassLine2"));
        changePassLine2->setEchoMode(QLineEdit::Password);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, changePassLine2);

        text_newpass = new QLabel(formLayoutWidget_3);
        text_newpass->setObjectName(QStringLiteral("text_newpass"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, text_newpass);

        text_publicinfo = new QLabel(Settings);
        text_publicinfo->setObjectName(QStringLiteral("text_publicinfo"));
        text_publicinfo->setGeometry(QRect(80, 20, 91, 17));
        text_publicinfo_2 = new QLabel(Settings);
        text_publicinfo_2->setObjectName(QStringLiteral("text_publicinfo_2"));
        text_publicinfo_2->setGeometry(QRect(310, 20, 131, 17));
        text_publicinfo_3 = new QLabel(Settings);
        text_publicinfo_3->setObjectName(QStringLiteral("text_publicinfo_3"));
        text_publicinfo_3->setGeometry(QRect(330, 170, 91, 21));
        horizontalLayoutWidget = new QWidget(Settings);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(250, 110, 241, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        errorLabel = new QLabel(horizontalLayoutWidget);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        errorLabel->setFont(font);
        errorLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(errorLabel);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        changePassButton = new QPushButton(horizontalLayoutWidget);
        changePassButton->setObjectName(QStringLiteral("changePassButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(changePassButton->sizePolicy().hasHeightForWidth());
        changePassButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(changePassButton);


        retranslateUi(Settings);
        QObject::connect(buttonBox, SIGNAL(accepted()), Settings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Settings, SLOT(reject()));

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Dialog", Q_NULLPTR));
        text_age->setText(QApplication::translate("Settings", "Age :", Q_NULLPTR));
        text_country->setText(QApplication::translate("Settings", "Country :", Q_NULLPTR));
        text_info->setText(QApplication::translate("Settings", "Info :", Q_NULLPTR));
        text_fullname->setText(QApplication::translate("Settings", "Fullname :", Q_NULLPTR));
        fullnameLineEdit->setInputMask(QString());
        fullnameLineEdit->setText(QString());
        text_phone->setText(QApplication::translate("Settings", "Phone :", Q_NULLPTR));
        text_email->setText(QApplication::translate("Settings", "Email", Q_NULLPTR));
        text_oldpass->setText(QApplication::translate("Settings", "Old password :", Q_NULLPTR));
        text_newpass->setText(QApplication::translate("Settings", "New password :", Q_NULLPTR));
        text_publicinfo->setText(QApplication::translate("Settings", "Public info :", Q_NULLPTR));
        text_publicinfo_2->setText(QApplication::translate("Settings", "Change password:", Q_NULLPTR));
        text_publicinfo_3->setText(QApplication::translate("Settings", "Private info :", Q_NULLPTR));
        errorLabel->setText(QString());
        changePassButton->setText(QApplication::translate("Settings", "Change", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
