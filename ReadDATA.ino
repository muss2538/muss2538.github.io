#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo Base;
Servo ArmBase1;
Servo ArmBase2;
Servo Arm1;
Servo Arm2;
Servo Arm3;
Servo Hand;

#define Righ_Base 2
#define Left_Base 3
#define Righ_joy 4
#define Left_joy 5
#define Righ_joyVRX A0
#define Righ_joyVRY A1
#define Left_joyVRX A3
#define Left_joyVRY A2

int Data[8];
int pos[6];

void setup() {
  Serial.begin(19200); 
  lcd.begin();

  Base.attach(6);
  ArmBase1.attach(7);
  ArmBase2.attach(8);
  Arm1.attach(9);
  Arm2.attach(10);
  Arm3.attach(11);
  Hand.attach(12);

  pos[0]=90;
  pos[1]=74;
  pos[2]=90;
  pos[3]=90;
  pos[4]=90;
  pos[5]=90;
  
  pinMode(Righ_Base,INPUT_PULLUP);  
  pinMode(Left_Base,INPUT_PULLUP);
  pinMode(Righ_joy,INPUT_PULLUP);  
  pinMode(Left_joy,INPUT_PULLUP);
}

void loop() {
  manual();
  Base.write(pos[5]);
  ArmBase1.write(pos[4]);
  ArmBase2.write(pos[4]);
  Arm1.write(pos[2]);
  Arm2.write(pos[3]);
  Arm3.write(pos[1]);
  Hand.write(pos[0]);
  delay(10);
}

void manual(){
  Data[0] = digitalRead(Righ_Base);
  Data[1] = digitalRead(Left_Base);
  Data[2] = digitalRead(Righ_joy);
  Data[3] = digitalRead(Left_joy);
  Data[4] = analogRead(Righ_joyVRX);
  Data[5] = analogRead(Righ_joyVRY);
  Data[6] = analogRead(Left_joyVRX);
  Data[7] = analogRead(Left_joyVRY);

//digitalSwitch
  if((Data[0] == LOW) && (pos[0] <= 98)){pos[0]++;}
  if((Data[1] == LOW) && (pos[0] >= 45)){pos[0]--;}
  if((Data[2] == LOW) && (pos[1] <= 180)){pos[1]++;}
  if((Data[3] == LOW) && (pos[1] >= 0)){pos[1]--;}

//analogjoy Righ_joyVRX
  if((Data[4] >= 600) && (pos[2] <= 100)){pos[2]++;}
  if((Data[4] <= 400) && (pos[2] >= 0)){pos[2]--;}

//analogjoy Righ_joyVRY
  if((Data[5] >= 600) && (pos[3] <= 100)){pos[3]++;}
  if((Data[5] <= 400) && (pos[3] >= 0)){pos[3]--;}

//analogjoy Left_joyVRX
  if((Data[6] >= 600) && (pos[4] <= 169)){pos[4]++;}
  if((Data[6] <= 400) && (pos[4] >= 0)){pos[4]--;}

//analogjoy Left_joyVRY
  if((Data[7] <= 400) && (pos[5] <= 180)){pos[5]++;}
  if((Data[7] >= 600) && (pos[5] >= 0)){pos[5]--;}
}

