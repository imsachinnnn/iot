#define TRIG_PIN 5
#define ECHO_PIN 12
#define LED_PIN 2
void setup(){
  Serial.begin(9600);
  pinMode(TRIG_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);
  pinMode(2,OUTPUT);
}
void loop(){
  digitalWrite(TRIG_PIN,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN,LOW);
  long duration= pulseIn(ECHO_PIN,HIGH);
  float distance= (duration*0.0343)/2;
  Serial.print("DISTANCE");
  Serial.print(distance);
  Serial.print("CM");
  if (distance >0 && distance<10) {
    digitalWrite(2,HIGH);
  }
  else{
    digitalWrite(2,LOW);
  }
  delay(1000);
}
