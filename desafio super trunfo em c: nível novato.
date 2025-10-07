#include <stdio.h>
#include <string.h>

// Definição da estrutura da carta
typedef struct {
    char estado[30];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função para calcular densidade populacional
float calcularDensidade(int populacao, float area) {
    return populacao / area;
}

// Função para calcular PIB per capita
float calcularPIBPerCapita(float pib, int populacao) {
    return pib / populacao;
}

int main() {
    // Cadastro de duas cartas fixas
    Carta carta1 = {
        "SP",
        "C001",
        "São Paulo",
        12300000,
        1521.11,
        230000000000.0,
        25
    };

    Carta carta2 = {
        "RJ",
        "C002",
        "Rio de Janeiro",
        6000000,
        1200.27,
        190000000000.0,
        18
    };

    // Calcula densidade populacional e PIB per capita das cartas
    carta1.densidadePopulacional = calcularDensidade(carta1.populacao, carta1.area);
    carta1.pibPerCapita = calcularPIBPerCapita(carta1.pib, carta1.populacao);

    carta2.densidadePopulacional = calcularDensidade(carta2.populacao, carta2.area);
    carta2.pibPerCapita = calcularPIBPerCapita(carta2.pib, carta2.populacao);

    // Escolha do atributo a ser comparado - altere aqui se desejar comparar outro atributo
    // Opções: populacao, area, pib, densidadePopulacional, pibPerCapita
    // Para este exemplo, vamos comparar População
    printf("Comparação de cartas (Atributo: População):\n\n");

    printf("Carta 1 - %s (%s): %d\n", carta1.cidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d\n\n", carta2.cidade, carta2.estado, carta2.populacao);

    // Lógica de comparação usando if-else
    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("Resultado: Empate! Ambas as cartas têm a mesma população.\n");
    }

    return 0;
}
