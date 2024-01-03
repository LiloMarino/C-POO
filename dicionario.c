#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct KeyValuePair {
    char key[50];
    char value[50];
    struct KeyValuePair* next;
};

typedef struct KeyValuePair KeyValuePair;

void adicionarElemento(KeyValuePair** lista, const char* chave, const char* valor) {
    KeyValuePair* novoElemento = (KeyValuePair*)malloc(sizeof(KeyValuePair));
    strcpy(novoElemento->key, chave);
    strcpy(novoElemento->value, valor);
    novoElemento->next = *lista;
    *lista = novoElemento;
}

void imprimirLista(KeyValuePair* lista) {
    while (lista != NULL) {
        printf("%s: %s\n", lista->key, lista->value);
        lista = lista->next;
    }
}

int main() {
    KeyValuePair* lista = NULL;

    adicionarElemento(&lista, "Nome", "João");
    adicionarElemento(&lista, "Idade", "25");
    adicionarElemento(&lista, "Altura", "1.75");

    imprimirLista(lista);

    return 0;
}
