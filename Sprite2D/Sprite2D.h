#ifndef Sprite2D_H
#define Sprite2D_H

#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"
#include "Bitmap.h"

class Sprite2D
{
public:

    Sprite2D();
    ~Sprite2D();
    /*
    void init(int y,int height,int width);
    void draw(N5110 &lcd);
    void drawGlider(N5110 &lcd, Sprite2D &oGlider);
    void update(Direction d,float mag);
    void PositionSet(N5110 &lcd);
    */
    void drawGlider(N5110 &lcd);
    void drawHeart(N5110 &lcd);
    void drawOneLifeGone(N5110 &lcd);
    void drawTwoLivesGone(N5110 &lcd);
    void drawThreeLivesGone(N5110 &lcd);
    void drawAllLivesGone(N5110 &lcd);
    void draw3DChar(N5110 &lcd);
    Bitmap heartData();
    

private:

    static int sprite_data[];

    int _height;
    int _width;
    int _x;
    int _y;
    int _speed;
    int _score;
    int position;
    

};
#endif