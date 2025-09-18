<<<<<<< HEAD
def coleta_pesquisa():
    dados = []
    print("Pesquisa: Perfil dos moradores - uso dos elevadores\n")

    while True:
        elevador = input("Qual elevador utiliza com mais frequência? (A, B, C) ou 'sair' para encerrar: ").strip().upper()
        if elevador == 'SAIR':
            break
        if elevador not in ['A', 'B', 'C']:
            print("Elevador inválido. Digite A, B ou C.")
            continue
        
        periodo = input("Qual período utiliza o elevador? (M=Matutino, V=Vespertino, N=Noturno): ").strip().upper()
        if periodo not in ['M', 'V', 'N']:
            print("Período inválido. Digite M, V ou N.")
            continue
        
        dados.append({'elevador': elevador, 'periodo': periodo})
    
    return dados

def processa_dados(dados):
    if not dados:
        print("Nenhum dado coletado.")
        return

    elevador_periodos = {
        'A': {'M': 0, 'V': 0, 'N': 0},
        'B': {'M': 0, 'V': 0, 'N': 0},
        'C': {'M': 0, 'V': 0, 'N': 0},
    }

    periodos_totais = {'M': 0, 'V': 0, 'N': 0}

    for registro in dados:
        elev = registro['elevador']
        per = registro['periodo']
        elevador_periodos[elev][per] += 1
        periodos_totais[per] += 1

    total_elevadores = {elev: sum(periodos.values()) for elev, periodos in elevador_periodos.items()}
    elev_mais_usado = max(total_elevadores, key=total_elevadores.get)
    qtd_elev_mais_usado = total_elevadores[elev_mais_usado]

    periodo_mais_fluxo_elev = max(elevador_periodos[elev_mais_usado], key=elevador_periodos[elev_mais_usado].get)
    fluxo_mais_periodo_elev = elevador_periodos[elev_mais_usado][periodo_mais_fluxo_elev]

    periodo_mais_usado = max(periodos_totais, key=periodos_totais.get)
    qtd_periodo_mais_usado = periodos_totais[periodo_mais_usado]

    periodo_menos_usado = min(periodos_totais, key=periodos_totais.get)
    qtd_periodo_menos_usado = periodos_totais[periodo_menos_usado]

    if qtd_periodo_menos_usado == 0:
        diferenca_percentual = float('inf') 
    else:
        diferenca_percentual = ((qtd_periodo_mais_usado - qtd_periodo_menos_usado) / qtd_periodo_menos_usado) * 100

    print("\nResultados da Pesquisa:")
    print(f"- Elevador mais utilizado: {elev_mais_usado} com {qtd_elev_mais_usado} usos.")
    print(f"- Período com maior fluxo no elevador {elev_mais_usado}: {periodo_mais_fluxo_elev} ({fluxo_mais_periodo_elev} usos).")
    print(f"- Período mais utilizado de todos: {periodo_mais_usado} ({qtd_periodo_mais_usado} usos).")
    if diferenca_percentual == float('inf'):
        print("- Diferença percentual: Não é possível calcular (divisão por zero).")
    else:
        print(f"- Diferença percentual entre o período mais usado e o menos usado: {diferenca_percentual:.2f}%")

def main():
    dados = coleta_pesquisa()
    processa_dados(dados)

if __name__ == "__main__":
    main()
=======
def coleta_pesquisa():
    dados = []
    print("Pesquisa: Perfil dos moradores - uso dos elevadores\n")

    while True:
        elevador = input("Qual elevador utiliza com mais frequência? (A, B, C) ou 'sair' para encerrar: ").strip().upper()
        if elevador == 'SAIR':
            break
        if elevador not in ['A', 'B', 'C']:
            print("Elevador inválido. Digite A, B ou C.")
            continue
        
        periodo = input("Qual período utiliza o elevador? (M=Matutino, V=Vespertino, N=Noturno): ").strip().upper()
        if periodo not in ['M', 'V', 'N']:
            print("Período inválido. Digite M, V ou N.")
            continue
        
        dados.append({'elevador': elevador, 'periodo': periodo})
    
    return dados

def processa_dados(dados):
    if not dados:
        print("Nenhum dado coletado.")
        return

    elevador_periodos = {
        'A': {'M': 0, 'V': 0, 'N': 0},
        'B': {'M': 0, 'V': 0, 'N': 0},
        'C': {'M': 0, 'V': 0, 'N': 0},
    }

    periodos_totais = {'M': 0, 'V': 0, 'N': 0}

    for registro in dados:
        elev = registro['elevador']
        per = registro['periodo']
        elevador_periodos[elev][per] += 1
        periodos_totais[per] += 1

    total_elevadores = {elev: sum(periodos.values()) for elev, periodos in elevador_periodos.items()}
    elev_mais_usado = max(total_elevadores, key=total_elevadores.get)
    qtd_elev_mais_usado = total_elevadores[elev_mais_usado]

    periodo_mais_fluxo_elev = max(elevador_periodos[elev_mais_usado], key=elevador_periodos[elev_mais_usado].get)
    fluxo_mais_periodo_elev = elevador_periodos[elev_mais_usado][periodo_mais_fluxo_elev]

    periodo_mais_usado = max(periodos_totais, key=periodos_totais.get)
    qtd_periodo_mais_usado = periodos_totais[periodo_mais_usado]

    periodo_menos_usado = min(periodos_totais, key=periodos_totais.get)
    qtd_periodo_menos_usado = periodos_totais[periodo_menos_usado]

    if qtd_periodo_menos_usado == 0:
        diferenca_percentual = float('inf') 
    else:
        diferenca_percentual = ((qtd_periodo_mais_usado - qtd_periodo_menos_usado) / qtd_periodo_menos_usado) * 100

    print("\nResultados da Pesquisa:")
    print(f"- Elevador mais utilizado: {elev_mais_usado} com {qtd_elev_mais_usado} usos.")
    print(f"- Período com maior fluxo no elevador {elev_mais_usado}: {periodo_mais_fluxo_elev} ({fluxo_mais_periodo_elev} usos).")
    print(f"- Período mais utilizado de todos: {periodo_mais_usado} ({qtd_periodo_mais_usado} usos).")
    if diferenca_percentual == float('inf'):
        print("- Diferença percentual: Não é possível calcular (divisão por zero).")
    else:
        print(f"- Diferença percentual entre o período mais usado e o menos usado: {diferenca_percentual:.2f}%")

def main():
    dados = coleta_pesquisa()
    processa_dados(dados)

if __name__ == "__main__":
    main()
>>>>>>> 570d47ce00267176900d1a8b293a85b83dde8b6e
