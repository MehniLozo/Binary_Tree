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
    ab = construire(1, construire(2,construire(4,NULL,NULL),construire(5,NULL,NULL))
            ,construire(3,construire(6,NULL,NULL),NULL));
    printf("\nprofondeur = %d\n",profondeur(ab));










   /* 
     ab = construire(100,construire(50,construire(20,NULL,NULL),construire(70,NULL,NULL)
                ),construire(150,construire(200,NULL,NULL),
                    construire(350,NULL,NULL)));
    */ 
    /*
    ab = construire(0,construire(9,construire(6,NULL,NULL),construire(10,NULL,NULL))
            ,construire(7,construire(8,NULL,NULL),construire(5,NULL,NULL)));

    printf("\naffichage trié d'arbre\n");
     parcours_niveau_trie(ab);
     affiche();
*/
    //arbre dégenéré
    /*
    ab = construire(100,construire(50,NULL,construire(80,NULL,NULL)),NULL);
    if(est_degeneree(ab))
               printf("\nabre ab est dégeneree\n");
     else
         printf("\nArbre non degenere\n");

     parcours_niveau_trie(ab);
     affiche();
*/
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
