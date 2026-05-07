#ifndef RCC_H
#define RCC_H
#include "stm32g431xx.h"

typedef struct
{
    volatile uint32_t *reg; // pointer to RCC register that is for the peripheral 
    uint8_t bit; // which bit of that register must tobe active
} RCC_PeriphDef;

typedef enum{
    RCC_GPIOA,
    RCC_GPIOB,
    RCC_GPIOC,
    RCC_GPIOD,
    RCC_GPIOE,
    RCC_GPIOF,

    RCC_USART1,
    RCC_USART2,
    RCC_USART3,

    RCC_UART4,
    RCC_UART5,

    RCC_TIM1,
    RCC_TIM2,
    RCC_TIM3,
    RCC_TIM4,
    RCC_TIM6,
    RCC_TIM7,
    RCC_TIM8,
    RCC_TIM15,
    RCC_TIM16,
    RCC_TIM17,

    RCC_SPI1,
    RCC_SPI2_I2S2,
    RCC_SPI3_I2S3,
    RCC_SPI4,

    RCC_I2C1,
    RCC_I2C2,
    RCC_I2C3,
    RCC_I2C4,

    RCC_DMA1,
    RCC_DMA2,
	RCC_DMAMUX1,

    RCC_ADC1,
    RCC_ADC2,
    RCC_ADC3,

    RCC_DAC1,
    RCC_DAC2,
} RCC_Peripheral;




#endif
