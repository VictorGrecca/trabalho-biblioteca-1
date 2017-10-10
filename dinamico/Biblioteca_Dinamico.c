// Trabalho de Algoritmos e Estruturas de Dados - Biblioteca (Versao dinamica)
// Pedro Pastorello Fernandes - N USP: 10262502
// Victor Hugo de Lima Grecca - N USP: 10392185

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "Biblioteca_Dinamico.h"

void InicializaBiblio ( ListaLivro* biblio ) {
	
	ListaLivroCria ( biblio );

}

void LivroCadastra( ListaLivro* biblio ) {

	// Alocacao de um livro temporario, para a funcao
	Livro * temp = malloc( sizeof(Livro) );
	if (temp == NULL) {
		printf("->  ERRO: o sistema encontrou um problema! (Falha em alocação de memoria).\n");
		abort();
	}

	printf("->  Cadastramento de um livro novo.\n");
	printf("->  Atencao: para adicionar uma copia de um livro ja existente, tenha certeza de digitar o seu titulo exatemente como esta cadastrado! Pressione ENTER para continuar.");
	EsperaEnter();

	printf("\tTitulo: ");
	temp->Titulo = StringLe();
	

	// Caso a lista nao esteja vazia
	if ( !ListaLivroEstaVazia(biblio) ) {
		/* Varre a biblioteca de livros, para checar se o novo livro
		 ja nao esta cadastrado */
		nodeLivro* p;
		for ( p = biblio->Primeiro ; p != NULL ; p = p->Proximo ) {
			if ( !strcmp(p->Valor.Titulo, temp->Titulo) ) {
				printf("->  O livro %s ja esta cadastrado. Uma copia sera adicionada a biblioteca. Pressione ENTER para continuar.", temp->Titulo );
				EsperaEnter();
				p->Valor.Qnt++;
				return;
			}
		}
	}	

	printf("\tAutor: ");
	temp->Autor = StringLe();
	
	printf("\tEditora: ");
	temp->Editora = StringLe();
	
	printf("\tISBN: ");
	temp->Isbn = StringLe();

	printf("\tAno: ");
	temp->Ano = StringLe();
	
	// Obviamente, o livro é inicializado com 1 copia, sendo 0 delas alugadas no momento
	temp->Qnt = 1;
	temp->Loc = 0;
	printf("\n");

	// Insere o livro na biblioteca e inicializa sua fila de espera
	ListaLivroInsere(biblio, temp);
	FilaEsperaCria( &biblio->Ultimo->Valor.Espera );
	
	printf("->  Cadastramento de livro concluido com sucesso. Pressione ENTER para continuar.");
	EsperaEnter();

}

void LivroRemove( ListaLivro* biblio ) {
	
	printf("->  Remocao de um livro. Pressione ENTER para continuar.");
	EsperaEnter();

	// Procura o livro a ser removido
	Livro* this = LivroBusca( biblio );
	printf("\n");

	if (this == NULL) {		// Caso a busca falhe
		printf("->  Falha na remocao do livro da biblioteca. Pressione ENTER para continuar.");
		EsperaEnter();
	}
	else {		// Caso o livro seja encontrado
		ListaLivroRemove ( biblio , this );
		printf("->  Livro removido da biblioteca com sucesso. Pressione ENTER para continuar.");
		EsperaEnter();
	}
}

