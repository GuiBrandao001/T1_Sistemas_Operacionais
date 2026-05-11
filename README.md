# T1 - Simulador de Escalonamento

Trabalho desenvolvido para a disciplina de Sistemas Operacionais utilizando C++.

O projeto simula diferentes algoritmos de escalonamento de processos utilizados em sistemas operacionais.

O sistema realiza:

- leitura dos processos por arquivo
- execução dos algoritmos
- exibição da ordem de processamento
- cálculo de métricas dos processos

As métricas exibidas são:

- tempo de espera
- tempo de retorno
- tempo de término

## Estrutura do Projeto

```txt
T1_Sistemas_Operacionais/
│
├── main.cpp
├── entrada.txt
├── README.md
└── .gitignore
```

## Algoritmos Implementados

### FCFS

Executa os processos na ordem de chegada.

### SJF Não Preemptivo

Executa primeiro o processo com menor duração entre os disponíveis.

### SJF Preemptivo (SRTF)

Executa sempre o processo com menor tempo restante.

### Prioridade

Executa primeiro o processo com maior prioridade.

No projeto:

```txt
Menor número = maior prioridade
```

### Round Robin

Executa os processos utilizando fatias de tempo (quantum).

O quantum é informado diretamente no terminal durante a execução.

## Entrada

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
- Duracao = tempo de CPU necessário
- Prioridade = prioridade do processo

## Compilação

No terminal:

```bash
g++ main.cpp -o simulador
```

## Execução

```bash
./simulador
```

## Menu do Sistema

```txt
1 - Mostrar processos carregados
2 - FCFS
3 - SJF Nao Preemptivo
4 - SJF Preemptivo
5 - Prioridade
6 - Round Robin
0 - Sair
```

## Informações Exibidas

Durante a execução dos algoritmos o sistema mostra:

- início da execução
- finalização dos processos
- ordem de execução
- tempo de espera
- tempo de retorno
- tempo de término

## Exemplo de Saída

```txt
Tempo 0: P1 iniciou execucao.
Tempo 10: P1 finalizou.

Tempo 10: P2 iniciou execucao.
Tempo 15: P2 finalizou.
```

## Tecnologias Utilizadas

- C++
- STL
- VSCode

## Autor

Guilherme de Araújo Brandão

## Disciplina

Sistemas Operacionais
