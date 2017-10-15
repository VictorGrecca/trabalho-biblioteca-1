// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao dinamica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include <stdio.h> 
#include <stdlib.h>
#include "Livro_Dinamico.h"

void PrintaLivro ( Livro este ) {

	printf("\tTitulo: %s\n\tAutor: %s\n\tEditora: %s\n\tISBN: %s\n\tAno: %s\n\n",
		este.Titulo, este.Autor, este.Editora, este.Isbn, este.Ano );
}


// Limpa todas os dados do livro e finaliza sua fila de espera
void LimpaLivro ( Livro * este ) {
		
		StringLimpa(este->Titulo);
		StringLimpa(este->Autor);
		StringLimpa(este->Isbn);
		StringLimpa(este->Ano);
		FilaEsperaFinaliza(&este->Espera);
}
