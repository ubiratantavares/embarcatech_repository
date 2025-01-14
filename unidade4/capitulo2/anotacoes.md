# Unidade 4 - Microcontoladores

## Capitulo 2 - Práticas de Portas de Entrada e Saída - GPIO

### Sumário

* Revisão: Plataforma BitDogLab
* GPIOs - General Purpose Input/Outputs
* RaspberryPi Pico - Explorando os GPIOs com BitDogLab
* Detalhando os Exercícios Práticos
	- Controle de LED e Leitura de Botão
	- Controle de LEDs RGB e Leitura de Dois Botões
	- Leitura de Teclado Matricial

### Revisão: Plataforma BitDogLab

* BitDogLab
	- Componentes: 
		- Bateria
		- Display OLED 128x64 pixels
		- Matriz de LEDs coloridos
		- Microfone
		- Joystick
		- Botões
		- Buzzer
		- Conectores de expansão
		
### GPIOs - General Purpose Input/Outputs

![Figura 1](https://github.com/ubiratantavares/embarcatech_repository/blob/main/unidade4/capitulo2/gpios.png)

* Características
	- O RP2040 tem 30 pinos de entrada/saída de uso geral (GPIO)
	- Conversores - ADC/DAC
	- Controladores de Interrupção
	- Embora seja possível configurar as propriedades dos pinos via software, alguns pinos já vêm configurados por padrão.
	- Além disso, alguns pinos possuem características específicas que os tornam mais ou menos adequados para diferentes projetos.

* Tipos de pinos e suas funções
	- A escolha do pino dependerá das necessidades específicas de um projeto.
	- Segue abaixo um guia de GPIO:

![Figura 2](https://github.com/ubiratantavares/embarcatech_repository/blob/main/unidade4/capitulo2/tipos_pinos_gpios.png)

### RaspberryPi Pico

* Explorando os GPIOs com BitDogLab

![Figura 3](https://github.com/ubiratantavares/embarcatech_repository/blob/main/unidade4/capitulo2/componentes_pinos_gpios.png)

* Efeito que ocorre ao pressionar o botão 1 vez: Importante entender antes de fazer as práticas.

![Figura 4](https://github.com/ubiratantavares/embarcatech_repository/blob/main/unidade4/capitulo2/efeito_bounce.png)
