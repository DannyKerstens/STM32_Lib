/*
 *  @file: gpio.hpp
 *
 *  @Date: Jan 25, 2025
 *  @Author: D. Kerstens
 *
 */

#ifndef GPIO_GPIO_HPP_
#define GPIO_GPIO_HPP_

class GPIO
{
public:
    GPIO(GPIO_TypeDef *port, uint16_t pin);
    virtual ~GPIO();

    void Toggle();
    GPIO_PinState Read();
    void Write(GPIO_PinState PinState);

private:
    GPIO_TypeDef *_port;
    uint16_t _pin;
};

#endif /* GPIO_GPIO_HPP_ */
