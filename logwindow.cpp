#include "logwindow.h"
#include "ui_logwindow.h"

logwindow::logwindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::logwindow)
{
    ui->setupUi(this);//窗口去边框
    setWindowFlag(Qt::FramelessWindowHint);
    //设置窗口透明
    setAttribute(Qt::WA_TranslucentBackground);
    //设置窗口大小
    setFixedSize(500,300);
    chacktime = new QTimer(this);
    connect(chacktime, SIGNAL(timeout()), this, SLOT(handleTimeout()));
    setWindowTitle("KK3.2-登录");
    pixmap.load("./files/logwin/images/background.png");
    LOGO.load("./files/logwin/images/logo.png");
    InitObject();
    Initstyle();
}

void logwindow::handleTimeout()
{
    //qDebug()<<"Enter timeout processing function\n";
    if(chacktime->isActive()){
        int account;
        account=ui->userin->text().toInt();
        QFile temp(QString("./files/%1/faces/%2.jpg").arg(account).arg(account));
        if(temp.exists())
        {
            ui->face->setStyleSheet(QString("QLabel{"
                                            "border-image: url(./files/%1/faces/%2.jpg);"
                                            "border-radius: 50px transparent;"
                                            "}").arg(account).arg(account));
        }else
        {
            ui->face->setStyleSheet("QLabel{"
                                    "border-image: url(./files//logwin/images/face.png);"
                                    "border-radius: 50px transparent;"
                                    "}");
        }
        chacktime->stop();
    }
}

void logwindow::Initstyle()
{
    ui->logo->setStyleSheet("QLabel{"
                            "border-image:url(./files/logwin/images/logo.png);"
                            "}");
    ui->face->setStyleSheet("QLabel{"
                            "border-image: url(./files/logwin/images/face.png);"
                            "border-radius: 50px transparent;"
                            "}");
    ui->login->setStyleSheet("QPushButton{"
                             "border-radius: 15px;"
                             "background-color:rgb(17,174,243);"
                             "}"
                             "QPushButton:hover{"
                             "border-radius: 15px;"
                             "background-color:rgb(34,189,243);"
                             "}"
                             "QPushButton:pressed{"
                             "border-radius: 15px;"
                             "background-color:rgb(10,160,243);"
                             "}");
    ui->user->setStyleSheet("QLabel{"
                            "font-size: 16px;"
                            "font-weight: 600;"
                            "}");
    ui->pass->setStyleSheet("QLabel{"
                            "font-size: 16px;"
                            "font-weight: 600;"
                            "}");
    ui->userin->setStyleSheet("QLineEdit{"
                              "background-color: rgba(255,255,255,0.5);"
                              "font-size: 16px;"
                              "font-weight: 600;"
                              "}");
    ui->passwordin->setStyleSheet("QLineEdit{"
                                  "background-color: rgba(255,255,255,0.5);"
                                  "font-size: 16px;"
                                  "font-weight: 600;"
                                  "}");
}

void logwindow::InitObject()
{
    ui->logo->setFixedSize(150,88);
    ui->logo->move((this->width()-ui->logo->width())/2,30);
    ui->logo->setText("");
    ui->face->setFixedSize(100,100);
    ui->face->move(50,130);
    ui->face->setText("");
    ui->login->setFixedSize(150,40);
    ui->login->move((this->width()-ui->login->width())/2,230);
    ui->user->move(160,140);
    ui->user->setText("账号:");
    ui->userin->move(210,140);
    ui->userin->setFixedSize(200,30);
    ui->pass->move(160,190);
    ui->pass->setText("密码:");
    ui->passwordin->move(210,180);
    ui->passwordin->setFixedSize(200,30);
    ui->login->setDisabled(true);
    //限制账号只能输入数字
    QRegExp regx("[0-9]+$");
    QValidator* validator = new QRegExpValidator(regx, ui->userin);
    ui->userin->setValidator(validator);
    //----

}

void logwindow::paintEvent(QPaintEvent *)
{

    QPainter pain;
    pain.begin(this);
    pain.drawPixmap(0,0,width(),height(),pixmap);
    pain.end();
}

void logwindow::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        move(event->globalPos()-p);
    }
}

void logwindow::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<event->x()<<event->y();
    if(event->button()==Qt::LeftButton)
    {
        p=event->globalPos()-frameGeometry().topLeft();
    }else
    {
        emit loginwinclose();
        close();
    }
}

void logwindow::readytolog()
{
    ui->login->setEnabled(true);
}

void logwindow::on_userin_textChanged(const QString &)
{
    //设置输入延迟检查，等待用户输入完全后在查找头像。
    if(chacktime->isActive())
    {
        chacktime->start(250);
    }else
    {
        chacktime->start(250);

    }

}

void logwindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return){
        on_login_clicked();
    }else if(event->key() == Qt::Key_Tab)
    {
        if(ui->userin->hasFocus())
        {
            ui->passwordin->grabMouse();
        }else
        {
            ui->userin->grabMouse();
        }
    }
}

logwindow::~logwindow()
{
    delete ui;
}


void logwindow::on_login_clicked()
{
    if(ui->userin->text()=="")
    {
        QMessageBox::information(this,tr("error"),tr("username NULL!"));
        return;
    }
    if(ui->passwordin->text()=="")
    {
        QMessageBox::information(this,tr("error"),tr("password NULL!"));
        return;
    }
    emit login(ui->userin->text().toInt(),ui->passwordin->text());
}
