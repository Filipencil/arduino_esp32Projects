#include <ESP32Servo.h>

Servo servoA;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  servoA.attach(13);
  servoA.write(0);
}

void loop() {
 if(Serial.available()>0){

  int angulo = Serial.parseInt();

  if (angulo>=0 && angulo <= 180){
    servoA.write(angulo);
    Serial.print("Servo movido para: ");
    Serial.print(angulo);
    Serial.println(" graus");
  } else {
    Serial.println("Ângulo invalido! Digite um valor entre 0 e 180.");
  }

  while (Serial.available()>0) {
    Serial.read();
  }
 }
}