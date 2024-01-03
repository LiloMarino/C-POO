#include <stdio.h>
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


#define print_generic(x) _Generic((x), \
    _Bool: printf("%s: %s\n", TYPENAME_BOOL, ((x) ? "true" : "false")), \
    unsigned char: printf("%s: %c\n", TYPENAME_UNSIGNED_CHAR, (x)), \
    char: printf("%s: %c\n", TYPENAME_CHAR, (x)), \
    signed char: printf("%s: %c\n", TYPENAME_SIGNED_CHAR, (x)), \
    short int: printf("%s: %hd\n", TYPENAME_SHORT_INT, (x)), \
    unsigned short int: printf("%s: %hu\n", TYPENAME_UNSIGNED_CHORT_INT, (x)), \
    int: printf("%s: %d\n", TYPENAME_INT, (x)), \
    unsigned int: printf("%s: %u\n", TYPENAME_UNSIGNED_INT, (x)), \
    long int: printf("%s: %ld\n", TYPENAME_LONG_INT, (x)), \
    unsigned long int: printf("%s: %lu\n", TYPENAME_UNSIGNED_LONG_INT, (x)), \
    long long int: printf("%s: %lld\n", TYPENAME_LONG_LONG_INT, (x)), \
    unsigned long long int: printf("%s: %llu\n", TYPENAME_UNSIGNED_LONG_LONG_INT, (x)), \
    float: printf("%s: %f\n", TYPENAME_FLOAT, (x)), \
    double: printf("%s: %lf\n", TYPENAME_DOUBLE, (x)), \
    long double: printf("%s: %Lf\n", TYPENAME_LONG_DOUBLE, (x)), \
    char *: printf("%s: %s\n", TYPENAME_POINTER_TO_CHAR, (x)), \
    void *: printf("%s: %p\n", TYPENAME_POINTER_TO_VOID, (x)), \
    int *: printf("%s: %p\n", TYPENAME_POINTER_TO_INT, (x)), \
    default: printf("%s: <unsupported type>\n", TYPENAME_OTHER) \
)
int main() {
    int a = 42;
    float b = 3.14;
    char *c = "Hello";
    bool teste = true;
    
    print_generic(a);
    print_generic(b);
    print_generic(c);
    print_generic(teste);

    return 0;
}
