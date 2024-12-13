#include <AFMotor.h>

//defining pins and variables
#define left A0
#define right A5
#define tr  500

//defining motors
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);



void setup() {
  //declaring pin types
  pinMode(left,INPUT);
  pinMode(right,INPUT);
  //begin serial communication
  Serial.begin(9600);
  
}

void stop(){
    delay(200);
}

void loop(){
  //printing values of the sensors to the serial monitor
  Serial.print("Left  : ");
  Serial.println(analogRead(left));
  Serial.print("Right : ");
  Serial.println(analogRead(right));

  // //line detected by both
  if(analogRead(left)<tr && analogRead(right)<tr){
    //Forward
    motor1.run(FORWARD);
    motor1.setSpeed(200);
    motor2.run(FORWARD);
    motor2.setSpeed(200);
    motor3.run(FORWARD);
    motor3.setSpeed(200);
    motor4.run(FORWARD);
    motor4.setSpeed(200);
  }
  // //line detected by left sensor
  else if(analogRead(left)<tr && analogRead(right)>tr){
    //turn left
    stop();
    motor1.run(FORWARD);
    motor1.setSpeed(200);
    motor2.run(FORWARD);
    motor2.setSpeed(200);
    motor3.run(BACKWARD);
    motor3.setSpeed(200);
    motor4.run(BACKWARD);
    motor4.setSpeed(200);
    
  }
  // //line detected by right sensor
  else if(analogRead(left)>tr && analogRead(right)<tr){
    //turn right
    stop();
    motor1.run(BACKWARD);
    motor1.setSpeed(200);
    motor2.run(BACKWARD);
    motor2.setSpeed(200);
    motor3.run(FORWARD);
    motor3.setSpeed(200);
    motor4.run(FORWARD);
    motor4.setSpeed(200);
   
  }
  // //line detected by none
  else if(analogRead(left)>tr && analogRead(right)>tr){
    //stop
    motor1.run(RELEASE);
    motor1.setSpeed(0);
    motor2.run(RELEASE);
    motor2.setSpeed(0);
    motor3.run(RELEASE);
    motor3.setSpeed(0);
    motor4.run(RELEASE);
    motor4.setSpeed(0);
   
  }
  delay(500);
}

