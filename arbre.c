

/****************PARTIE IMPLEMENTATION ARBRE BINAIRE************/




#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "arbre.h"


struct noeud* creer_arbre()
{
    return NULL;
}
unsigned arbre_vide(struct noeud* a)
{
    return a == NULL;
}
struct noeud* construire(char x ,struct noeud* sag,struct noeud* sad)
{
  struct noeud* a = (struct noeud*)malloc(sizeof(struct noeud*));
      a->info =  x;
      a->sag = sag;
      a->sad = sad;
    return a;

}
struct noeud* gauche(struct noeud* a)
{
    assert(!arbre_vide(a));
    return a->sag;
}
struct noeud* droite(struct noeud* a)
{
    assert(!arbre_vide(a));
    return a->sad;
}
char lire_racine(struct noeud *a)
{
    assert(!arbre_vide(a));
    return a->info;
}
