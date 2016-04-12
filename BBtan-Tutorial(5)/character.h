#ifndef CHARACTER_H
#define CHARACTER_H

#include <qobject.h>
#include <QGraphicsPixmapItem>
#include <iostream>
#include "ball.h"

using namespace std;

class Character : public QObject , public QGraphicsPixmapItem
        /* moc.exe requires to derive from QObject first */
{
    Q_OBJECT

public:
    Character(Ball *ball, int static_y_pos);
    void advance(int phase);

    Ball *b;
    int y_pos;
    int mutex_for_block;

signals:
    void BallIsOnFloor();
};

#endif // CHARACTER_H
