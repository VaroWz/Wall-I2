
#include <Servo.h>

#define IR_DEVANT A0
#define IR_DROITE A1
#define IR_GAUCHE A2

Servo monServo;
Servo monServo2;

void setup() {

  monServo.attach(8);
  monServo2.attach(9);

  Serial.begin(9600);
}

void StopMoteur(){
  monServo.writeMicroseconds(1500);
  monServo2.writeMicroseconds(1450);
}

void AvanceMoteur(){
  monServo.writeMicroseconds(2000);
  monServo2.writeMicroseconds(1000);
}

void ReculerMoteur(){
  monServo.writeMicroseconds(1000);
  monServo2.writeMicroseconds(2000);
}

void TourneG(){
  monServo.writeMicroseconds(1000);
  monServo2.writeMicroseconds(1000);
}

void TourneD(){
  monServo.writeMicroseconds(2000);
  monServo2.writeMicroseconds(2000);
}

void loop() {
  
  int DistanceDevant = analogRead(IR_DEVANT);
  int DistanceDroite = analogRead(IR_DROITE);
  int DistanceGauche = analogRead(IR_GAUCHE);

if(DistanceDevant > 150){
  AvanceMoteur();
  delay(300);

//rectifs
  if(DistanceGauche < 15){
    TourneD();
    delay(25);
  }
  else if (DistanceDroite < 15) {
    TourneG();
    delay(25);
  }
}
else{
  if (DistanceDevant<50){
    ReculerMoteur();
    delay(100)
    TourneG();
    delay(100)
  }
  //Un peu trop à droite
  else if (DistanceDroite<DistanceGauche) {
    TourneG();
    delay(100);

  }
  //Un peu trop à gauche
  else if (DistanceGauche<DistanceDroite) {
    TourneD();
    delay(100);

  }
}



  

}
