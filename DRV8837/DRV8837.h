#ifndef _DRV8837_H_
#define _DRV8837_H_

#include "../GPIO_PORT/GPIO_PORT.h"
#ifdef ARDUINO
#include <Arduino.h>
#endif

/* DRV883x control pin config */
#define PIN_M1_A 3
#define PIN_M1_B 4
#define PIN_M2_A 1
#define PIN_M2_B 0

/* Motor direction reverse set */
#define REVERSE_M1 0
#define REVERSE_M2 0
 
/* DRV883x driver class */
class DRV8837 : public GPIO_PORT {
    private:
        void _update_M1_duty(uint8_t M1_A_duty, uint8_t M1_B_duty);
        void _update_M2_duty(uint8_t M2_A_duty, uint8_t M2_B_duty);
    public:
        enum MOTOR {
            M1 = 0,
            M2,
        };
        void begin();
        void coast(MOTOR motor);
        void forward(MOTOR motor, uint8_t speed);
        void backward(MOTOR motor, uint8_t speed);
        void brake(MOTOR motor);
};

#endif