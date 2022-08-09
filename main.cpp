#include "Classes.hpp"

using namespace std;

const int MAX = 1000;
int tamanho = 0;

int menu();
void cadastraPessoa(Pessoa *pessoas[], int caso);
void pesquisaPessoa(Pessoa *pessoas[]);
void listaPessoasMes(Pessoa *pessoas[]);

int main() {
    system("cls");

    Pessoa *pessoa[MAX];

    int op;
    int caso;
    do {
        op = menu();
        switch (op) {
            case 0:
                cout << "Volte sempre!" << endl;
                break;
            case 1:
                caso = 1;
                cadastraPessoa(pessoa, caso);
                break;
            case 2:
                caso = 2;
                cadastraPessoa(pessoa, caso);
                break;
            case 3:
                pesquisaPessoa(pessoa);
                break;
            case 4:
                listaPessoasMes(pessoa);
                break;
            default:
                cout << "Numero digitado invalido!" << endl;
        }
    } while (op != 0);
    return 0;
}

int menu() {
    int op;

    printf("\n=========================================");
    printf("\n0 - Sair");
    printf("\n1 - Cadastrar um Professor");
    printf("\n2 - Cadastrar um Aluno");
    printf("\n3 - Listar todas as pessoas cadastradas");
    printf("\n4 - Pesquisar pessoas pelo mes");
    printf("\n=========================================");
    printf("\n\nOpcao: ");
    cin >> op;

return op;
}

void cadastraPessoa(Pessoa *pessoas[], int caso) {
    if (caso == 2) {
        pessoas[tamanho] = new Aluno();
    } else if (caso == 1) {
        pessoas[tamanho] = new Professor();
    }
    if (tamanho < MAX) {
        pessoas[tamanho]->setOrigem();
        (tamanho)++;
    } else {
        puts("\nO numero maximo de pessoas foi excedido!");
    }
}

void pesquisaPessoa(Pessoa *pessoas[]) {
    cout << endl;
    for (int i = 0; i < tamanho; i++) {
            pessoas[i]->escreveOrigem();
            cout << endl;
    }
}

void listaPessoasMes(Pessoa *pessoas[]) {
    cout << endl;
    int mes;
    cout << "Digite o mes que deseja listar as pessoas (1 a 12): ";
    cin >> mes;
    while (mes < 1 || mes > 12) {
        cout << "Digite um mes valido (1 a 12): ";
        cin >> mes;
    }
    for (int i = 0; i < tamanho; i++) {
        if (pessoas[i]->getDataNascimento().getMes() == mes) {
            cout << endl << endl << "Pesquisa feita pelo mes: " << pessoas[i]->getDataNascimento().mesExtenso(mes) << " ( " << mes << " ) " << endl << endl;
            pessoas[i]->escreveOrigem();
            cout << endl;
        }
    }
}