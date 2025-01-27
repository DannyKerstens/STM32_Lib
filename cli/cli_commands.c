#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cli_commands.h"
#include "debug/debug.h"
#include "app_filex.h"

extern UART_HandleTypeDef huart7;

extern bool repeat;
extern COMMAND_S repeatCommand;
extern char *repeatArgs[];
extern int repeatInterval;

void setInput(int argc, char *argv[])
{
  const char *gpioPort = argv[0];
  uint8_t pinnumber = atoi(argv[1]);

  /* Arguments Check */
  if (gpioPort == NULL || pinnumber <= 0 || pinnumber >= 16)
  {
    LOG_Print("Argument(s) Error");
      return;
  }

  if(gpioPort[0] == 'A' || gpioPort[0] == 'a')
    GPIOA->MODER &= ~(0b11 << (2 * pinnumber));

  else if(gpioPort[0] == 'B' || gpioPort[0] == 'b')
    GPIOB->MODER &= ~(0b11 << (2 * pinnumber));

  else if(gpioPort[0] == 'C' || gpioPort[0] == 'c')
    GPIOC->MODER &= ~(0b11 << (2 * pinnumber));

  else if(gpioPort[0] == 'D' || gpioPort[0] == 'd')
    GPIOD->MODER &= ~(0b11 << (2 * pinnumber));

  else if(gpioPort[0] == 'E' || gpioPort[0] == 'e')
    GPIOE->MODER &= ~(0b11 << (2 * pinnumber));

  else if(gpioPort[0] == 'F' || gpioPort[0] == 'f')
    GPIOF->MODER &= ~(0b11 << (2 * pinnumber));

  else if(gpioPort[0] == 'H' || gpioPort[0] == 'h')
    GPIOH->MODER &= ~(0b11 << (2 * pinnumber));

  else if(gpioPort[0] == 'I' || gpioPort[0] == 'i')
    GPIOI->MODER &= ~(0b11 << (2 * pinnumber));

  else
    LOG_Print("Port %c does not exist", gpioPort[0]);
}

void setOutput(int argc, char *argv[])
{
  const char *gpioPort = argv[0];
  uint8_t pinnumber = atoi(argv[1]);

  /* Arguments Check */
  if (gpioPort == NULL || pinnumber <= 0 || pinnumber >= 16)
  {
    LOG_Print("Argument(s) Error");
      return;
  }

  if(gpioPort[0] == 'A' || gpioPort[0] == 'a')
    GPIOA->MODER |= (0b01 << (2 * pinnumber));

  else if(gpioPort[0] == 'B' || gpioPort[0] == 'b')
    GPIOB->MODER |= (0b01 << (2 * pinnumber));

  else if(gpioPort[0] == 'C' || gpioPort[0] == 'c')
    GPIOC->MODER |= (0b01 << (2 * pinnumber));

  else if(gpioPort[0] == 'D' || gpioPort[0] == 'd')
    GPIOD->MODER |= (0b01 << (2 * pinnumber));

  else if(gpioPort[0] == 'E' || gpioPort[0] == 'e')
    GPIOE->MODER |= (0b01 << (2 * pinnumber));

  else if(gpioPort[0] == 'F' || gpioPort[0] == 'f')
    GPIOF->MODER |= (0b01 << (2 * pinnumber));

  else if(gpioPort[0] == 'H' || gpioPort[0] == 'h')
    GPIOH->MODER |= (0b01 << (2 * pinnumber));

  else if(gpioPort[0] == 'I' || gpioPort[0] == 'i')
    GPIOI->MODER |= (0b01 << (2 * pinnumber));

  else
    LOG_Print("Port %c does not exist", gpioPort[0]);
}

void setGPIO(int argc, char *argv[])
{
    const char *gpioPort = argv[0];
    uint8_t pinnumber = atoi(argv[1]);
    uint8_t status = atoi(argv[2]);

    /* Arguments Check */
    if (gpioPort == NULL || pinnumber <= 0 || pinnumber >= 16 || status >= 2)
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

    else if(gpioPort[0] == 'E' || gpioPort[0] == 'e')
      HAL_GPIO_WritePin(GPIOE, (1<<pinnumber), status);

    else if(gpioPort[0] == 'F' || gpioPort[0] == 'f')
      HAL_GPIO_WritePin(GPIOF, (1<<pinnumber), status);

    else if(gpioPort[0] == 'H' || gpioPort[0] == 'h')
      HAL_GPIO_WritePin(GPIOH, (1<<pinnumber), status);

    else if(gpioPort[0] == 'I' || gpioPort[0] == 'i')
      HAL_GPIO_WritePin(GPIOI, (1<<pinnumber), status);

    else
      LOG_Print("Port %c does not exist", gpioPort[0]);
}

