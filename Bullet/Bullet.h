#ifndef Bullet_H
#define Bullet_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"
#include "Glider.h"

class Bullet
{

public:
    Bullet();
    ~Bullet();
    void init(int speed);
    void draw(N5110 &lcd, Gamepad &pad);
    void positionSet();
    /// accessors and mutators
    void velocitySet(Vector2D v);
    Vector2D velocityGet();
    Vector2D positionGet();
    void positionSet(Vector2D p);
    
private:

    Gamepad pad;
    Glider _g;

    Vector2D _velocity;
    int _size;
    int _x;
    int _y;
};
#endif