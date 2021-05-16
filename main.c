#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "arbre.c"
void affichage(struct noeud* ab)
{
/*l'affichae de l'arbre exige l'existance d'une file d'attente
 *On va faire le parcours par niveau
 * */
    struct file f;
    creer_file(&f);
    
    enfiler(ab,&f); //enfiler la racine 

    while(!file_vide(f))
    {
        if(f.tete->info->sag)
            enfiler(f.tete->info->sag,&f);
        
        if(f.tete->info->sad)
            enfiler(f.tete->info->sad,&f);
        printf("%c\t",f.tete->info->info);
        defiler(&f);
    }

}

int main()
{

    struct noeud* ab = creer_arbre();

    ab = construire('*',construire('+',construire('a',NULL,NULL),
            construire('b',NULL,NULL)),construire('-',construire('c',NULL,NULL),
            construire('d',NULL,NULL)));
    printf("\n*********AFFICHAGE********\n");
     affichage(ab);

    /*************************TESTING*****************/ 
/*   struct noeud a;
   
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


*/

return 0;}
