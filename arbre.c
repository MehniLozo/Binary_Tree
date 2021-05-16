

/**********************************PARTIE IMPLEMENTATION ARBRE BINAIRE******************************/




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

/************************************IMPLEMTNATION FILE*************************************/
void creer_file(struct file* f)
{
    f->tete = NULL;
    f->queue = NULL;
}
unsigned file_vide(struct file f)
{
    return(f.tete == NULL && f.queue == NULL);
}
struct noeud*  premier(struct file f)
{
    assert(!file_vide(f));
    return f.tete->info;
}
void enfiler(struct noeud* x,struct file *f)
{
    struct elem* q;
    q = (struct elem*)malloc(sizeof(struct elem));
    q->suivant = NULL;
    q->info = x;
    
    //there are two cases 
    //empty queue and filled one 
    if(!file_vide(*f))
    
     f->queue->suivant = q;
    else
        f->tete = q;
   //We will add from the queue in both cases 
   
    f->queue = q;
   } 
void defiler(struct file *f)
{
   assert(!file_vide(*f));
    struct elem *q = f->tete;
    f->tete = f->tete->suivant;
    free(q);
    if(f->tete == NULL) //if ever the head is NULL,forcely the queue = NULL AUSSI
        f->queue = NULL;
}
