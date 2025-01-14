Introdução à programação do Raspberry Pi Pico

https://www.nabto.com/raspberry-pi-pico-programming/


Um Raspberry Pi Pico é uma opção popular de microcontrolador (MCU) para amadores e profissionais de IoT. Ele ocupa um lugar especial no mundo da IoT por causa de seu pequeno tamanho físico emparelhado com poder de processamento relativamente alto e baixo consumo de energia. Adicione a isso a enorme adoção mainstream de seus irmãos maiores (Raspberry Pi 1 a 4) tornando o hardware Raspberry Pi bem conhecido em todo o mundo da IoT. O Pico também é excepcionalmente barato, especialmente comparado aos irmãos, e você pode começar a usar um em apenas alguns minutos. Você não precisa de amplo conhecimento de programação, e há documentação suficiente online para mantê-lo ocupado experimentando por semanas a fio. 

Continue lendo para saber mais sobre recursos, alternativas, projetos e recursos para programar um Raspberry Pi Pico.


Configure um dispositivo IoT simulado no seu PC em minutos.
Nossas demonstrações full-stack dão a você acesso à Plataforma Nabto para que você possa experimentá-la agora. Somos especializados em conectividade P2P segura e de baixa latência. Obtenha o aplicativo de demonstração para experimentá-lo.

Obter demonstração do aplicativo
Família e recursos do Raspberry Pi Pico
O Raspberry Pi Pico não é apenas um microcontrolador. É uma família de placas MCU de alto desempenho. Elas incluem o Raspberry Pi Pico, Pico H, Pico W e Pico WH. O Pico e o Pico H são quase idênticos, a única grande diferença é que o Pico H vem com conectores pré-soldados – ou seja, lugares para conectar fios – enquanto o Pico não. Então, se você quiser conectar fios a um Pico normal, você mesmo terá que soldar os conectores.

O Pico W e o Pico WH adicionam um módulo Wi-Fi integrado que permite que o dispositivo se conecte à Internet. A única diferença entre o Pico W e o Pico WH é, novamente, que o WH tem headers pré-soldados.

Todas as quatro opções têm as seguintes características:

Microcontrolador RP2040
Processador Dual-Core Arm Cortex M0+
Velocidade de clock de até 133 MHz
264 KB de SRAM e 2 MB de memória flash
Uma porta USB 1.1
Modos de baixa potência ou inativos
26 pinos de entrada/saída de uso geral (GPIO)
Sensor de temperatura
2 x SPI, 2 x I2C, 2 x UART, 3 x ADC
Oito máquinas de estado de E/S programáveis
Todos os quatro tipos de Pico também têm um LED integrado, o que será importante para seu primeiro projeto. Se você já tem alguma experiência com IoT e MCUs, sinta-se à vontade para pular para a próxima seção. Caso contrário, aqui está um resumo do que alguns desses recursos significam e por que eles são importantes.

Vamos começar com o MCU. A maioria dos designs do Raspberry Pi são computadores de placa única (SBCs). Eles têm alto poder de processamento para seu tamanho e podem executar as mesmas ações básicas que seu computador desktop. Eles normalmente usam o RaspberryOS, que é baseado no sistema operacional Linux. Por outro lado, uma placa de microcontrolador não tem a capacidade de executar um sistema operacional completo. Então, enquanto em seu desktop ou laptop, você pode abrir vários aplicativos, um MCU executará apenas um aplicativo por vez.

Considere uma câmera de segurança inteligente padrão. Sua única função é transmitir vídeo, então não precisa de um SO completo. Em vez disso, o sistema operacional Raspberry Pi Pico será um sistema operacional em tempo real (RTOS) que executa apenas uma ação por vez.

No que diz respeito a um processador, os processadores ARM são extremamente populares para IoT e têm o mais alto nível de eficiência energética entre os tipos de processadores mais comuns. O M0+, que é o processador que o Raspberry Pi Pico emprega, é ainda mais eficiente do que o processador ARM típico. A velocidade de clock de 133 MHz, ou seja, a rapidez com que o processador executa instruções, não é especialmente rápida. Ainda assim, essa velocidade é mais do que adequada para uma aplicação típica de IoT. Para referência, um dispositivo de fitness inteligente com vários sensores e funções pode ter uma velocidade de clock máxima absoluta de cerca de 300 MHz.

Quando as especificações mostram 264 KB de SRAM e 2 MB de memória flash, o que isso significa é que o dispositivo tem 264 KB de memória que só permanece no dispositivo enquanto há energia. Quando o dispositivo é desconectado, desligado ou a bateria acaba, essa memória é destruída. A memória flash, por outro lado, é a memória que permanece no dispositivo mesmo depois que a energia é desligada. Em outras palavras, é o repositório de armazenamento de dados do dispositivo.

