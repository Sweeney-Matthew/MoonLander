/***********************************************************************
 * Source File:
 *    Lander : The landing craft that moves around the screen
 * Author:
 *    Matthew Sweeney
 * Summary:
 *    Everything about the lander. This controls the movement of the lander on the screen and has the velocity
 *    and other things.
 ************************************************************************/

#include "lander.h"
#include "uiDraw.h"
#include "point.h"
#include "velocity.h"
#include <cassert>

/*********************************************
 * Default constructor.
 *********************************************/
Lander :: Lander()
{
   // Initialize all variables
   setAlive(true);
   setLanded(false);
   setFuel(0);

   location.setY(225);
   location.setX(random(-190, 190));
}

/*********************************************
 * setLanded function. Sets landed variable.
 *********************************************/
void Lander :: setLanded(bool landed)
{
   this->landed = landed;   // Assign to parameter
}


/*********************************************
 * setAlive function. Sets alive variable.
 *********************************************/
void Lander :: setAlive(bool alive)
{
   this->alive = alive;   // Assign to parameter
}

/*********************************************
 * setFuel function. Sets the fuel variable for the lander.
 *********************************************/
void Lander :: setFuel(int fuel)
{
   // Sets the fuel to parameter
   this->fuel = fuel;

   // Sets fuel to 0 if for some reason it goes less than 0 on a thrust
   if (this->fuel <= 0)
      this->fuel = 0;
}

/*********************************************
 * canThrust function. Returns whether the lander has fuel left.
 *********************************************/
bool Lander :: canThrust()
{
   // Checks if there is fuel and whether the lander has landed or crashed.
   if (getFuel() > 0 && alive && !landed)
      return true;
   else
      return false;
}

/*********************************************
 * Gravity function. Applies the gravity to the lander's movement.
 *********************************************/
void Lander :: applyGravity(float gravity)
{
   assert(gravity >= 0);  // Since the algorithm multiplies to get negative, make sure gravity is positive

   // Applies the force of gravity to velocity as negative value
   velocity.setDy(velocity.getDy() + (gravity * -1));
}

/*********************************************
 * applyThrustLeft function. Applies thruster to the right for the lander's movement.
 *********************************************/
void Lander :: applyThrustLeft()
{
   //Sets the X coordinate velocity if thruster is fired
   velocity.setDx(velocity.getDx() + 0.1);

   // Subtracts fuel
   if (fuel > 0)
   {
      setFuel(fuel - 1);
   }
}

/*********************************************
 * applyThrustRight function. Applies thruster to the left for the lander's movement.
 *********************************************/
void Lander :: applyThrustRight()
{
   //Sets the X coordinate velocity if thruster is fired
   velocity.setDx(velocity.getDx() - 0.1);

   // Subtracts fuel
   if (fuel > 0)
   {
      setFuel(fuel - 1);
   }
}

/*********************************************
 * applyThrustBottom function. Applies thruster to the bottom of the lander for lander's movement.
 *********************************************/
void Lander :: applyThrustBottom()
{
   //Sets the Y coordinate velocity if thruster is fired
   velocity.setDy(velocity.getDy() + 0.3);

   // Subtracts fuel
   if (fuel > 0)
   {
      setFuel(fuel - 3);
   }
}

/*********************************************
 * draw function. Draws the lander wherever the location is.
 *********************************************/
void Lander :: draw()
{
   drawLander(getPoint());    // Draws the lander at the lander location. 
}

/*********************************************
 * advance function. Advances the lander's cycle by adding velocities to the lander location.
 *********************************************/
void Lander :: advance()
{
   //Adds the x and y velocities to the lander's current location
   location.addX(velocity.getDx());
   location.addY(velocity.getDy());

   // If this advances the lander goes up to far (or down to far) just make it crash.
   if (location.getY() > 350 || location.getY() < -200)
      setAlive(false);
}

