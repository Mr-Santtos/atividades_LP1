<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <omp.h>

int main() {
    int limite;
    printf("Digite até qual número deseja verificar: ");
    scanf("%d", &limite);

    bool *eh_primo = malloc((limite + 1) * sizeof(bool));
    int *divisores = calloc(limite + 1, sizeof(int));

    #pragma omp parallel for
    for (int i = 0; i <= limite; i++) {
        eh_primo[i] = true;
        divisores[i] = 0;
    }

    eh_primo[0] = eh_primo[1] = false;

    double t1 = omp_get_wtime(); // Início do cálculo

    int raiz = (int)sqrt(limite);
    for (int p = 2; p <= raiz; p++) {
        if (eh_primo[p]) {
            #pragma omp parallel for schedule(dynamic)
            for (int m = p * 2; m <= limite; m += p) {
                if (eh_primo[m]) {
                    eh_primo[m] = false;
                    if (divisores[m] == 0)
                        divisores[m] = p;
                }
            }
        }
    }

    double t2 = omp_get_wtime(); // Fim do cálculo

    // Gravação no arquivo
    FILE *arquivo = fopen("nao_primos.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }

    int total_primos = 0, total_nao_primos = 0;

    double t3 = omp_get_wtime(); // Início da gravação

    for (int i = 0; i <= limite; i++) {
        if (eh_primo[i]) {
            total_primos++;
        } else {
            total_nao_primos++;
            if (i >= 2 && divisores[i] != 0) {
                fprintf(arquivo, "%d não é primo — primeiro divisor: %d\n", i, divisores[i]);
            }
        }
    }

    fclose(arquivo);
    double t4 = omp_get_wtime(); // Fim da gravação

    // Exibe apenas o resumo
    printf("\n📊 Total de primos: %d\n", total_primos);
    printf("📊 Total de não primos: %d\n", total_nao_primos);
    printf("⏱️ Tempo de cálculo (crivo): %.4f segundos\n", t2 - t1);
    printf("💾 Tempo de gravação no arquivo: %.4f segundos\n", t4 - t3);
    printf("📄 Arquivo salvo como: nao_primos.txt\n");

    free(eh_primo);
    free(divisores);
    return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <omp.h>

int main() {
    int limite;
    printf("Digite até qual número deseja verificar: ");
    scanf("%d", &limite);

    bool *eh_primo = malloc((limite + 1) * sizeof(bool));
    int *divisores = calloc(limite + 1, sizeof(int));

    #pragma omp parallel for
    for (int i = 0; i <= limite; i++) {
        eh_primo[i] = true;
        divisores[i] = 0;
    }

    eh_primo[0] = eh_primo[1] = false;

    double t1 = omp_get_wtime(); // Início do cálculo

    int raiz = (int)sqrt(limite);
    for (int p = 2; p <= raiz; p++) {
        if (eh_primo[p]) {
            #pragma omp parallel for schedule(dynamic)
            for (int m = p * 2; m <= limite; m += p) {
                if (eh_primo[m]) {
                    eh_primo[m] = false;
                    if (divisores[m] == 0)
                        divisores[m] = p;
                }
            }
        }
    }

    double t2 = omp_get_wtime(); // Fim do cálculo

    // Gravação no arquivo
    FILE *arquivo = fopen("nao_primos.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }

    int total_primos = 0, total_nao_primos = 0;

    double t3 = omp_get_wtime(); // Início da gravação

    for (int i = 0; i <= limite; i++) {
        if (eh_primo[i]) {
            total_primos++;
        } else {
            total_nao_primos++;
            if (i >= 2 && divisores[i] != 0) {
                fprintf(arquivo, "%d não é primo — primeiro divisor: %d\n", i, divisores[i]);
            }
        }
    }

    fclose(arquivo);
    double t4 = omp_get_wtime(); // Fim da gravação

    // Exibe apenas o resumo
    printf("\n📊 Total de primos: %d\n", total_primos);
    printf("📊 Total de não primos: %d\n", total_nao_primos);
    printf("⏱️ Tempo de cálculo (crivo): %.4f segundos\n", t2 - t1);
    printf("💾 Tempo de gravação no arquivo: %.4f segundos\n", t4 - t3);
    printf("📄 Arquivo salvo como: nao_primos.txt\n");

    free(eh_primo);
    free(divisores);
    return 0;
}
>>>>>>> 570d47ce00267176900d1a8b293a85b83dde8b6e
