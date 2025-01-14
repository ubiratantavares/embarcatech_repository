# Exemplo 2: Controle de display de 7 segmentos com temporização por rotina de atraso

## Introdução

Neste segundo exemplo prático, vamos explorar como utilizar os GPIOs
do Raspberry Pi Pico para controlar um display de 7 segmentos[6]. Este
exercício tem como objetivo desenvolver um temporizador simples que
exibe os números de 0 a 9, utilizando rotinas de atraso para gerenciar a
mudança de dígitos. A prática com displays de 7 segmentos é essencial
para a criação de contadores, temporizadores e outros sistemas que
exigem uma interface visual para exibir informações numéricas de
maneira clara e precisa.

## Objetivo

O objetivo deste exemplo é implementar um contador de 0 a 9 utilizando
um display de 7 segmentos controlado pelo Raspberry Pi Pico. A cada
segundo, o número exibido no display será incrementado, e ao atingir 9, o
contador reiniciará em 0. Este exemplo ajudará a consolidar os conceitos
de temporização e controle de GPIOs, além de mostrar como manipular
um display de 7 segmentos para criar interfaces visuais simples, mas
eficazes, em sistemas embarcados.

## Materiais

1 x Raspberry Pi Pico no wokwi[7]
1 x Display de 7 segmentos (catodo comum)[6]
8 x Resistores de 220 ohms
1 x Protoboard

## Montagem do Circuito

1. Conexão dos Segmentos do Display:
• Conecte os pinos dos segmentos do display (a, b, c, d, e, f, g) aos pinos
GPIO correspondentes do Raspberry Pi Pico.
• Utilize resistores de 330 ohms em série para proteger os LEDs do
display.

2. Conexão do Ponto Decimal:
• Se necessário, o pino do ponto decimal (dp) pode ser conectado a um
GPIO adicional ou deixado desconectado se não for utilizado.

A seguir, temos o diagrama esquemático do circuito:

* Diagrama de conexão do display de 7 segmentos ao Raspberry Pi Pico

## Código

Abaixo está o código em C que implementa o controle do display de 7
segmentos, incrementando o número exibido a cada segundo. O código
utiliza a biblioteca padrão do Raspberry Pi Pico para configurar os pinos
GPIO e controlar cada segmento do display.

```C
  #include "pico/stdlib.h"

// Definição dos pinos dos segmentos do display
const uint8_t segment_pins[] = {0, 1, 2, 3, 4, 5, 6};

// Mapeamento dos dígitos para os segmentos do display
const uint8_t digits[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 0, 0, 1, 1}  // 9
};

// Função para exibir um dígito no display
void display_digit(uint8_t digit) {
    for (int i = 0; i < 7; i++) {
        gpio_put(segment_pins[i], digits[digit][i]);
    }
}

int main() {
    stdio_init_all();
    
    // Inicializa e configura os pinos dos segmentos como saída
    for (int i = 0; i < 7; i++) {
        gpio_init(segment_pins[i]);
        gpio_set_dir(segment_pins[i], GPIO_OUT);
    }

    uint8_t contador = 0;

    while (true) {
        display_digit(contador);  // Exibe o dígito atual no display
        sleep_ms(1000);  // Espera 1 segundo
        contador++;  // Incrementa o contador
        if (contador > 9) {
            contador = 0;  // Reinicia o contador após 9
        }
    }
    return 0;
}
```

## Análise do Código

O código apresentado acima utiliza a função display_digit() para
controlar a exibição dos números no display de 7 segmentos. A matriz
digits armazena o mapeamento dos segmentos para cada dígito de 0 a
9. Na função main(), os pinos dos segmentos são configurados como
saídas digitais, e um loop infinito é utilizado para atualizar o display a
cada segundo.
A cada iteração, o dígito exibido é incrementado, e a função sleep_
ms(1000) adiciona um atraso de 1 segundo entre as atualizações.
Quando o contador atinge o valor 10, ele é reiniciado para 0, criando um
ciclo contínuo de contagem de 0 a 9.

A partir de agora, você pode experimentar modificando o tempo de atraso
para alterar a velocidade da contagem, ou adicionar mais displays para
criar um contador de dois dígitos. No próximo subtópico, exploraremos a
multiplexação de displays de 7 segmentos, que nos permitirá controlar
múltiplos displays utilizando um número reduzido de pinos GPIO,
tornando possível a exibição de contagens mais complexas e a criação
de interfaces mais elaboradas.

