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
  int idade;
  vector<string> posicoes;
  Clube clubeAtual;
  vector<Clube> clubes;

public:
  Atleta();
  Atleta(string nome, int idade, vector<string> posicoes);
  void transferencia(Clube &novoClube);
  void exibir();
  string getNome();
};

#endif