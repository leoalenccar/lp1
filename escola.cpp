#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

enum Operacao
{
    ENCERRAR,
    CADASTRAR,
    DADOS_TODOS,
    MEDIA_ALUNO,
    MEDIA_TODOS,
    BUSCAR_ID
};

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
        cout << "\n";
        cout << "ID: " << id << ";\n";
        cout << "Nome: " << nome << ";\n";
        cout << "Idade: " << idade << ";\n";
        cout << "\n";

        int contador = 1;
        for (int i = 0; i < 3; i++)
        {
            cout << "nota " << contador << ": " << notas[i] << "\n";
            contador++;
        }

        cout <<"\n";
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

        int nmr_id = quantidade_alunos + 1;
        string novo_id;
        if (quantidade_alunos + 1 < 10)
        {
            novo_id = "#00" + to_string(nmr_id);
        }
        else if (quantidade_alunos + 1 < 100)
        {
            novo_id = "#0" + to_string(nmr_id);
        }
        else
        {
            novo_id = "#" + to_string(nmr_id);
        }

        aluno.id = novo_id;
        dados[quantidade_alunos] = aluno;
        quantidade_alunos++;
    }

    void exibir_dados_alunos ()
    {
        for (int i = 0; i < quantidade_alunos; i++)
        {
            dados[i].exibir_dados_aluno();
            cout << "\n";
            cout << "==========================\n";
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
                break;
            }
            if (i == quantidade_alunos - 1 && codigo != dados[i].id)
            {
                cout << "Aluno não encontrado, tente novamente.\n";
            }
        }

    }


    void buscar_media_aluno (string codigo)
    {
        bool encontrado = false;

        for (int i = 0; i < quantidade_alunos; i++)
        {
            if (codigo == dados[i].id)
            {
                double media = dados[i].calcular_media_aluno();

                cout << "Aluno: " << dados[i].nome << ";\n";
                cout << "ID: " << codigo << ";\n" << endl;

                int contador = 1;
                for (int j = 0; j < 3; j++)
                {
                    cout << "Nota " << contador << ": " << dados[i].notas[j] << ";\n";
                    contador++;
                }
                cout << "Media: " << media << ".\n";

                encontrado = true;
                break;
            }
        }

        if (!encontrado)
        {
            cout << "Aluno não encontrado, tente novamente.\n";
        }
    }

    void media_turma()
    {
        if (quantidade_alunos == 0)
        {
            cout << "Nenhum aluno cadastrado.\n";
        }
        else
        {

            double contador = 0;
            for (int i = 0; i < quantidade_alunos; i++)
            {
                Aluno a = dados[i];
                contador += a.calcular_media_aluno();
            }

            double media = contador / quantidade_alunos;
            cout << "Media da turma: " << media << endl;
        }
    }
};

class Interface
{
public:
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

    void encerrar ()
    {
        cout << "Encerrando...";
        this_thread::sleep_for(chrono::seconds(3));
        cout << "\n";
    }

    Aluno novo_aluno ()
    {
        string nome;
        int idade;
        double notas[3];

        cout << "Digite o nome do aluno: ";
        cin >> nome;

        cout << "\n";

        cout << "Digite a idade do aluno: ";
        cin >> idade;

        int contador = 1;
        for (int i = 0; i < 3; i++)
        {
            cout << "Digite a " << contador << "ª nota: ";
            cin >> notas[i];
            cout << "\n";
            contador++;
        }

        Aluno aluno = {"000", nome, idade, notas};
        return aluno;

    }

    string codigo ()
    {
        int id;
        cout << "Digite o código ID do aluno: ";
        cin >> id;

        string codigo_id;

        if (id < 10)
        {
            codigo_id = "#00" + to_string(id);
        }
        else if (id < 100)
        {
            codigo_id = "#0" + to_string(id);
        }
        else
        {
            codigo_id = "#" + to_string(id);
        }

        return codigo_id;
    }

    void invalido ()
    {
        cout << "Número inválido, tente novamente: ";
    }
};

class Programa
{
    Interface ui;
    Escola escola;

public:

    void chamar_operacao (int operacao)
    {
        switch (operacao)
        {
            case ENCERRAR:
                ui.encerrar();
                break;

            case CADASTRAR:
                escola.cadastrarAluno(ui.novo_aluno());
                break;

            case DADOS_TODOS:
                escola.exibir_dados_alunos();
                break;

            case MEDIA_ALUNO:
                escola.buscar_media_aluno(ui.codigo());
                break;

            case MEDIA_TODOS:
                escola.media_turma();
                break;

            case BUSCAR_ID:
                escola.busca_por_ID(ui.codigo());
                break;
        }
    }
    

    void executar ()
    {
        while (true)
        {
            ui.mostrar_menu();

            int op;
            cin >> op;
            while (op < 0 || op > 5)
            {
                ui.invalido();
                cin >> op;
            }

            chamar_operacao(op);

            if (op == 0)
            {
                break;
            }
        }
    }
};

int main ()
{
    Programa p;

    p.executar();

    return 0;
}