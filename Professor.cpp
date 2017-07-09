//
// Created by camil on 25/06/2017.
//

#include "Professor.h"



Professor::Professor() : Pessoa()
{
    disciplina = "";
    salario = 0;
}

Professor::Professor(std::string nome, int idade, std::string disciplina, float salario) : Pessoa(nome, idade)
{
    this->disciplina = disciplina;
    this->salario = salario;
}


Professor::~Professor()
{
}

void Professor::listarProfessores(std::vector<Professor> professores) {
    std::cout << "Professores" << std::endl;
    int i;
    for (i = 0; i < professores.size(); i++) {
        if(professores[i].getNome() == "")
            break;
        std::cout << "[" << i << "] " << professores[i] << std::endl;
    }
    std::cout << "Total de Professores: " << i << std::endl;
}

const std::string &Professor::getDisciplina() const {
    return disciplina;
}

void Professor::setDisciplina(const std::string &disciplina) {
    Professor::disciplina = disciplina;
}

float Professor::getSalario() const {
    return salario;
}

void Professor::setSalario(float salario) {
    Professor::salario = salario;
}

std::ostream &operator<<(std::ostream &os, const Professor &professor) {
    os << static_cast<const Pessoa &>(professor) << " Disciplina: " << professor.disciplina << " Salario: "
       << professor.salario;
    return os;
}

void Professor::buscaProfessor(std::vector<Professor> professores, std::string nome) {
    for (int i = 0; i < professores.size(); i++) {
        if (nome.compare(professores[i].getNome()) == 0){
            std::cout << professores[i] << " Posicao: " << i << std::endl;
        } else {
            std::cout << "Nome nao encontrado" << std::endl;
        }
    }
}

