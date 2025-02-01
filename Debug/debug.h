/*
 *  @file: debug.h
 *
 *  @Date: Jan 25, 2025
 *  @Author: D. Kerstens
 *
 */

#ifndef INC_DEBUG_H_
#define INC_DEBUG_H_

#include "stdint.h"
#include "time.h"
#include "stm32F3xx_hal.h"

void LOG_Print(const char *text, ...);
void LOG_Info(const char *text, ...);
void LOG_Warning(const char *text, ...);
void LOG_Error(const char *text, ...);
void LOG_Header(const char *str);
const char* DEBUG_GetTimestampStr(const time_t time);

#endif /* INC_DEBUG_H_ */
