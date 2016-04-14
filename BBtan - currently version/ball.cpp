#include "ball.h"

Ball::Ball(int upper, int lower, int left, int right)
{
    // Passing variable
    up = upper;
    low = lower;
    lef = left;
    rig = right;
    // For debugging
    x_speed = 0.0;
    y_speed = 0.0;

}

Ball::~Ball()
{

}

void Ball::advance(int phase)
{
    // Do moving
    this->setPos(this->pos().x()+ x_speed , this->pos().y()+ y_speed);
    // check the boundary
    checkBoundary();
}

void Ball::setX_speed(int speed)
{
    x_speed = speed;
}

void Ball::setY_speed(int speed)
{
    y_speed = speed;
}

void Ball::checkBoundary()
{
    /* Move per interval */
    // First , Boundary check
    int nowX = this->pos().x();
    int nowY = this->pos().y();

    // When out of boundary collision happen , we have to let speed on x ,y make some different

    if(nowX > rig)
    {
        // Out right boundary
        if(nowY > low)
        {
            // Out low boundary too => need to stop
            // Call stop function , and set the character to this position
            x_speed = 0;
            y_speed = 0;
        }
        else if(nowY <= low && nowY >= up)
        {
            // fit in size
            x_speed = -x_speed;
        }
        else if(nowY < up)
        {
            // Out of upper boundary
            x_speed = -x_speed;
            y_speed = -y_speed;
        }
    }
    else if(nowX <= rig && nowX >= lef)
    {
        // In x range
        if(nowY > low)
        {
            // Out low boundary => need to stop
            // Call stop function , and set the character to this position
            y_speed = 0;
            x_speed = 0;
        }
        else if(nowY <= low && nowY >= up)
        {
            // fit in size
            // do nothing
        }
        else if(nowY < up)
        {
            // Out of upper boundary
            y_speed = -y_speed;
        }
    }
    else if(nowX < lef)
    {
        // Out of left boundary
        if(nowY > low)
        {
            // Out low boundary => need to stop
            // Call stop function , and set the character to this position
            y_speed = 0;
            x_speed = 0;
        }
        else if(nowY <= low && nowY >= up)
        {
            // fit in size
            x_speed = -x_speed;
        }
        else if(nowY < up)
        {
            // Out of upper boundary
            y_speed = -y_speed;
            x_speed = -x_speed;
        }
    }
}

