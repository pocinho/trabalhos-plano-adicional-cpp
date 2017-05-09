/*
AUTOR: PAULO POCINHO
DESDE: 09-03-2017

Exercício 6: Uma loja oferece para os seus clientes, um determinado
desconto de acordo com o valor da compra efetuada. O desconto é de
10%, se o valor da compra for até 200.00€, 15% se for maior que 200€ e
menor ou igual a 500,00E e 20% se for acima de 500,00€. Crie um
algoritmo que leia o nome do cliente e o valor da compra. Mostre ao
final o nome do cliente, o valor da compra, o percentual de desconto e
o seu valor e valor total a pagar deste cliente. (só fazer duas
Contas)

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
    char nome[20] = {};
    double compra = 0.0;
    double desconto = 0.0;
    double total = 0.0;

    cout << "Introduza o nome de cliente:\n";
    cin.getline(nome, sizeof(nome));
    limparbuff();
    for (;;) {
        cout << "Introduza o valor da compra:\n";
        if (cin >> compra && compra > 0.0) {
            limparbuff();
            break;
        } else {
            cout << "Numero invalido.\n";
            limparbuff();
        }
    }

    if (compra <= 200.0)
        desconto = compra * 0.1;
    else if (compra > 200.0 && compra <= 500.0)
        desconto = compra * 0.15;
    else
        desconto = compra * 0.20;

    total = compra - desconto;

    cout << "Nome de Cliente: " << nome << endl;
    cout << "Valor da compra: " << compra << endl;
    cout << "Valor do desconto: " << desconto << endl;
    cout << "Total: " << total << endl;

    system("PAUSE");
    return 0;
}
