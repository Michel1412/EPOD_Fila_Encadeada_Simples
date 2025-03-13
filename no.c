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
		
		imprimirNovo(novo);
	} else {
		printf("Erro ao alocar memoria");
	}
}

void imprimir(No *no) {
	printf("\nEndereco Lista: %p", &no);
	printf("\nConteudo Lista: ");
	int i = 0;
	
	while (no) {
		printf("\n %d - %d => %p", i++, no->valor, no);
		no = no->prox;
	}
	
	printf("\n\n");
}

void imprimirNovo(No *novo) {
    printf("\nValor do Novo no: %p, Endereco Proximo: %p", novo, novo->prox);
    printf("\nEndereco de Novo(variavel): %p, Conteudo de Novo: %d", &novo, novo->valor);
    
    printf("\n");
}
