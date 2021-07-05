#ifndef RESOURCES_H_
#define RESOURCES_H_

#include <stdio.h>

typedef struct _fila{
   int ini;
   int fim;
   int tam;
   int *vetor;
} Fila;

void enqueue (Fila* f, int e);
int dequeue (Fila* F);
Fila* create_queue(int tamanho);
int empty (Fila *f);
int full (Fila *f);
void free_queue (Fila *f);


#endif