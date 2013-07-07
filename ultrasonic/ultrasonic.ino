#include <Ultrasonic.h>

const int trig = 8;
const int echo = 9;

Ultrasonic ultrasonic(8,9);

void setup(){
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  
  long cm;  
  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);
    
  cm = (ultrasonic.Ranging(CM));
  
  Serial.print(cm); 
  Serial.println(); 
  
  digitalWrite(echo, LOW);
  
  delay(1500);
}
