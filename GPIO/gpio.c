#include "gpio.h"
#include "stm32g431xx.h"


void GPIO_Rcc(GPIO_TypeDef *GPIOx)
{
    if (GPIOx == GPIOA)
    {
        RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    } else if (GPIOx == GPIOB)
    {
        RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
    }  else if (GPIOx == GPIOC)
    {
        RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
    }  else if (GPIOx == GPIOD)
    {
        RCC->AHB2ENR |= RCC_AHB2ENR_GPIODEN;
    }  else if (GPIOx == GPIOE)
    {
        RCC->AHB2ENR |= RCC_AHB2ENR_GPIOEEN;
    }  else if (GPIOx == GPIOF)
    {
        RCC->AHB2ENR |= RCC_AHB2ENR_GPIOFEN;
    }  else if (GPIOx == GPIOG)
    {
        RCC->AHB2ENR |= RCC_AHB2ENR_GPIOGEN;
    }
}

void GPIO_Init(GPIO_Config *Conf)
{
    // ENABLE CLOCK
    GPIO_Rcc(Conf->GPIOx);

    // CONFIGURE PIN MODE
    uint32_t pos0 = Conf->pin *2;

    Conf->GPIOx->MODER &= ~(3U << pos0); // CLEAR PIN
    Conf->GPIOx->MODER |= ((Conf->mode) << pos0); // MODE SELECT

    //PULL-UP/DOWN MODE
    Conf->GPIOx->PUPDR &= ~(3U << pos0); // CLEAR PIN
    Conf->GPIOx->PUPDR |= ((Conf->pull) << pos0); // PULL TYPE SELECT

    //OUTPUT MODE
    Conf->GPIOx->OTYPER &= ~(1U << Conf->pin); // CLEAR PIN
    Conf->GPIOx->OTYPER |= ((uint32_t)Conf->type << Conf->pin); // PUSH-PULL / OPEN DRAIN

    //OUTPUT SPEED
    Conf->GPIOx->OSPEEDR &= ~(3U << pos0); // CLEAR PIN
    Conf->GPIOx->OSPEEDR |= (((uint32_t)Conf->speed) << pos0);

    //ALTERNATE FUNCTION
    if(Conf->mode == AFMODE)
    {
        uint32_t pos1 = Conf->pin * 4;

        if (Conf->pin < 8)
        {
            //AFRL
            Conf->GPIOx->AFR[0] &= ~(0xF << pos1);
            Conf->GPIOx->AFR[0] |= ((uint32_t)Conf->af << pos1);
        } else
        {
            //AFRH
            uint8_t shift = ((Conf->pin) - 8) * 4;
            Conf->GPIOx->AFR[1] &= ~(0xF << shift);
            Conf->GPIOx->AFR[1] |= ((uint32_t)Conf->af << shift);
        }
    }
}

void GPIO_WritePin(GPIO_TypeDef *GPIOx, Pin pin, State state)
{
    if (state == SET)
        GPIOx->BSRR = (1U << pin);
    else
        GPIOx->BSRR = (1U << (pin + 16));
}

State GPIO_ReadPin(GPIO_TypeDef *GPIOx, Pin pin)
{
    return (GPIOx->IDR & (1U << pin)) ? SET : RESET;
}

void GPIO_TogglePin(GPIO_TypeDef *GPIOx, Pin pin)
{
    GPIOx->ODR ^= (1U << pin);
}

void GPIO_LockPin(GPIO_TypeDef *GPIOx, Pin pin)
{
    uint32_t lock_bit = (1U << pin);

    GPIOx->LCKR |= lock_bit;

    GPIOx->LCKR |= (1U << 16);

    GPIOx->LCKR &= ~(1U << 16);

    GPIOx->LCKR |= (1U << 16);
    
    volatile uint32_t temp = GPIOx->LCKR;
    temp = GPIOx->LCKR;
}

