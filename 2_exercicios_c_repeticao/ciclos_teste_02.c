/*
AUTOR: PAULO POCINHO
DESDE: 16-03-2017

Teste Final: Elabore uma base de dados de clientes de uma fábrica de
materiais. O programa deverá possibilitar inserção e listagem dos clientes bem
como as compras por eles efetuadas( Númcli(Automático), NomCli, morada, tel,
nif, compra, Divfin ). Divida final=compra – desconto, valor do desconto se
compra for entre 100 e 200 é 5%, se for superior a 200 e inferior a 500 é 10%
se superior a 500 é 15%. O programa deve validar todas as entradas e na
listagem deve parar cliente a cliente e ser possível busca direta por número
de cliente. 5v. O programa deve conter (Estruturas 3v, funções .5v, Vetores
.4v, apontadores .3v). 2 H 

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>


#ifndef MAX_NUMERO_CLIENTES
#define MAX_NUMERO_CLIENTES 10
#endif

#ifndef MAX_DADOS_CLIENTE
#define MAX_DADOS_CLIENTE 100
#endif

#ifndef NOME_BASE_DADOS
#define NOME_BASE_DADOS "db-clientes-c.txt"
#endif


struct dados_cliente
{
	unsigned int numero;
	char nome[MAX_DADOS_CLIENTE];
	char morada[MAX_DADOS_CLIENTE];
	int telefone;
	int nif;
	double compra;
	double divida;
};

typedef struct dados_cliente DADOS;

void menu();
void adicionar_cliente(DADOS *clientes, unsigned int *inscritos);
void consultar_cliente(DADOS *clientes, unsigned int inscritos);
void listar_clientes(DADOS *clientes, unsigned int inscritos);
void guardar_dados(DADOS *clientes, unsigned int inscritos);
void carregar_dados(DADOS *clientes, unsigned int *inscritos);
int existe_ficheiro(const char *filename);

int main()
{
	short opcao = 0;
	DADOS clientes[MAX_NUMERO_CLIENTES];
	unsigned int inscritos = 0;

	do
	{
		for (;;) // necessario para nao corromper o switch
		{
			menu();
			if (scanf("%hu", &opcao) != 1)
			{
				while (getchar() != '\n'); // limpar caracteres introduzidos
				puts("Opcao invalida.");
			}
			else
				break;
		}
		while (getchar() != '\n'); // consumir o '\n' para o fgets funcionar mais a frente

		switch (opcao)
		{
		case 1:
			adicionar_cliente(clientes, &inscritos);
			break;
		case 2:
			consultar_cliente(clientes, inscritos);
			break;
		case 3:
			listar_clientes(clientes, inscritos);
			break;
		case 4:
			guardar_dados(clientes, inscritos);
			break;
		case 5:
			carregar_dados(clientes, &inscritos);
			break;
		case 0:
			puts("Adeus, volte sempre!");
			break;
		default:
			puts("Opcao invalida.");
		}
	} while (opcao != 0);


	return 0;
}

void menu()
{
	puts("Opcoes disponiveis:");
	puts(" 1 - Adicionar Cliente");
	puts(" 2 - Consultar Cliente");
	puts(" 3 - Ver Lista de Clientes");
	puts(" 4 - Guardar Dados");
	puts(" 5 - Carregar Dados");
	puts(" 0 - Sair");
}

void adicionar_cliente(DADOS *clientes, unsigned int *inscritos)
{
	if ((*inscritos) >= MAX_NUMERO_CLIENTES - 1)
		puts("Nao e possivel adicionar mais clientes.");
	else
	{
		DADOS cliente;
		puts("Introduza o nome de cliente:");
		fgets(cliente.nome, MAX_DADOS_CLIENTE - 1, stdin);
		sscanf(cliente.nome, "%[^\n]", cliente.nome); // remover '\n'
		puts("Introduza a morada do cliente:");
		fgets(cliente.morada, MAX_DADOS_CLIENTE - 1, stdin);
		sscanf(cliente.morada, "%[^\n]", cliente.morada); // remover '\n'
		for (;;)
		{
			puts("Introduza o numero de telefone do cliente:");
			if (scanf("%d", &cliente.telefone) != 1 || cliente.telefone < 210000000 || cliente.telefone > 969999999)
			{
				while (getchar() != '\n'); // limpar caracteres introduzidos
				puts("Numero de telefone invalido.");
			}
			else
				break;
		}
		for (;;)
		{
			puts("Introduza o NIF do cliente:");
			if (scanf("%d", &cliente.nif) != 1)
			{
				while (getchar() != '\n'); // limpar caracteres introduzidos
				puts("NIF invalido.");
			}
			else
				break;
		}
		for (;;)
		{
			puts("Introduza o valor da compra:");
			if (scanf("%lf", &cliente.compra) != 1 || cliente.compra < 0)
			{
				while (getchar() != '\n'); // limpar caracteres introduzidos
				puts("Valor de compra invalido.");
			}
			else
				break;
		}
		if (cliente.compra >= 100 && cliente.compra <= 200)
			cliente.divida = cliente.compra - cliente.compra * 0.05;
		else if (cliente.compra > 200 && cliente.compra < 500)
			cliente.divida = cliente.compra - cliente.compra * 0.10;
		else if (cliente.compra >= 500) // Considerei 500 inclusive em vez de superior a 500
			cliente.divida = cliente.compra - cliente.compra * 0.15;
		else
			cliente.divida = cliente.compra;
		cliente.numero = *inscritos;
		clientes[*inscritos] = cliente;
		(*inscritos)++;
	}

}

void consultar_cliente(DADOS *clientes, unsigned int inscritos)
{
	unsigned int valor = 0;
	if (inscritos == 0)
		puts("Ainda nao ha clientes registados.");
	else
	{
		for (;;)
		{
			puts("Introduza o numero de cliente:");
			if (scanf("%u", &valor) != 1 || valor < 0 || valor > inscritos - 1)
			{
				while (getchar() != '\n'); // limpar caracteres introduzidos
				puts("Numero de cliente invalido.");
			}
			else
				break;
		}
		printf("Dados do cliente numero: %u\n", clientes[valor].numero);
		printf("Nome: %s\n", clientes[valor].nome);
		printf("Morada: %s\n", clientes[valor].morada);
		printf("Telefone: %d\n", clientes[valor].telefone);
		printf("NIF: %d\n", clientes[valor].nif);
		printf("Valor da compra: %.2lf\n", clientes[valor].compra);
		printf("Total divida: %.2lf\n", clientes[valor].divida);
	}
}

void listar_clientes(DADOS *clientes, unsigned int inscritos)
{
	if (inscritos == 0)
		puts("Ainda nao ha clientes registados.");
	else
	{
		short opcao = 2;
		for (unsigned int i = 0; i < inscritos; ++i)
		{
			if (opcao == 0)
				break;
			printf("Dados do cliente numero: %u\n", clientes[i].numero);
			printf("Nome: %s\n", clientes[i].nome);
			printf("Morada: %s\n", clientes[i].morada);
			printf("Telefone: %d\n", clientes[i].telefone);
			printf("NIF: %d\n", clientes[i].nif);
			printf("Valor da compra: %.2lf\n", clientes[i].compra);
			printf("Total divida: %.2lf\n", clientes[i].divida);
			for (;;)
			{
				puts("Prima 1 para continuar, 0 para sair.");
				if ((scanf("%hu", &opcao) != 1) || (opcao < 0) || (opcao > 1))
				{
					while (getchar() != '\n'); // limpar caracteres introduzidos
					puts("Opcao invalida.");
				}
				else
					break;
			}
		}
	}
}

void guardar_dados(DADOS *clientes, unsigned int inscritos)
{
	if (inscritos == 0)
		puts("Ainda nao ha clientes registados.");
	else
	{
		FILE *f;
		errno_t erro = fopen_s(&f, NOME_BASE_DADOS, "w");
		if (erro)
			puts("Nao foi possivel escrever dados.");
		else
		{
			for (unsigned int i = 0; i < inscritos; ++i)
			{
				fprintf(f, "%u,", clientes[i].numero);
				fprintf(f, "%s,", clientes[i].nome);
				fprintf(f, "%s,", clientes[i].morada);
				fprintf(f, "%d,", clientes[i].telefone);
				fprintf(f, "%d,", clientes[i].nif);
				fprintf(f, "%lf,", clientes[i].compra);
				fprintf(f, "%lf\n", clientes[i].divida);
			}
			puts("Dados gravados com sucesso.");
		}
		fclose(f);
	}
}

void carregar_dados(DADOS *clientes, unsigned int *inscritos)
{
	if (!existe_ficheiro(NOME_BASE_DADOS))
		puts("Ainda nao ha registo.");
	else
	{
		FILE *f;
		errno_t erro = fopen_s(&f, NOME_BASE_DADOS, "r");
		if (erro)
			puts("Nao foi possivel ler dados.");
		else
		{
			*inscritos = 0;
			DADOS cliente;
			char linha[1024];
			for (int i = 0; i < MAX_NUMERO_CLIENTES; ++i)
			{
				if (fgets(linha, sizeof(linha), f) == NULL)
					break;
#ifdef _DEBUG
				printf("A processar linha: %s", linha);
#endif // _DEBUG
				sscanf(linha, "%u,%[^,],%[^,],%d,%d,%lf,%lf",
					&cliente.numero,
					cliente.nome,
					cliente.morada,
					&cliente.telefone,
					&cliente.nif,
					&cliente.compra,
					&cliente.divida);
				clientes[i] = cliente;
				(*inscritos)++;
			}
			puts("Dados carregados com sucesso.");
		}
		fclose(f);
	}
}

int existe_ficheiro(const char *filename)
{
	struct stat st;
	int result = stat(filename, &st);
	return result == 0;
}
