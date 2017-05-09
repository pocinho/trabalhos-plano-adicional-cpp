/*
Autor: Paulo Pocinho
Desde: 30-03-2017

Exercício de contas com chars.

Avalia expressoes bem estruturadas (soma, subtracao, divisao e
multiplicacao) com parentesis, espaco, numeros negativos e precisao de
tres casas decimais. No caso dos parentesis, comeca a avaliar da
direita para a esquerda, do nivel mais interior para o mais exterior.

Batotas:
	- usei vectores de c++
	- usei sprintf para converter valor double em caracteres

*/

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

typedef vector<vector<char> > lexico;

void processar_paren(lexico& token, int* nr_paren_esq, int* nr_tokens);
void processar_op(lexico& token, const int inicio, int* fim, const char op);
double processar_valor(const lexico& token, const int posicao);

int main()
{
	char expr[100] = {};
	lexico token(1, vector<char>(0, '\0'));
	int t = 0;
	bool tem_operador = false;
	int nr_operadores = 0;
	int nr_paren_esq = 0;
	int nr_paren_dir = 0;

	cout << "Introduza uma expressao:\n";
	cin.getline(expr, sizeof(expr));

	// Fazer tokens:
	for (int i = 0; expr[i] != '\0'; ++i)
	{
		if (expr[i] == ' ')
		{
			continue;
		}
		else
		{
			if (expr[i] == '(')
			{
				nr_paren_esq++;
				token[t].push_back(expr[i]);
				token[t].push_back('\0');
				token.push_back(vector<char>(0, '\0')); // alocar espaço para o próx. operando
				t++;
			}
			else if (expr[i] == ')')
			{
				nr_paren_dir++;
				token[t].push_back('\0');				// terminar o ultimo operando
				token.push_back(vector<char>(0, '\0')); // alocar espaço para o parentesis
				t++;
				token[t].push_back(expr[i]);			// alocar parentesis
			}
			else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
			{
				if (expr[0] == '-') // numero negativo no principio da expressão
					tem_operador = true;

				if (!tem_operador)
				{
					token[t].push_back('\0');				// terminar o ultimo operando com '\0'
					token.push_back(vector<char>(0, '\0')); // alocar espaço para o novo operador
					t++;
					token[t].push_back(expr[i]);
					token[t].push_back('\0');
					token.push_back(vector<char>(0, '\0')); // alocar espaço para o próx. operando
					t++;
					tem_operador = true;
					nr_operadores++;
				}
				else // if (expr[i] == '-') // numero negativo
				{
					token[t].push_back(expr[i]);
				}
			}
			else
			{
				tem_operador = false;
				token[t].push_back(expr[i]);
			}

			if (expr[i + 1] == '\0')
				token[t].push_back('\0');
		}
	}

	// Verificar (de um modo simples) se a expressão está bem estruturada
	if ((t - nr_paren_esq - nr_paren_dir) / 2 == nr_operadores && nr_paren_esq == nr_paren_dir) // resultado de t / 2 trunca em inteiro
	{
		// processar parentesis
		while (nr_paren_esq > 0)
			processar_paren(token, &nr_paren_esq, &t);
		// processar operações, por ordem de precedência
		processar_op(token, 0, &t, '/');
		processar_op(token, 0, &t, '*');
		processar_op(token, 0, &t, '-');
		processar_op(token, 0, &t, '+');
		// finalizar o algoritmo com o resultado
		cout << "resultado: ";
		for (int i = 0; i <= t; ++i)
		{
			for (int j = 0; token[i][j] != '\0'; ++j)
			{
				cout << token[i][j];
			}
			cout << endl;
		}
	}
	else
	{
		cout << "expressao invalida.\n";
	}

	system("PAUSE");
	return 0;
}

