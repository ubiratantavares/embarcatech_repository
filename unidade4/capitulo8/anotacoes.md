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

 - Vamos controlar a intensidade do LED RGB usando PWM a partir dos comandos do Joystick.

 - Procedimento:

 	- Configurar os pinos analógicos e as saídas digitais (LEDs azul e verde).

 	- Configurar dois PWMs: wrap de 4096 e level (duty cycle) igual ao valor lido do Joystick.

 - Vamos fazer um loop de 100 ms

 	- Realizar a leitura das entradas analógicos.

 	- Ajuste do duty cycle.

* Crie o projeto no VS Code com auxílio do plugin do Pi Pico

* Altere o CMakeLists.txt

	- Adicione as bibliotecas do ADC e PWM

```text
# modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(joystick 0)
pico_enable_stdio_usb(joystick 1)

target_link_libraries(joystick pico_stdlib hardware_adc hardware_pwm)

pico_add_extra_outputs(joystick)
```

* Código da aplicação

```C
#include <stdio.h>        // biblioteca padrão de entrada e saída
#include "hardware/adc.h" // biblioteca para manipulação do ADC no RP2040
#include "hardware/pwm.h" // biblioteca para controle de PWM no RP2040
#include "pico/stdlib.h"  // biblioteca padrão do raspberry pi pico

// definição dos pinos usados para o joystick e LEDs
const int VRX = 26;            // pino de leitura do eixo X do joystick (conectado ao ADC)
const int VRY = 27;            // pino de leitura do eixo Y do joystick (conectado ao ADC)
const int ADC_CHANNEL_0 = 0;   // canal ADC para o eixo X do joystick
conts int ADC_CHANNEL_1 = 1;   // canal ADC para o eixo Y do joystick
const int SW = 22;             // pino de leitura do botão do joystick
const int LED_B = 13;          // pino para controle do LED azul via PWM
const int LED_R = 11;          // pino para controle do LED vermelho via PWM
const float DIVIDER_PWM = 16.0; // divisor freacional do clock para o PWM
const uint16_t PERIOD = 4096;   // período do PWM (valor máximo do contador)
uint16_t led_b_level, led_r_level = 100; // inicialização dos níveis de PWM para os LEDs
uint slice_led_b, slice_led_r;           // variáveis para armazenar os slices de PWM correspondentes aos LEDs

// função para configurar o joystick (pinos de leitura e ADC)

void setup_joystick() {
	// inicializa o ADC e os pinos de entrada analógica
	adc_init();              // inicializa o módulo ADC
	adc_gpio_init(VRX);      // configura o pino VRX (eixo X) para entrada ADC
	adc_gpio_init(VRY);      // configura o pino VRY (eixo Y) para entrada ADC

	// inicializa o pino do botão do joystick
	gpio_init(SW);              // inicializa o pino do botão
	gpio_set_dir(SW, GPIO_IN);  // configura o pino do botão como entrada
	gpio_pull_up(SW);	        // ativa o pull-up no pino do botão (para evitar flutuações)
}

// função para configurar o PWM de um LED (genérica para azul e vermelho)
void setup_pwm_led(uint led, uint *slice, uint16_t level) {
	gpio_set_function(led, GPIO_FUNC_PWM);     // configura o pino do LED como saída PWM
	*slice = pwm_gpio_to_slice_num(led);       // obtém o slice do PWM associado ao pino do LED
	pwm_set_clkdiv(*slice, DIVIDER_PWM);       // define o divisor de clock do PWM
	pwm_set_wrap(*slice, PERIOD);              // configura o valor máximo do contador (período)
	pwm_set_gpio_level(led, level);            // define o nível inicial do pWM para o LED
	pwm_set_enabled(*slice, true);             // habiita o PWM no slice correspondente apo LED
}

// função de configuração geral
void setup() {
	stdio_init_all();                                    // inicializa a porta serial para saída
	setup_joystick();                                    // chama a função de configuração do joystick
	setup_pwm_led(LED_B, &slice_led_b, led_b_level);     // configura o PWM para o LED azul
	setup_pwm_led(LED_R, &slice_led_r, led_r_level);     // configura o PWM para o LED vermelho
}

// função para ler os valores dos eixos do joystick (X e Y)
void joystick_read_axis(uint16_t *vrx_value, uint16_t *vry_value) {
	// leitura do valor do eixo X do joystick
	adc_select_input(ADC_CHANNEL_0);         // seleciona o canal ADC para o eixo X
	sleep_us(2);                             // pequeno delay para estabilidade
	*vrx_value = adc_read();                 // lê o valor do eixo X (0-4095)

	// leitura do valor do eixo Y do joystick
	adc_select_input(ADC_CHANNEL_1);         // seleciona o canal ADC para o eixo Y
	sleep_us(2);                             // pequeno delay para estabilidade
	*vry_value = adc_read();                 // lê o valor do eixo Y (0-4095)
}

int main() {
	// variáveis para armazenar os valores do joystick
	uint16_t vrx_value, vry_value, sw_value;

	// chama a função de configuração 
	setup();

	// exibe uma mensagem inicial via porta serial
	printf("Joystick-PWM\n");

	// loop principal
	while (1) {

		// lê os valores dos eixos do joystick
		joystick_read_axis(&vrx_value, &vry_value);

		// ajusta os níveis PWM dos LEDs de acordo com os valores do joystick
		pwm_set_gpio_level(LED_B, vrx_value);   // ajusta o brilho do LED azul com o valor do eixo X
		pwm_set_gpio_level(LED_R, vry_value);   // ajusta i brilho do LED vermelho com o valor do eixo Y

		// pequeno delay antes da próxima leitura 
		sleep_ms(100);                          // espera 100 ms antes de repetir o ciclo
	}
}
```



## Principais Pontos

* o ADC é um dispositivo que na interface do mundo analógico com o mundo digital.

* Um ADC possui várias características como resolução, taxa de amostragem, tensão referencial.

* O RP2040 possui um ADC interno do tipo SAR: 12 bits de resolução. 500 ksps.

* Aprendemos como usar o SDK para criar aplicações que usam o ADC e outros módulos como o PWM.
