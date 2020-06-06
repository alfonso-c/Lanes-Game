#ifndef Coins_H
#define Coins_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"

/** Coin Class
@brief Library for interfacing with the coin


*/

class Coins
{
public:

    Coins();
    ~Coins();
    /** Initialise Coin
    *   Initilases parameters for the coin
    *   @param speed - speed of the game 
    */
    void init2D(int speed);
    /** Draw Coin
    *   Function to draw the Coin at given parameters
    */
    void draw2D(N5110 &lcd);
    /** x Randomiser
    *   Randomises the value of x 
    */
    void xRandom();
   /** Position Set
    *   Function to set the position of the Coins
    */
    void positionSet();
    /// accessors and mutators
    /** Velocity Set
    *   Function to set the velocity of the Coins
    */
    void velocitySet(Vector2D v);
    /** Velocity Get
    *   Function to get the velocity of the Coins
    */
    Vector2D velocityGet();
    /** Position Get
    *   Gets the velocity of the Coins in the form of an array using Vector2D
    */
    Vector2D positionGet();
    /** Vector Position Set
    *   Function to get the position of the Coins in the form of an array using Vector2D
    */
    void set_pos(Vector2D p);
    

private:

    //Ticker ticker;

    int y;
    int _x;
    int _y;
    int _speed;
    int position;
    
    int _obsize;
    
    Vector2D _velocity;

};
#endif