#include "Sprite2D.h"

Sprite2D::Sprite2D()
{

}

Sprite2D::~Sprite2D()
{

}

void Sprite2D::drawGlider(N5110 &lcd){
  
  static int sprite_data[] = {
0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,
0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,
0,0,0,0,1,0,0,1,0,0,1,0,0,0,0, 
0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,
0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,
0,1,0,0,0,1,1,1,1,1,0,0,0,1,0,
1,0,1,0,0,1,1,1,1,1,0,0,1,0,1,     
  };
  
  Bitmap glider1(sprite_data, 8, 15);
  
  glider1.render(lcd, 17, _y);
  
  
}


void Sprite2D::drawHeart(N5110 &lcd){
  
  static int sprite_data[] = {
0,1,1,0,0,0,0,1,1,0,
1,1,1,1,0,0,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1, 
0,1,1,1,1,1,1,1,1,0,
0,0,1,1,1,1,1,1,0,0,
0,0,0,1,1,1,1,0,0,0,
0,0,0,0,1,1,0,0,0,0,     
  };
  
  Bitmap heart(sprite_data, 8, 10);
  for (int yheart = 3; yheart < HEIGHT-10; yheart+=11){
  heart.render(lcd, WIDTH - 12, yheart);
  }
}

void Sprite2D::drawOneLifeGone(N5110 &lcd){
  
  static int sprite_data[] = {
0,1,1,0,0,0,0,1,1,0,
1,0,0,1,0,0,1,0,0,1,
1,0,0,0,1,1,0,0,0,1,
1,0,0,0,0,0,0,0,0,1, 
0,1,0,0,0,0,0,0,1,0,
0,0,1,0,0,0,0,1,0,0,
0,0,0,1,0,0,1,0,0,0,
0,0,0,0,1,1,0,0,0,0,     
  };
  
  Bitmap heart_empty(sprite_data, 8, 10);
  heart_empty.render(lcd, WIDTH - 12, 3);
  
  static int sprite_data2[] = {
0,1,1,0,0,0,0,1,1,0,
1,1,1,1,0,0,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1, 
0,1,1,1,1,1,1,1,1,0,
0,0,1,1,1,1,1,1,0,0,
0,0,0,1,1,1,1,0,0,0,
0,0,0,0,1,1,0,0,0,0,     
  };
  
  Bitmap heart(sprite_data2, 8, 10);
  for (int yheart = 14; yheart < HEIGHT-10; yheart+=11){
  heart.render(lcd, WIDTH - 12, yheart);
  }

}

void Sprite2D::drawTwoLivesGone(N5110 &lcd){
  
  static int sprite_data[] = {
0,1,1,0,0,0,0,1,1,0,
1,0,0,1,0,0,1,0,0,1,
1,0,0,0,1,1,0,0,0,1,
1,0,0,0,0,0,0,0,0,1, 
0,1,0,0,0,0,0,0,1,0,
0,0,1,0,0,0,0,1,0,0,
0,0,0,1,0,0,1,0,0,0,
0,0,0,0,1,1,0,0,0,0,     
  };
  
  Bitmap heart_empty(sprite_data, 8, 10);
  heart_empty.render(lcd, WIDTH - 12, 3);
  heart_empty.render(lcd, WIDTH - 12, 14);
  
  static int sprite_data2[] = {
0,1,1,0,0,0,0,1,1,0,
1,1,1,1,0,0,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1, 
0,1,1,1,1,1,1,1,1,0,
0,0,1,1,1,1,1,1,0,0,
0,0,0,1,1,1,1,0,0,0,
0,0,0,0,1,1,0,0,0,0,     
  };
  
  Bitmap heart(sprite_data2, 8, 10);
  for (int yheart = 25; yheart < HEIGHT-10; yheart+=11){
  heart.render(lcd, WIDTH - 12, yheart);
  }

}

void Sprite2D::drawThreeLivesGone(N5110 &lcd){
  
  static int sprite_data[] = {
0,1,1,0,0,0,0,1,1,0,
1,0,0,1,0,0,1,0,0,1,
1,0,0,0,1,1,0,0,0,1,
1,0,0,0,0,0,0,0,0,1, 
0,1,0,0,0,0,0,0,1,0,
0,0,1,0,0,0,0,1,0,0,
0,0,0,1,0,0,1,0,0,0,
0,0,0,0,1,1,0,0,0,0,     
  };
  
  Bitmap heart_empty(sprite_data, 8, 10);
  heart_empty.render(lcd, WIDTH - 12, 3);
  heart_empty.render(lcd, WIDTH - 12, 14);
  heart_empty.render(lcd, WIDTH - 12, 25);
  
  static int sprite_data2[] = {
0,1,1,0,0,0,0,1,1,0,
1,1,1,1,0,0,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1, 
0,1,1,1,1,1,1,1,1,0,
0,0,1,1,1,1,1,1,0,0,
0,0,0,1,1,1,1,0,0,0,
0,0,0,0,1,1,0,0,0,0,     
  };
  
  Bitmap heart(sprite_data2, 8, 10);
  heart.render(lcd, WIDTH - 12, 36);
  

}

void Sprite2D::drawAllLivesGone(N5110 &lcd){
  
  static int sprite_data[] = {
0,1,1,0,0,0,0,1,1,0,
1,0,0,1,0,0,1,0,0,1,
1,0,0,0,1,1,0,0,0,1,
1,0,0,0,0,0,0,0,0,1, 
0,1,0,0,0,0,0,0,1,0,
0,0,1,0,0,0,0,1,0,0,
0,0,0,1,0,0,1,0,0,0,
0,0,0,0,1,1,0,0,0,0,     
  };
  
  Bitmap heart_empty(sprite_data, 8, 10);
  heart_empty.render(lcd, WIDTH - 12, 3);
  heart_empty.render(lcd, WIDTH - 12, 14);
  heart_empty.render(lcd, WIDTH - 12, 25);
  heart_empty.render(lcd, WIDTH - 12, 36);

}

void Sprite2D::draw3DChar(N5110 &lcd){
  
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
  
  char3D.render(lcd, WIDTH - 12, 3);

}
