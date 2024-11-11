 /*------------------------------------------------------------------
Flight Controller
Objective   : How to code default program 
syntax      : 
description : This flight Controller example. also known as Defualt program for CoDrone.
              Include how to use bottom IR sensor and assign buttons' action
-------------------------------------------------------------------*/
#include <CoDrone.h> // The codrone library that holds all the background files for this

void setup()
{  
  CoDrone.begin(115200);  

  //connect with drone controller have adress
//  CoDrone.pair(); 
  //connect with the nearest drone
  CoDrone.pair(Nearest);

  CoDrone.DroneModeChange(Flight);    // Changes the drone so that it is now in flight mode
}

void loop()
{

  
  // PAIRING is set to true in AutoConnect if they connect together
  if (PAIRING == true)  // Check to see that we are paired before trying to fly               
  {
    // reads the joystick (analogRead(A#)) and then converts it into a value that the drone can use (AnalogScaleChange())
    // if any of the joysticks move backwards compared to the drone (up is down or left is right), add -1 * at the start
    // it will change the direction the drone moves when you move the joystick
    YAW = -1 * CoDrone.AnalogScaleChange(analogRead(A3));   // YAW (turn left or right), port A3, reversed
    THROTTLE  = CoDrone.AnalogScaleChange(analogRead(A4));  // THROTTLE (height), port A4, not reversed
    ROLL = -1 * CoDrone.AnalogScaleChange(analogRead(A5));  // ROLL (tilt left or right), port A5, reversed
    PITCH = CoDrone.AnalogScaleChange(analogRead(A6));      // PITCH (tilt front or back), port A6, not reversed
    CoDrone.move(ROLL,PITCH,YAW,THROTTLE);                  // Send the new flight commands
  }
}

/*
Additional challenges

void loop(){ 
    byte bt8 = digitalRead(18);
    byte bt4 = digitalRead(14);
    byte bt1 = digitalRead(11);

    if(bt8){
     CoDrone.FlightEvent(TakeOff);
     
     delay(2000);
     CoDrone.FlightEvent(Landing);
   }

   else if(bt1 && bt4 && !bt8){
      CoDrone.FlightEvent(Stop);
    }
}
*/
