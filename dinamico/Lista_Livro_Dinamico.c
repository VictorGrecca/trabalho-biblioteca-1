// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao dinamica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include <stdio.h> 
#include <stdlib.h>
#include "Lista_Livro_Dinamico.h"

void ListaLivroCria (ListaLivro * this) {

	this->Primeiro = NULL;
	this->Ultimo = NULL;
}

int ListaLivroEstaVazia (ListaLivro * this) {

	return ( this->Primeiro == NULL );
}

void ListaLivroInsere (ListaLivro * this, Livro * arg ) {

	// Alocacao de um novo no
	nodeLivro * novoNode;
	novoNode = malloc( sizeof(nodeLivro) );
	if (novoNode == NULL) {
		printf("->  ERRO: o sistema encontrou um problema! (Falha em alocação de memoria).\n");
		abort();
	}

	// Sendo arg o argumento, um ponteiro para um livro que sera inserido na lista
	novoNode->Valor = *arg;
	novoNode->Proximo = NULL;

	// Caso a lista esteja vazia, o novo no sera o primeiro
	if (this->Primeiro == NULL)
		this->Primeiro = novoNode;
	else
		this->Ultimo->Proximo = novoNode;

	// O no inserido sempre sera o ultimo
	this->Ultimo = novoNode;
}

void ListaLivroRemove (ListaLivro * this, Livro * arg ) {

	// Caso a lista esteja vazia
	if ( ListaLivroEstaVazia(this) ) {
		printf("\nOperacao invalida. A biblioteca esta vazia!\n\n");
		return;
	}

	nodeLivro * p;

	// Caso a lista possua apenas um no
	
	if( this->Primeiro == this->Ultimo) {
		LimpaLivro(&this->Primeiro->Valor);
		free(this->Primeiro);
		this->Primeiro = NULL;
		this->Ultimo = NULL;
	}
	else {
		/* Caso o livro a remover seja o primeiro da lista
		 (strcmp() retorna 0 caso as strings sejam iguais) */

		if( strcmp(this->Primeiro->Valor.Titulo, arg->Titulo ) == 0 ) {
		
			nodeLivro * aux = this-> Primeiro;
			this->Primeiro = aux->Proximo;
			LimpaLivro(&aux->Valor);
			free(aux);
		
		}
		else {
			// Demais casos, quando é preciso encontrar o livro no meio da lista

			for ( p = this->Primeiro ; p != NULL ; p = p->Proximo )
				if ( strcmp(p->Proximo->Valor.Titulo, arg->Titulo) == 0 ) {
					break;
				}

			// Caso o livro a remover seja o ultimo da fila
			if( p->Proximo == this->Ultimo ) {
				LimpaLivro(&p->Proximo->Valor);
				free(p->Proximo);
				p->Proximo = NULL;
				this->Ultimo = p;
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

void ListaLivroFinaliza (ListaLivro * this) {
	
	// Limpa todos os nos e seus respectivos livros
	nodeLivro * p;
	for ( p = this->Primeiro ; p != NULL ; p = p->Proximo ) {
		LimpaLivro(&p->Valor);
		free(p);
	}
}