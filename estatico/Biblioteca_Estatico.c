// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao estatica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include <stdio.h>
#include <stdlib.h>
// #include <stdio_ext.h> Retire o comentario desta linha caso rode o programa no linux
#include "Biblioteca_Estatico.h"

void InicializaBiblio ( ListaLivro* biblio ) {
	
	ListaLivroCria ( biblio );

}

void LivroCadastra( ListaLivro* biblio ) {

	printf("  -> Cadastramento de um livro novo.\n");
	printf("  -> Atencao: para adicionar uma copia de um livro ja existente, tenha certeza de digitar o seu titulo exatemente como esta cadastrado! Pressione ENTER para continuar.");
	EsperaEnter();

	string TituloAux;
	printf("\tTitulo: ");
	StringLe( TituloAux );
	

	// Caso a lista nao esteja vazia
	if ( !ListaLivroEstaVazia(biblio) ) {
		/* Varre a biblioteca de livros, para checar se o novo livro
		 ja nao esta cadastrado */
		int i;
		for ( i = biblio->Primeiro ; i != -1 ; i = biblio->Vetor[i].Proximo ) {
			if ( !strcmp( biblio->Vetor[i].Valor.Titulo, TituloAux ) ) {
				printf("  -> O livro %s ja esta cadastrado. Uma copia sera adicionada a biblioteca. Pressione ENTER para continuar.", TituloAux );
				EsperaEnter();
				biblio->Vetor[i].Valor.Qnt++;
				return;
			}
		}
	}	

	string AutorAux;
	printf("\tAutor: ");
	StringLe( AutorAux );
	
	string EditoraAux;
	printf("\tEditora: ");
	StringLe( EditoraAux );
	
	string IsbnAux;
	printf("\tISBN: ");
	StringLe( IsbnAux );

	string AnoAux;
	printf("\tAno: ");
	StringLe( AnoAux );
	

	int erro;
	
	// Insere o livro na biblioteca e inicializa sua fila de espera
	ListaLivroInsere(biblio, TituloAux, AutorAux, EditoraAux, IsbnAux, AnoAux, &erro);
	
	if( erro ) {
		printf("\n  -> Falha no cadastramento de livro! A biblioteca esta cheia. Pressione ENTER para continuar.");
		EsperaEnter();
	}
	else {
		printf("\n  -> Cadastramento de livro concluido com sucesso. Pressione ENTER para continuar.");
		EsperaEnter();
	}
}

void LivroRemove( ListaLivro* biblio ) {
	
	printf("  -> Remocao de um livro. Pressione ENTER para continuar.");
	EsperaEnter();

	// Procura o livro a ser removido

	int erroBusca;
	int indice = LivroBusca( biblio, &erroBusca );
	printf("\n");

	if (erroBusca) {	// Caso a busca falhe
		printf("  -> Falha na remocao do livro da biblioteca. Pressione ENTER para continuar.");
		EsperaEnter();
	}
	else {		// Caso o livro seja encontrado
		int erroRemove;

		ListaLivroRemove ( biblio, indice, &erroRemove );
	
		if (erroRemove) {
			printf("  -> Falha na remocao do livro da biblioteca. A biblioteca esta vazia. Pressione ENTER para continuar.");
			EsperaEnter();
		}
		else {
			printf("  -> Livro removido da biblioteca com sucesso. Pressione ENTER para continuar.");
			EsperaEnter();
		}
	}
}

