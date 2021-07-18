#include "personlistbuddy.h"

personListBuddy::personListBuddy(QWidget *parent) : QWidget(parent)
{
    initUi();
    account=0;
}

//初始化Ui
void personListBuddy::initUi()
{
    //初始化
    head=new QWidget(this);
    name=new QLabel(this);
    sign=new QLabel(this);
    //设置头像大小
    head->setFixedSize(40,40);
    //设置个性签名字体为灰色
    QPalette color;
    color.setColor(QPalette::Text,Qt::gray);
    sign->setPalette(color);
    //布局
    head->move(7,7);
    name->move(54,10);
    sign->move(54,27);
    //装载事件过滤器
    head->installEventFilter(this);


}
//事件过滤器，主要是为了让图片能够全部填充在head里面
bool personListBuddy::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == head)
    {
        if(event->type() == QEvent::Paint)
        {
            QPainter painter(head);
            painter.drawPixmap(head->rect(),QPixmap(headPath));
        }
    }
    return QWidget::eventFilter(obj, event);
}

void personListBuddy::settips()
{
    sign->setToolTip(sign->text());
}

void personListBuddy::setread(int isread)
{
    if(isread==0)
    {
        QPalette color;
        color.setColor(QPalette::Text,Qt::gray);
        sign->setPalette(color);
    }
    else
    {
        QPalette color;
        color.setColor(QPalette::Text,Qt::red);
        sign->setPalette(color);
    }
}

void personListBuddy::mouseDoubleClickEvent(QMouseEvent *)
{
    emit doubleclick(account);
    setread(0);
}

void personListBuddy::windowclose(int a)
{
    qDebug()<<"get"<<a;
    //area.remove(a);
}

void personListBuddy::newmessage(QString wo, int isread)
{
    QString temp="";
    while(!wo.isEmpty())
    {
        if(wo[0]!='\n')
        {
            temp+=wo[0];
        }
        wo.remove(0,1);
    }
    sign->setText(temp);
    setread(isread);
    settips();
}

void personListBuddy::setlength(int len)
{
    sign->setFixedSize(len,27);
}
