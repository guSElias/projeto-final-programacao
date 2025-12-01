#include "Clube.h"
#include <iostream>
#include <algorithm>

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

void Clube::venderAtleta(Atleta& atleta)
{
    elenco.erase(
        remove(elenco.begin(), elenco.end(), &atleta),
        elenco.end()
    );
}


void Clube::comprarAtleta(Atleta& atleta)
{
    elenco.push_back(&atleta);
}


void Clube::exibirElenco()
{
    cout << "\n--- Elenco do " << this->nome << " ---\n";

    if (elenco.empty())
    {
        cout << "Nenhum atleta cadastrado.\n";
        return;
    }

    for (auto& atleta : elenco)
    {
        cout << "- " << atleta->getNome() << "\n";
    }
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
        cout << "- " << titulo << "\n";
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
