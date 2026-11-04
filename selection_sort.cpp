#include <iostream>
#include <vector>

void selectionSort(std::vector<int>& arr) {
    int n = arr.size(); // Ob´tem o tamanho do vetor
    int comparacoes = 0; // Contador de comparações
    int trocas = 0;       // Contador de trocas

    // Percorre todo o vetor exceto o último elemento
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i; // Assume que o menor elemento está na posição i

        // Procura o menor elemento no restante do vetor não ordenado
        for (int j = i + 1; j < n; j++) {
            comparacoes++; // Incrementa o número de comparações
            if (arr[j] < arr[min_idx]) {
                min_idx = j; // Atualiza o índice do menor elemento encontrado
            }
        }

        // Se o menor elemento não estiver na posição atual i, é realizada a troca
        if (min_idx != i) {
            std::swap(arr[i], arr[min_idx]); // Troca o menor encontrado com o da posição i
            trocas++; // Incrementa o contador de trocas
        }
    }

    std::cout << "Comparacoes: " << comparacoes << ", Trocas: " << trocas << "\n";
}

int main() {
    std::vector<int> arr = {4, 2, 1, 3};
    selectionSort(arr);
    return 0;
}