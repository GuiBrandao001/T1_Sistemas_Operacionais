# T1 - Simulador de Escalonamento de Processos

Trabalho desenvolvido para a disciplina de Sistemas Operacionais utilizando C++.

---

# Objetivo

O projeto consiste na implementação de um simulador de escalonamento de processos capaz de executar diferentes algoritmos utilizados por sistemas operacionais para gerenciamento da CPU.

O simulador realiza:

- Leitura de processos via arquivo
- Simulação dos algoritmos de escalonamento
- Exibição da execução dos processos
- Exibição da ordem de processamento
- Cálculo de métricas:
  - Tempo de espera
  - Tempo de retorno
  - Tempo de término

---

# Estrutura do Projeto

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

O algoritmo FCFS executa os processos na ordem em que chegam na fila.

Características:

- Não preemptivo
- Simples implementação
- Pode gerar efeito de fila longa
- O primeiro processo ocupa a CPU até finalizar

Exemplo:

```txt
P1 -> P2 -> P3 -> P4
```

---

## SJF Não Preemptivo

O algoritmo SJF (Shortest Job First) escolhe o processo com menor duração entre os disponíveis.

Características:

- Não preemptivo
- Reduz tempo médio de espera
- Processos menores possuem prioridade natural
- O processo executa até finalizar

Exemplo:

```txt
P2 -> P4 -> P3 -> P1
```

---

## SJF Preemptivo (SRTF)

O algoritmo SJF Preemptivo (Shortest Remaining Time First) sempre executa o processo com menor tempo restante.

Características:

- Preemptivo
- Pode interromper processos em execução
- Melhora o tempo médio de retorno
- Troca constantemente o processo ativo quando aparece um menor

Exemplo:

```txt
P1 -> P2 -> P1 -> P4 -> P3
```

---

## Escalonamento por Prioridade

O algoritmo de Prioridade executa primeiro o processo com maior prioridade.

No projeto:

```txt
Menor número = maior prioridade
```

Características:

- Não preemptivo
- Processos mais importantes executam primeiro
- Pode causar starvation em processos de baixa prioridade

Exemplo:

```txt
P2 -> P1 -> P4 -> P3
```

---

## Round Robin

O algoritmo Round Robin executa os processos utilizando fatias de tempo chamadas Quantum.

Características:

- Preemptivo
- Cada processo utiliza a CPU por um tempo limitado
- Após o quantum, o processo volta para a fila
- Muito utilizado em sistemas interativos

O Quantum é informado diretamente no terminal durante a execução do algoritmo.

Exemplo:

```txt
P1 -> P2 -> P3 -> P4 -> P1 ...
```

---

# Entrada

O arquivo `entrada.txt` possui o seguinte formato:

```txt
P1 0 10 2
P2 3 5 1
P3 5 8 3
P4 7 4 2
```

Formato:

```txt
Nome Chegada Duracao Prioridade
```

Onde:

- Nome = identificação do processo
- Chegada = instante de chegada
- Duracao = tempo necessário de CPU
- Prioridade = prioridade do processo

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
- Ordem de execução
- Tempo de espera
- Tempo de retorno
- Tempo de término

---

# Exemplo de Execução

```txt
Tempo 0: P1 iniciou execucao.
Tempo 10: P1 finalizou.
Tempo 10: P2 iniciou execucao.
Tempo 15: P2 finalizou.
```

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
- STL
- Vector
- Queue
- Algorithm
- Git
- GitHub
- VSCode

---

# Autor

Guilherme de Araújo Brandão

---

# Disciplina

Sistemas Operacionais

---

# Observações

Projeto desenvolvido com fins acadêmicos para estudo de algoritmos de escalonamento de processos em sistemas operacionais.
