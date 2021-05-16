#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "arbre.c"


int main()
{




    /*************************TESTING*****************/ 
   struct noeud a;
   
  struct noeud* sag = (struct noeud*)malloc(sizeof(struct noeud));
  sag -> sag = NULL;
  sag-> sad = NULL;
  sag -> info = 'c';
  struct noeud* sad = (struct noeud*)malloc(sizeof(struct noeud));
  sad -> sag = NULL;
  sad-> sad = NULL;
  sad -> info = 'e';

  a.sad = sad;
  a.sag = sag;
    
    printf("Sad = %c\n",a.sad->info);
    printf("Sag = %c\n",a.sag->info);




return 0;}
