
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
  delay(100);
}

void TourneG(){
  monServo.writeMicroseconds(1000);
  monServo2.writeMicroseconds(1000);
  delay(100);
}

void TourneD(){
  monServo.writeMicroseconds(2000);
  monServo2.writeMicroseconds(2000);
  delay(100);
}

void loop() {
  
  int DistanceDevant = analogRead(IR_DEVANT);
  int DistanceDroite = analogRead(IR_DROITE);
  int DistanceGauche = analogRead(IR_GAUCHE);

//Un peu trop à droite
  if (DistanceDroite < 200 && DistanceDevant > 400 && DistanceGauche > 400) {
    TourneG();
    delay(100);
    AvanceMoteur();
    delay(500);

  }
  //Un peu trop à gauche
  if (DistanceGauche < 200 && DistanceDevant > 400 && DistanceDroite > 400) {
    TourneD();
    delay(100);
    AvanceMoteur();
    delay(500);

  }
  //Mur devant
  if (DistanceGauche < 400) {

    if(DistanceDroite < 400){
      TourneG();
      delay(200);
      AvanceMoteur();
      delay(500);
    }
    else if(DistanceGauche < 400){
      TourneD();
      delay(200);
      AvanceMoteur();
      delay(500);
    }
    else{
      TourneG();
      delay(200);
      AvanceMoteur();
      delay(500);
    }

  }



  if (DistanceDevant < 400) {
    StopMoteur();
    ReculerMoteur();
    TourneD();

  } else {

    moveRobot();
  }
  

}
