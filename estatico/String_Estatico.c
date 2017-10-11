// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao estatica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "String_Estatico.h"

void StringLe( string texto ) {

	LimpaBuffer();

	fgets(texto, TAMANHO_STRING, stdin);
	
	// Tratamento da string gerada ,pois fgets() guarda o '\n' no final da string
	texto[strlen(texto)-1] = '\0';

}

void LimpaBuffer() {
	/* Uma das funcoes limpa o buffer no Windows e o outro no Linux,
	 portanto, usamos ambas para portabilidade */
	fflush(stdin);
	//__fpurge(stdin); // Retire o comentario desta linha caso rode o programa no linux

}

void StringLimpa( string this ) {

	this[0] = '\0';
}