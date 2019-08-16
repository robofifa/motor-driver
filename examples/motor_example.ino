#include <MX1508.h>

// the numbers of the motor pins
const int M1A = 16;  // 16 corresponds to GPIO16
const int M1B = 17;  // 16 corresponds to GPIO16

// setting PWM properties
const int freq = 100; // range at least 100-5000 Hz
const int ledChannel = 0; // 16 channels: 0-15, but every even channels shares its freq with the one before, thus 1&2, 3&4...
const int resolution = 8; // 1-16 bits
const int max_power = 100;
const int min_power = -100;
MX1508 M1(M1A, M1B, freq, ledChannel, resolution);

void setup() {
  Serial.begin(115200);
  M1.init();
  Serial.print("min and max are: ");
  Serial.print(M1.getMaxPwm());
  Serial.print(", ");
  Serial.println(M1.getMinPwm());
}

void loop() {
  for (int dutyCycle = min_power; dutyCycle <= max_power; dutyCycle++) {
    // changing the  PWM
    M1.setDutyCycle(dutyCycle);
    delay(15);
  }

  for (int dutyCycle = max_power; dutyCycle >= min_power; dutyCycle--) {
    // changing the PWM
    M1.setDutyCycle(dutyCycle);
    delay(15);
  }
}
