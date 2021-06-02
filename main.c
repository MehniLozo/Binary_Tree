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
        printf("%d\t",f.tete->info->info);
        defiler(&f);
    }

}

int main()
{

    struct noeud* ab = creer_arbre();
    /*
     ab = construire(100,construire(50,construire(20,NULL,NULL),construire(70,NULL,NULL)
                ),construire(150,construire(200,NULL,NULL),
                    construire(350,NULL,NULL)));
     */
    //arbre dégenéré
    ab = construire(100,construire(50,NULL,construire(80,NULL,NULL)),NULL);
    if(est_degeneree(ab))
               printf("\nabre ab est dégeneree\n");
     else
         printf("\nArbre non degenere\n");


    /*
    struct noeud* ab2= creer_arbre();
    ab = construire(100,construire(50,construire(20,NULL,NULL),construire(70,NULL,NULL)
                ),construire(150,construire(200,NULL,NULL),
                    construire(350,NULL,NULL)));
   ab2= construire(100,construire(50,construire(20,NULL,NULL),construire(70,NULL,NULL)
                ),construire(150,construire(200,NULL,NULL),
                    construire(15,NULL,NULL)));
   
     printf("\n*********AFFICHAGE********\n");
     affichage(ab);
     printf("\n");
     affichage(ab2);
     if (arbre_confondues(ab,ab2))
        printf("\nBoth trees of %d and %d are equal\n",ab->info,ab->info);
     else
         printf("\nTrees are not equal.\n");
    */
    
     
   return 0;}
