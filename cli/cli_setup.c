// STD LIBS
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// Own CLI headers
#include "cli_setup.h"

static UART_HandleTypeDef* cliHandle;

// UART buffers
static uint8_t UART_CLI_rxCharBuffer[UART_RX_BUFF_SIZE] = {0};

void cliInit(UART_HandleTypeDef* huart)
{
  cliHandle = huart;
  HAL_UART_Receive_IT(cliHandle, UART_CLI_rxCharBuffer, UART_RX_BUFF_SIZE);
}

// STM32 UART callback function, to pass received characters to the embedded-cli
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart == cliHandle)
    {
        HAL_UART_Receive_IT(cliHandle, UART_CLI_rxCharBuffer, UART_RX_BUFF_SIZE);
        char c = UART_CLI_rxCharBuffer[0];
        cliReceiveHandler(c);
    }
}
