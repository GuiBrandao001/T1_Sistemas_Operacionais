# T1 — Simulador de Escalonamento de Processos

Trabalho desenvolvido para a disciplina de Sistemas Operacionais utilizando C++.

---

# Objetivo

O projeto consiste na implementação de um simulador de escalonamento de processos capaz de executar diferentes algoritmos utilizados por sistemas operacionais para gerenciamento da CPU.

O simulador realiza:

- Leitura de processos via arquivo
- Simulação dos algoritmos de escalonamento
- Exibição da execução dos processos
- Cálculo de métricas como:
  - Tempo de espera
  - Tempo de retorno
  - Tempo de término

---

# 🛠️ PASSO 0 — Preparação do Ambiente (macOS)

Antes de executar o projeto, é necessário instalar as ferramentas de compilação do C++ no macOS.

Durante o desenvolvimento deste trabalho foram encontrados problemas comuns relacionados ao Xcode Command Line Tools, então este guia inclui os passos completos.

---

# Instalação das Dependências no macOS

## 1. Abrir o Terminal

Abra:

```txt
Applications → Utilities → Terminal
```

ou pesquise por:

```txt
Terminal
```

no Spotlight.

---

## 2. Instalar Command Line Tools

Execute:

```bash
xcode-select --install
```

Isso instala:

- g++
- clang++
- git
- ferramentas de compilação

---

## Problema Comum

Caso apareça erro como:

```txt
No developer tools were found
```

ou:

```txt
item not available on the software update server
```

execute:

```bash
softwareupdate --list
```

Depois:

```bash
softwareupdate --install --all
```

Isso atualiza o sistema e libera a instalação das ferramentas.

---

## 3. Aceitar licença do Xcode

Após instalar as ferramentas, execute:

```bash
sudo xcodebuild -license
```

Role até o final apertando:

```txt
Enter
```

Depois digite:

```txt
agree
```

---

## 4. Verificar instalação

Execute:

```bash
g++ --version
```

Se aparecer a versão do compilador, está tudo funcionando.

Exemplo:

```txt
Apple clang version ...
```

---

# 📁 Estrutura do Projeto

```txt
T1_Sistemas_Operacionais/
│
├── main.cpp
├── entrada.txt
├── README.md
└── .gitignore
```

---

# Algoritmos Implementados

## FCFS (First Come First Served)

Executa os processos na ordem de chegada.

---

## SJF Não Preemptivo

Executa primeiro o processo com menor duração entre os disponíveis.

---

## SJF Preemptivo (SRTF)

Sempre executa o processo com menor tempo restante.

---

## Escalonamento por Prioridade

Executa primeiro o processo de maior prioridade.

> Menor número = maior prioridade.

---

## Round Robin

Executa os processos em fatias de tempo utilizando Quantum.

---

# Entrada

O arquivo `entrada.txt` possui o seguinte formato:

```txt
2
P1 0 5 2
P2 1 3 1
P3 2 8 3
P4 3 6 2
```

## Formato:

```txt
Quantum
Nome Chegada Duracao Prioridade
```

---

# Compilação

No terminal:

```bash
g++ main.cpp -o simulador
```

---

# Execução

```bash
./simulador
```

---

# Menu do Sistema

O programa apresenta um menu interativo com as opções:

```txt
1 - Mostrar processos carregados
2 - FCFS
3 - SJF Nao Preemptivo
4 - SJF Preemptivo
5 - Prioridade
6 - Round Robin
0 - Sair
```

---

# Informações Exibidas

Ao executar os algoritmos, o sistema mostra:

- Início da execução
- Finalização dos processos
- Tempo de espera
- Tempo de retorno
- Tempo de término

---

# Controle de Versão com Git e GitHub

## Inicializar Git

```bash
git init
```

---

## Criar `.gitignore`

```bash
touch .gitignore
```

Conteúdo:

```txt
simulador
```

---

## Adicionar arquivos

```bash
git add .
```

---

## Criar commit

```bash
git commit -m "Primeira versao do simulador"
```

---

## Enviar para GitHub

```bash
git branch -M main
git push -u origin main
```

---

# Tecnologias Utilizadas

- C++
- STL (vector, queue, algorithm)
- Git
- GitHub
- VSCode
- macOS Terminal

---

# Autor

Guilherme de Araújo Brandão

---

# Disciplina

Sistemas Operacionais

---

# Observações

Projeto desenvolvido com fins acadêmicos para estudo de algoritmos de escalonamento de processos em sistemas operacionais.
