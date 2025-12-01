#include "Partida.h"
#include <iostream>

#include "../Atleta/Atleta.h"
using namespace std;

int golsTimeCasa;
int golsTimeFora;

Partida::Partida()
{
    this->campeonato = nullptr;
    this->timeCasa = nullptr;
    this->timeFora = nullptr;
}

Partida::Partida(Campeonato* c, Clube* timeCasa, Clube* timeFora)
{
    this->campeonato = c;
    this->timeCasa = timeCasa;
    this->timeFora = timeFora;
    registrarPartida(timeCasa);
    registrarPartida(timeFora);
}

bool Partida::validarTimeGol(Clube* timeGol)
{
    return timeGol == this->timeCasa || timeGol == this->timeFora;
}

void Partida::registrarGol(int minuto, Clube* timeGol, Atleta* autor, Atleta* assistencia = nullptr)
{
    if (this->validarTimeGol(timeGol))
    {
        gols.push_back(Gol{minuto, timeGol, autor, assistencia});
        autor->registarGol();
        if (assistencia != nullptr)
        {
            assistencia->registarAssistencia();
        }
    }
    else
    {
        cout << "O time inserido não está disputando esta partida." << endl;
    }
}

void Partida::placarFinal()
{
    for (int i = 0; i < gols.size(); i++)
    {
        if (gols[i].timeGol == this->timeCasa)
        {
            golsTimeCasa += 1;
        }
        else if (gols[i].timeGol == this->timeFora)
        {
            golsTimeFora += 1;
        }
    }
    cout << "Placar final: "
        << timeCasa << " " << golsTimeCasa
        << " x "
        << golsTimeFora << " " << timeFora
        << endl;
}

void Partida::registrarPartida(Clube* c)
{
    vector<Atleta*> elenco = c->getElenco();
    for (int i = 0; i < elenco.size(); i++)
    {
        elenco[i]->registarJogosDisputados();
    }
}
