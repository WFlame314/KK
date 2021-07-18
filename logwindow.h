#ifndef LOGWINDOW_H
#define LOGWINDOW_H

#include <QWidget>
#include <QEvent>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>
#include <QHostInfo>
#include <QFile>
#include <QPainter>
#include <QMouseEvent>
#include <QRegExpValidator>
#include <QDebug>
#include <QTimer>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class logwindow; }
QT_END_NAMESPACE

class logwindow : public QWidget
{
    Q_OBJECT

public:
    logwindow(QWidget *parent = nullptr);
    ~logwindow();
    void Initstyle();
    void InitObject();
    void readytolog();

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::logwindow *ui;
    QPixmap pixmap,LOGO;
    QPoint p;
    QTimer *chacktime;

signals:
    void login(int,QString);
    void loginwinclose();

private slots:
    void on_userin_textChanged(const QString &arg1);
    void on_login_clicked();
    void handleTimeout();
};
#endif // LOGWINDOW_H
