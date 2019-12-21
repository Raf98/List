#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/* Estrutura de um Nodo 
 * qualquer da lista*/
typedef struct nodo{
   int val;
   struct nodo *prox;
}Nodo;


/* Estrutura da cabeça da lista */
typedef struct Lista{
   int qtd;
   struct nodo *first;
}Lista;

/** Cria a cabeca de uma lista encadeada
 * @L->qtd deve ser ajustado para 0 (lista vazia)
 * @L->first deve apontar para NULL
 * @return endereço da cabeca alocada ou NULL*/
Lista* cria_lista();


/* Testa se a lista está cheia
   @param L descritor da lista
   @return -1 se ponteiro Nulo, 1 Se lista cheia, 0 Caso contrário*/
int lista_cheia(Lista *L);


/* Testa se a lista está vazia
   @param L descritor da lista
   @return -1 se ponteiro Nulo, 1 Se lista vazia, 0 Caso contrário*/
int lista_vazia(Lista *L);



/** Destrói a lista, liberando a memória.
	!!!!ATENCAO!!!!
		Destruir uma lista encadeada nao implica somente
		em liberar a memoria da cabeca. Eh preciso liberar
		TODOS OS ELEMENTOS DA LISTA
			Sugestao: Loop de "0 ate o tamanho da Lista" (nao faca a comparacao com 
			L->qtd, pois esse muda a cada execucao do deleta) com a funcao "deleta" 
			apagando o primeiro elemento e depois  finalmente liberar a cabeca
 * @param desc descritor da lista*/
void destroi_Lista(Lista *L);


/** Insere um elemento na lista em uma posição
Antes de inserir: 
	Testar se a posicao a ser inserida nao eh maior que qtd
 * @param L descritor da lista
 * @param pos posição para inserção
 * @param valor o que será inserido
 * @return 1 se OK, 0 se erro*/
int insere(Lista *L, int pos, int valor);


/** Remove um elemento de uma posição
	Antes de apagar:
		Testar se a lista nao esta vazia(utilize função criada)
 * @param L descritor da lista
 * @param pos posição para remoção
 * @return 1 se OK, 0 se erro*/
int deleta(Lista *L, int pos);


/** Encontra um elemento com um determinado valor
* @param L descritor da lista
* @param numero valor a ser buscado
* @return posicao caso encontre, -1 se não encontrar*/
int locate(Lista *L, int numero);


/** Retorna o valor do elemento. 
 * @param L descritor da lista
 * @param pos posição para elemento
 * @return valor caso encontre e 0 caso não exista*/
 int get(Lista *L, int pos);


/** Muda o valor do elemento.
 * @param L descritor da lista
 * @param pos posição para elemento
 * @param a novo valor para item
 * @return 1 se OK, 0 se erro*/
int set(Lista *L, int pos, int valor);


/** Retorna o comprimento da lista
* @param L descritor da lista
* @return comprimento da lista atual*/
int length(Lista *L);

void imprimeLista(Lista *L);
