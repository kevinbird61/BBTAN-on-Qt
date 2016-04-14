#include "scene.h"

Scene::Scene()
{
    screenMode = 0;
}

void Scene::Init(int x_start)
{
    // start
    btn_start = new Btn();
    QPixmap start;
    start.load(":/image/img/btn_start.jpg");
    start = start.scaled(start.width()*3/2,start.height()*3/2,Qt::KeepAspectRatio);
    btn_w = (start.width()*3)/2 - 60;
    btn_h = (start.height()*3)/2 - 30;
    btn_start->setPixmap(start);
    btn_start->setPos(200,390);
    addItem(btn_start);
    // change
    btn_change_ball = new Btn();
    QPixmap cb;
    cb.load(":/image/img/btn_change_ball.jpg");
    cb = cb.scaled((cb.width()*3)/2,(cb.height()*3)/2,Qt::KeepAspectRatio);
    btn_change_ball->setPixmap(cb);
    btn_change_ball->setPos(35,390);
    addItem(btn_change_ball);

    //  setting the boundary , only lowerBound has a little different
    leftBound = x_start-20;
    rightBound = leftBound+370;
    upperBound = 60;

    // Setting the sound
    bgm = new QSound(":/Sound/sound/start.wav");
    ball_hit = new QSound(":/Sound/sound/ball_hit.wav");
    bgm->play();
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(screenMode == 0)
    {
        // Beginning page
        if(event->scenePos().x() > btn_start->pos().x() && event->scenePos().x() <= btn_start->pos().x()+btn_w)
        {
            // Now x is in range , judge y
            if(event->scenePos().y() > btn_start->pos().y() && event->scenePos().y() <= btn_start->pos().y()+btn_h)
            {
                // x , y both in button area
                cout<< "Start Game"<< endl;
                // Clear original background
                bgChange();
                screenMode = 1;
            }
        }
        // or click on change ball
        if(event->scenePos().x() > btn_change_ball->pos().x() && event->scenePos().x() <= btn_change_ball->pos().x()+btn_w)
        {
            // Now x is in range , judge y
            if(event->scenePos().y() > btn_change_ball->pos().y() && event->scenePos().y() <= btn_change_ball->pos().y()+btn_h)
            {
                // x , y both in button area
                cout<< "change get"<< endl;
                bgChange();
                screenMode = 2; // mode to change ball
            }
        }
    }
    else if(screenMode == 1)
    {
        // Starting Page
        if(event->scenePos().x() > btn_back->pos().x() && event->scenePos().x() <= btn_back->pos().x()+btn_small_w)
        {
            // Now x is in range , judge y
            if(event->scenePos().y() > btn_back->pos().y() && event->scenePos().y() <= btn_back->pos().y()+btn_small_h)
            {
                // x , y both in back button area
                bgRecover();
                screenMode = 0;
            }
        }
        // Starting Page setting - shooting point

        // Goto setting the game initial
        gameInit();
        screenMode = 3;

    }
    else if(screenMode == 2)
    {
        // Changing ball Page
        if(event->scenePos().x() > btn_back->pos().x() && event->scenePos().x() <= btn_back->pos().x()+btn_small_w)
        {
            // Now x is in range , judge y
            if(event->scenePos().y() > btn_back->pos().y() && event->scenePos().y() <= btn_back->pos().y()+btn_small_h)
            {
                // x , y both in back button area
                bgRecover();
                screenMode = 0;
            }
        }
        // Else for changing ball's implementation

    }
    else if(screenMode == 3)
    {
        if(event->scenePos().x() > btn_back->pos().x() && event->scenePos().x() <= btn_back->pos().x()+btn_small_w)
        {
            // Now x is in range , judge y
            if(event->scenePos().y() > btn_back->pos().y() && event->scenePos().y() <= btn_back->pos().y()+btn_small_h)
            {
                // x , y both in back button area
                bgRecover();
                screenMode = 0;
            }
        }
        // get currently location , and then shoot the ball to that direction
        int ysp = (event->scenePos().y()-ball->pos().y());
        int xsp = (event->scenePos().x()-ball->pos().x());

        ball->setY_speed( ysp / 50 );
        ball->setX_speed( xsp / 50 );
        //cout<< ball->y_speed << " ; " << ysp << endl;
    }
    /* For debugging */
    //cout << "btn start x: " << btn_start->pos().x()<< " btn start y: " << btn_start->pos().y() << endl;
    //cout << "Now event x: " << event->scenePos().x()<< " event y: " << event->scenePos().y() << endl;
}

