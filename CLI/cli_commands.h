#ifndef INC_CLI_BINDING_H_
#define INC_CLI_BINDING_H_

/* CLI Command Structure */
typedef struct {
    const char *pCmd;
    const char *pHelp;
    void (*pFun)(char *);
} COMMAND_S;


/**
 * Example callback function, that also parses 2 arguments,
 * and has an 'incorrect usage' output.
 */
void setGPIO(char *args);

void getGPIO(char *args);


#endif /* INC_CLI_BINDING_H_ */
