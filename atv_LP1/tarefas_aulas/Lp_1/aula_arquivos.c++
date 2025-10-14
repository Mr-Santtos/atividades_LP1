#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

struct Aluno {
    string nome;
    float n1, n2, n3, media;
};

// entrada de nota
float inputNota(int num) {
    float nota;
    while (true) {
        cout << "Digite a nota " << num << " (0 a 10): ";
        cin >> nota;
        if (cin.fail() || nota < 0 || nota > 10) {
            cout << "⚠️ Entrada inválida. Digite um número entre 0 e 10.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            return nota;
        }
    }
}

// alunos em loop
void adicionarAluno() {
    char continuar = 'S';
    cin.ignore();

    while (toupper(continuar) == 'S') {
        Aluno a;
        cout << "\nDigite o nome do aluno: ";
        getline(cin, a.nome);

        a.n1 = inputNota(1);
        a.n2 = inputNota(2);
        a.n3 = inputNota(3);

        a.media = (a.n1 + a.n2 + a.n3) / 3.0;

        // Salva
        ofstream fNotas("notas.txt", ios::app);
        fNotas << a.nome << " - Notas: " << a.n1 << ", " << a.n2 << ", " << a.n3
               << " - Media: " << a.media << "\n";
        fNotas.close();

        // Classifica
        if (a.media >= 7) {
            ofstream f("aprovados.txt", ios::app);
            f << a.nome << " - Media: " << a.media << "\n";
        } else if (a.media >= 5) {
            ofstream f("exame.txt", ios::app);
            f << a.nome << " - Media: " << a.media
               << " - Notas: " << a.n1 << ", " << a.n2 << ", " << a.n3 << "\n";
        } else {
            ofstream f("reprovados.txt", ios::app);
            f << a.nome << " - Media: " << a.media << "\n";
        }

        cout << "✅ Aluno adicionado com sucesso!\n";

        cout << "\nDeseja adicionar outro aluno? (S/N): ";
        cin >> continuar;
        cin.ignore();
    }
}

// resultados
void verResultados() {
    string linha;
    cout << "\n--- NOTAS ---\n";
    ifstream fNotas("notas.txt");
    while (getline(fNotas, linha)) cout << linha << endl;
    fNotas.close();

    cout << "\n--- APROVADOS ---\n";
    ifstream fAp("aprovados.txt");
    while (getline(fAp, linha)) cout << linha << endl;
    fAp.close();

    cout << "\n--- EXAME ---\n";
    ifstream fEx("exame.txt");
    while (getline(fEx, linha)) cout << linha << endl;
    fEx.close();

    cout << "\n--- REPROVADOS ---\n";
    ifstream fRep("reprovados.txt");
    while (getline(fRep, linha)) cout << linha << endl;
    fRep.close();
}

// Recuperação
void recuperarAluno() {
    string nome;
    cout << "Digite o nome do aluno em exame: ";
    cin.ignore();
    getline(cin, nome);

    float notaRec = inputNota(4);

    // Carrega exame
    ifstream fEx("exame.txt");
    vector<string> linhas;
    string linha;
    bool encontrado = false;
    float n1, n2, n3, mediaAnterior;

    while (getline(fEx, linha)) {
        if (linha.find(nome) != string::npos) {
            encontrado = true;
            // extrai a média
            size_t posMedia = linha.find("Media:");
            if (posMedia != string::npos) {
                sscanf(linha.c_str() + posMedia, "Media: %f", &mediaAnterior);
            }
        
        
            
        } else {
            linhas.push_back(linha);
        }
    }
    fEx.close();

    if (!encontrado) {
        cout << "⚠️ Aluno não encontrado em exame.\n";
        return;
    }

    // nova media
    float mediaFinal = (mediaAnterior + notaRec) / 2.0;

    if (mediaFinal >= 5) {
        ofstream fAp("aprovados.txt", ios::app);
        fAp << nome << " - Aprovado na recuperação - Media final: " << mediaFinal << "\n";
        fAp.close();
        cout << "✅ Aluno aprovado na recuperação!\n";
    } else {
        ofstream fRep("reprovados.txt", ios::app);
        fRep << nome << " - Reprovado na recuperação - Media final: " << mediaFinal << "\n";
        fRep.close();
        cout << "❌ Aluno reprovado mesmo após recuperação.\n";
        }

}

// Menu
int main() {
    int opcao;
    bool rodando = true;

    while (rodando) {
        cout << "\n===== SISTEMA DE NOTAS =====\n";
        cout << "1. Adicionar aluno\n";
        cout << "2. Ver resultados\n";
        cout << "3. Recuperacao (exame)\n";
        cout << "4. Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao) {
            case 1: adicionarAluno(); break;
            case 2: verResultados(); break;
            case 3: recuperarAluno(); break;
            case 4: rodando = false; break;
            default: cout << "⚠️ Opcao invalida!\n";
        }
    }

    cout << "Programa encerrado.\n";
    return 0;
}
