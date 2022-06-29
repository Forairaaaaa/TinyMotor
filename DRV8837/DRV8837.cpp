#include "DRV8837.h"

/**
 * @brief Motor init
 * 
 */
void DRV8837::begin() {
    /* PWM init */
    _GPIO_PWM_init(PIN_M1_A, 1);
    _GPIO_PWM_init(PIN_M1_B, 2);
    _GPIO_PWM_init(PIN_M2_A, 3);
    _GPIO_PWM_init(PIN_M2_B, 4);
}

/**
 * @brief Motor coast
 * 
 * @param motor M1 & M2
 */
void DRV8837::coast(MOTOR motor) {
    if (motor == M1)
        _update_M1_duty(0, 0);
    else
        _update_M2_duty(0, 0);
}

/**
 * @brief Motor forward
 * 
 * @param motor M1 & M2
 * @param speed 0~255
 */
void DRV8837::forward(MOTOR motor, uint8_t speed) {
    if (motor == M1)
        #if REVERSE_M1
        _update_M1_duty(0, speed);
        #else
        _update_M1_duty(speed, 0);
        #endif
    else
        #if REVERSE_M2
        _update_M2_duty(0, speed);
        #else
        _update_M2_duty(speed, 0);
        #endif
}

/**
 * @brief Motor backward
 * 
 * @param motor M1 & M2
 * @param speed 0~255
 */
void DRV8837::backward(MOTOR motor, uint8_t speed) {
    if (motor == M1)
        #if REVERSE_M1
        _update_M1_duty(speed, 0);
        #else
        _update_M1_duty(0, speed);
        #endif
    else
        #if REVERSE_M2
        _update_M2_duty(speed, 0);
        #else
        _update_M2_duty(0, speed);
        #endif
}

/**
 * @brief Motor brake
 * 
 * @param motor M1 & M2
 */
void DRV8837::brake(MOTOR motor) {
    if (motor == M1)
        _update_M1_duty(255, 255);
    else
        _update_M2_duty(255, 255);
}


/* Private functions */
/**
 * @brief Update motor duty
 * 
 * @param M1_A_duty 
 * @param M1_B_duty 
 */
void DRV8837::_update_M1_duty(uint8_t M1_A_duty, uint8_t M1_B_duty) {
    _GPIO_PWM_setDuty(1, M1_A_duty);
    _GPIO_PWM_setDuty(2, M1_B_duty);
}

void DRV8837::_update_M2_duty(uint8_t M2_A_duty, uint8_t M2_B_duty) {
    _GPIO_PWM_setDuty(3, M2_A_duty);
    _GPIO_PWM_setDuty(4, M2_B_duty);
}