#include <stdio.h>
#include <stdlib.h>

// Definindo uma estrutura que contém uma função e uma variável de captura
typedef struct {
    int (*funcao)(int);
    int variavelCaptura;
} Clausura;

// Função que cria e retorna uma clausura
Clausura criarClausura(int valorCapturado) {
    // Definindo uma função interna
    int funcaoInterna(int parametro) {
        return parametro + valorCapturado;
    }

    // Criando a clausura
    Clausura clausura;
    clausura.funcao = funcaoInterna;
    clausura.variavelCaptura = valorCapturado;

    return clausura;
}

int main() {
    // Criando uma clausura com valor de captura 5
    Clausura minhaClausura = criarClausura(5);

    // Chamando a função dentro da clausura
    int resultado = minhaClausura.funcao(10);
    resultado = minhaClausura.funcao(5);

    printf("Resultado: %d\n", resultado);

    return 0;
}
