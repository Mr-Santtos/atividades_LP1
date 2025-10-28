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
    ifstream input("filmes_indicacao.csv");
    if (!input.is_open()) {
        cerr << "Erro ao abrir filmes_indicacao.csv\n";
        return 1;
    }

    string linha;
    getline(input, linha); // cabeçalho

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
        return a.nota > b.nota;
    });

    cout << "\n===== TOP FILMES =====\n";
    for (const auto &f : filmes) {
        cout << f.titulo << " (" << f.ano << ") - Nota: " << f.nota << "\n";
    }

    input.close();
    return 0;
}
