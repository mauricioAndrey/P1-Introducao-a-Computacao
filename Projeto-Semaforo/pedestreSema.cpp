
#include "pedestreSema.h"

/* variaveis gerais para a frequencia das coisas */
unsigned long pedestreMilli;
unsigned long buzMilli;

/* variável para a mudança de estados */
int estadoPedestre = 0;
/* variável para os estados */
enum estados_pedestre {
  neutro,
  amarelo,
  vermelho,
  verde
};

/* abstraindo o semaforo do pedestre */
void pedestreNeutro(){
  digitalWrite(LG, LOW);
  digitalWrite(LY, LOW);
  digitalWrite(LR, LOW);
}
void pedestreNoVermelho(){
  digitalWrite(LGP, LOW);
  digitalWrite(LYP, LOW);
  digitalWrite(LRP, HIGH);
}
void pedestreNoVerde(){
  digitalWrite(LGP, HIGH);
  digitalWrite(LYP, LOW);
  digitalWrite(LRP, LOW);
}
void pedestreNoAmarelo(){
  digitalWrite(LGP, LOW);
  digitalWrite(LYP, HIGH);
  digitalWrite(LRP, LOW);
}

/* coisas do buzzer */
void buzVerde(int tom){
  if(millis() - buzMilli < seg/2 && millis() - pedestreMilli < 6*seg){
    tone(buz, tom);
  } else { 
    noTone(buz);
  } 
}
void buzAmarelo(int tom){
  if(millis() - buzMilli < 300){
    tone(buz, tom);
  } else if(millis() - buzMilli < seg){
    noTone(buz);
  } 
}

/* as mudanças do semaforo do pedestre */
void maqEstadosPedestre(){
  /* máquina de estados para as mudanças das saídas */
  switch (estadoPedestre){
    case neutro:
      pedestreNeutro();
      break;
    case amarelo:
      pedestreNoAmarelo();
      buzAmarelo(900);
      break;
    case vermelho:
      pedestreNoVermelho(); 
      break;
    case verde:
      pedestreNoVerde(); 
      buzVerde(1000);
      break;
    default:
      break;
  }

  /* mudanças da variável estadoPedestre a depender do tempo*/
  int tempo = millis() - pedestreMilli;
  if(tempo < 5*seg){
    /*carro no amarelo*/
    estadoPedestre = vermelho;
  }
  else if(tempo < 12*seg){
    /*carro no vermelho*/
    estadoPedestre = verde;
  }
  else if(tempo < 15*seg){
    /*carro no vermelho*/
    estadoPedestre = amarelo;
  }
  else if(tempo < 25*seg){
    /*carro no verde*/
    estadoPedestre = vermelho;
  }
  else {
    pedestreMilli = millis();
  }

  /* frequencia do buzzer é a cada segundo */
  if(millis() - buzMilli > seg)
    buzMilli = millis();
}


//contar quanto tempo fica o pedestre andando
