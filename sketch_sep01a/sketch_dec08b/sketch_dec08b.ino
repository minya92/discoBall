#include <Stepper.h>

const int in1 = 2;
const int in2 = 3;
const int IN3 = 4;
const int IN4 = 5;

const int stepsPerRevolution = 3; // шагов за один оборот

const int dl = 2000;


void setup() {
   pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  //Stepper myStepper(stepsPerRevolution, IN1, IN2); 
 // myStepper.setSpeed(20); // скорость 5 об/минуту
  //delay(3000);
  //myStepper.step(stepsPerRevolution); // шаг в одном направлении
}

void loop() {
  digitalWrite( in1, LOW ); 
  digitalWrite( in2, LOW ); 
  delay(dl);

 

  digitalWrite( in1, HIGH ); 
  digitalWrite( in2, HIGH ); 
  delay(dl);

  
  //myStepper.step(stepsPerRevolution); // шаг в одном направлении
  //delay(3000);
  //Serial.println("counterclockwise");
  //myStepper.step(-stepsPerRevolution); // шаг в обратную сторону
  //delay(2500); 
}
