Embarcados - Raspberry Pi Pico W

https://embarcados.com.br/placa/raspberry-pi-pico-w/


Raspberry Pi Pico W
05/12/2023
Sthefania Fernandes

Descrição da placa:
Baseada no mesmo microcontrolador da sua antecessora, o RP2040, essa nova versão adiciona um módulo Wi-Fi 4 (802.11n) + Bluetooth 5.2 da Infineon. A Pico W mantém compatibilidade com a Pi Pico, mantendo o mesmo form factor e pinagem (embora não tenha sido adicionado o botão de reset tão solicitado pelos usuários).

Uma diferença é que o LED de uso geral está conectado ao módulo wireless, porém ainda é possível controlá-lo através do SDK. Outra diferença está na posição do conector Serial Wire Debug (SWD). Ele foi deslocado para dentro da placa. Esse é um detalhe a ser avaliado caso se queira usar a Pico W em uma placa desenvolvida para Pi Pico.

Raspberry Pi Pico W
Figura 1: Placa Raspberry Pi Pico W
 

É importante lembrar que a placa não acompanha barras de pinos, pois existem diversas formas de utilização. É possível utilizar a barra de pinos 180º macho, a barra de pinos 180º fêmea, a barra de 40 pinos 90º ou mesmo soldar fios diretamente nos furos dos GPIOs para conexão.

Suporte de software
O Pico SDK já suporta a rede sem fio. A pilha de rede é construída em com lwIP e usa libcyw43 de Damien George (MicroPython). Por padrão, a libcyw43 é licenciada para uso não comercial, mas os usuários do Pico W e qualquer outra pessoa que construa seu produto em torno de RP2040 e CYW43439 se beneficiam de uma licença gratuita de uso comercial.

Como o desenvolvedor da libcyw43 foi o Damien George, é natural que o Micropython também já suporte a rede sem fio.

Como mencionado acima, o módulo CYW43439 também possui bluetooth, porém ainda não há suporte de software para essa funcionalidade.

Especificações
Tipo
Microcontrolador
Fabricante
Raspberry
Preço
R$ 79,00
Dimensões
51mm × 21mm
Software
Arduino IDE, Thonny IDE
Clock
133MHz
Microcontrolador
RP2040 (Silicon Designed by Raspberry Pi)
Memória RAM
264kB
Memória Flash
2MB
GPIOs
26 GPIOs multifuncionais
Periféricos
2x SPI, 2x I2C, 2x UART
Conector de Expansão
Wireless
WiFi 2.4GHz 802.11n
Vídeo
Ethernet
USB
micro-USB
Tensão de alimentação
5V USB VBUS
Carregador de bateria
Tensão de operação
3.3V
Miscelâneas
Sensor de temperatura, Bluetooth 5.2
Pinos:

Figura 2: Pinout
Documentação:
Livro gratuito: Começando com a Pico (em inglês)

Datasheet da placa

Datasheet do processador RP2040

Documentação SDK C/C++

Documentação SDK Python

Pinagem da placa

Conectando a Pico W à Internet (em inglês)

Arquivos do Hardware Design
