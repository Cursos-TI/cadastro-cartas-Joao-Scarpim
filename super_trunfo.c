#include <stdio.h>

int main() {
    // ===== Declaração das variáveis da Carta 1 =====
    char estado1;
    char codigo1[4];
    char nomeCidade1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidadePopulacional1;
    float pibPerCapita1;

    // ===== Declaração das variáveis da Carta 2 =====
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidadePopulacional2;
    float pibPerCapita2;

    // ===== Cadastro da primeira carta =====
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Digite o estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Digite o codigo da carta (ex: A01): ");
    scanf("%s", codigo1);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nomeCidade1);

    printf("Digite a populacao: ");
    scanf("%d", &populacao1);

    printf("Digite a area (em km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB (em bilhoes de reais): ");
    scanf("%f", &pib1);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos1);

    // ===== Cadastro da segunda carta =====
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Digite o estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Digite o codigo da carta (ex: B03): ");
    scanf("%s", codigo2);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nomeCidade2);

    printf("Digite a populacao: ");
    scanf("%d", &populacao2);

    printf("Digite a area (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB (em bilhoes de reais): ");
    scanf("%f", &pib2);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // ===== Cálculos automáticos =====
    densidadePopulacional1 = populacao1 / area1;
    densidadePopulacional2 = populacao2 / area2;

    pibPerCapita1 = pib1 / populacao1;
    pibPerCapita2 = pib2 / populacao2;

    // ===== Escolha dos atributos =====
    int opcao1, opcao2;
    float valor1_c1 = 0, valor1_c2 = 0;
    float valor2_c1 = 0, valor2_c2 = 0;
    char nomeAtributo1[40], nomeAtributo2[40];

    printf("\n=== Escolha dos Atributos ===\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per Capita\n");

    printf("\nEscolha o primeiro atributo (1-6): ");
    scanf("%d", &opcao1);

    // Menu dinâmico: o segundo atributo não pode ser o mesmo
    printf("\nEscolha o segundo atributo (1-6, diferente do primeiro): ");
    scanf("%d", &opcao2);

    // Validação de escolha
    if (opcao1 < 1 || opcao1 > 6 || opcao2 < 1 || opcao2 > 6 || opcao1 == opcao2) {
        printf("\nOpcao invalida! Certifique-se de escolher dois atributos diferentes entre 1 e 6.\n");
        return 1;
    }

    // ===== Atribuição dos valores com switch =====
    switch (opcao1) {
        case 1: valor1_c1 = populacao1; valor1_c2 = populacao2; sprintf(nomeAtributo1, "Populacao"); break;
        case 2: valor1_c1 = area1; valor1_c2 = area2; sprintf(nomeAtributo1, "Area"); break;
        case 3: valor1_c1 = pib1; valor1_c2 = pib2; sprintf(nomeAtributo1, "PIB"); break;
        case 4: valor1_c1 = pontosTuristicos1; valor1_c2 = pontosTuristicos2; sprintf(nomeAtributo1, "Pontos Turisticos"); break;
        case 5: valor1_c1 = densidadePopulacional1; valor1_c2 = densidadePopulacional2; sprintf(nomeAtributo1, "Densidade Populacional"); break;
        case 6: valor1_c1 = pibPerCapita1; valor1_c2 = pibPerCapita2; sprintf(nomeAtributo1, "PIB per Capita"); break;
        default: printf("Opcao invalida!\n"); return 1;
    }

    switch (opcao2) {
        case 1: valor2_c1 = populacao1; valor2_c2 = populacao2; sprintf(nomeAtributo2, "Populacao"); break;
        case 2: valor2_c1 = area1; valor2_c2 = area2; sprintf(nomeAtributo2, "Area"); break;
        case 3: valor2_c1 = pib1; valor2_c2 = pib2; sprintf(nomeAtributo2, "PIB"); break;
        case 4: valor2_c1 = pontosTuristicos1; valor2_c2 = pontosTuristicos2; sprintf(nomeAtributo2, "Pontos Turisticos"); break;
        case 5: valor2_c1 = densidadePopulacional1; valor2_c2 = densidadePopulacional2; sprintf(nomeAtributo2, "Densidade Populacional"); break;
        case 6: valor2_c1 = pibPerCapita1; valor2_c2 = pibPerCapita2; sprintf(nomeAtributo2, "PIB per Capita"); break;
        default: printf("Opcao invalida!\n"); return 1;
    }

    // ===== Comparação individual =====
    int resultado1, resultado2;

    // Regra especial: densidade populacional -> menor vence
    resultado1 = (opcao1 == 5) ? (valor1_c1 < valor1_c2 ? 1 : (valor1_c1 > valor1_c2 ? 2 : 0))
                               : (valor1_c1 > valor1_c2 ? 1 : (valor1_c1 < valor1_c2 ? 2 : 0));

    resultado2 = (opcao2 == 5) ? (valor2_c1 < valor2_c2 ? 1 : (valor2_c1 > valor2_c2 ? 2 : 0))
                               : (valor2_c1 > valor2_c2 ? 1 : (valor2_c1 < valor2_c2 ? 2 : 0));

    // ===== Soma dos atributos =====
    float soma1 = valor1_c1 + valor2_c1;
    float soma2 = valor1_c2 + valor2_c2;

    // ===== Exibição dos resultados =====
    printf("\n\n=== Comparacao das Cartas ===\n");
    printf("Carta 1: %s (%c)\n", nomeCidade1, estado1);
    printf("Carta 2: %s (%c)\n\n", nomeCidade2, estado2);

    printf("Atributo 1: %s\n", nomeAtributo1);
    printf("  %s: %.2f\n  %s: %.2f\n", nomeCidade1, valor1_c1, nomeCidade2, valor1_c2);

    printf("\nAtributo 2: %s\n", nomeAtributo2);
    printf("  %s: %.2f\n  %s: %.2f\n", nomeCidade1, valor2_c1, nomeCidade2, valor2_c2);

    printf("\nSoma total dos atributos:\n");
    printf("  %s: %.2f\n  %s: %.2f\n", nomeCidade1, soma1, nomeCidade2, soma2);

    // ===== Resultado Final =====
    if (soma1 > soma2)
        printf("\nResultado final: Carta 1 (%s) venceu!\n", nomeCidade1);
    else if (soma2 > soma1)
        printf("\nResultado final: Carta 2 (%s) venceu!\n", nomeCidade2);
    else
        printf("\nResultado final: Empate!\n");

    return 0;
}
