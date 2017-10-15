// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao estatica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include <stdio.h> 
#include <stdlib.h>
#include "Aluno_Estatico.h"

void PrintaAluno ( Aluno * this ) {

	printf("\tNome: %s\n\tNumero USP: %s\n\tTelefone: %s\n\tEmail: %s\n\n",
		this->Nome, this->Nusp, this->Tel, this->Email );
}

void PrintaNUSPAluno ( Aluno * this ) {

	printf("\tAluno: %s\n\t  Numero USP: %s\n\n", this->Nome, this->Nusp);
}

void PrintaMensagens ( Aluno * this ) {

	printf("\n  -> Todas as mensagens nao lidas do aluno %s:\n\n", this->Nome );

	// Popa e printa todas as mensagens da pilha do aluno
	
	int erro = 1;
	string printa;

	while (!erro) {
		
		PilhaMsgPop( &this->Mensagens, printa, &erro );
		if (!erro) // Sem esse if(), uma string nula seria printada no final
			printf("\t-> %s\n", printa );
	}

}

void LimpaAluno ( Aluno * this ) {


	// 'Limpa' as strings
	StringLimpa( this->Nome );
	StringLimpa( this->Nusp );
	StringLimpa( this->Tel );
	StringLimpa( this->Email );

	// Reseta a pilha de mensagens
	PilhaMsgReseta( &this->Mensagens );

}