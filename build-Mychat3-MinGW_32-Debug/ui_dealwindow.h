/********************************************************************************
** Form generated from reading UI file 'dealwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEALWINDOW_H
#define UI_DEALWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dealwindow
{
public:
    QPushButton *closebtn;
    QPushButton *hidebtn;
    QWidget *groupch;
    QRadioButton *group1btn;
    QRadioButton *group3btn;
    QRadioButton *group4btn;
    QPushButton *okbtn;
    QRadioButton *group2btn;
    QLabel *status;
    QPushButton *backbtn;
    QLabel *chacklabel;
    QLabel *mask;

    void setupUi(QWidget *dealwindow)
    {
        if (dealwindow->objectName().isEmpty())
            dealwindow->setObjectName(QString::fromUtf8("dealwindow"));
        dealwindow->resize(400, 300);
        closebtn = new QPushButton(dealwindow);
        closebtn->setObjectName(QString::fromUtf8("closebtn"));
        closebtn->setGeometry(QRect(320, 10, 75, 27));
        hidebtn = new QPushButton(dealwindow);
        hidebtn->setObjectName(QString::fromUtf8("hidebtn"));
        hidebtn->setGeometry(QRect(230, 10, 75, 27));
        groupch = new QWidget(dealwindow);
        groupch->setObjectName(QString::fromUtf8("groupch"));
        groupch->setGeometry(QRect(150, 70, 141, 161));
        group1btn = new QRadioButton(groupch);
        group1btn->setObjectName(QString::fromUtf8("group1btn"));
        group1btn->setGeometry(QRect(29, 9, 84, 23));
        group1btn->setCursor(QCursor(Qt::PointingHandCursor));
        group1btn->setChecked(true);
        group3btn = new QRadioButton(groupch);
        group3btn->setObjectName(QString::fromUtf8("group3btn"));
        group3btn->setGeometry(QRect(29, 67, 84, 23));
        group3btn->setCursor(QCursor(Qt::PointingHandCursor));
        group4btn = new QRadioButton(groupch);
        group4btn->setObjectName(QString::fromUtf8("group4btn"));
        group4btn->setGeometry(QRect(29, 96, 84, 23));
        group4btn->setCursor(QCursor(Qt::PointingHandCursor));
        okbtn = new QPushButton(groupch);
        okbtn->setObjectName(QString::fromUtf8("okbtn"));
        okbtn->setGeometry(QRect(3, 125, 75, 27));
        okbtn->setCursor(QCursor(Qt::PointingHandCursor));
        group2btn = new QRadioButton(groupch);
        group2btn->setObjectName(QString::fromUtf8("group2btn"));
        group2btn->setGeometry(QRect(29, 38, 84, 23));
        group2btn->setCursor(QCursor(Qt::PointingHandCursor));
        status = new QLabel(groupch);
        status->setObjectName(QString::fromUtf8("status"));
        status->setGeometry(QRect(20, 60, 47, 19));
        backbtn = new QPushButton(groupch);
        backbtn->setObjectName(QString::fromUtf8("backbtn"));
        backbtn->setGeometry(QRect(100, 20, 75, 27));
        chacklabel = new QLabel(groupch);
        chacklabel->setObjectName(QString::fromUtf8("chacklabel"));
        chacklabel->setGeometry(QRect(90, 130, 47, 19));
        mask = new QLabel(dealwindow);
        mask->setObjectName(QString::fromUtf8("mask"));
        mask->setGeometry(QRect(130, 230, 47, 19));

        retranslateUi(dealwindow);

        QMetaObject::connectSlotsByName(dealwindow);
    } // setupUi

    void retranslateUi(QWidget *dealwindow)
    {
        dealwindow->setWindowTitle(QCoreApplication::translate("dealwindow", "Form", nullptr));
        closebtn->setText(QString());
        hidebtn->setText(QString());
        group1btn->setText(QCoreApplication::translate("dealwindow", "RadioButton", nullptr));
        group3btn->setText(QCoreApplication::translate("dealwindow", "RadioButton", nullptr));
        group4btn->setText(QCoreApplication::translate("dealwindow", "RadioButton", nullptr));
        okbtn->setText(QCoreApplication::translate("dealwindow", "\347\241\256\345\256\232", nullptr));
        group2btn->setText(QCoreApplication::translate("dealwindow", "RadioButton", nullptr));
        status->setText(QString());
        backbtn->setText(QCoreApplication::translate("dealwindow", "<<", nullptr));
        chacklabel->setText(QCoreApplication::translate("dealwindow", "\347\241\256\350\256\244\346\213\222\347\273\235\345\220\227\357\274\237", nullptr));
        mask->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class dealwindow: public Ui_dealwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEALWINDOW_H
