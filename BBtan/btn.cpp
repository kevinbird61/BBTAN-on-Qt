#include "btn.h"

Btn::Btn()
{
}

void Btn::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        /* Access to parent , and change the background color , and remove all main page item */
        cout << "Click !" << endl;
    }
}