O Raspberry Pi Pico também tem 26 pinos GPIO. Um pino é basicamente um pequeno furo que permite conectar dispositivos externos. Por exemplo, há um pino que permite conectar uma luz LED extra à placa, se você quiser.

SPI, I2C, UART e ADC são tipos diferentes de protocolos/formatos de entrada. Ter uma grande variedade é o que permite que você use o Pico para tantos projetos e aplicações diferentes. Finalmente, uma máquina de estado de E/S programável é um componente de entrada/saída que você pode programar para todas as funções e protocolos diferentes. Ter oito torna o Raspberry Pi Pico particularmente flexível.

Alternativas ao Raspberry Pi Pico
Embora o Raspberry Pi Pico se destaque como uma ótima opção para seus projetos, há muitas outras opções também. Veja como elas se alinham contra o Pico.

Raspberry Pi Pico vs. Arduino Uno
Comparado à placa Arduino Uno, que tem um tamanho físico similar, o Raspberry Pi Pico tem consideravelmente mais poder de processamento e opções de entrada. Por exemplo, enquanto o Pico tem uma velocidade máxima de clock de 133 MHz, o Arduino Uno só vai até 16 MHz. Ele tem apenas 32 KB de RAM e apenas 16 KB de memória flash. O Uno também tem menos pinos de E/S do que o Pico, maior consumo de energia e um preço mais alto. O Arduino Uno ainda é uma escolha popular, em grande parte porque é compatível com o grande conjunto de ferramentas de código aberto, bibliotecas e o Arduino Integrated Development Environment (IDE) do Arduino.

Raspberry Pi Pico vs. Zero
O Raspberry Pi Zero é um computador completo por si só, com um microprocessador integrado (MPU) em vez de um MCU. Ele pode executar vários aplicativos simultaneamente, e tem uma alta velocidade de clock e 512 MB de RAM junto com 8 GB de memória flash, mais 40 pinos de E/S para os 28 do Pico. É também o menor Raspberry Pi MPU disponível. No entanto, ele tem um consumo de energia consideravelmente maior do que o Raspberry Pi Pico, e é consideravelmente mais caro: US$ 15, enquanto o Pico custa apenas US$ 4.

Raspberry Pi Pico vs. ESP32
A família de MCUs ESP32 da Espressif é pequena e tem cerca de duas vezes o poder de processamento e a velocidade do Pico. Embora as especificações exatas variem entre os MCUs da família, eles geralmente têm dois pinos de E/S adicionais e o dobro da memória flash em comparação ao Pico. No entanto, eles também consomem o dobro de energia e são quase duas vezes mais caros. Então o Pico é provavelmente preferível para um primeiro projeto. Além disso, o ESP32 é um projeto comercial, enquanto o Pico é apoiado pela Raspberry Pi Foundation, uma instituição de caridade registrada com o objetivo de educar.

Programando um Raspberry Pi Pico
Vamos considerar um projeto inicial simples. Assim como os programadores de software tradicionalmente começam escrevendo um programa simples para imprimir “Hello World”, os programadores de hardware tradicionalmente começam escrevendo um programa simples para fazer uma luz piscar e apagar. Neste caso, você configurará o Raspberry Pi Pico para piscar uma luz em intervalos definidos.

Para fazer isso, você precisará escrever algum código. Um Raspberry Pi Pico responde a uma variedade de linguagens de codificação, incluindo C, C++ e MicroPython. MicroPython é uma versão mais leve e simples do Python tradicional, e é a linguagem mais comum usada por amadores do Raspberry Pi Pico. Então, se você já conhece Python, deve ser fácil para você começar com MicroPython no Raspberry Pi Pico, e você não deve ter problemas com este projeto inicial.

O que você vai precisar: hardware
Para este projeto, você não precisará de nada além da placa e de um cabo USB. Você usará seu computador para fornecer energia e programar o dispositivo. Se quiser continuar usando o Pico para outros projetos, no entanto, precisará conectá-lo a uma fonte de energia externa para que ele continue funcionando quando não estiver conectado ao seu computador.

Como alternativa, você pode obter um kit inicial Raspberry Pi Pico na Amazon ou em outro site. O kit normalmente fornecerá a placa MCU Raspberry Pi Pico, um cabo USB, uma breadboard, alguns LEDs e resistores e recursos tutoriais de algum tipo. Uma breadboard é apenas uma placa de plástico com furos. Você pode conectar o Pico a ela e, em seguida, conectar outros componentes elétricos à placa também, incluindo uma fonte de energia.

