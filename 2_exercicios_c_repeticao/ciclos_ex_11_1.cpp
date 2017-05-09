/*
AUTOR: PAULO POCINHO
DESDE: 16-03-2017

Exercício 11: Elabore um ciclo for para produzir o seguinte output.
    1
    22
    333
    4444
    55555

versão com dois ciclos

*/

#include <iostream>

using namespace std;

int main()
{
    for (int i = 1; i <= 5; ++i)
    {
		for (int j = 1; j <= i; ++j)
            cout << i;
        cout << endl;
    }

    system("PAUSE");
    return 0;
}
