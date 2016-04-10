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
    Btn *btn_change_ball;
    Btn *btn_pause;
    Btn *btn_conti;
    Btn *btn_back;
    int btn_w;
    int btn_h;
    int btn_small_w;
    int btn_small_h;
    // Use to control the scene page
    int screenMode;

public slots:
    void bgChange();
    void bgRecover();

};

#endif // SCENE_H
