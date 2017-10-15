// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao estatica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include "Aluno_Estatico.h"
#include "Defines.h"

// A lista de alunos estatica se comporta como um banco de memoria

typedef struct {

	Aluno Valor; // Os dados do aluno que o no guarda
	int Usado;	 // Variavel que indica se o no esta livre para ser utilizado ou nao
	int Proximo;	 // Indice do proximo no

} NodeAluno;

typedef struct {

	int Primeiro;	// Indice do primeiro no
	int Ultimo;		// Indice do ultimo no
	NodeAluno Vetor[TAMANHO_ALUNOS];	// Vetor de nos

} ListaAluno; // Declaracao de uma lista de alunos

void ListaAlunoCria ( ListaAluno * ); // Funcao de inicializacao
void ListaAlunoInsere ( ListaAluno *, string, string, string, string, int * ); // Funcao de insercao de um aluno numa lista de alunos
void ListaAlunoRemove ( ListaAluno *, int, int * ); // Funcao de remocao de um aluno de uma lista de alunos
int ListaAlunoEstaVazia ( ListaAluno * ); // Funcao que avalia se uma lista esta vazia
int ProximoVazioListaAluno ( ListaAluno * ); // Funcao que retorna o proximo espaco vazio da lista de alunos
int AnteriorListaAluno ( ListaAluno *, int ); // Funcao que retorna o valor do indice do nó anterior a algum nó
void ListaAlunoFinaliza( ListaAluno * ); // Rotina de limpeza