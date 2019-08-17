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
    const uint8_t pinA; // GPIO pin with output
    const uint8_t pinB; // GPIO pin with output
    const uint8_t freq;  // range at least 100-5000 Hz
    const uint8_t ledChannel; // 16 channels: 0-15, but every even channels shares its freq with the one before, thus 0&1, 2&3...
    const uint8_t resolution; // 1-16 bits
    int max_pwm;
    int min_pwm;
};

#endif
