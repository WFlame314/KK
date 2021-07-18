#include "words.h"

words::words(int l,QWidget *parent) : QWidget(parent)
{
    len=l;
    InitObject();
}

void words::InitObject()
{
    head = new QLabel(this);
    word = new QLabel(this);
    head->move(7,7);
    head->setFixedSize(30,30);
    word->move(40,10);
}

void words::setword(QString words, int account,int faccount,int type,bool end)
{
    word->setText(words);
    word->setFixedSize(len*8+8,27);
    head->setStyleSheet(QString("QLabel{"
                                "border-image: url(./files/%1/faces/%2.jpg);"
                                "border-radius: 20px transparent;"
                                "}").arg(account).arg(faccount));
    if(end)
    {
        word->setStyleSheet("QLabel{"
                            "font-size: 16px;"
                            "background: rgba(175,175,175,0.3);"
                            "border-radius: 5px;"
                            "border:1px solid black;"
                            "}");
    }else
    {
        word->setStyleSheet("QLabel{"
                            "font-size: 16px;"
                            "background: rgba(175,175,175,0.3);"
                            "border-top-left-radius: 5px;"
                            "border-top-right-radius: 5px;"
                            "border-left:1px solid black;"
                            "border-right:1px solid black;"
                            "border-top:1px solid black;"
                            "}");
    }
    if(type==1)
    {
        head->setStyleSheet(QString("QLabel{"
                                    "border-image: url(./files/%1/faces/%2.jpg);"
                                    "border-radius: 20px transparent;"
                                    "}").arg(account).arg(account));
        head->move(this->width()+100,7);
        word->move(this->width()-word->width()+97,10);
    }

}

void words::setjustword(QString words, int ,int ,int type,bool end)
{
    delete head;
    word->setText(words);
    word->setFixedSize(len*8+8,27);
    if(end)
    {
        word->setStyleSheet("QLabel{"
                            "font-size: 16px;"
                            "background: rgba(175,175,175,0.3);"
                            "border-bottom-left-radius: 5px;"
                            "border-bottom-right-radius: 5px;"
                            "border-left:1px solid black;"
                            "border-right:1px solid black;"
                            "border-bottom:1px solid black;"
                            "}");
    }else
    {
        word->setStyleSheet("QLabel{"
                            "font-size: 16px;"
                            "background: rgba(175,175,175,0.3);"
                            "padding-left: 1px;"
                            "border-left:1px solid black;"
                            "border-right:1px solid black;"
                            "}");
    }
    word->move(40,0);
    if(type==1)
    {
        word->move(this->width()-word->width()+97,0);
    }

}