void LivroRetira( ListaLivro* biblio, ListaAluno* alunos ) {
	
	printf("  -> Locacao de Livro. E preciso o titulo do livro a ser locado e, depois, o Numero USP do aluno que o locara. Pressione ENTER para continuar.");
	EsperaEnter();

	// Variavel para guardar se o aluno sera inserido na fila de espera para o livro ou nao
	int addFila = 0;

	// Busca o livro a ser alugado
	
	int erroBusca;

	int indiceLivro = LivroBusca( biblio, &erroBusca );
	if (erroBusca) {
		printf("  -> Falha na locacao de livro. Pressione ENTER para continuar");
		EsperaEnter();
		return;
	}
	
	// Caso nenhuma copia esteja disponivel para locacao
	if ( biblio->Vetor[indiceLivro].Valor.Qnt == 0 ) {

		printf("  -> O livro %s esta cadastrado na biblioteca, porem nao esta disponivel para locacao. Deseja adicionar o aluno a fila de espera de locacao deste livro? (s/n)\n", biblio->Vetor[indiceLivro].Valor.Titulo );
	
		// O usuario escolhe se ira adicionar o aluno na fila de espera ou cancelar a locacao	
		LimpaBuffer();
		char opcao1;
		opcao1 = getchar();
		printf("\n");
	
		if( (opcao1 == 's') || (opcao1 == 'S') )
			addFila = 1;
		else {
			printf("  -> Operacao de locacao cancelada. Pressione ENTER para cotinuar.");
			EsperaEnter();
			return;
		}
	}

	else {		// Caso o livro esteja disponivel para locacao
		printf("\n");
		printf("  -> O livro %s esta cadastrado na biblioteca e %d copias do mesmo estao disponiveis para locacao. Pressione ENTER para continuar.", biblio->Vetor[indiceLivro].Valor.Titulo, biblio->Vetor[indiceLivro].Valor.Qnt );
		EsperaEnter();
	}
	
	// Busca o aluno que o locara
	
	int indiceAluno = AlunoBusca( alunos, &erroBusca );
	if (erroBusca) {
		printf(" -> Falha na locacao de livro. Pressione ENTER para continuar");
		EsperaEnter();
		return;
	}

	// Caso o aluno deva ser inserido na fila de espera
	if (addFila) {

		int erroFila;
		FilaEsperaInsere (&biblio->Vetor[indiceLivro].Valor.Espera, &alunos->Vetor[indiceAluno].Valor, &erroFila);
		if (erroFila) {
			printf("  -> A fila de espera do livro %s esta cheia! O aluno nao sera adicionado a ela. Pressione ENTER para continuar.\n", biblio->Vetor[indiceLivro].Valor.Titulo );
			EsperaEnter();
			return;
		}
		else {

			// Envia uma mensagem para o aluno, informando que esta na fila de espera do livro

			/*
			string mensagem;
			sprintf( mensagem, "Voce agora esta na fila de espera para a locacao do livro %s, na posicao %d. Voce sera notificado quando o livro estiver disponivel para voce o alugar.", biblio->Vetor[indiceLivro].Valor.Titulo, biblio->Vetor[indiceLivro].Valor.Espera.Tam );
			int erroMsg;
			PilhaMsgPush(&alunos->Vetor[indiceAluno].Valor.Mensagens, &mensagem, &erroMsg );
			if (erroMsg) {
				printf("->  A caixa de mensagens deste aluno esta cheia e ele nao sera notificado da operacao.\n");
				printf("->  Comunique ao aluno para que o mesmo venha ler suas mensagens nao lidas o quanto antes!\n");
				printf("->  Pressione ENTER para continuar.");
				EsperaEnter();
			}
			*/

			// Fim da rotina
			printf("  -> O aluno %s agora esta no final da fila de espera para o livro. Pressione ENTER para continuar.", alunos->Vetor[indiceAluno].Valor.Nome );
			EsperaEnter();
		}
	}
	else {		// Caso a locacao ocorra, sem necessidade de utilizar a fila de espera
		printf("  -> O livro %s sera locado por %s. Prosseguir? (s/n): ", biblio->Vetor[indiceLivro].Valor.Titulo, alunos->Vetor[indiceAluno].Valor.Nome );
		LimpaBuffer();
		char opcao2;
		opcao2 = getchar();
		printf("\n");

		//	Caso o usuario decida prosseguir
		if ( (opcao2 == 's') || (opcao2 == 'S') ) {
			
			// Envia uma mensagem para o aluno, informando que alugou o livro em questao
			
			/*
			string mensagem;
			sprintf( mensagem, "Voce alugou o livro %s.", biblio->Vetor[indiceLivro].Valor.Titulo );
			int erroMsg;
			PilhaMsgPush(&alunos->Vetor[indiceAluno].Valor.Mensagens, &mensagem, &erroMsg );
			if (erroMsg) {
				printf("->  A caixa de mensagens deste aluno esta cheia e ele nao sera notificado da operacao.\n");
				printf("->  Comunique ao aluno para que o mesmo venha ler suas mensagens nao lidas o quanto antes!\n");
				printf("->  Pressione ENTER para continuar.");
				EsperaEnter();
			}
			*/

			// Reduz o numero de copias disponiveis do livro e aumenta o de alugadas no momento
			biblio->Vetor[indiceLivro].Valor.Qnt--;
			biblio->Vetor[indiceLivro].Valor.Loc++;
			printf("  -> Livro locado com sucesso. Agora, estao disponiveis %d copias do mesmo para locacao.\n", biblio->Vetor[indiceLivro].Valor.Qnt);
			printf("  -> Pressione ENTER para continuar.");
			EsperaEnter();
		}
		else {		// Caso o usuario decida cancelar a operacao
			printf("  -> Operacao de locacao cancelada. Pressione ENTER para continuar.");
			EsperaEnter();
			return;
		}
	}
}

