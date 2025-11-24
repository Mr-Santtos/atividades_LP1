1) Arquivo filmes.csv

Crie um arquivo chamado filmes.csv com este conteúdo:

1982,TRON
1983,WarGames
1995,Hackers
1999,Pirates of Silicon Valley
2010,The Social Network
2013,Jobs
2014,The Imitation Game
2014,Ex Machina
2016,Snowden
2018,Ready Player One

✅ 2) Criar repositório no GitHub

Nome: atividade-13-10-2025
Depois você vai subir todos os arquivos .py + .csv.

✅ 3) Script avaliacao.py

Objetivo:

Ler filmes.csv

Pedir nota para cada filme (0–10)

Tratar valores inválidos

Gerar arquivo filmes_avaliacao.csv

✔ Código (avaliacao.py)
import csv

# Arquivo de entrada e saída
entrada = "filmes.csv"
saida = "filmes_avaliacao.csv"

filmes_avaliados = []

with open(entrada, "r", encoding="utf-8") as f:
    leitor = csv.reader(f)
    
    for ano, titulo in leitor:
        while True:
            try:
                nota = float(input(f"Digite a nota para '{titulo}' ({ano}) [0 a 10]: "))
                if 0 <= nota <= 10:
                    break
                else:
                    print("Nota inválida! Digite um valor entre 0 e 10.")
            except ValueError:
                print("Entrada inválida! Digite um número.")
        
        filmes_avaliados.append([ano, titulo, nota])

# Salva em arquivo
with open(saida, "w", newline="", encoding="utf-8") as f:
    escritor = csv.writer(f)
    escritor.writerow(["Ano", "Título", "Nota"])
    escritor.writerows(filmes_avaliados)

print("Arquivo 'filmes_avaliacao.csv' criado com sucesso!")

✅ 4) Script indicacao.py

Objetivo:

Ler filmes_avaliacao.csv

Selecionar os 5 com maior nota

Empate → ordenar por título

Salvar em filmes_indicacao.csv

✔ Código (indicacao.py)
import csv

entrada = "filmes_avaliacao.csv"
saida = "filmes_indicacao.csv"

filmes = []

with open(entrada, "r", encoding="utf-8") as f:
    leitor = csv.reader(f)
    next(leitor)  # pular cabeçalho

    for ano, titulo, nota in leitor:
        filmes.append([ano, titulo, float(nota)])

# Ordenação:
# 1º: nota (decrescente)
# 2º: título (alfabético)
filmes.sort(key=lambda x: (-x[2], x[1]))

top5 = filmes[:5]

# Salvar arquivo
with open(saida, "w", newline="", encoding="utf-8") as f:
    escritor = csv.writer(f)
    escritor.writerow(["Ano", "Título", "Nota"])
    escritor.writerows(top5)

print("Arquivo 'filmes_indicacao.csv' criado com sucesso!")

✅ 5) Script top_filmes.py

Objetivo:

Ler filmes_indicacao.csv

Imprimir do maior para o menor

✔ Código (top_filmes.py)
import csv

entrada = "filmes_indicacao.csv"

filmes = []

with open(entrada, "r", encoding="utf-8") as f:
    leitor = csv.reader(f)
    next(leitor)

    for ano, titulo, nota in leitor:
        filmes.append([ano, titulo, float(nota)])

# Já estão ordenados no arquivo, mas garanto:
filmes.sort(key=lambda x: -x[2])

print("\n=== TOP FILMES INDICADOS ===\n")

for ano, titulo, nota in filmes:
    print(f"{titulo} ({ano}) - Nota: {nota}")

print("\n=============================\n")
