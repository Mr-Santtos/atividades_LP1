#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>

using namespace std;

int main() {
    ifstream input("filmes.csv");
    ofstream output("filmes_avaliacao.csv");
    string linha;

    if (!input.is_open()) {
        cerr << "Erro ao abrir filmes.csv\n";
        return 1;
    }

    output << "Ano,Filme,Nota\n"; 

    while (getline(input, linha)) {
        stringstream ss(linha);
        string ano, filme;
        getline(ss, ano, ',');
        getline(ss, filme);

        double nota;
        while (true) {
            cout << "Digite a nota (0 a 10) para \"" << filme << "\": ";
            cin >> nota;
            if (cin.fail() || nota < 0 || nota > 10) {
                cout << "Valor inválido. Digite novamente.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else break;
        }

        output << ano << "," << filme << "," << nota << "\n";
    }

    input.close();
    output.close();

    cout << "\nArquivo 'filmes_avaliacao.csv' criado com sucesso!\n";
    return 0;
}
