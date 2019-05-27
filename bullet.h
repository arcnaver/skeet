/*************************************************************
 * File: bullet.h
 * Author: Adam Tipton
 *
 * Description: This is my bullet class for the skeet game
 *
 *************************************************************/

#ifndef BULLET_H
#define BULLET_H


#include "flyingObject.h"
#include "point.h"
#include "velocity.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include "uiDraw.h"

// Shane Purcella's suggestion
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


#define BULLET_SPEED 10.0

class Bullet : public FlyingObject
{
private:
   Point point;
   float angle = 60.0;

   
   

public:
   Bullet() {}
   ~Bullet() {}

   Point getPoint() { return point; }
   void setPoint(Point point) { this->point = point; }

   Velocity getVelocity() { return velocity; }
   void setVelocity() { this->velocity = velocity; }

   bool isAlive() { return alive; }
   void setAlive() { alive = true; }
   
   void fire(Point point, float angle);
   void kill() { alive = false; }

   virtual void draw();
   virtual void advance();

};
#endif

