/*
Autor: Paulo Pocinho
Desde: 05/04/2017
*/

#include <iostream>

using namespace std;

#define MAX_BUFFER 20

int main()
{
    char buffer[MAX_BUFFER] = {};
    int dia = 0;
    int mes = 0;
    int ano = 0;

    cout << "Introduza uma data no formato dd/mm/aaaa:\n";
    cin.getline(buffer, sizeof(buffer));

    for (int i = 0; buffer[i] != '\0'; ++i)
    {
    	if (i >= 0 && i <= 1 )
    	{
    		dia *= 10;
    		dia += buffer[i] - '0';
		}
		if (i >= 3 && i <= 4)
		{
			mes *= 10;
			mes += buffer[i] - '0';
		}
		if (i >= 6 && i <= 9)
		{
			ano *= 10;
			ano += buffer[i] - '0';
		}
	}

	if (dia < 0 || dia > 31)
	{
		cout << "Data invalida.\n";
	}
	else
	{
		switch(mes)
		{
			case 1:
				cout << dia << " de Janeiro de " << ano << endl;
				break;
			case 2:
				cout << dia << " de Fevereiro de " << ano << endl;
				break;
			case 3:
				cout << dia << " de Marco de " << ano << endl;
				break;
			case 4:
				cout << dia << " de Abril de " << ano << endl;
				break;
			case 5:
				cout << dia << " de Maio de " << ano << endl;
				break;
			case 6:
				cout << dia << " de Junho de " << ano << endl;
				break;
			case 7:
				cout << dia << " de Julho de " << ano << endl;
				break;
			case 8:
				cout << dia << " de Agosto de " << ano << endl;
				break;
			case 9:
				cout << dia << " de Setembro de " << ano << endl;
				break;
			case 10:
				cout << dia << " de Outubro de " << ano << endl;
				break;
			case 11:
				cout << dia << " de Novembro de " << ano << endl;
				break;
			case 12:
				cout << dia << " de Dezembro de " << ano << endl;
				break;
			default:
				cout << "Data invalida\n";
				break;
		}
	}

    system("PAUSE");
    return 0;
}
