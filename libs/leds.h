#ifndef LEDS_H
#define LEDS_H

#include "pico/stdlib.h"

#define PIN_RED 13
#define PIN_BLUE 12
#define PIN_GREEN 11
#define PIN_YELLOW 12

// Function inicializate LED RGB (green, blue and red) or 3 LEDs conected in GPIOs: 11, 12, 13
void init_led();
void led_on(uint8_t pin);
void led_off(uint8_t pin);

#endif