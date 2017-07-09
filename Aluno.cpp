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
    int i;
    for (i = 0; i < alunos.size(); i++) {
        if (alunos[i].getNome() == "")
            break;
        cout << "[" << i << "] " << alunos[i] << endl;
    }
    cout << "Total de Alunos: " << i << endl;
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
    bool nAchou = true;
    for (int i = 0; i < aluno.size(); i++) {
        if (nome.compare(aluno[i].getNome()) == 0) {
            cout << aluno[i] << " Posicao: " << i << endl;
            nAchou = false;
        } else if(nAchou) {
            cout << "Nome nao encontrado" << endl;
            nAchou = false;
        }
    }
}

