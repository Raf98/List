#include "simpletest.h"

//COMENTAR O INCLUDE QUE NAO FOR USAR
#include "listaEncadeada.h"
//#include "listaSequencial.h"

void test_create(){
	DESCRIBE("CRIA LISTA");
	IF("Eu crio uma lista");
	THEN("Resultado deve ser ponteiro");
	Lista *l = cria_lista();
	isNotNull(l);
	
	IF("Eu Testo o tamanho");
	THEN("Comprimento deve ser 0");
	isEqual(length(l),0);
	
	destroi_Lista(l);
}

void test_inserts(){
	int i;

	Lista *l = cria_lista();

	DESCRIBE("INSERE ELEMENTOS");
	WHEN("Eu insiro elementos em ordem");
	IF("Insiro tantos quanto o máximo");
	THEN("Deve inserir todos");
	for(i=0; i<MAX; i++){
		isEqual_Spaced(insere(l, i, i), 1);
		//printf("Eu insiro o elemento %d\n",i);
	}

	//imprimeLista(l);


	THEN("Comprimento deve ser MAX");
	isEqual(length(l),MAX);

	THEN("Deve estar cheia");
	isEqual(lista_cheia(l),1);

	IF("Insiro mais que a capacidade");
	THEN("Resultado deve ser erro");
	isEqual(insere(l,MAX+1, MAX+1), 0);

	/*for(i=0; i<MAX; i++){
		printf("%d " , get(l,i));
	}*/	

	destroi_Lista(l);


	l = cria_lista();

	WHEN("Eu insiro os elementos de 0-99 na posicao 0");
	IF("Insiro tantos quanto o máximo");
	THEN("Deve inserir todos");
	for(i=0; i<MAX; i++){
		isEqual_Spaced(insere(l, 0, i), 1);
		//printf("Eu insiro o elemento %d\n",i);
	}

	//imprimeLista(l);

	printf("\n");
	THEN("Primeiro elemento deve ser 99");
	isEqual(get(l,0),99);
	
	THEN("Ultimo elemento deve ser 0");
	isEqual(get(l,99),0);

	destroi_Lista(l);
}

void test_delete(){

	int i;

	Lista * l = cria_lista();
	for(i=0; i<MAX; i++){
		insere(l, i, i);
		//printf("Eu insiro o elemento %d\n",i);
	}

	//imprimeLista(l);

	DESCRIBE("REMOVE ELEMENTOS");
	WHEN("Eu removo os elementos de uma lista");
	IF("Removo sempre o primeiro elemento");
	THEN("Deve remover");
	for(i=0; i < MAX; i++){
		isEqual_Spaced(deleta(l, 0),1);
		//printf("Eu removo o elemento %d\n",i);
	}
	printf("\n");
	THEN("Comprimento deve ser 0");
	isEqual(length(l),0);
	destroi_Lista(l);


	l = cria_lista();
	for(i=0; i<MAX; i++){
		insere(l, i, i);
		//printf("Eu insiro o elemento %d\n",i);
	}

	//imprimeLista(l);

	
	WHEN("Eu removo os elementos de uma lista");
	IF("Removo sempre o ultimo elemento");
	THEN("Deve remover");
	for(i=0; i < MAX; i++){
		isEqual_Spaced(deleta(l, (MAX-1)-i),1);
		//printf("Eu removo o elemento %d\n",(MAX-1)-i);
	}
	printf("\n");
	THEN("Comprimento deve ser 0");
	isEqual(length(l),0);
	destroi_Lista(l);
}

void test_get_set(){
	int i;

	Lista * l = cria_lista();
	for(i=0; i < MAX; i++){
		insere(l, i, i);
	}

	DESCRIBE("CONSULTANDO E MUDANDO ELEMENTOS");

	WHEN("Eu consulto um elemento inserido");
	THEN("Ele deve estar presente");
	isEqual(get(l,1), 1);

	WHEN("Eu consulto uma posição inexistente");
	THEN("Ele deve retornar Zero");
	isEqual(get(l,MAX),0);

	WHEN("Eu mudo o valor de um elemento existente");
	THEN("Ele deve mudar");
	isEqual(set(l,1,99), 1);
	isEqual(get(l,1), 99);

	WHEN("Eu mudo o valor de um elemento inexistente");
	THEN("Ele deve retornar erro");
	isEqual(set(l,MAX,1),0);

	destroi_Lista(l);
}

void test_locate(){
	int i;

	Lista * l = cria_lista();

	for(i=0; i<MAX; i++){
		insere(l, i, i);
	}
	DESCRIBE("LOCALIZANDO ELEMENTOS");
	WHEN("Procuro elemento inexistente");
	THEN("Não deve achar");
	isEqual(locate(l,-1),-1);
	isEqual(locate(l,MAX+MAX),-1);

	WHEN("Procuro elemento existente");
	THEN("Deve retornar a posição correta na lista");
	isEqual(locate(l,0),0);

	isEqual(locate(l,MAX/2),MAX/2);
	isEqual(locate(l,MAX-1),MAX-1);

	destroi_Lista(l);

}



int main () {
	test_create();
	test_inserts();
	test_delete();
	test_get_set();
	test_locate();
}
