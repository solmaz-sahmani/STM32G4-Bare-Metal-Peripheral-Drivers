#include "uart.h"

#define GPIOAEN 	(1U << 0)
#define UART2EN		(1U << 17)

#define SYS_FREQ	170000000 //depends on RCC in reference manual
#define APB1_CLK	85000000 //prescalor is 2 -> 170/2

#define CR1_TE		(1U << 3)
#define CR1_UE		(1U << 0)
#define ISR_TXE		(1U << 7)

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t Baudrate);
static uint16_t compute_uart_div(uint32_t PeriphClk, uint32_t Baudrate);

void uart2_tx_init(void)
{
	/*configure the UART pin*/
	/*Enable clock access to GPIOC for PA2 as TX line*/
	RCC->AHB2ENR |= GPIOAEN;

	/*set PA2 mode as alternate function mode*/
	GPIOA->MODER &= ~(0x3 << 4); //clear pin
	GPIOA->MODER |= (0x2 << 4);

	/*set the alternate function typed to UART*/
	GPIOA->AFR[0] &= ~(0xF << 8); //clear pin
	GPIOA->AFR[0] |= (0x7 << 8);  //set AF7

	/*configure the UART module*/
	/*Enable clock access to UART4*/
	RCC->APB1ENR1 |= UART2EN;

	/*Configure Baudrate*/
	uart_set_baudrate(USART2 , APB1_CLK, 115200);

	/*Enable transfer direction*/
	USART2->CR1 = CR1_TE;

	/*Enable UART module*/
	USART2->CR1 |= CR1_UE;
}

static void uart_write(int ch)
{
	/*Make sure transmit data register is empty*/
	while(!(USART2->ISR & ISR_TXE)){}

	/*Write to transmit data register*/
	USART2->TDR = (ch & 0xFF);
}

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t Baudrate)
{
	USARTx->BRR = compute_uart_div(PeriphClk, Baudrate);
}

static uint16_t compute_uart_div(uint32_t PeriphClk, uint32_t Baudrate)
{
	return ((PeriphClk + (Baudrate/2))/Baudrate);
}
