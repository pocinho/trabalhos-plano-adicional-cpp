/*
Autor: Paulo Pocinho
Desde: 02/05/2017

Crie um programa que suporte a entrada dos 12 meses do ano, os meses
devem ser inserido pelo utilizador.

*/

#include <iostream>

using namespace std;

#define NUM_MESES 12
#define PALAVRA_MES 10

int main()
{
    int posicao = -1;
    bool sair = false;
    char buffer[PALAVRA_MES] = {};
    char mes[NUM_MESES][PALAVRA_MES] = {
		{'j', 'a', 'n', 'e', 'i', 'r', 'o','\0','\0','\0'},
    	{'f', 'e', 'v', 'e', 'r', 'e', 'i', 'r', 'o','\0'},
    	{'m', 'a', 'r', 'c', 'o','\0','\0','\0','\0','\0'},
    	{'a', 'b', 'r', 'i', 'l','\0','\0','\0','\0','\0'},
    	{'m', 'a', 'i', 'o','\0','\0','\0','\0','\0','\0'},
    	{'j', 'u', 'n', 'h', 'o','\0','\0','\0','\0','\0'},
    	{'j', 'u', 'l', 'h', 'o','\0','\0','\0','\0','\0'},
    	{'a', 'g', 'o', 's', 't', 'o','\0','\0','\0','\0'},
    	{'s', 'e', 't', 'e', 'm', 'b', 'r', 'o','\0','\0'},
    	{'o', 'u', 't', 'u', 'b', 'r', 'o','\0','\0','\0'},
    	{'n', 'o', 'v', 'e', 'm', 'b', 'r', 'o','\0','\0'},
    	{'d', 'e', 'z', 'e', 'm', 'b', 'r', 'o','\0','\0'} };

    cout << "Introduza um mes:\n";
    cin.getline(buffer, sizeof(buffer));
    cin.clear();
    cin.sync();

    for (int m = 0; m < NUM_MESES; ++m)
    {
        if (sair == true)
            break;
        for (int i = 0; buffer[i] != '\0'; ++i)
        {
            if (buffer[i + 1] == '\0') {
                sair = true;
                break;
            }
            if (buffer[i] == mes[m][i] || buffer[i] == mes[m][i] - 32)
                posicao = m;
            else {
                posicao = -1;
                break;
            }
        }
    }

    if (posicao != -1)
    {
        cout << "O mes ";

        for (int i = 0; mes[posicao][i] != '\0'; ++i)
        {
            cout << mes[posicao][i];
        }

        cout << " corresponde ao numero " << (posicao + 1) << endl;
    }
    else
    {
        cout << "Mes \"" << buffer << "\" invalido.\n";
    }

    system("PAUSE");
    return 0;
}
