/*
AUTOR: PAULO POCINHO
DESDE: 09-03-2017

Exercício 2: Fazer um programa que analise 3 valores inteiros (através
das variáveis num1, num2 e num3), e informa qual o maior e qual o
menor deles.

Versão com if.

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

    if ((num1 <= num2) && (num1 >= num3))
    {
        cout << num2 << " e o maior\n";
        cout << num3 << " e o menor\n";
    }
    else if ((num1 >= num2) && (num1 <= num3))
    {
        cout << num3 << " e o maior\n";
        cout << num2 << " e o menor\n";
    }
    else if ((num2 <= num1) && (num2 >= num3))
    {
        cout << num1 << " e o maior\n";
        cout << num3 << " e o menor\n";
    }
    else if ((num2 >= num1) && (num2 <= num3))
    {
        cout << num3 << " e o maior\n";
        cout << num1 << " e o menor\n";
    }
    else if ((num3 <= num2) && (num3 >= num1))
    {
        cout << num2 << " e o maior\n";
        cout << num1 << " e o menor\n";
    }
    else if ((num3 >= num2) && (num3 <= num1))
    {
        cout << num1 << " e o maior\n";
        cout << num2 << " e o menor\n";
    }

    system("PAUSE");
    return 0;
}
