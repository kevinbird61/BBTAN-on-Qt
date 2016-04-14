#include "character.h"

Character::Character(Ball *ball, int static_y_pos)
{
    b = ball;
    y_pos = static_y_pos;
    mutex_for_block = 1;
}

void Character::advance(int phase)
{
    if(b->x_speed == 0 && b->y_speed == 0)
    {
        // setting man's position to here
        while(this->pos().x() != b->pos().x())
        {
            if(this->pos().x() < b->pos().x())
            {
                int x = this->pos().x() + 1;
                this->setPos( x , y_pos);
            }
            else{
                int x = this->pos().x() - 1;
                this->setPos( x , y_pos);
            }
        }

        if(mutex_for_block == 0)
        {
            // emit the signals
            mutex_for_block = 1;
            emit BallIsOnFloor();
        }
    }
    else {
        if(mutex_for_block!=0)
        {
            mutex_for_block = 0;
        }
    }
}

