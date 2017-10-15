// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao dinamica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include "Lista_Livro_Dinamico.h"
#include "Lista_Aluno_Dinamico.h"

// Rotinas especificas para tratar livros:

void InicializaBiblio( ListaLivro* ); // Funcao de inicializacao da estrutura de dados que guardara os livros
void LivroCadastra( ListaLivro* ); // Funcao de cadastramento de um livro
void LivroRemove( ListaLivro* ); // Funcao de remocao de um livro
Livro* LivroBusca( ListaLivro* ); // Funcao que busca um livro e retorna um ponteiro para o mesmo

// Rotinas especificas para tratar aluno:

void InicializaAlunos ( ListaAluno * );  // Funcao de inicializacao da estrutura de dados que guardara os alunos
void AlunoCadastra( ListaAluno* ); // Funcao de cadastramento de um aluno
void AlunoRemove( ListaAluno* ); // Funcao de remocao de um aluno
Aluno* AlunoBusca( ListaAluno* ); // Funcao que busca um aluno e retorna um ponteiro para o mesmo
void MensagensNaoLidas( ListaAluno * ); // Funcao que imprime todas as mensagens nao lidas de um aluno

// Rotinas mistas:

void LivroRetira( ListaLivro*, ListaAluno* ); // Funcao de locacao de um livro
void LivroRetorna( ListaLivro*, ListaAluno* ); // Funcao de devolucao de um livro

// Etc

void EsperaEnter(); // Funcao que faz o programa esperar ate que o usuario pressione 'ENTER'