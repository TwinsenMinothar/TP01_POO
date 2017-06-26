//
// Created by camil on 25/06/2017.
//

#ifndef TP01_POO_AUXILIAR_H
#define TP01_POO_AUXILIAR_H

#include <ostream>
#include "Pessoa.h"

class Auxiliar :
        public Pessoa {
    std::string funcao;
    float salario;
public:
    Auxiliar();

    Auxiliar(std::string nome, int idade, std::string funcao, float salario);

    static void listarAuxiliares(std::vector<Auxiliar> auxiliares);

    const std::string &getFuncao() const;

    void setFuncao(const std::string &funcao);

    float getSalario() const;

    void setSalario(float salario);

    static void buscaAuxiliar(std::vector<Auxiliar> auxiliares,std::string nome);

    virtual ~Auxiliar();

    friend std::ostream &operator<<(std::ostream &os, const Auxiliar &auxiliar);
};


#endif //TP01_POO_AUXILIAR_H
