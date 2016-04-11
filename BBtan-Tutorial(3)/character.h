#ifndef CHARACTER_H
#define CHARACTER_H

#include <QGraphicsPixmapItem>
#include <iostream>
#include "ball.h"

using namespace std;

class Character : public QGraphicsPixmapItem
{
public:
    Character(Ball *ball, int static_y_pos);
    void advance(int phase);

    Ball *b;
    int y_pos;
};

#endif // CHARACTER_H
