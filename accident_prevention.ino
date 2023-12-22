#include <NewPing.h>

int trig=11;
int echo=12;
int redpin=2;
int greenpin=3;
int yellowpin=4;
int motorpin=5;
int duration;
int distance;

void setup()
{
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(redpin,OUTPUT);
  pinMode(greenpin,OUTPUT);
  pinMode(yellowpin,OUTPUT);
  Serial.begin(9600);

}

void loop()
{
  digitalWrite(trig,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig,LOW);


  duration = pulseIn(echo,HIGH);
  //calculating distance between vehicle and obstrucle:
  distance = (duration/2) / 28.5 ;
  Serial.println(distance);
  //if the distance between vehicle and obstrucle is more than 30 its considered as safe distance and green LED light up indicating safety and motor runs with full speed:
  if(distance>30){
    digitalWrite(redpin,LOW);
    digitalWrite(greenpin,HIGH);
    digitalWrite(yellowpin,LOW);
    analogWrite(motorpin,255);
  }
  //if the distance between vehicle and obstrucle is more than 20 and less than 30 its considered as warning distance and yellow LED light up indicating warning and motor runs with slightly less speed:
  if(distance>20 && distance<30){
    digitalWrite(redpin,LOW);
    digitalWrite(greenpin,LOW);
    digitalWrite(yellowpin,HIGH);
    analogWrite(motorpin,125);
  }
  //if the distance between vehicle and obstrucle is more than 10 and less than 20 its considered as warning distance and yellow LED light up indicating warning and motor runs with slightly less speed:
  if(distance>10 && distance<20){
    digitalWrite(redpin,LOW);
    digitalWrite(greenpin,LOW);
    digitalWrite(yellowpin,HIGH);
    analogWrite(motorpin,125);
  }
  //if the distance between vehicle and obstrucle is less than 30 its considered as danger and red LED light up indicating danger and motor is off:
  if(distance<10){
    digitalWrite(redpin,HIGH);
    digitalWrite(greenpin,LOW);
    digitalWrite(yellowpin,LOW);
    analogWrite(motorpin,0);
  }
