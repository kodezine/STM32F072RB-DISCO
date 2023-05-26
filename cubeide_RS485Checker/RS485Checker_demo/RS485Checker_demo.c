/*
 * RS485Checker_demo.c
 *
 *  Created on: May 26, 2023
 *      Author: sohal
 */

#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#include "RS485Checker_demo.h"
#include "main.h"
#define UART_DMA_RX_BUFFER_SIZE 128
static uint8_t UART_DMA_RxBuffer[UART_DMA_RX_BUFFER_SIZE];
static uint8_t RxMainBuffer[UART_DMA_RX_BUFFER_SIZE * 2];
static volatile uint16_t RxBufferCopied = 0;

extern UART_HandleTypeDef huart3;
extern DMA_HandleTypeDef hdma_usart3_rx;


void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
	if(huart->Instance == USART3)
	{
		memcpy(RxMainBuffer, UART_DMA_RxBuffer, Size);
		HAL_UARTEx_ReceiveToIdle_DMA(&huart3, UART_DMA_RxBuffer, UART_DMA_RX_BUFFER_SIZE);
		__HAL_DMA_DISABLE_IT(&hdma_usart3_rx, DMA_IT_HT);
		RxBufferCopied = Size;
	}
}

void app_main(void)
{
	HAL_UARTEx_ReceiveToIdle_DMA(&huart3, UART_DMA_RxBuffer, UART_DMA_RX_BUFFER_SIZE);
	__HAL_DMA_DISABLE_IT(&hdma_usart3_rx, DMA_IT_HT);
	do
	{
		if(RxBufferCopied)
		{
			RxBufferCopied = 0;
		}
	}while(true);
}
