#ifndef CVM_H
#define CVM_H

typedef int (*Print)(const char *String, ...);
typedef int (*PrintLn)(const char *String);

struct Stout
{
    Print print;
    PrintLn println;
};

struct StSystem
{
    struct Stout out;
};

extern struct StSystem System;


void CVM();


#endif
