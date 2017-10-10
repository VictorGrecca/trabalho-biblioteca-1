// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao dinamica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include <string.h>

// Representacao de uma string em C, usando um TAD:
typedef char* string;

string StringLe(); // Funcao para ler uma string (ate 100 caracteres)
void StringLimpa( string ); // Funcao de limpeza de uma string
void LimpaBuffer(); // Funcao para limpar o buffer de entrada e evitar problemas com '\n'
