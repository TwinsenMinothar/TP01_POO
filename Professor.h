//
// Created by camil on 25/06/2017.
//

#ifndef TP01_POO_PROFESSOR_H
#define TP01_POO_PROFESSOR_H

#include <ostream>
#include "Pessoa.h"
class Professor :
        public Pessoa
{
    std::string disciplina;
    float salario;
public:
    Professor();
    Professor(std::string nome,int idade,std::string disciplina, float salario);
    static void listarProfessores(std::vector<Professor> professores);

    const std::string &getDisciplina() const;

    void setDisciplina(const std::string &disciplina);

    float getSalario() const;

    void setSalario(float salario);

    static void buscaProfessor(std::vector<Professor> professores,std::string nome);

    virtual ~Professor();

    friend std::ostream &operator<<(std::ostream &os, const Professor &professor);

};


#endif //TP01_POO_PROFESSOR_H
