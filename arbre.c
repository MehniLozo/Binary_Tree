

/**********************************PARTIE IMPLEMENTATION ARBRE BINAIRE******************************/




#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "liste.c"


struct noeud* creer_arbre()
{
    return NULL;
}
unsigned arbre_vide(struct noeud* a)
{
    return a == NULL;
}
struct noeud* construire(int x ,struct noeud* sag,struct noeud* sad)
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
int lire_racine(struct noeud *a)
{
    assert(!arbre_vide(a));
    return a->info;
}

unsigned arbre_confondues(struct noeud *ra,struct noeud *rb)
{

   /*Two trees are identical when they have same data and arrangement of data is also same. To identify if two trees are identical, we need to traverse both
     trees simultaneously, and while traversing we need to compare
    data and children of the trees*/ 

    /*idea is.. you will kind of mimic the display algorithm
      and instead of displaying the nodes content you're gonna compare.
      Obviously,you're gonna need two queues for the job
        cases:
            -same position nodes are/n't equal
      */

    assert(!arbre_vide(ra));
    assert(!arbre_vide(rb));
    struct file fa,fb;
    
    creer_file(&fa);
    creer_file(&fb);

    struct noeud* ta = ra,*tb = rb;

    enfiler(ta,&fa);
    enfiler(tb,&fb);

    printf("\n");
    while(!file_vide(fa) && !file_vide(fb))
    {
        ta = premier(fa);
        tb = premier(fb);
    

      if(ta->info != tb->info)
            return 0;
        defiler(&fa);
        defiler(&fb);   
       
        if(ta->sag)
            enfiler(ta->sag,&fa);
        if(ta->sad)
           enfiler(ta->sad,&fa);

        if(tb->sag)
            enfiler(tb->sag,&fb);
        if(ta->sad)
           enfiler(tb->sad,&fb);




    }



return 1;
}

unsigned est_degeneree(struct noeud *abr)
{
    //Degenerated/pathological
    /*Un
     * arbre binaire est dit dégénéré si
     chacun de ses noeuds a au plus un fils.*/
    
  
    struct noeud *q = abr;
    while(q)
    {
        if(q->sag && q->sad)
            return 0;
        if(q->sag)
            q = q->sag;
        else
            q = q->sad;
    
   }
return 1;
}
unsigned profondeur(struct noeud* abr)
{
   /*Approach is quite similar to "Level Order Traversal" (parcous par niveau)
    * initialise height = 0
    * "NULL" is gonna be used as a"marker"at "every level",so whenever we encounter
    * "NULL" we will increment the height+1
    *  -First add root to the QUEUE and add NULL as well as its marker
    *  -Extract a node from QUEUE
    *  -Check if it is "NULL" ,it means either we reached to the end of level or
    *   entire tree is traversed
    *  -So before adding NULL as marker to the next level,check if queue is 
    *  empty,which means we have traveled all the levels and if not empty
    *  then add NULL as marker and increase height +1
    *
    * */
    /*
     *WHEN SHOULD WE PUT THE NULL ELEMENT??


    NOTE : THE BELOW FUNCTION HAS FEW  ERRANEOUS PARTS ,ITS UNDER MAINTENANCE
     * */
    struct noeud *t;


    struct file f; creer_file(&f);
    enfiler(abr,&f); enfiler(NULL,&f); //its marker
    t = premier(f);
    unsigned height =-1;
    printf("\n");
    while(t || !file_vide(f))
    {
        t = premier(f);
        defiler(&f);
        
        if(t)
            printf("%d\t",t->info);
       
        if(!t)
        {
            height++;

        }
        
        if(t->sag || t->sad)
        {
            if(t->sag)
                enfiler(t->sag,&f);
            if(t->sad)
                enfiler(t->sad,&f);     
        }
   
    }
    
    return height;


}
void parcours_niveau_trie(struct noeud * abr)
{
    /*Avec une arbre binaire contenant des entiers.
      on va creer un algorithme qui va rendre la liste des
      elements entiers triés par ordre croissant sans utiliser 
      un algorithme de tri*/
    struct file f; creer_file(&f);
    creer_liste(); //OA liste
    struct noeud* t ;
    enfiler(abr,&f);
    while(!file_vide(f))
    {
        t = premier(f);
        ajout_trie(t);
        defiler(&f);

       if(t->sad)
          enfiler(t->sad,&f);
       if(t->sag)
         enfiler(t->sag,&f); 
    
    }


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
