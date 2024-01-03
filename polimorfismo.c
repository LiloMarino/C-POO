#include <stdio.h>

// Definindo uma "classe" base chamada Animal
typedef struct {
    const char* nome;
    void (*fazerBarulho)();
} Animal;

// Definindo uma "classe" derivada chamada Gato que herda de Animal
typedef struct {
    Animal base;
    void (*ronronar)();
} Gato;

// Métodos para animais específicos
void latir() {
    printf("Au au!\n");
}

void miar() {
    printf("Miau!\n");
}

void ronronar() {
    printf("Purr purr...\n");
}

// Construtor para inicializar um Animal
Animal criarAnimal(const char* nome, void (*fazerBarulho)()) {
    Animal animal;
    animal.nome = nome;
    animal.fazerBarulho = fazerBarulho;
    return animal;
}

// Construtor para inicializar um Gato
Gato criarGato(const char* nome) {
    Gato gato;
    gato.base = criarAnimal(nome, miar);
    gato.ronronar = ronronar;
    return gato;
}

int main() {
    // Criando instâncias de animais
    Animal cachorro = criarAnimal("Cachorro", latir);
    Gato gato = criarGato("Gato");

    // Chamando métodos de forma polimórfica
    printf("%s faz: ", cachorro.nome);
    cachorro.fazerBarulho();

    printf("%s faz: ", gato.base.nome);
    gato.base.fazerBarulho();
    printf("%s também ronrona: ", gato.base.nome);
    gato.ronronar();

    return 0;
}
