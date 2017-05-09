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
    int num1 = 0;
    int num2 = 0;

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

    num1 ^= num2;
    num2 ^= num1;
    num1 ^= num2;

    cout << "primeira variavel: " << num1 << endl;
    cout << "segunda variavel: " << num2 << endl;

    return 0;
}
