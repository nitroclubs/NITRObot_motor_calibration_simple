/*
      NITRO Clubs EU - Network of IcT Robo Clubs
 Site: https://www.nitroclubs.eu 
 GitHub repositories https://github.com/nitroclubs?tab=repositories 
 
  NITRObot motor speed calibration program

 Use this sketch to calibrate the motor speeds of your NITRObot. 
 You should fine tune your robot to move in a straight line.
 Find the detailed instructions in NITRObot_motor_calibration-Instructions_EN.odt
*/

//====== INCLUDE ======
#include <Arduino.h>

//====== DEFINE ======
#define MOTOR_LEFT_FWD_PIN 9    
#define MOTOR_LEFT_BKWD_PIN 5   
#define MOTOR_RIGHT_FWD_PIN 6   
#define MOTOR_RIGHT_BKWD_PIN 10 

//====== VARIABLES ======
int speedLeft = 100;  // Initial  value for the speed of the left side motors 
int speedRight = 100; // Initial  value for the speed of the right side motors

//====== FORWARD DECLARATIONS ======
void moveForward(); // function prototype includes return type, name, parameters, and semicolon.  No function body!
void stopMoving();  // function prototype includes return type, name, parameters, and semicolon.  No function body!

//----------------------------------------

void setup()
{ 
  pinMode(MOTOR_LEFT_FWD_PIN, OUTPUT);
  pinMode(MOTOR_LEFT_BKWD_PIN, OUTPUT);
  pinMode(MOTOR_RIGHT_FWD_PIN, OUTPUT);
  pinMode(MOTOR_RIGHT_BKWD_PIN, OUTPUT);
}

//----------------------------------------

void loop()
{ 
  moveForward();
  delay(5000); // With this default value, the robot will move for 5 seconds. 
               // Change this based on the free space in front of the robot! 
  stopMoving();   
}

//============== FUNCTION DEFINITIONS ==============

void moveForward() // Move forward
{
  analogWrite(MOTOR_LEFT_FWD_PIN, abs(speedLeft));
  analogWrite(MOTOR_LEFT_BKWD_PIN, LOW);
  analogWrite(MOTOR_RIGHT_FWD_PIN, abs(speedRight));
  analogWrite(MOTOR_RIGHT_BKWD_PIN, LOW);
}

void stopMoving() // Stop movement
{
  analogWrite(MOTOR_LEFT_FWD_PIN, HIGH);
  analogWrite(MOTOR_LEFT_BKWD_PIN, HIGH);
  analogWrite(MOTOR_RIGHT_FWD_PIN, HIGH);
  analogWrite(MOTOR_RIGHT_BKWD_PIN, HIGH);
}
