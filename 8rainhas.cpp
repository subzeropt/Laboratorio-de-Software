#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

const int N = 8;

bool podeColocar(const vector<int>& tabuleiro, int linha, int coluna) {
    for (int i = 0; i < linha; i++) {
        if (tabuleiro[i] == coluna ||
            abs(tabuleiro[i] - coluna) == abs(i - linha)) {
            return false;
        }
    }
    return true;
}

void dfs() {
    // Cada elemento da pilha representa um estado parcial do tabuleiro
    stack<vector<int>> pilha;
    pilha.push(vector<int>());  // Começamos com um tabuleiro vazio


    // enquanto a pilha estiver vazia; defenimos o estado atual como sendo o topo da pilha e retiramos esse element0
    while (!pilha.empty()) {
        vector<int> estadoAtual = pilha.top();
        pilha.pop();

        // Defenimos a linha atual como sendo o tamanho do vetor
        int linhaAtual = estadoAtual.size();

        // Verifica se uma solução foi encontrada (8 rainhas colocadas)
        if (linhaAtual == N) {
            for (int i = 0; i < N; i++) {
                cout << "(" << i << "," << estadoAtual[i] << ") ";
            }
            cout << endl;
            continue;
        }

        // Gera todos os possíveis sucessores (colunas válidas para a próxima linha)
        for (int coluna = N - 1; coluna >= 0; coluna--) {
            if (podeColocar(estadoAtual, linhaAtual, coluna)) {
                vector<int> novoEstado = estadoAtual;
                novoEstado.push_back(coluna);
                pilha.push(novoEstado);
            }
        }
    }
}

int main() {
    dfs();
    return 0;
}
