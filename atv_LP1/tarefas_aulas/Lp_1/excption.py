class M_Excecao(Exception):
    pass

try:
    x = int(input("Digite um número positivo: "))
    if x > 0:
        print('digite um numero ppositivo')

finally :
    print('finalizou')