void LivroRetorna( ListaLivro* biblio, ListaAluno* alunos ) {
	
	printf("  -> Devolucao de livro. E preciso o titulo do livro a ser devolvido e, depois, o Numero USP do aluno que o devolvera. Pressione ENTER para continuar.");
	EsperaEnter();

	// Busca o livro que sera devolvido
	int erroBusca;

	int indiceLivro = LivroBusca( biblio, &erroBusca );
	if (erroBusca) {
		printf("  -> Falha na devolucao de livro. Pressione ENTER para continuar");
		EsperaEnter();
		return;
	}

	// Caso o livro nao esteja locado
	if(biblio->Vetor[indiceLivro].Valor.Loc == 0) {
		printf("  -> O livro %s nao foi alugado! Pressione ENTER para continuar.\n", biblio->Vetor[indiceLivro].Valor.Titulo );
		EsperaEnter();
		return;
	}

	// Busca o aluno que esta devolvendo o livro
	int indiceAluno = AlunoBusca( alunos, &erroBusca );
	if (erroBusca) {
		printf("  -> Falha na devolucao de livro. Pressione ENTER para continuar");
		EsperaEnter();
		return;
	}

	// Escolha do usuario
	printf("  -> O livro %s sera devolvido por %s. Prosseguir? (s/n)\n", biblio->Vetor[indiceLivro].Valor.Titulo, alunos->Vetor[indiceAluno].Valor.Nome );
	LimpaBuffer();
	char opcao = getchar();

	if ( (opcao == 's') || (opcao == 'S') ) {

		// Envia uma mensagem ao aluno informando da devolucao do livro
	
		/*
		string mensagem;
		sprintf( mensagem, "Voce devolveu o livro %s.", biblio->Vetor[indiceLivro].Valor.Titulo );
		int erroMsg;
		PilhaMsgPush(&alunos->Vetor[indiceAluno].Valor.Mensagens, &mensagem, &erroMsg );
		if (erroMsg) {
			printf("->  A caixa de mensagens deste aluno esta cheia e ele nao sera notificado da operacao.\n");
			printf("->  Comunique ao aluno para que o mesmo venha ler suas mensagens nao lidas o quanto antes!\n");
			printf("->  Pressione ENTER para continuar.");
			EsperaEnter();
		}
		*/

		// Aumenta o numero de copias disponiveis do livro e reduz o numero de copias que estao send alugadas
		biblio->Vetor[indiceLivro].Valor.Qnt++;
		biblio->Vetor[indiceLivro].Valor.Loc--;
		
		// Anda a fila de espera do livro devolvido
		int erroFila;
		Aluno* ProximoFila;
		FilaEsperaAnda( &biblio->Vetor[indiceLivro].Valor.Espera, ProximoFila, &erroFila );
		if (!erroFila) {	// Caso andar a fila nao retorne erro, significa que a fila de espera nao esta vazia

			// Envia a mensagem ao proximo aluno da fila de espera, para que o mesmo venha o alugar

			/*
			sprintf( mensagem, "O livro %s agora esta disponivel para voce o locar. Venha o quanto antes.", biblio->Vetor[indiceLivro].Valor.Titulo );
			PilhaMsgPush(&ProximoFila->Mensagens, &mensagem, &erroMsg );
			if (erroMsg) {
				printf("->  A caixa de mensagens deste aluno esta cheia e ele nao sera notificado da operacao.\n");
				printf("->  Comunique ao aluno para que o mesmo venha ler suas mensagens nao lidas o quanto antes!\n");
				printf("->  Pressione ENTER para continuar.");
				EsperaEnter();
			}
			*/

		}
		// Caso a fila de espera esteja vazia, nao é preciso fazer nada.

		printf("  -> Livro devolvido com sucesso. Pressione ENTER para continuar.");
		EsperaEnter();
		return;
	}

	else {		// Caso o usuario cancele a operacao
		printf("  -> Operacao de devolucao cancelada. Pressione ENTER para continuar.");
		EsperaEnter();
		return;
	}

}