void toggleGPIO(int argc, char *argv[])
{
    const char *gpioPort = argv[0];
    uint8_t pinnumber = atoi(argv[1]);

    /* Arguments Check */
    if (gpioPort == NULL || pinnumber <= 0 || pinnumber >= 16)
    {
      LOG_Print("Argument(s) Error");
        return;
    }

    if(gpioPort[0] == 'A' || gpioPort[0] == 'a')
      HAL_GPIO_TogglePin(GPIOA, (1<<pinnumber));

    else if(gpioPort[0] == 'B' || gpioPort[0] == 'b')
      HAL_GPIO_TogglePin(GPIOB, (1<<pinnumber));

    else if(gpioPort[0] == 'C' || gpioPort[0] == 'c')
      HAL_GPIO_TogglePin(GPIOC, (1<<pinnumber));

    else if(gpioPort[0] == 'D' || gpioPort[0] == 'd')
      HAL_GPIO_TogglePin(GPIOD, (1<<pinnumber));

    else if(gpioPort[0] == 'E' || gpioPort[0] == 'e')
      HAL_GPIO_TogglePin(GPIOE, (1<<pinnumber));

    else if(gpioPort[0] == 'F' || gpioPort[0] == 'f')
      HAL_GPIO_TogglePin(GPIOF, (1<<pinnumber));

    else if(gpioPort[0] == 'H' || gpioPort[0] == 'h')
      HAL_GPIO_TogglePin(GPIOH, (1<<pinnumber));

    else if(gpioPort[0] == 'I' || gpioPort[0] == 'i')
      HAL_GPIO_TogglePin(GPIOI, (1<<pinnumber));

    else
      LOG_Print("Port %c does not exist", gpioPort[0]);
}

void getGPIO(int argc, char *argv[])
{
  const char *gpioPort = argv[0];
  uint8_t pinnumber = atoi(argv[1]);

  /* Arguments Check */
  if (gpioPort == NULL || pinnumber <= 0 || pinnumber >= 16)
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

  else if(gpioPort[0] == 'E' || gpioPort[0] == 'e')
    LOG_Print("PE%d: %d", pinnumber, HAL_GPIO_ReadPin(GPIOE, (1<<pinnumber)));

  else if(gpioPort[0] == 'F' || gpioPort[0] == 'f')
    LOG_Print("PF%d: %d", pinnumber, HAL_GPIO_ReadPin(GPIOF, (1<<pinnumber)));

  else if(gpioPort[0] == 'H' || gpioPort[0] == 'h')
    LOG_Print("PH%d: %d", pinnumber, HAL_GPIO_ReadPin(GPIOH, (1<<pinnumber)));

  else if(gpioPort[0] == 'i' || gpioPort[0] == 'i')
    LOG_Print("PI%d: %d", pinnumber, HAL_GPIO_ReadPin(GPIOI, (1<<pinnumber)));

  else
    LOG_Print("Port %c does not exist", gpioPort[0]);
}

void sendUart(int argc, char *argv[])
{
  uint8_t uartNumber = atoi(argv[0]);
  const char *data = argv[1];

  /* Arguments Check */
  if (data == NULL || uartNumber <= 0)
  {
      LOG_Print("Argument(s) Error");
      return;
  }

  if(uartNumber == 7)
    HAL_UART_Transmit(&huart7, (uint8_t*) data, strlen(data), 1000);
}

void testSDCard(int argc, char *argv[])
{
  int8_t result = SD_TEST();

  if(result < 0)
    LOG_Print("SD Card test: error");
  else
    LOG_Print("SD Card test: OK");
}

void repeatStop(int argc, char *argv[])
{
  repeat = false;

  // Clear repeat command arguments
  for (int i = 0; i < MAX_ARGS; ++i)
    repeatArgs[i] = NULL;
}

void repeatSetup(int argc, char *argv[])
{
  repeat = true;

  repeatInterval = strtol(argv[0], NULL, 10);
  char *command = argv[1];


  for(uint8_t i=0; i < (argc-2); i++)
    repeatArgs[i] = argv[i+2];


  /* Find received command in command list */
  for (int i = 0; i < sizeof(CLI_COMMANDS)/sizeof(COMMAND_S); ++i)
  {
    if(strcmp(CLI_COMMANDS[i].pCmd, command) == 0)
    {
      repeatCommand = CLI_COMMANDS[i];
      break;
    }
  }
}

void help(int argc, char *argv[])
{
  for (int i = 0; i < sizeof(CLI_COMMANDS)/sizeof(COMMAND_S); ++i)
  {
    LOG_Print("- %s",CLI_COMMANDS[i].pHelp);
  }
}
