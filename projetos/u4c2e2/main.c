#include "pico/stdlib.h"

// pinos dos componentes
#define BOTAO_A 5
#define BOTAO_B 6
#define LED_VERMELHO 12
#define LED_VERDE 13
#define LED_AZUL 11
#define TEMPO_ATRASO 100

void inicializar_led(const int led) {
	gpio_init(led);
	gpio_set_dir(led, GPIO_OUT);
}

void inicializar_botao(const int botao) {
	gpio_init(botao);
	gpio_set_dir(botao, GPIO_IN);
	gpio_pull_down(botao);	
}

int esta_pressionado(const int botao) {
	return gpio_get(botao);
}

void acender_led(const int led) {
	gpio_put(led, 1);	
}

void apagar_led(const int led) {
	gpio_put(led, 0);
}

int main() {
	// inicializa os LEDs
	inicializar_led(LED_VERMELHO);
	inicializar_led(LED_VERDE);	
	inicializar_led(LED_AZUL);
	
	// inicializa os botões
	inicializar_botao(BOTAO_A);
	inicializar_botao(BOTAO_B);

	// loop infinito
	while (true) {
		if ((esta_pressionado(BOTAO_A)) && (esta_pressionado(BOTAO_B))) { // verifica se os botoes A e B estão pressionados
 			acender_led(LED_VERMELHO); 
			apagar_led(LED_VERDE);
			apagar_led(LED_AZUL);
		} else if (esta_pressionado(BOTAO_A)) { // verifica se os botao A está pressionado
			apagar_led(LED_VERMELHO);
			apagar_led(LED_VERDE);
			acender_led(LED_AZUL);
		} else if (esta_pressionado(BOTAO_B)) { // verifica se o botao B está pressionado
			apagar_led(LED_VERMELHO);
			acender_led(LED_VERDE);
			apagar_led(LED_AZUL);
		} else { 
			apagar_led(LED_VERMELHO);
			apagar_led(LED_VERDE);
			apagar_led(LED_AZUL);
		}
		sleep_ms(TEMPO_ATRASO);
	}
}
