// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao dinamica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include "String_Dinamico.h"
#include "Fila_Espera_Dinamico.h"

typedef struct {

    string Titulo;
    string Autor;
    string Editora;
    string Isbn;
    string Ano;
    int Qnt; // Variavel que indica a quantidade de copias do livro disponiveis no momento
    int Loc; // Variavel que indica quantas copias do livro estao locadas no momento
    FilaEspera Espera; // Fila de espera para o livro

} Livro;

void PrintaLivro ( Livro ); // Funcao para printar os dados de um livro
void LimpaLivro ( Livro * ); // Funcao de limpeza