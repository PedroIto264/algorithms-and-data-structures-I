//Pedro Henrique Ito
//R.A: 159.515
//Torneio de Luta de Braço - Apontadores
//100% Sharif Judge
 
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include <stdbool.h>
 
typedef int TChave;
 
typedef struct 
{
    TChave Chave; 
    int Forca1,Forca2;
}   TItem;
 
typedef struct SCelula *TApontador;
 
typedef struct SCelula
{
    TItem Item;
    TApontador Prox;
}   TCelula;
 
typedef struct 
{
    TApontador Frente;
    TApontador Tras;
    int Tamanho;
}   TFila;
 
void TFila_Inicia (TFila *pFila)
{
    pFila->Frente = NULL;
    pFila->Tras = NULL;
    pFila->Tamanho = 0;
}
 
bool TFila_EhVazia (TFila *pFila)
{
    return (pFila->Frente == NULL);
}
 
int TFila_Enfileira (TFila *pFila, TItem x) 
{
    TApontador pNovo;
 
    pNovo = (TApontador) malloc(sizeof(TCelula));
    pNovo->Item = x;
    pNovo->Prox = NULL;
 
    if (TFila_EhVazia(pFila))
        pFila->Frente = pNovo;
    else 
        pFila->Tras->Prox = pNovo;
 
    pFila->Tras = pNovo;
    pFila->Tamanho++;
 
    return true;
}
 
int TFila_Desenfileira (TFila *pFila, TItem *pX)
{
    TApontador aux;
 
    if (TFila_EhVazia(pFila)){
        return false;
    }
    aux = pFila->Frente;
    pFila->Frente = aux->Prox;
    *pX = aux->Item;
    pFila->Tamanho--;
    free(aux);
 
    return true; 
}
 
int TFila_Tamanho (TFila *pFila)
{
    return (pFila->Tamanho);
}
 
int main ()
{
    int *pN;
    int *pK;
    int pi;
 
    pN = (int *) malloc(sizeof(int));
    pK = (int *) malloc(sizeof(int));
    pi = 0;
    
    scanf("%d %d", pN, pK);
 
    TFila * pFilaLutadores;
    pFilaLutadores = (TFila *) malloc (sizeof(TFila));

    TItem x;
 
    while (pi<pow(2,*pN))
    {
        x.Chave = pi + 1;
        scanf("%d", &x.Forca1);
        x.Forca2 = x.Forca1;
        ++pi;
        if (TFila_Enfileira(pFilaLutadores, x) == 0);
    }
 
    free(pN);
 
    TItem lutador1;
    TItem lutador2;
 
    while (pFilaLutadores->Tamanho != 1)
    {
        if (TFila_Desenfileira(pFilaLutadores, &lutador1) == 0 || TFila_Desenfileira(pFilaLutadores, &lutador2) == 0);
 
        if (lutador1.Forca2 >= lutador2.Forca2)
        {
            lutador1.Forca2 = lutador1.Forca2 - lutador2.Forca2 + *pK;
            if (lutador1.Forca2 > lutador1.Forca1){
                lutador1.Forca2 = lutador1.Forca1;
            }
            if (TFila_Enfileira(pFilaLutadores, lutador1) == 0); 
        }
        else
        {
            lutador2.Forca2 = lutador2.Forca2 - lutador1.Forca2 + *pK;
            if (lutador2.Forca2 > lutador2.Forca1){
                lutador2.Forca2 = lutador2.Forca1;
            }
            if (TFila_Enfileira(pFilaLutadores, lutador2) == 0);
        }
    }
 
    if (TFila_Desenfileira(pFilaLutadores, &x) == 0);
 
    printf("%d", x.Chave);
 
    free(pK);
    free(pFilaLutadores);
 
    return false; 
    }