#include <stdio.h>
#include <stdlib.h>
#include "no.h"

void inserir_inicio(No **lista, int num) {
	No *novo = malloc(sizeof(No));
	
	if (novo) {
		novo->valor = num;
		novo->prox = *lista;
		*lista = novo;
		
		imprimirNovo(novo);
	} else {
		printf("Erro ao alocar memoria");
	}
}

void inserir_fim(No **lista, int num) {
	No *aux, *novo = malloc(sizeof(No));
	
	if (novo) {
		novo->valor = num;
		novo->prox = NULL;
		
		if (*lista == NULL) {
			*lista = novo;
		} else {
			aux = *lista;
			while (aux->prox)
				aux = aux->prox;
			aux->prox = novo;
		}
		
		imprimirNovo(novo);
	} else {
		printf("Erro ao alocar memoria");
	}
}

void inserir_meio(No **lista, int num, int ant) {
	No *aux, *novo = malloc(sizeof(No));
	
	if (novo) {
		novo->valor = num;
		
		if (*lista == NULL) {
			novo->prox = NULL;
			*lista = novo;
			
		} else {
			aux = *lista;
			while (aux->valor != ant && aux->prox)
				aux = aux->prox;
			novo->prox = aux->prox;
			aux->prox = novo;
		}
		
		imprimirNovo(novo);
	} else {
		printf("Erro ao alocar memoria");
	}
}

void inserir_ordenado(No **lista, int num) {
	No *aux, *novo = malloc(sizeof(No));
	
	if (novo) {
		novo->valor = num;
		
		if (*lista == NULL) {
			novo->prox = NULL;
			*lista = novo;
			
		} else if (novo->valor < (*lista)->valor){
			novo->prox = *lista;
			*lista = novo;
		
		} else {
			aux = *lista;
			while (aux->prox && novo->valor > aux->prox->valor)
				aux = aux->prox;
			novo->prox = aux->prox;
			aux->prox = novo;
			
		}
		
    	printf("\n Endereco da Lista: %p\n Conteudo Lista: %p", &lista, *lista);
    	printf("\n Endereco do Novo: %p\n Conteudo Novo: %p", &novo, novo);
	} else {
		printf("Erro ao alocar memoria");
	}
}

void imprimir(No *no) {
	printf("\n------------------------------------------------------------");
	printf("\nEndereco Lista: %p", &no);
	printf("\nConteudo Lista: %p", no);
	printf("\n------------------------------------------------------------");
	int i = 0;
	
	while (no) {
		printf("\n %d - %d => Endereco: %p\n            Proximo: %p", i++, no->valor, no, no->prox);
		no = no->prox;
	}
	
	printf("\n\n");
}

void imprimirNovo(No *novo) {
	printf("\n------------------------------------------------------------");
    printf("\n Valor do Novo no: %p\n Endereco Novo->Proximo: %p", novo, novo->prox);
	printf("\n------------------------------------------------------------");
    printf("\n Endereco de Novo(variavel): %p\n Conteudo de Novo: %d", &novo, novo->valor);
	printf("\n------------------------------------------------------------");
    
    printf("\n");
}

No* remover(No **lista, int num) {
	No *remover, *aux = NULL;
	
	if (*lista) {
		if ((*lista)->valor == num) {
			remover = *lista;
			*lista = remover->prox;
		
		} else {
			aux = *lista;
		
			while(aux->prox && aux->prox->valor != num) 
				aux = aux->prox;
			
			if (aux->prox) {
				remover = aux->prox;
				aux->prox = remover->prox;
			}	
		}
	}
	
	return remover;
}

No* buscar(No **lista, int num) {
	No *aux = *lista;
	
	while(aux && aux->valor != num)
		aux = aux->prox;
	
	if (aux) 
		return aux;
	else
		return NULL;
}

