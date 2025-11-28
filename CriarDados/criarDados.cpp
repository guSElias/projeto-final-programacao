#include <iostream>
#include <map>
#include <ostream>
#include <string>
#include <utility>
#include <vector>

#include "../class/Campeonato/Campeonato.h"
#include "../class/Atleta/Atleta.h"
#include "../class/Clube/Clube.h"
using namespace std;

// --- ESTRUTURAS DE DADOS ---

struct DadosAtleta
{
    string nome;
    int idade;
    vector<string> posicoes;
};

vector<Clube*> criarInstanciasClubesTitularesTodos()
{
    // Mapa que contém os dados dos titulares de TODOS os 16 clubes
    map<string, vector<DadosAtleta>> elencosTitulares = {
        // 🇧🇷 PALMEIRAS (Já criado)
        {
            "Palmeiras", {
                {"Weverton", 37, {"Goleiro"}}, {"Agustín Giay", 21, {"Lateral Direito"}},
                {"Gustavo Gómez", 32, {"Zagueiro"}}, {"Murilo", 28, {"Zagueiro"}},
                {"Joaquín Piquerez", 27, {"Lateral Esquerdo"}}, {"Aníbal Moreno", 29, {"Volante"}},
                {"Lucas Evangelista", 30, {"Meio-campista"}}, {"Raphael Veiga", 30, {"Meia Ofensivo"}},
                {"Estêvão", 18, {"Ponta Direita"}}, {"Paulinho", 35, {"Ponta Esquerda"}},
                {"Vitor Roque", 20, {"Centroavante"}}
            }
        },

        // 🇪🇸 REAL MADRID (Já criado)
        {
            "Real Madrid", {
                {"Thibaut Courtois", 33, {"Goleiro"}}, {"Dani Carvajal", 33, {"Lateral Direito"}},
                {"Éder Militão", 27, {"Zagueiro"}}, {"David Alaba", 33, {"Zagueiro"}},
                {"Ferland Mendy", 30, {"Lateral Esquerdo"}}, {"Aurélien Tchouaméni", 25, {"Volante"}},
                {"Eduardo Camavinga", 22, {"Meia Central"}}, {"Fede Valverde", 26, {"Meia Central"}},
                {"Rodrygo", 24, {"Ponta Direita"}}, {"Kylian Mbappé", 26, {"Centroavante"}},
                {"Vinícius Júnior", 25, {"Ponta Esquerda"}}
            }
        },

        // 🏴󠁧󠁢󠁥󠁮󠁧󠁿 MANCHESTER CITY (Já criado)
        {
            "Manchester City", {
                {"Ederson", 31, {"Goleiro"}}, {"Kyle Walker", 35, {"Lateral Direito"}},
                {"Rúben Dias", 28, {"Zagueiro"}},
                {"J. Stones", 31, {"Zagueiro"}}, {"Joško Gvardiol", 23, {"Lateral Esquerdo"}},
                {"Rodri", 29, {"Volante"}},
                {"Kovacic", 31, {"Meia Central"}}, {"Phil Foden", 25, {"Ponta Esquerda"}},
                {"Kevin De Bruyne", 34, {"Meia Ofensivo"}}, {"Bernardo Silva", 30, {"Ponta Direita"}},
                {"Erling Haaland", 25, {"Centroavante"}}
            }
        },

        // 🇩🇪 BAYERN DE MUNIQUE (Já criado)
        {
            "Bayern de Munique", {
                {"Manuel Neuer", 39, {"Goleiro"}}, {"Joshua Kimmich", 30, {"Lateral Direito"}},
                {"Matthijs de Ligt", 25, {"Zagueiro"}}, {"Dayot Upamecano", 26, {"Zagueiro"}},
                {"Alphonso Davies", 24, {"Lateral Esquerdo"}}, {"Jamal Musiala", 22, {"Meia Central"}},
                {"Konrad Laimer", 28, {"Volante"}}, {"Leroy Sané", 29, {"Ponta Direita"}},
                {"Florian Wirtz", 22, {"Meia Ofensivo"}}, {"Serge Gnabry", 30, {"Ponta Esquerda"}},
                {"Harry Kane", 31, {"Centroavante"}}
            }
        },

        // 🇧🇷 FLAMENGO (Já criado)
        {
            "Flamengo", {
                {"Agustín Rossi", 29, {"Goleiro"}}, {"Guillermo Varela", 32, {"Lateral Direito"}},
                {"Léo Pereira", 29, {"Zagueiro"}}, {"Fabrício Bruno", 29, {"Zagueiro"}},
                {"Ayrton Lucas", 27, {"Lateral Esquerdo"}}, {"Erick Pulgar", 31, {"Volante"}},
                {"Gerson", 28, {"Meia Central"}}, {"De Arrascaeta", 31, {"Meia Ofensivo"}},
                {"Nicolás de la Cruz", 28, {"Ponta Direita"}}, {"Bruno Henrique", 34, {"Ponta Esquerda"}},
                {"Pedro", 28, {"Centroavante"}}
            }
        },

        // 🇧🇷 FLUMINENSE (Já criado)
        {
            "Fluminense", {
                {"Fábio", 45, {"Goleiro"}}, {"Samuel Xavier", 35, {"Lateral Direito"}},
                {"Felipe Melo", 42, {"Zagueiro"}},
                {"Manoel", 35, {"Zagueiro"}}, {"Marcelo", 37, {"Lateral Esquerdo"}}, {"André", 24, {"Volante"}},
                {"Martinelli", 24, {"Volante"}}, {"Keno", 36, {"Ponta Esquerda"}}, {"Ganso", 36, {"Meia Armador"}},
                {"Jhon Arias", 28, {"Ponta Direita"}}, {"Germán Cano", 37, {"Centroavante"}}
            }
        },

        // 🇧🇷 BOTAFOGO
        {
            "Botafogo", {
                {"John", 29, {"Goleiro"}},
                {"Vitinho", 26, {"Lateral Direito"}},
                {"Alexander Barboza", 30, {"Zagueiro"}},
                {"Kaio Pantaleão", 30, {"Zagueiro"}},
                {"Alex Telles", 32, {"Lateral Esquerdo"}},
                {"Gregore", 31, {"Volante"}},
                {"Marlon Freitas", 30, {"Meia Central"}},
                {"Allan", 34, {"Volante"}},
                {"Artur", 27, {"Ponta Direita"}},
                {"Joaquín Correa", 31, {"Segundo Atacante"}},
                {"Arthur Cabral", 27, {"Centroavante"}}
            }
        },

        // 🇮🇹 INTER DE MILÃO (Já criado)
        {
            "Inter de Milão", {
                {"Yann Sommer", 36, {"Goleiro"}}, {"B. Pavard", 29, {"Zagueiro"}}, {"F. Acerbi", 37, {"Zagueiro"}},
                {"Alessandro Bastoni", 26, {"Zagueiro"}}, {"Denzel Dumfries", 29, {"Ala Direito"}},
                {"Nicolò Barella", 28, {"Meia Central"}}, {"Hakan Çalhanoğlu", 31, {"Volante"}},
                {"H. Mkhitaryan", 36, {"Meia Ofensivo"}}, {"Federico Dimarco", 27, {"Ala Esquerdo"}},
                {"Lautaro Martínez", 28, {"Atacante"}}, {"Marcus Thuram", 27, {"Atacante"}}
            }
        },

        // --- 8 CLUBES RESTANTES ---

        // 🏴󠁧󠁢󠁥󠁮󠁧󠁿 CHELSEA (Base 4-2-3-1)
        {
            "Chelsea", {
                {"Robert Sánchez", 27, {"Goleiro"}}, {"Malo Gusto", 22, {"Lateral Direito"}},
                {"Benoît Badiashile", 24, {"Zagueiro"}}, {"Wesley Fofana", 24, {"Zagueiro"}},
                {"Marc Cucurella", 26, {"Lateral Esquerdo"}}, {"Enzo Fernández", 24, {"Volante"}},
                {"Moisés Caicedo", 23, {"Volante"}}, {"Cole Palmer", 23, {"Meia Ofensivo"}},
                {"Mykhailo Mudryk", 24, {"Ponta Esquerda"}}, {"Raheem Sterling", 30, {"Ponta Direita"}},
                {"Nicolas Jackson", 24, {"Centroavante"}}
            }
        },

        // 🇫🇷 PARIS SAINT-GERMAIN (Base 4-3-3)
        {
            "Paris Saint-Germain", {
                {"Gianluigi Donnarumma", 26, {"Goleiro"}}, {"Achraf Hakimi", 26, {"Lateral Direito"}},
                {"Marquinhos", 31, {"Zagueiro"}}, {"Lucas Beraldo", 21, {"Zagueiro"}},
                {"Nuno Mendes", 23, {"Lateral Esquerdo"}}, {"Vitinha", 25, {"Meia Central"}},
                {"Fabián Ruiz", 29, {"Meia Central"}}, {"Warren Zaïre-Emery", 19, {"Volante"}},
                {"Ousmane Dembélé", 28, {"Ponta Direita"}}, {"Randal Kolo Muani", 26, {"Atacante"}},
                {"Bradley Barcola", 22, {"Ponta Esquerda"}}
            }
        },

        // 🇵🇹 BENFICA (Base 4-2-3-1)
        {
            "Benfica", {
                {"Anatoliy Trubin", 23, {"Goleiro"}}, {"Alexander Bah", 27, {"Lateral Direito"}},
                {"Nicolás Otamendi", 37, {"Zagueiro"}}, {"António Silva", 21, {"Zagueiro"}},
                {"Álvaro Carreras", 22, {"Lateral Esquerdo"}}, {"João Neves", 20, {"Volante"}},
                {"Florentino Luís", 26, {"Volante"}}, {"Rafa Silva", 32, {"Meia Ofensivo"}},
                {"Ángel Di María", 37, {"Ponta Direita"}}, {"João Mário", 32, {"Ponta Esquerda"}},
                {"Arthur Cabral", 27, {"Centroavante"}}
            }
        },

        // 🇮🇹 JUVENTUS (Base 3-5-2)
        {
            "Juventus", {
                {"Wojciech Szczęsny", 35, {"Goleiro"}}, {"Bremer", 28, {"Zagueiro"}}, {"Danilo", 34, {"Zagueiro"}},
                {"Federico Gatti", 27, {"Zagueiro"}}, {"Andrea Cambiaso", 25, {"Ala Esquerdo"}},
                {"Manuel Locatelli", 27, {"Volante"}}, {"Adrien Rabiot", 30, {"Meia Central"}},
                {"Nicolò Fagioli", 24, {"Meia Central"}}, {"Timothy Weah", 25, {"Ala Direito"}},
                {"Dušan Vlahović", 25, {"Atacante"}}, {"Federico Chiesa", 27, {"Atacante"}}
            }
        },

        // 🇩🇪 BORUSSIA DORTMUND (Base 4-2-3-1)
        {
            "Borussia Dortmund", {
                {"Gregor Kobel", 27, {"Goleiro"}}, {"Julian Ryerson", 27, {"Lateral Direito"}},
                {"Mats Hummels", 36, {"Zagueiro"}}, {"Nico Schlotterbeck", 25, {"Zagueiro"}},
                {"Ian Maatsen", 23, {"Lateral Esquerdo"}}, {"Emre Can", 31, {"Volante"}},
                {"Marcel Sabitzer", 31, {"Meia Central"}}, {"Jadon Sancho", 25, {"Ponta Direita"}},
                {"Julian Brandt", 29, {"Meia Ofensivo"}}, {"Karim Adeyemi", 23, {"Ponta Esquerda"}},
                {"Niclas Füllkrug", 32, {"Centroavante"}}
            }
        },

        // 🇸🇦 AL HILAL (Base 4-2-3-1)
        {
            "Al Hilal", {
                {"Yassine Bounou (Bono)", 34, {"Goleiro"}}, {"Saud Abdulhamid", 26, {"Lateral Direito"}},
                {"Kalidou Koulibaly", 34, {"Zagueiro"}}, {"Ali Al Bulayhi", 35, {"Zagueiro"}},
                {"Renan Lodi", 27, {"Lateral Esquerdo"}}, {"Rúben Neves", 28, {"Volante"}},
                {"Sergej Milinkovic-Savić", 30, {"Meia Central"}}, {"Michael", 29, {"Ponta Direita"}},
                {"Malcom", 28, {"Meia Ofensivo"}}, {"Salem Al-Dawsari", 33, {"Ponta Esquerda"}},
                {"Aleksandar Mitrović", 30, {"Centroavante"}}
            }
        },

        // 🇲🇽 MONTERREY (Base 4-4-2)
        {
            "Monterrey", {
                {"Esteban Andrada", 34, {"Goleiro"}}, {"Erick Aguirre", 28, {"Lateral Direito"}},
                {"Héctor Moreno", 37, {"Zagueiro"}}, {"Stefan Medina", 33, {"Zagueiro"}},
                {"Gerardo Arteaga", 27, {"Lateral Esquerdo"}}, {"Maximiliano Meza", 33, {"Ponta Direita"}},
                {"Luis Romo", 30, {"Meia Central"}}, {"Sergio Canales", 34, {"Meia Central"}},
                {"Jesús Gallardo", 31, {"Ponta Esquerda"}}, {"Brandon Vázquez", 26, {"Atacante"}},
                {"Germán Berterame", 26, {"Atacante"}}
            }
        },

        // 🇺🇸 INTER MIAMI (Base 4-3-3)
        {
            "Inter Miami", {
                {"Drake Callender", 27, {"Goleiro"}}, {"DeAndre Yedlin", 32, {"Lateral Direito"}},
                {"Serhiy Kryvtsov", 34, {"Zagueiro"}}, {"Tomás Avilés", 21, {"Zagueiro"}},
                {"Jordi Alba", 36, {"Lateral Esquerdo"}}, {"Sergio Busquets", 37, {"Volante"}},
                {"Federico Redondo", 22, {"Meia Central"}}, {"Julian Gressel", 31, {"Meia Central"}},
                {"Lionel Messi", 38, {"Ponta Direita", "Meia"}}, {"Luis Suárez", 38, {"Centroavante"}},
                {"Leonardo Campana", 25, {"Ponta Esquerda"}}
            }
        }
    };

    // --- FUNÇÃO PRINCIPAL DE CRIAÇÃO E ASSOCIAÇÃO ---


    // Mapa para armazenar as instâncias dos clubes
    map<string, Clube*> clubes;
    vector<Clube*> clubesCriados;
    // Dados base para TODOS os 16 clubes
    vector<pair<string, int>> clubesParaInstanciar = {
        {"Palmeiras", 1914}, {"Real Madrid", 1902}, {"Manchester City", 1880}, {"Bayern de Munique", 1900},
        {"Flamengo", 1895}, {"Fluminense", 1902}, {"Botafogo", 1904}, {"Inter de Milão", 1908},
        // Clubes restantes:
        {"Chelsea", 1905}, {"Paris Saint-Germain", 1970}, {"Benfica", 1904}, {"Juventus", 1897},
        {"Borussia Dortmund", 1909}, {"Al Hilal", 1957}, {"Monterrey", 1945}, {"Inter Miami", 2018}
    };

    for (const auto& dadosClube : clubesParaInstanciar)
    {
        string nomeClube = dadosClube.first;
        int anoFundacao = dadosClube.second;

        // 1. Cria a instância do Clube
        Clube* novoClube = new Clube(nomeClube, anoFundacao);
        cout << novoClube->getNome() << endl;
        clubes[nomeClube] = novoClube;
        clubesCriados.push_back(novoClube);

        // 2. Itera sobre os jogadores titulares desse clube
        if (elencosTitulares.count(nomeClube))
        {
            for (const auto& dadosAtleta : elencosTitulares[nomeClube])
            {
                // 3. Cria a instância do Atleta
                Atleta* novoAtleta = new Atleta(dadosAtleta.nome, dadosAtleta.idade, dadosAtleta.posicoes);

                // 4. Associa o Atleta ao Clube
                novoClube->comprarAtleta(*novoAtleta);
            }
        }
    }
    return clubesCriados;
};

Campeonato criarCampeonato()
{
    Campeonato superMundial = Campeonato("Copa do Mundo de Clubes FIFA");
    superMundial.inserirTodosTimes(criarInstanciasClubesTitularesTodos());
    return superMundial;
};
