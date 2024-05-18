  #include <Servo.h>

  const int sensorPin = A0;
  const int relayPin = 7;
  const int motorPin1 = 5;
  const int motorPin2 = 6;
  const int enablePinA = 9;
  const int enablePinB = 10;

  Servo servo;

  void setup() {
    pinMode(sensorPin, INPUT);
    pinMode(relayPin, OUTPUT);
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(enablePinA, OUTPUT);
    pinMode(enablePinB, OUTPUT);
    
    servo.attach(3);
  }

  void loop() {
    int sensorValue = analogRead(sensorPin);
    float temperature = (sensorValue * 5.0 * 100.0) / 1024.0;
    
    if (temperature > 25) {
      digitalWrite(relayPin, HIGH);
      digitalWrite(motorPin1, HIGH);
      digitalWrite(motorPin2, LOW);
      analogWrite(enablePinA, 255);
      analogWrite(enablePinB, 0);
      Serial.println("Temperatura alta! Encendiendo motor en una dirección.");
    } else {
      digitalWrite(relayPin, LOW);
      analogWrite(enablePinA, 0);
      analogWrite(enablePinB, 0);
      Serial.println("Temperatura normal. Motor apagado.");
    }

    delay(1000);
  }
