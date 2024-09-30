/*tentativa de ler um controle infravermelho */
#include <IRremote.h>

#include <LiquidCrystal_I2C.h>

int RECV_PIN = 6;
IRrecv irrecv(RECV_PIN);
decode_results results;


LiquidCrystal_I2C lcd(0x27,20,4);

int ledGreen = 3;
bool LEDgreen = false;
int atraso = 250;

uint32_t resultado;


void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  lcd.setBacklight(HIGH);

  pinMode(ledGreen, OUTPUT);
  lcd.clear();
  results.value = 0;
}

void loop(){

  if(irrecv.decode(&results)){
    Serial.println(results.value, HEX); 
    irrecv.resume();
  }

}