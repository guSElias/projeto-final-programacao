#ifndef PARTIDA_H
#define PARTIDA_H

#include <string>
#include <vector>

#include "../Clube/Clube.h"

using namespace std;

class Campeonato;
class Atleta;

struct Gol
{
    int minuto;
    Clube* timeGol;
    Atleta* jogadorAutor;
    Atleta* jogadorAssistencia;
};

class Partida
{
private:
    Campeonato* campeonato;
    Clube* timeCasa;
    Clube* timeFora;
    vector<Gol> gols = {};

public:
    Partida();
    Partida(Campeonato* c, Clube* timeCasa, Clube* timeFora);
    bool validarTimeGol(Clube* timeGol);
    void registrarGol(int minuto, Clube* timeGol, Atleta* autor, Atleta* assistencia);
    void placarFinal();
    void registrarPartida(Clube* clube);
};

#endif
