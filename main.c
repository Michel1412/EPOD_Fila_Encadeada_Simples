#include <stdio.h>
#include <stdlib.h>
#include "no.h"

int perguntarValor() {
	int valor;
	
	printf("\nValor: ");
	scanf(" %d", &valor);
	
	return valor;
}

int main(void) {
	int opcao, valor, anterior;
	No *lista = NULL;
	
	do {
		printf("\n0 - Sair\n1 - Inserir no inicio\n2 - Inserir no fim\n3 - Inserir no meio\n4 - Inserir no ordanado\n5 - Imprimir\n");
		scanf(" %d", &opcao);
		
		switch (opcao) {
			case 1:
				imprimir(lista);
				inserir_inicio(&lista, perguntarValor());
				break;
				
			case 2:
				imprimir(lista);
				inserir_fim(&lista, perguntarValor());
				break;
				
			case 3:
				imprimir(lista);
				printf("\nValor de referecia: ");
				scanf(" %d", &anterior);
				
				inserir_meio(&lista, perguntarValor(), anterior);
				break;
				
			case 4:
				imprimir(lista);
				inserir_ordenado(&lista, perguntarValor());
				break;
			
			case 5:
				imprimir(lista);
				break;
					
			default:
				if (opcao != 0)
					printf("\nOpcao Invalida.\n");		
		}
		
	} while (opcao != 0);
	
	return 0;
}
