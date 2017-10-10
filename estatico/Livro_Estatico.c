// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao estatica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include <stdio.h> 
#include <stdlib.h>
#include "Livro_Estatico.h"

void PrintaLivro ( Livro* this ) {

	printf("\tTitulo: %s\n\tAutor: %s\n\tEditora: %s\n\tISBN: %s\n\tAno: %s\n\n",
		this->Titulo, this->Autor, this->Editora, this->Isbn, this->Ano );
}

void LimpaLivro ( Livro* this ) {


	// 'Limpa' as strings
	StringLimpa( this->Titulo );
	StringLimpa( this->Autor );
	StringLimpa( this->Editora );
	StringLimpa( this->Isbn );
	StringLimpa( this->Ano );

	this->Qnt = 0;
	this->Loc = 0;

	// Reseta a fila de espera
	FilaEsperaReseta( &this->Espera );

}