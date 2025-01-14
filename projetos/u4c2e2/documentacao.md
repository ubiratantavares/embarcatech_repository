# Projeto - Controle de LEDs RGB com base na leitura de dois botões

## Introdução

O controle de dispositivos eletrônicos com base em entradas de botões é um conceito fundamental em sistemas embarcados. 

Utilizando uma placa Raspberry Pi Pico, LEDs e botões, é possível implementar circuitos interativos que respondem a estímulos externos, 
permitindo o aprendizado prático de conceitos como entrada/saída digital, pull-up/pull-down e controle de estados. 

Este projeto explora o controle de LEDs RGB com base na leitura de dois botões, demonstrando como programar e interagir com os periféricos da placa por meio da linguagem C.

## Objetivo

O objetivo deste projeto é implementar um sistema que utiliza dois botões para controlar as cores de LEDs RGB através da placa Raspberry Pi Pico. 

Através da análise do código e da montagem do circuito, busca-se compreender conceitos de lógica condicional, controle digital e o uso de bibliotecas específicas do microcontrolador 
para manipular GPIOs.

## Materiais 

* Hardware:

	- 1 x Placa Raspberry Pi Pico.
	- 1 x LED RGB com terminais independentes (ou 3 LEDs separados: vermelho, verde e azul).
	- 2 x Botões tácteis (push buttons).
	- 3 x Resistores de 220 Ω (para limitar a corrente nos LEDs).
	- 2 x Resistores de 10 kΩ (para pull-down nos botões).
	- Fios de conexão.
	- Protoboard.

* Software:

	- SDK do Raspberry Pi Pico (C/C++).
	- Ambiente de desenvolvimento integrado (IDE) ou editor de texto.
	- Ferramentas para compilar e carregar o código na placa (como CMake e picotool).

## Montagem do Circuito

[Circuito]()

## Código


```C
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
```

## Análise do Código

O código implementado apresenta uma solução modular e eficiente para o controle de LEDs RGB com base no estado de dois botões. 

Cada função desempenha um papel claro no controle dos componentes:

1. Definição dos Pinos e Constantes:

	- Os pinos dos botões e LEDs são definidos por meio de macros (#define), facilitando a manutenção e a alteração do código.

	- A constante TEMPO_ATRASO determina o intervalo de atualização do estado dos LEDs.

2. Funções de Inicialização:

	- inicializar_led: Configura o pino do LED como saída (GPIO_OUT).
	- inicializar_botao: Configura o pino do botão como entrada (GPIO_IN) e ativa o resistor pull-down interno para garantir um estado de repouso estável.

3. Funções Auxiliares:

	- esta_pressionado: Verifica se o botão está pressionado (retorna 1 se pressionado, 0 caso contrário).
	- acender_led e apagar_led: Controlam o estado do pino associado ao LED (alto ou baixo).

4. Função main:

	- Inicializa os LEDs e botões.
	- Implementa um loop infinito que monitora o estado dos botões e aciona os LEDs de acordo com as condições:
		- Ambos os botões pressionados: LED vermelho aceso.
		- Apenas o botão A pressionado: LED azul aceso.
		- Apenas o botão B pressionado: LED verde aceso.
		- Nenhum botão pressionado: Todos os LEDs apagados.

	- O uso de sleep_ms no final do loop garante que as mudanças de estado não ocorram instantaneamente, reduzindo a instabilidade devido a possíveis ruídos nos botões.

NOTA: A estrutura do código é clara, organizada e demonstra boas práticas na utilização do SDK do Raspberry Pi Pico, como a modularização por funções e o uso correto dos modos de entrada/saída.
