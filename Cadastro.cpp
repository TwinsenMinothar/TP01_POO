//
// Created by camil on 25/06/2017.
//

#include "Cadastro.h"
using std::cout;
using std::endl;

static FILE *alunoF ;
static FILE *professorF;
static FILE *auxiliarF;

void Cadastro::abrirArquivos(std::vector<Aluno> &alunos, std::vector<Professor> &professores,
                             std::vector<Auxiliar> &auxiliares)
{
    alunoF = fopen("alunos.txt", "a+");
    professorF = fopen("professores.txt", "a+");
    auxiliarF = fopen("auxiliares.txt", "a+");
    fread(&alunos, sizeof(Aluno), 100, alunoF);
    fread(&professores, sizeof(Professor), 100, professorF);
    fread(&auxiliares, sizeof(Auxiliar), 100, auxiliarF);

}

void Cadastro::cadastro(Aluno aluno, std::vector<Aluno> &alunos)
{
    alunos.push_back(aluno);
    cout << "Cadastro realizado com sucesso" << endl;
}

void Cadastro::cadastro(Professor professor, std::vector<Professor> &professores)
{
    professores.push_back(professor);
    cout << "Cadastro realizado com sucesso" << endl;
}

void Cadastro::cadastro(Auxiliar auxiliar, std::vector<Auxiliar> &auxiliares)
{
    auxiliares.push_back(auxiliar);
    cout << "Cadastro realizado com sucesso" << endl;
}

void
Cadastro::salvarDados(std::vector<Aluno> alunos, std::vector<Professor> professores, std::vector<Auxiliar> auxiliares) {
    if(alunoF||professorF||auxiliarF == NULL)
        abrirArquivos(alunos,professores,auxiliares);
    fwrite(&alunos,sizeof(Aluno),alunos.size(),alunoF);
    fwrite(&professores,sizeof(Professor),professores.size(),professorF);
    fwrite(&auxiliares,sizeof(Auxiliar),auxiliares.size(),auxiliarF);
}

void Cadastro::listarTodos(std::vector<Aluno> alunos, std::vector<Professor> professores,
                           std::vector<Auxiliar> auxiliares) {
    cout << "Alunos" << endl;
    for (int i = 0; i < alunos.size(); i++) {
        cout << "[" << i << "] " << alunos[i].getNome() << " " << alunos[i].getIdade() << " " << alunos[i].getCurso() << endl;
    }
    std::cout << "Professores" << std::endl;
    for (int i = 0; i < professores.size(); i++) {
        std::cout << "[" << i << "] " << professores[i].getNome() << " " << professores[i].getIdade() << " " << professores[i].getDisciplina() << professores[i].getSalario() << std::endl;
    }
    std::cout << "Auxiliares" << std::endl;
    for (int i = 0; i < auxiliares.size(); i++) {
        std::cout << "[" << i << "] " << auxiliares[i].getNome() << " " << auxiliares[i].getIdade() << " " << auxiliares[i].getFuncao() << auxiliares[i].getSalario() << std::endl;
    }

}
