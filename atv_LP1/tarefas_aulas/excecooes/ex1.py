class NumeroImparError(Exception):
    pass

try:
    numero = int(input("Digite um número inteiro: "))

    if numero % 2 != 0:
        raise NumeroImparError("Erro: O número digitado é ímpar.")
    
    print(f"O número {numero} é par!")

except NumeroImparError as e:
    print(e)
except ValueError:
    print("Erro: Entrada inválida, digite um número inteiro.")
