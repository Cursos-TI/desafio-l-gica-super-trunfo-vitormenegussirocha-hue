#include <stdio.h>
#include <string.h>

// Estrutura da carta de país
typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
} Carta;

// Função para calcular densidade demográfica
float calcularDensidade(int populacao, float area) {
    return populacao / area;
}

// Função para exibir o menu de atributos
void exibirMenu(int atributosDisponiveis[5]) {
    printf("\nEscolha um atributo para comparar:\n");
    if (atributosDisponiveis[0]) printf("1 - População\n");
    if (atributosDisponiveis[1]) printf("2 - Área\n");
    if (atributosDisponiveis[2]) printf("3 - PIB\n");
    if (atributosDisponiveis[3]) printf("4 - Pontos Turísticos\n");
    if (atributosDisponiveis[4]) printf("5 - Densidade Demográfica\n");
    printf("Digite a opção: ");
}

// Função para obter valor do atributo
float obterValorAtributo(Carta carta, int atributo) {
    switch(atributo) {
        case 1: return (float)carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return (float)carta.pontosTuristicos;
        case 5: return carta.densidade;
        default: return 0;
    }
}

// Função para obter o nome do atributo
const char* nomeAtributo(int atributo) {
    switch(atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

int main() {
    // Cartas pré-definidas
    Carta carta1 = {"Brasil", 213000000, 8515767.0, 1868000000000.0, 25, 0};
    Carta carta2 = {"Canadá", 38000000, 9984670.0, 1736000000000.0, 15, 0};

    // Cálculo das densidades
    carta1.densidade = calcularDensidade(carta1.populacao, carta1.area);
    carta2.densidade = calcularDensidade(carta2.populacao, carta2.area);

    int atributosDisponiveis[5] = {1, 1, 1, 1, 1};
    int attr1 = 0, attr2 = 0;

    // Menu dinâmico para escolher o primeiro atributo
    exibirMenu(atributosDisponiveis);
    scanf("%d", &attr1);

    if (attr1 < 1 || attr1 > 5) {
        printf("Atributo inválido! Encerrando...\n");
        return 1;
    }
    atributosDisponiveis[attr1 - 1] = 0; // Desabilita o atributo escolhido

    // Menu dinâmico para escolher o segundo atributo
    exibirMenu(atributosDisponiveis);
    scanf("%d", &attr2);

    if (attr2 < 1 || attr2 > 5 || attr2 == attr1) {
        printf("Atributo inválido ou repetido! Encerrando...\n");
        return 1;
    }

    // Obter os valores dos atributos escolhidos para cada carta
    float valor1_attr1 = obterValorAtributo(carta1, attr1);
    float valor2_attr1 = obterValorAtributo(carta2, attr1);

    float valor1_attr2 = obterValorAtributo(carta1, attr2);
    float valor2_attr2 = obterValorAtributo(carta2, attr2);

    // Exibição dos atributos comparados
    printf("\n=== Comparação de Cartas ===\n");
    printf("Carta 1: %s\n", carta1.nome);
    printf("Carta 2: %s\n\n", carta2.nome);

    // Comparação do primeiro atributo
    printf("Atributo 1: %s\n", nomeAtributo(attr1));
    printf("%s: %.2f\n", carta1.nome, valor1_attr1);
    printf("%s: %.2f\n", carta2.nome, valor2_attr1);
    int ponto1 = (attr1 == 5) ? (valor1_attr1 < valor2_attr1) : (valor1_attr1 > valor2_attr1);
    int ponto2 = (attr1 == 5) ? (valor2_attr1 < valor1_attr1) : (valor2_attr1 > valor1_attr1);

    // Comparação do segundo atributo
    printf("\nAtributo 2: %s\n", nomeAtributo(attr2));
    printf("%s: %.2f\n", carta1.nome, valor1_attr2);
    printf("%s: %.2f\n", carta2.nome, valor2_attr2);
    ponto1 += (attr2 == 5) ? (valor1_attr2 < valor2_attr2) : (valor1_attr2 > valor2_attr2);
    ponto2 += (attr2 == 5) ? (valor2_attr2 < valor1_attr2) : (valor2_attr2 > valor1_attr2);

    // Soma total dos valores dos dois atributos
    float soma1 = valor1_attr1 + valor1_attr2;
    float soma2 = valor2_attr1 + valor2_attr2;

    printf("\nSoma dos Atributos:\n");
    printf("%s: %.2f\n", carta1.nome, soma1);
    printf("%s: %.2f\n", carta2.nome, soma2);

    // Resultado final usando operador ternário
    printf("\nResultado Final: ");
    if (soma1 > soma2)
        printf("%s venceu!\n", carta1.nome);
    else if (soma2 > soma1)
        printf("%s venceu!\n", carta2.nome);
    else
        printf("Empate!\n");

    return 0;
}
