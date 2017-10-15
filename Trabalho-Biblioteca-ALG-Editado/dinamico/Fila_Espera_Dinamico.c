// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao dinamica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include <stdio.h>
#include <stdlib.h>
#include "Fila_Espera_Dinamico.h"

void FilaEsperaCria (FilaEspera * este) {

	este->Primeiro = NULL;
	este->Ultimo = NULL;
}

int FilaEsperaEstaVazia (FilaEspera * este) {

	return ( este->Primeiro == NULL );
}

void FilaEsperaInsere (FilaEspera * este, Aluno * arg ) {

	// Alocacao de um novo no
	nodeFila * novoNode;
	novoNode = (nodeFila*)malloc( sizeof(nodeFila) );
	if (novoNode == NULL) {
		printf("ERRO: o sistema encontrou um problema! (Falha em alocação de memoria).\n");
		abort();
	}

	// Arg é o argumento da funcao, um ponteiro para um aluno
	novoNode->Valor = arg;
	novoNode->Proximo = NULL;

	// Caso a fila esteja vazia
	if (este->Primeiro == NULL)
		este->Primeiro = novoNode;
	else
		este->Ultimo->Proximo = novoNode;

	// O novo no sempre sera o ultimo
	este->Ultimo = novoNode;
}

/* 'Anda' a fila e retorna um ponteiro para o aluno que era o primeiro da fila.
Caso a fila esteja vazia, retorna NULL */	
Aluno* FilaEsperaAnda (FilaEspera * este ) {

	// Caso a fila esteja vazia
	if ( este->Primeiro == NULL )
		return NULL;
	else { // Caso nao esteja

		nodeFila * aux = este->Primeiro;
		este->Primeiro = este->Primeiro->Proximo;
		Aluno* retorno = aux->Valor;
		free(aux);
		return retorno;
	}
}

void FilaEsperaFinaliza (FilaEspera * este) {
	
	// Percorre a lista da fila de espera, limpando-a 
	nodeFila * p;
	for ( p = este->Primeiro ; p != NULL ; p = p->Proximo )
		free(p);
}

int FilaEsperaTamanho (FilaEspera * este) {

	int tam = 0;
	nodeFila * p;
	for ( p = este->Primeiro ; p != NULL ; p = p->Proximo )
		tam++;

	return tam;
}
