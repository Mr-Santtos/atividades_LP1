<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int eh_primo(int n, int* divisor) {
    if (n < 2) {
        *divisor = 1;
        return 0;
    }
    if (n == 2) return 1;
    if (n % 2 == 0) {
        *divisor = 2;
        return 0;
    }

    int limite = (int)sqrt(n);
    for (int i = 3; i <= limite; i += 2) {
        if (n % i == 0) {
            *divisor = i;
            return 0;
        }
    }
    return 1;
}

int main() {
    int limite;
    printf("Digite até qual número deseja verificar: ");
    if (scanf("%d", &limite) != 1 || limite < 0) {
        printf("Entrada inválida.\n");
        return 1;
    }

    clock_t inicio = clock();

    int total_primos = 0;
    int total_nao_primos = 0;

    printf("\nDivisores dos não primos:\n");

    for (int i = 0; i <= limite; i++) {
        int divisor = 0;
        if (eh_primo(i, &divisor)) {
            total_primos++;
        } else {
            total_nao_primos++;
            if (i >= 2) {
                printf("%d não é primo — primeiro divisor: %d\n", i, divisor);
            }
        }
    }

    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("\nTotal de primos: %d\n", total_primos);
    printf("Total de não primos: %d\n", total_nao_primos);
    printf("Tempo total de execução: %.2f segundos\n", tempo);

    return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int eh_primo(int n, int* divisor) {
    if (n < 2) {
        *divisor = 1;
        return 0;
    }
    if (n == 2) return 1;
    if (n % 2 == 0) {
        *divisor = 2;
        return 0;
    }

    int limite = (int)sqrt(n);
    for (int i = 3; i <= limite; i += 2) {
        if (n % i == 0) {
            *divisor = i;
            return 0;
        }
    }
    return 1;
}

int main() {
    int limite;
    printf("Digite até qual número deseja verificar: ");
    if (scanf("%d", &limite) != 1 || limite < 0) {
        printf("Entrada inválida.\n");
        return 1;
    }

    clock_t inicio = clock();

    int total_primos = 0;
    int total_nao_primos = 0;

    printf("\nDivisores dos não primos:\n");

    for (int i = 0; i <= limite; i++) {
        int divisor = 0;
        if (eh_primo(i, &divisor)) {
            total_primos++;
        } else {
            total_nao_primos++;
            if (i >= 2) {
                printf("%d não é primo — primeiro divisor: %d\n", i, divisor);
            }
        }
    }

    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("\nTotal de primos: %d\n", total_primos);
    printf("Total de não primos: %d\n", total_nao_primos);
    printf("Tempo total de execução: %.2f segundos\n", tempo);

    return 0;
}
>>>>>>> 570d47ce00267176900d1a8b293a85b83dde8b6e
