#include <iostream>
#include <string>
using namespace std;

struct Aluno
{
    string id;
    string nome;
    int idade;
    double notas[3];

    Aluno() : id(""), nome(""), idade(0), notas{0,0,0} {}

    Aluno(string id, string nome, int idade, double notas[3])
    {
        this->id = id;
        this->nome = nome;
        this->idade = idade;
        for (int i = 0; i < 3; i++)
        {
            this->notas[i] = notas[i];
        }
    }

    double calcular_media_aluno ()
    {
        double soma = 0;
        for (int i = 0; i < 3; i++)
        {
            soma += notas[i];
        }

        return soma / 3;
    }

    void exibir_dados_aluno()
    {
        cout << id;
        cout << nome;
        cout << idade;

        int contador = 1;
        for (int i = 0; i < 3; i++)
        {
            cout << "nota " << contador << ": " << notas[i];
            contador++;
        }
    }
};

class Escola
{
    int capacidade;
    int quantidade_alunos;
    Aluno *dados;

    void aumentarCapacidade()
    {
        capacidade += 5;
        Aluno *novo = new Aluno[capacidade];

        for (int i = 0; i < quantidade_alunos; i++)
        {
            novo[i] = dados[i];
        }

        delete[] dados;
        dados = novo;
    }

public:

    Escola (int cap = 5) : capacidade(cap), quantidade_alunos(0)
    {
        dados = new Aluno[capacidade];
    }

    ~Escola()
    {
        delete[] dados;
    }

    void cadastrarAluno (Aluno aluno)
    {
        if (quantidade_alunos >= capacidade)
        {
            aumentarCapacidade();
        }
        dados[quantidade_alunos] = aluno;
        quantidade_alunos++;
    }

    void exibir_dados_alunos ()
    {
        for (int i = 0; i < quantidade_alunos; i++)
        {
            Aluno a = dados[i];
            a.exibir_dados_aluno();
        }
    }

    //tentar usar busca binária
    void busca_por_ID (string codigo)
    {
        for (int i = 0; i < quantidade_alunos; i++)
        {
            if (codigo == dados[i].id)
            {
                dados[i].exibir_dados_aluno();
            }
        }
    }

    double media_turma ()
    {
        double contador = 0;
        for (int i = 0; i < quantidade_alunos; i++)
        {
            Aluno a = dados[i];
            contador += a.calcular_media_aluno();
        }
        return contador / quantidade_alunos;
    }

};

class Interface
{
    void mostrar_menu ()
    {
        cout << "O que deseja fazer?\n";
        cout << "1 - Cadastrar aluno no sistema;\n";
        cout << "2 - Exibir todos os alunos cadastrados;\n";
        cout << "3 - Ver média de aluno;\n";
        cout << "4 - Ver média geral da turma;\n";
        cout << "5 - Buscar aluno por ID;\n";
        cout << "0 - Encerrar.\n";
    }
};

class Programar
{
    Interface ui;

    

    void Executar ()
    {
        while (true)
        {
            
        }
    }
};

int main ()
{
    Aluno a;

    int array[3] = {0,2,3};

    for (int i = 0; i < 3; i++){
        a.notas[i] = array[i];
    }

    return 0;
}