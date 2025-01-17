# Capitulo 4 - Interrupções

## Objetivos

* Compreender o funcionamento do mecanismo de interrupções.

* Configurar o módulo de interrupções e rotinas de tratamento de interrupções.

* Desenvolver código de utilização de interrupções e seus diferentes modos

## Revisão

* Desenvolvimento de software em microcontroladores:

	- Entrada e saída programada: rotinas de delay.

	- Controlar os pinos de entrada e saída (GPIO): acionamento de LEDs e leitura de botões.

## Técnicas de Entrada e Saída

* E/S Programada

	- Processador tem controle direto das operações de E/S: monitoramento do estado do periférico (espera por eventos). Processador monitora o dispositivo para identificar a ocorrência de eventos.

	- Envio de comandos e/ou configurações.

	- Transferência de dados.

	- Desperdício do tempo do processador.

* E/S Programada por Interrupção

	- O periférico gera uma interrupção quando um evento de E/S acontece.

	- A execução do processador é interrompida, para atender à solicitação:

		- A execução é direcionada para uma rotina de tratamento de interrupções.

		- Ao fim, o processador retoma do ponto em que foi interrompido.

	- O processador não precisa monitorar periodicamente o periférico.

* Processo de Interrupção 

![processo_interrupcao]()

* Acesso Direto à Memória (DMA)

	- Nas técnicas anteriores, o processador ainda se ocupa de transferir dados entre o periférico e a memória principal.

	- DMA: co-processador específico para controlar as transferências de dados entre periféricos e a memória. Trata as interrupções dos periféricos e movimenta dados.

	- O RP2040 possui um módulo DMA que funciona para periféricos que geram dados (interfaces de comunicação).

	- Configuração desse módulo não é o objetivo no momento.

## Interrupções - RP2040

* O microcontrolador possui um módulo ARM NVIC para cada núcleo.

* 32 interrupções, onde 26 são usadas.

![tabela_interrupcao_irq_fonte]

* Múltiplas Interrupções

	- Níveis de prioridade: existem quatro níveis de prioridade.

	- Interrupções aninhadas:

		- Uma interrupção de menor prioridade pode ser interrompida por uma de maior prioridade.

		- Para interrupções de mesma prioridade, a de menor número de IRQ vence.

## Interrupções do Módulo GPIO

* Cada pino do GPIO possui quatro interrupções:

* Níveis de prioridade:

	- GPIO_IRQ_LEVEL_LOW

	- GPIO_IRQ_LEVEL_HIGH

	- GPIO_IRQ_EDGE_FALL (Borda de Descida)

	- GPIO_IRQ_EDGE_RISE (Borda de Subida)

	- Normalmente, usamos os dois últimos níveis de prioridade.

	- Existe apenas uma interrupção que atende todos os eventos de GPIO de todos os pinos.

* Funções do SDK

	- O SDK fornece um tratador de interrupções, chamado **gpio_irq_handler**, que faz as configurações ncessárias e chama uma rotina escrita pelo usuário chamada **CallbackFunction**. 
	Existe apenas uma para o módulo GPIO.

	- O programador precisa configurar a interrupção (portas e eventos) e designar uma função de **callback**.

	- **gpio_set_irq_enable_with_callback**: gpio (endereço da porta).

	- events: máscara de evento - GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL

	- enabled: valor booleano: True (habilitado) ou False (desabilitado)

	- callback: ponteiro para função de callback, chamada quando a interrupção ocorre.

## Exemplo de Código

```c
#include <stdio.h>]
#include "pico/stdlib.h"

const uint led_pin_red = 12;
const uint button_0 = 6;

static volatile uint a = 1;
static void gpio_irq_handler(uint gpio, uint32_t events);

int main() {
	stdio_init_all();

	gpio_init(led_pin_red);
	gpio_set_dir(led_pin_red, GPIO_OUT);
	
	gpio_init(button_0);
	gpio_set_dir(button_0, GPIO_IN);
	gpio_pull_up(button_0);
	gpio_set_irq_enabled_with_callback(button_0, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);

	while (true);
}

static void gpio_irq_handler(uint gpio, uint32_t events) {
	a++;
	if (a % 2 == 0) {
		gpio_put(led_pin_red, true);
	} else {
		gpio_put(led_pin_red, false);
	}
}
```

## Análise do Código

Este código em C é projetado para ser executado em um microcontrolador baseado no Raspberry Pi Pico, utilizando o SDK C/C++. 

