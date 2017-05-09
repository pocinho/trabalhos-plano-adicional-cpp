/*
AUTOR: PAULO POCINHO
DESDE: 16-03-2017

Exercício 10: Elabore um programa que lê um número e escreve quantos
divisores ele possui.

*/

#include <iostream>

using namespace std;

void limparbuff()
{
    cin.clear();
    cin.sync();
}

int main()
{
    int numero = 0;
    int divisores = 0;

    for (;;) {
        cout << "Introduza um numero:\n";
        if (cin >> numero) {
            limparbuff();
            break;
        } else {
            cout << "Numero invalido.\n";
            limparbuff();
        }
    }

    for (int i = 1; i <= numero; ++i)
    {
        if (numero % i == 0)
            divisores++;
    }

    cout << "O numero " << numero << " tem " << divisores << " divisores.\n";

    system("PAUSE");
    return 0;
}
