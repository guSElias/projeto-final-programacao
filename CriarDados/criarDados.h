#ifndef CRIARDADOS_H
#define CRIARDADOS_H

#include "../class/Clube/Clube.h"
#include "../class/Campeonato/Campeonato.h"
#include <string>

using namespace std;

vector<Clube*> criarInstanciasClubesTitularesTodos();
Campeonato criarCampeonato();

#endif