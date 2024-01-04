#ifndef CVM_H
#define CVM_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TYPENAME_BOOL "bool"
#define TYPENAME_UNSIGNED_CHAR "unsigned char"
#define TYPENAME_CHAR "char"
#define TYPENAME_SIGNED_CHAR "signed char"
#define TYPENAME_SHORT_INT "short int"
#define TYPENAME_UNSIGNED_CHORT_INT "unsigned short int"
#define TYPENAME_INT "int"
#define TYPENAME_UNSIGNED_INT "unsigned int"
#define TYPENAME_LONG_INT "long int"
#define TYPENAME_UNSIGNED_LONG_INT "unsigned long int"
#define TYPENAME_LONG_LONG_INT "long long int"
#define TYPENAME_UNSIGNED_LONG_LONG_INT "unsigned long long int"
#define TYPENAME_FLOAT "float"
#define TYPENAME_DOUBLE "double"
#define TYPENAME_LONG_DOUBLE "long double"
#define TYPENAME_POINTER_TO_CHAR "pointer to char"
#define TYPENAME_POINTER_TO_VOID "pointer to void"
#define TYPENAME_POINTER_TO_INT "pointer to int"
#define TYPENAME_OTHER "other"

enum t_typename
{
    ENUM_BOOL,
    ENUM_UNSIGNED_CHAR,
    ENUM_CHAR,
    ENUM_SIGNED_CHAR,
    ENUM_SHORT_INT,
    ENUM_UNSIGNED_CHORT_INT,
    ENUM_INT,
    ENUM_UNSIGNED_INT,
    ENUM_LONG_INT,
    ENUM_UNSIGNED_LONG_INT,
    ENUM_LONG_LONG_INT,
    ENUM_UNSIGNED_LONG_LONG_INT,
    ENUM_FLOAT,
    ENUM_DOUBLE,
    ENUM_LONG_DOUBLE,
    ENUM_POINTER_TO_CHAR,
    ENUM_POINTER_TO_VOID,
    ENUM_POINTER_TO_INT,
    ENUM_OTHER
};

#define print_generic(x) _Generic((x),             \
    _Bool: printf("%s", ((x) ? "true" : "false")), \
    char: printf("%c", (x)),                       \
    short int: printf("%hd", (x)),                 \
    unsigned short int: printf("%hu", (x)),        \
    int: printf("%d", (x)),                        \
    unsigned int: printf("%u", (x)),               \
    long int: printf("%ld", (x)),                  \
    unsigned long int: printf("%lu", (x)),         \
    long long int: printf("%lld", (x)),            \
    unsigned long long int: printf("%llu", (x)),   \
    float: printf("%f", (x)),                      \
    double: printf("%lf", (x)),                    \
    long double: printf("%Lf", (x)),               \
    char *: printf("%s", (x)),                     \
    void *: printf("%p", (x)),                     \
    int *: printf("%p", (x)),                      \
    default: printf("<unsupported type>"))

// int print_generic();
typedef void *Objeto;
typedef int (*Print)(const char *String, ...);
typedef int (*PrintLn)(const char *String);
typedef bool (*Comparator)(Objeto obj1, Objeto obj2); // A função Comparator deve retornar True caso os objetos sejam iguais
typedef void (*Free)(Objeto obj);                     // A função Free deve realizar a desalocação de memória do objeto
typedef int (*Printer)(Objeto obj);                   // A função Printer deve definir o objeto realizando sua impressão podendo usar a função print_generic()

struct Stout
{
    Print print;
    PrintLn println;
};

struct StSystem
{
    struct Stout out;
};

typedef struct StEnumerate
{
    Objeto obj;
    size_t index;
} Enumerate;

struct StFree
{
    Free f;
    Objeto obj;
};

typedef struct StCollector
{
    size_t size;
    struct StFree *collector;
} Collector;

extern Objeto self;
extern struct StSystem System;
extern Collector collector;

void CVM();

Objeto This(Objeto o);

void linkToGarbage(Free f, Objeto obj);

void GarbageCollector();

#endif
