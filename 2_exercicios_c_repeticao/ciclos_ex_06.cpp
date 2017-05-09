/*
AUTOR: PAULO POCINHO
DESDE: 16-03-2017

Exercício 6: Crie um algoritmo que mostre os 10 primeiros números primos.

*/

#include <iostream>

using namespace std;

int main()
{
    int factores = 0;
    int primos = 0;

    for (int i = 1; primos < 10; ++i)
    {
        for (int n = 1; n <= i; ++n)
        {
            if (i % n == 0)
                factores++;
        }
        if (factores == 2)
        {
            cout << i << " ";
            primos++;
        }
        factores = 0;
    }

    cout << endl;

    system("PAUSE");
    return 0;
}
