#include "MX1508.h"

MX1508::MX1508(const uint8_t pinA, const uint8_t pinB, const uint8_t freq, const uint8_t ledChannel, const uint8_t resolution):
    pinA(pinA), pinB(pinB), freq(freq), ledChannel(ledChannel), resolution(resolution){
  int limit = 1;
  for(int i = 0; i < resolution; i++){
    limit *= 2;
  }
  min_pwm = 1 - limit;
  max_pwm = limit - 1;
}

void MX1508::init(){
  // configure LED PWM functionalitites
  ledcSetup(ledChannel, freq, resolution);
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(pinA, ledChannel);
  pinMode(pinB, OUTPUT);
}

void MX1508::setDutyCycle(int duty_cycle){
  if(duty_cycle > 0){
    duty_cycle = duty_cycle > max_pwm ? max_pwm : duty_cycle;
    digitalWrite(pinB, LOW);
    ledcWrite(ledChannel, duty_cycle);
  }else{
    duty_cycle = duty_cycle < min_pwm ? min_pwm : duty_cycle;
    duty_cycle += max_pwm; //  offset to positive integers
    digitalWrite(pinB, HIGH);
    ledcWrite(ledChannel, duty_cycle);
  }
}

int MX1508::getMaxPwm(){
  return max_pwm;
}

int MX1508::getMinPwm(){
  return min_pwm;
}
