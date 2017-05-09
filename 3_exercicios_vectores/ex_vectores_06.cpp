/*
Autor: Paulo Pocinho
Desde: 05/04/2017

Escreva um programa que dado um vector de caracteres (como
argumento) a converta num inteiro.

*/

#include <iostream>

using namespace std;

#define MAX_STRING 100

int main()
{
    char buffer[MAX_STRING] = {};
    int valor = 0;

    cout << "Introduza uma frase:\n";
    cin.getline(buffer, sizeof(buffer));

    for (int i = 0; buffer[i] != '\0'; ++i)
    {
        valor += (int)buffer[i];
    }

    cout << "Valor da frase em inteiro: " << valor << endl;

    system("PAUSE");
    return 0;
}
