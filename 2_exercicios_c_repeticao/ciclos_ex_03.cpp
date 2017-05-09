/*
AUTOR: PAULO POCINHO
DESDE: 16-03-2017

Exercício 3: Ler a nota de 10 alunos, calcular a media e mostrar essa média.

*/

#include <iostream>
#include <limits>

using namespace std;

void limparbuff()
{
    cin.clear();
    cin.sync();
}

int main()
{
    double input = 0.0;
    double media = 0.0;

    for (int i = 1; i <= 10; ++i)
    {
        for (;;) {
            cout << "Introduza a nota do aluno " << i << ":\n";
            if (cin >> input) {
                limparbuff();
                break;
            } else {
                cout << "Nota invalida.\n";
                limparbuff();
            }
        }
        media += input;
    }

    media /= 10.0;

    cout << "A media e " << media << endl;

    system("PAUSE");
    return 0;
}