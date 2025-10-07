#include <stdio.h>
#include <string.h>

// Estrutura de uma carta
typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
} Carta;

// Funções auxiliares
float calcularDensidade(int populacao, float area) {
    return populacao / area;
}

void exibirMenu() {
    printf("\n=== Super Trunfo - Comparação de Cartas ===\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite a opção desejada: ");
}

int main() {
    // Cartas pré-definidas
    Carta carta1 = {"Brasil", 213000000, 8515767.0, 1868000000000.0, 25};
    Carta carta2 = {"Canadá", 38000000, 9984670.0, 1736000000000.0, 15};

    // Calculando densidade demográfica
    carta1.densidadeDemografica = calcularDensidade(carta1.populacao, carta1.area);
    carta2.densidadeDemografica = calcularDensidade(carta2.populacao, carta2.area);

    int opcao;
    exibirMenu();
    scanf("%d", &opcao);

    printf("\nComparando %s x %s\n", carta1.nome, carta2.nome);

    switch(opcao) {
        case 1: // População
            printf("Atributo: População\n");
            printf("%s: %d habitantes\n", carta1.nome, carta1.populacao);
            printf("%s: %d habitantes\n", carta2.nome, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: %s venceu!\n", carta1.nome);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Resultado: %s venceu!\n", carta2.nome);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2: // Área
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", carta1.nome, carta1.area);
            printf("%s: %.2f km²\n", carta2.nome, carta2.area);
            if (carta1.area > carta2.area) {
                printf("Resultado: %s venceu!\n", carta1.nome);
            } else if (carta2.area > carta1.area) {
                printf("Resultado: %s venceu!\n", carta2.nome);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("%s: R$ %.2f trilhões\n", carta1.nome, carta1.pib / 1e12);
            printf("%s: R$ %.2f trilhões\n", carta2.nome, carta2.pib / 1e12);
            if (carta1.pib > carta2.pib) {
                printf("Resultado: %s venceu!\n", carta1.nome);
            } else if (carta2.pib > carta1.pib) {
                printf("Resultado: %s venceu!\n", carta2.nome);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4: // Pontos turísticos
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d pontos\n", carta1.nome, carta1.pontosTuristicos);
            printf("%s: %d pontos\n", carta2.nome, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Resultado: %s venceu!\n", carta1.nome);
            } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                printf("Resultado: %s venceu!\n", carta2.nome);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5: // Densidade Demográfica (menor vence!)
            printf("Atributo: Densidade Demográfica\n");
            printf("%s: %.2f hab/km²\n", carta1.nome, carta1.densidadeDemografica);
            printf("%s: %.2f hab/km²\n", carta2.nome, carta2.densidadeDemografica);
            if (carta1.densidadeDemografica < carta2.densidadeDemografica) {
                printf("Resultado: %s venceu!\n", carta1.nome);
            } else if (carta2.densidadeDemografica < carta1.densidadeDemografica) {
                printf("Resultado: %s venceu!\n", carta2.nome);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            printf("Opção inválida. Por favor, escolha um número de 1 a 5.\n");
    }

    return 0;
}