O programa controla um LED conectado a um pino específico do microcontrolador e responde a um botão pressionado configurando uma interrupção para alternar o estado do LED. 

Vamos examinar cada parte:

### **Cabeçalhos Incluídos**

```c
#include <stdio.h>
#include "pico/stdlib.h"
```

- **`#include <stdio.h>`**: Permite o uso de funções padrão de entrada e saída, como `printf`.

- **`#include "pico/stdlib.h"`**: Inclui a biblioteca padrão do SDK do Raspberry Pi Pico, que fornece funções para manipulação de GPIO, configuração de pinos, interrupções, etc.

### **Declaração de Variáveis Globais e Funções**

```c
const uint led_pin_red = 12;
const uint button_0 = 6;

static volatile uint a = 1;
static void gpio_irq_handler(uint gpio, uint32_t events);
```

1. **`const uint led_pin_red = 12;`**:

   - Define o pino GPIO onde o LED vermelho está conectado.

2. **`const uint button_0 = 6;`**:

   - Define o pino GPIO onde o botão está conectado.

3. **`static volatile uint a = 1;`**:

   - Variável global usada para alternar o estado do LED. 

   - O modificador `volatile` instrui o compilador a não otimizar acessos a essa variável, já que ela pode ser modificada pela interrupção.

4. **`static void gpio_irq_handler(uint gpio, uint32_t events);`**:

   - Declaração da função de interrupção associada ao botão.

### **Função Principal**

```c
int main() {
	stdio_init_all();
```

- **`stdio_init_all();`**:

  - Inicializa a entrada/saída padrão, necessária para usar `printf` ou outras funções relacionadas.

```c
	gpio_init(led_pin_red);
	gpio_set_dir(led_pin_red, GPIO_OUT);
```

- Configuração do pino do LED:

  - **`gpio_init(led_pin_red);`**: Inicializa o pino associado ao LED.

  - **`gpio_set_dir(led_pin_red, GPIO_OUT);`**: Define o pino como saída.

```c
	gpio_init(button_0);
	gpio_set_dir(button_0, GPIO_IN);
	gpio_pull_up(button_0);
```

- Configuração do botão:

  - **`gpio_init(button_0);`**: Inicializa o pino associado ao botão.

  - **`gpio_set_dir(button_0, GPIO_IN);`**: Define o pino como entrada.

  - **`gpio_pull_up(button_0);`**: Ativa um resistor de pull-up interno, garantindo que o pino esteja em nível lógico alto quando o botão não estiver pressionado.

```c
	gpio_set_irq_enabled_with_callback(button_0, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
```

- Configuração de interrupção:

  - **`gpio_set_irq_enabled_with_callback`**:

    - Configura uma interrupção no botão para detectar bordas de descida (quando o botão é pressionado).

    - O último argumento é um ponteiro para a função de callback (`gpio_irq_handler`), que será executada quando a interrupção for acionada.

```c
	while (true);
```

- Mantém o programa em execução indefinidamente.

### **Função de Interrupção**

```c
static void gpio_irq_handler(uint gpio, uint32_t events) {
	a++;
	if (a % 2 == 0) {
		gpio_put(led_pin_red, true);
	} else {
		gpio_put(led_pin_red, false);
	}
}
```

- **Parâmetros**:

  - `gpio`: O pino que gerou a interrupção.

  - `events`: O tipo de evento que disparou a interrupção (não é usado diretamente no código).

- **Função**:

  1. Incrementa a variável global `a`.

  2. Verifica se `a` é par:

     - Se **sim**: Acende o LED (`gpio_put(led_pin_red, true)`).

     - Se **não**: Apaga o LED (`gpio_put(led_pin_red, false)`).

### **Resumo**

Este programa alterna o estado de um LED conectado ao pino 12 cada vez que o botão no pino 6 é pressionado. 

Ele utiliza interrupções para detectar o evento de pressão do botão, garantindo uma resposta rápida e eficiente sem depender de polling contínuo.

## Principais Pontos

* Existem três técnicas de entrada e saída.

* E/S controlada por interrupções é uma técnica importante para sistemas microcontrolados, agilizando o tratamento de eventos.

* O módulo GPIO possui quatro eventos que geram interrupções. A função **gpio_set_irq_enabled_with_callback** configura as interrupções desse módulo.

* É preciso ter cuidado ao usar interrupções. Erros em interrupções são muito difíceis de se identificar. Escreva funções simples.
