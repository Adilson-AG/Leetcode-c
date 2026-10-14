# Leetcode-c

Repositório dedicado à resolução de exercícios de programação da plataforma [LeetCode](https://leetcode.com/), utilizando a linguagem C.

O objetivo é praticar lógica de programação, estruturas de dados, algoritmos e gerenciamento de memória, desenvolvendo soluções corretas, eficientes e bem organizadas.

Os exercícios são desenvolvidos e executados localmente no Windows, utilizando o Visual Studio Code e o compilador GCC.

## Tecnologias e ferramentas

- **Linguagem:** C
- **Compilador:** GCC (GNU Compiler Collection)
- **Ambiente de desenvolvimento:** Visual Studio Code
- **Sistema operacional:** Windows
- **Terminal:** PowerShell
- **Ambiente de desenvolvimento C:** MSYS2 (UCRT64)
- **Versionamento:** Git e GitHub

## Objetivos do repositório

- Praticar lógica de programação por meio de problemas reais.
- Desenvolver o raciocínio algorítmico.
- Estudar arrays, strings, matrizes, listas e outras estruturas de dados.
- Compreender ponteiros e gerenciamento dinâmico de memória.
- Trabalhar com funções, recursão, ordenação e busca.
- Analisar a complexidade de tempo e espaço dos algoritmos.
- Comparar diferentes abordagens para resolver o mesmo problema.
- Manter um histórico de aprendizado e evolução na linguagem C.

## 1. Requisitos para instalação

Antes de executar os exercícios, instale as seguintes ferramentas.

### Visual Studio Code

O VS Code será utilizado para editar os arquivos, organizar os exercícios e executar os comandos de compilação no terminal integrado.

Download: https://code.visualstudio.com/

Após a instalação, abra o VS Code e instale a extensão **C/C++**, publicada pela Microsoft.

Extensão: https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools

A extensão oferece recursos como realce de sintaxe, IntelliSense, navegação pelo código e suporte à depuração. Ela não instala o compilador GCC automaticamente.

### Git

O Git permite controlar as versões dos arquivos e sincronizar o projeto com o GitHub.

Download: https://git-scm.com/downloads

Após a instalação, abra o PowerShell e verifique:

```powershell
git --version
```

### MSYS2 e GCC

O MSYS2 fornece um ambiente para instalar ferramentas de desenvolvimento no Windows, incluindo o GCC.

Download: https://www.msys2.org/

Após instalar o MSYS2, abra o terminal **MSYS2 UCRT64** e execute:

```bash
pacman -Syu
```

Se for solicitado fechar o terminal para concluir uma atualização, feche-o, abra novamente o MSYS2 UCRT64 e execute as atualizações restantes, se necessário.

Instale o GCC:

```bash
pacman -S --needed mingw-w64-ucrt-x86_64-gcc
```

Por padrão, se o MSYS2 foi instalado em `C:\msys64`, o compilador ficará em:

```text
C:\msys64\ucrt64\bin\gcc.exe
```

Verifique a instalação no terminal MSYS2 UCRT64:

```bash
gcc --version
```

Se o comando mostrar a versão do GCC, a instalação foi concluída.

## 2. Configuração do GCC no PowerShell do VS Code

Para compilar os exercícios diretamente pelo terminal integrado do VS Code, o Windows precisa localizar o executável `gcc.exe`.

### Configuração temporária

Se o MSYS2 estiver instalado em `C:\msys64`, execute no PowerShell:

```powershell
$env:PATH = "C:\msys64\ucrt64\bin;C:\msys64\usr\bin;$env:PATH"
```

Verifique se o compilador está disponível:

```powershell
gcc --version
```

Se aparecer a versão do GCC, a configuração funcionou.

**Importante:** os caminhos acima pressupõem que o MSYS2 está instalado em `C:\msys64`. Se você o instalou em outro diretório, substitua `C:\msys64` pelo caminho correto.

A alteração temporária vale apenas para a sessão atual do PowerShell. Ao abrir outro terminal, será necessário executar o comando novamente.

### Configuração permanente (opcional)

Para não precisar repetir o comando, adicione o seguinte diretório à variável de ambiente `Path` do Windows:

```text
C:\msys64\ucrt64\bin
```

Adicione também `C:\msys64\usr\bin` somente se precisar utilizar ferramentas desse diretório no PowerShell.

Para configurar:

1. Abra o menu Iniciar e pesquise por **Variáveis de ambiente**.
2. Selecione a opção para editar as variáveis de ambiente da sua conta.
3. Selecione `Path` e clique em **Editar**.
4. Adicione o caminho do GCC.
5. Salve as alterações e abra um novo terminal.

Verifique novamente:

```powershell
gcc --version
```

## 3. Obtendo o projeto

Existem duas maneiras de obter os códigos deste repositório.

### Opção 1 — Criar um fork (recomendado para modificar o código)

Um fork cria uma cópia do repositório na conta GitHub do usuário. Isso permite modificar os arquivos e enviar alterações para a própria cópia, sem alterar diretamente o projeto original.

1. Acesse o [repositório Leetcode-c](https://github.com/Adilson-AG/Leetcode-c).
2. Clique no botão **Fork**.
3. Selecione sua conta GitHub e conclua a criação do fork.
4. No terminal, clone sua própria cópia, substituindo `SEU-USUARIO` pelo seu nome de usuário do GitHub:

```powershell
git clone https://github.com/SEU-USUARIO/Leetcode-c.git
```

5. Entre na pasta:

```powershell
cd Leetcode-c
```

6. Abra o projeto no VS Code:

```powershell
code .
```

Caso o comando `code` não seja reconhecido, abra o VS Code manualmente e selecione a pasta do projeto.

Depois disso, você poderá modificar os exercícios e enviar suas alterações para o seu próprio fork.

**Observação:** criar um fork não concede permissão de escrita no repositório original. O proprietário continua controlando as alterações no projeto original.

### Opção 2 — Baixar os arquivos ZIP

Se você deseja apenas consultar os códigos, sem utilizar Git, acesse o [repositório Leetcode-c](https://github.com/Adilson-AG/Leetcode-c).

1. Clique em **Code**.
2. Selecione **Download ZIP**.
3. Extraia os arquivos para uma pasta no computador.
4. Abra a pasta extraída no Visual Studio Code.

Essa opção é indicada para quem deseja apenas estudar os exercícios, sem configurar o Git.

## 4. Compilar e executar um exercício

Os arquivos de solução são escritos em C e salvos com a extensão `.c`.

Por exemplo, considerando um arquivo chamado `main.c`, com uma função `main()`:

```c
#include <stdio.h>

int main(void)
{
    printf("Hello, LeetCode!\n");
    return 0;
}
```

No terminal do VS Code, entre na pasta onde está o arquivo e compile:

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic main.c -o main.exe
```

Execute o programa:

```powershell
.\main.exe
```

### O que significam os parâmetros?

- `gcc`: chama o compilador.
- `-std=c11`: utiliza o padrão C11.
- `-Wall`: habilita um conjunto importante de avisos.
- `-Wextra`: habilita avisos adicionais.
- `-Wpedantic`: solicita avisos sobre extensões fora do padrão selecionado.
- `main.c`: arquivo de código-fonte.
- `-o main.exe`: define o nome do executável gerado.

Os avisos ajudam a identificar possíveis problemas no código. É recomendável corrigir os avisos relevantes antes de considerar uma solução concluída.

## 5. Compilar arquivos com nomes diferentes

Cada exercício pode ter seu próprio arquivo. Por exemplo:

```text
arrays/
    two_sum.c
    remove_duplicates.c
    max_alternating_sum.c
```

Para compilar `two_sum.c`, estando dentro da pasta `arrays`:

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic two_sum.c -o two_sum.exe
```

Para executar:

```powershell
.\two_sum.exe
```

O nome do executável pode ser diferente do nome do arquivo `.c`.

Se o exercício possuir uma função `main()`, ele poderá ser executado como um programa independente. Algumas soluções do LeetCode contêm apenas a função exigida pela plataforma, sem `main()`. Nesses casos, é necessário criar um programa de testes local ou executar a solução no próprio LeetCode.

## 6. Organização dos exercícios

Os exercícios devem ser organizados por tema ou estrutura de dados, conforme o crescimento do repositório.

Uma estrutura possível é:

```text
Leetcode-c/
├── arrays/
│   ├── two_sum.c
│   ├── remove_duplicates.c
│   └── max_alternating_sum.c
├── strings/
├── linked_lists/
├── trees/
├── sorting/
└── README.md
```

Essa árvore é apenas uma sugestão de organização. As pastas e os arquivos reais devem refletir o conteúdo existente no repositório.

Cada arquivo deve ter um nome descritivo, preferencialmente relacionado ao problema resolvido.

## 7. Boas práticas de programação em C

Durante a resolução dos exercícios, procure seguir algumas práticas:

- Utilizar nomes de variáveis e funções que expressem sua finalidade.
- Dividir problemas maiores em funções menores.
- Utilizar tipos de dados adequados aos limites das entradas.
- Verificar o retorno de funções que podem falhar, como `malloc()`.
- Liberar a memória alocada dinamicamente com `free()` quando ela não for mais necessária.
- Evitar acessos fora dos limites de arrays.
- Considerar casos extremos e entradas vazias quando aplicável.
- Utilizar comentários para explicar decisões importantes, evitando comentários desnecessários.
- Avaliar a complexidade de tempo e espaço das soluções.

Sempre que possível, procure compreender o funcionamento do algoritmo antes de buscar otimizações.

## 8. Enviar alterações para o GitHub

Esta seção é destinada a quem mantém uma cópia própria do repositório, como um fork.

Após implementar ou modificar um exercício, confira as alterações:

```powershell
git status
```

Adicione os arquivos e crie um commit:

```powershell
git add .
git commit -m "Adiciona solução de exercício"
```

Envie as alterações para o repositório remoto configurado:

```powershell
git push
```

Se você clonou seu fork, o comando enviará as alterações para o seu próprio repositório, desde que a branch esteja configurada para acompanhar a branch remota correspondente.

Para atualizar sua cópia local a partir do remoto:

```powershell
git pull --rebase
```

Se houver conflitos, resolva-os antes de continuar.

**Atenção:** confira o resultado de `git status` antes de adicionar arquivos. Não envie executáveis, arquivos temporários, credenciais ou dados pessoais sem necessidade.

## 9. Recursos para estudo

- [LeetCode](https://leetcode.com/) — plataforma de problemas de programação.
- [Documentação do GCC](https://gcc.gnu.org/onlinedocs/) — opções de compilação e recursos do compilador.
- [Referência da linguagem C](https://en.cppreference.com/w/c) — biblioteca padrão, tipos e sintaxe.
- [Documentação do VS Code para C/C++](https://code.visualstudio.com/docs/languages/cpp) — configuração do ambiente e depuração.
- [Documentação do Git](https://git-scm.com/doc) — controle de versão e colaboração.

## Considerações finais

Este repositório é um espaço de estudo e prática contínua em C. Cada exercício representa uma oportunidade de compreender melhor a linguagem, desenvolver o raciocínio lógico e aprender a construir soluções eficientes.

O foco não está apenas em obter uma resposta aceita pela plataforma, mas também em entender o algoritmo, suas limitações, o uso da memória e as decisões tomadas durante a implementação.
