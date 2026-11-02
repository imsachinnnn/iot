#include<Servo.h>
Servo myservo;
int servopin=13;
void setup(){
  myservo.attach(servopin);
}
void loop(){
  myservo.write(20);
  delay(500);
  myservo.write(60);
  delay(500);
  myservo.write(180);
  delay(1000);
}
