// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao dinamica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#ifndef ALUNO_H // Para evitar problemas com #include
#define ALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include "Pilha_Mensagens_Dinamico.h"
#include "String_Dinamico.h"

typedef struct {

    string Nome;
    string Nusp;
    string Tel;
    string Email;
    PilhaMsg Mensagens; // Pilha de mensagens do aluno

} Aluno;

void PrintaAluno( Aluno * ); // Funcao para printar os dados de um aluno
void PrintaNUSPAluno( Aluno * ); // Funcao para printar apenas o nome e numero usp de um aluno
void PrintaMensagens ( Aluno * ); // Funcao para printar todas as mensagens nao lidas de um aluno
void LimpaAluno ( Aluno * ); // Funcao de limpeza
#endif