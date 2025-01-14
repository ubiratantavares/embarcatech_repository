Neste tutorial, configuraremos o Raspberry Pi Pico C/C++ SDK Toolchain para usar o VS Code como um IDE para o desenvolvimento de projetos embarcados com placas Pi Pico baseadas em RP2040. 
## Programação do Raspberry Pi Pico C/C++ SDK

Conforme declarado no tutorial anterior Getting Started With Raspberry Pi Pico (MicroPython), a programação Pi Pico C/C++ SDK é a maneira mais conservadora de programar os microcontroladores baseados em **RP2040**. A programação Embedded-C oferece o mais alto nível de controle sobre o comportamento e o desempenho do seu software embarcado. Podemos construir deterministicamente sistemas embarcados confiáveis​usando a linguagem de programação C, como sempre fizemos nas últimas décadas. Ainda é a maneira padrão de desenvolver tais sistemas em vários setores. Portanto, neste tutorial, prepararemos a configuração necessária para desenvolver e construir projetos C para o microcontrolador Raspberry Pi Pico **RP2040**.
## Arquitetura de Hardware RP2040

O microcontrolador **RP2040**, como a maioria dos microcontroladores, tem: RAM interna, ROM, GPIOs, Periféricos e DMA. Além disso, ele tem processadores ARM Cortex-M0+ dual-core e um PIO, que é um recurso muito interessante que abordaremos em tutoriais futuros. 

O diagrama abaixo mostra a arquitetura interna e a interconexão do hardware **RP2040**.

![[Raspberry-Pi-Pico-RP2040-Hardware-Architecture-Diagram.png]]

## O que é um SDK? Por que usar o Pico C/C++ SDK?

Todos os periféricos e recursos de hardware que você viu no diagrama de arquitetura do **RP2040** acima são configurados e controlados com registradores de função especial (SFRs) na memória do microcontrolador. Você pode consultar a folha de dados do **RP2040** para obter detalhes sobre como cada periférico opera e quais registradores são responsáveis ​​por qual configuração ou operação (ver arquivo "**rp2040_datasheet.pdf**" em docs)

Para construir aplicativos embarcados usando o **RP2040**, ou qualquer outro microcontrolador, precisamos construir um mapa de memória para os registradores de hardware que definem o endereço de cada registrador SFR na memória e dar a ele um nome que podemos referenciar no código. Este é, claro, um processo tedioso que temos que fazer **a menos que** o fabricante **forneça** seu próprio **SDK** (**S**oftware **D**evelopment **K**it) que tenha, pelo menos, definições de registradores de baixo nível mapeadas na memória.

O Raspberry Pi Pico C/C++ SDK não só nos dará definições de registro mapeado em memória de baixo nível, mas também todos os drivers de baixo nível necessários para a maioria dos periféricos de hardware no microcontrolador. Ele também tem alguns outros recursos, como veremos na próxima seção.

## Visão geral do Raspberry Pi Pico C/C++ SDK

O Raspberry Pi Pico C/C++ SDK consiste em vários drivers de dispositivo de baixo nível e drivers de abstração de hardware que são construídos sobre os drivers de baixo nível. Há também um punhado de APIs de alto nível que fornecem alguns serviços para dar suporte ao seu aplicativo de destino (coisas como tempo, sono, utilitários, etc.).

A arquitetura do software Raspberry Pi Pico C/C++ SDK pode ser visualizada como mostrado na figura abaixo. 

![[Raspberry-Pi-Pico-SDK-Software-Architecture-Layers-Diagram.png]]

O Pico SDK abstrairá a interface entre os aplicativos que desenvolveremos nesta série de tutoriais e o hardware de baixo nível do microcontrolador RP2040 de destino.
## Processo de construção do CMake e Pico C/C++ SDK

No momento em que este tutorial foi escrito, não havia um IDE “adequado” para desenvolver projetos embedded-C baseados no microcontrolador RP2040. Isso significa que teremos que instalar ferramentas individuais para criar um ambiente de desenvolvimento conveniente e teremos que lidar com compiladores em um nível mais baixo e usar coisas como CMake, sinalizadores de compilador, ferramentas de construção, etc.

