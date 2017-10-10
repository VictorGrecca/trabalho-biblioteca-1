// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (arquivo main)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>

//#include "Biblioteca_Dinamico.h"

#include "Biblioteca_Estatico.h"

int main() {

	//####################################################
    // Declaracao Dinamica: comente para a versao Estatica

	/*
	ListaLivro* Biblioteca;
	Biblioteca = malloc( sizeof(ListaLivro*) );
	if (Biblioteca == NULL) {
		printf("->  ERRO: o sistema encontrou um problema! (Falha em alocação de memoria).\n");
		abort();
	}
	InicializaBiblio( Biblioteca );

	ListaAluno* Alunos;
	Alunos = malloc( sizeof(ListaAluno*) );
	if (Alunos == NULL) {
		printf("->  ERRO: o sistema encontrou um problema! (Falha em alocação de memoria).\n");
		abort();
	}
	InicializaAlunos( Alunos );
	*/

	//####################################################
	// Declaracao Estatica, comente para a versao Dinamica:

	#include "Defines.h"
	
	ListaLivro Biblioteca[TAMANHO_LIVROS];
	InicializaBiblio( Biblioteca );

	ListaAluno Alunos[TAMANHO_ALUNOS];
	InicializaAlunos( Alunos );



	//####################################################
	// Inicio do codigo:

	printf("\n");
	printf("Sistema de Biblioteca. Menu de operacoes:\n");
	printf("\n");
	printf("\t1 - Cadastrar aluno\n");
	printf("\t2 - Cadastrar livro\n");
	printf("\t3 - Retirar livro\n");
	printf("\t4 - Retornar livro\n");
	printf("\t5 - Remover livro\n");
	printf("\t6 - Remover aluno\n");
	printf("\t7 - Imprimir mensagens nao lidas de um aluno\n");
	printf("\t8 - Mostrar o menu de operacoes novamente\n");
	printf("\t0 - Sair\n");
	printf("\n");

	char menu;
	
	// Loop principal do programa:
	while(1) {

		printf("Qual operacao deseja realizar? Use 8 para mostrar o menu de operacoes novamente.\n");
		menu = getchar();
		LimpaBuffer();
		printf("\n");

		switch(menu) {

			case '0':
				printf("Deseja mesmo sair do sistema de biblioteca? (s/n)\n");

				/* Entrada de opcao. Apesar da mensagem, qualquer valor diferente
				de s, maiusculo ou minusculo, sera considerado como um nao */
				LimpaBuffer();	
				char opcao;
				opcao = getchar();
				printf("\n");

				if ( (opcao == 's') || (opcao == 'S') ) {
					
					// Limpa todo o codigo (as funcoes chamam subrotinas de limpeza)
					ListaLivroFinaliza( Biblioteca );
					ListaAlunoFinaliza( Alunos );
					
					printf("Adeus!\n");
					return 0;
				}
				else {
					LimpaBuffer();
					break;
				}

			case '1':
				AlunoCadastra( Alunos );
				break;

			case '2':
				LivroCadastra( Biblioteca );
				break;

			case '3':
				LivroRetira( Biblioteca , Alunos );
				break;

			case '4':
				LivroRetorna( Biblioteca, Alunos );
				break;

			case '5':
				LivroRemove( Biblioteca );
				break;

			case '6':
				AlunoRemove( Alunos );
				break;

			case '7':
				MensagensNaoLidas( Alunos );
				break;

			case '8':
				printf("Sistema de Biblioteca. Menu de operacoes:\n");
				printf("\n");
				printf("\t1 - Cadastrar aluno\n");
				printf("\t2 - Cadastrar livro\n");
				printf("\t3 - Retirar livro\n");
				printf("\t4 - Retornar livro\n");
				printf("\t5 - Remover livro\n");
				printf("\t6 - Remover aluno\n");
				printf("\t7 - Imprimir mensagens nao lidas de um aluno\n");
				printf("\t8 - Mostrar o menu de operacoes novamente\n");
				printf("\t0 - Sair\n");
				printf("\n");
				break;
		}
	}

	return 0;
}