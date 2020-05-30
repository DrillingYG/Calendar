#include "mainwindow.h"

#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDesktopWidget desktop;
    MainWindow w;

    w.setGeometry(desktop.width() - w.width(), 36, w.width(), w.height());
    w.show();
    return a.exec();
}