O espaço maker sempre foi dominado por Arduino, AVR, PIC, STM32 e outros microcontroladores tradicionais. Cada um deles tem um excelente ambiente de desenvolvimento onde IDEs lidam com todas as coisas de baixo nível e ninguém tem que lidar com flags do compilador, CMake e coisas assim. Só não fique frustrado com esse assunto e veja isso como uma chance de aprender coisas novas e se aproximar do compilador e do processo de construção em C.

O Raspberry Pi Pico SDK usa **o CMake** para gerenciar builds de projetos. Cada projeto deve ter um arquivo chamado CMakeLists . txt , que especifica os arquivos de cabeçalho aos quais o projeto deve vincular, quaisquer arquivos de origem que ele deve incluir e outras configurações para o processo de build.

Para cada projeto que criaremos, usaremos um modelo de arquivo CMakeLists.txt que será modificado para atender às necessidades de cada projeto. Demonstraremos isso mais adiante neste tutorial, pois criaremos e construiremos um projeto do zero após instalar a cadeia de ferramentas necessária.

## O que é CMake?

CMake é um sistema de build multiplataforma de código aberto que fornece uma maneira unificada e independente de plataforma para gerenciar o processo de build para projetos de software. Ele permite que os desenvolvedores descrevam o processo de build usando uma linguagem de script simples (linguagem CMake) e gera arquivos de build nativos para várias plataformas e ambientes de build.

## Instalando o Pi Pico C/C++ SDK Toolchain

Agora, precisamos instalar o Raspberry Pi Pico C/C++ SDK toolchain para começar a desenvolver nosso primeiro projeto embarcado para o microcontrolador RP2040. Aqui está uma lista das ferramentas de software que precisamos instalar:

- Cadeia de ferramentas GNU Arm
- CMake
- Ninja
- Python 3.9
- Git para Windows
- Código do Visual Studio
- OCD aberto

Essas ferramentas de software incluem o compilador ARM C, CMake, gerenciador de build, editor de código VS (usaremos como um IDE) e depurador on-chip (OpenOCD). Felizmente, em vez de baixar e configurar cada ferramenta independentemente, há um instalador do Windows contribuído pela comunidade que reúne todas as ferramentas de software do toolchain em um arquivo que você pode baixar e ele irá configurar e instalar tudo automaticamente para nós.

Nota: Muitos usuários têm muitas reclamações sobre o processo de instalação e configuração do conjunto de ferramentas Raspberry Pi Pico C/C++ SDK, que pode realmente dar errado de muitas maneiras. Então, siga o seguinte guia passo a passo de configuração e me avise se estiver enfrentando algum problema.
## Atualizando o firmware para Raspberry Pi Pico (C SDK)

Aqui está um guia passo a passo sobre como atualizar um novo arquivo binário de saída de projeto de firmware para a placa Raspberry Pi Pico (ou Pico W).

**Passo 1**: **Segure** o botão **BOOTSEL** da placa Raspberry Pi Pico antes de conectá-la à porta USB do seu PC. Enquanto segura o botão BOOTSEL, **conecte** o Raspberry Pi Pico à porta USB do seu PC.

Ele inicializará no modo bootloader e seu PC o detectará como um dispositivo de armazenamento USB, então agora você está livre para **soltar** o botão BOOTSEL.

**Passo 2**: É uma questão de arrastar e soltar o arquivo de saída UF2 para a unidade USB Raspberry Pi Pico. Levará alguns segundos para carregar, então ele reiniciará automaticamente e começará a executar o novo firmware que atualizamos para o microcontrolador RP2040.

Você deve notar o LED onboard piscando com um atraso de 250 ms entre cada evento de alternância. Este é o projeto de exemplo de piscar do Pico SDK integrado.

Em seguida, aprenderemos como criar um projeto autônomo do Raspberry Pi Pico C/C++ SDK do zero, adicionar o arquivo CMakeList, construir o projeto e atualizar o arquivo binário de saída para validar todo o processo.

## Projeto autônomo Raspberry Pi Pico C/C++

Vamos agora criar nosso primeiro projeto autônomo Raspberry Pi Pico C/C++ SDK que também será um exemplo de LED piscando com um atraso de 100 ms entre eventos de alternância de estado de LED. Criaremos o projeto do zero de forma manual, no entanto, existe uma ferramenta de software geradora de projeto Raspberry Pi Pico SDK que automatiza esse processo. Que discutiremos e usaremos em um tutorial futuro também.

