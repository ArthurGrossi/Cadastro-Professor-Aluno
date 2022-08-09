#include <iostream>
using namespace std;

class Data
{
private:
    int dia, mes, ano;

public:
    Data()
    {
        dia = mes = ano = 0;
    }
    int getDia() { return this->dia; }
    int getMes() { return this->mes; }
    int getAno() { return this->ano; }

    void escreveData()
    {
        printf("\n%i/%i/%i", getDia(), getMes(), getAno());
    }

    bool setDia(int dia)
    {
        bool sucesso = false;
        if (dia >= 0 && dia <= 31)
        {
            this->dia = dia;
            sucesso = true;
        }
        return sucesso;
    }
    bool setMes(int mes)
    {
        bool sucesso = false;
        if (mes >= 0 && mes <= 12)
        {
            this->mes = mes;
            sucesso = true;
        }
        return sucesso;
    }
    void setAno(int ano) { this->ano = ano; }

    void leData()
    {
        bool error;
        do
        {
            int dia, mes, ano;
            printf("dd/mm/aaaa: ");
            scanf("%i/%i/%i", &dia, &mes, &ano);
            this->setDia(dia);
            this->setMes(mes);
            this->setAno(ano);
            if (setDia(dia) && setMes(mes))
            {
                error = false;
            }
            else
            {
                printf("Data invalida!\n");
                error = true;
            }
        } while (error);
    }

    string mesExtenso(int mes)
    {
        string mesExtenso;
        string meses[] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
        if (mes > 0 && mes <= 12)
        {
            mesExtenso = meses[mes - 1];
        }
        else
        {
            mesExtenso = "Mes invalido";
        }
        return mesExtenso;
    }
};

class Pessoa {
    private:
        string nome;
        Data dataNascimento;
    public:
        Pessoa() {
            nome = "";
            dataNascimento = Data();
        }

        void setNome(string nome) {
            this->nome = nome;
        }

        void setDataNascimento(Data dataNascimento) {
            this->dataNascimento = dataNascimento;
        }

        string getNome() { return nome; }
        Data getDataNascimento() { return this->dataNascimento; }

        // A função escrevePessoa foi substituída pela escreveOrigem() para ser virtual. Mais funções virtuais também foram adicionadas para deixar mais fácil a escrita do código.
        void escrevePessoa() {
            cout << "Nome: " << getNome() << endl;
            cout << "Data de nascimento: ";
            this->getDataNascimento().escreveData();
            cout << " ( " << getDataNascimento().mesExtenso(getDataNascimento().getMes()) << " )" << endl;
        }

        void lePessoa() {
            cout << endl << "Nome: ";
            cin.ignore();
            getline(cin, nome);
            cout << "Data de nascimento->";
            dataNascimento.leData();
        }

        // Funções virtuais.
        virtual void setOrigem() = 0;
        virtual void escreveOrigem() = 0;
        virtual string Origem() = 0;
};

class Aluno : public Pessoa {
    private:
        string curso;
    public:
        Aluno() {
            curso = "";
        }

        void setCurso(string curso) {
            this->lePessoa();
            cout << "Curso: ";
            cin.ignore();
            getline(cin, curso);
            this->curso = curso;
        }

        string Origem() { return curso; }

        void escreveAluno() {
            this->escrevePessoa();
            cout << "Curso: " << Origem() << endl;
        }

        void setOrigem() {
            this->setCurso(curso);
        }

        void escreveOrigem() {
            this->escreveAluno();
        }
};

class Professor : public Pessoa {
    private:
        string departamento;
    public:
        Professor() {
            departamento = "";
        }

        void setDepartamento(string departamento) {
            this->lePessoa();
            cin.ignore();
            cout << "Departamento: ";
            getline(cin, departamento);
            this->departamento = departamento;
        }

        string Origem() { return departamento; }

        void escreveProfessor() {
            this->escrevePessoa();
            cout << "Departamento: " << Origem() << endl;
        }

        void setOrigem() {
            this->setDepartamento(departamento);
        }

        void escreveOrigem() {
            this->escreveProfessor();
        }
};

