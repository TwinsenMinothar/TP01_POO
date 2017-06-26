//
// Created by camil on 25/06/2017.
//

#include "Pessoa.h"

Pessoa::Pessoa()
{
    nome = "";
    idade = 0;
}

Pessoa::Pessoa(std::string nome, int idade)
{
    this->nome = nome;
    this->idade = idade;
}


Pessoa::~Pessoa()
{
}

const std::string &Pessoa::getNome() const {
    return nome;
}

void Pessoa::setNome(const std::string &nome) {
    Pessoa::nome = nome;
}

int Pessoa::getIdade() const {
    return idade;
}

void Pessoa::setIdade(int idade) {
    Pessoa::idade = idade;
}

std::ostream &operator<<(std::ostream &os, const Pessoa &pessoa) {
    os << "Nome: " << pessoa.nome << " Idade: " << pessoa.idade;
    return os;
}