**Passo 1**: Crie a pasta do projeto LED_BLINK e um arquivo de código-fonte main.c . Este é o código-fonte para colar no arquivo main.c

```c
#include "pico/stdlib.h"

#define BUILTIN_LED PICO_DEFAULT_LED_PIN

int main() {
    gpio_init(BUILTIN_LED);
    gpio_set_dir(BUILTIN_LED, GPIO_OUT);
    
    while (1) {
        gpio_put(BUILTIN_LED, 1);
        sleep_ms(100);
        gpio_put(BUILTIN_LED, 0);
        sleep_ms(100);
    }
}
```

**Passo 2**: Crie e adicione o arquivo CMakeLists.txt à pasta do projeto. Este é o código CMake para colar no arquivo CMakeLists.txt .

```txt
cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(LED_BLINK C CXX ASM)
pico_sdk_init()
add_executable(main main.c)
pico_add_extra_outputs(main)
target_link_libraries(main pico_stdlib)
```

**Passo 3**: Copie o arquivo chamado (pico_sdk_import.cmake ) arquivo de origem do CMake da pasta **pico-sdk/external** para a pasta do seu novo projeto. A pasta do novo projeto agora deve se parecer com a mostrada abaixo.

![[Raspberry-Pi-Pico-C-SDK-Programming-Standalone-Project-VS-Code.png]]

**Passo 4**: Abra o iniciador de atalho “ **Pico – Visual Studio Code** ” na área de trabalho do menu iniciar (software adicionado recentemente). Selecione **Arquivo** > **Abrir pasta** . Navegue até onde a pasta do seu novo projeto está localizada e escolha essa pasta.

O VS Code solicitará que você configure a pasta do projeto na parte inferior da janela do IDE. Selecione "sim" e deixe que ele faça isso por você.

![[Raspberry-Pi-Pico-C-SDK-Programming-Standalone-Project-VS-Code-1-1536x821.png]]

**Passo #5**: Por fim, verifique o arquivo main.c se você quiser alterar o atraso de piscar do LED ou algo assim. Inicie o processo de construção usando o **botão de construção** ou no menu superior selecione **Terminal** > **Run Build Task** . Aguarde a conclusão e você deverá obter uma mensagem de saída como a mostrada abaixo, ela também mostra o caminho para os arquivos de saída. O ideal é que você encontre tudo na pasta **de construção** dentro da pasta do projeto que criamos.

![[Standalone-Raspberry-Pi-Pico-C-SDK-Project-Build-1536x269.png]]

**Passo #6**: Vamos agora fazer o flash do novo firmware do projeto na placa Raspberry Pi Pico. **Segure** o botão **BOOTSEL** da placa Raspberry Pi Pico antes de conectá-la à porta USB do seu PC. Enquanto segura o botão BOOTSEL, **conecte** o Raspberry Pi Pico à porta USB do seu PC.

Ele inicializará no modo bootloader e seu PC o detectará como um dispositivo de armazenamento USB, então agora você está livre para **soltar** o botão BOOTSEL.

Arraste e solte o arquivo de saída UF2 para a unidade USB Raspberry Pi Pico. Levará alguns segundos para carregar, então ele reiniciará automaticamente e começará a executar o novo firmware que atualizamos para o microcontrolador RP2040.

## Exemplo de LED piscando no Raspberry Pi Pico C/C++ SDK

Este é o projeto de exemplo de LED piscando do Raspberry Pi Pico C/C++ SDK que criamos na seção anterior.

**main.c** (Raspberry Pi Pico)

```c
/*
* LAB Name: Raspberry Pi Pico Arduino IDE (Project Template)
* Author: Khaled Magdy
* For More Info Visit: www.DeepBlueMbedded.com
*/

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Toggle onBoard LED
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  delay(100);
}
```

**CMakeLists.txt** (Raspberry Pi Pico)

```text
cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(LED_BLINK C CXX ASM)
pico_sdk_init()
add_executable(main main.c)
pico_add_extra_outputs(main)
target_link_libraries(main pico_stdlib)
```

