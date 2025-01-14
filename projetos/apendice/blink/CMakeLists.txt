# Define a versão mínima do CMake que será utilizada
cmake_minimum_required(VERSION 3.13)

# Define o nome do projeto
project(blink C CXX ASM)

# Define a versão do padrão C a ser utilizada
set(CMAKE_C_STANDARD 11)  # Uso do C11
set(CMAKE_CXX_STANDARD 17)  # Caso utilize C++ no projeto futuro

# Inclui o SDK do Raspberry Pi Pico
# Essa variável deve ser configurada previamente no ambiente
include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)

# Inicializa o SDK do Raspberry Pi Pico
pico_sdk_init()

# Adiciona o arquivo principal ao projeto
add_executable(blink
    main.c  # Substitua pelo nome do arquivo se diferente
)

# Alinha o projeto com as bibliotecas padrão da Pico
target_link_libraries(blink pico_stdlib)

# Define o nome da placa (pico ou pico_w, conforme o hardware)
pico_add_extra_outputs(blink)

# Adiciona suporte às bibliotecas necessárias
# A função pico_enable_stdio_* habilita saída pela UART ou USB
pico_enable_stdio_uart(blink 1)  # Habilita saída pela UART (1 = ativo)
pico_enable_stdio_usb(blink 0)   # Desativa saída pela USB (0 = inativo)

# Comentário: Essa configuração faz o link com as bibliotecas básicas
# e configura o suporte de entrada/saída para o projeto.
