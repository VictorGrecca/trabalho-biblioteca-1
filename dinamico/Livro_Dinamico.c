// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao dinamica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include <stdio.h> 
#include <stdlib.h>
#include "Livro_Dinamico.h"

void PrintaLivro ( Livro this ) {

	printf("\tTitulo: %s\n\tAutor: %s\n\tEditora: %s\n\tISBN: %s\n\tAno: %s\n\n",
		this.Titulo, this.Autor, this.Editora, this.Isbn, this.Ano );
}


// Limpa todas os dados do livro e finaliza sua fila de espera
void LimpaLivro ( Livro * this ) {
		
		StringLimpa(this->Titulo);
		StringLimpa(this->Autor);
		StringLimpa(this->Isbn);
		StringLimpa(this->Ano);
		FilaEsperaFinaliza(&this->Espera);
}