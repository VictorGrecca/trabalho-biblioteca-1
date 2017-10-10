// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao estatica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include <stdio.h> 
#include <stdlib.h>
#include "Pilha_Mensagens_Estatico.h"

void PilhaMsgCria( PilhaMsg * this ) {

	this->Top = -1;
}

int PilhaMsgEstaVazia( PilhaMsg * this ) {

	return ( this->Top == -1 );
}

int PilhaMsgEstaCheia( PilhaMsg * this ) {

	return ( this->Top == TAMANHO_PILHA-1 );
}

void PilhaMsgPush( PilhaMsg * this, string * msg, int * erro ) {

	// Caso a pilha de mensagens do auno esteja cheia, a mensagem simplesmente nao é enviada.
	if( PilhaMsgEstaCheia(this) ) {
		*erro = 1;
		return;
	}
	else {

		*erro = 0;
		// Aumenta o valor do topo coloca a mensagem no topo
		this->Top++;
		strcpy( this->Itens[this->Top], *msg );	

	}

}

// Popa a pilha e coloca a mensagem na string pop
void PilhaMsgPop( PilhaMsg * this, string pop, int * erro ) {
	
	if( !PilhaMsgEstaVazia(this) ) {
		// Caso a pilha nao esteja vazia, popa
		*erro = 0;
		strcpy( pop , this->Itens[this->Top] );
		this->Top--;
	}
	else {
		// Caso a pilha esteja vazia, pop é iniciado com termino de string
		*erro = 1;
		pop[0] = '\0';
	}
}

void PilhaMsgReseta ( PilhaMsg * this ) {

	int erro = 1;
	string lixo;

	// Popa toda a pilha
	while (!erro)
		PilhaMsgPop( this, lixo, &erro );

	// Reinicializa a pilha
	PilhaMsgCria( this );
}