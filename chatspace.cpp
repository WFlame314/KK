#include "chatspace.h"
#include "ui_chatspace.h"
#include <QDebug>

chatspace::chatspace(int a,int fa,QString name,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chatspace)
{
    ui->setupUi(this);
    account=a;
    faccount=fa;
    data=0;
    time=QTime(0,0,0);
    ismax=false;
    //窗口去边框
    setWindowFlag(Qt::FramelessWindowHint,true);
    //设置窗口透明
    //setAttribute(Qt::WA_TranslucentBackground);
    //设置窗口大小
    setFixedSize(800,600);
    //设置窗口名
    setWindowTitle(name);
    fname=name;
    bg.load(QString("./files/%1/images/bg-def.jpg").arg(account));
    wi = new QListWidget(this);
    wi->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    showchatarea = new chatshow(wi);
    QFile qss(":/styles/chatstyle.qss");
    qss.open(QFile::ReadOnly);
    showchatarea->setStyleSheet(qss.readAll());
    qss.close();
    ui->textEdit->setFocusPolicy(Qt::StrongFocus);
    ui->textEdit->setFocus();
    ui->textEdit->installEventFilter(this);
    InitObject();
    Initstyle();
}

chatspace::~chatspace()
{
    delete ui;
}

void chatspace::InitObject()
{
    ui->closebtn->setFixedSize(30,30);
    ui->closebtn->setText("×");
    ui->closebtn->move(this->width()-30,0);
    ui->maxbtn->setFixedSize(30,30);
    ui->maxbtn->setText("□");
    ui->maxbtn->move(this->width()-60,0);
    ui->minbtn->setFixedSize(30,30);
    ui->minbtn->setText("—");
    ui->minbtn->move(this->width()-90,0);
    ui->friendname->setFixedSize((this->width()-90)/2,30);
    ui->friendname->move((this->width()-90)/2,0);
    ui->friendname->setText(fname);
    //ui->friendname->setTextInteractionFlags(Qt::TextSelectableByMouse);
    wi->setFixedSize(this->width(),340);
    wi->move(0,30);
    showchatarea->setFixedSize(this->width(),340);
    showchatarea->move(5,0);
    ui->changeshowstylebtn->setFixedSize(100,30);
    ui->changeshowstylebtn->move(0,370);
    ui->changeshowstylebtn->setText("文本模式");
    ui->emoji->setFixedSize(30,30);
    ui->screancut->setFixedSize(30,30);
    ui->editmax->setFixedSize(30,30);
    ui->chathis->setFixedSize(30,30);
    ui->chathis->move(this->width()-50,370);
    ui->editmax->move(this->width()-100,370);
    ui->screancut->move(170,370);
    ui->emoji->move(120,370);
    ui->textEdit->setFixedSize(this->width(),160);
    ui->textEdit->move(0,400);
    ui->mask->setFixedSize(this->width(),30);
    ui->mask->move(0,370);
    ui->sendbtn->setFixedSize(100,30);
    ui->sendbtn->move(this->width()-120,565);
    ui->closebtn2->setFixedSize(100,30);
    ui->closebtn2->move(this->width()-230,565);
    ui->changeshowstylebtn->setToolTip("切换为"+ui->changeshowstylebtn->text()+"显示");
    ui->emoji->setToolTip("表情");
    ui->screancut->setToolTip("屏幕截图");
    ui->editmax->setToolTip("全屏输入");
    ui->chathis->setToolTip("历史记录");
}

