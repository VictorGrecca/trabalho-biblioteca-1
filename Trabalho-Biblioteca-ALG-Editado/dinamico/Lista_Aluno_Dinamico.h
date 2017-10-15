// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao dinamica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include "Aluno_Dinamico.h"

typedef struct NodeA {

	Aluno Valor;
	struct NodeA * Proximo;

} nodeAluno; // Declaracao de um no da lista de alunos

typedef struct {

	nodeAluno * Primeiro;
	nodeAluno * Ultimo;

} ListaAluno; // Declaracao da lista de alunos

void ListaAlunoCria (ListaAluno *); // Funcao de inicializacao
void ListaAlunoInsere (ListaAluno *, Aluno * ); // Funcao de insercao de um aluno numa lista de alunos
void ListaAlunoRemove (ListaAluno *, Aluno * ); // Funcao de remocao de um aluno de uma lista de alunos
void ListaAlunoFinaliza (ListaAluno *); // Funcao de limpeza
int ListaAlunoEstaVazia (ListaAluno *); // Funcao que avalia se uma lista esta vazias