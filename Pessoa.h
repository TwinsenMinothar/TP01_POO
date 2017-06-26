//
// Created by camil on 25/06/2017.
//

#ifndef TP01_POO_PESSOA_H
#define TP01_POO_PESSOA_H

#include <string>
#include <vector>
#include <iostream>

class Pessoa
{
    std::string nome;
    int idade;
public:
    Pessoa();
    Pessoa(std::string nome, int idade);

    const std::string &getNome() const;

    void setNome(const std::string &nome);

    int getIdade() const;

    void setIdade(int idade);

    virtual ~Pessoa();

    friend std::ostream &operator<<(std::ostream &os, const Pessoa &pessoa);
};


#endif //TP01_POO_PESSOA_H
