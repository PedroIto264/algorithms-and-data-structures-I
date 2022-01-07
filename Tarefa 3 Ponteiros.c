//Pedro Henrique Ito
//R.A: 159.515
//Batata Quente - Apontadores
//100% Sharif Judge

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>


typedef int TChave;

typedef struct 
{
    TChave Chave;
    char nome[20];
}   TItem;

typedef struct SCelula *TApontador;

typedef struct SCelula
{
    TItem Item;
    TApontador Prox;
}   TCelula;

typedef struct 
{
    TApontador Primeiro;
    TApontador Ultimo;
    int Tamanho;
}   TLista;

void TLista_Inicia (TLista *pLista)
{
    pLista->Primeiro = NULL;
    pLista->Ultimo = NULL;
    pLista->Tamanho = 0;
}

bool TLista_EhVazia (TLista *pLista)
{
    return (pLista->Primeiro == NULL);
}

TApontador TLista_Retorna (TLista *pLista, int p)
{
    TApontador pApontador;
    int Posicao = 0;

    pApontador = pLista->Primeiro;
    while ((pApontador != NULL) && (Posicao != p))
    {
        pApontador = pApontador->Prox;
        Posicao++;
    }

    return pApontador;
}

int TLista_InserePrimeiro (TLista *pLista, TItem x)
{
    TApontador pNovo;

    pNovo = (TApontador) malloc (sizeof(TCelula));

    pNovo->Item = x;
    pNovo->Prox = pLista->Primeiro;

    if (TLista_EhVazia(pLista))
    {
        pLista->Ultimo = pNovo;
    }

    pLista->Primeiro = pNovo;
    pLista->Tamanho++;
    
    return true;
}

int TLista_InsereUltimo (TLista *pLista, TItem x)
{
    TApontador pNovo;

    pNovo = (TApontador) malloc(sizeof(TCelula));
    pNovo->Item = x;
    pNovo->Prox = NULL;

    if (TLista_EhVazia(pLista))
    {
    pLista->Primeiro = pNovo;
    }
    else
    {
        pLista->Ultimo->Prox = pNovo;
    }

    pLista->Ultimo = pNovo;
    pLista->Tamanho++;
    return true;
}

int TLista_Insere (TLista *pLista, TApontador p, TItem x)
{
    TApontador pAnterior, pNovo;
    if (p == pLista->Primeiro)
    {
        return TLista_InserePrimeiro(pLista, x);
    }
    else 
    {
        if (p == NULL)
        {
            return TLista_InsereUltimo(pLista, x);
        }
        else
        {
            pAnterior = pLista->Primeiro;

            while ((pAnterior != pLista->Ultimo) && (pAnterior->Prox != p))
                pAnterior = pAnterior->Prox;

            if (pAnterior == pLista->Ultimo)
                return false;

            pNovo = (TApontador) malloc(sizeof(TCelula));

            pNovo->Item = x;
            pNovo->Prox = pAnterior->Prox;
            pAnterior->Prox = pNovo;
            pLista->Tamanho++;

            return true;
        }
    }
        
}

int TLista_RetiraPrimeiro (TLista *pLista, TItem *pX)
{
    TApontador pAux;

    if (TLista_EhVazia(pLista))
    {
        return false;
    }

    pAux = pLista->Primeiro;
    pLista->Primeiro = pAux->Prox;
    *pX = pAux->Item;

    free(pAux);
    pLista->Tamanho--;
    return true;
}

int TLista_RetiraUltimo (TLista *pLista, TItem *pX)
{
    TApontador pAnterior, pAux;
    pAnterior = pLista->Primeiro;

    if (pAnterior == pLista->Ultimo)
    {
        return TLista_RetiraPrimeiro(pLista, pX);
    }

    else 
    {
        while (pAnterior->Prox != pLista->Ultimo)
        {
            pAnterior = pAnterior->Prox;  
        }

        pAux = pLista->Ultimo;
        pAnterior->Prox = NULL;
        pLista->Ultimo = pAnterior;
        *pX = pAux->Item;

        free(pAux);
        pLista->Tamanho--;
        return true;
    }
}

int TLista_Retira (TLista *pLista, TApontador p, TItem *pX)
{
    TApontador pAnterior, pAux;

    if (p == pLista->Primeiro)
    {
        return TLista_RetiraPrimeiro(pLista, pX); 
    }
    else
    {
        if (p == pLista->Ultimo)
        {
            return TLista_RetiraUltimo(pLista, pX);
        }
        else 
        {
            pAnterior = pLista->Primeiro;
            while ((pAnterior != pLista->Ultimo) && (pAnterior->Prox != p)){
                pAnterior = pAnterior->Prox; 
            }
            if (pAnterior == pLista->Ultimo)
                return false;
            pAux = pAnterior->Prox;
            pAnterior->Prox = pAux->Prox;
            *pX = pAux->Item;
            free(pAux);
            pLista->Tamanho--;
            return true;
            }
    }
        
}

int TLista_Tamanho (TLista *pLista)
{
    return (pLista->Tamanho);
}

int main ()
{
    int N; 
    int K;
    int i;
    char nome[20];

    scanf("%i %i", &N, &K);

    TLista * pLista_de_criancas = (TLista *) malloc(sizeof(TLista));
    TLista_Inicia(pLista_de_criancas);

    TItem crianca;

    i = 0;

    while (i<N)
    {
        scanf("%s", nome);
        strcpy(crianca.nome, nome);
        TLista_Insere(pLista_de_criancas, TLista_Retorna(pLista_de_criancas, i), crianca);
        i++;
    }

    i = K;

    while (TLista_Tamanho(pLista_de_criancas) > 1){
        TLista_Retira(pLista_de_criancas, TLista_Retorna(pLista_de_criancas, i), &crianca);
        printf("%s\n", crianca.nome);
        i = (i + K) % TLista_Tamanho(pLista_de_criancas);
    }

    TLista_Retira(pLista_de_criancas, TLista_Retorna(pLista_de_criancas, 0), &crianca);
    printf("%s", crianca.nome);

    free(pLista_de_criancas);   
    return false;
}