/*
AUTOR: PAULO POCINHO
DESDE: 09-03-2017

Exercício 4: Fazer um algoritmo que leia o saldo inicial de cliente do banco e
leia também um cheque que entrou e ANALISE se o cheque poderá ser descontado
ou não, já que este cliente não possui limite. Se o cheque não poderá ser
descontado, mostre essa informação, caso contrário, desconte o cheque e
informe o saldo.

*/

#include <iostream>

using namespace std;

int main()
{
    int saldo = 0;
    int cheque = 0;

    for (;;)
    {
        cout << "Introduza o saldo inicial:\n";
        if (cin >> saldo)
            break;
        else
        {
            cout << "Numero invalido.\n";
        }
    }

    for (;;)
    {
        cout << "Introduza o montante do cheque:\n";
        if (cin >> cheque)
            break;
        else
        {
            cout << "Numero invalido.\n";
        }
    }

    if (cheque > saldo)
    {
        cout << "O cheque no valor de " << cheque << " não pode ser descontado.\n";
        cout << "A conta tem o valor de " << saldo << endl;
    }
    else
    {
        saldo -= cheque;
        cout << "O cheque no valor de " << cheque << " foi descontado.\n";
        cout << "A conta tem o valor de " << saldo << endl;
    }

    system("PAUSE");
    return 0;
}
