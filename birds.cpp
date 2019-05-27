/***********************************************************************
 * Source File:
 *    bird.cpp
 *
 * Summary:
 *    contains definitions of the birds parent and derived classes
 ************************************************************************/

#include "birds.h"
#include "uiDraw.h"


/*********************************************************
**********************************************************
*       Standard BIRD
*           Functions for Standard Bird
*********************************************************/
StandardBird::StandardBird(const Point & point) : Bird(point)
{
   float dx = random(3, 6);
   float dy = random(0, 4);

   if (point.getY() > 0)
   {
      dy *= -1;
   }

   Velocity newVelocity;
   newVelocity.setDx(dx);
   newVelocity.setDy(dy);

   setVelocity(newVelocity);

}

/*******************************************************
* DRAW
*     Function for Standard Bird 
********************************************************/
void StandardBird::draw()
{
   if (alive)
   {
      drawCircle(point, BIRD_RADIUS);
   }
}

/*******************************************************
* HIT
*     Function for Standard Bird 
********************************************************/
int StandardBird::hit()
{
   kill();

   return POINTS_STANDARD_BIRD;
}

/*******************************************************
********************************************************
* TOUGH BIRD
*     Functions for Tough Bird
********************************************************/
ToughBird::ToughBird(const Point & point) : Bird(point)
{
   
   
   float dx = random(2, 4);
   float dy = random(-3, 3);

   if (point.getY() > 0)
   {
      dy *= -1;
   }

   Velocity newVelocity;
   newVelocity.setDx(dx);
   newVelocity.setDy(dy);

   setVelocity(newVelocity);

}

/*******************************************************
* DRAW
*     Function for Tough Bird
*******************************************************/
void ToughBird::draw()
{
   if (alive)
   {
      drawToughBird(point, BIRD_RADIUS, hits);
   }
}

/*******************************************************
* DRAW
*     Function for Tough Bird
*******************************************************/
int ToughBird::hit()
{
   if (hits == 1)
   {
      kill();
      hits = 3;
      
      return 2;
   }
   
   hits--;
   return 1;
}

/*******************************************************
********************************************************
* SACRED BIRD
*     Functions for Sacred Bird
********************************************************/
SacredBird::SacredBird(const Point & point) : Bird(point)
{
   float dx = random(3, 6);
   float dy = random(0, 4);

   if (point.getY() > 0)
   {
      dy *= -1;
   }

   Velocity newVelocity;
   newVelocity.setDx(dx);
   newVelocity.setDy(dy);

   setVelocity(newVelocity);

}


/*******************************************************
* DRAW
*     Function for Sacred Bird Draw
********************************************************/
void SacredBird::draw()
{
   if (alive)
   {
      drawSacredBird(point, BIRD_RADIUS);
   }
}

/*******************************************************
* HIT
*     Function for Sacred Bird Draw
********************************************************/
int SacredBird::hit()
{
   kill();

   return POINTS_SACRED_BIRD;
}

/*******************************************************
********************************************************
* SPECIAL BIRD
*     Functions for Sacred Bird
********************************************************/
SpecialBird::SpecialBird(const Point & point) : Bird(point)
{
   // Make this bugger go fast!!
   float dx = random(10, 15);
   float dy = random(0, 6);

   if (point.getY() > 0)
   {
      dy *= -1;
   }

   Velocity newVelocity;
   newVelocity.setDx(dx);
   newVelocity.setDy(dy);

   setVelocity(newVelocity);

}


/*******************************************************
* DRAW
*     Function for Special Bird Draw
*     Basically just a lander with flames. Actually
*     looks kinda like Pheasant. 
********************************************************/
void SpecialBird::draw()
{
   if (alive)
   {
      drawLander(point);
      drawLanderFlames(point, true, true, true);
   }
}

/*******************************************************
* HIT
*     Function for Special Bird Draw
********************************************************/
int SpecialBird::hit()
{
   kill();
   // Give me lotsa points for killing it!
   return POINTS_SPECIAL_BIRD;
}