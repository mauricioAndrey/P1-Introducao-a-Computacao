#ifndef DEFINES
#define DEFINES

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

/*Geral*/
#define seg 1000

/* pinos dos leds do semaforo do carro */
#define LG 5
#define LY 4
#define LR 3

/* pinos dos leds do semaforo dos pedestres */
#define LGP 2
#define LYP 1
#define LRP 0

/* pino do buzzer*/
#define buz 13

/* lcd */
extern bool usoLCD; /*1 = pedestreSema usa | 0 = carroSema usa*/
extern LiquidCrystal_I2C lcd;

// #define RS 5
// #define E 4
// #define D4 3
// #define D3 2
// #define D2 1
// #define D1 0



#endif