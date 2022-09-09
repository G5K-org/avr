#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <avr/io.h>


#ifndef __FUNCTIONSXXXX
#define __FUNCTIONSXXXX

void init_GPIO();
void flash_light();
void USART_Init( unsigned int ubrr); 
void USART_Transmit_String(char* data);
void init_ADC();
void init_PWM();
int read_ADC();
void set_LED_Brightnes(int value);

#endif