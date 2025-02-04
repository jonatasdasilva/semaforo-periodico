#include "leds.h"

void init_led()
{
    // function init: initializate GPIOs: 11, 12 e 13.
    gpio_init(PIN_RED);
    gpio_init(PIN_BLUE);
    gpio_init(PIN_GREEN);
    // function define GPIOs: 11, 12 and 13 for out.
    gpio_set_dir(PIN_RED, GPIO_OUT);
    gpio_set_dir(PIN_BLUE, GPIO_OUT);
    gpio_set_dir(PIN_GREEN, GPIO_OUT);
}

// Função que liga o led no PIO (pino) indicado
void led_on(uint8_t pin)
{
    gpio_put(pin, true);
}

// Função que desliga o led no PIO (pino) indicado
void led_off(uint8_t pin)
{
    gpio_put(pin, false);
}