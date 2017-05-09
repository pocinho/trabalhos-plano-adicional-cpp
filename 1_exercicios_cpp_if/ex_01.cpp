/*
AUTOR: PAULO POCINHO
DESDE: 09-03-2017

Exercício 1: Desenvolva um programa que assuma uma entrada em Segundos
e transforme em Horas, Minutos e Segundos.

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
    int horas = 0;
    int minutos = 0;
    int segundos = 0;

    for (;;)
    {
        cout << "Introduza os segundos:\n";
        if (cin >> segundos)
        {
            limparbuff();
            break;
        }
        else
        {
            cout << "Numero invalido.\n";
            limparbuff();
        }
    }

    minutos = segundos / 60;
    horas = minutos / 60;

    minutos %= 60;
    segundos %= 60;

    cout << horas << ":" << minutos << ":" << segundos << endl;

    system("PAUSE");
    return 0;
}
