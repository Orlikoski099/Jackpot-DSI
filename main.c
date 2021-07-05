#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "resources.h"

int main(void){
    int tam_vetor, nro_roletas = 3, i, flag, tentativas = 1, giro1, giro2, giro3;
    //Pega o tamanho das roletas
    printf("Insira a quantidade de números que deseja ter nas roletas: ");
    scanf("%d", &tam_vetor);

    Fila *fila[nro_roletas];
    giro1 = rand() % tam_vetor*7;
    giro2 = rand() % tam_vetor+13;
    giro3 = rand() % tam_vetor%6;

    for(i = 0; i < nro_roletas; i++)
        fila[i] = create_queue(tam_vetor);
    while(flag){
        for(i = 0; i < giro1; i++){
            enqueue(fila[0], dequeue(fila[0]));
        }
        for(i = 0; i < giro2; i++){
            enqueue(fila[1], dequeue(fila[1]));
        }
        for(i = 0; i < giro3; i++){
            enqueue(fila[2], dequeue(fila[2]));
        }
        int a = fila[0]->vetor[0];
        int b = fila[1]->vetor[0];
        int c = fila[2]->vetor[0];
        printf("%d  %d  %d\n", a, b, c);
        Sleep(300);
        if(a == b && b == c){
            printf("VOCÊ GANHOUU!! PARABÉNS!! \n Foram necessárias %d tentativas para conseguir!\n", tentativas);
            flag = 0;
        }
        tentativas++;
    }
    printf("Seu prêmio foi de: %d reais!!", tam_vetor * tentativas-1 * 10);
    for(i = 0; i < nro_roletas; i++)
        free_queue(fila[i]);
    return 0;
}

