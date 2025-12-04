#include "Clube.h"
#include <iostream>
#include <algorithm>

#include "../Campeonato/Campeonato.h"
#include "../Atleta/Atleta.h"

using namespace std;

Clube::Clube()
{
    this->nome = "Indefinido";
    this->anoFundacao = 0;
    this->elenco = {};
    this->titulos = {};
}

Clube::Clube(string n, int af)
{
    this->nome = n;
    this->anoFundacao = af;
}

void Clube::venderAtleta(Atleta* atleta)
{
    elenco.erase(
        remove(elenco.begin(), elenco.end(), atleta),
        elenco.end()
    );
}


void Clube::comprarAtleta(Atleta* atleta)
{
    elenco.push_back(atleta);
    atleta->setClube(this);
}


void Clube::exibirElenco()
{
    cout << "\n--- Elenco do " << this->nome << " ---\n";

    if (elenco.empty())
    {
        cout << "Nenhum atleta cadastrado.\n";
        return;
    }

    for (int i = 0; i < elenco.size(); i++)
    {
        cout << "- " << elenco[i]->getNome() << ": " << elenco[i]->getPosicao() << "\n";
    }
}

void Clube::adicionarTitulo(Campeonato* t)
{
    this->titulos.push_back(t);
}

void Clube::exibirTitulos()
{
    cout << "\n--- Titulos do Clube ---\n";

    if (this->titulos.empty())
    {
        cout << "Nenhum titulo cadastrado.\n";
        return;
    }
    for (auto& titulo : titulos)
    {
        cout << "- " << titulo->getNome() << "\n";
    }
}

string Clube::getNome()
{
    return this->nome;
}

vector<Atleta*> Clube::getElenco()
{
    return elenco;
}
