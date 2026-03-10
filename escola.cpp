#include <iostream>
using namespace std;

struct Alunos
{
    string nome;
    int idade;
    int notas[3];
};

class Escola
{
    int capacidade;
    int quantidade_alunos;
    Alunos *dados;

    void aumentarCapacidade()
    {
        capacidade += 5;
        Alunos *novo = new Alunos[capacidade];

        for (int i = 0; i < quantidade_alunos; i++)
        {
            novo[i] = dados[i];
        }

        delete[] dados;
        dados = novo;
    }

public:

};

int main ()
{

    return 0;
}