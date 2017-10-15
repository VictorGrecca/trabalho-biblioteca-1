// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao dinamica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include <stdio.h> 
#include <stdlib.h>
#include "Lista_Livro_Dinamico.h"

void ListaLivroCria (ListaLivro * este) {

	este->Primeiro = NULL;
	este->Ultimo = NULL;
}

int ListaLivroEstaVazia (ListaLivro * este) {

	return ( este->Primeiro == NULL );
}

void ListaLivroInsere (ListaLivro * este, Livro * arg ) {

	// Alocacao de um novo no
	nodeLivro * novoNode;
	novoNode = (nodeLivro*)malloc( sizeof(nodeLivro) );
	if (novoNode == NULL) {
		printf("ERRO: o sistema encontrou um problema! (Falha em alocação de memoria).\n");
		abort();
	}

	// Sendo arg o argumento, um ponteiro para um livro que sera inserido na lista
	novoNode->Valor = *arg;
	novoNode->Proximo = NULL;

	// Caso a lista esteja vazia, o novo no sera o primeiro
	if (este->Primeiro == NULL)
		este->Primeiro = novoNode;
	else
		este->Ultimo->Proximo = novoNode;

	// O no inserido sempre sera o ultimo
	este->Ultimo = novoNode;
}

void ListaLivroRemove (ListaLivro * este, Livro * arg ) {

	// Caso a lista esteja vazia
	if ( ListaLivroEstaVazia(este) ) {
		printf("\n  -> Operacao invalida. A biblioteca esta vazia!\n\n");
		return;
	}

	nodeLivro * p;

	// Caso a lista possua apenas um no
	
	if( este->Primeiro == este->Ultimo) {
		LimpaLivro(&este->Primeiro->Valor);
		free(este->Primeiro);
		este->Primeiro = NULL;
		este->Ultimo = NULL;
	}
	else {
		/* Caso o livro a remover seja o primeiro da lista
		 (strcmp() retorna 0 caso as strings sejam iguais) */

		if( strcmp(este->Primeiro->Valor.Titulo, arg->Titulo ) == 0 ) {
		
			nodeLivro * aux = este-> Primeiro;
			este->Primeiro = aux->Proximo;
			LimpaLivro(&aux->Valor);
			free(aux);
		
		}
		else {
			// Demais casos, quando é preciso encontrar o livro no meio da lista

			for ( p = este->Primeiro ; p != NULL ; p = p->Proximo )
				if ( strcmp(p->Proximo->Valor.Titulo, arg->Titulo) == 0 ) {
					break;
				}

			// Caso o livro a remover seja o ultimo da fila
			if( p->Proximo == este->Ultimo ) {
				LimpaLivro(&p->Proximo->Valor);
				free(p->Proximo);
				p->Proximo = NULL;
				este->Ultimo = p;
			}
			else {		// Demais casos
				
				nodeLivro * aux = p->Proximo;
				p->Proximo = p->Proximo->Proximo;
				LimpaLivro(&aux->Valor);
				free(aux);
			}
		}
	}
}

void ListaLivroFinaliza (ListaLivro * este) {
	
	// Limpa todos os nos e seus respectivos livros
	nodeLivro * p;
	for ( p = este->Primeiro ; p != NULL ; p = p->Proximo ) {
		LimpaLivro(&p->Valor);
		free(p);
	}
}
