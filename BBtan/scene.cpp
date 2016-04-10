#include "scene.h"

Scene::Scene(QObject *parent)
{

}

void Scene::Init()
{
    btn_start = new Btn();
    QObject::connect((QGraphicsPixmapItem*)btn_start,SIGNAL(sender()),this,SLOT(bgChange()));
    QPixmap start;
    start.load("../img/btn_start.jpg");
    start = start.scaled(start.width()*3/2,start.height()*3/2,Qt::KeepAspectRatio);
    btn_start->setPixmap(start);
    btn_start->setPos(200,390);
    addItem(btn_start);
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}

void Scene::bgChange()
{
    /* first , change background picture */
    QImage bg;
    bg.load("../img/icon.png");
    bg = bg.scaled(370,630);
    this->setBackgroundBrush(bg);
    /* second , remove btn - start and change ball */
    this->removeItem(btn_start);
    //this->removeItem();
}

