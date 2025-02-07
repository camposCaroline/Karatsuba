# Algoritmo de Multiplicação de Karatsuba

## Descrição Geral
Este programa implementa o algoritmo de multiplicação de Karatsuba em linguagem C. O objetivo é realizar a multiplicação eficiente de dois números grandes de forma recursiva, reduzindo a quantidade de multiplicações necessárias em comparação com o método tradicional.

O programa também conta com um contador global para medir quantas vezes a função recursiva `karatsuba` é chamada ao longo da execução.

##Estrutura do Código

O código está dividido em:

- **Interface**:
  -Declaração do contador global `contador`.
  -Declaração da função `karatsuba(int, int)`, responsável por calcular a multiplicação.

- **Função `main`**
  - Define alguns valores de entrada para multiplicação.
  - Chama a função `karatsuba` com os valores definidos.
  - Exibe os resultados no console.
  - Reinicializa o contador para testar com novos valores.

- **Implementação da Função `:karatsuba`**
  - Caso base: se os números têm apenas um dígito, realiza a multiplicação diretamente.
  - Caso recursivo:
    - Determina o maior número de dígitos entre `a` e `b`.
    - Divide os números em partes "altas" e "baixas".
    - Aplica a fórmula de Karatsuba para calcular o resultado.

##Explicação das Variáveis

As variáveis foram nomeadas com base na atividade proposta para tornar a compreensão do algoritmo mais intuitiva:

- `altoA`, `baixoA`: representam as partes alta e baixa do número a.
- `altoB`, `baixoB`: representam as partes alta e baixa do número b.
- `multAltos`: resultado da multiplicação das partes altas.
- `multBaixos`: resultado da multiplicação das partes baixas.
- `multSoma`: resultado da multiplicação da soma das partes.
- `metade`: determina a divisão dos números em partes altas e baixas.

##Como Compilar e Executar

Para compilar o programa, utilize um compilador de C, como `gcc`:
```bash
gcc -o karatsuba CarolineGuimaraesCampos_Karatsuba.c -lm
```
Para executar:
```bash
./karatsuba
```
##Exemplo de Saída
```bash
A = 12345  B = 6789  C = 83755845
Chamadas = 7

A = 1234  B = 987654  C = 1218698436
Chamadas = 7
```
