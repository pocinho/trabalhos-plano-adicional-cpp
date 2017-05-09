/*
Autor: Paulo Pocinho
Desde: 30/03/2017
*/

#include <iostream>

using namespace std;

int main()
{
	int a[2][3] = { 0, 2, 4,
		            1, 1, 3 };

	int b[3][2] = { 1, 5,
		            6, 2,
		            3, 4 };

	int axb[2][2] = { 24, 20,
		              16, 19 };

	int r[2][2] = {};

	for (int c = 0; c < 2; ++c)
	{
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				r[c][i] += a[c][j] * b[j][i];
			}
		}
	}


	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			cout << r[i][j] << " ";
		}
		cout << endl;
	}

	system("PAUSE");
	return 0;
}
