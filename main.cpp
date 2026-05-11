#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Processo {
    string nome;
    int chegada;
    int duracao;
    int restante;
    int prioridade;
    int inicio;
    int termino;
    int espera;
    int retorno;
};

void mostrarProcessos(vector<Processo> processos) {
    cout << "\n===== PROCESSOS CARREGADOS =====\n\n";

    for (int i = 0; i < processos.size(); i++) {
        cout << processos[i].nome
             << " | Chegada: " << processos[i].chegada
             << " | Duracao: " << processos[i].duracao
             << " | Prioridade: " << processos[i].prioridade
             << endl;
    }
}

void mostrarOrdemExecucao(vector<string> ordem) {
    cout << "\n===== ORDEM DE EXECUCAO =====\n";

    for (int i = 0; i < ordem.size(); i++) {
        cout << ordem[i];

        if (i < ordem.size() - 1) {
            cout << " -> ";
        }
    }

    cout << endl;
}

void mostrarResumo(vector<Processo> processos) {
    cout << "\n===== RESUMO =====\n";
    cout << "Processo | Chegada | Duracao | Inicio | Termino | Espera | Retorno\n";

    for (int i = 0; i < processos.size(); i++) {
        cout << processos[i].nome
             << "        | " << processos[i].chegada
             << "       | " << processos[i].duracao
             << "      | " << processos[i].inicio
             << "      | " << processos[i].termino
             << "       | " << processos[i].espera
             << "      | " << processos[i].retorno
             << endl;
    }
}

void fcfs(vector<Processo> processos) {
    cout << "\n===== FCFS =====\n";

    vector<string> ordem;

    sort(processos.begin(), processos.end(), [](Processo a, Processo b) {
        return a.chegada < b.chegada;
    });

    int tempoAtual = 0;

    for (int i = 0; i < processos.size(); i++) {
        if (tempoAtual < processos[i].chegada) {
            tempoAtual = processos[i].chegada;
        }

        processos[i].inicio = tempoAtual;

        cout << "Tempo " << tempoAtual
             << ": " << processos[i].nome
             << " iniciou execucao.\n";

        tempoAtual += processos[i].duracao;

        processos[i].termino = tempoAtual;
        processos[i].retorno = processos[i].termino - processos[i].chegada;
        processos[i].espera = processos[i].retorno - processos[i].duracao;

        ordem.push_back(
            processos[i].nome + "[" +
            to_string(processos[i].inicio) + "-" +
            to_string(processos[i].termino) + "]"
        );

        cout << "Tempo " << tempoAtual
             << ": " << processos[i].nome
             << " finalizou.\n";
    }

    mostrarOrdemExecucao(ordem);
    mostrarResumo(processos);
}

void sjfNaoPreemptivo(vector<Processo> processos) {
    cout << "\n===== SJF NAO PREEMPTIVO =====\n";

    vector<string> ordem;

    int tempoAtual = 0;
    int concluidos = 0;
    int n = processos.size();

    vector<bool> finalizado(n, false);

    while (concluidos < n) {
        int escolhido = -1;
        int menorDuracao = 999999;

        for (int i = 0; i < n; i++) {
            if (!finalizado[i] &&
                processos[i].chegada <= tempoAtual &&
                processos[i].duracao < menorDuracao) {

                menorDuracao = processos[i].duracao;
                escolhido = i;
            }
        }

        if (escolhido == -1) {
            tempoAtual++;
            continue;
        }

        processos[escolhido].inicio = tempoAtual;

        cout << "Tempo " << tempoAtual
             << ": " << processos[escolhido].nome
             << " iniciou execucao.\n";

        tempoAtual += processos[escolhido].duracao;

        processos[escolhido].termino = tempoAtual;
        processos[escolhido].retorno =
            processos[escolhido].termino - processos[escolhido].chegada;
        processos[escolhido].espera =
            processos[escolhido].retorno - processos[escolhido].duracao;

        ordem.push_back(
            processos[escolhido].nome + "[" +
            to_string(processos[escolhido].inicio) + "-" +
            to_string(processos[escolhido].termino) + "]"
        );

        cout << "Tempo " << tempoAtual
             << ": " << processos[escolhido].nome
             << " finalizou.\n";

        finalizado[escolhido] = true;
        concluidos++;
    }

    mostrarOrdemExecucao(ordem);
    mostrarResumo(processos);
}

