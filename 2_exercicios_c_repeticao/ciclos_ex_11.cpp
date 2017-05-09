/*
AUTOR: PAULO POCINHO
DESDE: 16-03-2017

Exercício 11: Elabore um ciclo for para produzir o seguinte output.
    1
    22
    333
    4444
    55555
*/

#include <iostream>

using namespace std;

int main()
{
	int conta = 1;

    for (int i = 1; i <= 5; ++i)
    {
		cout << conta * i << endl;
		conta = conta * 10 + 1;
    }

    system("PAUSE");
    return 0;
}
