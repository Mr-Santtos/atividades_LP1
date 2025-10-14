try:
    numero = int(input("Digite um número inteiro: "))

    if numero == 0:
        raise ZeroDivisionError("Erro: Não é possível dividir por zero.")

    resultado = 10 / numero
    print(f"O resultado de 10 dividido por {numero} é {resultado}")

except ZeroDivisionError as e:
    print(e)
except ValueError:
    print("Erro: Entrada inválida, digite um número inteiro.")
