#ifndef ATLETA_H
#define ATLETA_H
#include <string>
#include <vector>
#include "Atleta.h"

using namespace std;
class Clube;

class Atleta
{
private:
    string nome;
    int idade;
    vector<string> posicoes;
    Clube* clubeAtual;
    vector<Clube*> clubes;
    int gols = 0;
    int assistencias = 0;
    int jogosDisputados = 0;
public:
    Atleta();
    Atleta(string nome, int idade, vector<string> posicoes);
    void transferencia(Clube* novoClube);
    void setClube(Clube* novoClube);
    void exibir();
    void registarGol();
    void registarAssistencia();
    void registarJogosDisputados();
    string getNome();
    string getPosicao();
};

#endif
