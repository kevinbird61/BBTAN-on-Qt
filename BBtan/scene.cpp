#include "scene.h"

Scene::Scene(QObject *parent)
{
    screenMode = 0;
}

void Scene::Init()
{
    btn_start = new Btn();
    QPixmap start;
    start.load("../img/btn_start.jpg");
    start = start.scaled(start.width()*3/2,start.height()*3/2,Qt::KeepAspectRatio);
    btn_w = start.width()*3/2;
    btn_h = start.height()*3/2;
    btn_start->setPixmap(start);
    btn_start->setPos(200,390);
    addItem(btn_start);
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(screenMode == 0)
    {
        // Beginning page
        if(event->scenePos().x() > btn_start->pos().x() && event->scenePos().x() <= btn_start->pos().x()+btn_w)
        {
            // Now x is in range , judge y
            if(event->scenePos().y() > btn_start->pos().y() && event->scenePos().y() <= btn_start->pos().y()+btn_h)
            {
                // x , y both in button area
                cout<< "Button get"<< endl;
                bgChange();
            }
        }
    }

    cout << "btn start x: " << btn_start->pos().x()<< " btn start y: " << btn_start->pos().y() << endl;
    cout << "Now event x: " << event->scenePos().x()<< " event y: " << event->scenePos().y() << endl;
}

void Scene::bgChange()
{
    /* first , change background picture */
    QImage bg;
    bg.load("../img/start.jpg");
    bg = bg.scaled(370,630);
    this->setBackgroundBrush(bg);
    /* second , remove btn - start and change ball */
    this->removeItem(btn_start);
    //this->removeItem();
}

