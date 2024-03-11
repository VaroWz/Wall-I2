#include <VL6180X.h>
#include <Wire.h>
#include <Servo.h>

VL6180X capteurD;
VL6180X capteur;
VL6180X capteurG;

/*#define IR_DEVANT A0
#define IR_DROITE A1
#define IR_GAUCHE A2*/

Servo monServo;
Servo monServo2;

void setup() {

  Wire.begin();

  monServo.attach(8);
  monServo2.attach(9);

  Serial.begin(9600);

  digitalWrite(12, HIGH);
  capteurD.init();
  capteurD.configureDefault();
  capteurD.setAddress(0x20);

  digitalWrite(11, HIGH);
  capteur.init();
  capteur.configureDefault();
  capteurD.setAddress(0x22);

  digitalWrite(10, HIGH);
  capteurG.init();
  capteurG.configureDefault();
  capteurD.setAddress(0x24);



}
/*
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
}*/

void loop() {
  
  Serial.println("testt");
/*
  int DistanceDroite = capteurD.readRangeSingle();
  int DistanceDevant = capteur.readRangeSingle();
  int DistanceGauche = capteurG.readRangeSingle();

  DistanceDroite = capteurD.readRangeSingle();
  Serial.print("Capteur droite: ");
  Serial.println(DistanceDroite);

  DistanceDevant = capteur.readRangeSingle();
  Serial.print("Capteur milieu: ");
  Serial.println(DistanceDevant);

  DistanceGauche = capteurG.readRangeSingle();
  Serial.print("Capteur gauche: ");
  Serial.println(DistanceGauche);*/

  /*int DistanceDevant = analogRead(IR_DEVANT);
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
      delay(100);
      TourneG();
      delay(100);
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
  }*/



  

}
