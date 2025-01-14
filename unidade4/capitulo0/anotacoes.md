# Unidade 4 - Microcontoladores

## Unidade 4 - Microcontroladores e aspectos de hardware

### Camadas do Hardware Embarcatech

* Microcontrolador RP2040

![Figura 1]()

* Módulo - Placa Raspberry Pi Pico

![Figura 2]()

* Kit de desenvolvimento - BitDogLab

![Figura 3]()

### Microcontrolador RP2040

#### Microcontrolador da família RP

* O RP2040 foi lançado em 21 de janeiro de 2021 pela Raspberry Pi Foundation.

* Combina alto desempenho, baixo custo, versatilidade e boa documentação.

* Vendeu 4 milhões de unidades até outubro de 2024.

#### Principais Características do RP2040

* Dual-core ARM Cortex-M0+

* Teccnologia de 40 nm

* Memória SRAM integrada (264 kB)

* Suporte para memória flash externa

* Frequência de clock ajustável até 133 MHz

#### Arquitetura Interna do RP2040

![Figura 4]()

#### Por Dentro de Encapuslamento

* Os tijolos para a construção dos blocos internos são os transitores.

![Figura 5]()

* Tecnologia TSMC CMOS de 40 nm

![Figura 6]()

#### Pinagem do RP2040

* QFN 56

![Figura 7]()

#### Interfaces

* Pinos de alimentação (5V e 3V3)

* Pinos de controle do sistema (BOOTSEL, RUN, RESET, DEBUG)

* 30x GPIO digitais, todos com suporte a interrupções (IRQ)

* 16 canais PWM, saída digital modulada por largura de pulso

* 4x pinos para entrada analógica - CAD

* 2x canais UART

* 2x canais SPI

* 2x canais I2C

* SWD Degub Port - Porta de depuração SWD

#### Periféricos Avançados

* PIO (Programmable IO)

* Programação em baixo nível, usando máquinas de estado.

* 2x PIOS com 4 máquinas de estado cada.

* DMA (Direct Memory Acess) - Transferência eficiente de dados para memória.

* 12 canais - transferindo 4 bytes em um ciclo de clock com capacidade de 50 MS/s

#### PIO - Programmable IO

* Permite programar em baixo nível com temporizações precisas, independentes dos núcleos de processamento.

* Exemplo de uso: 

	- Neopixel de uma matriz de LEDs RGB 
	- Tempos de pulso configurados para representar os valores 0 e 1 no protocolo WS2812B.

![Figura 8]()

#### DMA - Direct Memory Acess

* Transfere dados entre memória e periféricos sem depender dos núcleos de processamento.

* Exemplo prático

	- Aquisição de áudio: capturar dados de um microfone conectado ao conversor analógico digital (ADC) com alta taxa de amostragem.

![Figura 9]()

#### Níveis Lógicos permitidos nas GPIO Digitais

![Figura 10]()

#### Configurações Programáveis das GPIO Digitais

* Entrada: Pull-Up, Pull-Down

* Saída: Slew Rate, Drive Strength (IOH)

* IOH = 2, 4, 8 ou 12 mA configurável (Padrão é 4 mA)

#### Sinal PWM e o Ciclo de Trabalho (Duty Cycle)

[Duty Cycle]()

[PWM Signal]()

#### Mapas dos Sinais PWM no RP2040

* O RP2040 possui 8 geradores de PWM independentes chamados de slices.

* Cada slice contém 2 canais (A e B), totalizando 16 canais PWM.

* Todos os 30 GPIOs do RP2040 podem gerar sinais PWM, permitindo grande flexibilidade.

![Figura 12]()

* Dois canais no mesmo slice compartilham a mesma base de tempo (frequência), mas podem ter duty cycles (ciclos de trabalho) diferentes.

#### Conversor Analógico Digital de 12 Bits

* Clock do CAD: 48 MHz

* 96 ciclos de clock por conversão

* Sample rate: 500 kS/s

![Figura 13]()

![Figura 14]()

### Módulo - Placa Raspberry Pi Pico

#### Raspberry Pi Pico

* Interface USB (dados e alimentação)

* Circuito de proteção

* Reguladores de tensão

* Conectores GPIO e pinagem de fácil acesso

