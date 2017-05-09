/*
AUTOR: PAULO POCINHO
DESDE: 16-03-2017

Teste Final: Elabore um programa que leia um valor de entrada e mostre para cada
valor até ao 1 (se é número Primo, Quantos divisores e números perfeitos) o
Programa deve validar entradas entre 1 e 30.000, e parar de 10 em 10 valores com
instrução para parar ou continuar. No mesmo programa use um menu e Elabore uma
calculadora simples (+,-,*,/) com a função extra tabuada. Validar entradas de 1
a 1000 (nota a tabuada deve apresentar todas as multiplicações de 1 ate ao máximo
introduzido) deve parar de 20 em 20 valores.

*/

#include <iostream>
using namespace std;

void limparbuff();
void menu();
void verificar();
void calc(char op);
double soma2(double num1, double num2);
double mult2(double num1, double num2);
double div2(double num1, double num2);
double sub2(double num1, double num2);
void tabuada();

int main()
{
	short opcao = 0;

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
				cout << "Numero invalido\n";
			}
		}
		switch (opcao)
		{
		case 1:
			verificar();
			break;
		case 2:
			calc('+');
			break;
		case 3:
			calc('-');
			break;
		case 4:
			calc('*');
			break;
		case 5:
			calc('/');
			break;
		case 6:
			tabuada();
			break;
		case 0:
			cout << "Adeus, volte sempre!\n";
			break;
		default:
			cout << "Opcao invalida!\n";
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
	cout << "Introd opcao:\n";
	cout << "1 - verificar numero\n";
	cout << "2 - somar\n";
	cout << "3 - subtrair\n";
	cout << "4 - multiplicar\n";
	cout << "5 - dividir\n";
	cout << "6 - tabuada\n";
	cout << "0 - sair\n";
}
void verificar()
{
	int num = 0;
	int divisores = 0;
	int soma_divisores = 0;
	int perfeitos = 0;
	short sair = -1;
	short ct = 0;

	for (;;)
	{
		cout << "introd numero entre 1 e 30000: ";
		if (cin >> num && num >= 1 && num <= 30000)
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

	for (int i = num; i > 0; --i)
	{
		if (sair == 0)
			break;
		for (int j = 1; j <= i; ++j)
		{
			if (i % j == 0)
			{
				soma_divisores += j;
				divisores++;
			}
		}

		cout << i << " tem " << divisores << " divisores, ";
		if (divisores == 2)
			cout <<"e primo, ";
		else
			cout <<"nao e primo, ";

		soma_divisores -= i;

		if (soma_divisores == i)
		{
			perfeitos++;
			cout << "e perfeito\n";
		}
		else
			cout << "nao e perfeito\n";

		if (i == 1)
			cout << num << " contem " << perfeitos << " numeros perfeitos\n";

		if (ct == 10)
		{
			ct = 0;
   			for (;;)
			{
				cout << "1 para continuar, 0 para sair\n";
				if ((cin >> sair) && sair == 0 || sair == 1)
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
		}
		ct++;
		divisores = 0;
		soma_divisores = 0;
	}
}
void calc(char op)
{
	double num1;
	double num2;

	for (;;)
	{
		cout << "Introd primeiro numero: ";
		if (cin >> num1)
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

	for (;;)
	{
		cout << "Introd segundo numero: ";
		if (cin >> num2)
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
	switch (op)
	{
	case '+':
		cout << num1 << " + " << num2 << " = " << soma2(num1, num2) << endl;
		break;
	case '-':
		cout << num1 << " - " << num2 << " = " << sub2(num1, num2) << endl;
		break;
	case '*':
		cout << num1 << " * " << num2 << " = " << mult2(num1, num2) << endl;
		break;
	case '/':
		cout << num1 << " / " << num2 << " = " << div2(num1, num2) << endl;
		break;
	default:
		cout << "aconteceu algo errado\n";
		break;
	}

}
double soma2(double num1, double num2)
{
	return num1 + num2;
}
double mult2(double num1, double num2)
{
	return num1 * num2;
}
double div2(double num1, double num2)
{
	return num2 != 0 ? num1 / num2 : 0;
}
double sub2(double num1, double num2)
{
	return num1 - num2;
}
void tabuada()
{
	int num = 0;
	short sai = -1;
	short ct = 0;
	for (;;)
	{
		cout << "introd numero entre 1 e 1000: ";
		if (cin >> num && num >= 1 && num <= 1000)
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
	for (int i = 1; i <= num; ++i)
	{
		if (ct >= 20)
		{
			ct = 0;
			for (;;)
			{
				cout << "Prima 1 para continuar, 0 para sair\n";
				if (cin >> sai && sai == 0 || sai == 1)
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
		}
		if (sai == 0)
			break;
		for (int j = 1; j <= 10; ++j)
		{
			ct++;
			cout << i << " * " << j << " = " << (int)mult2(i, j) << endl;
		}
	}
}
