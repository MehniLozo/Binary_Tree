

/****************PARTIE INTERFACE ARBRE BINAIRE************/
struct noeud{ 
    char info;
    struct noeud *sag;
    struct noeud *sad;
};

struct noeud* creer_arbre();
unsigned arbre_vide(struct noeud*);
struct noeud* construire(char,struct noeud* ,struct noeud*);
struct noeud* gauche(struct noeud*);
struct noeud* droite(struct noeud*);
char lire_racine(struct noeud* );

