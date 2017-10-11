// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao dinamica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include <stdio.h> 
#include <stdlib.h>
#include "Aluno_Dinamico.h"

void PrintaAluno ( Aluno * this ) {

	printf("\tNome: %s\n\tNumero USP: %s\n\tTelefone: %s\n\tEmail: %s\n\n",
		this->Nome, this->Nusp, this->Tel, this->Email );
}

void PrintaNUSPAluno ( Aluno * this ) {

	printf("\tAluno: %s\n\t  Numero USP: %s\n\n", this->Nome, this->Nusp);
}

void PrintaMensagens ( Aluno * this ) {

	printf("\n ->  Todas as mensagens nao lidas do aluno %s:\n\n", this->Nome );

	string printa = malloc( 100 );
	if (printa == NULL) {
		printf("ERRO: o sistema encontrou um problema (falha em alocação de memoria)\n");
		abort();
	}

	while (printa != NULL) {
		printa = PilhaMsgPop(&this->Mensagens);
		if (printa != NULL) // Sem esse if(), uma string nula seria printada no final
			printf("\t-> %s\n", printa );
	}

}

// Limpa todos os dados de um aluno, finalizando sua pilha de mensagens
void LimpaAluno ( Aluno * this ) {
		
		StringLimpa(this->Nome);
		StringLimpa(this->Nusp);
		StringLimpa(this->Tel);
		StringLimpa(this->Email);
		PilhaMsgFinaliza(&this->Mensagens);

}