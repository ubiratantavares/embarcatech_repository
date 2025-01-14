/**
* Embarcatech 
* Exemplo Blink com a BitDogLab
*/

#include "pico/stdlib.h"

int main() {
    // Define o pino do LED e o configura como saída
    const uint LED_PIN = 12;  // Substitua com o número do GPIO desejado
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        // Liga o LED
        gpio_put(LED_PIN, true);
        sleep_ms(250);  // Espera 250ms

        // Desliga o LED
        gpio_put(LED_PIN, false);
        sleep_ms(250);  // Espera 250ms
    }
}
