#ifndef PSWIN32_64_H_INCLUDED
#define PSWIN32_64_H_INCLUDED
    #include <dirent.h>
    #include <windows.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <errno.h>
    #include <string.h>
    #include <ctype.h>
    #define MAX_STRING 1000
    #define CH(a) (((a)>='a' && (a)<='z') || ((a)>='A' && (a)<='Z'))?1:0
    char path[MAX_STRING];
    extern char files[MAX_STRING][MAX_STRING];//bude obsahovat mena suborov

    typedef enum bool
    {
        false,
        true
    }bool;
   extern int i;
   extern void sdir(char *location, DIR *t);
   extern int isFile(char *str);
   extern int vigenere(char *file1, char *file2);
   extern void ddir(char *location, DIR *t);
#endif // PSWIN32_64_H_INCLUDED
