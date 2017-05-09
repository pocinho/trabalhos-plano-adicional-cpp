/*
Autor: Paulo Pocinho
Desde: 20/04/2017

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
	int max = 0;
	int min = 0;
	int meio1 = 0;
	int meio2 = 0;

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

	max = num1;
	meio1 = num1;
	if (num2 > max)
		max = num2;
	else
		meio1 = num2;
    if (num3 > max)
		max = num3;
	else
		meio1 = num3;
	if (num4 > max)
		max = num4;
	else
		meio1 = num4;

	min = num1;
	meio2 = num1;
	if (num2 < min)
		min = num2;
	else
		meio2 == meio1 ? meio2 = num2 : 0;
    if (num3 < min)
		min = num3;
	else
		meio2 == meio1 ? meio2 = num3 : 0;
	if (num4 < min)
		min = num4;
	else
		meio2 == meio1 ? meio2 = num4 : 0;

	if (meio1 > meio2)
	{
		meio1 ^= meio2;
		meio2 ^= meio1;
		meio1 ^= meio2;
	}

    cout << "Minimo: " << min << "\nIntermedios: " << meio1 << " " << meio2 << "\nMaximo: " << max << endl;

    return 0;
}
