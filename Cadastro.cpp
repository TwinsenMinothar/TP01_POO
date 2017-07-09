//
// Created by camil on 25/06/2017.
//

#include <fstream>
#include "Cadastro.h"

using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::ios;

void Cadastro::abrirArquivos(std::vector<Aluno> &alunos, std::vector<Professor> &professores,
                             std::vector<Auxiliar> &auxiliares) {
    ifstream alunoF("alunos.txt", ios::in);
    int idade;
    double salario;
    char c;
    std::string buffer;
    while (alunoF.good()) {
        Aluno aBuf;
        while (alunoF.get(c)) {
            if (c == '-')
                break;
            buffer += c;
        }
        aBuf.setNome(buffer);
        buffer.clear();
        while (alunoF.get(c)) {
            if (c == '-')
                break;
            buffer += c;
        }
        idade = atoi(buffer.data());
        aBuf.setIdade(idade);
        buffer.clear();
        while (alunoF.get(c)) {
            if (c == '\n')
                break;
            buffer += c;
        }
        aBuf.setCurso(buffer);
        buffer.clear();
        if (aBuf.getNome() != "")
            alunos.push_back(aBuf);
    }
    alunoF.close();

    ifstream profF("professores.txt", ios::in);
    while (profF.good()) {
        Professor pBuf;
        while (profF.get(c)) {
            if (c == '-')
                break;
            buffer += c;
        }
        pBuf.setNome(buffer);
        buffer.clear();
        while (profF.get(c)) {
            if (c == '-')
                break;
            buffer += c;
        }
        idade = atoi(buffer.data());
        pBuf.setIdade(idade);
        buffer.clear();
        while (profF.get(c)) {
            if (c == '-')
                break;
            buffer += c;
        }
        pBuf.setDisciplina(buffer);
        buffer.clear();
        while (profF.get(c)) {
            if (c == '\n')
                break;
            buffer += c;
        }
        salario = atof(buffer.data());
        pBuf.setSalario(salario);
        buffer.clear();
        if (pBuf.getNome() != "")
        professores.push_back(pBuf);
    }
    profF.close();

    ifstream auxF("auxiliares.txt", ios::in);
    while (auxF.good()) {
        Auxiliar auxB;
        while (auxF.get(c)) {
            if (c == '-')
                break;
            buffer += c;
        }
        auxB.setNome(buffer);
        buffer.clear();
        while (auxF.get(c)) {
            if (c == '-')
                break;
            buffer += c;
        }
        idade = atoi(buffer.data());
        auxB.setIdade(idade);
        buffer.clear();
        while (auxF.get(c)) {
            if (c == '-')
                break;
            buffer += c;
        }
        auxB.setFuncao(buffer);
        buffer.clear();
        while (auxF.get(c)) {
            if (c == '\n')
                break;
            buffer += c;
        }
        salario = atof(buffer.data());
        auxB.setSalario(salario);
        buffer.clear();
        if (auxB.getNome() != "")
        auxiliares.push_back(auxB);
    }
    auxF.close();
}

void Cadastro::cadastro(Aluno aluno, std::vector<Aluno> &alunos) {
    alunos.push_back(aluno);
    cout << "Cadastro realizado com sucesso" << endl;
}

void Cadastro::cadastro(Professor professor, std::vector<Professor> &professores) {
    professores.push_back(professor);
    cout << "Cadastro realizado com sucesso" << endl;
}

void Cadastro::cadastro(Auxiliar auxiliar, std::vector<Auxiliar> &auxiliares) {
    auxiliares.push_back(auxiliar);
    cout << "Cadastro realizado com sucesso" << endl;
}

void
Cadastro::salvarDados(std::vector<Aluno> alunos, std::vector<Professor> professores, std::vector<Auxiliar> auxiliares) {

    ofstream alunoF("alunos.txt", ios::out);
    for (int i = 0; i < alunos.size(); i++) {
        if (alunos[i].getNome() == "")
            break;
        alunoF << alunos[i].getNome() << "-" << alunos[i].getIdade() << "-" << alunos[i].getCurso() << endl;
    }
    alunoF.close();

    ofstream profF("professores.txt", ios::out);
    for (int i = 0; i < professores.size(); i++) {
        if (professores[i].getNome() == "")
            break;
        profF << professores[i].getNome() << "-" << professores[i].getIdade() << "-" << professores[i].getDisciplina()
              << "-" << professores[i].getSalario() << endl;
    }
    profF.close();

    ofstream auxF("auxiliares.txt", ios::out);
    for (int i = 0; i < auxiliares.size(); i++) {
        if (auxiliares[i].getNome() == "")
            break;
        auxF << auxiliares[i].getNome() << "-" << auxiliares[i].getIdade() << "-" << auxiliares[i].getFuncao() << "-"
             << auxiliares[i].getSalario() << endl;
    }
    auxF.close();
}

void Cadastro::listarTodos(std::vector<Aluno> alunos, std::vector<Professor> professores,
                           std::vector<Auxiliar> auxiliares) {
    /*cout << "Alunos" << endl;
    for (int i = 0; i < alunos.size(); i++) {
        cout << "[" << i << "] " << alunos[i].getNome() << " " << alunos[i].getIdade() << " " << alunos[i].getCurso()
             << endl;
    }
    std::cout << "Professores" << std::endl;
    for (int i = 0; i < professores.size(); i++) {
        std::cout << "[" << i << "] " << professores[i].getNome() << " " << professores[i].getIdade() << " "
                  << professores[i].getDisciplina() << professores[i].getSalario() << std::endl;
    }
    std::cout << "Auxiliares" << std::endl;
    for (int i = 0; i < auxiliares.size(); i++) {
        std::cout << "[" << i << "] " << auxiliares[i].getNome() << " " << auxiliares[i].getIdade() << " "
                  << auxiliares[i].getFuncao() << auxiliares[i].getSalario() << std::endl;
    }*/
    Aluno::listarAlunos(alunos);
    Professor::listarProfessores(professores);
    Auxiliar::listarAuxiliares(auxiliares);

}
