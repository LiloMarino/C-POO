#include <stdio.h>

typedef int (*Clausura)(int);

Clausura criarClausura(int valorCapturado) {
    int funcaoInterna(int parametro) {
        return valorCapturado + parametro;
    }
    return funcaoInterna;
}

int main() {
    Clausura minhaClausura = criarClausura(5);
    
    // Agora, você pode chamar minhaClausura como uma função normal
    int resultado = minhaClausura(1);
    printf("Resultado: %d\n", resultado);  // Deve imprimir 6
    resultado = minhaClausura(2);
    printf("Resultado: %d\n", resultado);  // Deve imprimir 7
    resultado = minhaClausura(3);
    printf("Resultado: %d\n", resultado);  // Deve imprimir 8
    resultado = minhaClausura(4);
    printf("Resultado: %d\n", resultado);  // Deve imprimir 9
    
    minhaClausura = criarClausura(10);
    resultado = minhaClausura(1);
    printf("Resultado: %d\n", resultado);  // Deve imprimir 11
    resultado = minhaClausura(2);
    printf("Resultado: %d\n", resultado);  // Deve imprimir 12
    resultado = minhaClausura(3);
    printf("Resultado: %d\n", resultado);  // Deve imprimir 13
    resultado = minhaClausura(4);
    printf("Resultado: %d\n", resultado);  // Deve imprimir 14
    
    
    
    return 0;
}
