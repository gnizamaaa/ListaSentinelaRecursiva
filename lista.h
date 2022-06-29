#include <stdio.h>
#include <stdlib.h>

// Escrito por Rhuan Garcia de Assis Teixeira

#ifndef LISTA_H
#define LISTA_H

typedef struct lista Lista;

Lista *IniciaLista();
void InsereLista(Lista *listona, int i);
void RetiraLista(Lista *listona, int buscado);
void ImprimeLista(Lista *listona);
void LiberaLista(Lista *listona);

int VerificaListasIguais(Lista *listona1, Lista *listona2);

#endif