/*
AUTOR: PAULO POCINHO
DESDE: 16-03-2017

Exercícios 19:Escreva um programa que mostre os primeiros 60 números da serie bonatchi.
1, 1, 2, 3, 5, 8, 13, 21.
Como se constrói.
1+1=2
1+2=3
2+3=5

*/

#include <iostream>

using namespace std;

int main()
{
	long long num1 = 1;
	long long num2 = 1;
    long long conta = 0;

	cout << num1 << ", " << num2 << ", ";

    for (int i = 1; i <= 58; ++i)
    {
        conta = num1 + num2;
        num1 = num2;
        num2 = conta;
        cout << conta << ", ";
    }

    system("PAUSE");
    return 0;
}
