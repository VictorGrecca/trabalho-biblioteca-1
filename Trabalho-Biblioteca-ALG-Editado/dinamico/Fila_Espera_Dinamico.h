// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao dinamica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include "Aluno_Dinamico.h"

typedef struct nodeF {

	struct nodeF * Proximo;
	Aluno * Valor;

} nodeFila; // Declaracao de um no da lista, que se comporta como uma fila

typedef struct {

    nodeFila * Primeiro;
    nodeFila * Ultimo;

} FilaEspera; // Declaracao da fila de espera, que é uma lista ligada

void FilaEsperaCria ( FilaEspera * ); // Funcao de inicializacao
int FilaEsperaEstaVazia (FilaEspera * ); // Funcao que avalia se uma fila de espra esta vazia
void FilaEsperaInsere ( FilaEspera *, Aluno * ); // Funcao que insere um aluno em uma fila de espera
Aluno* FilaEsperaAnda ( FilaEspera * ); // Funcao que retira o proximo aluno da fila de espra e retorna um ponteiro para o mesmo
void FilaEsperaFinaliza (FilaEspera * ); // Funcao de limpeza
int FilaEsperaTamanho (FilaEspera * ); // Funcao que retorna o tamanho de uma fila de espera