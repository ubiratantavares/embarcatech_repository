# Capítulo 8 - Conversores A/D

## Objetivos

* Entender o processo de conversão A/D

* Compreender o funcionamento do módulo A/D

* Conhecer os diferentes modos de configuração do módulo conversor A/D

* Configurar e implementar o uso do módulo A/D, inclusive em conjunto com o módulo PWM

## Revisão

* Usar e configurar o clock e temporizadores

* A utilizar as interfaces de comunicação serial

* A configurar e aplicar o módulo PWM

## Visão Geral 

* O que é um conversor analógico-digital (ADC)?

 - Dispositivo que converter sinais analógicos (variáveis contínuas) em sinais digitais (variáveis discretas).

 - Microcontroladores só lidam com sinais digitais. Precisamos do ADC para tratar sensores analógicos.

![figura 1](https://github.com/ubiratantavares/embarcatech_repository/blob/main/unidade4/capitulo8/figura1.png)

* Princípios de Funcionamento

 - Amostragem: processo no qual o ADC lê o sinal analógico em períodos pré-definidos. Quanto maior a frequência de amostragem, mais preciso é a representação do sinal.

 - Quantização: aproxima (arredonda) o valor para um valor digital discreto. Erro de quantização. Quanto maior a resolução mais níveis de quantização.

 - Codificação binária: mapeia os valores.

![figura 2](https://github.com/ubiratantavares/embarcatech_repository/blob/main/unidade4/capitulo8/figura2.png)

* Características Importantes

 - Resolução: define a precisão do ADC: 8 bits, 10 bits, 12 bits, dentre outras.

 - Taxa de amostragem: quantas amostras podem ser feitas. Medida em sps (samples per second)

 - Tensão de referência: intervalo de tensões que o ADC pode medir.

## ADC no RP2040

* O RP2040 tem um ADC interno

 - Conversão por aproximações sucessivas.

 - 500 ksps (amostras por segundo) com clock de 48 MHz

 - Resolução de 12 bits

 - Cinco entradas: 4 pinos externos (GP26-GP29) e 1 sensor de temperatura

 - Interrupção/DMA: FIFO 8 amostras

 ![figura3](https://github.com/ubiratantavares/embarcatech_repository/blob/main/unidade4/capitulo8/figura3.png)

* Conversor SAR

 - O processo de conversão é feito por aproximações sucessivas.

 - Um conversor digital-analógico (DAC) gera valores analógicos que são comparados ao valor amostrado.

 - Um comparador determina se o valor gerado pelo DAC é maior (1) ou menor (0) que o valor amostrado.

 - O processo se repete com o DAC gerando valores anaógicos que são frações da tensão de referência.

 - Processo lento: leva 96 ciclos de clock para gerar os 12-bits. A precisão é baixa. Apenas os 9 bits mais significativos são precisos!

![figura 4](https://github.com/ubiratantavares/embarcatech_repository/blob/main/unidade4/capitulo8/figura4.png)

## Configurações

* o ADC possui dois modos de funcionamento.

 - One-Shot: realiza uma única conversão por vez. É preciso. 

 	- Inicializar o módulo ADC - adc_init()
 	- Configurar GPIO com entrada analógica - adc_gpio_init(gpio)
 	- Selecionar a entrada analógica - adc_select_inoput(channel)
 	- Realizar a conversão - v =  adc_read()

 - Free-Running

 	- Inicia novas conversões de forma automática.
 	- Amostra de forma sequencial as entradas analógicas pré-selecionadas.
 	- Armazena em uma FIFO de oito entradas.
 	- Integração com o DMA.

## Exemplos

* Leitura de entrada ADC

 - Vamos fazer a leitura do Joystick da BitDogLab. O Joystick gera dois sinais analógicos que representam os eixos X e Y. O GP26 (canal analógico 0)
VRX e GP27 (canal analógico 1) VRY. Há ainda uma entrada digital que representa se o controle foi pressionado GP22. Nesse exemplo,
iremos ler as três entradas e usar o console serial para mostrar os seus valores.

 - Crie o projeto no VS Code com auxilio do plugin do Pi Pico.

 - Faça a alteração abaixo no CMakeLists.txt: adicionar a biblioteca hardware_adc e configurar o console pela USB

```text
# modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(joystick 0)
pico_enable_stdio_usb(joystick 1)

target_link_libraries(joystick pico_stdlib hardware_adc)

pico_add_extra_outputs(joystick)
```

```C
#include <stdio.h>
#include "hardware/adc.h"
#include "pico/stdlib.h"

const int VRX = 26;
const int VRY = 27;
const int ADC_CHANNEL_0 = 0;
conts int ADC_CHANNEL_1 = 1;
const int SW = 22;

void setup() {
	// initialize chosen serial port
	stdio_init_all();
	adc_init();
	adc_gpio_init(VRX);
	adc_gpio_init(VRY);
	gpio_init(SW);
	gpio_set_dir(SW, GPIO_IN);
	gpio_pull_up(SW);	
}

int main() {
	uint16_t vrx_value, vry_value, sw_value;
	setup();
	printf("Joystick\n");
	while (1) {
		adc_select_input(ADC_CHANNEL_0);
		sleep_us(2);
		vrx_value = adc_read();
		adc_select_input(ADC_CHANNEL_1);
		sleep_us(2);
		vry_value = adc_read();
		sw_value = !gpio_get(SW);
		printf("X: %u, Y: %u, Botão: %d\n", vrx_value, vry_value, sw_value);
		sleep_ms(10000);
	}
}
```

* Controle de Intensidade dos LEDs com o JoyStick

slides 16-24


## Principais Pontos

* o ADC é um dispositivo que na interface do mundo analógico com o mundo digital.

* Um ADC possui várias características como resolução, taxa de amostragem, tensão referencial.

* O RP2040 possui um ADC interno do tipo SAR: 12 bits de resolução. 500 ksps.

* Aprendemos como usar o SDK para criar aplicações que usam o ADC e outros módulos como o PWM.
