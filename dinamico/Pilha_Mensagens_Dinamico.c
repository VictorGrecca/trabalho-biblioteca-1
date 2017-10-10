// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao dinamica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include <stdio.h> 
#include <stdlib.h>
#include "Pilha_Mensagens_Dinamico.h"

void PilhaMsgCria( PilhaMsg * this ) {

	this->Itens = NULL;	
	this->Top = -1;
}

void PilhaMsgFinaliza( PilhaMsg * this ) {

	// 'Popa' toda a pilha e limpa as strings
	string pop;
	while (1) { 
		pop = PilhaMsgPop(this);
		if (pop == NULL)
			break;
		else
			StringLimpa(pop);
	}
	free(this->Itens);
	return;
}

int PilhaMsgEstaVazia( PilhaMsg * this ) {

	return ( this->Top == -1 );
}

void PilhaMsgPush( PilhaMsg * this, string msg ) {

	// Aumenta o valor do topo e o tamanho da pilha
	this->Top++;

	this->Itens = (string*) realloc( this->Itens, this->Top+1 * sizeof(string) );
	if (this->Itens == NULL) {
			printf("->  ERRO: o sistema encontrou um problema! (Falha em alocação de memoria).\n");
			abort();
	}

	this->Itens[this->Top] = msg;	
	
}

// Popa a pilha e retorna a mensagem. Se estiver vazia, retorna NULL
string PilhaMsgPop( PilhaMsg * this ) {
	
	string temp;

	if( !PilhaMsgEstaVazia(this) ) {
	
		temp = this->Itens[this->Top];
		this->Top--;

		// Diminui o tamanho da pilha
		this->Itens = realloc( this->Itens, this->Top+1 * sizeof(string) );
		if (this->Itens == NULL) {
			printf("->  ERRO: o sistema encontrou um problema! (Falha em alocação de memoria).\n");
			abort();
		}
		return temp;
	}
	else
		return NULL;
}