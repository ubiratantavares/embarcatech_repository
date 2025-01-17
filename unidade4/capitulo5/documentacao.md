# Capitulo 5 - Clock e Interruptores

## Objetivos

	- Compreender o funcionamento do Clock e Temporizadores

	- Configurar o módulo de Clock

	- Configurar os módulos de Temporizadores

	- Aplicar os conhecimentos de Interrupções e Temporizadores

## Revisão

	- Usar e configurar as interrupções no RP2040.

	- Controlar os pinos de entrada e saída (GPIO).

	- Desenvolvimento de software em microcontroladores.

## Visão Geral

### O que é o Clock?

	- O clock em um microcontrolador é um sinal elétrico periódico que serve como referência de tempo para a execução de operações internas.
	Ele sincroniza a sequência de instruções, permitindo que o microcontrolador realize tarefas de forma coordenada e precisa.

	- O clock é gerado por um oscilador (interno ou externo) e sua frequência, medida em hertz (Hz), que determina quantas operações o microcontrolador pode executar por segundo.
	Uma frequência mais alta significa maior velocidade de processamento, mas também pode resuktar em maior consumo de energia. Assim, a escolha da frequência do clock 
	é crucial para otimizar o desempenho e a eficiência do sistema.

### O que é o Temporizador?

	- Um temporizador em um microcontrolador é um componente que permite medir intervalos de tempo intervalor de tempo
	ou gerar eventos em tempos específicos. Ele pode ser usado para diversas funções, como:

		- **Contagem de Intervalos**: O temporizador pode contar pulsos de um clock interno, permitindo medir intervalos de tempo com precisão.

		- **Geração de Interrupções**: Pode gerar interrupçoes após um certo tempo, permitindo que o microcontrolador execute outras tarefas enquanto aguarda.

		- **Controle de Frequencia**: Usado em aplicações que requerem sinais de PWM (modulação por largura de pulso) para controle de motores, LEDs, etc.

		- **Divisão de Frequência**: Permite dividir a frequência de um sinal, sendo útil em diversas aplicações de controle.


## Clock no RP2040

### Configurações do clock

	- No microcontrolador RP2040, utilizado no Raspberry Pi Pico e no Raspberry Pi Pico W, o sistema de clock é altamente configurável.
	Ele utiliza um oscilador de cristal externo (ou uma fonte de clock externa), um oscilador interno (clocks RC) e um sistema de Phase-Locked Loops (PPLs) para gerar os diversos
	clocks necessários para o funcionamento dos periféricos.

	- A configuração dos clocks no RP2040 é feita por meio de registradores específicos, que permitem:

		- Selecionar a fonte de clock para cada um dos módulos.

		- Configurar os divisores de clock para ajustar a frequência de saída.

		- Ativar/Desativar clocks para economia de energia.]

	- Principais configurações disponíveis:

		- Fontes de Clock:

			- XOSC (External Crystal Oscillator)

			- ROSC (Ring Oscillator)

			- CLK_SYS (System Clock)

			- CLK_PERI (Peripheral Clock)

			- CLK_USB

			- CLK_ADC

			- CLK_RTC

		- PPLs (Phase-Locked Loops)

			- PPL_sys

			- PLL_USB

		
		- Divisores de Clock:

			- CLK_REF (Clock de Referência)

			- CLK_SYS

			- CLK_PERI (Peripheral Clock)

			- CLK_USB

			- CLK_ADC

			- CLK_RTC

		- Módulo Wi-Fi:

			- Chip adicional de Wi-Fi (CYW43439)

			- Configuração de clock específica que não afeta diretamente o sistema de clocks do RP2040

### Visão Geral do Clock

![visao_geral_clock.png]()
		
## Temporizadores no RP2040

	- O RP2040 oferece uma variedade de temporizadores que podem ser usados para diferentes propósitos:

		- **Temporizadores de Hardware (Timer Hardware)**: O RP2040 tem vários temporizadores de hardware que podem ser usados para gerar interrupções temporizadas
		ou medir o tempo com precisão. Esses temporizadores são configuráveis e oferecem uma ampla gama de possibilidades para gerar eventos baseados em tempo.

		- **Temporizador de Sistema (SysTick)**: Este temporizador é útil para gerar interrupções regulares.
		É frequentemente usado para implementar sistemas de tempo real ou para criar intervalos regulares para execução de tarefas.

		- **Temporizadores de Pulse Width Modulation (PWM)**: O RP2040 possui blocos de PWM que permitem gerar sinais com PWM com precisão. Isso é útil para controlar servomecanismos,
		motores e outros dispositivos baseados em PWM. Esse assunto será visto no cappitulo 7.

		- **Temporizadores de Contagem (Counters)**: O RP2040 pode ser configurado para contar eventos ou pulsos, o que é útil para aplicações que requerem a medição precisa de frequência
		ou eventos.
		
## Exemplos de Código

### Exemplo prático 01 - clock

### Exemplo prático 02 - temporizador de sistema

### Exemplo prático 03 - temporizador de hardware

### Exemplo prático 04 - temporizador de sistema para controlar LED

### Exemplo prático 05 - temporizador de hardware para controlar LED

### Exemplo prático 06 - pisca LED verde com temporizador 

### Exemplo prático 07 - pisca LED azul com temporizador repetitivo

### Exemplo prático 08 - pisca LED VERMELHO com temporizador contador

### Comparação entre os exemplos práticos 2 e 3

	- **Abordagem**: o primeiro código, utilzando temporizador de sistema, utiliza uma abordagem manual de controle do tempo, enquanto o segundom utilizando temporizador de hardware, usa
	um temporizador automático.

	- **Complexidade**: o primeiro código é mais complexo devido ao gerenciamento manual do tempo. Já o segundo código, é mais simples e modular, com separação clara entre a lógica
	de temporização e o loop principal.

	- **Conclusão**: ambos os códigos têm a mesma funcionalidade de imprimir uma mensagem a cada segundo, mas a implementação do segundo código é mais limpa e eficiente.
	Utilizando uma abordagem de temporização que evita a necessidade de controle manual de tempo. O primeiro código oferece maia flexibilidade, mas à um custo de complexidade. 
	A escolha entre os dois depende das necessidades específicas do seu projeto.


## Principais Pontos

	- Clock e sua importância.

	- Temporizador e sua importância.

	- Plataforma BitDogLab.

	- Plataforma Worki.
	
	- Exercícios práticos.
