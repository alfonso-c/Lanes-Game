#include "Coins.h"


Coins::Coins()
{

}

Coins::~Coins()
{

}
// Initilases parameters for the coin
void Coins::init2D(int speed){
     
     xRandom();
     xRandom();
    
     _velocity.y = speed ;

}

// Function to draw the Coin at given parameters
void Coins::draw2D(N5110 &lcd){

    lcd.drawCircle(_x+7,_y+7,3,FILL_TRANSPARENT); // x,y,radius,transparent with outline

}

// Randomises the value of x 
void Coins::xRandom(){
    int xPosition = rand() % 256;
    
    //printf ("xRandom = %d", xPosition);
    
    if (xPosition <= 85 && xPosition >= 0){
        //printf ("%s \n", "Middle Coins Release");
        _x=35;
        }
    else if (xPosition <= 170 && xPosition >= 86){
        _x=17;
        //printf ("%s \n", "Left Coins Release");
        }
    else if (xPosition <= 256 && xPosition >= 171){
        _x=53;
        //printf ("%s \n", "Right Coins Release");
        }
}
// set the position of the Coins
void Coins::positionSet()
{
    // If the y value is greater than the height of the screen, the x value is randomised
    if (_y > HEIGHT){
        xRandom();
        _y = 0;
        }
    
    _x += _velocity.x;
    _y += _velocity.y;
}

// set the velocity of the Coins
void Coins::velocitySet(Vector2D v)
{
    _velocity.x = v.x;
    _velocity.y = v.y;
}

// Get the velocity of the Coins
Vector2D Coins::velocityGet()
{
    Vector2D v = {_velocity.x,_velocity.y};
    return v;
}

// Get the position of the Coins
Vector2D Coins::positionGet()
{
    Vector2D p = {_x,_y};
    return p;
}

// Set the position of the Coins
void Coins::set_pos(Vector2D p)
{
    _x = p.x;
    _y = p.y;
}    