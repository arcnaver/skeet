/***********************************************************************
 * Source File:
 *    FlyingObject 
 * 
 * Summary:
 *    contains definitions of the flyingObject class
 ************************************************************************/

#include "flyingObject.h"

 /******************************************
  * FlyingObject : advance()
  * sets up points
  *****************************************/
void FlyingObject::advance()
{   
   point.setX(point.getX() + velocity.getDx());
   point.setY(point.getY() + velocity.getDy());
}