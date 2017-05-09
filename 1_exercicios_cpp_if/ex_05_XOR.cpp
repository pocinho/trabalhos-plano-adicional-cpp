/*
AUTOR: PAULO POCINHO
DESDE: 09-03-2017

Exercício 5:Ler 3 valores INTEIROS para as variáveis Num1, Num2, Num3.
Apresentar os valores dispostos em ordem crescente e decrescente.

Versão com XOR

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
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;

    for (;;) {
        cout << "Introduza o primeiro inteiro:\n";
        if (cin >> num1) {
            limparbuff();
            break;
        } else {
            cout << "Numero invalido.\n";
            limparbuff();
        }
    }

    for (;;) {
        cout << "Introduza o segundo inteiro:\n";
        if (cin >> num2) {
            limparbuff();
            break;
        } else {
            cout << "Numero invalido.\n";
            limparbuff();
        }
    }

    for (;;) {
        cout << "Introduza o terceiro inteiro:\n";
        if (cin >> num3) {
            limparbuff();
            break;
        } else {
            cout << "Numero invalido.\n";
            limparbuff();
        }
    }

    if (num1 > num2)
    {
    	num1 ^= num2;
    	num2 ^= num1;
    	num1 ^= num2;
	}
	
	if (num1 > num3)
	{
		num1 ^= num3;
		num3 ^= num1;
		num1 ^= num3;
	}
	
	if (num2 > num3)
	{
		num2 ^= num3;
		num3 ^= num2;
		num2 ^= num3;
	}
	
	cout << "ordem crescente: " << num1 << " " << num2 << " " << num3 << endl;
	cout << "ordem decrescente: " << num3 << " " << num2 << " " << num1 << endl;

    system("PAUSE");
    return 0;
}
