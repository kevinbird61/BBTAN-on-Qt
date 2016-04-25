#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new Scene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(10,0,300,600); // change the value to fit
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
    bg = bg.scaled(370,630); // you can also change here
    scene->setBackgroundBrush(bg);
    /* Goto setting the initial page for bbtan */
    scene->Init();
}
