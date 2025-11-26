#include "Campeonato.h"

#include <iostream>

#include "Clube.h"

using namespace std;

Campeonato::Campeonato()
{
    this->nome = "Campeonato";
    this->clubesParticipantes = {};
}

Campeonato::Campeonato(string nome, vector<Clube*> clubesParticipantes = {})
{
    this->nome = nome;
    this->clubesParticipantes = clubesParticipantes;
}

string Campeonato::getNome()
{
    return this->nome;
}

void Campeonato::setCampeao(Clube* c)
{
    this->campeao = c;
    string campeao = c->getNome();
    cout << "Campeao: " << campeao << endl;
}
