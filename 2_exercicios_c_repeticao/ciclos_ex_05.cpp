/*
AUTOR: PAULO POCINHO
DESDE: 16-03-2017

Exercício 5: Elabore um programa que escreve os primeiros 10.000
números inteiros no ecrã.

*/

#include <iostream>

using namespace std;

int main()
{
    for (int i = 1; i <= 10000; ++i)
    {
        cout << i << endl;
    }

    system("PAUSE");
    return 0;
}