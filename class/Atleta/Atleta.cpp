#include "Atleta.h"
#include <iostream>
#include "../Clube/Clube.h"

using namespace std;

Atleta::Atleta()
{
    this->nome = "Não identificado";
    this->idade = 0;
    this->posicoes = {};
}

Atleta::Atleta(string n, int i, vector<string> p)
{
    this->nome = n;
    this->idade = i;
    this->posicoes = p;
}

// remove do clube atual, adiciona ao novo e altera o clube atual
void Atleta::transferencia(Clube* novoClube)
{
    clubeAtual->venderAtleta(this);
    novoClube->comprarAtleta(this);
    clubes.push_back(novoClube);
    clubeAtual = novoClube;
};

void Atleta::setClube(Clube* novoClube)
{
    clubeAtual = novoClube;
}

void Atleta::exibir()
{
    cout << "=== Informações do Atleta ===\n";

    cout << "Nome: " << this->nome << "\n";
    cout << "Idade: " << this->idade << "\n";

    // Exibir posições
    cout << "Posições: ";
    for (auto& p : this->posicoes)
    {
        cout << p << " ";
    }
    cout << "\n";

    cout << "Clube atual: " << this->clubeAtual->getNome() << "\n";

    // Histórico de clubes
    cout << "Clubes anteriores: ";
    if (this->clubes.empty())
    {
        cout << "Nenhum";
    }
    else
    {
        for (auto& c : this->clubes)
        {
            cout << c->getNome() << " ";
        }
    }
    cout << "\n\n";
};

void Atleta::registarGol()
{
    this->gols += 1;
}

void Atleta::registarAssistencia()
{
    this->assistencias += 1;
}

string Atleta::getNome()
{
    return this->nome;
}

void Atleta::registarJogosDisputados()
{
    this->jogosDisputados += 1;
}
