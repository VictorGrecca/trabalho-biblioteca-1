// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao dinamica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#ifndef PILHA_MENSAGENS_H // Para evitar problemas com #include
#define PILHA_MENSAGENS_H

#include "String_Dinamico.h"

typedef struct {

	int Top; 
	string * Itens; // Os valores da pilha estao em um vetor dinamico de strings

} PilhaMsg; // Definicao da pilha de mensagens


void PilhaMsgCria ( PilhaMsg * ); // Funcao de inicializacao
void PilhaMsgFinaliza ( PilhaMsg * ); // Funcao de limpeza
int PilhaMsgEstaVazia ( PilhaMsg * ); // Funcao que verifica se uma pilha esta vazia
int PilhaMsgEstaCheia ( PilhaMsg * ); // Funcao verifica se uma pilha esta cheia
void PilhaMsgPush ( PilhaMsg *, string ); // Funcao que adiciona uma mensagem ao topo de uma pilha
string PilhaMsgPop ( PilhaMsg * ); // Funcao que 'popa' a mensagem do topo de uma pilha

#endif