void Scene::geneNextBlock()
{
    // Generate Block here
    // random the seed
    qsrand(qrand());
    int every_level_num = 5;
    int every_level_size = (rightBound - leftBound)/every_level_num;
    int every_level_height = (lowerBound - upperBound)/ 10;
    // rand a number : 0 ~ 5
    int rand = qrand();
    int current_level_build = rand%every_level_num;
    // Moving the block to next level
    movingBlock();
    // After moving exists , we can build our new block
    for(int i = 0 ; i < current_level_build ; i++)
    {
        // new block
        Block *block;
        block = new Block(every_level_size,every_level_height);
        QPixmap bl;
        bl.load(":/image/img/block.jpg");
        bl = bl.scaled(every_level_size,every_level_height ,Qt::IgnoreAspectRatio);
        block->setPixmap(bl);
        block->setPos( (qrand()%every_level_num )*every_level_size , upperBound);
        this->addItem(block);
        list.push_front(block);
    }
}

void Scene::DoCollision()
{
    // Do the ball's collision
    QList<QGraphicsItem *> hit_list = this->collidingItems(ball);
    foreach (QGraphicsItem *i, hit_list) {
        Character *item2 = dynamic_cast<Character *>(i);
        if(item2 == man)
        {
            // detect if hit the man
            break;
        }
        else{
        Block *item = dynamic_cast<Block *>(i);
        // Let the speed reverse
        if(ball->pos().y() <= item->pos().y() ){
            // upside
            ball->setY_speed( - ball->y_speed);
        }
        else if(ball->pos().y() > item->pos().y() && ball->pos().y() < (item->pos().y() + item->size_h - 20) ){
            // inside
            ball->setX_speed( - ball->x_speed);
        }
        else{
            // downside
            ball->setY_speed( - ball->y_speed);
        }
        // Play the sound
        ball_hit->play();
        // Remove from scene
        this->removeItem(item);
        // Delete it from scene
        list.removeOne(item);
        delete item;
        }
    }
}

void Scene::bgChange()
{
    /* first , change background picture */
    QImage bg;
    bg.load(":/image/img/start.jpg");
    bg = bg.scaled(370,630);
    this->setBackgroundBrush(bg);
    /* second , remove btn - start and change ball */
    this->removeItem(btn_start);
    this->removeItem(btn_change_ball);

    // Back buttom setting
    btn_back = new Btn();
    QPixmap bk;
    bk.load(":/image/img/back.jpg");
    btn_small_w = bk.width()*2/3;
    btn_small_h = bk.height()*2/3;
    bk = bk.scaled(btn_small_w , btn_small_h ,Qt::KeepAspectRatio);
    btn_back->setPixmap(bk);
    btn_back->setPos(0,5);
    addItem(btn_back);

    // save the initial position
    ch_y_pos = 450;
    // save the initial lowerBoundary
    lowerBound = 450+50; // 50 is the bias (every picture's have it's original boundary)

    // Setting the ball on it
    ball = new Ball(upperBound,lowerBound,leftBound,rightBound);
    QPixmap ba;
    ba.load(":/image/img/ball.png");
    ba = ba.scaled(ba.width()/5 , ba.height()/5,Qt::KeepAspectRatio);
    ball->setPixmap(ba);
    ball->setPos(300,lowerBound);
    this->addItem(ball);

    // Setting the character on it
    man = new Character(ball,ch_y_pos);
    QPixmap ch;
    ch.load(":/image/img/character.png");
    ch = ch.scaled( ch.width()*2/3, ch.height()*2/3 ,Qt::KeepAspectRatio);
    man->setPixmap(ch);
    man->setPos(300,450);
    this->addItem(man);
}

void Scene::bgRecover()
{
    // remove item here
    removeItem(btn_back);
    removeItem(man);
    foreach (Block *i, list) {
        this->removeItem(i);
        list.removeOne(i);
    }
    // add back initial page
    addItem(btn_start);
    addItem(btn_change_ball);
    QImage bg;
    bg.load(":/image/img/open.jpg");
    bg = bg.scaled(370,630);
    this->setBackgroundBrush(bg);

    // reset ball status
    ball->x_speed = 0;
    ball->y_speed = 0;
    this->removeItem(ball);

    // Setting the sound => Play again the sound
    bgm->play();
}

void Scene::gameInit()
{
    // Set up timer to control each item
    timer = new QTimer(this);
    connect(timer , SIGNAL(timeout()) , this , SLOT(advance()));
    connect(timer , SIGNAL(timeout()) , this , SLOT(DoCollision()));
    timer->start(10);

    // Using first generate block
    geneNextBlock();
    // Set up man and scene's connect
    QObject::connect( man , SIGNAL(BallIsOnFloor()) , this , SLOT(geneNextBlock()));
}

void Scene::movingBlock()
{
    foreach(Block *i , list)
    {
        // Moving each down to next level
        i->setPos(i->pos().x(),i->pos().y()+i->size_h);
        // Do boundary check
        if(i->pos().y() + i->size_h >= lowerBound)
        {
            // reset the screen , go to score page , and break;
            // FIXME : score page
            break;
        }
    }
}