void LivroRetira( ListaLivro* biblio, ListaAluno* alunos ) {
	
	printf("->  Locacao de Livro. E preciso o titulo do livro a ser locado e o Numero USP do aluno que o locara. Pressione ENTER para continuar.");
	EsperaEnter();

	// Variavel para guardar se o aluno sera inserido na fila de espera para o livro ou nao
	int addFila = 0;

	// Busca o livro a ser alugado
	Livro* thisL = LivroBusca( biblio );
	if (thisL == NULL) {
		printf("->  Falha na locacao de livro. Pressione ENTER para continuar");
		EsperaEnter();
		return;
	}
	
	// Caso nenhuma copia esteja disponivel para locacao
	if (thisL->Qnt == 0 ) {

		printf("->  O livro %s esta cadastrado na biblioteca, porem nao esta disponivel para locacao. Deseja adicionar o aluno a fila de espera de locacao deste livro? (s/n)\n", thisL->Titulo );
	
		// O usuario escolhe se ira adicionar o aluno na fila de espera ou cancelar a locacao	
		LimpaBuffer();
		char opcao1;
		opcao1 = getchar();
		printf("\n");
	
		if( (opcao1 == 's') || (opcao1 == 'S') )
			addFila = 1;
		else {
			printf("->  Operacao de locacao cancelada. Pressione ENTER para cotinuar.");
			EsperaEnter();
			return;
		}
	}

	else {		// Caso o livro esteja disponivel para locacao
		printf("\n");
		printf("->  O livro %s esta cadastrado na biblioteca e %d copias do mesmo estao disponiveis para locacao. Pressione ENTER para continuar.", thisL->Titulo, thisL->Qnt);
		EsperaEnter();
	}
	
	// Busca o aluno que o locara
	Aluno* thisA = AlunoBusca( alunos );
	if (thisA == NULL) {
		printf("->  Falha na locacao de livro. Pressione ENTER para continuar.");
		EsperaEnter();
		return;
	}

	// Caso o aluno deva ser inserido na fila de espera
	if (addFila) {
		FilaEsperaInsere (&thisL->Espera, thisA);

		/* Uma mensagem é alocada, com o tamanho exato (com uma pequena margem) necessario
		  (tamanho da mensagem = mensagem + titulo do livro) */
		string mensagem = malloc( ( strlen(thisL->Titulo) + 151 + sizeof(int) ) * sizeof(char) );
		if (mensagem == NULL) { // Caso a alocacao falhe
			printf("->  ERRO: o sistema encontrou um problema! (Falha em alocação de memoria).\n");
			abort();
		}

		// Envia a mensagem para o aluno, informando que esta na fila de espera do livro
		sprintf( mensagem, "Voce agora esta na fila de espera para a locacao do livro %s, na posicao %d. Voce sera notificado quando o livro estiver disponivel para voce o alugar.", thisL->Titulo, FilaEsperaTamanho(&thisL->Espera) );
		PilhaMsgPush(&thisA->Mensagens, mensagem );
		
		// Fim da rotina
		printf("->  O aluno %s agora esta no final da fila de espera para o livro %s. Pressione ENTER para continuar.", thisA->Nome, thisL->Titulo );
		EsperaEnter();
	}
	else {		// Caso a locacao ocorra, sem necessidade de utilizar a fila de espera
		printf("->  O livro %s sera locado por %s. Prosseguir? (s/n): ", thisL->Titulo, thisA->Nome );
		LimpaBuffer();
		char opcao2;
		opcao2 = getchar();
		printf("\n");

		//	Caso o usuario decida prosseguir
		if ( (opcao2 == 's') || (opcao2 == 'S') ) {
			
			/* Uma mensagem é alocada, com o tamanho exato (com uma pequena margem) necessario
		     (tamanho da mensagem = mensagem + titulo do livro) */
			string mensagem = malloc( ( strlen(thisL->Titulo) + 23 ) * sizeof(char) );
			if (mensagem == NULL) {
				printf("->  ERRO: o sistema encontrou um problema! (Falha em alocação de memoria).\n");
				abort();
			}

			// Envia a mensagem para o aluno, informando que alugou o livro
			sprintf( mensagem, "Voce alugou o livro %s.", thisL->Titulo );
			PilhaMsgPush( &thisA->Mensagens, mensagem );

			// Reduz o numero de copias disponiveis do livro e aumenta o de alugadas no momento
			thisL->Qnt--;
			thisL->Loc++;
			printf("->  Livro locado com sucesso. Agora, estao disponiveis %d copias do mesmo para locacao.\n", thisL->Qnt);
			printf("->  Pressione ENTER para continuar.");
			EsperaEnter();
		}
		else {		// Caso o usuario decida cancelar a operacao
			printf("->  Operacao de locacao cancelada. Pressione ENTER para continuar.");
			EsperaEnter();
			return;
		}
	}
}

