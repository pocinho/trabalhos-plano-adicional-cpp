/*
AUTOR: PAULO POCINHO
DESDE: 16-03-2017

Exercício 18: Elabore um programa que leia uma entrada e diga
quantos números perfeitos existem. Exemplo de numero perfeito
em que somando todos os divisores ele da o numero inicial.
6=3+2+1 .

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
    int divisores = 0;
    int soma_factores = 0;
	int formatador = 0;

    
    for (;;) {
        cout << "Introduza um numero inteiro positivo:\n";
        if ((cin >> numero) && (numero > 0)) {
            limparbuff();
            break;
        } else {
            cout << "Numero invalido.\n";
            limparbuff();
        }
    }

    for (int i = numero; i > 0; --i)
    {
        for (int p = 1; p < i; ++p)
        {
            if (i % p == 0)
            {
                soma_factores += p;
                divisores++;
            }
        }

        if (soma_factores == i)
        {
            cout << i << " = ";
            for (int j = i - 1; j > 0; --j)
            {
                if (i % j == 0)
                {
                    formatador++;
                    if (formatador < divisores)
                        cout << j << " + ";
                    else
                        cout << j;
                }
            }
            cout << endl;
        }
        soma_factores = 0;
        divisores = 0;
        formatador = 0;
    }

    system("PAUSE");
    return 0;
}
