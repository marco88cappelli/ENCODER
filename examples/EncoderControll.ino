#include <ENCODER.h>

#define CLK 2
#define DT  3
#define SW  4

MY_ENCODER enc;

int n;
int old_n;

void aumenta(){
  n++;
}

void diminuisci(){
  n--;
 }
 
 void pulsante(){
  Serial.println("PULSANTE PREMUTO");
 }
 
 void setup(){
  Serial.begin(9600);
  enc.begin(CLK,DT,SW,aumenta,diminuisci,pulsante);
  n = 0;
  old_n = 1;
 }
 
 void loop(){
  enc.controll_Encoder(); //Intercetta la rotazione dell'encoder in senso orario e antiorario
  enc.controll_Button();  //Intercetta la pressione dello switch dell'ENCODER
  
  if (n != old_n){
    //Stampa il valore della variabile n incrementata o decrementata dalle funzioni attivate dall'encoder e le stampa
    //solo se il valore è cambiato
    Serial.println(n);
    old_n = n;
  }
 }
