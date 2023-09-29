#define __VIRTUAL_MODULE

// Pin Info: 0 - D; 1 - A; 2 - PWM; 3 - SPECIAL (I2C, SPI, UART, ...)

void digitalWrite(int pin, short value) {
  __JS_Arduino_pins_write__(pin, value);
}

void analogWrite(int pin, short pwm) {
  if (__JS_Arduino_pins_info__(pin) == 2) {
    __JS_Arduino_pins_write__(pin, pwm);
  } else {
    __JS_Console_error__("Error! Pin $$1$$ is not PWM!", pin);
  }
}

short digitalRead(int pin) {
  return __JS_Arduino_pins_read__(pin);
}

short analogRead(int pin) {
  if (__JS_Arduino_pins_info__(pin) == 0) {
    return __JS_Arduino_pins_read__(pin);
  } else {
    __JS_Console_error__("Error! Pin $$1$$ is not analog pin!", pin);
    return 0;
  }
}
