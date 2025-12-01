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
    Campeonato(string nome);
    void setCampeao(Clube* c);
    void inserirUmClube(Clube* c);
    vector<Clube*> getClubes();
    string getNome();
    void exibirClubes();
    void inserirTodosTimes(vector<Clube*> c);
    string getCampeao();
};


#endif
