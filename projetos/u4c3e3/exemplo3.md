# Exemplo 3 - Multiplexação de displays de 7 segmentos

## Introdução

Neste terceiro exemplo prático, vamos explorar como utilizar a técnica
de multiplexação[8] para controlar dois displays de 7 segmentos com o
Raspberry Pi Pico. A multiplexação permite alternar rapidamente entre os
displays, criando a ilusão de que ambos estão acesos simultaneamente,
enquanto utilizamos um número reduzido de pinos GPIO. Esse exercício é
fundamental para o desenvolvimento de sistemas que exigem a exibição
de números ou informações em múltiplos displays, otimizando o uso dos
recursos do microcontrolador.

## Objetivo

O objetivo deste exemplo é implementar um contador de dois dígitos
utilizando multiplexação para controlar dois displays de 7 segmentos.
A cada segundo, o número exibido nos displays será incrementado,
contando de 00 a 99, e então reiniciará para 00. Essa prática permitirá
consolidar os conceitos de multiplexação e controle de GPIOs, técnicas
fundamentais para desenvolver sistemas eficientes que exigem a
utilização de múltiplos displays ou indicadores visuais, utilizando um
número reduzido de pinos. Isso possibilita a criação de interfaces visuais
complexas e otimizadas, mesmo em microcontroladores com recursos
limitados.

## Materiais

1 x Raspberry Pi Pico no wokwi
2 x Displays de 7 segmentos (catodo comum)
16 x Resistores de 220 ohms
1 x Protoboard

## Montagem do Circuito

1. •Conexão
dos Segmentos dos Displays:

Conecte
os pinos dos segmentos (a, b, c, d, e, f, g) dos dois displays aos

mesmos pinos GPIO do Raspberry Pi Pico, usando resistores de 330
Montagem do Circuito
ohms em série para proteger os LEDs dos displays.

2. Conexão dos Pinos de Controle dos Displays


UtilizeGPIO
dois
GPIOs Piadicionais
(GPIOde11
GPIO
12,para
por
exemplo)
para
LEDs dos
controlar
a displays.
ativação dos displays. Conecte os pinos comuns de
display
permitindo ligar e desligar cada display
2.cada
Conexão
dos Pinosadeesses
Controle GPIOs,
dos Displays:
individualmente.
• Utilize dois GPIO

A seguir, temos
diagrama
esquemático
do circuito:

* Diagrama de conexão dos displays de 7 segmentos ao Raspberry
Pi Pico


## Código

Abaixo está o código em C que implementa o controle de dois displays
de 7 segmentos utilizando multiplexação (Dig1 e Dig2). O código alterna
rapidamente entre os displays para exibir um número de dois dígitos,
incrementando o valor a cada segundo.


```C


```

## Análise do Código

O código apresentado acima utiliza a função display_digit() para alternar
rapidamente entre os dois displays, exibindo um dígito de cada vez em
cada display. A matriz digits armazena o mapeamento dos segmentos
para cada número de 0 a 9. Na função main(), os pinos dos segmentos
e dos displays são configurados como saídas digitais, e o loop infinito
é utilizado para atualizar os displays com base na contagem de 0 a 99.
Vamos explorar o funcionamento de cada parte do código para entender
como a multiplexação é utilizada para controlar múltiplos displays com
um número limitado de pinos GPIO:

segment_pins[]: Cada elemento do array corresponde a um pino do
Raspberry Pi Pico[3] que está conectado aos segmentos a, b, c, d, e, f, g
dos displays de 7 segmentos. Esses pinos controlam quais segmentos
de cada display serão acesos para formar o dígito.

display_pins[]: Define os pinos que controlam qual display está ativo.
O primeiro display é controlado pelo GPIO 12 e o segundo pelo GPIO 11.

Mapeamento dos dígitos: Cada linha do array digits corresponde a um
número de 0 a 9, e cada coluna representa um segmento do display
(a, b, c, d, e, f, g). O valor 1 significa que o segmento correspondente
estará aceso, enquanto 0 indica que estará apagado. Por exemplo,
para exibir o número 2, os segmentos a, b, d, e, g serão ativados (1), e
os segmentos c e f serão desativados (0).

Função setup (): Na inicialização, os pinos de segmento (segment_
pins) e de controle de display (display_pins) são configurados como
saídas. Na desativação inicial, todos os displays são desativados
inicialmente (gpio_put(display_pins[i], 0)), garantindo que nenhum
display esteja ativo ao iniciar

Função show_digit(): A desativação dos displays ocorre antes de
configurar os segmentos, pois ambos os displays são desativados para
evitar exibição incorreta de dígitos. Na configuração dos segmentos,
a função percorre cada segmento e configura o estado (ligado ou
desligado) com base na matriz digits para o dígito desejado.

A técnica de multiplexação permite que o mesmo conjunto de pinos
de segmentos seja compartilhado entre os displays, com apenas dois
pinos adicionais utilizados para controlar qual display está ativo em um
dado momento. A rápida alternância entre os displays cria a ilusão de
que ambos estão acesos simultaneamente, sem causar interferências
visuais.

Você pode experimentar adicionando mais displays e ajustando o tempo
de multiplexação para melhorar a estabilidade visual dos dígitos exibidos.

No próximo subtópico, vamos estruturar um desafio mais avançado: o
desenvolvimento de um cofre digital com senha, utilizando um teclado
matricial para a entrada de dados e temporização para validação das
entradas e controle de segurança. Esse exemplo permitirá explorar a
criação de sistemas interativos mais sofisticados, aplicando tudo o que
aprendemos até agora.

