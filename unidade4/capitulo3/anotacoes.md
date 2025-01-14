## Unidade 4 - Microcontroladores

## Capitulo 3 - Práticas de GPIO com delay

### 1. Boas-Vindas e Introdução

Olá, estudante do EmbarcaTech! 

Seja bem-vindo a mais uma etapa do nosso curso de capacitação. Nesta unidade, vamos explorar práticas avançadas de controle de portas de entrada e saída (GPIO) utilizando temporização (delay). 
O foco desta aula é compreender como utilizar técnicas de atraso para controlar dispositivos eletrônicos como LEDs, displays de 7 segmentos e desenvolver sistemas mais complexos como um cofre digital.

Com base nos conhecimentos adquiridos anteriormente sobre GPIOs, estamos prontos para dar mais um passo em direção ao desenvolvimento de sistemas embarcados. 
Nesta aula, você terá a oportunidade de aplicar a programação em C para realizar projetos práticos e desafiadores. Vamos aprender a controlar o tempo de execução de nossos programas
para sincronizar e coordenar múltiplos dispositivos e ações. Vamos lá?

### 2. Objetivos da Unidade

Ao final desta aula, espera-se que você tenha desenvolvido a capacidade de utilizar técnicas de temporização (delay) em sistemas embarcados com o Raspberry Pi Pico[2] ou com a plataforma educacional BitDogLab[1], configurando e controlando de forma eficiente as portas de entrada e saída (GPIO) para interagir com diversos dispositivos eletrônicos. Você será capaz de implementar sistemas temporizados, como um semáforo controlado por push-button, e controlar displays de 7 segmentos [6,8], utilizando rotinas de atraso para gerenciar a exibição de números e informações.

Você também estará preparado para aplicar a técnica de multiplexação em múltiplos displays de 7 segmentos, otimizando o uso dos pinos GPIO e garantindo uma exibição eficiente e sincronizada de dados. 

Além disso, terá a habilidade de desenvolver aplicações mais complexas, como um cofre digital com senha, empregando teclados matriciais para a entrada de dados e implementando lógica de controle e validação para garantir a segurança e a integridade do sistema.

Essas práticas permitirão que você adquira habilidades fundamentais para a resolução de problemas recorrentes em sistemas embarcados, como a sincronização de tarefas e a otimização dos recursos do
microcontrolador. Você estará apto a aplicar essas técnicas em projetos práticos, utilizando tanto o Raspberry Pi Pico quanto a BitDogLab, expandindo sua capacidade de criar soluções inovadoras e eficazes para os desafios reais no desenvolvimento de sistemas embarcados.

### 3. Temporização (delay) em sistemas embarcados

Nos capítulos anteriores, exploramos os conceitos básicos e intermediários de manipulação de GPIOs, utilizando a plataforma educacional BitDogLab e o microcontrolador Raspberry Pi Pico.
Aprendemos a configurar pinos como entradas e saídas digitais, e a interagir com componentes eletrônicos como LEDs e botões. 

Discutimos a estrutura e as capacidades do microcontrolador RP2040, que integra múltiplos periféricos e interfaces, como GPIO, UART, I2C e SPI[4], permitindo a comunicação eficiente com dispositivos externos.

Além disso, revisamos o uso das bibliotecas fornecidas no SDK do Raspberry Pi Pico, que facilitam a programação e o controle dos recursos do microcontrolador.

Nesta unidade, vamos aprofundar nosso conhecimento sobre a utilização de temporização (delay) em sistemas embarcados. A aplicação de delays é fundamental para coordenar e sincronizar eventos, permitindo a criação de sistemas que reagem de forma precisa a estímulos externos.

Vamos entender como utilizar rotinas de atraso para controlar o tempo de execução de ações, como acender LEDs em sequência, exibir números em displays de 7 segmentos e implementar sistemas mais complexos que envolvem múltiplas interações com o usuário.

Utilizaremos a plataforma BitDogLab e wokwi para ilustrar exemplos práticos, oferecendo um ambiente de aprendizado integrado e interativo.

A BitDogLab, equipada com diversos periféricos como displays, botões e LEDs, será o suporte ideal para experimentarmos as funcionalidades de temporização e controlarmos o comportamento 
dos dispositivos em tempo real.

Hoje, vamos expandir esse conhecimento adquirido e explorar aplicações práticas de temporização, utilizando o microcontrolador Raspberry Pi Pico e a BitDogLab. Neste material, abordaremos novos conteúdos que incluem a configuração de delays para controlar LEDs de forma sequencial, a criação de contadores em displays de 7 segmentos e o desenvolvimento de sistemas interativos que combinam controle de tempo e entradas do usuário.

Este tópico é crucial porque possibilita o controle preciso de dispositivos eletrônicos e a coordenação de eventos em sistemas embarcados. A capacidade de utilizar temporização de maneira eficaz é essencial para o desenvolvimento de projetos que exigem sincronização de tarefas e resposta a eventos temporais, como semáforos, cronômetros e contadores. Dominar essas habilidades é um passo importante para a criação de soluções inovadoras e eficientes, tanto em ambientes educacionais quanto em aplicações industriais.

Nesta seção, vamos analisar quatro exemplos práticos que ilustram o uso dos GPIOs com temporização no desenvolvimento de projetos com o Raspberry Pi Pico, cada um explorado em um subtópico específico deste eBook:

* Quatro exemplos práticos do uso dos GPIOs com o Raspberry Pi Pico

