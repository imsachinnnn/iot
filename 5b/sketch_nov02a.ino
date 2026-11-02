#define TRIG_PIN 5 
#define ECHO_PIN 13 
#define BUZZER_PIN 2 
 
void setup() { 
  Serial.begin(9600); 
 
  pinMode(TRIG_PIN, OUTPUT); 
  pinMode(ECHO_PIN, INPUT); 
  pinMode(2, OUTPUT); 
 
  digitalWrite(TRIG_PIN, LOW); 
  digitalWrite(BUZZER_PIN, LOW); 
} 
 
void loop() { 
  // Send ultrasonic trigger pulse 
  digitalWrite(TRIG_PIN, LOW); 
  delayMicroseconds(2); 
 
  digitalWrite(TRIG_PIN, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(TRIG_PIN, LOW); 
 
  // Measure echo 
  long duration = pulseIn(ECHO_PIN, HIGH, 30000); 
 
  // Check if echo was received 
  if (duration == 0) { 
    Serial.println("No echo detected"); 
    digitalWrite(BUZZER_PIN, LOW); 
    delay(500); 
    return; 
  } 
 
  // Calculate distance 
  float distance = (duration * 0.0343) / 2; 
 
  Serial.print("Distance: "); 
  Serial.print(distance); 
  Serial.println(" cm"); 
 
  // Turn buzzer ON when object is closer than 10 cm 
  if (distance > 0 && distance < 10) { 
    digitalWrite(2, HIGH); 
  }  
  else { 
    digitalWrite(2, LOW); 
  } 
 
  delay(300); 
} 
