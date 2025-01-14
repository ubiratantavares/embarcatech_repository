# Unidade 4 - Microcontroladores

## Capítulo 1 - Introdução ao Desenvolvimento de Software Embarcado com Microcontroladores

### Sumário

* Objetivos
* Introdução
* Kit de Desenvolvimento
* RaspberryPi Pico W
* RP2040
* Organização do SDK
* Principais Pontos

### Objetivos

* Entender as características do desenvolvimento de software em microcontroladores
* Conhecer e caracterizar a placa de desenvolvimento BitDogLab e seus componentes principais: CPU, memória, interfaces de entrada/saída.
* Compreender a organização das bibliotecas de desenvolvimento do RaspberryPi Pico W.

### Introdução

* Desenvolvimento em Microcontroladores
	- Recursos limitados
	- Programação em baixo nível
	- Controle pŕeciso de tempo: requisitos de tempo-real
	- Interação com o mundo físico

### Kit de Desenvolvimento

* BitDogLab
	- Iniciativa do projeto escola 4.0: UNICAMP
	- Ferramenta educacional: sistemas embarcados, eletrônica
	- RaspberryPi Pico W
	- Componentes: bateria, display OLED 128x64 pixels, matriz de LEDs coloridos, microfone, joystick, botões, buzzer, conectores de expansão.

