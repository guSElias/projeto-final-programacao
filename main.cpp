#include <iostream>
#include <string>
#include <limits>

#include "class/Atleta/Atleta.h"
#include "CriarDados/criarDados.h"

using namespace std;

Campeonato superMundial = criarCampeonato();
vector<Clube*> clubes = superMundial.getClubes();

Clube* buscarClube(string nome)
{
    for (int i = 0; i < clubes.size(); i++)
    {
        if (clubes[i]->getNome() == nome)
        {
            return clubes[i];
        }
    }
    return nullptr;
}

void adicionarCampeao()
{
    Clube* chelsea = buscarClube("Chelsea");
    superMundial.setCampeao(chelsea);
}

Atleta* buscarAtleta(string nome)
{
    for (int i = 0; i < clubes.size(); i++)
    {
        vector<Atleta*> atletas = clubes[i]->getElenco();
        for (int j = 0; j < atletas.size(); j++)
        {
            if (atletas[j]->getNome() == nome)
            {
                return atletas[j];
            }
        }
    }
    return nullptr;
}


void menu(int opcao)
{
    switch (opcao)
    {
    case 1:
        {
            string nome;
            int anoFundacao;

            cout << "====Cadastro de Clube====\n";

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Digite o nome do Clube: ";
            getline(cin, nome);

            cout << "Digite o ano de fundação: ";
            cin >> anoFundacao;

            Clube* novoClube = new Clube(nome, anoFundacao);
            cout << "Novo clube criado: " << novoClube->getNome() << endl;
            clubes.push_back(novoClube);
            break;
        }

    case 2:
        {
            string nome;
            int idade;
            string posicao;
            vector<string> posicoes;
            int opcao;

            cout << "====Cadastro de Atleta====\n";

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Digite o nome do Atleta: ";
            getline(cin, nome);

            cout << "Digite a idade do atleta: ";
            cin >> idade;

            // Limpar o buffer após ler um int e antes de ler string (getline)
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            do
            {
                cout << "Digite a posicao do atleta: ";
                getline(cin, posicao);
                posicoes.push_back(posicao);

                cout << "Deseja inserir uma outra posição(1- Sim/ 2- Não): ";
                // Ler a opção do usuário
                cin >> opcao;

                // Limpar o buffer novamente para o próximo loop do getline funcionar
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            while (opcao == 1);

            Atleta* novoAtleta = new Atleta(nome, idade, posicoes);
            cout << "Novo atleta criado: " << novoAtleta->getNome() << endl;

            cout << "Deseja inserir o atleta à um clube?(1- Sim/ 2- Não)" << endl;
            cin >> opcao;
            if (opcao == 1)
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Digite o nome do Clube: " << endl;
                getline(cin, nome);

                Clube* c = buscarClube(nome);
                if (c != nullptr)
                {
                    c->comprarAtleta(novoAtleta);
                }
                else
                {
                    cout << "Clube não encontrado!" << endl;
                }
            }
        }
        break;

    case 3:
        {
            string nome;
            cout << "====Exibir títulos do Clube====\n";

            // limpar buffer antes do getline
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Digite o nome do Clube: " << endl;
            getline(cin, nome);

            Clube* c = buscarClube(nome);
            if (c != nullptr)
            {
                cout << "Exibindo o clube: " << c->getNome() << endl;
                c->exibirTitulos();
            }
            else
            {
                cout << "Clube não encontrado!" << endl;
            }
            break;
        }

    case 4:
        {
            string nome;
            cout << "====Exibir jogador====\n";

            // limpar buffer antes do getline
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Digite o nome do jogador: ";
            getline(cin, nome);

            Atleta* a = buscarAtleta(nome);
            if (a != nullptr)
                a->exibir();
            else
                cout << "Atleta não encontrado!" << endl;

            break;
        }

    case 5:
        cout << "====Exibir Campeonato===\n";
        superMundial.exibirClubes();
        cout << "\nCampeão: " << superMundial.getCampeao() << endl;
        break;

    case 0:
        cout << "Saindo...\n";
        break;

    default:
        cout << "Opcao inválida! Tente novamente.\n";
    }
}

int main()
{
    adicionarCampeao();
    int opcao;

    do
    {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Cadastrar clube\n";
        cout << "2. Cadastrar jogador\n";
        cout << "3. Exibir clube\n";
        cout << "4. Exibir jogador\n";
        cout << "5. Exibir campeonato\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        menu(opcao);
    }
    while (opcao > 0);

    return 0;
}