void LivroRetorna( ListaLivro* biblio, ListaAluno* alunos ) {
	
	printf("->  Devolucao de livro. E preciso o titulo do livro a ser devolvido e o Numero USP do aluno que o devolvera. Pressione ENTER para continuar.");
	EsperaEnter();

	// Busca o livro que sera devolvido
	Livro* thisL = LivroBusca( biblio );
	if (thisL == NULL) {
		printf("->  Falha na devolucao de livro. Pressione ENTER para continuar.");
		EsperaEnter();
		return;
	}

	// Caso o livro nao esteja locado
	if(thisL->Loc == 0) {
		printf("->  O livro %s nao foi alugado! Pressione ENTER para continuar.\n", thisL->Titulo );
		EsperaEnter();
		return;
	}

	// Busca o aluno que esta devolvendo o livro
	Aluno* thisA = AlunoBusca( alunos );
	if (thisA == NULL) {
		printf("->  Falha na devolucao de livro. Pressione ENTER para continuar.");
		EsperaEnter();
		return;
	}

	// Escolha do usuario
	printf("->  O livro %s sera devolvido por %s. Prosseguir? (s/n)\n", thisL->Titulo, thisA->Nome );
	LimpaBuffer();
	char opcao = getchar();

	if ( (opcao == 's') || (opcao == 'S') ) {
		
		/* Uma mensagem é alocada, com o tamanho exato (com uma pequena margem) necessario
		 (tamanho da mensagem = mensagem + titulo do livro) */
		string mensagem = malloc( ( sizeof(thisL->Titulo) + 25 ) * sizeof(char) );
		if (mensagem == NULL) {
			printf("->  ERRO: o sistema encontrou um problema! (Falha em alocação de memoria).\n");
			abort();
		}

		// Envia a mensagem ao aluno
		sprintf( mensagem, "Voce devolveu o livro %s.", thisL->Titulo );
		PilhaMsgPush(&thisA->Mensagens, mensagem );

		// Aumenta o numero de copias disponiveis do livro e reduz o numero de copias que estao send alugadas
		thisL->Qnt++;
		thisL->Loc--;
		
		// Anda a fila de espera do livro devolvido
		Aluno* ProximoFila = FilaEsperaAnda( &thisL->Espera );
		if (ProximoFila != NULL) {

			/* Uma mensagem é alocada, com o tamanho exato (com uma pequena margem) necessario
			 (tamanho da mensagem = mensagem + titulo do livro) */
			mensagem = realloc( mensagem, ( sizeof(thisL->Titulo) + 73 ) * sizeof(char) );
			if (mensagem == NULL) {
				printf("->  ERRO: o sistema encontrou um problema! (Falha em alocação de memoria).\n");
				abort();
			}

			// Envia a mensagem ao aluno
			sprintf( mensagem, "O livro %s agora esta disponivel para voce o locar. Venha o quanto antes.", thisL->Titulo );
			PilhaMsgPush(&ProximoFila->Mensagens, mensagem );
		}

		printf("->  Livro devolvido com sucesso. Pressione ENTER para continuar.");
		EsperaEnter();
		return;
	}

	else {		// Caso o usuario cancele a operacao
		printf("->  Operacao de devolucao cancelada. Pressione ENTER para continuar.");
		EsperaEnter();
		return;
	}

}

// Busca um livro em uma lista de livros. Retorna NULL caso nao o encontre ou aconteca um erro durante a execucao
Livro* LivroBusca( ListaLivro* biblio ) {

	// Caso a biblioteca esteja vazia
	if( ListaLivroEstaVazia( biblio ) ) {
		printf("->  Operacao invalida. A biblioteca esta vazia!" );
		printf("\n");
		
		return NULL;
	}

	// O usuario entra com o titulo do livro que deseja buscar
	printf("->  Digite o titulo do livro desejado: ");
	string find = StringLe();

	nodeLivro* p;

	// Procura o livro e, se o encontrar, retorna o mesmo
	for ( p = biblio->Primeiro ; p != NULL ; p = p->Proximo ) {
		if ( strcmp(p->Valor.Titulo, find) == 0 )
			return &p->Valor;
	}

	// Caso nao retornar apos o laco, significa que o livro nao foi encontrado
	
	/* Pergunta ao usuario se deseja que sejam impressos na tela todos os livros
	 que contem o texto digitado em seu titulo, caso o usuario tenha esquecido como
	 o titulo do livro esta armazenado na biblioteca */
	printf("\n->  Livro nao encontrado! Tente rever a digitacao.\n->  Atencao: o texto digitado dever ser exatemente igual ao titulo do livro procurado!\n" );
	printf("->  Exibir livros cujo titulo contem o texto digitado? (s/n): ");
	
	LimpaBuffer();
	char opcao;
	opcao = getchar();
	printf("\n");

	if ( (opcao == 's') || (opcao == 'S') ) {
		
		// Caso o usuario escolha SIM

		printf("->  Livros que contem '%s' no titulo: \n\n", find );

		for ( p = biblio->Primeiro ; p != NULL ; p = p->Proximo ) {
			
			if ( strstr(p->Valor.Titulo, find) )
				PrintaLivro(p->Valor);

			printf("Pressione ENTER para continuar.");
			EsperaEnter();
		}
	}

	return NULL;
}

void InicializaAlunos ( ListaAluno * alunos ) {
	
	ListaAlunoCria ( alunos );

}

