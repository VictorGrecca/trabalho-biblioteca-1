// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao estatica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include <string.h>
#include "Defines.h"

// Representacao de uma string em C com um vetor de 100 caracteres, usando um TAD:
typedef char string[TAMANHO_STRING];

void StringLe( string ); // Funcao para ler uma string (ate 100 caracteres)
void LimpaBuffer(); // Funcao para limpar o buffer de entrada e evitar problemas com '\n'
void StringLimpa( string ); // Funcao que 'limpa' uma string estatica (seu primeiro caracter se torna '\0' e entao a string é nula)