Como você pode ver facilmente, ele define o pino LED onboard como um pino de saída. E alterna seu estado a cada **100 ms** e continua repetindo para sempre.

Nota: Se você estiver usando uma **placa Raspberry Pi Pico W** , precisará prosseguir para o próximo projeto de exemplo, que mostra como replicar o que fizemos para ajustar a placa Raspberry Pi Pico W.

## Exemplo de LED piscando no Raspberry Pi Pico C/C++ SDK

Este é um projeto de exemplo do Raspberry Pi Pico WC/C++ SDK LED Blinking. Você precisa seguir exatamente os mesmos passos de criação do projeto que o projeto anterior para o Raspberry Pi Pico. A única diferença é: o código-fonte ( main . c ) e os arquivos ( CMakeLists . txt ).

**main.c** (Raspberry Pi Pico W)

```c
/*
* LAB Name: Raspberry Pi Pico W C/C++ SDK (Project Template)
* Author: Khaled Magdy
* For More Info Visit: www.DeepBlueMbedded.com
*/

#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#define BUILTIN_LED CYW43_WL_GPIO_LED_PIN

int main() {
    stdio_init_all();
    if (cyw43_arch_init()) {
        return -1;
    }

    while (1) {
        cyw43_arch_gpio_put(BUILTIN_LED, 1);
        sleep_ms(100);
        cyw43_arch_gpio_put(BUILTIN_LED, 0);
        sleep_ms(100);
    }
}
```

**CMakeLists.txt** (Raspberry Pi Pico W)

```text
cmake_minimum_required(VERSION 3.12)
set(PICO_BOARD pico_w)
include(pico_sdk_import.cmake)
project(main C CXX ASM)
pico_sdk_init()
add_executable(main main.c)
target_link_libraries(main pico_stdlib pico_cyw43_arch_none)
pico_add_extra_outputs(main)
```

Nota: Os links para download do projeto são encontrados perto do final deste tutorial. Caso você queira usá-los como referência.

## Projeto de simulação Raspberry Pi Pico C/C++ SDK (Wokwi)

No momento em que este tutorial foi escrito, havia apenas um simulador Raspberry Pi Pico que parecia muito promissor: a ferramenta **[de simulador online Wokwi](https://wokwi.com/)** . Há um guia tutorial dedicado para “simulação de projeto Raspberry Pi Pico” vinculado abaixo nesta seção a seguir.

Este é o resultado da simulação para o projeto de exemplo anterior Raspberry Pi Pico LED Blinking (C SDK) usando Wokwi. Você pode encontrar os arquivos de Simulação de Projeto vinculados abaixo, para que você possa salvar uma cópia deles no painel de projetos do Wokwi e brincar com o ambiente do simulador.

![[Raspberry-Pi-Pico-C-SDK-LED-Blinking-Example-Simulation.png]]

Simular seus projetos Raspberry Pi Pico pode ser muito útil, especialmente quando você está apenas começando. Este passo não é obrigatório, no entanto, executar seu projeto em um ambiente de simulador ajudará você a capturar e corrigir alguns erros de lógica no código ou nas conexões de fiação do circuito.

O projeto de simulação Wokwi vinculado acima será nosso modelo para todos os tutoriais do Raspberry Pi Pico Arduino IDE, então você precisa fazer uma cópia dele no painel do projeto da sua conta Wokwi.
## Observações Finais
	
Para concluir este tutorial, podemos apenas dizer que é apenas o primeiro passo na jornada de programação do Raspberry Pi Pico C baseado em RP2040. Os tutoriais a seguir nesta série ajudarão você a começar a programar no Raspberry Pi Pico e aprender mais tópicos com exemplos práticos e explicações passo a passo.

Siga esta **série de tutoriais do Raspberry Pi Pico** para aprender mais sobre a programação do Raspberry Pi Pico em diferentes ambientes de linguagens de programação.

Se você está apenas começando com o Raspberry Pi Pico, você deve conferir os seguintes guias de introdução com a linguagem de programação que você mais gosta. Existem 4 variantes dos tutoriais do Raspberry Pi Pico para atender às suas necessidades e ajudar você no caminho que você vai escolher.
