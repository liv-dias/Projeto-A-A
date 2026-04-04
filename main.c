#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NUM_IDIOMAS 3
#define NUM_LETRAS 26

const char *nomes_idiomas[] = {"Portugues", "Ingles", "Esperanto"};

// Tabela de frequências (A-Z)
const float freq_referencia[NUM_IDIOMAS][NUM_LETRAS] = {
    {14.63, 1.04, 3.88, 4.99, 12.57, 1.02, 1.30, 1.28, 6.18, 0.40, 0.02, 2.78, 4.74, 5.05, 10.73, 2.52, 1.20, 6.53, 7.81, 4.34, 4.63, 1.67, 0.01, 0.21, 0.01, 0.47},
    {8.17, 1.49, 2.78, 4.25, 12.70, 2.23, 2.02, 6.09, 6.97, 0.15, 0.77, 4.03, 2.41, 6.75, 7.51, 1.93, 0.10, 5.99, 6.33, 9.06, 2.76, 0.98, 2.36, 0.15, 1.97, 0.07},
    {12.12, 0.98, 0.78, 3.04, 9.09, 1.03, 1.17, 0.38, 10.37, 3.50, 4.16, 6.10, 2.99, 7.98, 8.77, 2.75, 0.00, 5.91, 6.09, 5.27, 3.18, 1.90, 0.00, 0.00, 0.00, 0.49}
};

int main() {
    char texto[5000];
    int contagem[NUM_LETRAS] = {0};
    int total_letras = 0;
    float freq_texto[NUM_LETRAS];

    printf("---- Identificador de Linguas (Versao Estatistica Refinada) ----\n");
    printf("Digite o texto:\n");
    if (fgets(texto, sizeof(texto), stdin) == NULL) return 1;

    // Converte para minusculo para busca de palavras e contagem de letras
    for(int i = 0; texto[i]; i++) texto[i] = tolower(texto[i]);

    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] >= 'a' && texto[i] <= 'z') {
            contagem[texto[i] - 'a']++;
            total_letras++;
        }
    }

    if (total_letras == 0) return 1;

    for (int i = 0; i < NUM_LETRAS; i++) {
        freq_texto[i] = ((float)contagem[i] / total_letras) * 100.0;
    }

    float menor_distancia = -1.0;
    int idioma_escolhido = -1;

    for (int i = 0; i < NUM_IDIOMAS; i++) {
        float distancia_atual = 0.0;
        
        for (int j = 0; j < NUM_LETRAS; j++) {
            float diff = freq_texto[j] - freq_referencia[i][j];
            float peso = 1.0;

            // PESOS ESTATISTICOS: Letras raras em PT mas comuns em EN/EO
            char letra = j + 'a';
            if (letra == 'w' || letra == 'y' || letra == 'k' || letra == 'j') {
                peso = 15.0; // Aumentamos o impacto dessas letras "assinatura"
            }
            
            distancia_atual += (diff * diff) * peso;
        }

        // AJUSTE POR PALAVRAS-CHAVE (Stopwords)
        // Se encontrar " the " ou " and ", reduzimos a distancia para o Ingles
        if (i == 1 && (strstr(texto, " the ") || strstr(texto, " and "))) distancia_atual /= 2.0;
        // Se encontrar " que " ou " para ", reduzimos para o Portugues
        if (i == 0 && (strstr(texto, " que ") || strstr(texto, " para "))) distancia_atual /= 2.0;
        // Se encontrar " kaj " ou " estas ", reduzimos para o Esperanto
        if (i == 2 && (strstr(texto, " kaj ") || strstr(texto, " estas "))) distancia_atual /= 2.0;

        if (menor_distancia < 0 || distancia_atual < menor_distancia) {
            menor_distancia = distancia_atual;
            idioma_escolhido = i;
        }
    }

    printf("\nIdioma detectado: %s\n", nomes_idiomas[idioma_escolhido]);

    return 0;
}