//Pedro Henrique Ito
//RA: 159.515
//Tarefa 02 – TAD Pilha – Calculadora Pós-Fixada
//100% - Sharif Judge

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define MAX_PILHA 100
 
typedef struct{
    float item[MAX_PILHA];
    int top;
}   TPilha;
TPilha * Iniciar(){
    TPilha * p = (TPilha *) malloc(sizeof(TPilha));
    p->top = 0; 
    return p;
}
int TPilha_Tamanho(TPilha * p){
    return (p->top);
}
int TPilha_Cheia (TPilha*p){
  if(p->top == MAX_PILHA -1){
    return 1;
  }else{
    return 0;
  }
}
int TPilha_EhVazia(TPilha * p){
    if(p->top == -1){
        return true;
    }
    else {
        return false;
  }
}
int TPilha_Empilha(TPilha * p, float x){
    if (p->top == MAX_PILHA){
        return false;
    }
    p->item[p->top] = x;
    p->top++;
    return true;
}
int TPilha_Desempilha(TPilha * p, float * px){
    if (TPilha_EhVazia(p) == 1){
        printf("A Pilha está Vazia.");
        return false;
    }
    p->top--;
    *px = p->item[p->top];
    return true;
}
void elementos(TPilha * p){
    int i;
    for (i = p->top-1; i >= 0; i--){
        printf("Item[%i]: %f \n", i, p->item[i]);
    }
}
 
int main(){
    char exp[100];
    int i, j;
    float aux, ultNum, penultNum, num[52][2];
    bool lido = false;
    TPilha * pilha;
    
    scanf("%s", exp);
    
    for (i=0; i<strlen(exp); i++){
        lido = false;
        for (j=0; j<52; j++){
            if(exp[i] == num[j][0]){
                lido = true;
            }
        }
        if (lido == true){
            continue;
        }                
        if ((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z')){
            num[i][0] = exp[i];
            scanf("%f", &num[i][1]);
        }
    }
    
    pilha = Iniciar();
    
    for (i=0; i<strlen(exp); i++){
        switch (exp[i]){
            case '+':
                TPilha_Desempilha(pilha, &ultNum);
                TPilha_Desempilha(pilha, &penultNum);
                aux = ultNum + penultNum;
                TPilha_Empilha(pilha, aux);
                break;
            case '*':
                TPilha_Desempilha(pilha, &ultNum);
                TPilha_Desempilha(pilha, &penultNum);
                aux = ultNum * penultNum;
                TPilha_Empilha(pilha, aux);
                break;
            case '-':
                TPilha_Desempilha(pilha, &ultNum);
                TPilha_Desempilha(pilha, &penultNum); 
                aux = penultNum - ultNum;
                TPilha_Empilha(pilha, aux);
                break;
            case '/':
                TPilha_Desempilha(pilha, &ultNum);
                TPilha_Desempilha(pilha, &penultNum);
                aux = penultNum / ultNum;
                TPilha_Empilha(pilha, aux);
                break;    
            default:
                for (j=0; j<52; j++){
                    if(exp[i] == num[j][0]){
                        aux = num[j][1];
                    }
                }
                TPilha_Empilha(pilha, aux);
                break;
        }
    }
    TPilha_Desempilha(pilha, &ultNum);
    printf("%f\n", ultNum);
    free(pilha);
    return 0;
}