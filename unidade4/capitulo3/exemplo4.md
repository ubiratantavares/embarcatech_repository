# Exemplo 4 - Controle de cofre digital com senha

## Introdução

Neste subtópico, o objetivo é guiá-lo na estruturação de um projeto
completo de controle de um cofre digital utilizando um teclado
matricial[5] e dois displays de 7 segmentos. A intenção é mostrar a lógica
e o raciocínio necessários para desenvolver a aplicação sem fornecer o
código completo, incentivando você a aplicar os conceitos aprendidos
e a desenvolver suas próprias soluções. Essa prática será valiosa para
consolidar o conhecimento adquirido e para que você possa enfrentar
desafios reais em projetos de sistemas embarcados.

## Objetivo

O objetivo deste projeto é criar um sistema embarcado que permita o
controle de um cofre digital por meio de uma senha de 4 dígitos. A senha
deve ser inserida utilizando um teclado matricial, e o estado do cofre (aberto
ou fechado) será indicado por dois LEDs: um LED verde, que acenderá
quando o cofre estiver aberto, e um LED vermelho, que piscará em caso de
senha incorreta. Além disso, após três tentativas incorretas consecutivas,
o sistema deve entrar em um modo de bloqueio temporário, desativando a
entrada de novas tentativas por um período determinado.

## Planejamento e Estruturação do Projeto

a) Definição dos Requisitos Funcionais
Antes de iniciar a implementação, é essencial definir claramente o que
o sistema deve fazer. Os requisitos funcionais básicos para este projeto
são:

b) Diagrama de Blocos do Sistema
Para facilitar a compreensão do funcionamento do sistema, crie um
diagrama de blocos. O diagrama deve incluir os seguintes componentes:

c) Design do Circuito
Para implementar o sistema, você precisará conectar adequadamente
todos os componentes ao microcontrolador. Aqui estão as principais
conexões que devem ser feitas:

d) Algoritmo de Funcionamento
Descreva o algoritmo básico que o sistema deve seguir para atingir os
objetivos propostos:

e) Funções Auxiliares
Para simplificar a implementação, é importante dividir o código em
funções menores que realizem tarefas específicas:

## Desafio da Implementação

Com base nas orientações fornecidas, implemente a lógica para
capturar a senha, validar a entrada e controlar os LEDs e displays
conforme descrito. Não fornecemos o código completo, pois este
exercício é um desafio prático para consolidar seu aprendizado.
Lembre-se de aplicar os conceitos de temporização e controle
de GPIOs aprendidos nos exemplos anteriores para completar o
projeto.
1. Desafio Adicional:
• Modifique o sistema para permitir a configuração da senha
através do próprio teclado matricial.
• Adicione um buzzer para emitir um alerta sonoro em caso de
tentativas incorretas.
Ao finalizar o projeto, você terá uma aplicação funcional de
controle de cofre digital, uma excelente demonstração prática dos
conceitos de sistemas embarcados com microcontroladores.