void sjfPreemptivo(vector<Processo> processos) {
    cout << "\n===== SJF PREEMPTIVO =====\n";

    vector<string> ordem;

    int tempoAtual = 0;
    int concluidos = 0;
    int n = processos.size();

    string processoAnterior = "";
    int inicioBloco = -1;

    while (concluidos < n) {
        int escolhido = -1;
        int menorRestante = 999999;

        for (int i = 0; i < n; i++) {
            if (processos[i].chegada <= tempoAtual &&
                processos[i].restante > 0 &&
                processos[i].restante < menorRestante) {

                menorRestante = processos[i].restante;
                escolhido = i;
            }
        }

        if (escolhido == -1) {
            if (processoAnterior != "") {
                ordem.push_back(
                    processoAnterior + "[" +
                    to_string(inicioBloco) + "-" +
                    to_string(tempoAtual) + "]"
                );

                processoAnterior = "";
                inicioBloco = -1;
            }

            tempoAtual++;
            continue;
        }

        if (processos[escolhido].inicio == -1) {
            processos[escolhido].inicio = tempoAtual;
        }

        if (processoAnterior != processos[escolhido].nome) {
            if (processoAnterior != "") {
                ordem.push_back(
                    processoAnterior + "[" +
                    to_string(inicioBloco) + "-" +
                    to_string(tempoAtual) + "]"
                );
            }

            processoAnterior = processos[escolhido].nome;
            inicioBloco = tempoAtual;
        }

        cout << "Tempo " << tempoAtual
             << ": " << processos[escolhido].nome
             << " executando.\n";

        processos[escolhido].restante--;
        tempoAtual++;

        if (processos[escolhido].restante == 0) {
            processos[escolhido].termino = tempoAtual;
            processos[escolhido].retorno =
                processos[escolhido].termino - processos[escolhido].chegada;
            processos[escolhido].espera =
                processos[escolhido].retorno - processos[escolhido].duracao;

            cout << "Tempo " << tempoAtual
                 << ": " << processos[escolhido].nome
                 << " finalizou.\n";

            concluidos++;
        }
    }

    if (processoAnterior != "") {
        ordem.push_back(
            processoAnterior + "[" +
            to_string(inicioBloco) + "-" +
            to_string(tempoAtual) + "]"
        );
    }

    mostrarOrdemExecucao(ordem);
    mostrarResumo(processos);
}

void prioridade(vector<Processo> processos) {
    cout << "\n===== PRIORIDADE =====\n";

    vector<string> ordem;

    int tempoAtual = 0;
    int concluidos = 0;
    int n = processos.size();

    vector<bool> finalizado(n, false);

    while (concluidos < n) {
        int escolhido = -1;
        int maiorPrioridade = 999999;

        for (int i = 0; i < n; i++) {
            if (!finalizado[i] &&
                processos[i].chegada <= tempoAtual &&
                processos[i].prioridade < maiorPrioridade) {

                maiorPrioridade = processos[i].prioridade;
                escolhido = i;
            }
        }

        if (escolhido == -1) {
            tempoAtual++;
            continue;
        }

        processos[escolhido].inicio = tempoAtual;

        cout << "Tempo " << tempoAtual
             << ": " << processos[escolhido].nome
             << " iniciou execucao.\n";

        tempoAtual += processos[escolhido].duracao;

        processos[escolhido].termino = tempoAtual;
        processos[escolhido].retorno =
            processos[escolhido].termino - processos[escolhido].chegada;
        processos[escolhido].espera =
            processos[escolhido].retorno - processos[escolhido].duracao;

        ordem.push_back(
            processos[escolhido].nome + "[" +
            to_string(processos[escolhido].inicio) + "-" +
            to_string(processos[escolhido].termino) + "]"
        );

        cout << "Tempo " << tempoAtual
             << ": " << processos[escolhido].nome
             << " finalizou.\n";

        finalizado[escolhido] = true;
        concluidos++;
    }

    mostrarOrdemExecucao(ordem);
    mostrarResumo(processos);
}

