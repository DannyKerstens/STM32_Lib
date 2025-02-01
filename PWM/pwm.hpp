/*
 *  @file: pwm.hpp
 *
 *  @Date: Jan 25, 2025
 *  @Author: D. Kerstens
 *
 */

#ifndef PWM_PWM_HPP_
#define PWM_PWM_HPP_

class Pwm
{
public:
	typedef enum
	{
		PWM_RESULT_OK = HAL_OK, //0x00
		PWM_RESULT_ERROR = HAL_ERROR,
		PWM_RESULTL_BUSY = HAL_BUSY,
		PWM_RESULT_TIMEOUT = HAL_TIMEOUT,
		PWM_RESULT_ARG_ERROR
	} RESULT_StatusTypeDef;

	Pwm(TIM_HandleTypeDef *timer, uint32_t channel);
	virtual ~Pwm();
	RESULT_StatusTypeDef start();
	void stop();
	RESULT_StatusTypeDef set(uint16_t duty);

	/* Variables */
	uint16_t _dutycycle;

private:
	TIM_HandleTypeDef *_timer;
	uint32_t _channel;
};

#endif /* PWM_PWM_HPP_ */
