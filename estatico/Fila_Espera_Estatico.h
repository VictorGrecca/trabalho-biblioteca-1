// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao estatica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include "Aluno_Estatico.h"
#include "Defines.h"

// A fila de espera estatica se comporta de forma circular

typedef struct {

    int Primeiro;
    int Ultimo;
    int Tam;
    Aluno* Itens[TAMANHO_FILA];

} FilaEspera; // Declaracao da fila de espera, que é uma lista ligada

void FilaEsperaCria ( FilaEspera * ); // Funcao de inicializacao
int FilaEsperaEstaVazia ( FilaEspera * ); // Funcao que avalia se uma fila de espra esta vazia
void FilaEsperaInsere ( FilaEspera *, Aluno *, int * ); // Funcao que insere um aluno em uma fila de espera
void FilaEsperaAnda ( FilaEspera *, Aluno*, int * ); // Funcao que retira o proximo aluno da fila de espra e retorna um ponteiro para o mesmo
void FilaEsperaReseta ( FilaEspera * ); // Funcao que 'reseta' uma fila de espera