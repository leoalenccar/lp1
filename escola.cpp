#include <iostream>
#include <string>
using namespace std;

struct Aluno
{
    string id;
    string nome;
    int idade;
    double notas[3];
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

    int calcular_media_aluno (Aluno aluno)
    {
        double soma = 0;
        for (int i = 0; i < 3; i++)
        {
            soma += aluno.notas[i];
        }

        return soma / 3;
    }

    void exibir_dados_aluno (Aluno aluno)
    {
        cout << aluno.id;
    }

    void exibir_dados_alunos ()
    {
        for (int i = 0; i < quantidade_alunos; i++0)
        {
            cout 
        }
    }

};

int main ()
{

    return 0;
}