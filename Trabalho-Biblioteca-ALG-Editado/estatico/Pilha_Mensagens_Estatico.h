// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao estatica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#ifndef PILHA_MENSAGENS_H // Para evitar problemas com #include
#define PILHA_MENSAGENS_H

#include "String_Estatico.h"
#include "Defines.h"

typedef struct {

	int Top; 
	string Itens[TAMANHO_PILHA]; // Os valores da pilha estao em um vetor dinamico de strings

} PilhaMsg; // Definicao da pilha de mensagens


void PilhaMsgCria ( PilhaMsg * ); // Funcao de inicializacao
int PilhaMsgEstaVazia ( PilhaMsg * ); // Funcao que verifica se uma pilha esta vazia
int PilhaMsgEstaCheia ( PilhaMsg * ); // Funcao verifica se uma pilha esta cheia
void PilhaMsgPush ( PilhaMsg *, string*, int * ); // Funcao que adiciona uma mensagem ao topo de uma pilha
void PilhaMsgPop ( PilhaMsg * , string, int * ); // Funcao que 'popa' a mensagem do topo de uma pilha
void PilhaMsgReseta ( PilhaMsg * ); // Funcao que 'reseta' uma pilha de mensagens

#endif