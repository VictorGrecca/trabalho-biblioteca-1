// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao dinamica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include <stdio.h> 
#include <stdlib.h>
#include "Pilha_Mensagens_Dinamico.h"

void PilhaMsgCria( PilhaMsg * este ) {

	este->Itens = NULL;	
	este->Top = -1;
}

void PilhaMsgFinaliza( PilhaMsg * este ) {

	// 'Popa' toda a pilha e limpa as strings
	string pop;
	while (1) { 
		pop = PilhaMsgPop(este);
		if (pop == NULL)
			break;
		else
			StringLimpa(pop);
	}
	free(este->Itens);
	return;
}

int PilhaMsgEstaVazia( PilhaMsg * este ) {

	return ( este->Top == -1 );
}

void PilhaMsgPush( PilhaMsg * este, string msg ) {

	// Aumenta o valor do topo e o tamanho da pilha
	este->Top++;

	este->Itens = (string*) realloc( este->Itens, este->Top+1 * sizeof(string) );
	if (este->Itens == NULL) {
			printf("ERRO: o sistema encontrou um problema! (Falha em alocação de memoria).\n");
			abort();
	}

	este->Itens[este->Top] = msg;	
	
}

// Popa a pilha e retorna a mensagem. Se estiver vazia, retorna NULL
string PilhaMsgPop( PilhaMsg * este ) {
	
	string temp;

	if( !PilhaMsgEstaVazia(este) ) {
	
		temp = este->Itens[este->Top];
		este->Top--;

		// Diminui o tamanho da pilha
		este->Itens = (char**)realloc( este->Itens, este->Top+1 * sizeof(string) );
		if (este->Itens == NULL) {
			printf("ERRO: o sistema encontrou um problema! (Falha em alocação de memoria).\n");
			abort();
		}
		return temp;
	}
	else
		return NULL;
}
