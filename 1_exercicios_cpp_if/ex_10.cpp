/*
AUTOR: PAULO POCINHO
DESDE: 09-03-2017

Exercício for: Ler 10 números, e determinar o número par e numero
impar….

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
    int nums[10] = {};

    for (int i = 0; i < 10; ++i)
    {
        for (;;) {
            cout << "Introduza um numero (" << (i + 1) << "):\n";
            if (cin >> nums[i]) {
                limparbuff();
                break;
            } else {
                cout << "Numero invalido.\n";
                limparbuff();
            }
        }
    }

    for (int i = 0; i < 10; ++i)
    {
        if ((nums[i] % 2) == 0)
            cout << nums[i] << " e par\n";
        else
            cout << nums[i] << " e impar\n";
    }

    system("PAUSE");
    return 0;
}
