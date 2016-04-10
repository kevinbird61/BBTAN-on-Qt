#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "btn.h"

class Scene : public QGraphicsScene
{
public:
    /* function */
    Scene(QObject *parent = 0);
    void Init();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    /* Variable */
    Btn *btn_start;
public slots:
    void bgChange();

};

#endif // SCENE_H
