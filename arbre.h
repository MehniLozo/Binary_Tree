

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

/****************PARTIE INTERFACE FILE***********/
/*So,the content of the queue is gonna be struct elem*  */

struct elem{
    struct noeud * info;
    struct elem* suivant;
};
struct file{
    struct elem* tete;
    struct elem* queue;
    
};

void creer_file(struct file* );
unsigned file_vide(struct file );
struct noeud*  premier(struct file );
void enfiler(struct noeud *x,struct file *);
void defiler(struct file *);