![Figura 1](https://github.com/ubiratantavares/embarcatech_repository/blob/main/unidade4/capitulo3/exemplos.png)

### 4. Síntese

Nesta unidade, exploramos como utilizar técnicas de temporização (delay) em sistemas embarcados com o Raspberry Pi Pico ou com a plataforma educacional BitDogLab, aplicando-as em diversos
exemplos práticos. Iniciamos com o controle de um semáforo temporizado, no qual aprendemos a usar delays para alternar entre três LEDs representando as fases do semáforo, e a utilizar um
push-button para iniciar e pausar o ciclo de operação. 

Em seguida, passamos para o controle de um display de 7 segmentos, exibindo números de 0 a 9 com intervalos de tempo definidos, reforçando o conceito de mapeamento correto dos segmentos e o uso de rotinas de atraso para temporização.

A seguir, abordamos a multiplexação de displays de 7 segmentos, criando um contador de dois dígitos que alterna rapidamente entre os displays, economizando pinos de GPIO e exibindo números
de 00 a 99. Com esse exemplo, consolidamos a compreensão da multiplexação e sua aplicação em projetos com múltiplos displays. 

Por fim, estruturamos o projeto de um cofre digital com senha, utilizando um teclado matricial para a entrada de dados e LEDs para indicar o status do cofre. Este projeto destacou a importância
do uso de temporização na validação de entradas e na gestão de tentativas incorretas.

De forma geral, desenvolvemos habilidades essenciais para o controle de GPIOs em sistemas embarcados, aplicando temporização para coordenar dispositivos e criar sistemas interativos. A prática
com esses exemplos proporcionou uma base sólida para projetos mais complexos, ampliando nossa capacidade de criar soluções eficientes e robustas em aplicações embarcadas.

Agora que você concluiu esta unidade sobre práticas de GPIO com delay, é hora de colocar todo o conhecimento adquirido em prática! Relembre cada exemplo, revise o código e experimente implementar suas próprias variações. Modifique os tempos de delay, adicione novos componentes e crie suas próprias aplicações utilizando os conceitos de temporização.

Não se esqueça de revisar todo o material e concluir as atividades práticas disponíveis na plataforma. Esses exercícios são essenciais para consolidar o seu aprendizado e garantir que você compreendeu todos os conceitos abordados.

Lembre-se, a prática constante é o caminho para a excelência. Desafie-se a desenvolver projetos novos e criativos. Que tal implementar um temporizador de contagem regressiva ou um sistema de controle de acesso mais avançado?

Compartilhe suas criações e dúvidas com a comunidade EmbarcaTech!

Participar ativamente das discussões e colaborar com outros alunos é uma excelente maneira de aprimorar suas habilidades e aprender novas soluções.

Estamos ansiosos para ver o que você é capaz de construir.

## 5. Conclusão

Nesta unidade, exploramos a aplicação prática de técnicas de temporização com GPIOs, utilizando o Raspberry Pi Pico para desenvolver projetos que exigem controle preciso de tempo. Implementamos desde
sistemas simples, como o controle de semáforo com push-button, até projetos mais complexos, como a multiplexação de displays de 7 segmentos e o desenvolvimento de um cofre digital com senha.
Ao dominar o uso de delays, você aprendeu a coordenar ações e sincronizar dispositivos de maneira eficiente, habilidades fundamentais para qualquer desenvolvedor de sistemas embarcados. 

A prática com temporização, aliada ao conhecimento de manipulação de GPIOs, abre portas para a criação de sistemas interativos e inteligentes, capazes de responder a estímulos externos com precisão.

Agora, você está preparado para enfrentar novos desafios, aplicando os conceitos aprendidos em projetos ainda mais avançados. Não se esqueça de continuar praticando, explorando novas possibilidades e buscando soluções criativas para os problemas encontrados. 

A programação em C, aliada à manipulação de hardware, permite uma infinidade de aplicações.

Utilize este conhecimento para criar, inovar e transformar suas ideias em realidade.

Na próxima aula, vamos discutir interrupções, abordando sua configuração, rotinas de tratamento e atividades práticas. Com as interrupções, você aprenderá a reagir a eventos externos de forma
instantânea, sem depender de verificações constantes no código. Isso permitirá a criação de sistemas mais eficientes e responsivos, expandindo ainda mais suas habilidades em sistemas embarcados.
O aprendizado contínuo é essencial. Continue se aprofundando nos temas abordados, participando de comunidades de desenvolvedores e experimentando novas técnicas e tecnologias. Estamos confiantes
de que você está no caminho certo para se tornar um especialista em sistemas embarcados.

## 6. Referências

[1] BITDOGLAB. BitDogLab. 
Disponível em: https://github.com/BitDogLab/BitDogLab. Acesso em: 26 set. 2024.

[2] RASPBERRY PI FOUNDATION. RP2040 Datasheet. 
Disponível em: https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf. Acesso em: 25 set. 2024.

[3] GAY, Warren. Debouncing. In: GAY, Warren. Exploring the Raspberry Pi 2 with C++. 1. ed. New York: Apress, 2015. p. 105-112.

[4] IGINO, Wellington Passos et al. Ensino de sistemas embarcados baseado em projeto: exemplo aplicado à robótica. 2023.

[5] CIRCUIT BASICS. How to set up a keypad on an Arduino. 
Disponível em: https://www.circuitbasics.com/how-to-set-up-a-keypad-on-an-arduino/. Acesso em: 26 set. 2024.

[6] BARROS, ANDRÉ; OLIVEIRA, MELLO. Fundamentos para o Ensino Técnico de MECATRÔNICA–TEORIA. 2017.

[7] WOKWI. Wokwi 7 Segment Display. 
Disponível em: https://docs.wokwi.com/pt-BR/parts/wokwi-7segment. Acesso em: 25 set. 2024.

[8] TOCCI, Ronald J.; WIDMER, Neal S.; MOSS, Gregory L. Sistemas digitais. Pearson Educación, 2010.
