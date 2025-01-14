#include "pico/stlib.h"

#define LED_PIN 11
#define BTN_PIN 5

int main() {
	gpio_init(LED_PIN);
	gpio_set_dir(LED_PIN, GPIO_OUT);
	gpio_init(BTN_PIN);
	gpio_set_dir(BTN_PIN, GPIO_OUT);
	while (1) {
		while (gpio_get(BTN_PIN)) {
			gpio_put(LED_PIN, 1);
		}
		gpio_put(LED_PIN, 0);
	}
}
