// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao estatica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#ifndef ALUNO_H // Para evitar problemas com #include
#define ALUNO_H

#include <stdio.h>
#include <stdlib.h>
#include "Pilha_Mensagens_Estatico.h"
#include "String_Estatico.h"
#include "Defines.h"

typedef struct {

    string Nome;
    string Nusp;
    string Tel;
    string Email;
    PilhaMsg Mensagens; // Pilha de mensagens do aluno

} Aluno;

void PrintaAluno ( Aluno * ); // Funcao para printar os dados de um aluno
void PrintaNUSPAluno ( Aluno * ); // Funcao para printar apenas o nome e numero usp de um aluno
void PrintaMensagens ( Aluno * ); // Funcao para printar todas as mensagens nao lidas de um aluno
void LimpaAluno ( Aluno * ); // Funcao que 'limpa' os valores armazenados de um aluno (nao é um free, apenas 'zera' o lixo de memoria)

#endif