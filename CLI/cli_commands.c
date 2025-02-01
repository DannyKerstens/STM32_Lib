#include "cli_commands.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Debug/debug.h"


void setGPIO(char *args)
{
    const char *gpioPort = strtok(NULL, " ");
    uint8_t pinnumber = atoi(strtok(NULL, " "));
    uint8_t status = atoi(strtok(NULL, " "));

    /* Arguments Check */
    if (gpioPort == NULL || pinnumber == 0 || status >= 2)
    {
    	LOG_Print("Argument(s) Error");
        return;
    }

    if(gpioPort[0] == 'A' || gpioPort[0] == 'a')
    	HAL_GPIO_WritePin(GPIOA, (1<<pinnumber), status);

    else if(gpioPort[0] == 'B' || gpioPort[0] == 'b')
    	HAL_GPIO_WritePin(GPIOB, (1<<pinnumber), status);

    else if(gpioPort[0] == 'C' || gpioPort[0] == 'c')
    	HAL_GPIO_WritePin(GPIOC, (1<<pinnumber), status);

    else if(gpioPort[0] == 'D' || gpioPort[0] == 'd')
    	HAL_GPIO_WritePin(GPIOD, (1<<pinnumber), status);
}

void getGPIO(char *args)
{
    const char *gpioPort = strtok(NULL, " ");
    uint8_t pinnumber = atoi(strtok(NULL, " "));

    /* Arguments Check */
    if (gpioPort == NULL || pinnumber == 0)
    {
        LOG_Print("Argument(s) Error");
        return;
    }

    if(gpioPort[0] == 'A' || gpioPort[0] == 'a')
    	LOG_Print("PA%d: %d", pinnumber, HAL_GPIO_ReadPin(GPIOA, (1<<pinnumber)));

    else if(gpioPort[0] == 'B' || gpioPort[0] == 'b')
    	LOG_Print("PB%d: %d", pinnumber, HAL_GPIO_ReadPin(GPIOB, (1<<pinnumber)));

    else if(gpioPort[0] == 'C' || gpioPort[0] == 'c')
    	LOG_Print("PC%d: %d", pinnumber, HAL_GPIO_ReadPin(GPIOC, (1<<pinnumber)));

    else if(gpioPort[0] == 'D' || gpioPort[0] == 'd')
    	LOG_Print("PD%d: %d", pinnumber, HAL_GPIO_ReadPin(GPIOD, (1<<pinnumber)));

}

