/*
AUTOR: PAULO POCINHO
DESDE: 16-03-2017

Exercício 17: Elabore um programa que determine os múltiplos de 5
mas não múltiplos de 3 …. De 1 a 1000 deve ser a sequência

*/

#include <iostream>

using namespace std;

int main()
{
    for (int i = 1; i <= 1000; ++i)
    {
        if ((i % 5 == 0) && (i % 3 != 0))
            cout << i << " ";
    }

    cout << endl;

    system("PAUSE");
    return 0;
}
