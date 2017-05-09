/*
AUTOR: PAULO POCINHO
DESDE: 16-03-2017

Exercício 2: Ler 10 números, e determinar se o número par e número impar.

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

    for (int i = 1; i <= 10; ++i)
    {
        for (;;) {
            cout << "Introduza o " << i << " numero:\n";
            if (cin >> numero) {
                limparbuff();
                break;
            } else {
                cout << "Numero invalido.\n";
                limparbuff();
            }
        }

        switch (numero % 2)
        {
        case 0:
            cout << numero << " e par\n";
            break;
        case 1:
            cout << numero << " e impar\n";
            break;
        default:
            cout << "Alguma coisa correu mal.\n";
        }
    }

    system("PAUSE");
    return 0;
}