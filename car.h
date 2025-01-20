//structure pour la voiture
typedef struct {
    int id;
    char marque[50];
    char utilisateur[50];
    char modele[50];
    char carburant[20];
    int places;
    char transmission[20];
    float prix;
    int disponible;
} Voiture;
//constante
// Prototypes des fonctions
void afficherMenu();
void ajouterVoiture();
void afficherVoitures();
void modifierVoiture();
void supprimerVoiture();
void rechercherVoiture();
void trierVoitures();
void sauvegarderVoiture(Voiture voiture, FILE *file);
