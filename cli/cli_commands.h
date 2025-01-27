#ifndef INC_CLI_BINDING_H_
#define INC_CLI_BINDING_H_

#include "cli_setup.h"

/* CLI Command Structure */
typedef struct{
    const char *pCmd;
    const char *pHelp;
    void (*pFun)(int argc, char *argv[]);
} COMMAND_S;


void setInput(int argc, char *argv[]);

void setOutput(int argc, char *argv[]);

void setGPIO(int argc, char *argv[]);
void toggleGPIO(int argc, char *argv[]);
void getGPIO(int argc, char *argv[]);

void sendUart(int argc, char *argv[]);

void testSDCard(int argc, char *argv[]);

void repeatStop(int argc, char *argv[]);
void repeatSetup(int argc, char *argv[]);

void help(int argc, char *argv[]);


static const COMMAND_S CLI_COMMANDS[] =
{
  { "set-gpio", "set-gpio <PORT> <PIN> <STATUS>\r\n", setGPIO },
  { "toggle-gpio", "toggle-gpio <PORT> <PIN>\r\n", toggleGPIO },
  { "get-gpio", "get-gpio <PORT> <PIN>\r\n", getGPIO },
  { "set-output", "set-output <PORT> <PIN>\r\n", setOutput },
  { "set-input", "set-input <PORT> <PIN>\r\n", setInput },
  { "uart", "uart <PORT> <DATA>\r\n", sendUart },
  { "test-sd", "test-sd\r\n", testSDCard },
  { "repeat", "repeat <interval> <command>\r\n", repeatSetup },
  { "stop", "stop\r\n", repeatStop },
  { "help", "help\r\n", help}
};

#endif /* INC_CLI_BINDING_H_ */
