#include <iostream>
using namespace std;

enum Produto
{
    MACA,
    PAO,
    LEITE,
    CAFE,
    QUEIJO,
    BISCOITO,
    CARNE
};

struct Item
{
    Produto nome;
    double quantidade;
    double preco;
};

struct Pedido
{

private:

    int quantidade_itens;
    int capacidade_pedidos;
    Item *itens;

    void aumentarCapacidade(int n)
    {
        capacidade_pedidos += n;
        Item *novo = new Item[capacidade_pedidos];

        for (int i = 0; i < quantidade_itens; i++)
        {
            novo[i] = itens[i];
        }

        delete[] itens;
        itens = novo;
    }

public:

    Pedido (int cap = 5) : capacidade_pedidos(cap), quantidade_itens(0)
    {
        itens = new Item[capacidade_pedidos];
    }

    ~Pedido()
    {
        delete[] itens;
    }

    void valor_compra () 
    {

    }

    void tabela (int n)
    {
        switch (n)
        {
            case MACA:
                
            case PAO:
            case LEITE:
            case CAFE:
            case QUEIJO:
            case BISCOITO:
            case CARNE:
        }
    }


};

int main()
{

    return 0;
}