#include <iostream>
#include <vector>

int comparacoes = 0; // Variável global para contar comparações
int trocas = 0;       // Variável global para contar atribuições/trocas

// Função para intercalar (merge) duas metades ordenadas
void merge(std::vector<int>& arr, int esquerda, int meio, int direita) {
    int n1 = meio - esquerda + 1; // Tamanho do subvetor esquerdo
    int n2 = direita - meio;      // Tamanho do subvetor direito

    // Vetores temporários
    std::vector<int> L(n1), R(n2);

    // Copia os dados para os vetores temporários
    for (int i = 0; i < n1; i++) L[i] = arr[esquerda + i];
    for (int j = 0; j < n2; j++) R[j] = arr[meio + 1 + j];

    int i = 0, j = 0, k = esquerda;

    // Intercala as duas metades de volta no vetor principal
    while (i < n1 && j < n2) {
        comparacoes++; // Incrementa contagem de comparações
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        trocas++; // Conta a gravação no vetor principal como troca/atribuição
        k++;
    }

    // Copia os elementos restantes de L, se houver
    while (i < n1) {
        arr[k] = L[i];
        i++; k++; trocas++;
    }

    // Copia os elementos restantes de R, se houver
    while (j < n2) {
        arr[k] = R[j];
        j++; k++; trocas++;
    }
}

// Função principal do Merge Sort
void mergeSort(std::vector<int>& arr, int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2; // Encontra o ponto médio

        mergeSort(arr, esquerda, meio);      // Ordena a primeira metade
        mergeSort(arr, meio + 1, direita);  // Ordena a segunda metade
        merge(arr, esquerda, meio, direita); // Intercala as duas metades
    }
}

int main() {
    std::vector<int> arr = {4, 2, 1, 3};
    mergeSort(arr, 0, arr.size() - 1);
    std::cout << "Comparacoes: " << comparacoes << ", Trocas (Atribuicoes): " << trocas << "\n";
    return 0;
}