//Calibration test
#include <Arduino.h>

#define LEFT_FOR 9    // PWMB
#define LEFT_BACK 5   // DIRB  ---  Left
#define RIGHT_FOR 6   // PWMA
#define RIGHT_BACK 10 // DIRA  ---  Right

const int LeftSpeed =100; // задава се скоростта на левия двигател при Калибриране
const int RightSpeed =100; // задава се скоростта на десния двигател при Калибриране
// Данните се запазват за задачите "Изход лабиринт" и "Следене на линия"

int speedLeft = LeftSpeed;
int speedRight = RightSpeed;
//-----------------------------------------------

void setup()
{ 
  pinMode(LEFT_FOR, OUTPUT);
  pinMode(LEFT_BACK, OUTPUT);
  pinMode(RIGHT_FOR, OUTPUT);
  pinMode(RIGHT_BACK, OUTPUT);
}

//---------------------------------------------------------

void loop()
{ 
  moveForward();   
}

//==================================== FUNCTIONS =====================================================

void moveForward() // Move forward
{
  analogWrite(LEFT_FOR, abs(speedLeft));
  analogWrite(LEFT_BACK, LOW);
  analogWrite(RIGHT_FOR, abs(speedRight));
  analogWrite(RIGHT_BACK, LOW);
}

void stopMoving() // Stop movement
{
  analogWrite(LEFT_FOR, HIGH);
  analogWrite(LEFT_BACK, HIGH);
  analogWrite(RIGHT_FOR, HIGH);
  analogWrite(RIGHT_BACK, HIGH);
}
