#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    int n = arr.size(); // Obtém o tamanho do vetor
    int comparacoes = 0; // Contador de comparações
    int trocas = 0;       // Contador de deslocamentos/trocas

    // Começa do segundo elemento (1)
    for (int i = 1; i < n; i++) {
        int chave = arr[i]; // Guarda o valor a ser inserido na parte ordenada
        int j = i - 1;

        // Move os elementos maiores que a chave para uma posição à frente
        while (j >= 0) {
            comparacoes++; // Incrementa comparação do loop
            if (arr[j] > chave) {
                arr[j + 1] = arr[j]; // Desloca o elemento para a direita
                trocas++;            // Conta o deslocamento como troca
                j--;
            } else {
                break; // Se encontrou elemento menor ou igual, para a busca
            }
        }
        arr[j + 1] = chave; // Insere a chave na sua posição correta
    }

    std::cout << "Comparacoes: " << comparacoes << ", Trocas (Deslocamentos): " << trocas << "\n";
}

int main() {
    std::vector<int> arr = {4, 2, 1, 3};
    insertionSort(arr);
    return 0;
}