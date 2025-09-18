<<<<<<< HEAD
def coleta_pesquisa():
    dados = []
    print("pesquisa sobre as chances do brasil ganhar a copa 2026")

    while True:
        geracao = input("digite a geração (X,Y,Z) ou 'sair' pra finalizar: ").strip().capitalize()
        if geracao.lower() == "sair":
            break
        if geracao not in ['X', 'Y', 'Z']:
            print("geração inválida digite (X, Y, Z)")
            continue

        sexo = input("Digite o sexo (Masculino/Feminino): ").strip().capitalize()
        if sexo not in ['Masculino', 'Feminino']:
            print("Sexo inválido. Use 'Masculino' ou 'Feminino'.")
            continue
        
        pratica = input("Pratica/Praticou futebol? (Sim/Não): ").strip().capitalize()
        if pratica.lower() not in ['sim', 'não', 'nao']:
            print("Resposta inválida. Use 'Sim' ou 'Não'.")
            continue
        pratica = 'Sim' if pratica.lower() == 'sim' else 'Não'

        ganhar = input("O Brasil vai ganhar a copa de 2026? (Sim/Não): ").strip().capitalize()
        if ganhar.lower() not in ['sim', 'não', 'nao']:
            print("Resposta inválida. Use 'Sim' ou 'Não'.")
            continue
        ganhar = 'Sim' if ganhar.lower() == 'sim' else 'Não'

        dados.append({
            'geracao': geracao,
            'sexo': sexo,
            'pratica': pratica,
            'ganhar': ganhar,
        })
    return dados

def calculadora_percentual(dados, chave):
    resultado = {}

    for registros in dados:
        categoria = registros[chave]
        if categoria not in resultado:
            resultado[categoria] = {'Sim': 0, 'Não': 0, 'total': 0}
        
        resposta = registros['ganhar']
        resultado[categoria][resposta] += 1
        resultado[categoria]['total'] += 1

    for cat, contagem in resultado.items():
        total = contagem['total']
        sim_percent = (contagem['Sim'] / total) * 100 if total > 0 else 0
        nao_percent = (contagem['Não'] / total) * 100 if total > 0 else 0
        resultado[cat] = (sim_percent, nao_percent)
    
    return resultado

def exibe_resultados(titulo, dados_percentuais):
    print(f"\n{titulo}:")
    for categoria, (sim_p, nao_p) in dados_percentuais.items():
        print(f"{categoria}: {sim_p:.0f}% ganhar, {nao_p:.0f}% perder")

def main():
    dados = coleta_pesquisa()
    if not dados:
        print("nenhuma pesquisa foi registrada")
        return
    
    geracao = calculadora_percentual(dados, 'geracao')
    sexo = calculadora_percentual(dados, 'sexo')
    pratica = calculadora_percentual(dados, 'pratica')

    exibe_resultados("Por geração", geracao)
    exibe_resultados("Por sexo", sexo)
    exibe_resultados("Por prática de futebol", pratica)

if __name__ == "__main__":
    main()
=======
def coleta_pesquisa():
    dados = []
    print("pesquisa sobre as chances do brasil ganhar a copa 2026")

    while True:
        geracao = input("digite a geração (X,Y,Z) ou 'sair' pra finalizar: ").strip().capitalize()
        if geracao.lower() == "sair":
            break
        if geracao not in ['X', 'Y', 'Z']:
            print("geração inválida digite (X, Y, Z)")
            continue

        sexo = input("Digite o sexo (Masculino/Feminino): ").strip().capitalize()
        if sexo not in ['Masculino', 'Feminino']:
            print("Sexo inválido. Use 'Masculino' ou 'Feminino'.")
            continue
        
        pratica = input("Pratica/Praticou futebol? (Sim/Não): ").strip().capitalize()
        if pratica.lower() not in ['sim', 'não', 'nao']:
            print("Resposta inválida. Use 'Sim' ou 'Não'.")
            continue
        pratica = 'Sim' if pratica.lower() == 'sim' else 'Não'

        ganhar = input("O Brasil vai ganhar a copa de 2026? (Sim/Não): ").strip().capitalize()
        if ganhar.lower() not in ['sim', 'não', 'nao']:
            print("Resposta inválida. Use 'Sim' ou 'Não'.")
            continue
        ganhar = 'Sim' if ganhar.lower() == 'sim' else 'Não'

        dados.append({
            'geracao': geracao,
            'sexo': sexo,
            'pratica': pratica,
            'ganhar': ganhar,
        })
    return dados

def calculadora_percentual(dados, chave):
    resultado = {}

    for registros in dados:
        categoria = registros[chave]
        if categoria not in resultado:
            resultado[categoria] = {'Sim': 0, 'Não': 0, 'total': 0}
        
        resposta = registros['ganhar']
        resultado[categoria][resposta] += 1
        resultado[categoria]['total'] += 1

    for cat, contagem in resultado.items():
        total = contagem['total']
        sim_percent = (contagem['Sim'] / total) * 100 if total > 0 else 0
        nao_percent = (contagem['Não'] / total) * 100 if total > 0 else 0
        resultado[cat] = (sim_percent, nao_percent)
    
    return resultado

def exibe_resultados(titulo, dados_percentuais):
    print(f"\n{titulo}:")
    for categoria, (sim_p, nao_p) in dados_percentuais.items():
        print(f"{categoria}: {sim_p:.0f}% ganhar, {nao_p:.0f}% perder")

def main():
    dados = coleta_pesquisa()
    if not dados:
        print("nenhuma pesquisa foi registrada")
        return
    
    geracao = calculadora_percentual(dados, 'geracao')
    sexo = calculadora_percentual(dados, 'sexo')
    pratica = calculadora_percentual(dados, 'pratica')

    exibe_resultados("Por geração", geracao)
    exibe_resultados("Por sexo", sexo)
    exibe_resultados("Por prática de futebol", pratica)

if __name__ == "__main__":
    main()
>>>>>>> 570d47ce00267176900d1a8b293a85b83dde8b6e
