#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Pessoa {
    string nome;
    int idade;
    double peso;
    double altura;
    double imc;
    string categoria;
};

string classificarIMC(double imc) {
    if (imc < 16)
        return "Baixo peso (Grau I)";
    else if (imc < 17)
        return "Baixo peso (Grau II)";
    else if (imc < 18.5)
        return "Baixo peso (Grau III)";
    else if (imc < 25)
        return "Peso adequado";
    else if (imc < 30)
        return "Sobrepeso";
    else if (imc < 35)
        return "Obesidade (Grau I)";
    else if (imc < 40)
        return "Obesidade (Grau II)";
    else
        return "Obesidade (Grau III)";
}

int main() {
    vector<Pessoa> lista;
    char continuar;

    do {
        Pessoa p;
        cin.ignore();
        cout << "\n--- Nova Pessoa ---\n";
        cout << "Nome: ";
        getline(cin, p.nome);
        cout << "Idade: ";
        cin >> p.idade;
        cout << "Peso (kg): ";
        cin >> p.peso;
        cout << "Altura (m): ";
        cin >> p.altura;

        p.imc = p.peso / (p.altura * p.altura);
        p.categoria = classificarIMC(p.imc);

        lista.push_back(p);

        cout << "\nDeseja cadastrar outra pessoa? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    cout << "\n--- Resultados ---\n";
    for (size_t i = 0; i < lista.size(); i++) {
        cout << fixed << setprecision(2);
        cout << lista[i].nome << " - " << lista[i].idade << " anos - "
             << lista[i].categoria << " (IMC: " << lista[i].imc << ")\n";
    }

    return 0;
}