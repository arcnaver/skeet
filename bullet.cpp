/***********************************************************************
 * Source File:
 *    bullet.cpp
 * Author:
 *    Adam Tipton
 * Summary:
 *    Everything we need to know about a bullet
 ************************************************************************/

#include "bullet.h"
#include "uiDraw.h"


 /*********************************************
  * DRAW
  * Draws the bullet
  *********************************************/
void Bullet::draw()
{
   drawDot(point);
}

/*********************************************
 * ADVANCE
 * A single position.
 *********************************************/
void Bullet::advance()
{
  
   point.addX(velocity.getDx());
   point.addY(velocity.getDy());
   
}

/*********************************************
 * FIRE
 * A single position.
 *********************************************/
void Bullet::fire(Point point, float angle)
{
   this->point = point;
   float dx = BULLET_SPEED * (-cos(M_PI / 180.0 * angle));
   float dy = BULLET_SPEED * (sin(M_PI / 180.0 * angle));

   velocity.setDx(velocity.getDx() + dx);
   velocity.setDy(velocity.getDy() + dy);
}