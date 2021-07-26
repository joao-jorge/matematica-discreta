#include <stdio.h>
#include <stdlib.h>
#define MAX 6

typedef struct 
{
  int valor;
}ELEMENTO;

typedef struct 
{
  ELEMENTO key[MAX];
  int nElem;
}TABELA;

void init(TABELA *tab) 
{
  tab->nElem = 0;
}
void inserir(TABELA *tab, int item)
{
  if(tab->nElem == MAX)
    printf("Impossivel adicionar, vector cheio!");
  tab->key[tab->nElem].valor = item;
  tab->nElem++;
}
void listar(TABELA *tab)
{
  int i = 0;
  while(i < tab->nElem)
  {
    printf("%i ", tab->key[i].valor);
    i++;
  }
  printf("\n");
}
/*
  FUNCAO PARA TROCAR(FAZER O SWAP) OS ELEMENTOS
*/
void troca(int *x, int *y)
{
  int aux = *y;
  *y = *x;
  *x = aux;
}

/*
  FUNCAO PARA ORDERNAR O ARRAY 
  DE UMA FORMA SEQUENCIAL
*/
void ordenacaoSequencial(TABELA *tab)
{
  for(int i = 0; i < tab->nElem-1; i++)
  {
    for(int j = i+1; j < tab->nElem; j++)
    {
      if(tab->key[i].valor > tab->key[j].valor)
        troca(&tab->key[i].valor, &tab->key[j].valor);
    }
  }
}


int main()
{
  TABELA *tab = (TABELA*)malloc(sizeof(TABELA));
  init(tab);
  inserir(tab, 15);
  inserir(tab, 2);
  inserir(tab, 35);
  inserir(tab, 5);
  inserir(tab, 3);
  inserir(tab, 4);
  ordenacaoSequencial(tab);
  listar(tab);


  return 0;
}