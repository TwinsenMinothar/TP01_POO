cmake_minimum_required(VERSION 3.7)
project(TP01_POO)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Pessoa.cpp Pessoa.h Aluno.cpp Aluno.h Pessoa.cpp Pessoa.h Aluno.cpp Aluno.h Professor.cpp Professor.h Auxiliar.cpp Auxiliar.h Cadastro.cpp Cadastro.h)
add_executable(TP01_POO ${SOURCE_FILES})