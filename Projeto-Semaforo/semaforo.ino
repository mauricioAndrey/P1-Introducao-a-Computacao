/*Bibliotecas criadas*/
#include "carroSema.h"
#include "pedestreSema.h"

LiquidCrystal_I2C lcd(0x27,20,4);

void setup() {
  /*inicializando o lcd*/
  lcd.init();
  lcd.setBacklight(HIGH);
  lcd.clear();
  /*mapeando leds*/
  pinMode(LG, OUTPUT);
  pinMode(LY, OUTPUT);
  pinMode(LR, OUTPUT);
  pinMode(LGP, OUTPUT);
  pinMode(LYP, OUTPUT);
  pinMode(LRP, OUTPUT);
  /*mapeando buz*/
  pinMode(buz, OUTPUT);
}

void loop() {
  maqEstadosPedestre();
  maqEstadosCarro();
}

