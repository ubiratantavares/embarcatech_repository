# Como instalar o CMake no Linux Ubuntu

## Método 1: Usar o gerenciador de pacotes `apt` (instalação simples)

1. Abra o terminal.

2. Atualize o sistema e os repositórios:

   ```bash
   sudo apt update && sudo apt upgrade -y
   ```
3. Instale o CMake:

   ```bash
   sudo apt install cmake -y
   ```

NOTA: Isso instalará a versão disponível no repositório oficial do Ubuntu.

## Método 2: Instalar a versão mais recente a partir do site oficial

1. Verifique a versão atual disponível no site oficial: https://cmake.org/download/](https://cmake.org/download/

2. Baixe a última versão (substitua `<versão>` pela versão desejada):

   ```bash
   wget https://github.com/Kitware/CMake/releases/download/v<versão>/cmake-<versão>-linux-x86_64.sh
   ```
3. Torne o script executável:

   ```bash
   chmod +x cmake-<versão>-linux-x86_64.sh
   ```
4. Instale o CMake no sistema:

   ```bash
   sudo ./cmake-<versão>-linux-x86_64.sh --skip-license --prefix=/usr/local
   ```
