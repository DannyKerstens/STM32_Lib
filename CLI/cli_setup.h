/*
 * cli_setup.h
 *
 *  Created on: Jul 7, 2023
 *      Author: NeusAap
 */

#ifndef INC_CLI_SETUP_H_
#define INC_CLI_SETUP_H_

#include "stm32F3xx_hal.h"

#include "cli_commands.h"
#include "embedded_cli.h"

extern UART_HandleTypeDef huart1;

/**
 * Char for char is needed for instant char echo, so size 1
 */
#define UART_RX_BUFF_SIZE 1

void cliInit(void);

#endif /* INC_CLI_SETUP_H_ */
