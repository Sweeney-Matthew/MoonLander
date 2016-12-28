/***********************************************************************
 * Header File:
 *    Lander : The landing craft that moves around the screen
 * Author:
 *    Matthew Sweeney
 * Summary:
 *    Everything about the lander. This controls the movement of the lander on the screen and has the velocity
 *    and other things.
 ************************************************************************/

#ifndef LANDER_H
#define LANDER_H

#include "uiDraw.h"
#include "point.h"
#include "velocity.h"

/*********************************************
 * LANDER
 * The landing craft.
 *********************************************/

class Lander
{
public:
   // Default constructor
   Lander();

   // getters
   Point getPoint() const { return location; }
   Velocity getVelocity() const { return velocity; }
   bool isAlive() const { return alive; }
   bool isLanded() const { return landed; }
   int getFuel() const { return fuel; }


   // setters
   void setLanded(bool landed);
   void setAlive(bool alive);
   void setFuel(int fuel);
   
   // Methods for what the lander can do
   void applyGravity(float gravity);
   void applyThrustLeft();
   void applyThrustRight();
   void applyThrustBottom();
   bool canThrust();

   // Loop methods
   void draw();
   void advance();

// Characteristics of the lander
private:
   int fuel;
   Velocity velocity;
   Point location;
   bool landed;
   bool alive;
};

#endif // LANDER_H