O que você vai precisar: software
Você também precisará ter certos softwares instalados no seu computador para programação do Raspberry Pi Pico. A maioria dos projetos usa o Thonny Integrated Development Environment , que você precisará baixar e instalar. Em seguida, baixe o arquivo MicroPython para o seu computador e você estará pronto para começar a programar.

Etapa 1: Conecte-se ao seu computador
Conecte seu cabo USB à porta USB do dispositivo. Em seguida, pressione o pequeno botão branco na placa Raspberry Pi Pico – chamado de botão de seleção de inicialização – e conecte a outra extremidade do USB ao seu computador enquanto ainda mantém o botão pressionado. Você pode soltar o botão depois que o dispositivo estiver conectado ao seu computador. No seu explorador de arquivos, você deve ver um novo dispositivo conectado chamado “RP1-RP2”.

Etapa 2: Instale o MicroPython no Pico
Copie o arquivo MicroPython que você baixou. Abra o dispositivo RP1-RP2 no seu explorador de arquivos e cole o arquivo MicroPython lá.

Etapa 3: Defina o intérprete para Thonny
Abra o software Thonny. Na barra de ferramentas Executar, clique em “Selecionar Interpretador”. Haverá um menu suspenso com muitas opções, uma das quais será “MicroPython (Raspberry Pico)”. Selecione-o e clique em “OK”.

Etapa 4: Escreva seu programa
Digite ou cole o seguinte código na janela principal do software Thonny:

máquina de importação

importar utime

led = máquina.Pin(25, máquina.Pin.OUT)

enquanto Verdadeiro:

led.valor(1)

utime.sleep(1)

led.valor(0)

utime.sleep(1)

Este código fará com que a luz LED fique acesa por um segundo e depois apagada por um segundo em um loop infinito, ou até que o dispositivo seja desconectado.

Etapa 5: Execute o programa
Em seguida, clique no botão executar, que tem um símbolo de reprodução nele. Um pop-up perguntará onde você deseja salvar o arquivo. Clique em “Raspberry Pi Pico”. Ao nomear o arquivo, certifique-se de adicionar .py no final para que o MCU reconheça a linguagem como MicroPython. Você pode, por exemplo, chamá-lo de LED.py. No entanto, se quiser que o arquivo seja executado automaticamente sempre que conectar o dispositivo, chame-o de main.py. Isso dirá ao Pico que é o único programa ao qual ele precisa prestar atenção e que ele deve executá-lo imediatamente na inicialização. Em seguida, clique em “OK”. Agora sua luz deve estar piscando em intervalos regulares. Parabéns por concluir com sucesso seu primeiro projeto de programação no seu Raspberry Pi Pico.

Mais projetos Raspberry Pi Pico
Claro, você não precisa parar em apenas fazer uma piscada de luz. Há alguns outros ótimos projetos iniciais listados abaixo.

Câmera Raspberry Pi Pico
Você pode configurar o Raspberry Pi Pico para executar uma câmera inteligente e transmitir vídeo. A Nabto tem um aplicativo de streaming de vídeo que ignora firewalls e fornece o menor nível de latência possível. Leia nosso guia para uma explicação detalhada de como conectar a câmera de vídeo Raspberry Pi ao seu smartphone para que você possa controlá-la diretamente por meio de uma conexão segura. O aplicativo e o SDK da Nabto são de código aberto, então você pode fazer alterações conforme desejar.

Exibição Raspberry Pi Pico
Um projeto interessante para um Raspberry Pi Pico é anexar um display eletrônico diretamente à placa e programar o display. Você pode usar o display para contar segundos como um cronômetro, ou pode usá-lo para exibir a temperatura com base nos dados do sensor de temperatura. Você pode até mesmo programar o display para mostrar certas formas em certos intervalos. No entanto, isso exigirá alguma fiação e ferramentas extras para funcionar corretamente, e você precisará de um conhecimento mais avançado de Python.

Controlador lógico programável (PLC) Raspberry Pi Pico
Um controlador lógico programável (PLC) é um pequeno dispositivo que pode automatizar certos processos industriais. Por exemplo, ele pode automatizar tarefas repetitivas realizadas por máquinas em uma fábrica automotiva. Você pode criar uma versão simples de um PLC com um Raspberry Pi Pico usando um software especial de código aberto chamado Beremiz4Pico , embora seu dispositivo tenha algumas limitações em comparação a um PLC típico de nível industrial. A maioria dos PLCs tem mais pinos de E/S do que o Pico para oferecer suporte a funcionalidade aprimorada em uma variedade de casos de uso de automação.

Considerações finais
O Raspberry Pi Pico é uma opção barata e fácil para qualquer coisa, desde aprender programação até prototipagem e criar dispositivos IoT do zero. Seu design flexível fornece infinitas possibilidades para projetos que o manterão ocupado por algum tempo.
