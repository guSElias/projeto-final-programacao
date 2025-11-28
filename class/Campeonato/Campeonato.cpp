#include "Campeonato.h"

#include <iostream>

#include "Clube.h"

using namespace std;

Campeonato::Campeonato()
{
    this->nome = "Campeonato";
    this->clubesParticipantes = {};
}

Campeonato::Campeonato(string nome)
{
    this->nome = nome;
}

string Campeonato::getNome()
{
    return this->nome;
}

void Campeonato::exibirClubes()
{
    cout << "Clubes participando do campeonato:" << endl;
    for (int i = 0; i < this->clubesParticipantes.size(); i++)
    {
        cout << this->clubesParticipantes[i] << endl;
    }
}

void Campeonato::inserirTodosTimes(vector<Clube*> c)
{
    this->clubesParticipantes = c;
}

void Campeonato::setCampeao(Clube* c)
{
    this->campeao = c;
    string campeao = c->getNome();
    cout << "Campeao: " << campeao << endl;
}

void Campeonato::inserirUmClube(Clube* c)
{
    this->clubesParticipantes.push_back(c);
}
