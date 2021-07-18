/********************************************************************************
** Form generated from reading UI file 'logwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGWINDOW_H
#define UI_LOGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_logwindow
{
public:
    QLabel *face;
    QLabel *logo;
    QPushButton *login;
    QLabel *user;
    QLabel *pass;
    QLineEdit *userin;
    QLineEdit *passwordin;

    void setupUi(QWidget *logwindow)
    {
        if (logwindow->objectName().isEmpty())
            logwindow->setObjectName(QString::fromUtf8("logwindow"));
        logwindow->resize(800, 600);
        face = new QLabel(logwindow);
        face->setObjectName(QString::fromUtf8("face"));
        face->setGeometry(QRect(20, 30, 47, 19));
        logo = new QLabel(logwindow);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(20, 60, 47, 19));
        login = new QPushButton(logwindow);
        login->setObjectName(QString::fromUtf8("login"));
        login->setGeometry(QRect(170, 280, 75, 27));
        user = new QLabel(logwindow);
        user->setObjectName(QString::fromUtf8("user"));
        user->setGeometry(QRect(210, 160, 47, 19));
        pass = new QLabel(logwindow);
        pass->setObjectName(QString::fromUtf8("pass"));
        pass->setGeometry(QRect(240, 210, 47, 19));
        userin = new QLineEdit(logwindow);
        userin->setObjectName(QString::fromUtf8("userin"));
        userin->setGeometry(QRect(360, 150, 113, 25));
        userin->setMaxLength(10);
        passwordin = new QLineEdit(logwindow);
        passwordin->setObjectName(QString::fromUtf8("passwordin"));
        passwordin->setGeometry(QRect(360, 210, 113, 25));
        passwordin->setContextMenuPolicy(Qt::DefaultContextMenu);
        passwordin->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        passwordin->setEchoMode(QLineEdit::Password);

        retranslateUi(logwindow);

        QMetaObject::connectSlotsByName(logwindow);
    } // setupUi

    void retranslateUi(QWidget *logwindow)
    {
        logwindow->setWindowTitle(QCoreApplication::translate("logwindow", "logwindow", nullptr));
        face->setText(QCoreApplication::translate("logwindow", "face", nullptr));
        logo->setText(QCoreApplication::translate("logwindow", "logo", nullptr));
        login->setText(QCoreApplication::translate("logwindow", "\347\231\273\345\275\225", nullptr));
        user->setText(QCoreApplication::translate("logwindow", "user", nullptr));
        pass->setText(QCoreApplication::translate("logwindow", "password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class logwindow: public Ui_logwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGWINDOW_H
