#include <stdio.h>

typedef struct{
    float a, e, o, t, h, j, s, k, y, w, q;
}Frequencias_letras;

Frequencias_letras pt = {0.146, 0.125, 0.107, 0.045, 0.013, 0.004, 0.107, 0.001, 0.001, 0.001, 0.018};
Frequencias_letras espe = {};
Frequencias_letras ing = {};

int main(){
    float frequencia_port = [];
    char texto[300];
    printf("----Identificador de Línguas----\n");
    printf("Esse programa irá analisar o texto escrito e, usando probabilidades das letras, irá definir se o texto está escrito em Esperanto, Português ou Inglês");
    printf("\nDigite o texto em uma das línguas:");
    scanf("%s", texto);
}