![Figura 1](https://github.com/ubiratantavares/embarcatech_repository/blob/main/unidade4/capitulo1/bigdoglab.png)
	
### RaspberryPi Pico W

* Placa de microcontrolador
	- Baseado no RP2040
	- Baixo custo e flexível
	- Interface sem-fio de 2.4 GHz: 802.11, Bluetooth 5.2
	- Porta micro-usbtipo B: alimentação e dados
	- Porta de depuração SWD
	- SDK simples de usar

![[microcontrolador_RP2040.png]]
	
### RP2040

* Primeiro MCU do RaspberryPi
* Alta performance
* Baixo custo
* Fácil de usar
* Recursos Avançados: Dual-Core, Rico conjunto de periféricos, programmableI/O

![[rp2040.png]]


* Dual CortexM0+, 133 MHz
* 264kB SRAM
* Barramento
* 30 GPIO
* SPI Flash
* Vários periféricos
* 4 Canais ADC: 500 ksps, 12 bit
* USB 1.1
* Recursos: Clock, SWD, PWM, Timer, RTC, SPI, UART, I2C, ADC, PIO
	- Clock
		- O RP2040 possui um sistema de clock que é configurável e controla a frequência de operação dos núcleos de processamento, periféricos e outros subsistemas.
		- Possui um cristal oscilador externo de 12 MHz e um oscilador interno que pode ser usado em aplicações onde a precisão não é crítica.
		- O clock principal pode ser configurado com o Phase-Locked Loop (PLL), permitindo frequências de até **133 MHz**.

	- SWD (Serial Wire Debug)
		- Um protocolo de depuração usado para programar e depurar o RP2040.
		- É um padrão da ARM Cortex-M, que oferece um método de comunicação bidirecional eficiente para debugging.
		- Permite que você monitore o comportamento do código em tempo real, inspecione variáveis e registre informações de execução.

	- PWM (Pulse Width Modulation)
		- O RP2040 possui 16 canais PWM independentes, cada um com dois slices.
		- Esses canais podem ser usados para controlar dispositivos como motores, LEDs, e gerar sinais analógicos por meio de modulação digital.
		- Permite configurar a frequência, ciclo de trabalho (duty cycle) e fase, sendo bastante flexível.
	
	- Timer
		- O RP2040 possui temporizadores que permitem a execução de tarefas baseadas em tempo.
		- Esses temporizadores podem ser usados para gerar interrupções periódicas, medir intervalos de tempo ou implementar atrasos precisos.
		- Cada núcleo do RP2040 possui um timer dedicado, além de temporizadores de propósito geral para tarefas mais complexas.

	- RTC (Real-Time Clock)
		- O Real-Time Clock do RP2040 permite manter o registro do tempo e da data, mesmo durante estados de baixa energia.
		- É útil para aplicações que precisam de timestamps, como dataloggers e sistemas baseados em tempo.
		- Pode ser alimentado por uma fonte externa para continuar funcionando mesmo se o microcontrolador for desligado.

	- SPI (Serial Peripheral Interface)
		- Uma interface serial síncrona usada para comunicação de alta velocidade entre o RP2040 e periféricos como sensores, displays e cartões SD.
		- Suporta operação como mestre ou escravo.
		- O RP2040 possui até 2 controladores SPI, cada um configurável para diferentes taxas de transmissão e modos de operação.

	- UART (Universal Asynchronous Receiver/Transmitter)
		- Permite comunicação serial assíncrona, como a conexão a computadores, módulos Bluetooth ou Wi-Fi.
		- O RP2040 suporta até **2 portas UART**, cada uma com buffers independentes para transmissão e recepção.

	- I2C (Inter-Integrated Circuit)
		- Uma interface de comunicação serial síncrona com suporte a múltiplos dispositivos no mesmo barramento.
		- O RP2040 possui até 2 controladores I2C, configuráveis para diferentes velocidades (padrão, rápido, alta velocidade).
		- Usada para conectar sensores, displays e outros periféricos.

	- ADC (Analog-to-Digital Converter)
		- O RP2040 possui um ADC de 12 bits com até 5 canais.
		- Permite a conversão de sinais analógicos para digitais, como leitura de sensores de temperatura, luz ou tensão.
		- Um dos canais do ADC é conectado ao sensor de temperatura interno do microcontrolador.

	- PIO (Programmable Input/Output)
		- O recurso mais inovador do RP2040: consiste em dois blocos PIO, cada um com 4 máquinas de estado independentes.
		- Permite implementar protocolos de comunicação personalizados (como DVI ou WS2812 para LEDs) que não são suportados diretamente por hardware.
		- Altamente configurável, pode gerar ou capturar sinais digitais de forma precisa, liberando os núcleos principais para outras tarefas.

![[rp2040_diagram.png]]

### Organização do SDK

O SDK provê recursos para criar aplicações C/C++ e Assembly.

* Bibliotecas
	- Padrão do C e C++
	- API: periféricos, interrupções, DMA, alto nível (USB, programação multi-core)
* Build System
* Exemplo de aplicação

```c
#include <stdio.h>
#include "pico/stdlib.h"

const uint led_pin_red = 12;

int main() {
	uint a = 100;

	gpio_init(led_pin_red);
	gpio_set_dir(led_pin_red, GPIO_OUT);
	stdio_init_all();

	while (true) {
		a++;
		if (a % 2) 
			printf("Blinking!\r\n");
		gpio_put(led_pin_red, true);
		sleep_ms(1000);
		gpio_put(led_pin_red, false);
		sleep_ms(1000);
	}
}
```

```CMake
cmake_minimum_required(VERSION 3.21)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(pico-projects C CXX ASM)

pico_sdk_init()

add_executable(blink
	blink.c
)

target_link_libraries(blink pico_stdlib)

pico_add_extra_outputs(blink)
```

* Estrutura das Bibliotecas
	- Bibliotecas de Alto Nível: pico_xxx, APIs que lidam com vários periféricos (pico_time)
	- Suporte ao Ambiente de Execução: setup e inicialização
	- Hardware: hardware_xxx, suporte e registradores


### Principais Pontos

* Desenvolvimento em Microcontroladores: BitDogLab
* Arquitetura e Recursos do RP2040: Dual-Core Cortex-M0+, 256 kB SRAM, periféricos e PIO
* SDK do RaspberryPi Pico
* Configuração do CMakeList: configuração do processo de build.
