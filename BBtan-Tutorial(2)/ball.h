#ifndef BALL_H
#define BALL_H

#include <QGraphicsPixmapItem>
#include <iostream>

using namespace std;

class Ball : public QGraphicsPixmapItem
{
public:
    Ball(int upper,int lower,int left,int right);
    // For ball
    int x_speed;
    int y_speed;
    // For scene boundary
    int up;
    int low;
    int lef;
    int rig;

    void advance(int phase);
    void checkBoundary();
};

#endif // BALL_H
