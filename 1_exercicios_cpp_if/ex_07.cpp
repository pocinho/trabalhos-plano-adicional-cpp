/*
AUTOR: PAULO POCINHO
DESDE: 09-03-2017

Exercício 7: O sistema de avaliação de determinada disciplina, é
composto por três provas Nota (0 a 10). A primeira prova tem peso 2, a
Segunda tem peso 3 e a terceira prova tem peso 5. Faça um algoritmo
para calcular a média final de um aluno desta disciplina e se a media
for maior ou igual a 6, mostrar APROVADO, senão, mostrar REPROVADO.

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
    double prova1 = 0.0;
    double prova2 = 0.0;
    double prova3 = 0.0;
    double media = 0.0;

    for (;;)
    {
        cout << "Introduza a nota da primeira prova (0-10):\n";
        if (cin >> prova1 && prova1 >= 0 && prova1 <= 10) {
            limparbuff();
            break;
        } else {
            cout << "Numero invalido.\n";
            limparbuff();
        }
    }

    for (;;)
    {
        cout << "Introduza a nota da segunda prova (0-10):\n";
        if (cin >> prova2 && prova2 >= 0 && prova2 <= 10) {
            limparbuff();
            break;
        } else {
            cout << "Numero invalido.\n";
            limparbuff();
        }
    }

    for (;;)
    {
        cout << "Introduza a nota da terceira prova (0-10):\n";
        if (cin >> prova3 && prova3 >= 0 && prova3 <= 10) {
            limparbuff();
            break;
        } else {
            cout << "Numero invalido.\n";
            limparbuff();
        }
    }

    media = (prova1 * 0.2) + (prova2 * 0.3) + (prova3 * 0.5);
    cout << "Media: " << media << endl;

    if (media >= 6.0)
       cout << "APROVADO\n";
    else
       cout << "REPROVADO\n";

    system("PAUSE");
    return 0;
}
