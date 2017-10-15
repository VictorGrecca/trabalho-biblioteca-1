// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao dinamica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include <stdio.h> 
#include <stdlib.h>
#include "Aluno_Dinamico.h"

void PrintaAluno ( Aluno * este ) {

	printf("\tNome: %s\n\tNumero USP: %s\n\tTelefone: %s\n\tEmail: %s\n\n",
		este->Nome, este->Nusp, este->Tel, este->Email );
}

void PrintaNUSPAluno ( Aluno * este ) {

	printf("\tAluno: %s\n\t  Numero USP: %s\n\n", este->Nome, este->Nusp);
}

void PrintaMensagens ( Aluno * este ) {

	printf("\n ->  Todas as mensagens nao lidas do aluno %s:\n\n", este->Nome );

	string printa = (char *)malloc( 100 );
	if (printa == NULL) {
		printf("ERRO: o sistema encontrou um problema (falha em alocação de memoria)\n");
		abort();
	}

	while (printa != NULL) {
		printa = PilhaMsgPop(&este->Mensagens);
		if (printa != NULL) // Sem esse if(), uma string nula seria printada no final
			printf("\t-> %s\n", printa );
	}

}

// Limpa todos os dados de um aluno, finalizando sua pilha de mensagens
void LimpaAluno ( Aluno * este ) {
		
		StringLimpa(este->Nome);
		StringLimpa(este->Nusp);
		StringLimpa(este->Tel);
		StringLimpa(este->Email);
		PilhaMsgFinaliza(&este->Mensagens);

}
