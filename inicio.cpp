#include <iostream>
#include <string>
using namespace std;

struct Pessoa
{
    string nome;
    int idade;
    double altura;

/*
    Pessoa(string n, int i, double a)
    {
        nome = n;
        idade = i;
        altura = a;
    }


    Pessoa (string nome, int idade, double altura)
    {
        this->nome = nome;
        this->idade = idade;
        this->altura = altura;
    }
*/
    void mostrar()
    {
        cout << "nome: " << nome << "; idade: " << idade << "; altura: " << altura << ".\n";
    }
};

int main()
{
    string nome;
    int idade;
    double altura;

    Pessoa array[3];

    for (int i = 0; i < 3; i++)
    {
        cin >> nome >> idade >> altura;
        Pessoa p = {nome, idade, altura};
        array[i] = p; 
    }

    for (int i = 0; i < 3; i++)
    {
        array[i].mostrar();
    }

    return 0;
}