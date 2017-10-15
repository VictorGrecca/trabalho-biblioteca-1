// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao estatica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include "Livro_Estatico.h"
#include "Defines.h"

// A lista de livros estatica se comporta como um banco de memoria

typedef struct {

	Livro Valor; // Os dados do livro que o no guarda
	int Usado;	 // Variavel que indica se o no esta livre para ser utilizado ou nao
	int Proximo;	 // Indice do proximo no

} NodeLivro;

typedef struct {

	int Primeiro;	// Indice do primeiro no
	int Ultimo;		// Indice do ultimo no
	NodeLivro Vetor[TAMANHO_LIVROS];	// Vetor de nos

} ListaLivro; // Declaracao de uma lista de livros

void ListaLivroCria ( ListaLivro * ); // Funcao de inicializacao
void ListaLivroInsere ( ListaLivro *, string, string, string, string, string, int * ); // Funcao de insercao de um livro numa lista de livros
void ListaLivroRemove ( ListaLivro *, int, int * ); // Funcao de remocao de um livro de uma lista de livros
int ListaLivroEstaVazia ( ListaLivro * ); // Funcao que avalia se uma lista esta vazia
int ProximoVazioListaLivro ( ListaLivro * ); // Funcao que retorna o proximo espaco vazio da lista de livros
int AnteriorListaLivro ( ListaLivro *, int ); // Funcao que retorna o valor do indice do nó anterior a algum nó
void ListaLivroFinaliza( ListaLivro * ); // Rotina de limpeza