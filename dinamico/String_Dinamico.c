// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao dinamica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "String_Dinamico.h"

string StringLe() {


	string texto;
	texto = malloc( 100 ); // Alocacao de 100 bytes (100 chars) para todas as strings do codigo
	if (texto == NULL) {
		printf("->  ERRO: o sistema encontrou um problema! (Falha em alocação de memoria).\n");
		abort();
	}

	LimpaBuffer();

	fgets(texto, 100, stdin);
	
	// Tratamento da string gerada ,pois fgets() guarda o '\n' no final da string
	texto[strlen(texto)-1] = '\0';

	return texto;
}

void StringLimpa(string p) {
	/* Apesar de ser apenas um free(), a criacao da funcao 
	 facilita a compreensao ao utilizar em niveis mais altos do codigo */
	free(p);
}

void LimpaBuffer() {
	/* Uma das funcoes limpa o buffer no Windows e o outro no Linux,
	 portanto, usamos ambas para portabilidade */
	fflush(stdin);
	__fpurge(stdin);

}