#include <stdio.h>

int main()
{
	/*
	Inicia as variaveis, que tem nome autoexplicativos e significativos,
	isso está de acordo com o Capitulo 2 do Livro Codigo Limpo

	O código está inteiro formatado da mesma maneira,
	e sem linhas excessivamente grandes.
	Assim como manda o Capitulo 5 do Livro Codigo Limpo.
	*/
	int quantSessoes, quantPessSessao, idade, opcao, valorArrecadadoSessao1 = 0;
	int valorArrecadadoSessao2 = 0, quantInteiras = 0, quantMeias = 0;
	int quantMulheres, quantHomens, quantMulheresMaioresDeIdade = 0;
	int quantHomensMaioresDeIdade = 0;
	int quantCriancas, quantAdolescentes, quantAdultos, quantIdosos;
	int quantPagamentosInteira = 0, quantPagamentosMeia = 0, quantMaioresIdade = 0;
	char sexo, nomeFilme1[50], nomeFilme2[50];

	// Mostra na tela a informacao das pessoas do grupo.
	printf("+--------------------------------------------+\n");
	printf("| Nome Completo: Gabriel Gomes Carvalho      |\n");
	printf("| Matricula: UC22103194                      |\n");
	printf("| Curso: Ciencia da Computacao               |\n");
	printf("|                                            |\n");
	printf("| Nome Completo: Lucas Sabino Alves          |\n");
	printf("| Matricula: UC22103214                      |\n");
	printf("| Curso: Ciencia da Computacao               |\n");
	printf("+--------------------------------------------+\n");
	printf("\n");

	// Pede ao usuario que digite o numero de sessoes,
	// So aceita o valor 2
	do
	{
		printf("Digite o numero de sessoes: ");
		scanf("%d", &quantSessoes);
		fflush(stdin);
		if (quantSessoes != 2)
		{
			printf("Entrada invalida.\n\n");
		}
	} while (quantSessoes != 2);

	/*O usuario repetira o processo do preenchimento dos dados,
	  fara isso uma vez por sessao*/
	int n;
	for (n = 0; n < quantSessoes; n++)
	{
		/*Cada vez que e iniciado o processo de solicitacao e validacao dos dados,
		  os valores abaixo sao redefinidos.*/
		quantCriancas = 0, quantAdolescentes = 0, quantAdultos = 0, quantIdosos = 0;
		quantMulheres = 0;
		quantHomens = 0;
		// mostra em que sessao se esta
		printf("%d Sessao\n", n + 1);
		// Pede o nome do filme
		printf("Digite o nome do filme: ");
		fflush(stdin);
		scanf("%[^\n]s", nomeFilme1);
		// Pede a quantidade de pessoas na sessao, so aceita valores maiores que 10
		do
		{
			printf("Digite a quantidade de pessoas presentes nesta sessao: ");
			fflush(stdin);
			scanf("%d", &quantPessSessao);
			fflush(stdin);
			if (quantPessSessao < 10)
				printf("Entrada invalida.\n\n");
		} while (quantPessSessao < 10);

		// Pede o preenchimento dos dados de cada pessoa na sessao
		int i;
		for (i = 0; i < quantPessSessao; i++)
		{
			// Valida o sexo da pessoa, so aceita M e F.
			do
			{
				printf("Digite o sexo da %d pessoa: ", i + 1);
				fflush(stdin);
				scanf("%c", &sexo);
				if (sexo != 'M' && sexo != 'F')
					printf("Sexo invalido.\n\n");
			} while (sexo != 'M' && sexo != 'F');
			// Valida a idade da pessoa, so aceita idades entre 3 e 100
			do
			{
				printf("Digite a idade da %d pessoa: ", i + 1);
				fflush(stdin);
				scanf("%d", &idade);
				fflush(stdin);
				if (idade < 3 || idade > 100)
					printf("Idade invalida.\n\n");
				/*Conta quantos homens e quantas mulheres estao na sessao.
				  Conta quantos homens e mulheres maiores de idade
				  estao presentes ao total nas sessoes.*/
				else
				{
					if (sexo == 'M')
					{
						quantHomens++;
						if (idade >= 18)
						{
							quantHomensMaioresDeIdade++;
						}
					}
					if (sexo == 'F')
					{
						quantMulheres++;
						if (idade >= 18)
						{
							quantMulheresMaioresDeIdade++;
						}
					}
					// Conta as pessoas por faixa etaria.
					if (idade >= 3 && idade <= 13)
					{
						quantCriancas++;
					}
					else if (idade >= 14 && idade <= 17)
					{
						quantAdolescentes++;
					}
					else if (idade >= 18 && idade <= 64)
					{
						quantAdultos++;
					}
					else if (idade >= 65 && idade <= 100)
					{
						quantIdosos++;
					}
				}
			} while (idade < 3 || idade > 100);
			do
			{
				// Pede ao ususario que selecione o tipo de entrada da pessoa
				printf("\n");
				printf("Digite a entrada selecionada:\n");
				printf("[1] - Inteira, R$ 50,00\n");
				printf("[2] - Meia Entrada, RS 25,00\n");
				printf("Opcao: ");
				fflush(stdin);
				scanf("%d", &opcao);

				/*Controla quanto foi arrecadado em cada sessao.
				Controla quantas entradas de cada tipo foram compradas*/
				switch (opcao)
				{
				case 1:
					if (n == 0)
						valorArrecadadoSessao1 += 50;
					if (n == 1)
						valorArrecadadoSessao2 += 50;
					quantInteiras++;
					printf("\n");
					break;
				case 2:
					if (n == 0)
						valorArrecadadoSessao1 += 25;
					if (n == 1)
						valorArrecadadoSessao2 += 25;
					quantMeias++;
					printf("\n");
					break;
				default:
					printf("Opcao invalida.\n");
					break;
				}
			} while (opcao != 1 && opcao != 2);
		}
		// Mostra o resumo das informacoes recolhidas.
		printf("\n");
		printf("|  Nome do filme: %s\n", nomeFilme1);
		printf("|  Quantidade de pessoas do sexo feminino: %d\n", quantMulheres);
		printf("|  Quantidade de pessoas do sexo masculino: %d\n", quantHomens);
		printf("|  Quantidade de:\n");
		printf("|  \tCriancas: %d\n", quantCriancas);
		printf("|  \tAdolecentes: %d\n", quantAdolescentes);
		printf("|  \tAdultos: %d\n", quantAdultos);
		printf("|  \tIdosos: %d\n", quantIdosos);
		printf("\n");
	}
	/*Resumo das informacoes recolhidas que so sao mostradas
	ao quando o usuario ja preencheu todos os dados*/
	printf("\n");
	printf("|  Quantidade de pessoas maiores de idade:\n");
	printf("|  Do sexo masculino: %d\n", quantHomensMaioresDeIdade);
	printf("|  Do sexo feminino: %d\n", quantMulheresMaioresDeIdade);
	printf("|\n");
	printf("|  Valor arrecadado:\n");
	printf("|  Sessao 1: %d\n", valorArrecadadoSessao1);
	printf("|  Sessao 2: %d\n", valorArrecadadoSessao2);
	/*Faz a comparacao entre a quantidade de entradas e diz se houveram
	  mais inteiras, meias ou se suas quantidades sao iguais*/
	if (quantMeias > quantInteiras)
	{
		printf("|  Houveram mais meias entradas ao total.\n");
	}
	else if (quantMeias < quantInteiras)
	{
		printf("|  Houveram mais entradas inteiras ao total.\n");
	}
	else
	{
		printf("|  Houveram tantas meias entradas quanto inteiras.\n");
	}
	printf("| Quantidade de entradas inteiras: %d\n", quantInteiras);
	printf("| Quantidade de meias entradas: %d\n", quantMeias);
}
