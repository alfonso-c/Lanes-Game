#ifndef Powerup_H
#define Powerup_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"
#include "Bitmap.h"

class Powerup
{
public:

    Powerup();
    ~Powerup();
    void init(int x,int height,int width);
    //void init3D(int r, int r3, int yd, int xd, int ydl, int xdl);
    
    void init3D();
    void init2D(int speed);
    void draw2D(N5110 &lcd);
    void draw3DL(N5110 &lcd);
    void draw3DC(N5110 &lcd);
    void draw3DR(N5110 &lcd);
    
    
    
    void xRandom();
    void positionSet();
    /// accessors and mutators
    void velocitySet(Vector2D v);
    Vector2D velocityGet();
    Vector2D positionGet();
    void set_pos(Vector2D p);
    

private:

    //Ticker ticker;

    int y;
    int _x;
    int _xOb;
    int _y;
    int _speed;
    int _score;
    int position;
    
    int _obsize;
    
    int r;
    int r3;
    int yd;
    int xd;
    int ydl;
    int xdl;
    
    Vector2D _velocity;

};
#endif