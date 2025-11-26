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
public:
    Atleta();
    Atleta(string nome, int idade, vector<string> posicoes);
    void transferencia(Clube*& novoClube);
    void exibir();
    void registarGol();
    void registarAssistencia();
    string getNome();
};

#endif
