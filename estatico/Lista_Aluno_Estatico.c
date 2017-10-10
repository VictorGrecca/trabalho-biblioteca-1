// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao estatica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include <stdio.h> 
#include <stdlib.h>
#include "Lista_Aluno_Estatico.h"

void ListaAlunoCria( ListaAluno * this ) {

	// Seta a lista como 'vazia'
	this->Primeiro = -1;
	this->Ultimo = -1;

	// Seta todos os nos da lista como livres seus 'proximos' como o proximo indice
	int i;
	for ( i = 0 ; i < TAMANHO_ALUNOS ; i++ ) {
		
		this->Vetor[i].Usado = 0;
		this->Vetor[i].Proximo = i+1;
	}

	// Seta o proximo do ultimo indice como -1
	this->Vetor[TAMANHO_ALUNOS-1].Proximo = -1;

}

int ListaAlunoEstaVazia( ListaAluno * this ) {

	return ( this->Primeiro == -1 );
}

void ListaAlunoInsere( ListaAluno * this, string ArgNome, string ArgNusp, string ArgTel, string ArgEmail, int * erro ) {

	// Encontra o indice do vetor em que o novo aluno entrara
	int indice = ProximoVazioListaAluno(this);
	if( indice == -1 ) {
		// Caso a lista esteja cheia
		*erro = 1;
		return;
	}	
	
	// Caso a lista nao esteja cheia, pois a funcao nao retornou
	
	*erro = 0;

	// Caso a lista esteja vazia
	if ( ListaAlunoEstaVazia(this) ) {
		
		// Atualiza valores da lista e do no
		this->Primeiro = 0;
		this->Ultimo = 0;
		this->Vetor[0].Usado = 1;
		this->Vetor[0].Proximo = -1;



		// Armazena os argumentos da funcao (dados do aluno) no no do aluno 
		strcpy(this->Vetor[0].Valor.Nome, ArgNome);
		strcpy(this->Vetor[0].Valor.Nusp, ArgNusp);
		strcpy(this->Vetor[0].Valor.Tel, ArgTel);
		strcpy(this->Vetor[0].Valor.Email, ArgEmail);


		// Inicializa a pilha de mensagens do aluno
		PilhaMsgCria( &this->Vetor[0].Valor.Mensagens );

		return;
	}
	
	// Caso nao esteja vazia
	else {

		// Armazena os argumentos da funcao (dados do aluno) no no do aluno 
		strcpy(this->Vetor[indice].Valor.Nome, ArgNome);
		strcpy(this->Vetor[indice].Valor.Nusp, ArgNusp);
		strcpy(this->Vetor[indice].Valor.Tel, ArgTel);
		strcpy(this->Vetor[indice].Valor.Email, ArgEmail);
		
		// Atualiza valores da lista e do no
		this->Vetor[indice].Usado = 1;
		this->Vetor[this->Ultimo].Proximo = indice;
		this->Ultimo = indice;
		this->Vetor[indice].Proximo = -1;


		// Inicializa a pilha de mensagens do aluno
		PilhaMsgCria( &this->Vetor[0].Valor.Mensagens );
	}


}

void ListaAlunoRemove( ListaAluno * this, int arg, int * erro ) {

	// Caso a lista esteja vazia
	if( ListaAlunoEstaVazia( this ) ) {
		*erro = 1;
		return;

	}

	// Caso a lista nao esteja vazia, pois a funcao nao retornou

	*erro = 0;


	// Caso o aluno a se remover seja o unico da lista
	if( ( arg == this->Primeiro ) && ( arg == this->Ultimo ) ) {

		this->Vetor[arg].Usado = 0;
		this->Primeiro = -1;
		this->Ultimo = -1;

		// Caso o indice do aluno seja o ultimo do vetor, seu valor de proximo deve ser -1
		// Senao, é o proximo indice
		if (arg != TAMANHO_ALUNOS-1)
			this->Vetor[arg].Proximo = arg+1;
		else
			this->Vetor[arg].Proximo = -1;

		// Limpa os valores da memoria deste aluno
		LimpaAluno( &this->Vetor[arg].Valor );

		return;
	}

	// Caso o aluno a se remover seja o ultimo da lista
	if ( arg == this->Ultimo ) {

		this->Vetor[arg].Usado = 0;
		this->Ultimo = AnteriorListaAluno(this, arg);

		// Caso o indice do aluno seja o ultimo do vetor, seu valor de proximo deve ser -1
		// Senao, é o proximo indice
		if (arg != TAMANHO_ALUNOS-1)
			this->Vetor[arg].Proximo = arg+1;
		else
			this->Vetor[arg].Proximo = -1;

		// Limpa os valores da memoria deste aluno
		LimpaAluno( &this->Vetor[arg].Valor );

		return;
	}

	// Caso o aluno a se remover seja o primeiro da lista
	if ( arg == this->Primeiro ) {

		this->Vetor[arg].Usado = 0;
		this->Primeiro = this->Vetor[arg].Proximo;

		// Caso o indice do aluno seja o ultimo do vetor, seu valor de proximo deve ser -1
		// Senao, é o proximo indice
		if (arg != TAMANHO_ALUNOS-1)
			this->Vetor[arg].Proximo = arg+1;
		else
			this->Vetor[arg].Proximo = -1;

		// Limpa os valores da memoria deste aluno
		LimpaAluno( &this->Vetor[arg].Valor );

		return;
	}

	// Caso o aluno a se remover esteja no meio da lista, pois a funcao nao retornou ainda
	this->Vetor[arg].Usado = 0;
	this->Vetor[AnteriorListaAluno(this, arg)].Proximo = this->Vetor[arg].Proximo;

	// Caso o indice do aluno seja o ultimo do vetor, seu valor de proximo deve ser -1
	// Senao, é o proximo indice
	if (arg != TAMANHO_ALUNOS-1)
		this->Vetor[arg].Proximo = arg+1;
	else
		this->Vetor[arg].Proximo = -1;

	// Limpa os valores da memoria deste aluno
	LimpaAluno( &this->Vetor[arg].Valor );

	return;
}

int ProximoVazioListaAluno( ListaAluno * this ) {

	// Varre TODO o vetor e, assim que encontrar um no livre, retorna seu indice
	int i;
	for ( i = 0 ; i < TAMANHO_ALUNOS ; i++ )
		if( this->Vetor[i].Usado == 0 )
			return i;

	return -1;	// -1 indica que a lista esta cheia
}

int AnteriorListaAluno( ListaAluno * this , int indice ) {

	// Encontra o valor do no anterior
	int i;
	for ( i = this->Primeiro ; 1 ; i = this->Vetor[i].Proximo )
		if( this->Vetor[i].Proximo == indice )
			return i;

	// Caso nao encontre o valor anterior (!?)
	return -1;
}

void ListaAlunoFinaliza( ListaAluno* this ) {

	ListaAlunoCria(this);

}