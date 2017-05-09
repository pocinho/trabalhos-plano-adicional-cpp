/*
Autor: Paulo Pocinho
Desde: 26-04-2017

Crie um programa que receba nomes de clientes e que faça uma busca num vector
de caracteres bidimensional e devolva a posição que o mesmo se encontram bem
como o que se encontra na posição.( menu introduzir dados, procura dados)

*/

#include <iostream>

#define MAX_NOME 20
#define MAX_CLI 10

using namespace std;

void limparbuff();
void menu();
void inserir(int * registados, char clientes[][MAX_NOME]);
void procurar(int registados, char clientes[][MAX_NOME]);

int main()
{
	char clientes[MAX_CLI][MAX_NOME] = {};
	int registados = 0;
	int opcao = 0;

	do
	{
		for (;;)
		{
			menu();
			if (cin >> opcao)
			{
				limparbuff();
				break;
			}
			else
			{
				limparbuff();
				cout << "input invalido\n";
			}
		}
		switch (opcao)
		{
		case 1:
			inserir(&registados, clientes);
			break;
		case 2:
			procurar(registados, clientes);
			break;
		case 0:
			cout << "adeus, volte sempre\n";
			break;
		default:
			cout << "opcao invalida\n";
			break;
		}
	} while (opcao != 0);

	return 0;
}

void limparbuff()
{
	cin.clear();
	cin.sync();
}
void menu()
{
	cout << "opcoes:\n";
	cout << "1 - inserir\n";
	cout << "2 - procurar\n";
	cout << "0 - sair\n";
	cout << "introd opcao:\n";
}
void inserir(int * registados, char clientes[][MAX_NOME])
{
	char buff[MAX_NOME] = {};
	if (*registados >= MAX_CLI)
		cout << "impossivel adicionar mais clientes\n";
	else
	{
		cout << "introd nome de cliente: ";
		cin.getline(buff, sizeof(buff));
		limparbuff();
		for (int i = 0; i < MAX_NOME; ++i)
		{
			clientes[*registados][i] = buff[i];
		}
		(*registados)++;
		cout << "cliente " << buff << " adicionado\n";
	}
}
void procurar(int registados, char clientes[][MAX_NOME])
{
	char buff[MAX_NOME] = {};
	char conteudo[MAX_NOME] = {};
	int encontrado = -1;
	bool sair = false;

	if (registados == 0)
		cout << "ainda nao ha clientes registados\n";
	else
	{
		cout << "introd nome de cliente: ";
		cin.getline(buff, sizeof(buff));
		limparbuff();
		for (int i = 0; i < registados; ++i)
		{
			if (sair)
				break;

			for (int j = 0; j < MAX_NOME; ++j)
			{
				if (clientes[i][j] == buff[j])
				{
					encontrado = i;
					if (clientes[i][j + 1] == '\0')
					{
						sair = true;
						break;
					}
				}
				else
				{
					encontrado = -1;
					break;
				}
			}
		}
		if (encontrado != -1)
		{
			for (int i = 0; i < MAX_NOME; ++i)
			{
				conteudo[i] = clientes[encontrado][i];
			}
			cout << "cliente " << conteudo << " encontrado na posicao " << encontrado << endl;
		}
	}
}


