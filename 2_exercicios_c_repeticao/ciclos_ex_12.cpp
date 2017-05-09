/*
AUTOR: PAULO POCINHO
DESDE: 16-03-2017

Exercício 12: Elabore um programa que leia quantos números quer que se efetue
a soma, subtrações, divisões, multiplicações e no fim por meio de um
acumulador diga quantas operações foram efetuadas. Exemplo: introduzindo o
número 60 o programa deve apresentar 60 a somar, dividir multiplicar e
subtrair por todos os números menores que ele.

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
    double conta = 0.0;
    int operacoes = 0;

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

    cout << numero << " a somar por todos os numeros abaixo dele: ";
    conta = numero;
    for (int i = 1; i < numero; ++i)
    {
        conta += i;
        operacoes++;
    }
    cout << conta << endl;

    cout << numero << " a subtrair por todos os numeros abaixo dele: ";
    conta = numero;
    for (int i = 1; i < numero; ++i)
    {
        conta -= i;
        operacoes++;
    }
    cout << conta << endl;

    cout << numero << " a multiplicar por todos os numeros abaixo dele: ";
    conta = numero;
    for (int i = 1; i < numero; ++i)
    {
        conta *= i;
        operacoes++;
    }
    cout << conta << endl;

    cout << numero << " a dividir por todos os numeros abaixo dele: ";
    conta = numero;
    for (int i = 1; i < numero; ++i)
    {
        conta /= i;
        operacoes++;
    }
    cout << conta << endl;

    cout << "Foram efectuadas " << operacoes << " operacoes.\n";

    system("PAUSE");
    return 0;
}