// Busca o indice de um livro em uma lista de livros. Retorna -1 caso nao o encontre ou aconteca um erro durante a execucao
int LivroBusca( ListaLivro* biblio, int * erro ) {

	// Caso a biblioteca esteja vazia
	if( ListaLivroEstaVazia( biblio ) ) {
		printf("  -> Operacao invalida. A biblioteca esta vazia!" );
		printf("\n");
		
		*erro = 1;
		return -1;
	}

	// O usuario entra com o titulo do livro que deseja buscar
	printf("  -> Digite o titulo do livro desejado: ");
	string find;
	StringLe( find );

	// Procura o livro e, se o encontrar, retorna o mesmo
	int i;
	for ( i = biblio->Primeiro ; i != -1 ; i = biblio->Vetor[i].Proximo ) {
		if ( strcmp( biblio->Vetor[i].Valor.Titulo, find ) == 0 ) {
			*erro = 0;
			return i;
		}
	}

	*erro = 1;

	// Caso nao retorner apos o laco, significa que o livro nao foi encontrado
	
	/* Pergunta ao usuario se deseja que sejam impressos na tela todos os livros
	 que contem o texto digitado em seu titulo, caso o usuario tenha esquecido como
	 o titulo do livro esta armazenado na biblioteca */
	printf("\n  -> Livro nao encontrado! Tente rever a digitacao.\n->  Atencao: o texto digitado dever ser exatemente igual ao titulo do livro procurado!\n" );
	printf("  -> Exibir livros cujo titulo contem o texto digitado? (s/n): ");
	
	LimpaBuffer();
	char opcao;
	opcao = getchar();
	printf("\n");

	if ( (opcao == 's') || (opcao == 'S') ) {
		
		// Caso o usuario escolha SIM

		printf(" -> Livros que contem '%s' no titulo: \n\n", find );

		for ( i = biblio->Primeiro ; i != -1 ; i = biblio->Vetor[i].Proximo )
			if ( strstr( biblio->Vetor[i].Valor.Titulo, find ) )
				PrintaLivro( &biblio->Vetor[i].Valor );

		printf("  -> Pressione ENTER para continuar.");
		EsperaEnter();
	}

	printf("\n");
	return -1;
}

void InicializaAlunos ( ListaAluno * alunos ) {
	
	ListaAlunoCria ( alunos );

}

void AlunoCadastra( ListaAluno* alunos ) {

	printf("  -> Cadastramento de um aluno novo. Pressione ENTER para continuar.");
	EsperaEnter();

	string NomeAux;
	printf("\tNome: ");
	StringLe( NomeAux );

	string NuspAux;
	printf("\tNumero USP: ");
	StringLe( NuspAux );

	// Caso a lista nao esteja vazia
	if ( !ListaAlunoEstaVazia(alunos) ) {
		/* Varre a lista de alunos, para checar se o novo aluno
		 ja nao esta cadastrado */
		int i;
		for ( i = alunos->Primeiro ; i != -1 ; i = alunos->Vetor[i].Proximo ) {
			if ( !strcmp( alunos->Vetor[i].Valor.Nusp, NuspAux ) ) {
				printf("\n  -> Operacao invalida. O aluno %s ja esta cadastrado. Pressione ENTER para continuar.", NomeAux );
				EsperaEnter();
				return;
			}
		}
	}
	
	string TelAux;
	printf("\tTelefone: ");
	StringLe( TelAux );
	
	string EmailAux;
	printf("\tEmail: ");
	StringLe( EmailAux );

	int erro;
	
	// Insere o aluno na alunosteca e inicializa sua fila de espera
	ListaAlunoInsere(alunos, NomeAux, NuspAux, TelAux, EmailAux, &erro);
	
	if( erro ) {
		printf("\n  -> Falha no cadastramento de aluno! O sistema esta cheio. Pressione ENTER para continuar.");
		EsperaEnter();
	}
	else {
		printf("\n  -> Cadastramento de aluno concluido com sucesso. Pressione ENTER para continuar.");
		EsperaEnter();
	}

	// Envia a mensagem de boas vindas ao aluno

	/*
	string mensagem;
	int erroMsg;
	sprintf( mensagem, "Bem vindo ao sistema de biblioteca, %s!", NomeAux );
	PilhaMsgPush(&alunos->Vetor[alunos->Ultimo].Valor.Mensagens, &mensagem, &erroMsg );
	if (erroMsg) {
		printf("->  A caixa de mensagens deste aluno esta cheia e ele nao sera notificado da operacao.\n");
		printf("->  Comunique ao aluno para que o mesmo venha ler suas mensagens nao lidas o quanto antes!\n");
		printf("->  Pressione ENTER para continuar.");
		EsperaEnter();
	}
	*/

}

