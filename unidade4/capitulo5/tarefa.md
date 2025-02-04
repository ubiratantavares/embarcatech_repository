# Capítulo 5 - Clock e Temporizadores

## Tarefa

Reutilize o circuito no [Wokwi](https://wokwi.com/) criado na sala de aula. 

Realize os 6 itens pedidos a seguir: 

1. Elabore um programa para acionar um LED quando o botão A for pressionado 5 vezes, tomando cuidado para registrar essa contagem. 
Quando o valor da contagem chegar a 5, um LED deve piscar por 10 segundos, na frequência de 10 Hz.

2. Modifique o código da questão anterior, implementando o botão B para mudar a frequência do LED para 1 Hz.

3. Elabore um código utilizando a interface UART0 e conecte os fios TX e RX atribuídos à essa interface aos da UART1 do mesmo microcontrolador (Raspberry Pi Pico). Essa estrutura envia e recebe dados na mesma interface, apenas para verificar seu funcionamento. Utilize a função “scanf” da biblioteca stdio para enviar, via console, um dado à placa. Em seguida, transmita da UART0 para a UART1 e, por fim, transmita o dado recebido para o console utilizando o “printf”. 

OBS: Quando usamos o printf (ou qualquer função de saída pelo stdio) para escrever no terminal via UART0, os bytes gerados por essa escrita também ficam no buffer de transmissão dessa mesma UART. Assim, se fisicamente conectarmos TX de UART0 ao RX da UART1, tudo que foi “impresso” anteriormente acaba sendo retransmitido logo que tentamos enviar outro dado.
Como resolver?

a) Limpar o buffer após cada printf ou função de escrita.
Pode-se fazer um loop que “lê” tudo que ficou no buffer de saída, antes de transmitir o dado que realmente queremos.
Ou, dependendo do caso, usar funções que limpem buffers internos do Pico, como fflush(stdout). Ainda assim, pode restar dado “em trânsito” na UART, então muitas vezes é preciso um “flush” manual em nível de hardware.

b) Usar pinos (UART) diferentes para o console e para o teste de loopback (UART0 <-> UART1).
Basta alterar o diagram.json para que o terminal (Serial Monitor) fique, por exemplo, na UART0 (GP0/GP1), enquanto o teste de loop (UART0 <-> UART1) é feito em outro par de pinos (por exemplo, GP4/GP5 para UART1, e GP8/GP9 para UART0, etc.).

Assim, a UART usada pelo console não fica “contaminando” o teste de transmissão.

![figura1.png]()

![figura2.png]()

4. Já para a comunicação I2C, utilize o DS1307, que é um Real Time Clock – RTC – disponível no simulador Wokwi. O endereço I2C do DS1307 é 0x68. Um RTC é um hardware que garante a contagem de tempo na unidade de segundos. Muitos microcontroladores possuem RTC internos, mas alguns fazem uso de hardwares externos. Para ler os valores, é necessário inicialmente configurar um valor de data e hora que deve, por exemplo, ser inserido manualmente pelo usuário. Nessa questão, você deverá configurar o RTC para 24/09/2024 –13:27:00 e, em seguida, realizar a leitura do mesmo a cada 5 segundos, imprimindo na tela do console (Serial USB) o valor lido. Na tabela a seguir, são apresentados os principais endereços do RTC DS1307.

![figura3.png]()

Fonte: tabela elaborada pelo Prof. Pedro Henrique Almeida Miranda.

5. Modifique o exemplo de código apresentado na videoaula (reproduzido abaixo) para controlar os LEDs RGB da placa BitDogLab usando o módulo PWM e interrupções, seguindo as orientações a seguir:
O LED vermelho deve ser acionado com um PWM de 1kHz.

O LED verde deve ser acionado com um PWM de 10kHz.

O Duty Cycle deve ser iniciado em 5% e atualizado a cada 2 segundos em incrementos de 5%. Quando atingir o valor máximo, deve retornar a 5% e continuar a incrementando. - Fazer isso para ambos os LEDs: verde e vermelho.

Tente controlar frequência e o Duty Cycle do LED azul de forma independente do que fez nos LEDs vermelho e verde. Você consegue? Por que não? 

![figura4.png]()

6. Refaça o Programa Prático 00 presente no Ebook do Capítulo de ADC (Capítulo 8), mas implementando no código a conversão da unidade de medida da temperatura de Celsius para Fahrenheit.
A Tabela 1 mostra um lembrete das conexões de GPIO da placa BitDogLab.
Forma de entrega: O/A aluno/a deverá enviar um único arquivo, em formato pdf (com no máximo 1 MB), contendo:

Nome completo;

Resposta aos 6 itens, sendo que, para cada um deles:

- Copie o enunciado;

- Explique resumidamente o procedimento que você usou para responder o item;

- Copie e cole o link do projeto no Wokwi com a sua solução. 

OBS.: Este é um trabalho individual e a resposta a esta tarefa deve ser de sua autoria. O plágio pode desclassificar o seu envio.