void chatspace::Initstyle()
{
    ui->textEdit->setStyleSheet("QTextEdit{color: black; "
                                "background-color: rgba(255,255,255,0.5); "
                                "border:0px solid red;"
                                "font-size:16px;"
                                "}");
    ui->textEdit->verticalScrollBar()->setStyleSheet("QScrollBar:vertical {"
                                                     "background:transparent;"
                                                     "width:9px;"
                                                     "margin: 0px 0px 2px 0px;"
                                                     "}"
                                                     "QScrollBar::handle:vertical {"
                                                     "background: rgb(195, 195, 195);"
                                                     "min-height: 20px;"
                                                     "border-radius: 3px;"
                                                     "}"
                                                     "QScrollBar::handle:vertical:hover{"
                                                     "background:rgba(0,0,0,30%);"
                                                     "}"
                                                     "QScrollBar::add-line:vertical {"
                                                     "height: 0px;"
                                                     "subcontrol-position: bottom;"
                                                     "subcontrol-origin: margin;"
                                                     "}"
                                                     "QScrollBar::sub-line:vertical {"
                                                     "height: 0px;"
                                                     "subcontrol-position: top;"
                                                     "subcontrol-origin: margin;"
                                                     "}");
    ui->closebtn->setStyleSheet("QPushButton{"
                                "background-color: rgba(255,255,255,0);"
                                "font-size:20px;"
                                "color: rgb(255,255,255);"
                                "}"
                                "QPushButton:hover{"
                                "background-color: rgba(175,0,0,0.3);"
                                "font-size:20px;"
                                "}"
                                "QPushButton:pressed{"
                                "background-color: rgba(255,0,0,0.3);"
                                "font-size:20px;"
                                "}");
    ui->maxbtn->setStyleSheet("QPushButton{"
                               "background-color: rgba(255,255,255,0);"
                               "font-size:16px;"
                               "color: rgb(255,255,255);"
                               "}"
                               "QPushButton:hover{"
                               "background-color: rgba(255,255,255,0.3);"
                               "font-size:16px;"
                               "}"
                               "QPushButton:pressed{"
                               "background-color: rgba(255,255,255,0.5);"
                               "font-size:16px;"
                               "}");
    ui->minbtn->setStyleSheet("QPushButton{"
                              "background-color: rgba(255,255,255,0);"
                              "font-size:16px;"
                              "color: rgb(255,255,255);"
                              "}"
                              "QPushButton:hover{"
                              "background-color: rgba(255,255,255,0.3);"
                              "font-size:16px;"
                              "}"
                              "QPushButton:pressed{"
                              "background-color: rgba(255,255,255,0.5);"
                              "font-size:16px;"
                              "}");
    ui->friendname->setStyleSheet("QLabel{"
                                  "font-size:16px;"
                                  "margin-top: 2px;"
                                  "font-weight:600;"
                                  "color: rgb(255,255,255);"
                                  "}");
    wi->setStyleSheet("QListWidget{"
                      "background: rgba(255,255,255,0.5);"
                      "}");
    ui->mask->setStyleSheet("QLineEdit{"
                                "background-color: rgba(255,255,255,0.5);"
                                "font-size: 16px;"
                                "font-weight: 600;"
                                "border: 1px 0px 0px 0px solid black;"
                                "}");
    ui->changeshowstylebtn->setStyleSheet("QPushButton{"
                                          "background-color: rgba(255,255,255,0);"
                                          "font-size:16px;"
                                          "color: rgb(255,255,255);"
                                          "}"
                                          "QPushButton:hover{"
                                          "background-color: rgba(255,255,255,0.3);"
                                          "font-size:16px;"
                                          "border-radius: 5px;"
                                          "border:1px solid gray;"
                                          "}"
                                          "QPushButton:pressed{"
                                          "background-color: rgba(255,255,255,0.5);"
                                          "font-size:16px;"
                                          "border-radius: 5px;"
                                          "border:1px solid gray;"
                                          "}");
    ui->emoji->setStyleSheet("QPushButton{"
                             "background-color: rgba(255,255,255,0);"
                             "font-size:16px;"
                             "border-image: url(./files/logwin/images/emoji.png);"
                             "}"
                             "QPushButton:hover{"
                             "background-color: rgba(255,255,255,0.3);"
                             "font-size:16px;"
                             "border-radius: 5px;"
                             "border:1px solid gray;"
                             "}"
                             "QPushButton:pressed{"
                             "background-color: rgba(255,255,255,0.5);"
                             "font-size:16px;"
                             "border-radius: 5px;"
                             "border:1px solid gray;"
                             "}");
    ui->screancut->setStyleSheet("QPushButton{"
                                 "background-color: rgba(255,255,255,0);"
                                 "font-size:16px;"
                                 "border-image: url(./files/logwin/images/cut.png);"
                                 "}"
                                 "QPushButton:hover{"
                                 "background-color: rgba(255,255,255,0.3);"
                                 "font-size:16px;"
                                 "border-radius: 5px;"
                                 "border:1px solid gray;"
                                 "}"
                                 "QPushButton:pressed{"
                                 "background-color: rgba(255,255,255,0.5);"
                                 "font-size:16px;"
                                 "border-radius: 5px;"
                                 "border:1px solid gray;"
                                 "}");
    ui->editmax->setStyleSheet("QPushButton{"
                               "background-color: rgba(255,255,255,0);"
                               "font-size:16px;"
                               "border-image: url(./files/logwin/images/tobig.png);"
                               "}"
                               "QPushButton:hover{"
                               "background-color: rgba(255,255,255,0.3);"
                               "font-size:16px;"
                               "border-radius: 5px;"
                               "border:1px solid gray;"
                               "}"
                               "QPushButton:pressed{"
                               "background-color: rgba(255,255,255,0.5);"
                               "font-size:16px;"
                               "border-radius: 5px;"
                               "border:1px solid gray;"
                               "}");
    ui->chathis->setStyleSheet("QPushButton{"
                               "background-color: rgba(255,255,255,0);"
                               "font-size:16px;"
                               "border-image: url(./files/logwin/images/chathis.png);"
                               "}"
                               "QPushButton:hover{"
                               "background-color: rgba(255,255,255,0.3);"
                               "font-size:16px;"
                               "border-radius: 5px;"
                               "border:1px solid gray;"
                               "}"
                               "QPushButton:pressed{"
                               "background-color: rgba(255,255,255,0.5);"
                               "font-size:16px;"
                               "border-radius: 5px;"
                               "border:1px solid gray;"
                               "}");
    ui->sendbtn->setStyleSheet("QPushButton{"
                               "background-color: rgba(255,255,255,0.3);"
                               "font-size:16px;"
                               "color: rgb(255,255,255);"
                               "border-radius: 5px;"
                               "border:1px solid gray;"
                               "}"
                               "QPushButton:hover{"
                               "background-color: rgba(255,255,255,0.5);"
                               "font-size:16px;"
                               "border-radius: 5px;"
                               "border:1px solid gray;"
                               "}"
                               "QPushButton:pressed{"
                               "background-color: rgba(255,255,255,0.7);"
                               "font-size:16px;"
                               "border-radius: 5px;"
                               "border:1px solid gray;"
                               "}");
    ui->closebtn2->setStyleSheet("QPushButton{"
                                 "background-color: rgba(255,255,255,0.3);"
                                 "font-size:16px;"
                                 "color: rgb(255,255,255);"
                                 "border-radius: 5px;"
                                 "border:1px solid gray;"
                                 "}"
                                 "QPushButton:hover{"
                                 "background-color: rgba(255,255,255,0.5);"
                                 "font-size:16px;"
                                 "border-radius: 5px;"
                                 "border:1px solid gray;"
                                 "}"
                                 "QPushButton:pressed{"
                                 "background-color: rgba(255,255,255,0.7);"
                                 "font-size:16px;"
                                 "border-radius: 5px;"
                                 "border:1px solid gray;"
                                 "}");

}

