<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>


int main() {
    int limite;
    printf("Digite até qual número deseja verificar: ");
    scanf("%d", &limite);

    clock_t inicio = clock();

    // Aloca vetor de flags (true = primo, false = não primo)
    bool *eh_primo = malloc((limite + 1) * sizeof(bool));
    int *divisores = calloc(limite + 1, sizeof(int));

    for (int i = 0; i <= limite; i++) {
        eh_primo[i] = true;
        divisores[i] = 0;
    }

    eh_primo[0] = false;
    eh_primo[1] = false;

    int raiz = (int)sqrt(limite);

    for (int p = 2; p <= raiz; p++) {
        if (eh_primo[p]) {
            for (int m = p * 2; m <= limite; m += p) {
                if (eh_primo[m]) {
                    eh_primo[m] = false;
                    if (divisores[m] == 0)
                        divisores[m] = p; // salva o primeiro divisor
                }
            }
        }
    }

    // Estatísticas
    int total_primos = 0, total_nao_primos = 0;
    printf("\nDivisores dos não primos:\n");
    for (int i = 0; i <= limite; i++) {
        if (eh_primo[i]) {
            total_primos++;
        } else {
            total_nao_primos++;
            if (i >= 2 && divisores[i] != 0)
                printf("%d não é primo — primeiro divisor: %d\n", i, divisores[i]);
        }
    }

    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("\nTotal de primos: %d\n", total_primos);
    printf("Total de não primos: %d\n", total_nao_primos);
    printf("Tempo total de execução: %.2f segundos\n", tempo);

    free(eh_primo);
    free(divisores);
    return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>


int main() {
    int limite;
    printf("Digite até qual número deseja verificar: ");
    scanf("%d", &limite);

    clock_t inicio = clock();

    // Aloca vetor de flags (true = primo, false = não primo)
    bool *eh_primo = malloc((limite + 1) * sizeof(bool));
    int *divisores = calloc(limite + 1, sizeof(int));

    for (int i = 0; i <= limite; i++) {
        eh_primo[i] = true;
        divisores[i] = 0;
    }

    eh_primo[0] = false;
    eh_primo[1] = false;

    int raiz = (int)sqrt(limite);

    for (int p = 2; p <= raiz; p++) {
        if (eh_primo[p]) {
            for (int m = p * 2; m <= limite; m += p) {
                if (eh_primo[m]) {
                    eh_primo[m] = false;
                    if (divisores[m] == 0)
                        divisores[m] = p; // salva o primeiro divisor
                }
            }
        }
    }

    // Estatísticas
    int total_primos = 0, total_nao_primos = 0;
    printf("\nDivisores dos não primos:\n");
    for (int i = 0; i <= limite; i++) {
        if (eh_primo[i]) {
            total_primos++;
        } else {
            total_nao_primos++;
            if (i >= 2 && divisores[i] != 0)
                printf("%d não é primo — primeiro divisor: %d\n", i, divisores[i]);
        }
    }

    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("\nTotal de primos: %d\n", total_primos);
    printf("Total de não primos: %d\n", total_nao_primos);
    printf("Tempo total de execução: %.2f segundos\n", tempo);

    free(eh_primo);
    free(divisores);
    return 0;
}
>>>>>>> 570d47ce00267176900d1a8b293a85b83dde8b6e
