#include "Powerup.h"


Powerup::Powerup()
{

}

Powerup::~Powerup()
{

}

void Powerup::init2D(int speed){
     
     Ticker ticker;

     //ticker.attach(&xRandom,0.1);
     
     xRandom();
     xRandom();
     
     //_obsize = 15;
     _velocity.y = speed + 3;
     //_x = 35;
     //printf("%s", "Powerup Initialised");
}

void Powerup::draw2D(N5110 &lcd)
{
    static int sprite_data[] = {
        1,1,1,0,1,1,0,0,
        0,0,1,0,1,0,1,0,
        0,0,1,0,1,0,0,1,
        1,1,1,0,1,0,0,1,
        0,0,1,0,1,0,0,1,
        0,0,1,0,1,0,1,0,
        1,1,1,0,1,1,0,0,
    };
    Bitmap char3D(sprite_data, 7, 8);
    char3D.render(lcd, _x+4, _y);

    //lcd.drawRect(_x,_y,7, 7,FILL_BLACK);
    //lcd.printString("3D",70,0);
    //lcd.drawCircle(_x+7,_y+7,3,FILL_TRANSPARENT); // x,y,radius,transparent with outline
    //printf("%s", "Powerup Drawn");

}

void Powerup::xRandom(){
    int xPosition = rand() % 1000; //Much less posibility of this powerup falling
    
    printf ("xRandom = %d", xPosition);
    
    if (xPosition <= 85 && xPosition >= 0){
        //printf ("%s \n", "Middle Powerup Release");
        _x=35;
        }
    else if (xPosition <= 170 && xPosition >= 86){
        _x=17;
        //printf ("%s \n", "Left Powerup Release");
        }
    else if (xPosition <= 256 && xPosition >= 171){
        _x=53;
        //printf ("%s \n", "Right Powerup Release");
        }
    else {
        _x=HEIGHT + WIDTH; //Arbitrary constant chosen which is out of the screen 
        //printf ("%s \n", "No 3D Powerup Released");
        }
}

void Powerup::positionSet()
{
    if (_y > HEIGHT){
        xRandom();
        _y = 0;
        }
    
    _x += _velocity.x;
    _y += _velocity.y;
    //printf("Power up X = %d", _x);
    //printf("Power up Y = %d", _y);
}

void Powerup::velocitySet(Vector2D v)
{
    _velocity.x = v.x;
    _velocity.y = v.y;
    //printf("%s", "Powerup velocitySet");
}

Vector2D Powerup::velocityGet()
{
    Vector2D v = {_velocity.x,_velocity.y};
    return v;
}

Vector2D Powerup::positionGet()
{
    Vector2D p = {_x,_y};
    return p;
}

void Powerup::set_pos(Vector2D p)
{
    _x = p.x;
    _y = p.y;
    //printf("Power up setPos X = %d", _x);
    //printf("Power up setPos X = %d", _y);
}    