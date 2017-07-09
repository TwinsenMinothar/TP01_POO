#include "Aluno.h"
#include "Professor.h"
#include "Auxiliar.h"
#include "Cadastro.h"

using std::cout;
using std::cin;
using std::endl;

int setAInt();

int main() {
    std::vector<Aluno> alunos;
    std::vector<Professor> professores;
    std::vector<Auxiliar> auxiliares;

    std::string nome, curso, disciplina, funcao;
    int idade, salario;

    Cadastro::abrirArquivos(alunos, professores, auxiliares);

    cout << "Bem-vindo ao gerenciador de Alunos e Funcionarios" << endl;
    mainMenu:
    cout << "Escolha se deseja 1.Cadastrar, 2.Visualizar, 3.Buscar, 4.Sair" << endl;
    int op = setAInt();
    switch (op) {
        case 1: {
            cout << "Cadastro de 1.Aluno, 2.Professor, 3.Auxiliar" << endl;
            op = setAInt();
            switch (op) {
                case 1: {
                    cout << "Digite o nome: ";
                    cin.ignore();
                    getline(cin, nome);
                    cout << "Digite a idade: ";
                    idade = setAInt();
                    cout << "Digite o curso: ";
                    cin.ignore();
                    getline(cin, curso);
                    Aluno *novoAluno = new Aluno(nome, idade, curso);
                    Cadastro::cadastro(*novoAluno, alunos);
                    delete novoAluno;
                    break;
                }
                case 2: {
                    cout << "Digite o nome: ";
                    cin.ignore();
                    getline(cin, nome);
                    cout << "Digite a idade: ";
                    idade = setAInt();
                    cout << "Digite a disciplina: ";
                    cin.ignore();
                    getline(cin, disciplina);
                    cout << "Digite o salario: ";
                    salario = setAInt();
                    Professor *novoProfessor = new Professor(nome, idade, disciplina, salario);
                    Cadastro::cadastro(*novoProfessor, professores);
                    delete novoProfessor;
                    break;
                }
                case 3: {
                    cout << "Digite o nome: ";
                    cin.ignore();
                    getline(cin, nome);
                    cout << "Digite a idade: ";
                    idade = setAInt();
                    cout << "Digite a funcao: ";
                    cin.ignore();
                    getline(cin, funcao);
                    cout << "Digite o salario: ";
                    salario = setAInt();
                    Auxiliar *novoAuxiliar = new Auxiliar(nome, idade, funcao, salario);
                    Cadastro::cadastro(*novoAuxiliar, auxiliares);
                    delete novoAuxiliar;
                    break;
                }
                default: {
                    cout << "Opcao Invalida " << endl;
                    goto mainMenu;
                }
            }
            break;
        }
        case 2: {
            cout << "Escolha se deseja visualizar 1.Alunos, 2.Professores, 3.Auxiliares, 4.Todos" << endl;
            op = setAInt();
            switch (op) {
                case 1:
                    Aluno::listarAlunos(alunos);
                    break;
                case 2:
                    Professor::listarProfessores(professores);
                    break;
                case 3:
                    Auxiliar::listarAuxiliares(auxiliares);
                    break;
                case 4:
                    Cadastro::listarTodos(alunos, professores, auxiliares);
                    break;
                default: {
                    cout << "Opcao Invalida" << endl;
                    goto mainMenu;
                }
            }
            break;
        }
        case 3: {
            cout << "Escolha se deseja buscar 1.Alunos, 2.Professores, 3.Auxiliares" << endl;
            op = setAInt();
            cout << endl << "Digite o nome a ser buscado: ";
            cin.ignore();
            getline(cin, nome);
            switch (op) {
                case 1:
                    Aluno::buscaAluno(alunos, nome);
                    break;
                case 2:
                    Professor::buscaProfessor(professores, nome);
                    break;
                case 3:
                    Auxiliar::buscaAuxiliar(auxiliares, nome);
                    break;
                default: {
                    cout << "Opcao Invalida" << endl;
                    goto mainMenu;
                }
            }
            break;
        }
        case 4: {
            cout << "Deseja salvar as mudancas 1.Sim 2.Nao: " << endl;
            op = setAInt();
            switch (op) {
                case 1:
                    Cadastro::salvarDados(alunos, professores, auxiliares);
                    cout << "Salvo com Sucesso" << endl;
                    return 0;
                case 2:
                    return 0;
                default: {
                    cout << "Opcao Invalida" << endl;
                    goto mainMenu;
                }
            }
        }
        default: {
            cout << "Opcao invalida" << endl;
            goto mainMenu;
        }
    }
    goto mainMenu;
}

int setAInt() {
    int myint;
    cin >> myint;
    while (cin.fail() || myint < 0) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Entrada invalida digite novamente: ";
        cin >> myint;
    }
    return myint;
}