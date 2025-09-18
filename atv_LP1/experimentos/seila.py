<<<<<<< HEAD
import math
import time

def eh_primo(n):
    if n < 2:
        return False, 1
    if n == 2:
        return True, None
    if n % 2 == 0:
        return False, 2

    limite = int(math.sqrt(n))
    for i in range(3, limite + 1, 2):
        if n % i == 0:
            return False, i
    return True, None

def main():
    try:
        limite = int(input("Digite até qual número deseja verificar: "))
        if limite < 0:
            raise ValueError
    except ValueError:
        print("Entrada inválida.")
        return

    inicio = time.time()

    total_primos = 0
    total_nao_primos = 0

    print("\nDivisores dos não primos:")

    for i in range(limite + 1):
        primo, divisor = eh_primo(i)
        if primo:
            total_primos += 1
        else:
            total_nao_primos += 1
            if i >= 2:
                print(f"{i} não é primo — primeiro divisor: {divisor}")

    fim = time.time()
    tempo = fim - inicio

    print(f"\nTotal de primos: {total_primos}")
    print(f"Total de não primos: {total_nao_primos}")
    print(f"Tempo total de execução: {tempo:.6f} segundos")

if __name__ == "__main__":
    main()
=======
import math
import time

def eh_primo(n):
    if n < 2:
        return False, 1
    if n == 2:
        return True, None
    if n % 2 == 0:
        return False, 2

    limite = int(math.sqrt(n))
    for i in range(3, limite + 1, 2):
        if n % i == 0:
            return False, i
    return True, None

def main():
    try:
        limite = int(input("Digite até qual número deseja verificar: "))
        if limite < 0:
            raise ValueError
    except ValueError:
        print("Entrada inválida.")
        return

    inicio = time.time()

    total_primos = 0
    total_nao_primos = 0

    print("\nDivisores dos não primos:")

    for i in range(limite + 1):
        primo, divisor = eh_primo(i)
        if primo:
            total_primos += 1
        else:
            total_nao_primos += 1
            if i >= 2:
                print(f"{i} não é primo — primeiro divisor: {divisor}")

    fim = time.time()
    tempo = fim - inicio

    print(f"\nTotal de primos: {total_primos}")
    print(f"Total de não primos: {total_nao_primos}")
    print(f"Tempo total de execução: {tempo:.6f} segundos")

if __name__ == "__main__":
    main()
>>>>>>> 570d47ce00267176900d1a8b293a85b83dde8b6e
