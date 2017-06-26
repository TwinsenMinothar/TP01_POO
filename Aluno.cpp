//
// Created by camil on 25/06/2017.
//

#include "Aluno.h"

using std::cout;
using std::endl;

Aluno::Aluno() : Pessoa() {
    curso = "";
}

Aluno::Aluno(std::string nome, int idade, std::string curso) : Pessoa(nome, idade) {
    this->curso = curso;
}


Aluno::~Aluno() {
}

void Aluno::listarAlunos(std::vector<Aluno> alunos) {
    cout << "Alunos" << endl;
    for (int i = 0; i < alunos.size(); i++) {
        cout << "[" << i << "] " << alunos[i].getNome() << " " << alunos[i].getIdade() << " " << alunos[i].getCurso()
             << endl;
    }
}

const std::string &Aluno::getCurso() const {
    return curso;
}

void Aluno::setCurso(const std::string &curso) {
    Aluno::curso = curso;
}

std::ostream &operator<<(std::ostream &os, const Aluno &aluno) {
    os << static_cast<const Pessoa &>(aluno) << " Curso: " << aluno.curso;
    return os;
}

void Aluno::buscaAluno(std::vector<Aluno> aluno, std::string nome) {
    for (int i = 0; i < aluno.size(); i++) {
        if (nome.compare(aluno[i].getNome()) == 0){
             cout << aluno[i] << " Posicao: " << i << endl;
        } else {
            cout << "Nome nao encontrado" << endl;
        }
    }
}

