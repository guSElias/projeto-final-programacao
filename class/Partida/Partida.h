#ifndef PARTIDA_H
#define PARTIDA_H

#include <string>
#include <vector>

#include "Clube.h"

using namespace std;

class Campeonato;
class Atleta;

// Estrutura que representa um gol da partida
struct Gol
{
    int minuto;
    string timeGol;
    Atleta* jogadorAutor;
    Atleta* jogadorAssistencia;
};

class Partida
{
private:
    Campeonato* campeonato;
    string timeCasa;
    string timeFora;
    vector<Gol> gols = {};

public:
    Partida();
    Partida(Campeonato* c, string timeCasa, string timeFora);
    bool validarTimeGol(string timeGol);
    void registrarGol(int minuto, string timeGol, Atleta* autor, Atleta* assistencia);
    void placarFinal();
};

#endif
