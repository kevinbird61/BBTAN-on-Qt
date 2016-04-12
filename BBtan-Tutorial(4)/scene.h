#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QSound>
#include "btn.h"
#include "character.h"
#include "ball.h"
#include "block.h"

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    /* function */
    Scene();
    void Init(int x_start ); // For screen initialize
    void bgChange(); // For background change from start to game
    void bgRecover(); // For background change back to start page
    void gameInit(); // Start the game page
    void movingBlock(); // Moving block down
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    /* Variable */
    // For button
    Btn *btn_start;
    Btn *btn_change_ball;
    Btn *btn_pause;
    Btn *btn_conti;
    Btn *btn_back;
    int btn_w;
    int btn_h;
    int btn_small_w;
    int btn_small_h;
    // For game item
    Character *man;
    Ball *ball;
    int ch_y_pos;
    // For block
    QList<Block *> list;

    // For sound
    QSound *bgm;

    // For timer
    QTimer *timer;
    /* Use to control the scene page */
    int screenMode;
    // For scene boundary
    int upperBound;
    int lowerBound;
    int leftBound;
    int rightBound;

public slots:
    void geneNextBlock();
    void DoCollision();
};

#endif // SCENE_H
