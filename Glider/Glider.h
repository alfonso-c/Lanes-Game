#ifndef GLIDER_H
#define GLIDER_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"
#include "Bitmap.h"
#include "Sprite2D.h"

#define CURB_LEFT_2D 15
#define CURB_RIGHT_2D 69

/** Glider Class
@brief Library for interfacing with the glider and adjusting the points/lives


*/

class Glider
{
public:

    Glider();
    /**
     * Free allocated memory when object goes out of scope
     */
    ~Glider();
    /** Initialise Glider
    *   Initilases parameters for the glider
    *   @param y - Fixed vertical position - the glider only moves horizontally
    */
    void init(int y);
    /** Draw Glider
    *   Function to draw Glider
    */
    void draw(N5110 &lcd);
    /** Position Set
    *   Function to set the position of the Glider
    *   @param d - direction of glider travel (east or west)
    *   @param mag - magnitude of glider travel
    */
    void positionSet(Direction d,float mag);
    /** Position Get
    *   Function to get the position of the Glider in the form of an array using Vector2D
    */
    Vector2D positionGet();
    /** Add Points
    *   Function to add points to existing score, initial score is zero
    */
    void add_points();
    /** Take Lives
    *   Function to subtract lives, initial score is zero
    */
    void take_lives();
    //Public integers for points and lives
    int get_points();
    int check_lives();

private:
    
    //Parameters of the Glider
    int width;
    int height;
    int _height;
    int _width;
    int y;
    int _x;
    int _y;
    int _speed;
    int _score;
    int _lives;
    int position;
    

};
#endif