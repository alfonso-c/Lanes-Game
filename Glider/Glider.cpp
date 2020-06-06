#include "Glider.h"


Glider::Glider()
{

}

Glider::~Glider()
{

}

void Glider::init(int y)
{
    _x = 35;  // initial x value on screen
    _y = y;  // y value is fixed
    
    width = 15;
    height = 8;
    
    _height = height;
    _width = width;
    _speed = 1;  // default speed
    _score = 0;
    _lives = 4;

}

void Glider::draw(N5110 &lcd)
{
   // draw glider 

// First declare the pixel map data using '1' for black,
  // or '0' for white pixels
  static int sprite_data[] = {
0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,
0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,
0,0,0,0,1,0,0,1,0,0,1,0,0,0,0, 
0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,
0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,
0,1,0,0,0,1,1,1,1,1,0,0,0,1,0,
1,0,1,0,0,1,1,1,1,1,0,0,1,0,1,     
  };
  
  // Instantiate the Bitmap object using the data above
  Bitmap glider1(sprite_data, 7, 15); // Specify rows and columns in sprite
  
  // We can render the bitmap wherever we want on the screen
  glider1.render(lcd, _x, HEIGHT - 8); // x and y locations for rendering

}
void Glider::positionSet(Direction d,float mag)
{
    _speed = int(mag*10.0f);  // scale is arbitrary, could be changed in future
    
    // update x value depending on direction of movement
    // If moving joystick east, north east or south east, glider moves right
     if (d == E || d == NE || d == SE) {
        _x+=_speed;
        position = 1;
    // If moving joystick west, north west or south west, glider moves left
    } else if (d == W || d== NW || d == SW) {
        _x-=_speed;
        position = 2;
    }

    // check x to ensure that the glider stays within the lane boundaries
    if (_x < 1) {
        _x = 1;
    }
    if (_x > CURB_RIGHT_2D - 16) {
        _x = CURB_RIGHT_2D - 16;
    }
    if (_x < CURB_LEFT_2D + 2) {
        _x = CURB_LEFT_2D + 2;
    }
    //printf("Position = %d",position);
}
Vector2D Glider::positionGet() {
    Vector2D p = {_x,_y};
    return p;    
}
void Glider::add_points()
{
    _score++; // add points every time it is called
}
int Glider::get_points()
{
    return _score;
}
void Glider::take_lives()
{
    _lives--; //takes away one life when called
}
int Glider::check_lives()
{
    return _lives;
}