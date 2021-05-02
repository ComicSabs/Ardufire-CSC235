//Sabrina Bagley
//CSC 235, Chris Whitmire
//4/22/2021
//Ardufire (pivoted)

//Servos and all that jazz
#include <Servo.h>
Servo servoWing1; //Servo controlling left wing flap
Servo servoWing2; //Servo controlling right wing flap
Servo servoFlaps; //Servo that controls both elevator flaps
//on the tail

//Servo servoRudder; //servo that controls rudder movements

//potentiometer
int potPin=A0; //serves as the "throttle"

//DC motor/ prop
int propeller=3;

//buttons
int aButtonPin=2;
int aButState;
boolean aPrevState=LOW;
boolean aTrueState=LOW;
int wait=50;


void setup() {
  // put your setup code here, to run once:
  //syntax
  //servoWing1.attach(insert pin here)
  servoWing1.attach(5); //left wing
  servoWing2.attach(6); //right wing
  servoFlaps.attach(9);
  pinMode(potPin,INPUT);
  pinMode(aButtonPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
//controlling the propeller
int potVal=analogRead(potPin);
int throttle=map(potVal,0,1023,0,255);
analogWrite(propeller,throttle);
Serial.println(throttle);
//debouncing the button & providing values
aTrueState= digitalRead(aButtonPin);
//Serial.println(aButState);

if(aTrueState== HIGH && aPrevState==LOW){
  aButState=1-aButState;
  delay(wait);
}
aPrevState=aTrueState;
//Serial.println(aTrueState);

if(aButState==1){
  servoWing1.write(130);
 // delay(500);
  servoWing2.write(130);
  servoFlaps.write(150);
}

  else{
 servoWing1.write(0);
 servoWing2.write(0);
 servoFlaps.write(0);
  }
  
//  delay(500);
//  servoWing2.write(0);
}
