#include "rcc.h"
#include "stm32g431xx.h"



static const RCC_PeriphDef RCC_Table[] = 
{
		{&RCC->AHB2ENR, 0}, //GPIOA
		{&RCC->AHB2ENR, 1}, //GPIOB
		{&RCC->AHB2ENR, 2}, //GPIOC
		{&RCC->AHB2ENR, 3}, //GPIOD
		{&RCC->AHB2ENR, 4}, //GPIOE
		{&RCC->AHB2ENR, 5}, //GPIOF

		{&RCC->APB2ENR,  14}, //USART1
		{&RCC->APB1ENR1, 17}, //USART2
		{&RCC->APB1ENR1, 18}, //USART3

		{&RCC->APB1ENR1, 19}, //UART4
		{&RCC->APB1ENR1, 20}, //UART5

		{&RCC->APB2ENR, 11},  //TIM1
		{&RCC->APB1ENR1, 0},  //TIM2
		{&RCC->APB1ENR1, 1},  //TIM3
		{&RCC->APB1ENR1, 2},  //TIM4
		{&RCC->APB1ENR1, 4},  //TIM6
		{&RCC->APB1ENR1, 5},  //TIM7
		{&RCC->APB2ENR, 13},  //TIM8
		{&RCC->APB2ENR, 16},  //TIM15
		{&RCC->APB2ENR, 17},  //TIM16
		{&RCC->APB2ENR, 18},  //TIM17

		{&RCC->APB2ENR,  12}, //SPI1
		{&RCC->APB1ENR1, 14}, //SPI2
		{&RCC->APB1ENR1, 15}, //SPI3
		{&RCC->APB2ENR,  15}, //SPI4

		{&RCC->APB1ENR1, 21}, //I2C1
		{&RCC->APB1ENR1, 22}, //I2C2
		{&RCC->APB1ENR1, 23}, //I2C3
		{&RCC->APB1ENR2,  1}, //I2C4

		{&RCC->AHB1ENR, 0},   //DMA1
		{&RCC->AHB1ENR, 1},   //DMA2
		{&RCC->AHB1ENR, 2},   //DMAMUX1

		{&RCC->AHB2ENR, 13},  //ADC12
		{&RCC->AHB2ENR, 14},  //ADC3

		{&RCC->AHB2ENR, 16},  //DAC1
		{&RCC->AHB2ENR, 17},  //DAC2

};


static const RCC_PeriphDef RCC_ResetTable[] =
{
    { &RCC->AHB2RSTR, 0 }, // GPIOA
    { &RCC->AHB2RSTR, 1 }, // GPIOB
    { &RCC->AHB2RSTR, 2 }, // GPIOC
    { &RCC->AHB2RSTR, 3 }, // GPIOD
    { &RCC->AHB2RSTR, 4 }, // GPIOE
    { &RCC->AHB2RSTR, 5 }, // GPIOF

    { &RCC->APB2RSTR, 14 },  // USART1
    { &RCC->APB1RSTR1, 17 }, // USART2
    { &RCC->APB1RSTR1, 18 }, // USART3
    { &RCC->APB1RSTR1, 19 }, // UART4
    { &RCC->APB1RSTR1, 20 }, // UART5

    { &RCC->APB2RSTR, 11 }, // TIM1
    { &RCC->APB1RSTR1, 0 }, // TIM2
    { &RCC->APB1RSTR1, 1 }, // TIM3
    { &RCC->APB1RSTR1, 2 }, // TIM4
    { &RCC->APB1RSTR1, 4 }, // TIM6
    { &RCC->APB1RSTR1, 5 }, // TIM7
    { &RCC->APB2RSTR, 13 }, // TIM8
    { &RCC->APB2RSTR, 16 }, // TIM15
    { &RCC->APB2RSTR, 17 }, // TIM16
    { &RCC->APB2RSTR, 18 }, // TIM17

    { &RCC->APB2RSTR, 12 },  // SPI1
    { &RCC->APB1RSTR1, 14 }, // SPI2
    { &RCC->APB1RSTR1, 15 }, // SPI3
    { &RCC->APB2RSTR, 15 },  // SPI4

    { &RCC->APB1RSTR1, 21 }, // I2C1
    { &RCC->APB1RSTR1, 22 }, // I2C2
    { &RCC->APB1RSTR1, 23 }, // I2C3
    { &RCC->APB1RSTR2, 1 },  // I2C4

    { &RCC->AHB1RSTR, 0 }, // DMA1
    { &RCC->AHB1RSTR, 1 }, // DMA2
    { &RCC->AHB1RSTR, 2 }, // DMAMUX1

    { &RCC->AHB2RSTR, 13 }, // ADC12
    { &RCC->AHB2RSTR, 14 }, // ADC345

    { &RCC->AHB2RSTR, 16 }, // DAC1
    { &RCC->AHB2RSTR, 17 }, // DAC2

    { &RCC->APB2RSTR, 0 },  // SYSCFG
};


void RCC_EnableClock(RCC_PeriphDef periph)
{
	*RCC_Table[periph].reg |=(1U << RCC_Table[periph].bit);
}

void RCC_DisableClock(RCC_PeriphDef periph)
{
	*RCC_Table[periph].reg &= ~(1U << RCC_Table[periph].bit);
}

void RCC_ResetPeripheral(RCC_PeriphDef periph)
{
	*RCC_ResetTable[periph].reg |=(1U << RCC_ResetTable[periph].bit);    // Set reset bit
	*RCC_ResetTable[periph].reg &= ~(1U << RCC_ResetTable[periph].bit);  //Clear reset bit
}
