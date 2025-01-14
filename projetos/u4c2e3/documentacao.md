# Projeto - Leitura de Teclado Matricial

## Introdução

Teclados matriciais são amplamente utilizados em sistemas embarcados por sua eficiência em capturar múltiplas entradas em um espaço compacto. 

Eles permitem a detecção de diversas teclas utilizando um número reduzido de pinos de entrada e saída. 

Neste projeto, implementamos a leitura de um teclado matricial 4x4 conectado a um Raspberry Pi Pico W, 
explorando conceitos de multiplexação, entrada/saída digital e mapeamento de teclas. 

Através da implementação em linguagem C, o sistema reconhece e exibe, via comunicação serial, a tecla pressionada pelo usuário.


## Objetivo

O objetivo deste projeto é realizar a interface e a leitura de teclas de um teclado matricial 4x4 utilizando a placa Raspberry Pi Pico W. 

Através do desenvolvimento de um código em C, buscamos interpretar as combinações de linhas e colunas acionadas pelo usuário e apresentar a tecla correspondente na saída serial, 
permitindo a integração do teclado em sistemas mais complexos.

## Materiais 

* Teclado matricial

![Figura 8](https://github.com/ubiratantavares/embarcatech_repository/blob/main/projetos/u4c2e3/exemplo3_1.png)

* Leitura de uma tecla do teclado matricial

![Figura 9](https://github.com/ubiratantavares/embarcatech_repository/blob/main/projetos/u4c2e3/exemplo3_2.png)

## Montagem do Circuito

* Teclado 4 x 4 conectado a um Raspberry Pi Pico W

![Figura 10](https://github.com/ubiratantavares/embarcatech_repository/blob/main/projetos/u4c2e3/exemplo3_3.png)

* Como conectar um teclado matricial a um Raspberry Pi Pico W

![Figura 11](https://github.com/ubiratantavares/embarcatech_repository/blob/main/projetos/u4c2e3/exemplo3_4.png)

## Código

```C
#include <stdio.h>
#include <pico/stdlib.h>

// Define os pinos das colunas do teclado
const uint8_t COL_PINS[] = {1, 2, 3, 4}; 
const uint8_t ROW_PINS[] = {5, 6, 7, 8};

// Mapa de teclas 
const char KEY_MAP[4][4] = {
  {'D', '#', '0', '*'},
  {'C', '9', '8', '7'},
  {'B', '6', '5', '4'},
  {'A', '3', '2', '1'}
};

// Função para ler uma tecla do teclado
char read_keypad(uint8_t *cols, uint8_t *rows) {
  for (int i = 0; i < 4; i++) {
    gpio_put(rows[i], 0); // Define o pino da linha como baixo
    uint8_t result = 0;
    for (int j = 0; j < 4; j++) {
      result |= gpio_get(cols[j]); // Lê os estados dos pinos das colunas
    }
    if (result == 0) { // Verifica se alguma coluna está baixa
      // Obtém a tecla usando a posição do bit menos significativo
      char key = KEY_MAP[i][__builtin_ctz(result)]; 
      gpio_put(rows[i], 1); // Define o pino da linha como alto (debounce)
      return key;
    }
    gpio_put(rows[i], 1); // Define o pino da linha como alto
  }
  return 0; // Nenhuma tecla pressionada
}

int main() {

// Inicializa a serial
 uart_init(uart0, 115200);
 stdio_init_all();


    // Inicializa os pinos das colunas como entrada com pull-up
 for (int i = 0; i < sizeof(COL_PINS)/sizeof(COL_PINS[0]); i++) {
    gpio_init(COL_PINS[i]);
    gpio_set_dir(COL_PINS[i], GPIO_IN);
    gpio_pull_up(COL_PINS[i]);
  }

  // Inicializa os pinos das linhas como saída
  for (int i = 0; i < sizeof(ROW_PINS)/sizeof(ROW_PINS[0]); i++) {
    gpio_init(ROW_PINS[i]);
    gpio_set_dir(ROW_PINS[i], GPIO_OUT);
  }

setbuf(stdout, NULL); // Desabilita o buffering de linha

printf("--- Pronto para receber entradas do usuário ---\n");
   while (true) {
        for (int row = 0; row < 4; row++) {
            gpio_put(ROW_PINS[row], 0); // Define a linha como baixo

            // Lê todas as colunas de uma vez para otimizar
            uint8_t columns = 0;
            for (int col = 0; col < 4; col++) {
                columns |= gpio_get(COL_PINS[col]) << col;
            }

            if (columns != 0) {
                int col = __builtin_ctz(columns);
                char key = KEY_MAP[row][col];
                printf("Tecla pressionada: %c\n", key);
                sleep_ms(300); // Debounce
                break; // Sai do loop externo, pois uma tecla foi pressionada
            }

            gpio_put(ROW_PINS[row], 1); // Define a linha como alto
        }
  
	}
}
```

## Análise do Código

O código apresentado realiza a leitura de um teclado matricial 4x4 e exibe, via comunicação serial, as teclas pressionadas. 

A seguir, analisamos as principais partes do programa:

1. Definição dos Pinos e do Mapa de Teclas:

	- Os pinos das linhas e colunas do teclado são configurados em arrays (ROW_PINS e COL_PINS). 

	- O KEY_MAP define a correspondência entre as combinações de linhas e colunas e os caracteres que representam as teclas, permitindo o mapeamento direto.

2. Inicialização:

	- Os pinos das colunas são configurados como entradas com resistores pull-up internos ativados.

	- Os pinos das linhas são configurados como saídas, permitindo que sejam alternados entre níveis alto e baixo para varrer o teclado.

3. Função read_keypad:

	- A função implementa a varredura do teclado ativando uma linha por vez (definindo-a como nível baixo).

	- Em seguida, lê os estados das colunas para identificar se alguma tecla está pressionada.

	- Caso uma tecla seja pressionada, utiliza a função __builtin_ctz para identificar a coluna correspondente, obtendo assim o caractere do KEY_MAP.

4. Loop Principal (main):

	- O loop principal executa continuamente a varredura do teclado.

	- Quando uma tecla é detectada, exibe o caractere correspondente na saída serial (printf).

	- Após identificar uma tecla, um atraso de 300 ms (sleep_ms) é aplicado para debounce, evitando múltiplas leituras da mesma tecla.

5. Comunicação Serial:

	- O programa inicializa a comunicação serial utilizando o UART, permitindo a exibição das teclas pressionadas no terminal do computador.

	- A função setbuf(stdout, NULL) desabilita o buffer de linha, garantindo que as mensagens sejam exibidas imediatamente.

NOTA: O código é eficiente e modular, com uma abordagem clara para a varredura do teclado. A aplicação de conceitos como debounce, uso de pull-ups e mapeamento de teclas 
torna o programa robusto e adequado para integrar teclados matriciais em sistemas embarcados.

