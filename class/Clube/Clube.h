#ifndef CLUBE_H
#define CLUBE_H
#include <string>
#include <vector>
#include <Atleta.h>
#include <Campeonato.h>

using namespace std;

class Clube
{
private:
  string nome;
  int anoFundacao;
  vector<Atleta> jogadores;
  vector<Campeonato> titulos;
  vector<Campeonato> titulos;

public:
  Clube(string nome, int anoFundacao, vector<Atleta> jogadores);
  void venderAtleta(Atleta atleta);
  void comprarAtleta(Atleta atleta);
};
#endif