Embarcados - Nova Raspberry Pi Pico W - Agora com WiFi (e Bluetooth)

https://embarcados.com.br/nova-raspberry-pi-pico-w-agora-com-wifi-e-bluetooth/https://embarcados.com.br/nova-raspberry-pi-pico-w-agora-com-wifi-e-bluetooth/


Nova Raspberry Pi Pico W: Agora com WiFi (e Bluetooth)
30/06/2022
Fábio Souza
4 Comentários

A fundação Raspberry Pi acaba de anunciar sua mais nova placa, a Raspberry Pi Pico W. 

Baseada no mesmo microcontrolador da sua antecessora, o RP2040, essa nova versão adiciona um módulo Wi-Fi 4 (802.11n) + Bluetooth 5.2 da Infineon:

Raspberry Pi Pico W
Pico W mantêm compatibilidade com a Pi Pico, mantendo o mesmo form factor e pinagem (Note que não foi adicionado o botão de reset tão solicitado pelos usuários). Uma diferença é que o LED de uso geral está conectado ao módulo wireless, porém ainda é possível controlá-lo através do SDK. Outra diferença está na posição do conector Serial Wire Debug (SWD). Ele foi deslocado para dentro da placa. Esse é um detalhe a ser avaliado caso se queira usar a Pico W em uma placa desenvolvida para Pi Pico.

-- publicidade --

Raspberry Pi Pico W
A placa foi lançada por $6 sendo agora uma alternativa para placas com ESP32 a ser considerada. Infelizmente, para manter esse valor, não houve um upgrade na capacidade da flash onboard. Foram mantidos os 2 MB de flash

Suporte de software
O Pico SDK já suporta a rede sem fio. A pilha de rede é construída em com lwIP e usa libcyw43 de Damien George( o MicroPython). Por padrão, a libcyw43 é licenciada para uso não comercial, mas os usuários do Pico W e qualquer outra pessoa que construa seu produto em torno de RP2040 e CYW43439 se beneficiam de uma licença gratuita de uso comercial.


BLACK NOVEMBER EMBARCADOS

Aproveite a Black November do Embarcados para garantir nossos cursos com descontos imperdíveis! Não perca essa oportunidade de se capacitar com as melhores ofertas do ano!

MATRÍCULE-SE AGORA
Como o desenvolvedor da libcyw43 foi o Damien George, é natural que o Micropython também já suporte a rede sem fio. 

Como mencionado acima, o módulo CYW43439 também possui bluetooth, porém ainda não há suporte de software para essa funcionalidade.

Video de lançamento da Raspberry Pi Pico W
NEW Raspberry Pi Pico W - your $6 wireless microcontroller
E aí, o que achou dessa nova versão da Raspberry Pi Pico? Deixe seu comentário.

Mais detalhes em: Raspberry Pi Pico W: your $6 IoT platform

Avatar photo
Fábio Souza
402 posts
https://br.linkedin.com/in/engfabiosouza
Engenheiro com experiência no desenvolvimento de projetos eletrônicos embarcados. Hoje é diretor do portal Embarcados, onde trabalha para levar conteúdos de eletrônica, sistemas embarcados e IoT para o Brasil. Atua no ensino de sistemas embarcados com diversos cursos e materiais publicados., já formou milhares de alunos na área de sistemas embarcados. É um entusiasta do movimento maker, da cultura DIY e do compartilhamento de conhecimento, publicando diversos artigos, projetos open hardware e sendo autor de livros da área. Por meio de iniciativas como o projeto Franzininho e outros projetos open source, promove a cultura maker no Brasil, capacitando e incentivando professores e alunos a usarem a tecnologia em suas vidas.
Licença Creative CommonsEsta obra está licenciada com uma Licença Creative Commons Atribuição-CompartilhaIgual 4.0 Internacional.
Comentários:
 Notificações 
Please login to comment
4 Comentários
recentes 
Rogerio Moreira
Rogerio Moreira
Membro
 21/07/2022 15:49
É o Franzininho da Raspberrypi ?

0
Daniel Quadros
Daniel Quadros
Membro
 04/07/2022 14:05
Olhando o datasheet do CYW43439 e o esquema do Pico W, reparei que os pinos referentes ao Bluetooth não estão conectados (por exemplo, os dados do BT são transferidos através de uma UART). Portanto acho que não é apenas uma questão de software.

0
Cesar
Cesar
 02/07/2022 19:57
O raspberry pico w roda o linux?

0
Fábio Souza
Fábio Souza
Autor
Reply to 
Cesar
 04/07/2022 09:12
Olá Cesar. Ela não roda Linux. É uma placa com um microcontrolador Arm Cortex M0+

0
Notícias
Home » Notícias » Nova Raspberry Pi Pico W: Agora com WiFi (e Bluetooth)



