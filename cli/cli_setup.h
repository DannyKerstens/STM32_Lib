#ifndef INC_CLI_SETUP_H_
#define INC_CLI_SETUP_H_

#include "embedded_cli.h"
#include "cli_commands.h"
#include "stm32H5xx_hal.h"
#include "stm32H5xx_it.h"

#define MAX_ARGS 8

/**
 * Char for char is needed for instant char echo, so size 1
 */
#define UART_RX_BUFF_SIZE 1

void cliInit(UART_HandleTypeDef* huart);

#endif /* INC_CLI_SETUP_H_ */
