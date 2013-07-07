#include <NECIRrcv.h>

/*
  Play button code = 3375783559
  Stop button code = 3442630279  
*/

const long btnPlay = 3375783559;
const long btnStop = 3442630279;
int irPin = 9;
int ledpin = 8;

NECIRrcv ir(irPin);

void setup(){
  Serial.begin(9600);
  pinMode(irPin, INPUT);
  pinMode(ledpin, OUTPUT);
  ir.begin();
}

void loop(){
  
  unsigned long code = 0;
  while(ir.available()){
    code = ir.read();
    Serial.println(code);
    
    if(code == btnPlay){  
      digitalWrite(ledpin, HIGH);
    }else if(code == btnStop){
      digitalWrite(ledpin, LOW);
    }
    
}
  
  
 
}
