/*
Drone Software AUTO
Objective: To learn how to use the CoDrone library to make the drone complete task autonomously.
Description: It will contain the setup to launch and fly the drone through obstacle courses in the field.

What is Autonomous?
The ability to make decisions on its own with no human input, and it will either use sensors or predefine actions
to make its decisions.

*/

/*------------------------------------------------------------------
Go
Objective	  : How to Use go() in three different ways
syntax		  : go("Direction") 	* duration 1 sec, 50% of power.
			        go("direction", "duration") *50% of power.
			        go("direction", "duration", "power")
description : Go function is for control the drone with more nature language.
			        as you can see in example you and put "Direction" like FORWARD,
			        BACKWARD, LEFT, RIGHT, UP, DOwN. second parameter is duration.
			        If you put positive number for set duration. 
			        last parameter is power you can set 0~100
-------------------------------------------------------------------*/
/*------------------------------------------------------------------
move
Objective   : How to Use move() in three different ways
syntax      : move() *use saved roll, pitch, yaw, throttle (setter function) and infinity movement
              move("duration")   *use saved roll, pitch, yaw, throttle (setter function)
              move("duration", "roll", "pitch", "yaw", "throttle") 
description : move function is for control the drone with duration, roll
              pitch, yaw, throttle value. It higher version for go() function
              but and can do more like  move forward and left at the sametime
              also duration 0 can be infinity movement
-------------------------------------------------------------------*/
/*------------------------------------------------------------------
goToHeight
Objective   : How to Use goToHeight function
syntax      : goToHeight("height")
description : goToHeight example is using goToHeight() for fly certain height
              You can set 100 ~ 2000 boundary 
              Distance is checked from IR distance sensor next to Optical flow sensor(bottom )
-------------------------------------------------------------------*/
/*------------------------------------------------------------------
Turn
Objective   : How to Use turnDegree()
syntax      : turnDegree("direction", "angle")
description : TurnDegree is for make drone turn with specific angle
			  Angle can be ANGLE_30, ANGLE_45, ANGLE_60, ANGLE_90,
			  ANGLE_ 120, ANGLE_135, ANGLE_150, ANGLE_180. you actually
			  can use number but have to be int type and bigger than 10.
-------------------------------------------------------------------*/
#include <CoDrone.h>

void setup() {
  // put your setup code here, to run once:
  CoDrone.begin(115200);     // sets up the connection to the drone using the bluetooth module Baudrate at 115200bps 
  CoDrone.pair(Nearest);
  CoDrone.DroneModeChange(Flight);
  CoDrone.
  delay(1000);
  // Example for the go function
  CoDrone.takeoff();        // Take off and hovers for 3 seconds for auto calibration
  CoDrone.go(FORWARD);      // Go forward at 50% power for 1 second
  CoDrone.go(UP,5);         // Go up for 5 seconds at 50% power
  CoDrone.go(BACKWARD,3,90); // Go backwards for 3 seconds at 90% power
  CoDrone.land();            // Landing with sound

  // Example for the move function
  CoDrone.move();    // move indefinetly based on the current value of flight variables
  CoDrone.move(5);   // moves 5 seconds based on the current value of flight variables
  CoDrone.move(0,0,0,80,80);    // Moves up(throttle) and turns left(yaw) indefinelty
  CoDrone.move(5,0,0,80,80);    // Moves 5 seconds up(throttle) and turns left(yaw) indefinelty
  CoDrone.land();
  
  // Example for the goToHeightFuction

  CoDrone.takeoff();     // take off and hover for 3 seconds for auto calibration
  CoDrone.goToHeight(1000);   // FLy 1000mm from bottom nad hover
  CoDrone.land();

  // Example for turnDegree
  CoDrone.takeoff();
  CoDrone.turnDegree(LEFT, ANGLE_45);   // Turn left 45 degrees
  CoDrone.land();  



}

void loop() {
  // put your main code here, to run repeatedly:

}
