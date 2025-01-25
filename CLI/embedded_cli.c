#include "embedded_cli.h"
#include "cli_setup.h"
#include "debug.h"

static char UART_CLI_rxBuffer[128];
bool cliReady = false;
uint8_t rxBufferIndex = 0;

const COMMAND_S CLI_COMMANDS[] =
{
	{ "set-gpio", "set-gpio <PORT> <PIN> <STATUS>\r\n", setGPIO },
	{ "get-gpio", "get-gpio <PORT> <PIN>\r\n", getGPIO }
};

void cliReceiveHandler(char c)
{
	if(((c == '\r') || (c == '\n')) && !cliReady)
	{
		UART_CLI_rxBuffer[rxBufferIndex] = ' ';
		cliReady = true;
	}
	else if(!cliReady)
	{
		UART_CLI_rxBuffer[rxBufferIndex] = c;
		rxBufferIndex++;
	}
}

void cliProcess()
{
	if(cliReady)
	{
		char *command = strtok(UART_CLI_rxBuffer, " ");

		for (int i = 0; i < sizeof(CLI_COMMANDS)/sizeof(COMMAND_S); ++i)
		{
			if(strcmp(CLI_COMMANDS[i].pCmd, command) == 0)
			{
				CLI_COMMANDS[i].pFun(UART_CLI_rxBuffer);
				cliReady = false;
				rxBufferIndex = 0;
				return;
			}
		}

		/* Command doesn't exist */
		LOG_Print("Command %s doesn't exist\r\n", command);
		cliReady = false;
		rxBufferIndex = 0;
		return;
	}
}
