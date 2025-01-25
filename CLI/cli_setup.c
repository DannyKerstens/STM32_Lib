// STD LIBS
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// STM files
//#include "usart.h"
#include "stm32F1xx_hal.h"
#include "stm32F1xx_it.h"

// Own CLI headers
#include "cli_setup.h"


// UART buffers
static uint8_t UART_CLI_rxBuffer[UART_RX_BUFF_SIZE] = {0};

void cliInit(void)
{
	HAL_UART_Receive_IT(&huart1, UART_CLI_rxBuffer, UART_RX_BUFF_SIZE);
}

// STM32 UART callback function, to pass received characters to the embedded-cli
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart == &huart1)
    {
        HAL_UART_Receive_IT(&huart1, UART_CLI_rxBuffer, UART_RX_BUFF_SIZE);
        char c = UART_CLI_rxBuffer[0];
        cliReceiveHandler(c);
    }
}

