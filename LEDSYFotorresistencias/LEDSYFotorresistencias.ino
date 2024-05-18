int ldr = A0;  
int led = 13;  

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  int valor = analogRead(ldr);  
  if (valor > 500) {
    digitalWrite(led, LOW);     
    Serial.println("LEDs Apagados");
  } else {
    digitalWrite(led, HIGH);   
    Serial.println("LEDs Encendidos");
  }
  delay(100); 
}