* Pinos SWD para depuração

* Memória Flash Externa

* Botão BOOTSEL para seleção de modos de programação

* LED verde on-board

#### Versões da Raspberry Pi Pico

![Figura 15]()

#### Componentes da Pico W

![Figura 16]()

![Figura 17]()

#### Conectividade Wi-Fi

* Chip Infineon CYW43439 integrado para Wi-Fi 802.11n

* Antena de cerâmica embutida

* GPIO23 dedicado para o controle do módulo Wi-Fi

#### Ecossistema de programação da RP Pico

* Thonny: ideal para quem quer começar com MicroPython

* Arduino IDE: ótimo para quem já está habituado à plataforma Arduino.

* Visual Studio Code + SDK: para projetos em C/C++ de maior escala ou profissionais, com acesso aos recursos do SDK oficial.

* Workwi: o simulador online para testes rápidos.

#### Simulação de hardware usando o Workwi

* Simuladores são uma ferramenta poderosa, porém seu resultado deve ser analisado com atenção. 

* A simulação é uma caricatura da realidade.

![Figura 18]()

### Kit de desenvolvimento - BitDogLab

#### Componentes 

![Figura 19]()

![Figura 20]()

#### Mapeamento das Interconexões

![Figura 21]()

#### Mapeamento das Expansões

![Figura 22]()

#### Exemplos de Código escritos em C

	- Saída digital: Blink
	- Entrada Digital: Botoes
	- PWM: LED RGB
	- IRQ + PWM: Buzzer
	- Entrada Analógica: Joystick
	- PIO: Matriz de LEDs
	- Display OLED
	- DMA: Microfone
	- Wi-Fi
	- Outros
	
* Referências

https://github.com/ubiratantavares/BitDogLab

https://github.com/raspberrypi/pico-examples

https://github.com/ubiratantavares/RPIPicoFreeRTOSExample

#### Referências

* [rp2040-datasheet.pdf](https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf)

