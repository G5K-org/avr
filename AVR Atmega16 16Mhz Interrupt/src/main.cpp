#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "functions.h"
#define BAUD 9600
#define UBRRx F_CPU/16/BAUD-1



void init_ADC1();

int timer_x;



int main()
{
  USART_Init(UBRRx);
  init_ADC1();
  DDRD |= (1 << PORTD7);
  TCCR0 |= (1 << WGM01) | (1 << CS02) | (1 << CS00);

  OCR0 = 255;
  TIMSK |= (1 << OCIE0);
  sei();

  while (1)
  {
  char buffer[8];
  USART_Transmit_String(itoa(read_ADC(),buffer,10));
  _delay_ms(1000);
  }///dddd

  return 0;
}

ISR(TIMER0_COMP_vect)
{
  timer_x++;
  if (timer_x >= 25)
  {
    PORTD ^= (1 << PD7);
    timer_x = 0;
  }
}

void init_ADC1()
{
  ADMUX |= (1 << REFS0) | (7 << MUX0);
  ADCSRA |= (1 << ADEN) | (1 << ADPS2) |(1 << ADPS1) |(1 << ADPS0);
}
