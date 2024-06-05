#include <Wire.h>
#include <Servo.h>

Servo monServo;
Servo monServo2;

void setup() {

  Wire.begin();

  monServo.attach(8);
  monServo2.attach(9);

  delay(1500)

  Serial.begin(9600);

}

void StopMoteur(){
  //Serial.println("STOP");
  monServo.writeMicroseconds(1500);
  monServo2.writeMicroseconds(1450);
}

void AvanceMoteur(){
  //Serial.println("AVANCE");
  monServo.writeMicroseconds(2000);
  monServo2.writeMicroseconds(1000);
}

void ReculerMoteur(){
  //Serial.println("RECULE");
  monServo.writeMicroseconds(1000);
  monServo2.writeMicroseconds(2000);
  delay(100);
}

void TourneG(){
  //Serial.println("GAUCHE");
  monServo.writeMicroseconds(1500);
  monServo2.writeMicroseconds(1000);
}

void TourneD(){
  //Serial.println("DROITE");
  monServo.writeMicroseconds(2000);
  monServo2.writeMicroseconds(1500);
}
void CalibTourneG(){
  //Serial.println("GAUCHE");
  monServo.writeMicroseconds(1700);
  monServo2.writeMicroseconds(1200);
}

void CalibTourneD(){
  //Serial.println("DROITE");
  monServo.writeMicroseconds(1800);
  monServo2.writeMicroseconds(1300);
}

void loop() {
  
  AvanceMoteur();
  delay(2700);
  CalibTourneD();
  delay(200);
  CalibTourneG();
  delay(200);
  AvanceMoteur();
  delay(2000);

  
}
