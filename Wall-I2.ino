#include <VL6180X.h>
#include <Wire.h>
#include <Servo.h>

VL6180X capteurD;
VL6180X capteur;
VL6180X capteurG;

Servo monServo;
Servo monServo2;

void setup() {

  Wire.begin();

  monServo.attach(8);
  monServo2.attach(9);

  Serial.begin(9600);

  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);

  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);

  digitalWrite(10, HIGH);             //DROITE
  delay(150);
  capteurG.init();
  delay(150);
  capteurG.setAddress(0x20);
  delay(150);
  capteurG.configureDefault();
  delay(150);

  digitalWrite(12, HIGH);             //GAUCHE
  delay(150);
  capteurD.init();
  delay(150);
  capteurD.setAddress(0x22);
  delay(150);
  capteurD.configureDefault();
  delay(150);

  digitalWrite(11, HIGH);           //MILIEU
  delay(150);
  capteur.init();
  delay(150);
  capteur.setAddress(0x24);
  delay(150);
  capteur.configureDefault();
  delay(150);



}
void initCapteurs(VL6180X& cap, uint8_t addresse) {
  cap.setAddress(addresse);
  cap.init();
  cap.configureDefault();
  cap.setTimeout(500);
}

void StopMoteur(){
  Serial.println("STOP");
  monServo.writeMicroseconds(1500);
  monServo2.writeMicroseconds(1450);
}

void AvanceMoteur(){
  Serial.println("AVANCE");
  monServo.writeMicroseconds(2000);
  monServo2.writeMicroseconds(1000);
}

void ReculerMoteur(){
  Serial.println("RECULE");
  monServo.writeMicroseconds(1000);
  monServo2.writeMicroseconds(2000);
  delay(100);
}

void TourneG(){
  Serial.println("GAUCHE");
  monServo.writeMicroseconds(1500);
  monServo2.writeMicroseconds(1000);
}

void TourneD(){
  Serial.println("DROITE");
  monServo.writeMicroseconds(2000);
  monServo2.writeMicroseconds(1500);
}

void loop() {
  

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
  Serial.println(DistanceGauche);

  
  if(DistanceDevant > 200 && DistanceDroite > 200 && DistanceGauche > 200){

    AvanceMoteur();

  }
  else{
    if(DistanceDevant > 130){
      AvanceMoteur();
      /*if(DistanceDroite > 35 && DistanceGauche > 35){
        AvanceMoteur();
      }
      
    
      //rectifs
      if(DistanceGauche < 35){
        TourneD();
      }
      else if (DistanceDroite < 35) {
        TourneG();
      }*/
    }
    else{
      if (DistanceDevant<130){
        if(DistanceDevant < 30){
          ReculerMoteur();
        }
        
        
        else if (DistanceDroite<DistanceGauche) {
          TourneG();

        }
      //Un peu trop à gauche
        else if (DistanceGauche<DistanceDroite) {
          TourneD();

        }
        //TourneG();
      }
      //Un peu trop à droite
      
    }

  
  }
}
