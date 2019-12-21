#include "listaEncadeada.h"

Lista* cria_lista(){

	Lista *linkedList;

	linkedList = malloc(sizeof(Lista));
	if(linkedList == NULL)
	{
		//printf("Memory allocation error.\n");
		//exit(1);
		return NULL;							//bloco de codigo alterado pos-apresentacao para retornar NULL como definido no arquivo header
	}

	linkedList->qtd = 0;						//seta para 0 a quantidade de elementos na alocacao da cabeca da lista
	linkedList->first = NULL;					//ponteiro tipo Nodo da cabeca recebe NULL na criacao da Lista

	return linkedList;

}


int lista_cheia(Lista *L){

	if(L == NULL)
		return -1;
	else
		if(L->qtd == MAX)
			return 1;
		else
			return 0;

}

int lista_vazia(Lista *L){


	if(L == NULL)
		return -1;
	else
		if(L->qtd == 0)
			return 1;
		else
			return 0;

}

void imprimeLista(Lista *L){

	Nodo *aux;
	for(aux=L->first;aux!=NULL;aux = aux->prox)
	{
		printf("%d ",aux->val);
	}

}



int insere(Lista *L, int pos, int valor){
	if(lista_cheia(L) || pos < 0 || pos > L->qtd){
		return 0;
	}

	struct nodo *novoNodo;
	novoNodo = malloc(sizeof(Lista));
	if(novoNodo == NULL)
	{
		//printf("Memory allocation error.\n");
		//exit(1);
		return 0;						//bloco de codigo alterado pos-apresentacao para retornar 0 como definido no arquivo header
	}

	novoNodo->val = valor; 				//Se chegar aqui criou um nodo e atribuiu valor
	L->qtd++;							//aumenta a quantidade de elementos da lista registrados

	if(L->first == NULL)				//testa se a lista esta vazia
	{
		novoNodo->prox = NULL;			//insere na primeira pos
		L->first = novoNodo;
		return 1;
	}

	struct nodo *aux;
	if(pos == 0) 						//Se nao esta vazia e quero inserir na primeira pos
	{
			aux = L->first;
			L->first = novoNodo;
			novoNodo->prox = aux;
			return 1;
	}else
	{
		int i=1;						//se quero inserir em qualquer outra pos
		for(aux=L->first;i<pos;i++)
		{
			aux=aux->prox;
		}

		novoNodo->prox = aux->prox;
		aux->prox = novoNodo;
		return 1;
	}

}


int deleta(Lista *L, int pos){

	
	if(lista_vazia(L) == 0)
	{

		Nodo *anterior,*atual;
		int i=0;

		if(L->first != NULL){					

			anterior = L->first;				//criam-se dois ponteiros Nodo 
			atual = anterior->prox;

			if(pos == 0 && anterior != NULL)  
			{
				if(atual != NULL)				//se atual for diferente de NULL, além de dimunuir-se o L->qtd,desaloca o bloco de memória
				{								//atual e aponta para o prox dele,senão,apenas diminui o L->qtd
					anterior->prox = atual->prox;
					free(atual);
				}
				L->qtd--;						
				return 1;
			}

			while(atual != NULL && i!=pos)		//enquanto nao for encontrada a posicao do elemento a ser deletado,
			{									//aponta para o proximo elemento da lista

				anterior=atual;
				atual = anterior->prox;
				i++;
			}

			if(i == pos && anterior!= NULL)		//se atual for diferente de NULL, além de dimunuir-se o L->qtd,desaloca o bloco de memória
			{									//atual e aponta para o prox dele,senão,apenas diminui o L->qtd
				if(atual != NULL)
				{
					anterior->prox = atual->prox;
					free(atual);
				}
				L->qtd--;
				return 1;
			}
	 	}
	}
	return 0;

}


void destroi_Lista(Lista *L){

	Nodo *aux1,*aux2;
	for(aux1 = L->first;aux1!=NULL;aux1=aux2)		//desaloca os blocos/elementos da lista um por vez, sempre guardando o endereco
	{												//do proximo elemento
		aux2 = aux1->prox;
		free(aux1);
	}
	free(L);										//comando adicionado pos-apresentacao para liberar L da memoria tambem

}

int get(Lista *L, int pos){

	if((pos <= L->qtd && pos!=MAX) || (pos>=0 && pos!=MAX)){  				//se a posicao for invalida(nao obedecer a esses parametros),retorna 0
		Nodo *aux; int i;

		for(aux = L->first,i=0;aux!=NULL;aux=aux->prox,i++) 	//enquanto nao encontrar a posicao, aponta para o proximo elemento da lista,
		{														//relacionando o ponteiro
			if(i == pos)
			return aux->val;
		}
	}
	return 0;											

}


int set(Lista *L, int pos, int valor){				 

	if((pos <= L->qtd && pos!=MAX) || (pos>=0 && pos!=MAX)) 				//se a posicao for invalida(nao obedecer a esses parametros),retorna 0

	{

		int i=0;
		struct nodo *aux;

		for(aux = L->first; aux!=NULL; aux=aux->prox,i++)	//enquanto nao encontrar a posicao, aponta para o proximo elemento da lista,													
		{													//relacionando o ponteiro
			if(pos == i)
			{
				aux->val = valor;
				return 1;
			}
		}
	}
	return 0;

}


int locate(Lista *L, int numero){

	struct nodo *aux;
	int contaPos=0;

	for(aux = L->first; aux != NULL; aux=aux->prox)			//itera sobre a lista enquanto ela nao acabar ou enquanto ela
	{														//nao encontrar o valor passado na funcao			
		if(aux->val == numero)								
		{
			return contaPos;
		}
		contaPos++;											//conta os blocos de memoria a cada iteracao, para fazer relacao dos
	}														//blocos alocados com uma posicao
	return -1;
}


int length(Lista *L){
	return L->qtd;
}

