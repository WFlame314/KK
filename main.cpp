#include "logwindow.h"
#include "base.h"

#include <QApplication>
#include <QMap>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);
    base w;
    //w.show();

    return a.exec();
}
