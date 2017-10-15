// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao dinamica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include "Livro_Dinamico.h"

typedef struct NodeL {

	Livro Valor;
	struct NodeL * Proximo;

} nodeLivro; // Declaracao de um no da lista de livros

typedef struct {

	nodeLivro * Primeiro;
	nodeLivro * Ultimo;

} ListaLivro; // Declaracao de uma lista de livros

void ListaLivroCria (ListaLivro *); // Funcao de inicializacao
void ListaLivroInsere (ListaLivro *, Livro * ); // Funcao de insercao de um livro numa lista de livros
void ListaLivroRemove (ListaLivro *, Livro * ); // Funcao de remocao de um livro de uma lista de livros
void ListaLivroFinaliza (ListaLivro *); // Funcao de limpeza
int ListaLivroEstaVazia (ListaLivro *); // Funcao que avalia se uma lista esta vaiza