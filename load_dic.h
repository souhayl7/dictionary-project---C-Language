#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX         336532
#define MAX_WORD     100
typedef struct mot
{
    int longueur;
    char WORD[100];
    int nombre;
}mot;
typedef struct dictionnaire {
  mot * word ;
}dictionnaire ;
//int memoriser(struct Dictionnaire *dico, char *file);
