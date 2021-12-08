//Pedro Henrique Ito
//R.A: 159.515
//Torneio de Luta de Braço - Arranjos
//100% Sharif Judge
 
#include<stdio.h>
#include<math.h>
#include <stdbool.h>
#define MAXTAM 32769
 
typedef int TChave;
 
typedef struct 
{
    TChave Chave; 
    int Forca1, Forca2;
}   TItem;
 
typedef int TApontador;
 
typedef struct 
{
    TItem Item[MAXTAM];
    TApontador Frente, Tras;
}   TFila;
 
void TFila_Inicia (TFila *pFila)
{
    pFila->Frente = 0;
    pFila->Tras = 0;
}

bool TFila_EhVazia (TFila *pFila)
{
    return (pFila->Frente == pFila->Tras);
}
 
int TFila_Enfileira(TFila *pFila, TItem x)
{
    if(pFila -> Tras >= MAXTAM){
        printf("Lista Cheia.");
        return 0;
    }       
 
    pFila->Item[pFila->Tras] = x;
    pFila->Tras = (pFila->Tras + 1) % MAXTAM;
 
    return 1;
}
 
int TFila_Desenfileira (TFila *pFila, TItem *pX) 
{
    if (TFila_EhVazia(pFila)) 
        return 0;
    
    *pX = pFila->Item[pFila->Frente];
    pFila->Frente = (pFila->Frente + 1) % MAXTAM;
 
    return 1;
}
 
int TFila_Tamanho (TFila *pFila)
{
    return (pFila->Tras - pFila->Frente);
}

int main ()
{
    int N, K, a;
    scanf("%d %d", &N, &K);
 
    TFila FilaLutadores;
    TFila_Inicia(&FilaLutadores);
 
    TItem x;
    a = 0;
 
    while (a<pow(2,N))
    {
        x.Chave = a + 1;
        scanf("%d", &x.Forca1);
        x.Forca2 = x.Forca1;
        ++a;
        if (TFila_Enfileira(&FilaLutadores, x) == 0);
    }
 
    TItem lutador1;
    TItem lutador2;
 
    while (TFila_Tamanho(&FilaLutadores) != 1){
        if (TFila_Desenfileira(&FilaLutadores, &lutador1) && TFila_Desenfileira(&FilaLutadores, &lutador2) == 0);
        if (lutador1.Forca2 >= lutador2.Forca2)
        {
            lutador1.Forca2 = lutador1.Forca2 - lutador2.Forca2 + K;
            if (lutador1.Forca2 > lutador1.Forca1)
                lutador1.Forca2 = lutador1.Forca1;
            if (TFila_Enfileira(&FilaLutadores, lutador1) == 0);
        }
        else
        {
            lutador2.Forca2 = lutador2.Forca2 - lutador1.Forca2 + K; 
            if (lutador2.Forca2 > lutador2.Forca1)
                lutador2.Forca2 = lutador2.Forca1;
            if (TFila_Enfileira(&FilaLutadores, lutador2) == 0);
        }
    }
    if (TFila_Desenfileira(&FilaLutadores, &x) == 0);
    printf("%d", x.Chave); 
    return 0; 
}