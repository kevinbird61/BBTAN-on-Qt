#ifndef BLOCK_H
#define BLOCK_H

#include <QGraphicsPixmapItem>

class Block : public QGraphicsPixmapItem
{
public:
    Block(int width , int height);
    int size_w;
    int size_h;
};

#endif // BLOCK_H
