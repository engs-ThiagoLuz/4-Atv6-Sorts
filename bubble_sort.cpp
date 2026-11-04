#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size(); // Obtém o tamanho do vetor
    int comparacoes = 0; // Contador de comparações
    int trocas = 0;       // Contador de trocas

    // Laço externo para controlar o número de passagens
    for (int i = 0; i < n - 1; i++) {
        // Laço interno para comparar elementos adjacentes
        for (int j = 0; j < n - i - 1; j++) {
            comparacoes++; // Incrementa cada vez que faz uma comparação
            // Se o elemento atual for maior que o próximo, é realizada a troca
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]); // Troca os elementos de posição
                trocas++; // Incrementa o contador de trocas
            }
        }
    }

    std::cout << "Comparacoes: " << comparacoes << ", Trocas: " << trocas << "\n";
}

int main() {
    std::vector<int> arr = {4, 2, 1, 3};
    bubbleSort(arr);
    return 0;
}