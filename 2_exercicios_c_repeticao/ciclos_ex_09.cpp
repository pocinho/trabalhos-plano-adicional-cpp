/*
AUTOR: PAULO POCINHO
DESDE: 16-03-2017

Exercício 9: Escreva um programa que solicite um número
ao utilizador até que o valor deste esteja entre os valores 1 e 100.
 (Use o ciclo do ... while)

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

    do
    {
        cout << "Introduza um numero de 1 a 100\n";
        cin >> numero;
        limparbuff();
    }
    while (numero < 1 || numero > 100);

    system("PAUSE");
    return 0;
}
