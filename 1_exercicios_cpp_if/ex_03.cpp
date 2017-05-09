/*
AUTOR: PAULO POCINHO
DESDE: 09-03-2017

Exercício 3: Crie 2 variáveis (num1 e num2) e leia o valor para cada
um deles. Mostre os valores de forma crescente e decrescente.

*/

#include <iostream>

using namespace std;

int main()
{
    int n1 = 0;
    int n2 = 0;

    for (;;)
    {
        cout << "introduza o primeiro inteiro:\n";
        if (cin >> n1)
            break;
        else
        {
            cout << "Numero invalido.\n";
        }
    }

    for (;;)
    {
        cout << "introduza o segundo inteiro:\n";
        if (cin >> n2)
            break;
        else
        {
            cout << "Numero invalido.\n";
        }
    }

    cout << "por ordem crescente:\n";
    if (n2 >= n1)
        cout << n1 << " " << n2 << endl;
    else
        cout << n2 << " " << n1 << endl;

    cout << "por ordem decrescente:\n";
    if (n1 >= n2)
        cout << n1 << " " << n2 << endl;
    else
        cout << n2 << " " << n1 << endl;

    system("PAUSE");
    return 0;
}
