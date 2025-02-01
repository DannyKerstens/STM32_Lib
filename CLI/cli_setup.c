
#include "cli_setup.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// STM files
#include "stm32F3xx_hal.h"
#include "stm32F3xx_it.h"


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

