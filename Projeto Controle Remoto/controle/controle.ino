/*tentativa de ler um controle infravermelho */
#include <IRremote.h>

int RECV_PIN = 6;
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();

  results.value = 0;
}

void loop(){

  if(irrecv.decode(&results)){
    /*mostrar o valor da tecla em hexadecimal*/
    Serial.println(results.value, HEX); 
    delay(100);
    /*reinicia o receptor infravermelho para receber outro sinal*/
    irrecv.resume();
    delay(100);
  }

}