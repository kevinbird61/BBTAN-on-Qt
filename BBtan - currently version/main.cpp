#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    // ================= Setting Windows Size =================
    QDesktopWidget wid;
    int screenW = 400;
    int screenH = 700;
    w.setGeometry(wid.screen()->width()/2 - (screenW/2) , wid.screen()->height()/2 - (screenH/2) , screenW , screenH);
    // ================= Setting Windows Title and Icon =================
    w.setWindowTitle("BBTAN");
    w.setWindowIcon(QIcon(":/image/img/icon.png"));
    w.setFixedSize(screenW , screenH);
    w.show();
    return a.exec();
}
