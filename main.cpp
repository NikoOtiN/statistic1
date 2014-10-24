#include "dialog.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *ww = new MainWindow();
    ww->show();


    return a.exec();
}
