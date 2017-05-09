/*
Autor: Paulo Pocinho
Desde: 20/04/2017

*/

#include <iostream>

using namespace std;

void limpabuff()
{
    cin.clear();
    cin.sync();
}

int main()
{
    int segundos = 0;
    int minutos = 0;
    int horas = 0;

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

    cout << horas << " : " << minutos << " : " << segundos << endl;

    return 0;
}
