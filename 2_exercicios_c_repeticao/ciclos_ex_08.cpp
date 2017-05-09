/*
AUTOR: PAULO POCINHO
DESDE: 16-03-2017

Exercício 8: Faça um algoritmo que gere
a seguinte série: 10, 20, 30, 40, ..... 980, 990, 1000.
e outro a fazer 15, 25, 35, 985, 995.(dois ciclos)
*/

#include <iostream>

using namespace std;

int main()
{
    int conta1 = 0;
    int conta2 = 0;

    for (int i = 1; i <= 100; ++i)
    {
        conta1 += 10;
        cout << conta1 << " ";
        for (int j = i; j < 100; ++j)
        {
            conta2 = conta1 + 5;
            cout << conta2 << " ";
            break;
        }
    }
    
	cout << endl;

    system("PAUSE");
    return 0;
}
