/*
AUTOR: PAULO POCINHO
DESDE: 16-03-2017

Exercício 1: Crie um algoritmo que mostre os 30 primeiros números ímpares e pares.

versão com switch

*/

#include <iostream>

using namespace std;

int main()
{
    for (int i = 1; i <= 60; ++i)
    {
        switch (i % 2)
        {
            case 0:
                cout << i << " par\n";
                break;
            case 1:
                cout << i << " impar\n";
                break;
            default:
                cout << "Alguma coisa correu mal.\n";
                break;
        }
    }

    system("PAUSE");
    return 0;
}
