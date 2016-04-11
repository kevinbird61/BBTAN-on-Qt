#include "character.h"

Character::Character(Ball *ball, int static_y_pos)
{
    b = ball;
    y_pos = static_y_pos;
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
    }
    //cout << "Ball : "<< b->pos().x() << " ; " << b->pos().y() << endl;
}