void chatspace::paintEvent(QPaintEvent *)
{
    QPainter pain;
    pain.begin(this);
    pain.drawPixmap(0,0,width(),height(),bg);
    pain.end();
}

void chatspace::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        move(event->globalPos()-p);
    }
}

void chatspace::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<event->x()<<event->y();
    if(event->button()==Qt::LeftButton)
    {
        p=event->globalPos()-frameGeometry().topLeft();
    }
}

bool chatspace::eventFilter(QObject *target, QEvent *event)
{
    if(target == ui->textEdit)
    {
        if(event->type() == QEvent::KeyPress)//回车键
        {
            QKeyEvent *k = static_cast<QKeyEvent *>(event);
            if(k->key() == Qt::Key_Return)
            {
                on_sendbtn_clicked();
                return true;
            }
        }
    }
    return QWidget::eventFilter(target,event);
}

void chatspace::on_closebtn_clicked()
{
    emit myclose(faccount);
}

void chatspace::on_sendbtn_clicked()
{

    if(ui->textEdit->toPlainText()=="")
    {
        QMessageBox::information(this,tr("内容为空"),tr("发送内容不能为空"));
    }
    else
    {
        emit sendmessage(faccount,ui->textEdit->toPlainText().toUtf8(),QDate::currentDate(),QTime::currentTime());
        ui->textEdit->setText("");
    }
    qDebug()<<"send";
}