void roundRobin(vector<Processo> processos, int quantum) {
    cout << "\n===== ROUND ROBIN =====\n";

    vector<string> ordem;

    int tempoAtual = 0;
    int concluidos = 0;
    int n = processos.size();

    queue<int> fila;
    vector<bool> entrouNaFila(n, false);

    while (concluidos < n) {

        for (int i = 0; i < n; i++) {
            if (!entrouNaFila[i] && processos[i].chegada <= tempoAtual) {
                fila.push(i);
                entrouNaFila[i] = true;
            }
        }

        if (fila.empty()) {
            tempoAtual++;
            continue;
        }

        int atual = fila.front();
        fila.pop();

        if (processos[atual].inicio == -1) {
            processos[atual].inicio = tempoAtual;
        }

        int inicioExecucao = tempoAtual;
        int tempoExecucao;

        if (processos[atual].restante > quantum) {
            tempoExecucao = quantum;
        } else {
            tempoExecucao = processos[atual].restante;
        }

        cout << "Tempo " << tempoAtual
             << ": " << processos[atual].nome
             << " executando por " << tempoExecucao
             << " unidade(s).\n";

        processos[atual].restante -= tempoExecucao;
        tempoAtual += tempoExecucao;

        ordem.push_back(
            processos[atual].nome + "[" +
            to_string(inicioExecucao) + "-" +
            to_string(tempoAtual) + "]"
        );

        for (int i = 0; i < n; i++) {
            if (!entrouNaFila[i] && processos[i].chegada <= tempoAtual) {
                fila.push(i);
                entrouNaFila[i] = true;
            }
        }

        if (processos[atual].restante > 0) {
            fila.push(atual);

            cout << "Tempo " << tempoAtual
                 << ": " << processos[atual].nome
                 << " voltou para a fila.\n";
        } else {
            processos[atual].termino = tempoAtual;
            processos[atual].retorno =
                processos[atual].termino - processos[atual].chegada;
            processos[atual].espera =
                processos[atual].retorno - processos[atual].duracao;

            cout << "Tempo " << tempoAtual
                 << ": " << processos[atual].nome
                 << " finalizou.\n";

            concluidos++;
        }
    }

    mostrarOrdemExecucao(ordem);
    mostrarResumo(processos);
}

int main() {
    vector<Processo> processos;
    int opcao;

    ifstream arquivo("entrada.txt");

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo entrada.txt" << endl;
        return 1;
    }

    Processo processo;

    while (
        arquivo >> processo.nome
                >> processo.chegada
                >> processo.duracao
                >> processo.prioridade
    ) {
        processo.restante = processo.duracao;
        processo.inicio = -1;
        processo.termino = 0;
        processo.espera = 0;
        processo.retorno = 0;

        processos.push_back(processo);
    }

    arquivo.close();

    do {
        cout << "\n===== SIMULADOR DE ESCALONAMENTO =====\n";
        cout << "1 - Mostrar processos carregados\n";
        cout << "2 - FCFS\n";
        cout << "3 - SJF Nao Preemptivo\n";
        cout << "4 - SJF Preemptivo\n";
        cout << "5 - Prioridade\n";
        cout << "6 - Round Robin\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                mostrarProcessos(processos);
                break;

            case 2:
                fcfs(processos);
                break;

            case 3:
                sjfNaoPreemptivo(processos);
                break;

            case 4:
                sjfPreemptivo(processos);
                break;

            case 5:
                prioridade(processos);
                break;

            case 6: {
                int quantum;

                cout << "Informe o quantum: ";
                cin >> quantum;

                roundRobin(processos, quantum);
                break;
            }

            case 0:
                cout << "\nEncerrando simulador.\n";
                break;

            default:
                cout << "\nOpcao invalida.\n";
        }

    } while (opcao != 0);

    return 0;
}