#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Filme {
    int ano;
    string titulo;
    double nota;
};

int main() {
    ifstream input("filmes_avaliacao.csv");
    ofstream output("filmes_indicacao.csv");

    if (!input.is_open()) {
        cerr << "Erro ao abrir filmes_avaliacao.csv\n";
        return 1;
    }

    string linha;
    getline(input, linha); // ignorar cabeçalho

    vector<Filme> filmes;
    while (getline(input, linha)) {
        stringstream ss(linha);
        string ano, titulo, nota_str;
        getline(ss, ano, ',');
        getline(ss, titulo, ',');
        getline(ss, nota_str);

        Filme f;
        f.ano = stoi(ano);
        f.titulo = titulo;
        f.nota = stod(nota_str);
        filmes.push_back(f);
    }

    sort(filmes.begin(), filmes.end(), [](const Filme &a, const Filme &b) {
        if (a.nota != b.nota)
            return a.nota > b.nota;
        return a.titulo < b.titulo; 
    });

    output << "Ano,Filme,Nota\n";
    for (int i = 0; i < 5 && i < (int)filmes.size(); i++) {
        output << filmes[i].ano << "," << filmes[i].titulo << "," << filmes[i].nota << "\n";
    }

    cout << "Arquivo 'filmes_indicacao.csv' criado com sucesso!\n";

    input.close();
    output.close();
    return 0;
}
