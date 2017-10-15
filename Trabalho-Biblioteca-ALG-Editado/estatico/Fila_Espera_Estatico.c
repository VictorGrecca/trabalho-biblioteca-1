// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao estatica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include <stdio.h>
#include <stdlib.h>
#include "Fila_Espera_Estatico.h"

void FilaEsperaCria (FilaEspera * this) {

	this->Primeiro = -1;
	this->Ultimo = -1;
	this->Tam = 0;
}

int FilaEsperaEstaVazia( FilaEspera * this ) {

	return ( this->Primeiro == -1 );
}

int FilaEsperaEstaCheia( FilaEspera * this ) {

	return ( this->Tam == TAMANHO_FILA );
}

void FilaEsperaInsere( FilaEspera * this, Aluno * arg, int * erro ) {

	// Caso a fila esteja cheia
	if ( FilaEsperaEstaCheia( this ) ) {
		*erro = 1;
		return;
	}
	else { // Caso nao esteja
		*erro = 0;

		// Caso a fila esteja vazia
		if ( FilaEsperaEstaVazia( this ) ) {
			this->Primeiro = 0;
			this->Ultimo = 0;
			this->Itens[this->Ultimo] = arg;			
			this->Tam++;
			return;
		}
		// Caso o ultimo aponte para a ultima posicao do vetor
		if (this->Ultimo == TAMANHO_FILA-1) {
			this->Ultimo = 0;
			this->Itens[this->Ultimo] = arg;
			this->Tam++;
			return;
		}
		// Demais casos
		this->Ultimo++;
		this->Itens[this->Ultimo] = arg;
		this->Tam++;
	}
	
}

// 'Anda' a fila armazena o valor que saiu na variavel andas
void FilaEsperaAnda( FilaEspera* this, Aluno* anda, int* erro ) {

	// Caso a fila esteja vazia
	if ( FilaEsperaEstaVazia( this ) ) {
		*erro = 1;
		anda = NULL;
	}
	else { // Caso nao esteja
		*erro = 0;

		anda = this->Itens[this->Primeiro];

		/* Caso o primeiro da fila seja o ultimo indice do vetor,
			a fila 'da a volta' para o comeco do vetor */
		if (this->Primeiro == TAMANHO_FILA-1) {
			this->Primeiro = 0;
			this->Tam--;
			return;
		}
		// Caso o vetor possua apenas um indice, a fila se torna vazia
		if (this->Primeiro == this->Ultimo) {
			this->Primeiro = -1;
			this->Ultimo = -1;
			this->Tam--;
			return;
		}
		// Demais casos
		this->Primeiro++;
		this->Tam--;

	}
}

void FilaEsperaReseta ( FilaEspera * this ) {

	int erro = 1;
	Aluno* lixo;

	// Anda toda a fila
	while (!erro)
		FilaEsperaAnda( this, lixo, &erro );

	// Reinicializa a fila de espera
	FilaEsperaCria( this );
}