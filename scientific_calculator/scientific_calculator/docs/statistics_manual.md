# Manual de Estatísticas - Calculadora Científica

## Visão Geral

O módulo de estatísticas da calculadora científica oferece um conjunto completo de funções para análise estatística de dados, incluindo estatísticas descritivas, correlação, regressão, distribuições probabilísticas e testes estatísticos.

## Funcionalidades Implementadas

### 1. Estatísticas Descritivas

#### Média Aritmética
```cpp
double mean(const double* data, int size);
```
Calcula a média aritmética de um conjunto de dados.

#### Mediana
```cpp
double median(const double* data, int size);
```
Calcula a mediana (valor central) de um conjunto de dados ordenados.

#### Moda
```cpp
double mode(const double* data, int size);
```
Calcula a moda (valor mais frequente) de um conjunto de dados.

#### Desvio Padrão
```cpp
double standard_deviation(const double* data, int size);      // Populacional
double sample_standard_deviation(const double* data, int size); // Amostral
```
Calcula o desvio padrão populacional ou amostral.

#### Variância
```cpp
double variance(const double* data, int size);      // Populacional
double sample_variance(const double* data, int size); // Amostral
```
Calcula a variância populacional ou amostral.

#### Medidas de Dispersão
```cpp
double min_value(const double* data, int size);  // Valor mínimo
double max_value(const double* data, int size);  // Valor máximo
double range(const double* data, int size);      // Amplitude (max - min)
```

### 2. Correlação e Regressão

#### Coeficiente de Correlação de Pearson
```cpp
double correlation(const double* x, const double* y, int size);
```
Calcula o coeficiente de correlação linear entre duas variáveis.

#### Regressão Linear Simples
```cpp
void linear_regression(const double* x, const double* y, int size, 
                      double& slope, double& intercept);
```
Calcula os parâmetros da reta de regressão linear (y = ax + b).

#### Coeficiente de Determinação
```cpp
double coefficient_of_determination(const double* x, const double* y, int size);
```
Calcula o R² (coeficiente de determinação).

### 3. Distribuições Probabilísticas

#### Distribuição Normal Padrão
```cpp
double normal_pdf(double x);  // Função densidade de probabilidade
double normal_cdf(double x);  // Função distribuição acumulada
```

#### Distribuição Binomial
```cpp
double binomial_pdf(int n, int k, double p);  // Função massa de probabilidade
double binomial_cdf(int n, int k, double p);  // Função distribuição acumulada
```

### 4. Testes Estatísticos

#### Teste t para Uma Amostra
```cpp
double t_test_one_sample(const double* data, int size, double hypothesized_mean);
```
Testa se a média da amostra difere significativamente de um valor hipotético.

#### Teste t para Duas Amostras
```cpp
double t_test_two_samples(const double* data1, int size1, 
                         const double* data2, int size2);
```
Testa se as médias de duas amostras independentes diferem significativamente.

## Exemplo de Uso

```cpp
#include "include/math/statistics.h"
using namespace math::statistics;

// Dados de exemplo
double data[] = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0, 10.1};
int size = 10;

// Estatísticas básicas
double media = mean(data, size);
double desvio = sample_standard_deviation(data, size);
double mediana_val = median(data, size);

// Correlação
double x[] = {1, 2, 3, 4, 5};
double y[] = {2, 4, 6, 8, 10};
double corr = correlation(x, y, 5);

// Regressão linear
double slope, intercept;
linear_regression(x, y, 5, slope, intercept);
// Equação: y = slope * x + intercept
```

## Notas Técnicas

### Implementação de Funções Matemáticas
Como a biblioteca padrão C++ não está disponível no ambiente de desenvolvimento, todas as funções matemáticas foram implementadas manualmente:

- **Funções trigonométricas**: Aproximações por séries de Taylor
- **Exponencial**: Série de Taylor para e^x
- **Logaritmo**: Expansão em série para ln(x)
- **Raiz quadrada**: Método de Newton
- **Função erro**: Aproximação polinomial

### Precisão
As implementações usam aproximações que fornecem boa precisão para a maioria das aplicações práticas, mas podem não ser adequadas para cálculos de alta precisão.

### Limitações
- As funções step-by-step estão temporariamente desabilitadas devido à indisponibilidade da biblioteca padrão
- Algumas funções avançadas podem ter limitações de precisão
- O tratamento de casos extremos pode ser limitado

## Estrutura dos Arquivos

```
include/math/statistics.h    - Declarações das funções
src/math/statistics.cpp      - Implementações das funções
examples/statistics_example.cpp - Exemplo de uso
docs/statistics_manual.md    - Este manual
```

## Contribuições

Para adicionar novas funcionalidades estatísticas:

1. Adicione as declarações no arquivo `statistics.h`
2. Implemente as funções no arquivo `statistics.cpp`
3. Adicione exemplos de uso no arquivo de exemplo
4. Atualize este manual com a documentação

## Licença

Este módulo faz parte da calculadora científica e segue a mesma licença do projeto principal.
