#include <Servo.h>


int value = 0; // set values you need to zero


Servo firstESC; //Create as much as Servoobject you want. You can controll 2 or more Servos at the same time

void setup() {

  firstESC.attach(9);    // attached to pin 9 I just do this with 1 Servo
  Serial.begin(9600);    // start serial at 9600 baud

}

void loop() {

  value = analogRead(0);

  value = map(value, 0, 1023, 1205, 2000);
 
  Serial.println(value);

  if(Serial.available()) 
    value = Serial.parseInt();    // Parse an Integer from Serial

  firstESC.writeMicroseconds(value);

  delay(5);
 
}
