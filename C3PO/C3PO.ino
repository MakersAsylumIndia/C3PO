/*
C3PO
Date: 9-Apr-15
Author: Hemal M. Chevli
2 DC motors move the two arms
2 servos move the waist and the head

Pin definitions

Left Arm 1:5   ->IN4
Left Arm 2:6   ->IN3
Right Arm 1:9  ->IN2
Right Arm 2:10 ->IN1

Servo Head : 3
Servo Waist: 11

Limit Switch:4
Limit Switch:7
*/
#include <Servo.h>
const int L_arm1 = 5;
const int L_arm2 = 6;
const int R_arm1 = 9;
const int R_arm2 = 10;

const int limit_left = 4;
const int limit_right = 7;

Servo head; //3
Servo waist;//11
int pos = 0;

void setup() {
  //set io
  //Motors
  pinMode(L_arm1, OUTPUT);
  pinMode(L_arm2, OUTPUT);
  pinMode(R_arm1, OUTPUT);
  pinMode(R_arm2, OUTPUT);
  //Limts
  pinMode(limit_left, INPUT);
  pinMode(limit_right, INPUT);
  digitalWrite(limit_left, HIGH);
  digitalWrite(limit_right, HIGH);
  //Servos
  head.attach(3);
  waist.attach(11);
  
  head.write(70);
  waist.write(130);
  /*
  Pseudo code
  set head and waist
  move motors slowly so arms towards body till limits are hit then stop
  */
}

void loop() {
  
  for(pos = 70; pos <= 130; pos += 1) 
  {                                 
    head.write(pos);            
    delay(15);                      
  }
  delay(1000);
  for(pos = 130; pos>=70; pos-=1)     
  {                                 
    head.write(pos);             
    delay(15);                       
  }
  delay(1000);
 
  //Move arms
  /*
  down('L');
  up('L');
  up('R');
 down('L');
 down('R');
*/
  for(pos = 70; pos <= 130; pos += 1) 
  {                                  
    waist.write(pos);             
    delay(15);                       
  }
  delay(1000);
  for(pos = 130; pos>=70; pos-=1)  
  {                               
    waist.write(pos);          
    delay(15);                     
  }
  delay(1000);
  
  //Pseudo code
  /*
  move head left right
  move hands up down alternatly, each movement will hit limit switch
  move waist
  delay for effect
  repeat
  */
}

void up(char arm){
  if(arm == 'L'){
  //Move left arm up
  }
  if(arm == 'R'){
  //Move right arm up
  }
}

void down(char arm){
  if(arm == 'L'){
  //Move left arm down
  }
  if(arm == 'R'){
  //Move right arm down
  }
}
