#include <Servo.h>

Servo myServo;

// Ultrasonic sensor pins
const int trigPin = 2;
const int echoPin = 3;

long duration;
int distance;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myServo.attach(9);   // Servo signal pin
  myServo.write(0);    // Start position
}

void loop() {

  // --- Ultrasonic Sensor Trigger ---
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // --- Read Echo Time ---
  duration = pulseIn(echoPin, HIGH);

  // --- Convert to Distance in cm ---
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // --- Condition: Object Detected ---
  if (distance < 20) {          // If object is within 20 cm
    myServo.write(90);          // Turn servo ON (rotate to 90°)
    delay(500);
  } 
  else {
    myServo.write(0);           // No object → servo OFF (0°)
  }

  delay(200);
}