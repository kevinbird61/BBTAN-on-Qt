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
    settingBg();
    ui->graphicsView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::settingBg()
{
    QImage bg;
    bg.load("../img/open.jpg");
    bg = bg.scaled(370,630);
    scene->setBackgroundBrush(bg);
    /* Goto setting the initial page for bbtan */
    scene->Init();
}
