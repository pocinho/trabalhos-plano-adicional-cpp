/*
Autor: Paulo Pocinho
Desde: 20/04/2017

Ordenação de quatro numeros com bubblesort hardcoded.
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
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    int num4 = 0;

    for (;;) {
        cout << "Introd primeiro numero: ";
        if (cin >> num1) {
            limpabuff();
            break;
        } else {
            limpabuff();
            cout << "tens os dedos gordos\n";
        }
    }

    for (;;) {
        cout << "Introd segundo numero: ";
        if (cin >> num2) {
            limpabuff();
            break;
        } else {
            limpabuff();
            cout << "tens os dedos gordos\n";
        }
    }

    for (;;) {
        cout << "Introd terceiro numero: ";
        if (cin >> num3) {
            limpabuff();
            break;
        } else {
            limpabuff();
            cout << "tens os dedos gordos\n";
        }
    }

    for (;;) {
        cout << "Introd quarto numero: ";
        if (cin >> num4) {
            limpabuff();
            break;
        } else {
            limpabuff();
            cout << "tens os dedos gordos\n";
        }
    }

	// bubblesort hardcoded

	// a b
	if (num1 > num2)
	{
		num1 ^= num2;
		num2 ^= num1;
		num1 ^= num2;
	}

	// c d
	if (num3 > num4)
	{
		num3 ^= num4;
		num4 ^= num3;
		num3 ^= num4;
	}

	// a c
	if (num1 > num3)
	{
		num1 ^= num3;
		num3 ^= num1;
		num1 ^= num3;
	}

	// b d
	if (num2 > num4)
	{
		num2 ^= num4;
		num4 ^= num2;
		num2 ^= num4;
	}

	// b c
	if (num2 > num3)
	{
		num2 ^= num3;
		num3 ^= num2;
		num2 ^= num3;
	}

    cout << "Minimo: " << num1 << "\nIntermedios: " << num2 << " " << num3 << "\nMaximo: " << num4 << endl;

    return 0;
}
