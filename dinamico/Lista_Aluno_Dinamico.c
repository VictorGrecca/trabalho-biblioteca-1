// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao dinamica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include <stdio.h> 
#include <stdlib.h>
#include "Lista_Aluno_Dinamico.h"

void ListaAlunoCria (ListaAluno * this) {

	this->Primeiro = NULL;
	this->Ultimo = NULL;
}

int ListaAlunoEstaVazia (ListaAluno * this) {

	return ( this->Primeiro == NULL );
}

void ListaAlunoInsere (ListaAluno * this, Aluno * arg ) {

	// Alocacao de um novo no
	nodeAluno * novoNode;
	novoNode = malloc( sizeof(nodeAluno) );
	if (novoNode == NULL) {
		printf("ERRO: o sistema encontrou um problema! (Falha em alocação de memoria).\n");
		abort();
	}
	
	// Sendo arg o argumento, um ponteiro para um aluno que sera inserido na lista
	novoNode->Valor = *arg;
	novoNode->Proximo = NULL;

	// Caso a lista esteja vazia
	if (this->Primeiro == NULL)
		this->Primeiro = novoNode;
	else
		this->Ultimo->Proximo = novoNode;

	// O novo no sempre sera o ultimo da lista
	this->Ultimo = novoNode;
}

void ListaAlunoRemove (ListaAluno * this, Aluno * arg ) {

	// Caso a lista esteja vazia
	if ( ListaAlunoEstaVazia(this) ) {
		printf("\n  -> Operacao invalida. Nenhum aluno esta cadastrado!\n\n");
		return;
	}

	nodeAluno * p;

	// Caso a lista possua apenas um no

	if( this->Primeiro == this->Ultimo) {
		LimpaAluno(&this->Primeiro->Valor);
		free(this->Primeiro);
		this->Primeiro = NULL;
		this->Ultimo = NULL;
	}
	else {
		/* Caso o aluno a remover seja o primeiro da lista
		 (strcmp() retorna 0 caso as strings sejam iguais) */
		
		if( strcmp(this->Primeiro->Valor.Nusp, arg->Nusp ) == 0 ) {
		
			nodeAluno * aux = this-> Primeiro;
			this->Primeiro = aux->Proximo;
			LimpaAluno(&aux->Valor);
			free(aux);
		
		}
		else {
			// Demais casos, quando é preciso encontrar o aluno no meio da lista
			
			for ( p = this->Primeiro ; p != NULL ; p = p->Proximo )
				if ( strcmp(p->Proximo->Valor.Nusp, arg->Nusp) == 0 ) {
					break;
				}

			// Caso o aluno a remover seja o ultimo da fila
			if( p->Proximo == this->Ultimo ) {
				LimpaAluno(&p->Proximo->Valor);
				free(p->Proximo);
				p->Proximo = NULL;
				this->Ultimo = p;
			}
			else {		// Demais casos
				
				nodeAluno * aux = p->Proximo;
				p->Proximo = p->Proximo->Proximo;
				LimpaAluno(&aux->Valor);
				free(aux);
			}
		}
	}
}

void ListaAlunoFinaliza (ListaAluno * this) {
	
	// Limpa todos os nos e seus respectivos aluno
	nodeAluno * p;
	for ( p = this->Primeiro ; p != NULL ; p = p->Proximo ) {

		LimpaAluno(&p->Valor);
		free(p);
	}
}