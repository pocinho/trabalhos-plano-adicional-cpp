/*
AUTOR: PAULO POCINHO
DESDE: 16-03-2017

Exercício 4: Crie um algoritmo que leia um número inteiro,
e diga se ele é um número primo ou não.

*/

#include <iostream>
#include <limits>

using namespace std;

void limparbuff()
{
    cin.clear();
    cin.sync();
}

int main()
{
    int numero = 0;
    int factores = 0;

    for (;;) {
        cout << "Introduza um numero inteiro positivo:\n";
        if (cin >> numero && numero > 0) {
            limparbuff();
            break;
        } else {
            cout << "Numero invalido.\n";
            limparbuff();
        }
    }

    for (int i = 1; i < numero; ++i)
    {
        if (numero % i == 0)
            factores++;
    }

    if (factores == 2)
        cout << numero << " e primo\n";
    else
        cout << numero << " nao e primo\n";

    system("PAUSE");
    return 0;
}
