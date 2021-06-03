#include "arbre.h"


/*
 *Liste sous forme Objet Abstrait
 * */


struct liste{
    struct elem* premier;
    struct elem* dernier;
    };

void creer_liste();
unsigned liste_vide();
void ajouter_av_premier(struct noeud* x);
void ajouter_ap_dernier(struct noeud* x);
void parcours_niveau_trie(struct noeud * abr);
void ajouter_ap_ref(struct noeud* x,struct elem* p);
void ajout_trie(struct noeud* x);
void affiche();
