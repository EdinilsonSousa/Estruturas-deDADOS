/*
Construa um programa que receba N números do usuário e insira esses números de forma ordenada em uma lista ligada
Não é permitido a utilização de vetores;
O programa deverá ler números do usuário até que seja digitado o número -1
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct lista
{
    int qtd;
    struct registro *inicio;
}lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
}registro;

lista * aloca_lista(void);
registro * aloca_registro(void);
void incluir_inicio(lista *l, int x);
void mostrar_lista(lista *l);
void menu(void);

int main() {

    int num = 0, opcao = -1;
    
    lista *lista1;
    lista1 = aloca_lista();

    while(opcao != 3){ 
    menu();
    scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            puts("Qual numero voce quer adicionar na lista ?\n");
                scanf("%d", &num);
            incluir_inicio(lista1,num);
        break;

        case 2:
            mostrar_lista(lista1);
            
        break;
        
        case 3: 
        puts("\nSaindo do Programa, até algum dia guerreiro\n");
        break;

        default:
        puts("Selecione uma opção valida");
            break;
        }
    }
    return 0;
}

void menu ()
{
    puts(" Menu de opções\n");
    puts(" [1] - Adicionar numero na lista  ");
    puts(" [2] - Mostrar lista");
    puts(" [3] - Para sair\n ");
}

lista *aloca_lista()
{
    lista * nova_lista;
    
    nova_lista = (lista*)malloc(sizeof(lista));
    nova_lista->qtd = 0;
    nova_lista->inicio = NULL;
    
    return nova_lista;
}


registro *aloca_registro(void)
{
    registro * novo;
    
    novo = (registro*)malloc(sizeof(registro));
    novo->valor = 0;
    novo->prox = NULL;
    
    return novo;
}

void incluir_inicio(lista *l, int x)
{
    registro *novo, *aux, *ant;
    novo = aloca_registro();
    novo->valor = x;

    if (l->qtd == 0) l->inicio = novo;
    else if(l->inicio->valor > novo->valor)
    {
      aux = l->inicio;
      novo->prox = aux;
      l->inicio = novo;
    }
    else
    {
      aux = l->inicio;
      
      while (novo->valor > aux->valor)
      {
        if(aux->prox == NULL)
        {
          aux->prox = novo;
          l->qtd++;
          return;
        }
        
        ant = aux;
        aux = aux->prox;
      }
      
      novo->prox = aux;
      ant->prox = novo;
    }
    l->qtd++;
}

void mostrar_lista(lista *l)
{
    registro *aux;
    
    if(l->qtd == 0) puts("\nLista vazia, preencha ela antes\n");
        else
        {
            aux = l->inicio;
            puts("\n");
            while(aux != NULL)
            {
                printf(" |%d| ", aux->valor);
                aux = aux->prox;
            }
        puts("\n");
    }
}
