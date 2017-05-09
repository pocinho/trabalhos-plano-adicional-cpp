/*
AUTOR: PAULO POCINHO
DESDE: 09-03-2017

Exercício for: Ler 10 números, e determinar o número par e numero
impar….

versão sem array.

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
    int num = 0;

    for (int i = 0; i < 10; ++i)
    {
        for (;;) {
            cout << "Introduza um numero (" << (i + 1) << "):\n";
            if (cin >> num) {
                limparbuff();
                break;
            } else {
                cout << "Numero invalido.\n";
                limparbuff();
            }
        }
        if ((num % 2) == 0)
            cout << num << " e par\n";
        else
            cout << num << " e impar\n";
    }

    system("PAUSE");
    return 0;
}
