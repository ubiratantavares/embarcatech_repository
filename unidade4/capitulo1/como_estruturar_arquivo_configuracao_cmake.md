# Como estruturar um arquivo de configuração no CMake para compilar um projeto escrito em C

Aqui está o passo a passo para criar o arquivo `CMakeLists.txt`:

## Exemplo: Código "blink"

Suponha que você tenha um projeto com a seguinte estrutura:

```
blink/
├── CMakeLists.txt
├── main.c
```

## Conteúdo do `main.c` (código de exemplo para piscar um LED)

```c
#include <stdio.h>
#include "pico/stdlib.h"

int main() {
    const uint LED_PIN = 25; // LED embutido no Raspberry Pi Pico
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        gpio_put(LED_PIN, 1); // Liga o LED
        sleep_ms(500);
        gpio_put(LED_PIN, 0); // Desliga o LED
        sleep_ms(500);
    }
}
```

## Conteúdo do `CMakeLists.txt`

```cmake

# Indica a versão mínima necessária do CMake para este projeto
cmake_minimum_required(VERSION 3.13)

# Nome do projeto e especificação da linguagem
project(blink_project LANGUAGES C)

# Inclui o SDK do Raspberry Pi Pico
include(pico_sdk_import.cmake)

# Cria um executável a partir do arquivo "main.c"
add_executable(blink main.c)

# Linka o SDK ao projeto, adicionando as bibliotecas necessárias
target_link_libraries(blink pico_stdlib)

# Prepara o projeto para ser construído no Raspberry Pi Pico
pico_add_extra_outputs(blink)
```

## O que cada linha faz

1. `cmake_minimum_required(VERSION 3.13)`: Define a versão mínima do CMake que o projeto suporta.

2. `project(blink_project LANGUAGES C)`: Nomeia o projeto como "blink_project" e especifica que é escrito em C.

3. `include(pico_sdk_import.cmake)`: Inclui o SDK do Raspberry Pi Pico, que contém as definições e bibliotecas necessárias.

4. `add_executable(blink main.c)`: Adiciona o arquivo `main.c` como o ponto de entrada para o executável chamado "blink".

5. `target_link_libraries(blink pico_stdlib)`: Linka a biblioteca padrão do Pico (`pico_stdlib`) ao executável.

6. `pico_add_extra_outputs(blink)`: Garante que os binários finais (como `.uf2` e `.bin`) sejam gerados para o Raspberry Pi Pico.

## Compilando o projeto com CMake

1. No terminal, vá até a pasta do projeto:

   ```bash
   cd blink
   ```

2. Crie um diretório de compilação:

   ```bash
   mkdir build && cd build
   ```
3. Configure o projeto:

   ```bash
   cmake ..
   ```
4. Compile o projeto:

   ```bash
   make
   ```
5. Após a compilação bem-sucedida, o arquivo `blink.uf2` estará no diretório `build`. Transfira-o para o Pico, que deve estar em modo de bootloader.
