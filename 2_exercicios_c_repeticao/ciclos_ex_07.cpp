/*
AUTOR: PAULO POCINHO
DESDE: 16-03-2017

Exercício 7: Faça um algoritmo que gere
a seguinte série: 10, 20, 30, 40, ..... 980, 990, 1000.

*/

#include <iostream>

using namespace std;

int main()
{
    int conta = 0;

    for (int i = 1; i <= 100; ++i)
    {
        conta += 10;
        cout << conta << " ";
    }
    
    cout << endl;

    system("PAUSE");
    return 0;
}