void AlunoRemove( ListaAluno* alunos ) {
	
	printf("  -> Descadastramento de um aluno. Pressione ENTER para continuar.");
	EsperaEnter();

	// Procura o aluno a ser removido

	int erroBusca;
	int indice = AlunoBusca( alunos, &erroBusca );
	printf("\n");

	if (erroBusca) {	// Caso a busca falhe
		printf(" -> Falha no descadastramento do aluno. Pressione ENTER para continuar.");
		EsperaEnter();
	}
	else {		// Caso o aluno seja encontrado
		int erroRemove;

		ListaAlunoRemove ( alunos, indice, &erroRemove );
	
		if (erroRemove) {
			printf("  -> Falha no descadastramento. Nao ha alunos cadastrados. Pressione ENTER para continuar.");
			EsperaEnter();
		}
		else {
			printf("  -> Aluno descadastrado com sucesso. Pressione ENTER para continuar.");
			EsperaEnter();
		}
	}
}

// Busca o indice de um aluno em uma lista de alunos. Retorna -1 caso nao o encontre ou aconteca um erro durante a execucao
int AlunoBusca( ListaAluno* alunos, int * erro ) {

	// Caso a biblioteca esteja vazia
	if( ListaAlunoEstaVazia( alunos ) ) {
		printf("  -> Operacao invalida. Nenhum aluno esta cadastrado!" );
		printf("\n");
		
		*erro = 1;
		return -1;
	}

	// O usuario entra com o numero  usp do aluno que deseja buscar
	printf("  -> Digite o Numero USP do aluno desejado: ");
	string find;
	StringLe( find );

	// Procura o aluno e, se o encontrar, retorna o mesmo
	int i;
	for ( i = alunos->Primeiro ; i != -1 ; i = alunos->Vetor[i].Proximo ) {
		if ( strcmp( alunos->Vetor[i].Valor.Nusp, find ) == 0 ) {
			*erro = 0;
			return i;
		}
	}

	*erro = 1;

	// Caso nao retornar apos o laco, significa que o aluno nao foi encontrado
	
	/* Pergunta ao usuario se deseja que sejam impressos na tela todos os alunos
	 e seus numeros usp, caso o usuario tenha esquecido o numero usp do aluno que
	 deseja encontrar */
	printf("\n  -> Aluno nao encontrado!\n");
	printf("  -> Exibir todos os alunos e seus respectivos Numeros USP? (s/n): ");
	
	LimpaBuffer();
	char opcao;
	opcao = getchar();
	printf("\n");

	if ( (opcao == 's') || (opcao == 'S') ) {
		
		// Caso o usuario escolha SIM

		printf("  -> Todos os alunos e seus respectivos Numeros USP: \n\n");

		for ( i = alunos->Primeiro ; i != -1 ; i = alunos->Vetor[i].Proximo )
			PrintaNUSPAluno( &alunos->Vetor[i].Valor );

		printf("  -> Pressione ENTER para continuar.");
		EsperaEnter();
	}

	printf("\n");
	return -1;
}

void MensagensNaoLidas( ListaAluno * alunos ) {

	// Busca um aluno
	int erro;

	int indice = AlunoBusca( alunos, &erro );
	if (!erro) // Caso encontre, imprime suas mensagens nao lidas
		PrintaMensagens ( &alunos->Vetor[indice].Valor );

	printf("\n");
}

void EsperaEnter() {

	// Funcao simples para esperar o usuario apertar 'ENTER'
	LimpaBuffer();
	getchar();
	printf("\n");
}