// Escrito por Rhuan Garcia de Assis Teixeira
#include "lista.h"

typedef struct celula Celula;

struct celula
{
    int dado;
    Celula *prox;
};

struct lista
{
    Celula *prim;
    Celula *ult;
};

Lista *IniciaLista()
{
    Lista *saida = (Lista *)malloc(sizeof(Lista));
    saida->prim = NULL;
    saida->ult = NULL;
    return saida;
}

void InsereLista(Lista *listona, int i)
{
    Celula *inserido = (Celula *)malloc(sizeof(Celula));
    inserido->dado = i;
    inserido->prox = listona->prim;
    listona->prim = inserido;

    if (listona->ult == NULL)
        listona->ult = inserido;
}

static Celula *RetiraPorCel(Celula *ref, int buscado)
{
    if (ref)
    {
        if (ref->dado == buscado)
        {
            Celula *temp = ref;
            ref = ref->prox;
            free(temp);
        }
        else
            ref->prox = RetiraPorCel(ref->prox, buscado);
    }

    return ref;
}

static Celula *BuscaUlt(Celula *ref)
{
    // Se for o ultimo
    if (ref->prox == NULL)
        return ref;

    else
        return BuscaUlt(ref->prox);
}

void RetiraLista(Lista *listona, int buscado)
{

    listona->prim = RetiraPorCel(listona->prim, buscado);

    // Nao foi passada a Lista como parametro para RetiraPorCel,
    // logo nao tem acesso a prim e ult, para contornar isso foi
    // feito BuscaUlt
    listona->ult = BuscaUlt(listona->prim);
}

static void ImprimePorCel(Celula *inic)
{
    if (inic)
    {
        printf("%i\n", inic->dado);
        ImprimePorCel(inic->prox);
    }
    else
        return;
}

void ImprimeLista(Lista *listona)
{
    Celula *impresso = listona->prim;
    ImprimePorCel(impresso);

    if (listona->ult)
        printf("Ult:%i\n", listona->ult->dado);
}

static void LiberaPorCel(Celula *inic)
{
    if (inic)
    {
        LiberaPorCel(inic->prox);
        free(inic);
    }
    else
        return;
}

void LiberaLista(Lista *listona)
{
    Celula *liberado = listona->prim;
    LiberaPorCel(liberado);
    free(listona);
}

static Celula *UltimaCelIgual(Celula *l1, Celula *l2)
{
    if (l1 && l2 && l1->dado == l2->dado)          // Se forem iguais
        return UltimaCelIgual(l1->prox, l2->prox); // Checam a prox celula

    else // Se for diferente retorne l1
        return l1;
}

int VerificaListasIguais(Lista *listona1, Lista *listona2)
{
    if (UltimaCelIgual(listona1->prim, listona2->prim) == NULL &&
        listona1->ult->dado == listona2->ult->dado)
        return 1;
    else
        return 0;
}