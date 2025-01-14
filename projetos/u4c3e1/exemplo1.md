# Exemplo 1: Controle de semáforo temporizado com push-button

## Introdução

Neste primeiro exemplo prático, vamos explorar como utilizar os GPIOs do
Raspberry Pi Pico para implementar um sistema de controle de semáforo,
utilizando três LEDs para representar as cores de um semáforo real e um
push-button para iniciar e pausar o ciclo de funcionamento. Essa atividade
é essencial para compreender a configuração e a utilização de pinos de
entrada e saída, bem como a aplicação de técnicas de temporização
(delay) para o controle preciso de eventos. O controle de semáforo é um
exemplo clássico em sistemas embarcados que envolve a interação com
dispositivos externos e a sincronização de múltiplos sinais.

## Objetivo

O objetivo deste exemplo é implementar um sistema de controle de
semáforo utilizando três LEDs (vermelho, amarelo e verde) e um push-
button, simulando o funcionamento de um semáforo de trânsito. Vamos
configurar os LEDs para acender em sequência, com tempos específicos
para cada cor, e usar o push-button para iniciar e pausar o ciclo do
semáforo.

## Materiais 

Para realizar este experimento, você precisará dos seguintes
componentes:
• 1 x Raspberry Pi Pico ou BitDogLab
• 1 x LED Vermelho
• 1 x LED Amarelo
• 1 x LED Verde
• 3 x Resistores de 330 ohms
• 1 x Push-Button

## Montagem do Circuito

1. Conexão dos LEDs:
• Conecte o ânodo (perna maior) do LED vermelho ao pino GPIO 11 do Raspberry Pi Pico e o cátodo (perna menor) ao GND, através de um
resistor de 330 ohms.
• Repita o procedimento para o LED amarelo no pino GPIO 12 e para o
LED verde no pino GPIO 13, utilizando resistores de 330 ohms para
limitar a corrente.
Conecte um terminal do push-button ao pino GPIO 05 e o
•
2. Conexão do
• Push-Button:
Adicione um resistor de pull-down (10k ohms) entre o pino
• Conecte um terminal do push-button ao pino GPIO 05 e o outro terminal
ao GND.
leituras instáveis.
• Adicione um resistor de pull-down (10k ohms) entre o pino GPIO 5 e o
GND para evitar leituras instáveis.
A seguir, temos o diagrama esquemático do circuito:
A seguir, temos o diagrama esquemático do circuito:
Figura 11- Diagrama
do circuito
do semáforo
temporizado.

* Diagrama do circuito do semáforo temporizado

## Código

Segue abaixo, o código de implementação do controle do semáforo temporizado com o push-button. O código utiliza a biblioteca padrão do Raspberry Pi Pico
para configurar os pinos GPIO e controlar o ciclo dos LEDs.

```C

```

## Análise do Código

O código apresentado acima implementa a lógica de controle do
semáforo utilizando funções da biblioteca pico/stdlib.h para manipular
os pinos GPIO. Na função main(), os LEDs são configurados como saídas
digitais e o push-button como uma entrada com resistor de pull-
down, garantindo que a leitura seja estável quando o botão não estiver
pressionado.
A função iniciar_ciclo() contém o ciclo de funcionamento do semáforo,
no qual cada LED é aceso por um tempo específico: o LED verde por 5
segundos, seguido do LED amarelo por 2 segundos e, finalmente, o LED
vermelho por 5 segundos. O estado ciclo_ativo controla se o ciclo do
semáforo está em execução. Quando o push-button é pressionado, o valor
de ciclo_ativo é alternado entre verdadeiro e falso, permitindo iniciar ou
pausar o ciclo.
O funcionamento do semáforo é controlado pelo estado do push-button.
Quando pressionado, o botão inicia o ciclo de temporização dos LEDs,
alternando entre verde, amarelo e vermelho com os respectivos tempos
definidos. A cada novo ciclo, o LED correspondente acende e apaga
conforme a sequência pré-determinada. Se o botão for pressionado
novamente, o ciclo é interrompido e o semáforo permanece no estado
atual até que o botão seja pressionado novamente para retomar. A partir
desse ponto, você pode experimentar diferentes combinações de LEDs
e adicionar mais botões para ampliar as opções de controle, criando
sequências de iluminação e interações mais complexas.
No próximo subtópico, exploraremos a utilização de um display de 7
segmentos para criar um temporizador que exibe números de 0 a 9.
Nesse exemplo, vamos aplicar técnicas de temporização para controlar a
mudança dos dígitos de forma precisa, oferecendo uma base prática para
a criação de contadores e indicadores visuais em projetos de sistemas
embarcados.

