#ifndef CAMPEONATO_H
#define CAMPEONATO_H
#include <string>
#include <vector>
#include <Clube.h>

using namespace std;

class Campeonato
{
private:
  string nome;
  string organizador;
  vector<Clube> clubes;
  int ano;
  Clube campeao;

public:
  Campeonato(string nome, string organizador, vector<Clube> clubes, int ano);
  Clube definirCampeao();
};

#endif