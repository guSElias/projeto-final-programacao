#include "Partida.h"
#include <iostream>

#include "Atleta.h"
using namespace std;

int golsTimeCasa;
int golsTimeFora;

Partida::Partida()
{
    this->campeonato = nullptr;
    this->timeCasa = "time casa";
    this->timeFora = "time visitante";
}

Partida::Partida(Campeonato* c, string timeCasa, string timeFora)
{
    this->campeonato = c;
    this->timeCasa = timeCasa;
    this->timeFora = timeFora;
}

bool Partida::validarTimeGol(string timeGol)
{
    return timeGol == this->timeCasa || timeGol == this->timeFora;
}

void Partida::registrarGol(int minuto, string timeGol, Atleta* autor, Atleta* assistencia = nullptr)
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
