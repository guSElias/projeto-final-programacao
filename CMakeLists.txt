cmake_minimum_required(VERSION 4.0)
project(projeto_final_programacao)

set(CMAKE_CXX_STANDARD 14)

include_directories(class/Atleta)
include_directories(class/Campeonato)
include_directories(class/Clube)
include_directories(class/Partida)

add_executable(projeto_final_programacao
        class/Atleta/Atleta.cpp
        class/Atleta/Atleta.h
        class/Campeonato/Campeonato.h
        class/Clube/Clube.cpp
        class/Clube/Clube.h
        class/Partida/Partida.h
        main.cpp
        class/Campeonato/Campeonato.cpp
        class/Campeonato/Campeonato.h
        class/Campeonato/Campeonato.h
        class/Partida/Partida.cpp
        class/Partida/Partida.h)
