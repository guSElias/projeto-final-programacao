#ifndef CAMPEONATO_H
#define CAMPEONATO_H
#include <string>
#include <vector>

using namespace std;
class Clube;

class Campeonato
{
private:
    string nome;
    vector<Clube*> clubesParticipantes;
    Clube* campeao = nullptr;
public:
    Campeonato();
    Campeonato(string nome, vector<Clube*> clubesParticipantes = {});
    Clube* setCampeao();
    string getNome();
};


#endif
