#include <Servo.h>

const int pirPin = 4;   
const int servoPin = 3;
Servo servo;

void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  servo.attach(servoPin);
  servo.write(0); 
}

void loop() {
  int pirState = digitalRead(pirPin); 

  if (pirState == HIGH) {
    servo.write(90);
    Serial.println("Movimiento detectado! Moviendo servo a 90°");
    delay(2000);
  } else {
    servo.write(0);  
    Serial.println("No hay movimiento. Servo en 0°");
  }

  delay(1000); 
}

