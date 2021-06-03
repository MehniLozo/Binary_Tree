#include <stdio.h>
#include "liste.h"

static struct liste l;

void creer_liste()
{
    l.premier = NULL;
    l.dernier = NULL;
}
unsigned liste_vide()
{
    return l.premier == NULL && l.dernier== NULL;
}
void initialiser(struct noeud* x)
{
    struct elem* q = (struct elem*)malloc(sizeof(struct elem));
    q->info = x;
    q->suivant = NULL;
    l.premier = q;
    l.dernier = NULL;
}
void ajouter_av_premier(struct noeud* x)
{
    
        struct elem* q = (struct elem*)malloc(sizeof(struct elem));
        q->info = x;
        if(!liste_vide())
            q->suivant = l.premier;
        else 
        {
            q->suivant = NULL;
            l.dernier = q;
        }   
    
        l.premier = q;
    

}
void ajouter_ap_dernier(struct noeud* x)
{
       struct elem* q = (struct elem*)malloc(sizeof(struct elem));
        q->info = x;
        q->suivant = NULL;

        if(liste_vide())
            l.premier = q;
        else 
            l.dernier->suivant = q;
        l.dernier = q;
}
void ajouter_ap_ref(struct noeud* x,struct elem* p)
{
    struct elem* q = (struct elem*)malloc(sizeof(struct elem));
    q->info = x;
    if(liste_vide())
         initialiser(x);
    else{
        q->suivant = p->suivant;
        p->suivant = q;
        if(p == l.dernier)
            l.dernier = p;
    }
}
void ajout_trie(struct noeud* x)
{
    /*
     *There should be these cases:
        -empty list: initialise the list and you're up ready
        -full list:
            -add the x in the proper position so that in order to keep
            and ordered list
                -our x's info is inferior than the first cell info:
                    add the x just before the lists first element
                - x's info is inferior to some other cell's info in the middle

     * */
    
    struct elem* q = l.premier,*prec = NULL;

    if(liste_vide())
    {
        initialiser(x);
        return;
    }

    

    while(q && x->info > q->info->info )
    {
        prec = q;
        q = q->suivant;

    }
    if(q== l.premier)
        ajouter_av_premier(x);
    else
        ajouter_ap_ref(x,prec);

}
void affiche()
{ 
    printf("\n");
    struct elem* p = l.premier;
    while(p)
    {
        printf("%d\t",p->info->info);
        p = p->suivant;
    }
    printf("\n");
}
