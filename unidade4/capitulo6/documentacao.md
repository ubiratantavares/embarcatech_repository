# Capitulo 6 - Guia de Interfaces de Comunicação com RP2040 / Raspberry Pi Pico W

Os protocolos UART, SPI e I2C são métodos de comunicação serial usados para a troca de dados entre o Raspberry Pi Pico W (ou outros microcontroladores) 
e dispositivos periféricos, como sensores, atuadores e módulos de comunicação. 

Cada protocolo apresenta características específicas que o tornam mais adequado para diferentes tipos de aplicações.

Os protocolos UART, SPI e I2C são essenciais porque permitem que o Raspberry Pi Pico W interaja com outros componentes eletrônicos, 
formando sistemas embarcados completos e robustos. Sua escolha depende de fatores como velocidade, número de dispositivos conectados, simplicidade de implementação e requisitos de hardware.

Os principais usuários são desenvolvedores de sistemas embarcados, engenheiros eletrônicos e hobistas que trabalham com o Raspberry Pi Pico W em aplicações de automação, 
Internet das Coisas (IoT), robótica e projetos educacionais.

Esses protocolos podem ser usados em qualquer aplicação que envolva o Raspberry Pi Pico W, como:

	- Sistemas de monitoramento ambiental, utilizando sensores conectados via I2C.
	- Projetos de controle de motores e displays gráficos usando SPI.
	- Comunicação com módulos Bluetooth ou GPS usando UART.

A escolha do protocolo deve ser feita na etapa de design do sistema, considerando as especificações do hardware, a quantidade de dispositivos periféricos e os requisitos de comunicação, 
como velocidade e confiabilidade.

Cada protocolo é configurado e utilizado de forma distinta no Raspberry Pi Pico W, geralmente por meio da biblioteca MicroPython ou do SDK em C/C++.

Os custos dependem do número e do tipo de dispositivos conectados. 

Como o Raspberry Pi Pico W possui suporte nativo aos três protocolos, a implementação geralmente não requer hardware adicional significativo, 
além de resistores pull-up para o barramento I2C.


## Objetivos

* Programar e conectar, corretamente, um sistema embarcado com outros sistemas embarcados ou outros dispositivos com esses protocolos de comunicação.

## Raspberry Pi Pico W/RP2040

* Interfaces de comunicação: UART, SPI e I2C

## Contexto de Interfaces Seriais

* UART (Universal Asynchronous Receiver-Transmitter)

	-  Comunicação serial simples e assíncrona, usada para conectar dispositivos que precisam trocar pequenos volumes de dados em taxas moderadas.

	- É amplamente suportado, simples de implementar e não requer clock externo, sendo útil para comunicação ponto a ponto.

	- Configuração via pinos GPIO com as funções machine.UART (MicroPython) ou uart_init (C/C++).

	- Necessário definir parâmetros como baud rate, bits de parada e paridade.

![imagem1.png]()

![imagem16.png]()

* SPI (Serial Peripheral Interface)

	- Comunicação síncrona, ideal para alta velocidade e conexão com múltiplos dispositivos, como displays ou conversores analógico-digitais.

	- Oferece alta velocidade e eficiência para sistemas onde a largura de banda é crítica.

	- Exige configuração dos pinos para MOSI, MISO, SCLK e CS.

	- Utiliza as funções machine.SPI (MicroPython) ou spi_init (C/C++) para definir frequência e modo de operação.	

![imagem2.png]()

![imagem8.png]()

![imagem9.png]()

![imagem10.png]()

![imagem17.png]()

	- Comunicação síncrona e multiponto, frequentemente usada para conectar vários dispositivos em um barramento único e eficiente, como sensores em sistemas embarcados.

* I2C (Inter-Integrated Circuit)

	- Permite conectar vários dispositivos usando menos pinos, economizando espaço e recursos.

	- Configura pinos para SDA e SCL com a função machine.I2C (MicroPython) ou i2c_init (C/C++).

	- É preciso conhecer os endereços dos dispositivos conectados ao barramento.

![imagem3.png]()

## I2C

![imagem11.png]()

![imagem12.png]()

![imagem13.png]()

![imagem14.png]()

![imagem15.png]()

![imagem17.png]()

## Revisão - Capítulo 5

![imagem4.png]()

* Pico Examples (Lines 13 - 21)

![imagem5.png]()


![imagem6.png]()

![imagem7.png]()

