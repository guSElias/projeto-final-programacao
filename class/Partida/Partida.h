#ifndef PARTIDA_H
#define PARTIDA_H
#include <string>
#include <vector>
#include <Atleta.h>
#include <Clube.h>

using namespace std;

struct Gol
{
  int minuto;
  Atleta jogadorAutor;
  Atleta jogadorAssistencia;
};

class Partida
{
private:
  Clube timeCasa;
  Clube timeFora;
  vector<Gol> gols;

public:
  Partida(Clube mandante, Clube visitante);
  void registrarGol(int minuto, Atleta &autor, Atleta &assistencia);
};

#endif