* [Raspberry Pi Foundation](https://www.raspberrypi.org/)

* [BitDogLab](https://github.com/BitDogLab/BitDogLab)

* [BitDogLab - Uma Jornada Educativa com Eletrônica, Embarcados e IA](https://embarcados.com.br/bitdoglab-uma-jornada-educativa-com-eletronica-embarcados-e-ia/)

* [Empowering STEAM Activities With Artificial Intelligence and Open Hardware: The BitDogLab](https://ieeexplore.ieee.org/abstract/document/10500382)

## Glossário de Siglas e Recursos do RP2040

	- Introdução ao Glossário de siglas e recursos do RP2040: Este glossário foi criado para ajudar os estudantes do Embarcatech a entender melhor os recursos e as possibilidades do 
	microcontrolador RP2040. Aqui você vai encontrar explicações resumidas sobre os principais componentes, como os núcleos de processamento, memórias, protocolos de comunicação e 
	outros recursos avançados que tornam esse microcontrolador tão versátil. A ideia é que esse material sirva como apoio tanto para quem está começando quanto para quem já tem experiência 
	e quer explorar funcionalidades mais avançadas. Espero que este guia seja útil. Boa leitura e bons projetos!

	- Ver "Unidade 4  Glossario de Siglas e Recursos do RP2040.pdf"
	
## Palavras cruzadas sobre vocabulário do RP2040

	- Atividade Teórica

## Quizz - Siglas e Recursos do RP2040

	- Atividade Teórica

## 01.37M2-U4C0OIG-Guia da Unidade

1. BOAS-VINDAS E INTRODUÇÃO

Olá, estudantes! Sejam bem-vindos à Unidade 4 do curso de capacitação EmbarcaTech. O objetivo desta unidade é proporcionar uma compreensão teórica e prática sobre microcontroladores.

Os microcontroladores são dispositivos digitais que integram, em um único chip, processadores, memória e periféricos. Esses dispositivos são projetados para atuar em diversas aplicações, 
desde brinquedos simples até o controle de processos industriais, passando por sensores usados em aplicações de Internet das Coisas. Por isso, eles são amplamente utilizados em projetos 
de sistemas embarcados. Dominar as técnicas de projeto de software para microcontroladores é essencial para qualquer projetista de sistemas embarcados.

Durante esta unidade, teremos a oportunidade de realizar diversas atividades práticas utilizando um kit de desenvolvimento chamado BitDogLab. Essa ferramenta foi criada para auxiliar no ensino
de sistemas embarcados e eletrônica. A BitDogLab é baseada na popular placa Raspberry Pi Pico W, utilizada mundialmente em inúmeros projetos e produtos de sucesso. Você terá a oportunidade
de utilizar essa ferramenta em casa para aprimorar seus conhecimentos em microcontroladores. O aprendizado com essa ferramenta permitirá que você adquira maturidade para trabalhar facilmente 
com outros microcontroladores.

2. OBJETIVOS EDUCACIONAIS

O objetivo desta aula é fornecer um contexto inicial para nosso estudo de microcontroladores. Ao final, você será capaz de compreender as principais vantagens e desafios de projeto com 
microcontroladores. Além disso, entenderá como o conteúdo da Unidade 4 está organizado.

3. CONTEÚDO DA UNIDADE

Os microcontroladores têm baixo custo e consumo de energia, o que os torna ideais para diversas aplicações. Por isso, são a escolha preferida para soluções econômicas e eficientes.
Outra vantagem significativa dos microcontroladores é a simplicidade da sua programação. Atualmente, os fornecedores de semicondutores oferecem diversas bibliotecas e 
kits de desenvolvimento de software (SDKs), que abstraem a complexidade dos circuitos internos, proporcionando aos desenvolvedores interfaces amigáveis e fáceis de
utilizar.

Por outro lado, existem desafios no desenvolvimento de software para microcontroladores. Esses dispositivos apresentam várias limitações, como restrições de poder de processamento, memória e energia. 
Um bom desenvolvedor de software embarcado sabe explorar ao máximo os recursos dos microcontroladores, apesar dessas limitações, para criar produtos que atendam a critérios rigorosos de qualidade 
e restrições de tempo real.
 
4. REVISANDO O CONTEÚDO

Agora, vamos revisar os conteúdos que você estudará nas aulas da Unidade 4, que está dividida em oito capítulos:

* Capítulo 1: Introdução dos principais conceitos de desenvolvimento de software para microcontroladores e apresentação da nossa placa didática.

* Capítulos 2 e 3: Uso do módulo GPIO para controlar diversos componentes, como chaves, LEDs e teclados matriciais.

* Capítulo 4: Compreensão do mecanismo de interrupções e como ajuda a lidar com eventos de entrada e saída. 

* Capítulo 5: Como configurar o clock e os temporizadores do sistema. 

* Capítulo 6: As interfaces de comunicação serial.

* Capítulo 7: PWM, um módulo muito útil para controlar motores e conversores de potência.

* Capítulo 8: Como fazer a interface entre o mundo digital e o analógico por meio dos conversores digitais-analógicos.

5. EM RESUMO

Você aprendeu que os microcontroladores são dispositivos digitais usados em diversas aplicações embarcadas. Viu que seu baixo custo e facilidade de programação os tornam uma solução atraente para
muitos problemas, incluindo aqueles encontrados em aplicações de Internet das Coisas. Por fim, vimos que, apesar de suas vantagens, existem vários desafios a serem enfrentados ao trabalharmos
com essa tecnologia.

Revise todo o material com atenção e não deixe de realizar as atividades propostas na plataforma. Esta é sua chance de entender uma tecnologia que está na base de muitos produtos que utilizamos 
no nosso dia a dia. Contamos com sua participação ativa nesta jornada de aprendizado. Vamos em frente!

6. REFERÊNCIAS

* [RASPBERRY PI LTD. Raspberry Pi Pico W Datasheet: An RP2040-based microcontroller board with wireless. 2024](https://datasheets.raspberrypi.com/picow/pico-w-datasheet.pdf)

* [RASPBERRY PI LTD. Raspberry Pi Pico C/C++ SDK. 2024](https://datasheets.raspberrypi.com/pico/raspberry-pi-pico-c-sdk.pdf)

* [RASPBERRY PI LTD. RP2040 Datasheet. 2024](https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf)

* [BitDogLab. Manual BitDogLab](https://github.com/BitDogLab/BitDogLab/tree/main/doc)
