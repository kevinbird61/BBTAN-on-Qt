#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new Scene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(10,0,350,630);
    settingBg(10,630);
    ui->graphicsView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::settingBg(int x_start , int y_end)
{
    QImage bg;
    bg.load("../img/open.jpg");
    bg = bg.scaled(370,y_end);
    scene->setBackgroundBrush(bg);
    /* Goto setting the initial page for bbtan */
    scene->Init(x_start);
}
