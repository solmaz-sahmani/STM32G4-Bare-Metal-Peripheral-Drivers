#ifndef GPIO_H
#define GPIO_H

#include "stm32g431xx.h"

typedef enum 
{
    PIN_0,
    PIN_1,
    PIN_2,
    PIN_3,
    PIN_4,
    PIN_5,
    PIN_6,
    PIN_7,
    PIN_8,
    PIN_9,
    PIN_10,
    PIN_11,
    PIN_12,
    PIN_13,
    PIN_14,
    PIN_15,
} Pin;

typedef enum
{
    INPUT = 0x0,
    OUTPUT = 0x01,
    AFMODE = 0x02,
    ANALOG = 0x03
} Mode;

typedef enum
{
    NO_PULL = 0x0,
    PULL_UP = 0x1,
    PULL_DOWN = 0x2,
} Pull;

typedef enum {
    PUSH_PULL  = 0x0,
    OPEN_DRAIN = 0x1
} OutputType;

typedef enum{
    RESET,
    SET
} State;

typedef enum
{
    LOW = 0x0,
    MEDIUM = 0x01,
    HIGH = 0x02,
    VERY_HIGH = 0x03
} Speed;

typedef enum{
    AF0 = 0x0,
    AF1 = 0x1,
    AF2 = 0x2,
    AF3 = 0x3,
    AF4 = 0x4,
    AF5 = 0x5,
    AF6 = 0x6,
    AF7 = 0x7,
    AF8 = 0x8,
    AF9 = 0x9,
    AF10 = 0xA,
    AF11 = 0xB,
    AF12 = 0xC,
    AF13 = 0xD,
    AF14 = 0xE,
    AF15 = 0xF,
} AlternateFunction;

typedef struct
{
    GPIO_TypeDef *GPIOx;
    Pin pin;
    Mode mode;
    Pull pull;
    OutputType type;
    Speed speed;
    AlternateFunction af;
} GPIO_Config;

void GPIO_Rcc(GPIO_TypeDef *GPIOx);
void GPIO_Init(GPIO_Config *Conf);
void GPIO_WritePin(GPIO_TypeDef *GPIOx, Pin pin, State state);
State GPIO_ReadPin(GPIO_TypeDef *GPIOx, Pin pin);
void GPIO_TogglePin(GPIO_TypeDef *GPIOx, Pin pin);
void GPIO_LockPin(GPIO_TypeDef *GPIOx, Pin pin);

#endif
