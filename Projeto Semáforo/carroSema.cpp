
#include "carroSema.h"

/* variaveis gerais para a frequencia das coisas */
unsigned long carroMilli;

int estadoCarro = 0;
/* variável para os estados */
enum estados_carro {
  neutro,
  amarelo,
  vermelho,
  verde
};
void carroNeutro(){
  digitalWrite(LG, LOW);
  digitalWrite(LY, LOW);
  digitalWrite(LR, LOW);
}
void carroNoVermelho(){
  digitalWrite(LG, LOW);
  digitalWrite(LY, LOW);
  digitalWrite(LR, HIGH);
}
void carroNoVerde(){
  digitalWrite(LG, HIGH);
  digitalWrite(LY, LOW);
  digitalWrite(LR, LOW);
}
void carroNoAmarelo(){
  digitalWrite(LG, LOW);
  digitalWrite(LY, HIGH);
  digitalWrite(LR, LOW);
}

/* mexendo no lcd durante as mudanças de estado */
void lcdAmarelo(){
  lcd.setCursor(0,0);
  lcd.print("--------------------");

  lcd.setCursor(0,1);      
  lcd.print("Proximo: Pedestres  "); 

  lcd.setCursor(0,2);
  lcd.print("Tempo: ");
  lcd.print(4 - contando(5), "    ");

  lcd.setCursor(0,3);
  lcd.print("--------------------");
}
void lcdVermelho(){
  lcd.setCursor(0,0);
  lcd.print("--------------------");

  lcd.setCursor(0,1); 
  lcd.print("Vez do Pedestres   "); 
  
  lcd.setCursor(0,2);
  lcd.print("Tempo: ");
  lcd.print(14 - contando(5), "    ");

  lcd.setCursor(0,3);
  lcd.print("--------------------");
}
void lcdVerde(){
  lcd.setCursor(0,0);
  lcd.print("--------------------");

  lcd.setCursor(0,1);
  lcd.print("Vez dos Carros    ");
  
  lcd.setCursor(0,2);
  lcd.print("Tempo: ");
  lcd.print(24 - contando(5), "    ");

  lcd.setCursor(0,3);
  lcd.print("--------------------");
}

/* para mostrar o tempo que falta para mudança no semaforo */
int contando(int resto){
    return ((millis() - carroMilli) - resto)/seg;
}

void maqEstadosCarro(){
  /* mudanças de estados */
  switch (estadoCarro){
    case neutro:
      carroNeutro();
      carroMilli = millis();
      lcd.clear();
      break;
    /*AMARELO: primeiro estado do semaforo para os carros */
    case amarelo:
      carroNoAmarelo();
      if(!usoLCD) lcdAmarelo();     
      break;
    /*VERMELHO: segundo estado do semaforo para os carros */
    case vermelho:
      carroNoVermelho();
      if(!usoLCD) lcdVermelho();
      break;
    /*VERDE: terceiro estado do semaforo para os carros */
    case verde:
      carroNoVerde();
      if(!usoLCD) lcdVerde();
      break;
    default:
      carroMilli = millis();
      lcd.clear();
      break;
  }

  /* a depender do tempo, os estados mudam */
  unsigned long tempo = millis() - carroMilli;
  if(tempo < 4.8*seg){
    usoLCD = 0;
    estadoCarro = amarelo;
  }
  /* situação especial */
  else if(tempo < 4.9*seg) {
    usoLCD = 0;
    lcd.clear();
  }
  else if(tempo < 14.8*seg){
    estadoCarro = vermelho;
  }
  /* situação especial */
  else if(tempo < 14.9*seg) {
    lcd.clear();
  }
  else if(tempo < 25*seg){
    estadoCarro = verde;
  }
  else {
    estadoCarro = neutro;
  }

}
