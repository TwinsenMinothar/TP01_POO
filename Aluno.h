//
// Created by camil on 25/06/2017.
//

#ifndef TP01_POO_ALUNO_H
#define TP01_POO_ALUNO_H

#include <ostream>
#include "Pessoa.h"

class Aluno :
        public Pessoa
{
    std::string curso;
public:
    Aluno();
    Aluno(std::string nome,int idade,std::string curso);
    static void listarAlunos(std::vector<Aluno> alunos);
    static void buscaAluno(std::vector<Aluno> aluno,std::string nome);
    virtual ~Aluno();

    const std::string &getCurso() const;

    void setCurso(const std::string &curso);

    friend std::ostream &operator<<(std::ostream &os, const Aluno &aluno);
};

#endif //TP01_POO_ALUNO_H
