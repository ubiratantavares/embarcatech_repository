# Capitulo 7 - Modulação por Largura de Pulso (PWM)

## Objetivos

* Entender o processo de modulação por largura de pulso e seu funcionamento.
* Configurar e utilizar os diferentes modos de configuração do módulo PWM.
* Aplicar o módulo PWM para controle de intensidade luminosa do LED.

## Revisão

* Nas últimas aulas foi aprendido:

	- Utilizar os pinos de entrada e saída.
	- Configurar o clock e temporizadores.
	- Utilizar as interrupções para tratar eventos dos periféricos.

## Visão Geral - Pulse Width Modulation (PWM)

* Técnica para controlar a potência entregue a dispositivos eletrônicos.
* Permite variar a largura de pulso mantendo uma frequêncioa constante: período e Duty Cycle.

![Figura 1](https://github.com/ubiratantavares/embarcatech_repository/blob/main/unidade4/capitulo7/figura1.png)

* Aplicações do PWM

	- Controle do brilho de LEDs.
	- Geração de sinais de áudio.
	- Controle da velocidade de motores.
	- Controle de conversores de potência.

* Vantagens do PWM

	- Fácil de implementar em microcontroladores.
	- Precisão no controle.

![Figura 2](https://github.com/ubiratantavares/embarcatech_repository/blob/main/unidade4/capitulo7/figura2.png)

## PWM no RP2040

* Bloco de PWM

	- 8 slices idênticos: cada um gera dois sinais de PWM

		- saída: PWM
		- entrada: medição de período ou ciclo ativo.

	- 16 saídas de PWM: qualquer GPIO pode ser uma saída PWM.

* Características

	- Contador de 16 bits: contagem crescente/decrescente; divisor de clock fracional.
	- 2 canais de saída independentes
	- Detecção de eventos de borda: medição de período
	- Detecção de nível: medição de Duty Cycle
	- Configuração do wrap (período) e level (Duty Cycle)
	- Interrupção e DMA

![Figura 3](https://github.com/ubiratantavares/embarcatech_repository/blob/main/unidade4/capitulo7/figura3.png)

* Todos os 30 pinos de GPIO podem ser usados para PWM

![Figura 4](https://github.com/ubiratantavares/embarcatech_repository/blob/main/unidade4/capitulo7/figura4.png)

* Funcionamento do módulo PWM

 	- O circuito do PWM compara um contador livre de 16 bits com uma entrada: geração de um sinal
	 de saída que fica alternando entre 0 e 1. O tempo em alto é proporcional ao valor da entrada.

 ![Figura 5](https://github.com/ubiratantavares/embarcatech_repository/blob/main/unidade4/capitulo7/figura5.png)

 	- No modo de ajuste de fase, o contador é crescente/decrescente: O centro do Duty Cicle é sempre o mesmo.

 ![Figura 6](https://github.com/ubiratantavares/embarcatech_repository/blob/main/unidade4/capitulo7/figura6.png)

## Configurações

* Etapas de configuração usando o SDK

	- Configuração do GPIO.
	- Configuração do sinal de saída: período, divisor de clock, Duty Cycle.
	- Habilitação da saída PWM.
	- Ajustando o Duty Cycle.

* Configuração do GPIO

	- gpio_set_function(gpio, GPIO_FUNC_PWM) // gpio: número da porta que será usada.
	- GPIO_FUNC_PWM: constante que indica que o pino será usado como PWM.
	- slice = pwm_gpio_to_slice_num(gpio)    // slice: endereço do slice para o pino gpio.

* Configurações do sinal de saída

	- a frequência do sinal de PWM é dada pela fórmula abaixo:

$$
f_{PWM} = \frac{f_{clock}{(divisor inteiro + \frac{divisor fracional}{16}) \times wrap}}
$$

Onde:

* $f_{PWM}$ é a frequência do sinal de PWM.
* $f_{clock}$ é a frequência do sinal de clock base (125 MHz).
* divisor inteiro é a parte inteira do divisor de clock, possui 8 bits.
* divisor fracionário é a parte fracionária do divisor de clock, possui 4 bits.
* wrap é o valor máximo de contagem, possui 16 bits.

	- As funções abaixo são usadas para configurar o divisor do clock  o período (wrap)

		* pwm_set_clkdiv(slice, divider)
		* pwm_set_wrap(slice, period)
			
			- divider: número float que indica o valor do divisor do clock de entrada.
			- slice: número do slice do PWM.
			- period: valor máximo de contagem.

	- As funções abaixo são usadas para configurar o dutycycle(level):

		* pwm_set_gpio_level(gpio, level)

			- gpio: número da porta usada para PWM.
			- level: valor de contagem do duty cycle.

	- Ajustando o Duty Cycle:

		* pwm_set_gpio_level(gpio, level)

			- de forma periódica ou sob demanda.
			- Interrupção.

## Exemplos

* Controle o brilho do LED

	 - Vamos controlar a intensidade do LED azul da placa BitDogLab

	 	* Configurar o gpio
	 	* Configurar o PWM (frequência de 3,9 kHz)

	 - Periodicamente (1 Hz) ajustar o Duty Cycle de forma crescente/decrescente.

	 - Após criar o projeto no VS Code

	 - Abra o arquivo CMakeLists.txt

	 	* Faça a alteração abaixo, adicionando a biblioteca hardware_pwm

	 	# add the standard library to the build
	 	target_link_libraries(PWM_LED_0 pico_stdlib hardware_pwm)

```c
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

const uint LED = 12; // pino do LED conectado
const uint16_t PERIOD = 2000; // período do PWM (valor máximo do contador)
const float DIVIDER_PWM = 16.0; // divisor fracional do clock para bo PWM
const uint16_t LED_STEP = 100; // passo de incremento/decremento para o duty cycle do LED
uint16_t led_level = 100; // nível inicial do PWM (duty cycle)

void setup_pwm() {
	uint slice;
	gpio_set_function(LED, GPIO_FUNC_PWM); // configura o pino do LED para função PWM
	slice = pwm_gpio_to_slice_num(LED); // obtém o slice do PWM associado ao pino do LED
	pwm_set_clkdiv(slice, divider_PWM); // define o divisor de clock do PWM 
	pwm_set_wrap(slice, PERIOD); // configura o valor máximo do contador (período do PWM)
	pwm_set_gpio_level(LED, led_level); // define o nível inicial do PWM para o pino do LED
	pwm_set_enabled(slice, true); // habilita o PWM no slice correspondente
} 

int main {
 	uint up_down = 1; // variável para controlar se o nível do LED aumenta ou diminui
 	stdio_init_all(); // inicializa o sistema padrão de I/O
 	setup_pwm(); // configura o PWM

 	while (true) {
 		pwm_set_gpio_level(LED, led_level); // define o nível atual do PWM (duty cycle)
 		sleep_ms(1000); // atraso de 1 segundo
 		if (up_down) {
 			led_level += LED_STEP; // incrementa o nivel do LED
 			if (led_level >= PERIOD) {
 				up_down = 0; // muda direção para diminuir quando atingir o período máximo
 			} else {
 				led_level -= LED_STEP; // decrementa o nível do LED
 				if (led_level <= LED_STEP) {
 					up_down = 1; // muda direção para aumentar quando atingir o mínimo
 				}
 			}
 		}
 	}	
}
```

## Principais Pontos

* PWM é um dispositivo que nos permite controlar a potência entregue a dispositivos eletrônicos.

* Existem várias aplicações de pWM, como: controle de brilho de LED, motores, conversores de potência, dentre outras.

* O RP2040 pode gerar 16 sinais de PWM.

* O SDK da Raspberry nos fornece funções simples para configurar e usar o PWM.
