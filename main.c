#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct{
    float a, i, e, o, n, l, s, r, t, k, j;
}Frequencias_letras;

Frequencias_letras pt = {0.146, 0.062, 0.126, 0.108, 0.050, 0.028, 0.078, 0.065, 0.043, 0.0002, 0.004};
Frequencias_letras espe = {0.121, 0.101, 0.090, 0.088, 0.078, 0.061, 0.061, 0.059, 0.053, 0.042, 0.035};
Frequencias_letras ing = {0.082, 0.097, 0.127, 0.075, 0.067, 0.040, 0.063, 0.059, 0.090, 0.007, 0.006};

int main(){
    char texto[300];
    int a=0, i=0, e=0, o=0, n=0, l=0, s=0, r=0, t=0, k=0, j = 0;
    printf("----Identificador de Línguas----\n");
    printf("Esse programa irá analisar o texto escrito e, usando probabilidades das letras, irá definir se o texto está escrito em Esperanto, Português ou Inglês");
    printf("\nDigite o texto em uma das línguas:");
    fgets(texto, 300, stdin);
    int tamanho_texto = strlen(texto);
    for (int cont = 0; cont < tamanho_texto; cont++){
        texto[cont] = tolower(texto[cont]);
    }
    for (int cont = 0; cont<tamanho_texto; cont++){
        if (texto[cont] == 'a'){
            a++;
        }
        else if(texto[cont] == 'i'){
            i++;
        }
        else if(texto[cont] == 'e'){
            e++;
        }
        else if(texto[cont] == 'o'){
            o++;
        }
        else if(texto[cont] == 'n'){
            n++;
        }
        else if(texto[cont] == 'l'){
            l++;
        }
        else if(texto[cont] == 's'){
            s++;
        }
        else if(texto[cont] == 'r'){
            r++;
        }
        else if(texto[cont] == 't'){
            t++;
        }
        else if(texto[cont] == 'k'){
            k++;
        }
        else if(texto[cont] == 'j'){
            j++;
        }
    }
    float frequencia_a = (float)a/tamanho_texto;
    float frequencia_i = (float)i/tamanho_texto;
    float frequencia_e = (float)e/tamanho_texto;
    float frequencia_o = (float)o/tamanho_texto;
    float frequencia_n = (float)n/tamanho_texto;
    float frequencia_l = (float)l/tamanho_texto;
    float frequencia_s = (float)s/tamanho_texto;
    float frequencia_r = (float)r/tamanho_texto;
    float frequencia_t = (float)t/tamanho_texto;
    float frequencia_k = (float)k/tamanho_texto;
    float frequencia_j = (float)j/tamanho_texto;

    float erro_pt = 0;
    float erro_espe = 0;
    float erro_ing = 0;
    
    //português
    erro_pt += fabs(frequencia_a - pt.a);
    erro_pt += fabs(frequencia_i - pt.i);
    erro_pt += fabs(frequencia_e - pt.e);
    erro_pt += fabs(frequencia_o - pt.o);
    erro_pt += fabs(frequencia_n - pt.n);
    erro_pt += fabs(frequencia_l - pt.l);
    erro_pt += fabs(frequencia_s - pt.s);
    erro_pt += fabs(frequencia_r - pt.r);
    erro_pt += fabs(frequencia_t - pt.t);
    erro_pt += fabs(frequencia_k - pt.k);
    erro_pt += fabs(frequencia_j - pt.j);

    //esperanto
    erro_espe += fabs(frequencia_a - espe.a);
    erro_espe += fabs(frequencia_i - espe.i);
    erro_espe += fabs(frequencia_e - espe.e);
    erro_espe += fabs(frequencia_o - espe.o);
    erro_espe += fabs(frequencia_n - espe.n);
    erro_espe += fabs(frequencia_l - espe.l);
    erro_espe += fabs(frequencia_s - espe.s);
    erro_espe += fabs(frequencia_r - espe.r);
    erro_espe += fabs(frequencia_t - espe.t);
    erro_espe += fabs(frequencia_k - espe.k);
    erro_espe += fabs(frequencia_j - espe.j);

    //inglês
    erro_ing += fabs(frequencia_a - ing.a);
    erro_ing += fabs(frequencia_i - ing.i);
    erro_ing += fabs(frequencia_e - ing.e);
    erro_ing += fabs(frequencia_o - ing.o);
    erro_ing += fabs(frequencia_n - ing.n);
    erro_ing += fabs(frequencia_l - ing.l);
    erro_ing += fabs(frequencia_s - ing.s);
    erro_ing += fabs(frequencia_r - ing.r);
    erro_ing += fabs(frequencia_t - ing.t);
    erro_ing += fabs(frequencia_k - ing.k);
    erro_ing += fabs(frequencia_j - ing.j);

    if(erro_pt < erro_ing && erro_pt < erro_espe){
        printf("O texto está escrito em Português!");
    }
    else if(erro_ing < erro_pt && erro_ing < erro_espe){
        printf("O texto está escrito em Inglês!");
    }
    else if(erro_espe < erro_pt && erro_espe < erro_ing){
        printf("O texto está escrito em Esperanto!");
    }

    return 0;

}