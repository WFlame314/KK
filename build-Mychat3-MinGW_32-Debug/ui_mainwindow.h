/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QPushButton *hidebtn;
    QPushButton *closebtn;
    QLabel *logo;
    QPushButton *facebtn;
    QLabel *name;
    QLineEdit *tag;
    QLineEdit *search;
    QPushButton *menubtn;
    QPushButton *addbtn;
    QLineEdit *mask;
    QPushButton *addmessagebtn;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 800);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        hidebtn = new QPushButton(MainWindow);
        hidebtn->setObjectName(QString::fromUtf8("hidebtn"));
        hidebtn->setGeometry(QRect(230, 20, 75, 27));
        closebtn = new QPushButton(MainWindow);
        closebtn->setObjectName(QString::fromUtf8("closebtn"));
        closebtn->setGeometry(QRect(320, 20, 75, 27));
        logo = new QLabel(MainWindow);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(20, 20, 47, 19));
        facebtn = new QPushButton(MainWindow);
        facebtn->setObjectName(QString::fromUtf8("facebtn"));
        facebtn->setGeometry(QRect(20, 90, 75, 27));
        facebtn->setCursor(QCursor(Qt::PointingHandCursor));
        name = new QLabel(MainWindow);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(140, 80, 47, 19));
        tag = new QLineEdit(MainWindow);
        tag->setObjectName(QString::fromUtf8("tag"));
        tag->setGeometry(QRect(120, 110, 113, 25));
        search = new QLineEdit(MainWindow);
        search->setObjectName(QString::fromUtf8("search"));
        search->setGeometry(QRect(50, 150, 113, 25));
        menubtn = new QPushButton(MainWindow);
        menubtn->setObjectName(QString::fromUtf8("menubtn"));
        menubtn->setGeometry(QRect(20, 760, 75, 27));
        addbtn = new QPushButton(MainWindow);
        addbtn->setObjectName(QString::fromUtf8("addbtn"));
        addbtn->setGeometry(QRect(110, 760, 75, 27));
        mask = new QLineEdit(MainWindow);
        mask->setObjectName(QString::fromUtf8("mask"));
        mask->setGeometry(QRect(70, 760, 113, 25));
        mask->setReadOnly(true);
        addmessagebtn = new QPushButton(MainWindow);
        addmessagebtn->setObjectName(QString::fromUtf8("addmessagebtn"));
        addmessagebtn->setGeometry(QRect(200, 760, 75, 27));
        mask->raise();
        hidebtn->raise();
        closebtn->raise();
        logo->raise();
        facebtn->raise();
        name->raise();
        tag->raise();
        search->raise();
        menubtn->raise();
        addbtn->raise();
        addmessagebtn->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Form", nullptr));
        hidebtn->setText(QCoreApplication::translate("MainWindow", "hide", nullptr));
        closebtn->setText(QCoreApplication::translate("MainWindow", "close", nullptr));
        logo->setText(QCoreApplication::translate("MainWindow", "logo", nullptr));
        facebtn->setText(QCoreApplication::translate("MainWindow", "face", nullptr));
        name->setText(QCoreApplication::translate("MainWindow", "name", nullptr));
        menubtn->setText(QString());
        addbtn->setText(QString());
        addmessagebtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
