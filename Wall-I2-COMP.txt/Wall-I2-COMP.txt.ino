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



}


void StopMoteur(){
 //Serial.println("STOP");
 monServo.writeMicroseconds(1450);
 monServo2.writeMicroseconds(1450);
}

void AvanceMoteur(){
 //Serial.println("AVANCE");
 monServo.writeMicroseconds(2000);
 monServo2.writeMicroseconds(1150);
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

void AvanceMoteurDuree(int duree) {
 AvanceMoteur();
 delay(duree);
}

void StopMoteurDuree(int duree) {
 StopMoteur();
 delay(duree);
}

void TourneDroiteDuree(int duree){
 TourneD();
 delay(duree);
}

void TourneGroiteDuree(int duree){
 TourneG();
 delay(duree);
}

void loop(){

StopMoteurDuree(3000);
AvanceMoteurDuree(2700);
TourneDroiteDuree(300);
AvanceMoteurDuree(150);
TourneGroiteDuree(330);
AvanceMoteurDuree(600);
TourneGroiteDuree(300);
AvanceMoteurDuree(200);
TourneDroiteDuree(300);
AvanceMoteurDuree(1400);

TourneGroiteDuree(300);
AvanceMoteurDuree(400);
TourneDroiteDuree(350);
AvanceMoteurDuree(500);


}