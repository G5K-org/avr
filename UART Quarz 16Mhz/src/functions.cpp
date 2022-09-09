#include "functions.h"

void init_GPIO()
{
 DDRD |= (1<<PORTD);
}
void USART_Init( unsigned int ubrr)
{
UBRRH = (unsigned char)(ubrr>>8);
UBRRL = (unsigned char)ubrr;
UCSRB = (1<<RXEN)|(1<<TXEN);
UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
}


void init_ADC()
{
ADMUX |= (1<<REFS0);
ADCSRA |= (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}

void init_PWM()
{
//PD7 // OC2
TCNT2 = 0;
TCCR2 |= (1<<WGM21)|(1<<WGM20)|(1<<CS20)|(1<<COM21);
DDRD|= (1<<PD7);
}


void USART_Transmit_String(char* data )
{
int i = 0;
while(data[i]!='\0')
{
while (!(UCSRA & (1<<UDRE)));
UDR = data[i];
i++;
}
while (!(UCSRA & (1<<UDRE)));
UDR = '\n';


}

void set_LED_Brightnes(int value)
{
    OCR2 = value;
}

void flash_light()
{

PORTD ^= (1<<PD7);
_delay_ms(00);
}

int read_ADC()
{
    ADCSRA |= (1<<ADSC);
    while(ADCSRA &(1<<ADSC));
    if(ADIF)
    {
    int alldata = (ADCL);
    alldata |= (ADCH<<8);
    return alldata;
    
    }
    return 0;
    
}

