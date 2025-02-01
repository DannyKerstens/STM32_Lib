/*
 *  @file: pwm.cpp
 *
 *  @Date: Jan 25, 2025
 *  @Author: D. Kerstens
 *
 */

#include "main.h"
#include "pwm.hpp"


Pwm::Pwm(TIM_HandleTypeDef *timer, uint32_t channel)
{
    assert_param(timer);
    assert_param(channel);

    _timer = timer;
    _channel = channel;
}

Pwm::RESULT_StatusTypeDef Pwm::start()
{
    RESULT_StatusTypeDef result = PWM_RESULT_OK;

    result = (RESULT_StatusTypeDef) HAL_TIM_PWM_Start(_timer, _channel);

    return result;
}

void Pwm::stop()
{
    HAL_TIM_PWM_Stop(_timer, _channel);
}

Pwm::RESULT_StatusTypeDef Pwm::set(uint16_t duty)
{
    RESULT_StatusTypeDef result = PWM_RESULT_OK;

    /* Check if dutycycle is valid. 1000 = 100% */
    if (duty > 1000)
    {
        assert_param(0);
        return PWM_RESULT_ARG_ERROR;
    }

    /* Set the timer dutycycle */
    __HAL_TIM_SET_COMPARE(_timer, _channel, duty * _timer->Init.Period / 1000); //Convert duty to timer compare range
    _dutycycle = duty;

    return result;
}

Pwm::~Pwm()
{
    // TODO Auto-generated destructor stub
}
