/********************************************************************************
** Form generated from reading UI file 'addwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDWINDOW_H
#define UI_ADDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addwindow
{
public:
    QLabel *logo;
    QLabel *searchlabel;
    QLineEdit *searcedit;
    QPushButton *searcbtn;
    QPushButton *locatedbtn;
    QComboBox *sex;
    QComboBox *age;
    QPushButton *closebtn;
    QPushButton *hidebtn;
    QLabel *sexlabel;
    QLabel *agelabel;
    QPushButton *hidedetailbtn;
    QCheckBox *Exact_btn;
    QLabel *bgimage;
    QLabel *namelabel;
    QLabel *signlabel;
    QPushButton *facebtn;
    QPushButton *addbtn;
    QFrame *line;
    QWidget *groupch;
    QRadioButton *group1btn;
    QRadioButton *group3btn;
    QRadioButton *group4btn;
    QPushButton *okbtn;
    QRadioButton *group2btn;
    QLabel *status;
    QPushButton *backbtn;
    QLabel *mask;

    void setupUi(QWidget *addwindow)
    {
        if (addwindow->objectName().isEmpty())
            addwindow->setObjectName(QString::fromUtf8("addwindow"));
        addwindow->resize(400, 300);
        logo = new QLabel(addwindow);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(10, 10, 47, 19));
        searchlabel = new QLabel(addwindow);
        searchlabel->setObjectName(QString::fromUtf8("searchlabel"));
        searchlabel->setGeometry(QRect(50, 10, 47, 19));
        searcedit = new QLineEdit(addwindow);
        searcedit->setObjectName(QString::fromUtf8("searcedit"));
        searcedit->setGeometry(QRect(20, 50, 113, 25));
        searcbtn = new QPushButton(addwindow);
        searcbtn->setObjectName(QString::fromUtf8("searcbtn"));
        searcbtn->setGeometry(QRect(230, 50, 75, 27));
        locatedbtn = new QPushButton(addwindow);
        locatedbtn->setObjectName(QString::fromUtf8("locatedbtn"));
        locatedbtn->setGeometry(QRect(10, 100, 75, 27));
        sex = new QComboBox(addwindow);
        sex->setObjectName(QString::fromUtf8("sex"));
        sex->setGeometry(QRect(100, 100, 62, 25));
        age = new QComboBox(addwindow);
        age->setObjectName(QString::fromUtf8("age"));
        age->setGeometry(QRect(180, 100, 62, 25));
        closebtn = new QPushButton(addwindow);
        closebtn->setObjectName(QString::fromUtf8("closebtn"));
        closebtn->setGeometry(QRect(320, 0, 75, 27));
        hidebtn = new QPushButton(addwindow);
        hidebtn->setObjectName(QString::fromUtf8("hidebtn"));
        hidebtn->setGeometry(QRect(230, 0, 75, 27));
        sexlabel = new QLabel(addwindow);
        sexlabel->setObjectName(QString::fromUtf8("sexlabel"));
        sexlabel->setGeometry(QRect(100, 100, 47, 19));
        agelabel = new QLabel(addwindow);
        agelabel->setObjectName(QString::fromUtf8("agelabel"));
        agelabel->setGeometry(QRect(180, 100, 47, 19));
        hidedetailbtn = new QPushButton(addwindow);
        hidedetailbtn->setObjectName(QString::fromUtf8("hidedetailbtn"));
        hidedetailbtn->setGeometry(QRect(140, 0, 75, 27));
        Exact_btn = new QCheckBox(addwindow);
        Exact_btn->setObjectName(QString::fromUtf8("Exact_btn"));
        Exact_btn->setEnabled(false);
        Exact_btn->setGeometry(QRect(150, 50, 71, 23));
        Exact_btn->setCheckable(true);
        Exact_btn->setChecked(true);
        bgimage = new QLabel(addwindow);
        bgimage->setObjectName(QString::fromUtf8("bgimage"));
        bgimage->setGeometry(QRect(260, 130, 121, 81));
        namelabel = new QLabel(addwindow);
        namelabel->setObjectName(QString::fromUtf8("namelabel"));
        namelabel->setGeometry(QRect(260, 140, 101, 81));
        signlabel = new QLabel(addwindow);
        signlabel->setObjectName(QString::fromUtf8("signlabel"));
        signlabel->setGeometry(QRect(240, 220, 47, 19));
        facebtn = new QPushButton(addwindow);
        facebtn->setObjectName(QString::fromUtf8("facebtn"));
        facebtn->setGeometry(QRect(170, 190, 75, 27));
        addbtn = new QPushButton(addwindow);
        addbtn->setObjectName(QString::fromUtf8("addbtn"));
        addbtn->setGeometry(QRect(150, 240, 75, 27));
        addbtn->setCursor(QCursor(Qt::PointingHandCursor));
        line = new QFrame(addwindow);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(220, 170, 118, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        groupch = new QWidget(addwindow);
        groupch->setObjectName(QString::fromUtf8("groupch"));
        groupch->setGeometry(QRect(30, 120, 141, 161));
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
        mask = new QLabel(addwindow);
        mask->setObjectName(QString::fromUtf8("mask"));
        mask->setGeometry(QRect(310, 260, 47, 19));
        bgimage->raise();
        logo->raise();
        searchlabel->raise();
        searcedit->raise();
        searcbtn->raise();
        locatedbtn->raise();
        sex->raise();
        age->raise();
        closebtn->raise();
        hidebtn->raise();
        sexlabel->raise();
        agelabel->raise();
        hidedetailbtn->raise();
        Exact_btn->raise();
        namelabel->raise();
        signlabel->raise();
        facebtn->raise();
        addbtn->raise();
        line->raise();
        groupch->raise();
        mask->raise();

        retranslateUi(addwindow);

        QMetaObject::connectSlotsByName(addwindow);
    } // setupUi

    void retranslateUi(QWidget *addwindow)
    {
        addwindow->setWindowTitle(QCoreApplication::translate("addwindow", "Form", nullptr));
        logo->setText(QString());
        searchlabel->setText(QCoreApplication::translate("addwindow", "\346\237\245\346\211\276", nullptr));
        searcbtn->setText(QCoreApplication::translate("addwindow", "\346\237\245  \346\211\276", nullptr));
        locatedbtn->setText(QCoreApplication::translate("addwindow", "PushButton", nullptr));
#if QT_CONFIG(tooltip)
        sex->setToolTip(QCoreApplication::translate("addwindow", "\345\271\264\351\276\204", nullptr));
#endif // QT_CONFIG(tooltip)
        closebtn->setText(QCoreApplication::translate("addwindow", "PushButton", nullptr));
        hidebtn->setText(QCoreApplication::translate("addwindow", "PushButton", nullptr));
        sexlabel->setText(QCoreApplication::translate("addwindow", "\346\200\247\345\210\253", nullptr));
        agelabel->setText(QCoreApplication::translate("addwindow", "\345\271\264\351\276\204", nullptr));
        hidedetailbtn->setText(QCoreApplication::translate("addwindow", "PushButton", nullptr));
        Exact_btn->setText(QCoreApplication::translate("addwindow", "\347\262\276\347\241\256\345\214\271\351\205\215", nullptr));
        bgimage->setText(QString());
        namelabel->setText(QString());
        signlabel->setText(QString());
        facebtn->setText(QString());
        addbtn->setText(QCoreApplication::translate("addwindow", "\345\212\240\345\245\275\345\217\213", nullptr));
        group1btn->setText(QCoreApplication::translate("addwindow", "RadioButton", nullptr));
        group3btn->setText(QCoreApplication::translate("addwindow", "RadioButton", nullptr));
        group4btn->setText(QCoreApplication::translate("addwindow", "RadioButton", nullptr));
        okbtn->setText(QCoreApplication::translate("addwindow", "\347\241\256\345\256\232", nullptr));
        group2btn->setText(QCoreApplication::translate("addwindow", "RadioButton", nullptr));
        status->setText(QString());
        backbtn->setText(QCoreApplication::translate("addwindow", "<<", nullptr));
        mask->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class addwindow: public Ui_addwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDWINDOW_H
