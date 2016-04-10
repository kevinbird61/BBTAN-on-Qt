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
    int btn_w;
    int btn_h;
    // Use to control the scene page
    int screenMode;

public slots:
    void bgChange();

};

#endif // SCENE_H
