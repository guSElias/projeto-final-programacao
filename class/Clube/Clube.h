#ifndef CLUBE_H
#define CLUBE_H
#include <string>
#include <vector>
// #include "Campeonato.h"
class Atleta;
using namespace std;

class Clube
{
private:
    string nome;
    int anoFundacao;
    vector<Atleta*> elenco;
    // vector<Campeonato> titulos;

public:
    Clube();
    Clube(string nome, int anoFundacao);
    void venderAtleta(Atleta& atleta);
    void comprarAtleta(Atleta& atleta);
    void exibirElenco();
    void exibirTitulos();
    string getNome();
};

#endif
