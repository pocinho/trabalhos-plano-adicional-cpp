/*
AUTOR: PAULO POCINHO
DESDE: 16-03-2017

Exercícios 15: Elabore um programa que escreva no ecrã
todas as linhas de código ASCII(0 a 255) e o código
correspondente. Dispor de 20 em 20 com a condição de
continuação ou saída do programa.

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
    int opcao = 0;

    for (int i = 1; i <= 255; ++i)
    {
        cout << (char)i << " - representado em decimal: " << i << endl;
        if (i % 20 == 0)
        {
            do
            {
                cout << "Prima 0 para sair ou 1 para continuar:\n";
                cin >> opcao;
                limparbuff();
            }
            while (opcao < 0 || opcao > 1);
            if (opcao == 0)
                break;
        }
    }

    system("PAUSE");
    return 0;
}
