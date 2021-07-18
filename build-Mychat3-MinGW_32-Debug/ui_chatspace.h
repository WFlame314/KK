/********************************************************************************
** Form generated from reading UI file 'chatspace.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATSPACE_H
#define UI_CHATSPACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chatspace
{
public:
    QPushButton *changeshowstylebtn;
    QPushButton *sendbtn;
    QPushButton *emoji;
    QPushButton *screancut;
    QPushButton *editmax;
    QPushButton *chathis;
    QPushButton *closebtn;
    QPushButton *maxbtn;
    QPushButton *minbtn;
    QLabel *friendname;
    QLineEdit *mask;
    QTextEdit *textEdit;
    QPushButton *closebtn2;

    void setupUi(QWidget *chatspace)
    {
        if (chatspace->objectName().isEmpty())
            chatspace->setObjectName(QString::fromUtf8("chatspace"));
        chatspace->resize(704, 518);
        changeshowstylebtn = new QPushButton(chatspace);
        changeshowstylebtn->setObjectName(QString::fromUtf8("changeshowstylebtn"));
        changeshowstylebtn->setGeometry(QRect(10, 250, 70, 27));
        changeshowstylebtn->setMaximumSize(QSize(70, 16777215));
        sendbtn = new QPushButton(chatspace);
        sendbtn->setObjectName(QString::fromUtf8("sendbtn"));
        sendbtn->setGeometry(QRect(604, 491, 75, 27));
        sendbtn->setMaximumSize(QSize(100, 16777215));
        emoji = new QPushButton(chatspace);
        emoji->setObjectName(QString::fromUtf8("emoji"));
        emoji->setGeometry(QRect(100, 250, 30, 27));
        emoji->setMaximumSize(QSize(30, 16777215));
        screancut = new QPushButton(chatspace);
        screancut->setObjectName(QString::fromUtf8("screancut"));
        screancut->setGeometry(QRect(140, 250, 30, 27));
        screancut->setMaximumSize(QSize(30, 16777215));
        editmax = new QPushButton(chatspace);
        editmax->setObjectName(QString::fromUtf8("editmax"));
        editmax->setGeometry(QRect(610, 250, 30, 27));
        editmax->setMaximumSize(QSize(30, 16777215));
        chathis = new QPushButton(chatspace);
        chathis->setObjectName(QString::fromUtf8("chathis"));
        chathis->setGeometry(QRect(660, 250, 30, 27));
        chathis->setMaximumSize(QSize(30, 16777215));
        closebtn = new QPushButton(chatspace);
        closebtn->setObjectName(QString::fromUtf8("closebtn"));
        closebtn->setGeometry(QRect(660, 0, 30, 30));
        closebtn->setMaximumSize(QSize(30, 30));
        maxbtn = new QPushButton(chatspace);
        maxbtn->setObjectName(QString::fromUtf8("maxbtn"));
        maxbtn->setGeometry(QRect(630, 0, 30, 30));
        maxbtn->setMaximumSize(QSize(30, 30));
        minbtn = new QPushButton(chatspace);
        minbtn->setObjectName(QString::fromUtf8("minbtn"));
        minbtn->setGeometry(QRect(580, 0, 30, 30));
        minbtn->setMaximumSize(QSize(30, 30));
        friendname = new QLabel(chatspace);
        friendname->setObjectName(QString::fromUtf8("friendname"));
        friendname->setGeometry(QRect(250, 0, 47, 19));
        mask = new QLineEdit(chatspace);
        mask->setObjectName(QString::fromUtf8("mask"));
        mask->setGeometry(QRect(20, 250, 661, 25));
        mask->setReadOnly(true);
        textEdit = new QTextEdit(chatspace);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(170, 340, 471, 141));
        textEdit->setMaximumSize(QSize(16777215, 160));
        textEdit->setAutoFillBackground(false);
        closebtn2 = new QPushButton(chatspace);
        closebtn2->setObjectName(QString::fromUtf8("closebtn2"));
        closebtn2->setGeometry(QRect(500, 490, 75, 27));
        mask->raise();
        changeshowstylebtn->raise();
        sendbtn->raise();
        emoji->raise();
        screancut->raise();
        editmax->raise();
        chathis->raise();
        closebtn->raise();
        maxbtn->raise();
        minbtn->raise();
        friendname->raise();
        textEdit->raise();
        closebtn2->raise();

        retranslateUi(chatspace);

        QMetaObject::connectSlotsByName(chatspace);
    } // setupUi

    void retranslateUi(QWidget *chatspace)
    {
        chatspace->setWindowTitle(QCoreApplication::translate("chatspace", "Form", nullptr));
        changeshowstylebtn->setText(QString());
        sendbtn->setText(QCoreApplication::translate("chatspace", "\345\217\221\351\200\201", nullptr));
        emoji->setText(QString());
        screancut->setText(QString());
        editmax->setText(QString());
        chathis->setText(QString());
        closebtn->setText(QCoreApplication::translate("chatspace", "PushButton", nullptr));
        maxbtn->setText(QCoreApplication::translate("chatspace", "PushButton", nullptr));
        minbtn->setText(QCoreApplication::translate("chatspace", "PushButton", nullptr));
        friendname->setText(QCoreApplication::translate("chatspace", "TextLabel", nullptr));
        closebtn2->setText(QCoreApplication::translate("chatspace", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chatspace: public Ui_chatspace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATSPACE_H
