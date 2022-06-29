// Escrito por Rhuan Garcia de Assis Teixeira

#include "lista.h"

int main()
{
    Lista *gladiadora = IniciaLista();

    ImprimeLista(gladiadora);

    InsereLista(gladiadora, 5);
    InsereLista(gladiadora, 4);
    InsereLista(gladiadora, 3);

    ImprimeLista(gladiadora);

    printf("Retira elemento 4\n");
    RetiraLista(gladiadora, 4);
    ImprimeLista(gladiadora);

    printf("Retira elemento 3\n");
    RetiraLista(gladiadora, 3);
    ImprimeLista(gladiadora);

    InsereLista(gladiadora, 3);
    ImprimeLista(gladiadora);

    printf("Retira elemento 5\n");
    RetiraLista(gladiadora, 5);
    ImprimeLista(gladiadora);

    Lista *birken = IniciaLista();
    InsereLista(birken, 3);
    ImprimeLista(birken);

    if (VerificaListasIguais(gladiadora, birken))
        printf("Iguais\n");
    else
        printf("Diferentes\n");

    InsereLista(birken, 7);
    ImprimeLista(birken);

    if (VerificaListasIguais(gladiadora, birken))
        printf("Iguais\n");
    else
        printf("Diferentes\n");

    LiberaLista(gladiadora);
    LiberaLista(birken);

    return 0;
}