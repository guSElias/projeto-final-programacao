#include <iostream>
#include <string>

#include "CriarDados/criarDados.h"

using namespace std;

Campeonato superMundial = criarCampeonato();

void menu()
{
    int opcao;

    do
    {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Cadastrar item\n";
        cout << "2. Listar itens\n";
        cout << "3. Pesquisar item\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Você escolheu CADASTRAR.\n";
            // código da opção 1
            break;

        case 2:
            cout << "Você escolheu LISTAR.\n";
            // código da opção 2
            break;

        case 3:
            cout << "Você escolheu PESQUISAR.\n";
            // código da opção 3
            break;

        case 4:
            cout << "Saindo...\n";
            break;

        default:
            cout << "Opcao inválida! Tente novamente.\n";
        }
    }
    while (opcao > 0);
}

int main()
{
    menu();
    return 0;
}
