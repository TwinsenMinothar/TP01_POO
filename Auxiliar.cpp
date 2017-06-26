//
// Created by camil on 25/06/2017.
//

#include "Auxiliar.h"

Auxiliar::Auxiliar() : Pessoa() {
    this->funcao = "";
    this->salario = 0;
}

Auxiliar::Auxiliar(std::string nome, int idade, std::string funcao, float salario) : Pessoa(nome, idade) {
    this->funcao = funcao;
    this->salario = salario;
}


Auxiliar::~Auxiliar() {
}

void Auxiliar::listarAuxiliares(std::vector<Auxiliar> auxiliares) {
    std::cout << "Auxiliares" << std::endl;
    for (int i = 0; i < auxiliares.size(); i++) {
        std::cout << "[" << i << "] " << auxiliares[i].getNome() << " " << auxiliares[i].getIdade() << " "
                  << auxiliares[i].getFuncao() << " " << auxiliares[i].getSalario() << std::endl;
    }
}

const std::string &Auxiliar::getFuncao() const {
    return funcao;
}

void Auxiliar::setFuncao(const std::string &funcao) {
    Auxiliar::funcao = funcao;
}

float Auxiliar::getSalario() const {
    return salario;
}

void Auxiliar::setSalario(float salario) {
    Auxiliar::salario = salario;
}

std::ostream &operator<<(std::ostream &os, const Auxiliar &auxiliar) {
    os << static_cast<const Pessoa &>(auxiliar) << " Funcao: " << auxiliar.funcao << " Salario: " << auxiliar.salario;
    return os;
}

void Auxiliar::buscaAuxiliar(std::vector<Auxiliar> auxiliares, std::string nome) {
    for (int i = 0; i < auxiliares.size(); i++) {
        if (nome.compare(auxiliares[i].getNome()) == 0) {
            std::cout << auxiliares[i] << " Posicao: " << i << std::endl;
        } else {
            std::cout << "Nome nao encontrado" << std::endl;
        }
    }
}
