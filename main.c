#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"car.h"
#define FILENAME "cars.csv"



int main() {
    int choix;

    do {
        afficherMenu();
        printf("\nEntrez votre choix : ");
        scanf("%d", &choix);
        getchar(); // Pour consommer le retour à la ligne

        switch (choix) {
            case 1:
                ajouterVoiture();
                break;
            case 2:
                afficherVoitures();
                break;
            case 3:
                modifierVoiture();
                break;
            case 4:
                supprimerVoiture();
                break;
            case 5:
                rechercherVoiture();
                break;
            case 6:
                trierVoitures();
                break;
            case 0:
                printf("\nAu revoir !\n");
                break;
            default:
                printf("\nChoix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 0);

    return 0;
}

void afficherMenu() {
    printf("\n=========== MENU ===========");
    printf("\n1. Ajouter une voiture");
    printf("\n2. Afficher toutes les voitures");
    printf("\n3. Modifier une voiture");
    printf("\n4. Supprimer une voiture");
    printf("\n5. Rechercher une voiture");
    printf("\n6. Trier les voitures");
    printf("\n0. Quitter");
    printf("\n============================\n");
}

void ajouterVoiture() {
    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    Voiture voiture;
    printf("\nEntrez l'ID de la voiture : ");
    scanf("%d", &voiture.id);
    getchar();

    printf("Entrez la marque : ");
    fgets(voiture.marque, 50, stdin);
    voiture.marque[strcspn(voiture.marque, "\n")] = 0;

    printf("Entrez le nom d'utilisateur : ");
    fgets(voiture.utilisateur, 50, stdin);
    voiture.utilisateur[strcspn(voiture.utilisateur, "\n")] = 0;

    printf("Entrez le modele : ");
    fgets(voiture.modele, 50, stdin);
    voiture.modele[strcspn(voiture.modele, "\n")] = 0;

    printf("Entrez le type de carburant : ");
    fgets(voiture.carburant, 20, stdin);
    voiture.carburant[strcspn(voiture.carburant, "\n")] = 0;

    printf("Entrez le nombre de places : ");
    scanf("%d", &voiture.places);

    getchar(); // Consommer le retour à la ligne
    printf("Entrez la transmission (automatique/manuelle) : ");
    fgets(voiture.transmission, 20, stdin);
    voiture.transmission[strcspn(voiture.transmission, "\n")] = 0;

    printf("Entrez le prix de location par jour : ");
    scanf("%f", &voiture.prix);

    printf("La voiture est-elle disponible ? (1 pour oui, 0 pour non) : ");
    scanf("%d", &voiture.disponible);

    sauvegarderVoiture(voiture, file);
    fclose(file);
    printf("\nVoiture ajoutee avec succes !\n");
}

void sauvegarderVoiture(Voiture voiture, FILE *file) {
    fprintf(file, "%d,%s,%s,%s,%s,%d,%s,%.2f,%d\n",
            voiture.id, voiture.marque, voiture.utilisateur, voiture.modele,
            voiture.carburant, voiture.places, voiture.transmission,
            voiture.prix, voiture.disponible);
}

void afficherVoitures() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    printf("\nListe des voitures :\n");
    printf("ID, Marque, Utilisateur, Modele, Carburant, Places, Transmission, Prix, Disponibilite\n");

    char ligne[256];
    while (fgets(ligne, sizeof(ligne), file)) {
        printf("%s", ligne);
    }

    fclose(file);
}

void modifierVoiture() {
    // Implementation pour modifier une voiture
    printf("\nModification non implemente\n");
}

void supprimerVoiture() {
    // Implementation pour supprimer une voiture
    printf("\nSuppression non implemente\n");
}

void rechercherVoiture() {
    // Implementation pour rechercher une voiture
    printf("\nRecherche non implemente\n");
}

void trierVoitures() {
    // Implementation pour trier les voitures
    printf("\nTri non implemente\n");
}
