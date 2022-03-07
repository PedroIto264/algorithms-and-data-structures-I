//Pedro Henrique Ito
//R.A: 159.515
//Soma Tudo - 100% Sharif Judge
 
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MAX 1000
 
int Custo (int *numeros, int TAM)
{
    int soma;
    int custo;
    int i;
    int resultado;
 
    soma = numeros[0] + numeros[1];
    custo = soma;
 
    i = 2;
 
    while (i<TAM)
    {
        soma += numeros[i];
        resultado = soma + custo;
        custo += soma;
        ++i;
    }
 
    return resultado;
}
 
 
void BuubleSort(int *numeros, int TAM)
{
    int i;
    int j;
    int aux;
 
    for (i=0; i<TAM; ++i)
    {
        for (j=0; j<TAM-1-i; ++j)
        {
            if (numeros[j] > numeros[j+1])
            {
                aux = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = aux;
            }
        }
    }
}
 
int main()
{
    int i;
    int numeros[MAX];
    int N;
 
    scanf("%d", &N);
 
    i = 0;
 
    while (i<N)
    {
        scanf("%d", &numeros[i]);
        ++i;
    }
 
    BuubleSort(numeros, N);
 
    printf("%d", Custo(numeros, N));
 
return false; }