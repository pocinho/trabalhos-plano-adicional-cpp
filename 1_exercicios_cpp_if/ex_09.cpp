/*
AUTOR: PAULO POCINHO
DESDE: 09-03-2017

Exercício switch: Ler para uma variável INTEIRA um número de 1 a 12 e
mostrar o nome do mês correspondente. Caso o mês não existir, mostrar
essa informação.

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
    int mes = 0;
    
    for (;;) {
        cout << "Introduza o numero do mes:\n";
        if (cin >> mes) {
            limparbuff();
            break;
        } else {
            cout << "Numero invalido.\n";
            limparbuff();
        }
    }

    switch(mes)
    {
        case 1:
             cout << "Janeiro\n";
             break;
        case 2:
             cout << "Fevereiro\n";
             break;
        case 3:
             cout << "Marco\n";
             break;
        case 4:
             cout << "Abril\n";
             break;
        case 5:
             cout << "Maio\n";
             break;
        case 6:
             cout << "Junho\n";
             break;
        case 7:
             cout << "Julho\n";
             break;
        case 8:
             cout << "Agosto\n";
             break;
        case 9:
             cout << "Setembro\n";
             break;
        case 10:
             cout << "Outubro\n";
             break;
        case 11:
             cout << "Novembro\n";
             break;
        case 12:
             cout << "Dezembro\n";
             break;
        default:
            cout << "Nao existe mes " << mes << endl;
            break;
    }

    system("PAUSE");
    return 0;
}
