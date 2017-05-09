/*
AUTOR: PAULO POCINHO
DESDE: 16-03-2017

Exercício 16: Elabore um programa que constitua a média de 30 números
pares que sejam introduzidos. Validando a entrada de números inteiros
entre 1 e 50.

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
    int pares = 0;
    int conta = 0;
    int numero = 0;

    while (pares < 30)
    {
        do
        {
            cout << "Introduza o numero par " << pares + 1 << " de 30 (valores entre 1 e 50):\n";
            cin >> numero;
            limparbuff();
        }
        while (numero < 1 || numero > 50);

        if (numero % 2 == 0)
        {
            pares++;
            conta += numero;
        }
    }
    cout << "A media e: " << (double)conta / 30.0 << endl;

    system("PAUSE");
    return 0;
}
