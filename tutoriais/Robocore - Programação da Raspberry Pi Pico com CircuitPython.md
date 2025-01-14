https://www.robocore.net/tutoriais/programacao-raspberry-pi-pico-circuitpython?srsltid=AfmBOorVG-SuviU_ZReKTXUo42eKR2pjGdNQHsEjQ4z9C0jMz1E5gDES



Robocore - Programação da Raspberry Pi Pico com CircuitPython


Introdução
CircuitPython é um interpretador Python baseado no MicroPython e que atualmente é apoiado majoritariamente pela Adafruit. Esse interpretador visa facilitar a introdução de iniciantes à programação em Python de placas microcontroladas como a Pico, por exemplo.

Neste tutorial você verá como programar a Raspberry Pi Pico usando CircuitPython pelo Mu Editor, gravando o exemplo "Blink" para a placa.

Lista de Materiais
Configurações Iniciais
Antes de programar a Raspberry Pi Pico com CircuitPython, precisamos gravar o firmware do interpretador na placa e instalar a IDE onde os códigos serão escritos.

Gravação do Firmware
Para gravar o firmware do CircuitPython na sua Pico, primeiramente baixe o arquivo contido no botão abaixo.

 Download do Firmware para CircuitPython
Com o arquivo baixado, conecte a sua placa no seu computador pressionando o botão "BOOTSEL" para que a placa entre em modo de gravação de firmware, como no GIF abaixo.

Inicialização da Placa em Modo de Gravação de Firmware
Fonte: Raspberry Pi
Deste modo, a placa será reconhecida como um disco removível de nome "RPI-RP2" no seu computador, basicamente como um pendrive. Neste momento, copie e cole o arquivo UF2 baixado dentro da pasta aberta da placa, ou então envie o arquivo para a placa, como mostrado na imagem abaixo.

envio-arquivo-firmware-placa
Envio do Arquivo de Firmware para a Placa
Assim que a cópia do arquivo for finalizada, a placa já será reconhecida novamente como um disco removível, sem a necessidade de reiniciá-la, mas desta vez com o nome "CIRCUITPY" e com alguns arquivos adicionais do firmware gravado, como na próxima imagem.

arquivos-adicionais-firmware
Arquivos Adicionais do Firmware
Essa mudança nos arquivos da placa indica que o firmware foi gravado corretamente, e que podemos prosseguir com a gravação.

Configuração da IDE
Agora a placa já está pronta para receber os códigos do CircuitPython e o próximo passo para isso é a instalação do Mu Editor, uma IDE da linguagem Python voltada para iniciantes. Você pode baixar o Mu Editor acessando a sua página de downloads através do botão abaixo. Basta baixar o arquivo instalador para o seu sistema operacional (infelizmente o Mu Editor não suporta mais computadores com arquitetura de 32 bits), e então seguir os passos para a instalação. Para computadores Linux, a instalação é feita através do terminal de comandos, e você pode seguir o passo a passo da instalação através deste link.

 Download do Mu Editor
Assim que o programa estiver instalado, abra-o para que possamos gravar um código na Pico (a primeira inicialização do programa pode levar alguns minutos). Com o programa aberto, temos que alterar o interpretador do editor clicando sobre o botão "Mode", como demarcado na imagem abaixo. Talvez o programa abra uma janela dizendo que reconheceu um dispositivo "CircuitPython" e perguntando se você deseja alterar o modo de edição, mas como vamos fazer essa alteração manualmente, apenas pressione o botão "Cancelar" desta janela.

janela-mu-editor-localizacao-botao-mode
Janela do Mu Editor e Localização do Botão "Mode"
Ao pressionar esse botão, será aberta uma janela com os interpretadores disponíveis na IDE, como na próxima imagem.

janela-selecao-interpretador
Janela de Seleção do Interpretador
Com esta janela aberta, você perceberá que o Mu Editor é iniciado pela primeira vez com o interpretador Python 3 selecionado por padrão. Como vamos gravar um código na Raspberry Pi Pico, selecione a opção "RP2040", como demarcado na imagem acima, e então pressione o botão "OK" para salvar a alteração.

Código "Blink"
Com as configurações iniciais finalizadas, digite o código a seguir na IDE.

