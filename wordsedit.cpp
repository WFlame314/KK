#include "wordsedit.h"

wordsedit::wordsedit(QWidget *parent) : QWidget(parent)
{
    InitObject();
}

void wordsedit::InitObject()
{
    head = new QLabel(this);
    word = new QLabel(this);
    head->move(7,7);
    head->setFixedSize(30,30);
    word->move(40,10);
}

void wordsedit::setword(QString words, int account,int faccount,int type)
{
    word->setText(words);
    word->setFixedSize(words.length()*17,27);
    head->setStyleSheet(QString("QLabel{"
                                "border-image: url(./files/%1/faces/%2.jpg);"
                                "border-radius: 20px transparent;"
                                "}").arg(account).arg(faccount));
    word->setStyleSheet("QLabel{"
                        "font-size: 16px;"
                        "}");
    if(type==1)
    {
        head->setStyleSheet(QString("QLabel{"
                                    "border-image: url(./files/%1/faces/%2.jpg);"
                                    "border-radius: 20px transparent;"
                                    "}").arg(account).arg(account));
        head->move(this->width()+100,7);
        word->move(this->width()-word->width()+100,10);
    }

}

void wordsedit::setjustword(QString words, int ,int ,int type)
{
    word->setText(words);
    word->setFixedSize(words.length()*17,27);
    word->setStyleSheet("QLabel{"
                        "font-size: 16px;"
                        "}");
    if(type==1)
    {
        head->hide();
        word->move(this->width()-340+100,10);
    }

}

