/*
AUTOR: PAULO POCINHO
DESDE: 16-03-2017

Exercício 13: Elabore um programa que leia um número e mostre a tabuada.
(multiplicar de 1 a 10)

*/

#include <iostream>

using namespace std;

void limparbuff()
{
    cin.clear();
    cin.sync();
}

int main()
{
    int numero = 0;

    for (;;) {
        cout << "Introduza um numero:\n";
        if (cin >> numero) {
            limparbuff();
            break;
        } else {
            cout << "Numero invalido.\n";
            limparbuff();
        }
    }

    for (int i = 1; i <= 10; ++i)
    {
    	cout << numero << " x " << i << " = " << numero * i << endl;
	}
	
    system("PAUSE");
    return 0;
}
