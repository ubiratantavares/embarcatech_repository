# Projeto - Controle de semáforo temporizado com push-button

## Introdução

Este projeto demonstra o controle de um LED por meio de um push-button usando o Raspberry Pi Pico, empregando conceitos básicos de programação em linguagem C e interação entre hardware e software. 

## Objetivo

O objetivo deste projeto é implementar um sistema básico de controle de um LED utilizando o Raspberry Pi Pico. 

O LED acende enquanto o botão é pressionado, demonstrando o uso de GPIOs (General-Purpose Input/Output) configurados para entrada e saída.  

## Materiais 

Os materiais necessários para a realização deste projeto incluem:  

- Microcontrolador Raspberry Pi Pico;  
- 1 LED;  
- 2 resistores (330 Ω e 10 kΩ);  
- 1 push-button;  
- Protoboard para montagem do circuito;  
- Jumpers para conexão;  
- Fonte de alimentação USB para o Raspberry Pi Pico.  

## Montagem do Circuito

[Circuito]()

## Código

```C
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
```

## Análise do Código

O código apresentado utiliza a biblioteca padrão do Raspberry Pi Pico (`pico/stdlib.h`) e implementa as seguintes etapas:  

1. **Definição de pinos**

   - O LED é conectado ao pino GPIO 11, enquanto o botão está conectado ao GPIO 5. Essas definições são realizadas com as diretivas `#define`.  

2. **Configuração dos GPIOs**:  
   
   - O pino do LED é configurado como saída (`GPIO_OUT`), permitindo o controle do estado do LED.  
   
   - O pino do botão é configurado como entrada (`GPIO_IN`), para detectar quando o botão é pressionado.  

3. **Loop principal**:  
   
   - Dentro de um loop infinito (`while(1)`), o programa verifica continuamente o estado do botão usando a função `gpio_get`.  
   
   - Se o botão estiver pressionado (estado lógico alto), o LED é aceso com a função `gpio_put(LED_PIN, 1)`.  
   
   - Quando o botão não está pressionado, o LED é apagado com `gpio_put(LED_PIN, 0)`.  

4. **Uso do debounce (não implementado)**: 

   - Embora o circuito funcione corretamente, o código pode apresentar instabilidade devido à ausência de debounce, uma técnica que filtra oscilações mecânicas no botão.

