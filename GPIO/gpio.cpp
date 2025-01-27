/*
 *  @file: gpio.cpp
 *
 *  @Date: Jan 25, 2025
 *  @Author: D. Kerstens
 *
 */

#include "main.h"
#include "gpio.hpp"


GPIO::GPIO(GPIO_TypeDef *port, uint16_t pin)
{
    assert_param(port);
    assert_param(pin);

    _port = port;
    _pin = pin;
}

void GPIO::Toggle()
{
    HAL_GPIO_TogglePin(_port, _pin);
}

GPIO_PinState GPIO::Read()
{
    return HAL_GPIO_ReadPin(_port, _pin);
}

void GPIO::Write(GPIO_PinState PinState)
{
    HAL_GPIO_WritePin(_port, _pin, PinState);
}

