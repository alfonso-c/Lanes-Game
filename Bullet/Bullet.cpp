#include "Bullet.h"

Bullet::Bullet()
{

}

Bullet::~Bullet()
{

}

void Bullet::init(int speed)
{
    //_size = size;

    _x = WIDTH/2;
    _y = HEIGHT-8;

        _velocity.x = 0;
        _velocity.y = speed;
}

void Bullet::draw(N5110 &lcd,Gamepad &pad)
{
    lcd.drawRect(_x,_y,1,1,FILL_BLACK);
}

void Bullet::positionSet()
{
    Vector2D g_position = _g.positionGet();
    _x += g_position.x;
    _y -= _velocity.y;
}

void Bullet::velocitySet(Vector2D v)
{
    _velocity.x = v.x;
    _velocity.y = v.y;
}

Vector2D Bullet::velocityGet()
{
    Vector2D v = {_velocity.x,_velocity.y};
    return v;
}

Vector2D Bullet::positionGet()
{
    Vector2D p = {_x,_y};
    return p;
}

void Bullet::positionSet(Vector2D p)
{
    _x = p.x;
    _y = p.y;
}