/*
Autor: Paulo Pocinho
Desde: 05/04/2017

Contador de Palavras
Desenvolva um programa em C que leia uma frase até 80 caracteres e
exiba o tamanho da frase e a quantidade de palavras que a compõe.
Frase: Estou a aprender a programar em C++
A frase possui 29 caracteres
Total de palavras: 7

*/

#include <iostream>

using namespace std;

int main()
{
	char buffer[80];
	int palavras = 0;
	int caracteres = 0;

	cout << "Introduza uma frase:\n";
	cin.getline(buffer, sizeof(buffer));

	for (int i = 0; buffer[i] != '\0'; ++i)
	{
		if (buffer[i] != ' ')
			caracteres++;

		if (i != 0 && buffer[i] == ' ' && buffer[i - 1] != ' ')
			palavras++;

		if (i != 0 && buffer[i + 1] == '\0' && buffer[i - 1] != ' ')
			palavras++;
	}

	cout << "A frase possui " << caracteres << " caracteres.\n";
	cout << "Total de palavras: " << palavras << endl;

    return 0;
}
