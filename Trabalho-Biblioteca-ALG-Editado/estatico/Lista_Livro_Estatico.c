// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao estatica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include <stdio.h> 
#include <stdlib.h>
#include "Lista_Livro_Estatico.h"

void ListaLivroCria( ListaLivro * this ) {

	// Seta a lista como 'vazia'
	this->Primeiro = -1;
	this->Ultimo = -1;

	// Seta todos os nos da lista como livres seus 'proximos' como o proximo indice
	int i;
	for ( i = 0 ; i < TAMANHO_LIVROS ; i++ ) {
		
		this->Vetor[i].Usado = 0;
		this->Vetor[i].Proximo = i+1;
	}

	// Seta o proximo do ultimo indice como -1
	this->Vetor[TAMANHO_LIVROS-1].Proximo = -1;

}

int ListaLivroEstaVazia( ListaLivro * this ) {

	return ( this->Primeiro == -1 );
}

void ListaLivroInsere( ListaLivro * this, string ArgTitulo, string ArgAutor, string ArgEditora, string ArgIsbn, string ArgAno, int * erro ) {

	// Encontra o indice do vetor em que o novo livro entrara
	int indice = ProximoVazioListaLivro(this);
	if( indice == -1 ) {
		// Caso a lista esteja cheia
		*erro = 1;
		return;
	}	
	
	// Caso a lista nao esteja cheia, pois a funcao nao retornou
	
	*erro = 0;

	// Caso a lista esteja vazia
	if ( ListaLivroEstaVazia(this) ) {
		
		// Atualiza valores da lista e do no
		this->Primeiro = 0;
		this->Ultimo = 0;
		this->Vetor[0].Usado = 1;
		this->Vetor[0].Proximo = -1;

		
		// Armazena os argumentos da funcao (dados do aluno) no no do aluno 
		strcpy( this->Vetor[0].Valor.Titulo, ArgTitulo );
		strcpy( this->Vetor[0].Valor.Autor, ArgAutor );
		strcpy( this->Vetor[0].Valor.Editora, ArgEditora );
		strcpy( this->Vetor[0].Valor.Isbn, ArgIsbn );
		strcpy( this->Vetor[0].Valor.Ano, ArgAno );

		// Obviamente, o livro é inicializado com 1 copia, sendo 0 delas alugadas no momento
		this->Vetor[0].Valor.Qnt = 1;
		this->Vetor[0].Valor.Loc = 0;

		// Inicializa a lista de espera do livro
		FilaEsperaCria( &this->Vetor[0].Valor.Espera );

		return;
	}
	
	// Caso nao esteja vazia
	else {

		// Armazena os argumentos da funcao (dados do aluno) no no do aluno 
		strcpy( this->Vetor[indice].Valor.Titulo, ArgTitulo );
		strcpy( this->Vetor[indice].Valor.Autor, ArgAutor );
		strcpy( this->Vetor[indice].Valor.Editora, ArgEditora );
		strcpy( this->Vetor[indice].Valor.Isbn, ArgIsbn );
		strcpy( this->Vetor[indice].Valor.Ano, ArgAno );


		// Atualiza valores da lista e do no

		this->Vetor[indice].Usado = 1;
		this->Vetor[this->Ultimo].Proximo = indice;
		this->Ultimo = indice;
		this->Vetor[indice].Proximo = -1;


		// Obviamente, o livro é inicializado com 1 copia, sendo 0 delas alugadas no momento
		this->Vetor[indice].Valor.Qnt = 1;
		this->Vetor[indice].Valor.Loc = 0;

		// Inicializa a lista de espera do livro
		FilaEsperaCria( &this->Vetor[indice].Valor.Espera );
	}


}

void ListaLivroRemove( ListaLivro * this, int arg, int * erro ) {

	// Caso a lista esteja vazia
	if( ListaLivroEstaVazia( this ) ) {
		*erro = 1;
		return;

	}

	// Caso a lista nao esteja vazia, pois a funcao nao retornou

	*erro = 0;


	// Caso o livro a se remover seja o unico da lista
	if( ( arg == this->Primeiro ) && ( arg == this->Ultimo ) ) {

		this->Vetor[arg].Usado = 0;
		this->Primeiro = -1;
		this->Ultimo = -1;

		// Caso o indice do livro seja o ultimo do vetor, seu valor de proximo deve ser -1
		// Senao, é o proximo indice
		if (arg != TAMANHO_LIVROS-1)
			this->Vetor[arg].Proximo = arg+1;
		else
			this->Vetor[arg].Proximo = -1;

		// Limpa os valores da memoria deste livro
		LimpaLivro( &this->Vetor[arg].Valor );

		return;
	}

	// Caso o livro a se remover seja o ultimo da lista
	if ( arg == this->Ultimo ) {

		this->Vetor[arg].Usado = 0;
		this->Ultimo = AnteriorListaLivro(this, arg);

		// Caso o indice do livro seja o ultimo do vetor, seu valor de proximo deve ser -1
		// Senao, é o proximo indice
		if (arg != TAMANHO_LIVROS-1)
			this->Vetor[arg].Proximo = arg+1;
		else
			this->Vetor[arg].Proximo = -1;

		// Limpa os valores da memoria deste livro
		LimpaLivro( &this->Vetor[arg].Valor );

		return;
	}

	// Caso o livro a se remover seja o primeiro da lista
	if ( arg == this->Primeiro ) {

		this->Vetor[arg].Usado = 0;
		this->Primeiro = this->Vetor[arg].Proximo;

		// Caso o indice do livro seja o ultimo do vetor, seu valor de proximo deve ser -1
		// Senao, é o proximo indice
		if (arg != TAMANHO_LIVROS-1)
			this->Vetor[arg].Proximo = arg+1;
		else
			this->Vetor[arg].Proximo = -1;

		// Limpa os valores da memoria deste livro
		LimpaLivro( &this->Vetor[arg].Valor );

		return;
	}

	// Caso o livro a se remover esteja no meio da lista, pois a funcao nao retornou ainda
	this->Vetor[arg].Usado = 0;
	this->Vetor[AnteriorListaLivro(this, arg)].Proximo = this->Vetor[arg].Proximo;

	// Caso o indice do livro seja o ultimo do vetor, seu valor de proximo deve ser -1
	// Senao, é o proximo indice
	if (arg != TAMANHO_LIVROS-1)
		this->Vetor[arg].Proximo = arg+1;
	else
		this->Vetor[arg].Proximo = -1;

	// Limpa os valores da memoria deste livro
	LimpaLivro( &this->Vetor[arg].Valor );

	return;
}

int ProximoVazioListaLivro( ListaLivro * this ) {

	// Varre TODO o vetor e, assim que encontrar um no livre, retorna seu indice
	int i;
	for ( i = 0 ; i < TAMANHO_LIVROS ; i++ )
		if( this->Vetor[i].Usado == 0 )
			return i;

	return -1;	// -1 indica que a lista esta cheia
}

int AnteriorListaLivro( ListaLivro * this , int indice ) {

	// Encontra o valor do no anterior
	int i;
	for ( i = this->Primeiro ; 1 ; i = this->Vetor[i].Proximo )
		if( this->Vetor[i].Proximo == indice )
			return i;

	// Caso nao encontre o valor anterior (!?)
	return -1;
}

void ListaLivroFinaliza( ListaLivro* this ) {

	ListaLivroCria(this);

}