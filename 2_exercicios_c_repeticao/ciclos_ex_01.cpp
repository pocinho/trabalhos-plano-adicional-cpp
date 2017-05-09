/*
AUTOR: PAULO POCINHO
DESDE: 16-03-2017

Exercício 1: Crie um algoritmo que mostre os 30 primeiros números ímpares e pares.

*/

#include <iostream>

using namespace std;

int main()
{
    cout << "Primeiros 30 numeros impares:\n";
    for (int i = 1; i <= 60; ++i)
    {
        if (i % 2 != 0)
            cout << i << " ";
    }
    cout << endl;

    cout << "Primeiros 30 numeros pares:\n";
    for (int i = 1; i <= 60; ++i)
    {
        if (i % 2 == 0)
            cout << i << " ";
    }
    cout << endl;
    
    system("PAUSE");
    return 0;
}
