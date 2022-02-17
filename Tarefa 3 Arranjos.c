//Pedro Henrique Ito
//R.A: 159.515
//Batata Quente - Arranjo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define INICIO 0
#define MAXTAM 1000

typedef int TApontador;

 typedef struct 
{
    char nome[20];
}   TItem;

typedef struct 
{
    TItem Item[MAXTAM];
    TApontador Primeiro;
    TApontador Ultimo;
}   TLista;

void TLista_Inicia(TLista * pLista)
{
    pLista -> Primeiro = INICIO;
    pLista -> Ultimo = pLista -> Primeiro;
}

bool TLista_EhVazia(TLista * plista)
{
    return(plista->Primeiro == plista->Ultimo);
}

int TLista_Tamanho(TLista * pLista)
{
    return (pLista->Ultimo - pLista->Primeiro);
}

int TLista_Insere(TLista * pLista, TApontador p, TItem x)
{
    TApontador q;

    if ((pLista->Ultimo == MAXTAM) || (p < pLista->Primeiro) || (p > pLista->Ultimo))
    {
        return false;
    }

    for (q = pLista->Ultimo-1; q >=p; q--)
    {
        pLista->Item[q+1] = pLista->Item[q];
    }
    pLista->Item[p] = x;
    pLista->Ultimo++;
    
    return true;
}

int TLista_Retira(TLista * pLista, TApontador p, TItem *pX)
{
    TApontador q;

    if (TLista_EhVazia(pLista) || (p < pLista->Primeiro) || (p >= pLista->Ultimo))
    {
        return false;
    }
    
    *pX = pLista ->Item[p];
    for(q = p+1; q < pLista->Ultimo; q++)
    {
        pLista->Item[q-1] = pLista->Item[q];
    }
    pLista->Ultimo--;

    return true;  
}

int main(){
	int N;
    int K;
    int i;
    char nome[20];

	TLista * pLista;
    
    pLista = (TLista *)malloc(sizeof(TLista));

    scanf("%i %i", &N, &K);

    TItem crianca;
    
    i = 0;

    while (i<N){
        scanf("%s", nome);
        strcpy(crianca.nome, nome);
        TLista_Insere(pLista, i, crianca);
        i++;
    }

    i = K;

    while (TLista_Tamanho(pLista) > 1){
        TLista_Retira(pLista, i, &crianca);
        printf("%s\n", crianca.nome); 
        i = (i + K) % TLista_Tamanho(pLista); 
    }

    TLista_Retira(pLista, 0, &crianca);
    printf("%s", crianca.nome);

	free(pLista); 

	return false;
}
