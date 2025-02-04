#include <stdio.h>
#include "libs/leds.h"
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definitions of the: functions, variables and constants
#define DELAY 1000
// Variables
uint8_t bitdoglab = 0;
uint8_t traffic_signal_state = 0; // 0: vermelho, 1: amarelo, 2: verde
volatile absolute_time_t next_time;

// functions
bool traffic_light_callback(struct repeating_timer *t);


int main() {
    // Hardware and Software incialization
    init_led();
    stdio_init_all();

    // initial state of LED
    led_on(PIN_RED);
    next_time = make_timeout_time_ms(3000);
    // Configura o timer periódico
    struct repeating_timer traffic_light_timer;
    add_repeating_timer_ms(3000, traffic_light_callback, NULL, &traffic_light_timer);

    // Tasks to be performed by the microcontroller during its operation
    while (true) {
        sleep_ms(DELAY);
        printf("Intervalor de 1000ms alcançado!\n");
    }
}

// function callback for periodic timer
bool traffic_light_callback(struct repeating_timer *t) {
    uint32_t now = to_us_since_boot(get_absolute_time()); // set actual time
    // checks if the current time is greater than the time set for the change
    if (absolute_time_diff_us(now, to_ms_since_boot(next_time)) < 0) {
        // Turn off the current led
        if (traffic_signal_state == 0) {
            led_off(PIN_RED);// Turn off LED RED
            next_time = make_timeout_time_ms(3000);
        } else if (traffic_signal_state == 1) {
            if (bitdoglab) {
                // combinate colors for LED RGB
                led_off(PIN_RED);// Turn off LED RED
                led_off(PIN_GREEN);// Turn off LED GREEN
            } else {
                led_off(PIN_YELLOW);// Turn off LED YELLOW
            }
            next_time = make_timeout_time_ms(3000);
        } else {
            led_off(PIN_GREEN);// Turn off LED GREEN
            next_time = make_timeout_time_ms(3000);
        }

        // Avança para o próximo estado
        traffic_signal_state = (traffic_signal_state + 1) % 3;

        // Acende o próximo LED
        if (traffic_signal_state == 0) {
            led_on(PIN_RED); // Turn on the LED RED
            next_time = make_timeout_time_ms(3000); // sets 3 seconds time for next change
         } else if (traffic_signal_state == 1) {
            if (bitdoglab) {
                // combinate colors for LED RGB
                led_on(PIN_RED);// Turn on the LED RED
                led_on(PIN_GREEN);// Turn on the LED GREEN
            } else {
                led_on(PIN_YELLOW);// Turn on the LED YELLOW
            }
            next_time = make_timeout_time_ms(3000);
         } else {
            led_on(PIN_GREEN);  // Turn on the LED YELLOW
            next_time = make_timeout_time_ms(3000);
         }
    }
     return true;
}