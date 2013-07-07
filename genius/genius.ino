int leds[6] = {2,3,4,5,6,7};
int buttons[6] = {8,9,10,11,12,13};
int seqLed[6];
int seqButton[6];
int buttonState = 0;
int rodada = 1;
boolean resposta;
int ledGreen = 12;
int ledRed = 13;
long time = 0;
long limTime = 25000;

void setup(){
  
  for (int i=0;i<=5;i++)
  {
    pinMode(leds[i],OUTPUT);
    pinMode(buttons[i],INPUT);
  }
  pinMode(ledGreen,OUTPUT);
  pinMode(ledRed,OUTPUT);
}

void loop(){
  randomSeed(millis()/1000); //semente para variar o rand;
  
  for (int a=0;a<=5;a++)
  {
       seqLed[a]=leds[rand()%6]; //como começa no 2, passei o rand como indice do array
  }
  
  for (int b=0;b<=5;b++)
  {
       digitalWrite(seqLed[b], HIGH);
       delay(1000);
       digitalWrite(seqLed[b], LOW);
       delay(1000);
  }  
  
  
 for (int j=0;j<=5;j++)
  {
       /*for (int i=0;i<=5;i++)
       {
            buttonState = digitalRead(buttons[i]);
            if (buttonState == HIGH)
            {
                seqButton[j] = i+1;
                break;
            }
        }*/
        time = millis();//tempo atual
        while(millis() <= (time+limTime)){//condição de contagem do tempo
          for (int i=0;i<=5;i++){//percorre os botões
            buttonState = digitalRead(buttons[i]);
            if (buttonState == HIGH)
              {
                seqButton[j] = (buttons[i]-6);//passa o valor do led correspondente ao botão
                
                while(digitalRead(buttons[i]) == HIGH)
                  digitalWrite(buttons[i]-6, HIGH);//acende o led correspondente
                  
                digitalWrite(buttons[i]-6, LOW);
                break;//fim do while
              }
          } 
          
        }
  }
    
 for (int c=0;c<=5;c++)
 {
      if (seqLed[c] == seqButton[c])
          resposta = true;
      else
      {
          resposta = false;
          break;
      }
 }
 
 if (resposta == true)
 {
     digitalWrite(ledGreen,HIGH);
     delay(3000);
     digitalWrite(ledGreen,LOW);
     rodada++;
     limTime = limTime - (rodada*500);
 } 
 else
 {
    digitalWrite(ledRed,HIGH);
    delay(3000);
    digitalWrite(ledRed,LOW);
    rodada = 1;
    limTime = 25000;
 }
}
  
  