void AlunoCadastra( ListaAluno* alunos ) {

	// Aloca um ponteiro para aluno temporario
	Aluno * temp = malloc( sizeof(Aluno) );
	if (temp == NULL) {
		printf("->  ERRO: o sistema encontrou um problema! (Falha em alocação de memoria).\n");
		abort();
	}

	printf("->  Cadastramento de um aluno novo. Pressione ENTER para continuar.");
	EsperaEnter();

	// Le os dados no novo aluno

	printf("\tNome: ");
	temp->Nome = StringLe();

	printf("\tNumero USP: ");
	temp->Nusp = StringLe();
	
	/* Procura o numero usp digitado na lista de alunos e, se encontrar
	 cancela a operacao pois 2 alunos nao podem ter o mesmo numero usp */
	nodeAluno* p;
	if ( !ListaAlunoEstaVazia(alunos) ) {
		for ( p = alunos->Primeiro ; p != NULL ; p = p->Proximo ) {
			if ( !strcmp(p->Valor.Nusp, temp->Nusp) ) {
				printf("\n->  Operacao invalida. Este aluno ja esta cadastrado! Pressione ENTER para continuar.");
				EsperaEnter();
				return;
			}
		}
	}	
	
	printf("\tTelefone: ");
	temp->Tel = StringLe();
	
	printf("\tEmail: ");
	temp->Email = StringLe();

	printf("\n");

	// Insere o aluno na lista de alunos e inicializa sua pilha de mensanges
	ListaAlunoInsere(alunos, temp);
	PilhaMsgCria(&alunos->Ultimo->Valor.Mensagens);

	/* Uma mensagem é alocada, com o tamanho exato (com uma pequena margem) necessario
	 (tamanho da mensagem = mensagem + nome do aluno) */
	string mensagem = malloc( (strlen(temp->Nome) + 40 ) * sizeof(char) );
	if (mensagem == NULL) {
		printf("->  ERRO: o sistema encontrou um problema! (Falha em alocação de memoria).\n");
		abort();
	}

	// Envia a mensagem ao aluno
	sprintf( mensagem, "Bem vindo ao sistema de biblioteca, %s!", temp->Nome );
	PilhaMsgPush(&alunos->Ultimo->Valor.Mensagens, mensagem );

	printf("->  Cadastramento de aluno concluido com sucesso. Pressione ENTER para continuar.");
	EsperaEnter();

}

void AlunoRemove( ListaAluno* alunos ) {
	
	printf("->  Descadastramento de um aluno. Pressione ENTER para continuar.");
	EsperaEnter();

	// Busca o aluno a ser removido
	Aluno* this = AlunoBusca( alunos );
	printf("\n");

	// Caso nao seja encontrado
	if (this == NULL) {
		printf("->  Falha no descadastramento de aluno. Pressione ENTER para continuar.");
		EsperaEnter();
	}
	else {		// Caso seja encontrado
		// Remove o aluno
		ListaAlunoRemove ( alunos , this );

		printf("->  Aluno descadastrado com sucesso. Pressione ENTER para continuar.");
		EsperaEnter();
	}
}

Aluno* AlunoBusca( ListaAluno* alunos ) {

	// Caso a lista de alunos esteja vazia
	if( ListaAlunoEstaVazia( alunos ) ) {
		printf("->  Operacao invalida. Nenhum aluno esta cadastrado!" );
		return NULL;
	}

	// Le um numero usp, para procurar o aluno desejado
	printf("->  Numero USP do aluno desejado: ");
	string find = StringLe();

	nodeAluno* p;

	// Varre a lista de alunos e retorna o desejado
	for ( p = alunos->Primeiro ; p != NULL ; p = p->Proximo ) {
		if ( strcmp(p->Valor.Nusp, find) == 0 )
			return &p->Valor;
	}

	// Caso a funcao nao retorne, significa que o aluno nao foi encontrado

	/* Pergunta ao usuario se ele deseja imprimir todos os alunos
	 e seus respectivos numeros usp, para o mesmo verificar caso tenha
	 esquecido, ja que nao encontrou o aluno que buscava */
	printf("\n->  Aluno nao encontrado!\n" );
	printf("->  Exibir o Numero USP de cada aluno? (s/n): ");
	
	LimpaBuffer();
	char opcao;
	opcao = getchar();
	printf("\n");

	if ( (opcao == 's') || (opcao == 'S') ) {
		
		printf("->  Cada aluno e seu respectivo Numero USP: \n\n");

		for ( p = alunos->Primeiro ; p != NULL ; p = p->Proximo )
				PrintaNUSPAluno(&p->Valor);

		printf("->  Pressione ENTER para continuar.");
		EsperaEnter();
	}

	return NULL;
}

void MensagensNaoLidas( ListaAluno * alunos ) {

	// Busca um aluno
	Aluno* this = AlunoBusca( alunos );
	if (this != NULL) // Caso encontre, imprime suas mensagens nao lidas
		PrintaMensagens ( this );

	printf("\n");
}

void EsperaEnter() {

	// Funcao simples para esperar o usuario apertar 'ENTER'
	LimpaBuffer();
	getchar();
	printf("\n");
}