void processar_paren(lexico& token, int* nr_paren_esq, int* nr_tokens)
{
	int scan = 0;
	int inicio = 0;
	int fim = 0;
	int diferenca = 0;

	if (*nr_paren_esq > 0)
	{
		for (int i = 0; *nr_paren_esq > 0 && i < *nr_tokens; ++i)
		{
			for (int j = 0; token[i][j] != '\0'; ++j)
			{
				if (token[i][j] == '(')
					scan++;

				if (scan == *nr_paren_esq)
				{
					token.erase(token.begin() + i); // remover parentesis esq
					(*nr_tokens)--;
					inicio = i;
					for (int p = i; ; ++p)
					{
						if (token[p][0] == ')')
						{
							fim = p - 1;
							diferenca = fim;
							token.erase(token.begin() + p); // remover parentesis dir
							(*nr_tokens)--;
							break;
						}
					}
					processar_op(token, inicio, &fim, '/');
					processar_op(token, inicio, &fim, '*');
					processar_op(token, inicio, &fim, '-');
					processar_op(token, inicio, &fim, '+');
					(*nr_paren_esq)--;
					*nr_tokens = *nr_tokens - (diferenca - fim);
					scan = 0;
					i = 0;
					break;
				}
			}
		}
	}
}

void processar_op(lexico& token, const int inicio, int* fim, const char op)
{
	char buffer[20] = {}; // para conversao de double para char

	for (int i = inicio; i < *fim; ++i)
	{
		for (int j = 0; token[i][j] != '\0'; ++j)
		{
			if (token[i][j] == op && i != 0) // salvaguardar numeros negativos no inicio
			{
				double valorEsq = 0.0;
				double valorDir = 0.0;
				double resultado = 0.0;

				valorEsq = processar_valor(token, i - 1);
				valorDir = processar_valor(token, i + 1);

				switch (op)
				{
				case '*':
					resultado = valorEsq * valorDir;
#ifdef _DEBUG
					cout << "mult: " << resultado << endl;
#endif
					break;
				case '/':
					resultado = valorDir != 0 ? valorEsq / valorDir : 0; // responder com zero à divisão por zero
#ifdef _DEBUG
					cout << "div: " << resultado << endl;
#endif
					break;
				case '+':
					resultado = valorEsq + valorDir;
#ifdef _DEBUG
					cout << "soma: " << resultado << endl;
#endif
					break;
				case '-':
					resultado = valorEsq - valorDir;
#ifdef _DEBUG
					cout << "subt: " << resultado << endl;
#endif
					break;
				default:
					resultado = 0;
					cout << "Ocorreu um erro: operacao invalida.\n";
					break;
				}

				sprintf(buffer, "%.3lf", resultado);

				token[i].clear();
				for (int k = 0; buffer[k] != '.'; ++k)
				{
					token[i].push_back(buffer[k]);
					if (buffer[k + 1] == '.')
					{
						token[i].push_back(buffer[k + 1]); // ponto
						token[i].push_back(buffer[k + 2]); // decimas
						token[i].push_back(buffer[k + 3]); // centesimas
						token[i].push_back(buffer[k + 4]); // milesimas
						token[i].push_back('\0');
					}
				}

				token.erase(token.begin() + i + 1);
				(*fim)--;
				token.erase(token.begin() + i - 1);
				(*fim)--;

				i = inicio;
				break;
			}
		}
	}
}

double processar_valor(const lexico& token, const int posicao)
{
	double resultado = 0.0;
	int negativo = 0;
	int divisoes = 0;
	double decimal = 0.0;

	for (int k = 0; token[posicao][k] != '\0'; ++k)
	{
		if (token[posicao][k] == '-')
		{
			negativo = 1;
			continue;
		}
		if (token[posicao][k] == '.')
		{
			for (int p = k + 1; token[posicao][p] != '\0'; ++p)
			{
				decimal *= 10;
				decimal += token[posicao][p] - '0';
				divisoes++;
			}
			for (int d = 0; d < divisoes; ++d)
				decimal /= 10;
			resultado += decimal;
			break;
		}

		resultado *= 10;
		resultado += token[posicao][k] - '0';
	}

	if (negativo)
	{
		resultado = 0 - resultado;
	}

	return resultado;
}
