// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao dinamica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include <stdio.h> 
#include <stdlib.h>
#include "Lista_Aluno_Dinamico.h"

void ListaAlunoCria (ListaAluno * este) {

	este->Primeiro = NULL;
	este->Ultimo = NULL;
}

int ListaAlunoEstaVazia (ListaAluno * este) {

	return ( este->Primeiro == NULL );
}

void ListaAlunoInsere (ListaAluno * este, Aluno * arg ) {

	// Alocacao de um novo no
	nodeAluno * novoNode;
	novoNode = (nodeAluno*)malloc( sizeof(nodeAluno) );
	if (novoNode == NULL) {
		printf("ERRO: o sistema encontrou um problema! (Falha em alocação de memoria).\n");
		abort();
	}
	
	// Sendo arg o argumento, um ponteiro para um aluno que sera inserido na lista
	novoNode->Valor = *arg;
	novoNode->Proximo = NULL;

	// Caso a lista esteja vazia
	if (este->Primeiro == NULL)
		este->Primeiro = novoNode;
	else
		este->Ultimo->Proximo = novoNode;

	// O novo no sempre sera o ultimo da lista
	este->Ultimo = novoNode;
}

void ListaAlunoRemove (ListaAluno * este, Aluno * arg ) {

	// Caso a lista esteja vazia
	if ( ListaAlunoEstaVazia(este) ) {
		printf("\n  -> Operacao invalida. Nenhum aluno esta cadastrado!\n\n");
		return;
	}

	nodeAluno * p;

	// Caso a lista possua apenas um no

	if( este->Primeiro == este->Ultimo) {
		LimpaAluno(&este->Primeiro->Valor);
		free(este->Primeiro);
		este->Primeiro = NULL;
		este->Ultimo = NULL;
	}
	else {
		/* Caso o aluno a remover seja o primeiro da lista
		 (strcmp() retorna 0 caso as strings sejam iguais) */
		
		if( strcmp(este->Primeiro->Valor.Nusp, arg->Nusp ) == 0 ) {
		
			nodeAluno * aux = este-> Primeiro;
			este->Primeiro = aux->Proximo;
			LimpaAluno(&aux->Valor);
			free(aux);
		
		}
		else {
			// Demais casos, quando é preciso encontrar o aluno no meio da lista
			
			for ( p = este->Primeiro ; p != NULL ; p = p->Proximo )
				if ( strcmp(p->Proximo->Valor.Nusp, arg->Nusp) == 0 ) {
					break;
				}

			// Caso o aluno a remover seja o ultimo da fila
			if( p->Proximo == este->Ultimo ) {
				LimpaAluno(&p->Proximo->Valor);
				free(p->Proximo);
				p->Proximo = NULL;
				este->Ultimo = p;
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

void ListaAlunoFinaliza (ListaAluno * este) {
	
	// Limpa todos os nos e seus respectivos aluno
	nodeAluno * p;
	for ( p = este->Primeiro ; p != NULL ; p = p->Proximo ) {

		LimpaAluno(&p->Valor);
		free(p);
	}
}
