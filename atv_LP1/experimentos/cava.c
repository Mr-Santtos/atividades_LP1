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

    // Alocação de memória
    bool *eh_primo = malloc((limite + 1) * sizeof(bool));
    int *divisores = calloc(limite + 1, sizeof(int));

    for (int i = 0; i <= limite; i++) {
        eh_primo[i] = true;
        divisores[i] = 0;
    }

    eh_primo[0] = eh_primo[1] = false;

    int raiz = (int)sqrt(limite);
    for (int p = 2; p <= raiz; p++) {
        if (eh_primo[p]) {
            for (int m = p * 2; m <= limite; m += p) {
                if (eh_primo[m]) {
                    eh_primo[m] = false;
                    if (divisores[m] == 0)
                        divisores[m] = p;
                }
            }
        }
    }

    // =============================
    // MÉTODO 1: PRINT no TERMINAL
    // =============================
    clock_t ini_terminal = clock();
    int total_primos = 0, total_nao_primos = 0;

    for (int i = 0; i <= limite; i++) {
        if (eh_primo[i]) {
            total_primos++;
        } else {
            total_nao_primos++;
            if (i >= 2 && divisores[i] != 0)
                printf("%d não é primo — primeiro divisor: %d\n", i, divisores[i]);
        }
    }

    clock_t fim_terminal = clock();
    double tempo_terminal = (double)(fim_terminal - ini_terminal) / CLOCKS_PER_SEC;

    printf("\n[TERMINAL] Total de primos: %d\n", total_primos);
    printf("[TERMINAL] Total de não primos: %d\n", total_nao_primos);
    printf("[TERMINAL] Tempo: %.8f segundos\n", tempo_terminal);

    // =============================
    // MÉTODO 2: SALVAR EM ARQUIVO
    // =============================
    total_primos = 0;
    total_nao_primos = 0;
    FILE *arquivo = fopen("nao_primos.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    clock_t ini_arquivo = clock();

    for (int i = 0; i <= limite; i++) {
        if (eh_primo[i]) {
            total_primos++;
        } else {
            total_nao_primos++;
            if (i >= 2 && divisores[i] != 0)
                fprintf(arquivo, "%d não é primo — primeiro divisor: %d\n", i, divisores[i]);
        }
    }

    fclose(arquivo);
    clock_t fim_arquivo = clock();
    double tempo_arquivo = (double)(fim_arquivo - ini_arquivo) / CLOCKS_PER_SEC;

    printf("\n[ARQUIVO] Total de primos: %d\n", total_primos);
    printf("[ARQUIVO] Total de não primos: %d\n", total_nao_primos);
    printf("[ARQUIVO] Tempo: %.8f segundos\n", tempo_arquivo);

    // Liberação
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

    // Alocação de memória
    bool *eh_primo = malloc((limite + 1) * sizeof(bool));
    int *divisores = calloc(limite + 1, sizeof(int));

    for (int i = 0; i <= limite; i++) {
        eh_primo[i] = true;
        divisores[i] = 0;
    }

    eh_primo[0] = eh_primo[1] = false;

    int raiz = (int)sqrt(limite);
    for (int p = 2; p <= raiz; p++) {
        if (eh_primo[p]) {
            for (int m = p * 2; m <= limite; m += p) {
                if (eh_primo[m]) {
                    eh_primo[m] = false;
                    if (divisores[m] == 0)
                        divisores[m] = p;
                }
            }
        }
    }

    // =============================
    // MÉTODO 1: PRINT no TERMINAL
    // =============================
    clock_t ini_terminal = clock();
    int total_primos = 0, total_nao_primos = 0;

    for (int i = 0; i <= limite; i++) {
        if (eh_primo[i]) {
            total_primos++;
        } else {
            total_nao_primos++;
            if (i >= 2 && divisores[i] != 0)
                printf("%d não é primo — primeiro divisor: %d\n", i, divisores[i]);
        }
    }

    clock_t fim_terminal = clock();
    double tempo_terminal = (double)(fim_terminal - ini_terminal) / CLOCKS_PER_SEC;

    printf("\n[TERMINAL] Total de primos: %d\n", total_primos);
    printf("[TERMINAL] Total de não primos: %d\n", total_nao_primos);
    printf("[TERMINAL] Tempo: %.8f segundos\n", tempo_terminal);

    // =============================
    // MÉTODO 2: SALVAR EM ARQUIVO
    // =============================
    total_primos = 0;
    total_nao_primos = 0;
    FILE *arquivo = fopen("nao_primos.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    clock_t ini_arquivo = clock();

    for (int i = 0; i <= limite; i++) {
        if (eh_primo[i]) {
            total_primos++;
        } else {
            total_nao_primos++;
            if (i >= 2 && divisores[i] != 0)
                fprintf(arquivo, "%d não é primo — primeiro divisor: %d\n", i, divisores[i]);
        }
    }

    fclose(arquivo);
    clock_t fim_arquivo = clock();
    double tempo_arquivo = (double)(fim_arquivo - ini_arquivo) / CLOCKS_PER_SEC;

    printf("\n[ARQUIVO] Total de primos: %d\n", total_primos);
    printf("[ARQUIVO] Total de não primos: %d\n", total_nao_primos);
    printf("[ARQUIVO] Tempo: %.8f segundos\n", tempo_arquivo);

    // Liberação
    free(eh_primo);
    free(divisores);
    return 0;
}
>>>>>>> 570d47ce00267176900d1a8b293a85b83dde8b6e
