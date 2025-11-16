#ifndef ATLETA_H
#define ATLETA_H
#include <string>
#include <vector>
#include "Clube.h"

using namespace std;

class Atleta
{
private:
  string nome;
  vector<string> posicoes;
  int idade;
  Clube clubeAtual;
  vector<Clube> clubes;

public:
  Atleta(string nome, vector<string> posicoes, int idade);
  void transferencia(Clube novoClube);
};

#endif