1
#############################################################################################
2
# RoboCore - Primeiros Passos com a Raspberry Pi Pico com CircuitPython
3
# Faz o LED conectado ao GPIO 25 (LED interno da placa) piscar de 1 em 1 segundo.
4
#############################################################################################
5
​
6
# Adiciona as bibliotecas ao codigo
7
from time import sleep
8
import board
9
import digitalio
10
​
11
# Declara a variavel "led" conectada ao LED interno da placa
12
led = digitalio.DigitalInOut(board.LED)
13
​
14
# Configura o pino conectado a variavel "led" como uma saida do sistema
15
led.direction = digitalio.Direction.OUTPUT
16
​
17
# Repete infinitamente
18
while True:
19
    led.value = True  # Acende o LED
20
    sleep(1)  # Aguarda 1 segundo
21
    led.value = False  # Apaga o LED
22
    sleep(1)  # Aguarda 1 segundo
Entendendo o Código
O código inicia com a adição da função "sleep" da biblioteca "time" da linguagem Python e com a adição das bibliotecas "board" e "digitalio", que são responsáveis por "mapear" os pinos da placa do interpretador selecionado e controlar as portas digitais da placa, respectivamente.

Feito isso, a variável led é criada e atribuída ao pino digital conectado ao LED interno da Pico através do comando led = digitalio.DigitalInOut(board.LED). Em seguida, o pino atribuído à variável led é configurado como uma saída do sistema graças ao comando led.direction = digitalio.Direction.OUTPUT.

Já na repetição do código (função while True), apenas acendemos (led.value = True) e apagamos (led.value = False) o LED interno da placa, com um intervalo de 1 segundo (sleep(1)) entre cada mudança de estado (de "True" - nível lógico alto - para "False" - nível lógico baixo - e vice versa).

1
# Repete infinitamente
2
while True:
3
    led.value = True  # Acende o LED
4
    sleep(1)  # Aguarda 1 segundo
5
    led.value = False  # Apaga o LED
6
    sleep(1)  # Aguarda 1 segundo
Salvar e Executar o Código
Com o código digitado no Mu Editor, pressione o botão "Save", demarcado na imagem abaixo, para salvar o arquivo na placa.

botao-salvar-arquivo
Botão para Salvar o Arquivo
Ao pressionar esse botão, será aberta a janela do "Gerenciador de Arquivos" do seu computador, como se estivesse salvando o arquivo de outro programa. Neste momento, abra o disco da Raspberry Pi Pico no seu computador, e então salve o arquivo com um nome ("blink", por exemplo) neste diretório, como feito na próxima imagem.

salvamento-codigo-placa
Salvamento do Código na Placa
Assim que o código estiver salvo, pressione o botão "Run", como demarcado na imagem abaixo, para que o código seja executado.

botao-executar-codigo
Botão para Executar o Código
Após pressionar este botão, o código já será executado e será possível observar o LED da placa piscar de 1 em 1 segundo, como no GIF a seguir.

Resultado Final
Indo Além
O código desenvolvido anteriormente só será executado ao pressionar o botão "Run" no Mu Editor, porém é possível editar o arquivo "code.py" contido na pasta do disco da Pico no computador para que a placa sempre execute o código que você deseja ao ser iniciada. Por padrão esse arquivo possui um único comando print("Hello world!"), porém você pode abrí-lo no Mu Editor para alterá-lo e então salvá-lo novamente na placa.

Além disso, o CircuitPython possui diversas bibliotecas desenvolvidas pela própria Adafruit que já estão inclusas na plataforma para facilitar o desenvolvimento de diversas aplicações.

Conclusão
Neste tutorial vimos como programar a Raspberry Pi Pico em Circuit Python através do Mu Editor e como executar o exemplo "Blink" nela.

Solução de Problemas
O Código não é Executado após Pressionar o Botão "Run"
Se mesmo ao pressionar o botão "Run" o código não for executado, verifique se o código foi salvo dentro do disco da Pico no computador. Se ele tiver sido salvo em outro local por engano, é possível copiá-lo e colá-lo dentro do diretório, como foi feito para a gravação de firmware, mas será necessário pressionar o botão "Run" novamente.

Avatar


