#include <iostream>
#include <string>

#include "CriarDados/criarDados.h"

using namespace std;
vector<Clube*> clubes;

int main()
{
    clubes = criarInstanciasClubesTitularesTodos();
    for (int i = 0; i < clubes.size(); i++)
    {
        clubes[i]->exibirElenco();
    }
}