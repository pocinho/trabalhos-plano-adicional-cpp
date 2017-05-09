/*
AUTOR: PAULO POCINHO
DESDE: 16-03-2017

Exercício 14: Altere o programa anterior para que mostre todas as tabuadas de 1 a 100.
(ciclos for).

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

    cout << "Introduza um numero:\n";
    for (;;) {
        if (cin >> numero) {
            limparbuff();
            break;
        }
        else
        {
            cout << "Numero invalido.\n";
            limparbuff();
        }
    }

    for (int i = 1; i <= 100; ++i)
    {
        cout << numero << " x " << i << " = " << numero * i << endl;
    }

    system("PAUSE");
    return 0;
}
