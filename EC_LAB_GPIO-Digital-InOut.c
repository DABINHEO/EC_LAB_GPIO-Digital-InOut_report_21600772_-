#include "stm32f4xx.h"
#include "ecRCC.h"
#include "ecGPIO.h"

#define LED_PIN 	5
#define BUTTON_PIN 13

void setup(void);
	
int main(void) { 
	int num = 0;
	int State[4][4] = {
	{1,0,0,0},
	{0,1,0,0},
	{0,0,1,0},
	{0,0,0,1}
	};	
	// Initialiization --------------------------------------------------------
	setup();
	// Inifinite Loop ----------------------------------------------------------
	while(1){
		GPIO_write(GPIOA, 5, State[num][0]);
		GPIO_write(GPIOA, 6, State[num][1]);
		GPIO_write(GPIOA, 7, State[num][2]);
		GPIO_write(GPIOB, 6, State[num][3]);
		if(GPIO_read(GPIOC, BUTTON_PIN) == 0)	{
			num++;
			if (num > 3) num = 0;
			for(int i = 0; i < 500000;i++){}
		}
	}
}


// Initialiization 
void setup(void)
{
	RCC_HSI_init();	
	GPIO_init(GPIOC, BUTTON_PIN, INPUT);
	LED_init();
	
}
