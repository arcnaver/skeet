/***********************************************************************
 * Header File:
 *    bird class
 * Author:
 *    Adam Tipton
 * Summary:
 *    Everything we need to know about a birds
 ************************************************************************/


#ifndef BIRD_H
#define BIRD_H

#include "flyingObject.h"
#include "uiDraw.h"

#define BIRD_RADIUS 15
#define BIRD_X_SPEED_MIN 3.0
#define BIRD_X_SPEED_MAX 6.0
#define BIRD_Y_SPEED_MIN 0.0
#define BIRD_Y_SPEED_MAX 4.0

#define POINTS_STANDARD_BIRD 1
#define POINTS_SACRED_BIRD -10
#define POINTS_TOUGH_BIRD_HIT 1
#define POINTS_TOUGH_BIRD_KILL 3
#define POINTS_SPECIAL_BIRD 25

class Bird : public FlyingObject
{
private:

public:
   
   Bird(const Point & point)
   {
      alive = true;
      setPoint(point);
   }
   
   virtual void draw() = 0;
   virtual int hit() = 0;
};


/*         STANDARD BIRD            */
class StandardBird : public Bird
{
public:
   StandardBird(const Point & point);

   virtual void draw();
   virtual int hit();
};

/*        TOUGH BIRD           */
class ToughBird : public Bird
{
private:
   int hits = 3;
public:
   ToughBird(const Point & point);

   virtual void draw();
   virtual int hit();
};


/*        SACRED BIRD          */
class SacredBird : public Bird
{
public:
   SacredBird(const Point & point);

   virtual void draw();
   virtual int hit();
};

/*        SPECIAL BIRD          */
class SpecialBird : public Bird
{
public:
   SpecialBird(const Point & point);

   virtual void draw();
   virtual int hit();
};


#endif
