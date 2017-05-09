/*
Autor: Paulo Pocinho
Desde: 24-03-2017

Autenticação de utilizadores

Desenvolva um programa em C++ que simule a autenticação de utiliadores do
Linux. O programa deverá solicitar um nome de utilizador e uma senha e
confrontá-los com duas respectivas constantes que representariam o único
utilizador autorizado no sistema. Exibir a mensagem de acesso autorizado se os
dados forem corretos, caso contrário exibir acesso negado.

Notas:
Compilado no dev c++.

*/

#include <iostream>
#include <stdio.h>
#include <conio.h>

#ifndef UTILIZADORES
#define UTILIZADORES 10
#endif

#ifndef MAX_NOME
#define MAX_NOME 30
#endif

#ifndef MAX_PASS
#define MAX_PASS 40
#endif

using namespace std;

int main()
{
	char utilizador[UTILIZADORES][MAX_NOME]= {"user1", "user2", "user3", "user4", "user5", "user6", "user7", "user8", "user9", "user10"};
	char password[UTILIZADORES][MAX_PASS] = {"pass1", "pass2", "pass3", "pass4", "pass5", "pass6", "pass7", "pass8", "pass9", "pass10"};

	char entrar_utilizador[MAX_NOME];
	char entrar_password[MAX_PASS];

	for (;;)
	{
		int acesso = 0;
		int c = 0; // contador de caracteres para password
		char ch = '\0';

		cout << "Utilizador: ";
		cin.getline(entrar_utilizador, sizeof(entrar_utilizador));
		cin.clear();
		cin.sync();
		cout << "Password: ";
		// Modificar cin.getline(entrar_p, sizeof(entrar_p));
		// por uma versão que mete asteriscos na password:
		for (c = 0; (ch = (char)_getch()) != '\r'; ++c)
		{
			if (ch == '\b')
			{
				if (c == 0) // estamos a apagar para alem dos caracteres introduzidos
				{
					c -= 1; // no limite -1, i é incrementado para 0
				}
				else  // if (i >= 1) não queremos apagar para trás do índice. no limite -1, i é incrementado para 0
				{
					c -= 2; // Voltar atras pelo caractere e pelo '\b' introduzido pelo _getch
					cout << '\b' << ' ' << '\b'; // apagar input
				}
			}
			else
			{
				cout << "*";
			}
			if (c >= 0 && c < sizeof(entrar_password))
			{
				entrar_password[c] = ch;
			}
		}
		if (c < MAX_PASS) // terminar a palavra com '\0' em vez de '\r'
			entrar_password[c] = '\0';
		else
			entrar_password[MAX_PASS - 1] = '\0';
		// Verificar nome de utilizador:
		for (int i = 0; i < UTILIZADORES; ++i)
		{
			acesso = i;
			for (int j = 0; utilizador[i][j] != '\0' || entrar_utilizador[j] != '\0'; ++j)
			{
				if ((int)utilizador[i][j] != (int)entrar_utilizador[j])
				{
					acesso = 0;
					break;
				}
			}
			if (acesso)
				break;
		}
		// Verificar password respectiva:
		if (acesso)
		{
			for (int i = 0; password[acesso][i] != '\0' || entrar_password[i] != '\0'; ++i)
			{
				if ((int)password[acesso][i] != (int)entrar_password[i])
				{
					acesso = 0;
					break;
				}
			}
		}
		// Verificar login:
		if (acesso)
		{
			cout << "\nAcesso Autorizado\n";
			break;
		}
		else
			cout << "\nAcesso Negado\n";
	}

	system("PAUSE");
	return 0;
}
