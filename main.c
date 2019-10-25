#include "stm32f10x.h"                  // Device header
#include "delay.h"

int liste [10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
uint8_t sayac=0;
void Ayarlar()
{
	RCC->APB2ENR |=1<<2;
	GPIOA->CRL =0x22222222;
	GPIOA->ODR =0;
}

int main()
{
	delay_init();
	Ayarlar();
	
	while(1)
	{
	
   if(sayac>=10)
     sayac=0;
   else
	{	 
	 GPIOA->ODR =liste[sayac];
	 delay_ms(1000);
	 sayac++;	
	 }
	
	}
	
}

//volatile uint32_t *ptr=(uint32_t *) (gpioa adresi)   *ptr=12