void chatspace::addchathis(int type, int acc, int facc, QString word, int tdata ,int ttime)
{
    QDate d(tdata/10000,(tdata-(tdata/10000)*10000)/100,tdata-(tdata/100)*100);
    QTime t(ttime/10000,(ttime-(ttime/10000)*10000)/100,ttime-(ttime/100)*100);
    if(tdata!=data)
    {
        data=tdata;
        if(tdata!=(QDate::currentDate().year()*10000+QDate::currentDate().month()*100+QDate::currentDate().day()))
        {
            showchatarea->addtime(d.toString(Qt::ISODate)+" "+t.toString());
        }
        else
        {
            showchatarea->addtime(t.toString());
        }
        time=t;
    }
    else
    {
        qDebug()<<t.msecsSinceStartOfDay()<<time.msecsSinceStartOfDay();
        qDebug()<<t.msecsSinceStartOfDay()-time.msecsSinceStartOfDay();
        if(tdata!=(QDate::currentDate().year()*10000+QDate::currentDate().month()*100+QDate::currentDate().day()))
        {
            if(t.msecsSinceStartOfDay()-time.msecsSinceStartOfDay()>300000)
            {
                showchatarea->addtime(d.toString(Qt::ISODate)+" "+t.toString());
            }
        }
        else
        {
            if(t.msecsSinceStartOfDay()-time.msecsSinceStartOfDay()>300000)
            {
                showchatarea->addtime(t.toString());
            }
        }
        time=t;

    }
    showchatarea->addchat(type,facc,acc,word);
    showchatarea->scrollToBottom();
}

void chatspace::on_minbtn_clicked()
{
    showMinimized();
}

void chatspace::on_closebtn2_clicked()
{
    on_closebtn_clicked();
}

void chatspace::on_editmax_clicked()
{
    if(ismax)
    {
        ui->editmax->setStyleSheet("QPushButton{"
                                   "background-color: rgba(255,255,255,0);"
                                   "font-size:16px;"
                                   "border-image: url(./files/logwin/images/tobig.png);"
                                   "}"
                                   "QPushButton:hover{"
                                   "background-color: rgba(255,255,255,0.3);"
                                   "font-size:16px;"
                                   "border-radius: 5px;"
                                   "border:1px solid gray;"
                                   "}"
                                   "QPushButton:pressed{"
                                   "background-color: rgba(255,255,255,0.5);"
                                   "font-size:16px;"
                                   "border-radius: 5px;"
                                   "border:1px solid gray;"
                                   "}");
        ismax=false;
        ui->changeshowstylebtn->move(0,370);
        ui->chathis->move(this->width()-50,370);
        ui->editmax->move(this->width()-100,370);
        ui->screancut->move(170,370);
        ui->emoji->move(120,370);
        ui->textEdit->setFixedSize(this->width(),160);
        ui->textEdit->move(0,400);
        ui->mask->move(0,370);
        ui->editmax->setToolTip("全屏输入");
        wi->show();

    }
    else
    {
        ui->editmax->setStyleSheet("QPushButton{"
                                   "background-color: rgba(255,255,255,0);"
                                   "font-size:16px;"
                                   "border-image: url(./files/logwin/images/tosmall.png);"
                                   "}"
                                   "QPushButton:hover{"
                                   "background-color: rgba(255,255,255,0.3);"
                                   "font-size:16px;"
                                   "border-radius: 5px;"
                                   "border:1px solid gray;"
                                   "}"
                                   "QPushButton:pressed{"
                                   "background-color: rgba(255,255,255,0.5);"
                                   "font-size:16px;"
                                   "border-radius: 5px;"
                                   "border:1px solid gray;"
                                   "}");
        ismax=true;
        ui->changeshowstylebtn->move(0,30);
        ui->chathis->move(this->width()-50,30);
        ui->editmax->move(this->width()-100,30);
        ui->screancut->move(170,30);
        ui->emoji->move(120,30);
        ui->textEdit->setFixedSize(this->width(),this->height()-100);
        ui->textEdit->move(0,60);
        ui->mask->move(0,30);
        ui->editmax->setToolTip("恢复");
        wi->hide();

    }
}
