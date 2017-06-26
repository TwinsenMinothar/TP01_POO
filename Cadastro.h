//
// Created by camil on 25/06/2017.
//

#ifndef TP01_POO_CADASTRO_H
#define TP01_POO_CADASTRO_H

#include <cstdio>
#include "Aluno.h"
#include "Professor.h"
#include "Auxiliar.h"

class Cadastro : public Pessoa {
public:
    static void
    abrirArquivos(std::vector<Aluno> &alunos, std::vector<Professor> &professores, std::vector<Auxiliar> &auxiliares);

    static void cadastro(Aluno aluno, std::vector<Aluno> &alunos);

    static void cadastro(Professor professor, std::vector<Professor> &professores);

    static void cadastro(Auxiliar auxiliar, std::vector<Auxiliar> &auxiliares);

    static void
    salvarDados(std::vector<Aluno> alunos, std::vector<Professor> professores, std::vector<Auxiliar> auxiliares);

    static void listarTodos(std::vector<Aluno> alunos, std::vector<Professor> professores,
                            std::vector<Auxiliar> auxiliares);
};


#endif //TP01_POO_CADASTRO_H
