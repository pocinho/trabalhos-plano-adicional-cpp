/*
Autor: Paulo Pocinho
Desde: 26/04/2017

Faça uma Struct de funcionário
código(int)
nome (101 char)
sexo(1 caracter – m/f)
salario(float)

Defina Funções:
a) inserir um funcionário na lista
b) exibir os dados de todos os funcionários
c) dado o código de um funcionário e uma percentagem p, aumentar o salario deste funcionário em p%
d) contar quantos funcionários do sexo masculino e feminino há na lista
e) dado o código de um funcionário, remove-lo da lista(a lista não pode conter conteúdos vazios)
f) somar o salario de todos os funcionário

Obrigatório o uso de apontadores.

*/

#include <iostream>

#define MAX_NOME 20
#define MAX_FUNC 10

using namespace std;

typedef struct funcionario
{
	int codigo = 0;
	char nome[MAX_NOME] = {};
	char sexo = '\0';
	float salario = 0.0;
} Funcionario;

void limparbuff();
void menu();
void inserir(int * registados, Funcionario * funcs);
void listar(int registados, Funcionario * funcs);
void aumentar(int registados, Funcionario * funcs);
void contar_genero(int registados, Funcionario * funcs);
void remover(int * registados, Funcionario * funcs);
void somar_salarios(int registados, Funcionario * funcs);

int main()
{
	Funcionario funcs[MAX_FUNC];
	int registados = 0;
	int opcao = 0;
	
	do
	{
		menu();
		for (;;)
		{
			if (cin >> opcao)
			{
				limparbuff();
				break;
			}
			else
			{
				limparbuff();
				cout << "numero invalido\n";
			}
		}
		switch (opcao)
		{
		case 1:
			inserir(&registados, funcs);
			break;
		case 2:
			listar(registados, funcs);
			break;
		case 3:
			aumentar(registados, funcs);
			break;
		case 4:
			contar_genero(registados, funcs);
			break;
		case 5:
			remover(&registados, funcs);
			break;
		case 6:
			somar_salarios(registados, funcs);
			break;
		case 0:
			cout << "adeus, volte sempre.\n";
			break;
		default:
			cout << "opcao invalida.\n";
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
	cout << "1 - inserir func\n";
	cout << "2 - listar func\n";
	cout << "3 - aumentar func\n";
	cout << "4 - contar genero func\n";
	cout << "5 - remover func\n";
	cout << "6 - somar salarios\n";
	cout << "0 - sair\n";
	cout << "Introd opcao:\n";
}
void inserir(int * registados, Funcionario * funcs)
{
	if (*registados >= MAX_FUNC - 1)
		cout << "nao e possivel inserir mais funcionarios\n";
	else
	{
		Funcionario f;
		for (;;)
		{
			cout << "introd codigo de func: ";
			if (cin >> f.codigo)
			{
				limparbuff();
				break;
			}
			else
			{
				limparbuff();
				cout << "numero invalido\n";
			}
		}
		cout << "introd nome funcionario: ";
		cin.getline(f.nome, sizeof(f.nome));
		limparbuff();
		for (;;)
		{
			cout << "introd sexo funcionario (m/f): ";
			if (cin >> f.sexo && (f.sexo == 'm' || f.sexo == 'f'))
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
		for (;;)
		{
			cout << "introd salario funcionario: ";
			if (cin >> f.salario)
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
		funcs[*registados] = f;
		(*registados)++;
		cout << "func com codigo " << f.codigo << " adicionado\n";
	}
}
void listar(int registados, Funcionario * funcs)
{
	if (registados == 0)
		cout << "ainda nao ha funcionarios\n";
	else
	{
		for (int i = 0; i < registados; ++i)
		{
			cout << "codigo: " << funcs[i].codigo << endl;
			cout << "nome: " << funcs[i].nome << endl;
			cout << "sexo: " << funcs[i].sexo << endl;
			cout << "salario: " << funcs[i].salario << endl;
			cout << endl;
		}
	}
}
void aumentar(int registados, Funcionario * funcs)
{
	int codigo = 0;
	bool encontrado = false;
	float percentagem = 0.0;
	
	if (registados == 0)
		cout << "ainda nao ha funcionarios\n";
	else
	{
		
		for (;;)
		{
			cout << "introd codigo de func: ";
			if (cin >> codigo)
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
		for (int i = 0; i < registados; ++i)
		{
			if (funcs[i].codigo == codigo)
			{
				encontrado = true;
				cout << "introd percentagem a aumentar: ";
				for (;;)
				{
					if (cin >> percentagem)
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
				funcs[i].salario = funcs[i].salario + funcs[i].salario * percentagem;
				cout << "func com codigo " << codigo << " aumentado para " << funcs[i].salario << endl;
				break;
			}
		}
		if (!encontrado)
			cout << "nao foi possivel encontrar func com codigo " << codigo << endl;
	}
}
void contar_genero(int registados, Funcionario * funcs)
{
	int masc = 0;
	int femi = 0;
	
	if (registados == 0)
		cout << "ainda nao ha funcionarios\n";
	else
	{
		for (int i = 0; i < registados; ++i)
		{
			if (funcs[i].sexo == 'm')
				masc++;
			else
				femi++;
		}
		cout << "funcs do genero feminino: " << femi << endl;
		cout << "funcs do genero masculino: " << masc << endl;
	}
}
void remover(int * registados, Funcionario * funcs)
{
	int codigo = 0;
	bool encontrado = false;
	if (registados == 0)
		cout << "ainda nao ha funcionarios\n";
	else
	{
		for (;;)
		{
			cout << "introd codigo de func: ";
			if (cin >> codigo)
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
		for (int i = 0; i < *registados; ++i)
		{
			if (funcs[i].codigo == codigo)
			{
				encontrado = true;
				for (int j = i; j < *registados - 1; ++j)
				{
					funcs[j] = funcs[j + 1];
				}
				(*registados)--;
			}
		}
		if (!encontrado)
			cout << "nao foi possivel encontrar func com codigo " << codigo << endl;
	}
}
void somar_salarios(int registados, Funcionario * funcs)
{
	float total = 0.0;
	
	if (registados == 0)
		cout << "ainda nao ha funcionarios\n";
	else
	{
		for (int i = 0; i < registados; ++i)
		{
			total += funcs[i].salario;
		}
		cout << "total salarios: " << total << endl;
	}
}


