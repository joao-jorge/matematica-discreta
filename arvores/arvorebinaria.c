#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1

typedef int bool;
typedef int TIPOCHAVE;

typedef struct aux 
{
  TIPOCHAVE chave;
  struct aux *esq;
  struct aux *dir;
}NO;

typedef NO *PONT;


/* Inicializar a arvore */
PONT inicializa()
{
  return (NULL);
}

/* Criar um novo NO */
PONT criarNovoNo(TIPOCHAVE ch)
{
  PONT novoNo = (PONT)malloc(sizeof(NO));
  novoNo->esq = NULL;
  novoNo->dir = NULL;
  novoNo->chave = ch;
  return(novoNo);
}

/* Adicionar novo NO na arvore */
PONT adiciona(PONT raiz, PONT no)
{
  if(raiz == NULL) return (no);
  if(no->chave < raiz->chave)
    raiz->esq = adiciona(raiz->esq, no);
  else
    raiz->dir = adiciona(raiz->dir, no);
  return(raiz);
}

/* Verificar se um elemento esta na arvore */
PONT contem(TIPOCHAVE ch, PONT raiz)
{
  if(raiz == NULL) return (NULL);
  if(raiz->chave == ch) return (raiz);
  if(raiz->chave > ch)
    return contem(ch, raiz->esq);
  return contem(ch, raiz->dir);
}

/* Contar elementos da arvore */
int numeroNos(PONT raiz)
{
  if(!raiz) return 0;
  return numeroNos(raiz->dir) + 1 + numeroNos(raiz->esq);
}

/* Exibir a arvore binaria */
void exibirArvore(PONT raiz)
{
  if(raiz != NULL)
  {
    printf("%i", raiz->chave);
    printf("(");
    exibirArvore(raiz->esq);
    exibirArvore(raiz->dir);
    printf(")");
  }
}

int main()
{
  PONT r = inicializa();
  int num;

  PONT no = criarNovoNo(23);
  r = adiciona(r, no);

  no = criarNovoNo(27);
  r = adiciona(r, no);

  no = criarNovoNo(20);
  r = adiciona(r, no);

  no = criarNovoNo(10);
  r = adiciona(r, no);

  no = criarNovoNo(21);
  r = adiciona(r, no);

  no = criarNovoNo(25);
  r = adiciona(r, no);

  no = criarNovoNo(29);
  r = adiciona(r, no);

  PONT pr = contem(25, r);
  if(pr != NULL)
    printf("O numero %i foi achado na posicao de memoria: %p\n", pr->chave, pr);

  num = numeroNos(r);
  printf("A arvore tem %i elementos\n", num);
  
  exibirArvore(r);
  printf("\n");

  return 0;
}
