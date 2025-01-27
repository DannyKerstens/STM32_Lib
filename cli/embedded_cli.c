#include "embedded_cli.h"
#include "cli_commands.h"
#include "cli_setup.h"
#include "debug/debug.h"

bool repeat = false;
COMMAND_S repeatCommand;
char *repeatArgs[MAX_ARGS];
int repeatInterval = 1000;

static char UART_CLI_rxBuffer[128];
bool cliReady = false;
uint8_t rxBufferIndex = 0;


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
    uint8_t argc = 0;
    char *argv[MAX_ARGS];
    char *command = strtok(UART_CLI_rxBuffer, " ");

    // Extract all arguments and add them to argv
    char *token = strtok(NULL, " ");
    while(token != NULL)
    {
      if(argc >= MAX_ARGS)
      {
        LOG_Print("Maximum number of arguments exceeded. Rest is ignored.\r\n");
        break;
      }
      argv[argc] = token;
      argc++;
      token = strtok(NULL, " ");
    }

    /* Find received command in command list */
    for (int i = 0; i < sizeof(CLI_COMMANDS)/sizeof(COMMAND_S); ++i)
    {
      if(strcmp(CLI_COMMANDS[i].pCmd, command) == 0)
      {
        CLI_COMMANDS[i].pFun(argc, argv);
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

void cliRepeatHandler(void)
{
  static int prescaler = 0;

  if(repeat && ((repeatInterval/100) <= prescaler))
  {
    repeatCommand.pFun(3, repeatArgs);
    prescaler=0;
  }
  prescaler++;
}
