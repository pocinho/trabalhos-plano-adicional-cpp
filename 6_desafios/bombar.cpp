/*
Autor: Paulo Pocinho
Desde: 07/04/2017
*/

#include <iostream>

struct j {
	char estado[20] = "Weeeeeee";
};

typedef j JOAO;

void likaboss(char * in, char * out);

int main() {
	char bombar[20] = "Joao a bombar.";
	JOAO joao;
	std::cout << joao.estado << std::endl;
	likaboss(bombar, joao.estado);
	std::cout << joao.estado << std::endl;
	system("PAUSE");
	return 0;
}

void likaboss(char * in, char * out) {
	for (int i = 0; *in != '\0'; ++i) {
		*out = *in;
		*in++;
		if (*in == '\0') {
			*out++;
			*out = '\0';
		}
		*out++;
	}
}
