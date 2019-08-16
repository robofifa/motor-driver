#ifndef MX1508_h
#define MX1508_h

#include "Arduino.h"

class MX1508 {
  public:
    MX1508(const uint8_t pinA, const uint8_t pinB, const uint8_t freq, const uint8_t ledChannel, const uint8_t resolution);
    void init();
    void setDutyCycle(int pwmVal);
    int getMaxPwm();
    int getMinPwm();
  private:
    const uint8_t pinA;
    const uint8_t pinB;
    const uint8_t freq;
    const uint8_t ledChannel;
    const uint8_t resolution;
    int max_pwm;
    int min_pwm;
};

#endif
