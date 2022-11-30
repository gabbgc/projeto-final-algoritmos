#include <stdio.h>

int main()
{
	int sess, quantidade, idade, opcao, i, valor;
    int case1=25,case2=50;
	char sexo;
    
	do
	{
		printf("\n");
		printf("Digite o numero de sessoes: ");
		scanf("%d", &sess);
		fflush(stdin);
	if (sess != 2)
		{
			printf("Entrada invalida.\n");
		}
	} while (sess != 2);

	do
	{
		printf("\n");
		printf("Digite a quantidade de pessoas presentes nesta sessao: ");
		fflush(stdin);
		scanf("%d", &quantidade);
		fflush(stdin);
	
	} while (quantidade > 10);

	for (int i = 0; i < quantidade; i++)
	{
		do
		{
			printf("\n");
			printf("Digite o sexo da %d pessoa: ", i + 1);
			fflush(stdin);
			scanf("%c", &sexo);
			if (sexo != 'M' && sexo != 'F')
				printf("Sexo invalido.\n");
		} while (sexo != 'M' && sexo != 'F');
		do
		{
			printf("\n");
			printf("Digite a idade da %d pessoa: ", i + 1);
			fflush(stdin);
			scanf("%d", &idade);
			fflush(stdin);
			if (idade < 3 || idade > 100)
				printf("Idade invalida.\n");
		} while (idade < 3 || idade > 100);
		do
		{
			printf("\n");
			printf("Digite a entrada selecionada:\n");
			printf("[1]  - Inteira, R$ 50,00\n");
			printf("[2]  - Meia Entrada, RS 25,00\n");
			printf("Opcao: ");
			scanf("%d", &opcao);

			switch (opcao)
			{
			case 1:
            for (int i = 25; i < quantidade; i * 2)
				break;

			case 2:
				break;
			default:
				printf("Opcao invalida.\n");
			}
		} while (opcao != 1 && opcao != 2);
	}
    printf("Valor total arrecadado nessa sessao: %d", valor);
}
	