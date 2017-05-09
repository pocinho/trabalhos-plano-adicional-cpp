/*
AUTOR: PAULO POCINHO
DESDE: 09-03-2017

Prova de Avaliação: Crie um programa que leia a nota de 10 alunos,
calcule a média e mostre essa média e mostre também quantos alunos
ficaram com a sua nota igual ou acima da média. (NOTAS de 0 a20).

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
    double notas[10] = {};
    double media = 0.0;
    int alunos_acima = 0;

    for (int i = 0; i < 10; ++i)
    {
        for (;;) {
            cout << "Introduza a nota para o aluno " << (i+1) << " (0-20):\n";
            if (cin >> notas[i] && notas[i] >= 0 && notas[i] <= 20) {
                limparbuff();
                break;
            } else {
                cout << "Numero invalido.\n";
                limparbuff();
            }
        }        
        media += notas[i];
    }

    media /= 10;

    for (int i = 0; i < 10; ++i)
    {
        if (notas[i] >= media)
           alunos_acima++;
    }

    cout << "Media: " << media << endl;
    cout << "Alunos com nota igual ou superior a media: " << alunos_acima << endl;

    system("PAUSE");
    return 0;
}
