#include <stdio.h>
#include <stdlib.h>


typedef struct Element Element;
struct Element{
    int valeur;
    Element *suivant;
};

typedef struct Liste Liste ;
struct Liste{
    int longueur;
    Element *tete;
};


void append2(Element **tete, int valeur){

    Element *element = malloc(sizeof(Element));
    element->suivant = NULL;
    element->valeur = valeur;
    if(*tete == NULL) {
        *tete = element;
    }else{
        Element *tmp = *tete;
        while(tmp->suivant != NULL){
            tmp = tmp->suivant;
        }

        tmp->suivant = element;
    }
}


void afficher2(Element *tete){

    Element *tmp = tete;

    while(tmp != NULL){
        printf(" %d ->", tmp->valeur);
        tmp = tmp->suivant;
    }

    printf("NULL\n");
}

Liste *initialize(int valeur){
    Liste *liste = malloc(sizeof(Liste));
    Element * element = malloc(sizeof(Element));

    if(liste == NULL || element == NULL) exit(EXIT_FAILURE);

    element->valeur = valeur;
    element->suivant = NULL;

    liste->longueur = 1;
    liste->tete = element;

    return liste;
}


void append(Liste *liste, int valeur){
    if(liste == NULL) return ;

    Element *element = malloc(sizeof(Element));

    if(element == NULL) exit(EXIT_FAILURE);

    element ->valeur = valeur ;
    element ->suivant = NULL;
    Element * tmp = liste->tete;
    while(tmp->suivant != NULL){
        tmp = tmp->suivant;
    }

    tmp->suivant = element;
    liste->longueur ++;
}


void ajoutEnTete(Liste *liste, int valeur){
    if(liste == NULL) return;

    Element *element = malloc(sizeof(Element));
    element->valeur = valeur;
    element->suivant = liste->tete;
    liste->tete = element ;
    liste->longueur++;
}

void afficher(Liste *liste){
    if(liste == NULL) return;

    Element *tmp = liste->tete;

    while(tmp!=NULL){
        printf("%d -> ", tmp->valeur);
        tmp = tmp->suivant;
    }

    printf("NULL\n");
}


void supp_1er_Element(Liste *liste){
    if(liste == NULL)return ;

    if(liste->tete != NULL){
        Element *tete = liste->tete;
        liste->tete = tete->suivant;
        tete->suivant = NULL;
        liste->longueur--;
        free(tete);
    }
}

void suppSelonPosition(Liste *liste, int position){
    if(liste == NULL) return;

    int i = 1;
    Element *tmp = liste->tete;
    Element *precedent = NULL;
    while(i<position && tmp->suivant !=NULL){
        precedent = tmp;
        tmp = tmp->suivant;
        i++;
    }

    if(precedent == NULL){ //Suppression de la tete
        liste->tete = tmp->suivant;
    }else if(tmp->suivant == NULL){ //Suppression de la queue
        precedent->suivant = NULL;
    }else{
        precedent->suivant = tmp->suivant;
    }

    free(tmp);
    liste->longueur--;

}

int main(){

    printf("--------------------------------------------Sans structure Liste-------------------------------------------------------\n");
    Element *listeB = NULL;
    append2(&listeB, 10);
    append2(&listeB, 20);
    append2(&listeB, 30);
    printf("Affichage de la liste :\n\t");
    afficher2(listeB);


    printf("\n\n-----------------------------------------A laide dune structure Liste-----------------------------------------------\n\n");
    Liste *liste = initialize(10);
    append(liste, 20);
    append(liste, 30);
    append(liste, 40);
    append(liste, 50);
    append(liste, 60);

    printf("Ajout de 10, 20, 30, 40, 50 et 60 a l'aide de la fonction append :\n\t");
    afficher(liste);
    printf("\tLongueur de la liste : %d\n", liste->longueur);

    printf("\nAjout de 100 a la tete de la liste :\n\t");
    ajoutEnTete(liste, 100);
    afficher(liste);
    printf("\tLongueur de la liste : %d\n", liste->longueur);

    printf("\nAffichage apres la suppression du premier element de la liste :\n\t");
    supp_1er_Element(liste);
    afficher(liste);
    printf("\tLongueur de la liste : %d\n", liste->longueur);

    printf("\nAffichage apres la suppression de lelement a la position 1 :\n\t");
    suppSelonPosition(liste, 1);
    afficher(liste);
    printf("\tLongueur de la liste : %d\n", liste->longueur);

    printf("\nAffichage apres la suppression de lelement a la position 6 (derniere) :\n\t");
    suppSelonPosition(liste, 6);
    afficher(liste);
    printf("\tLongueur de la liste : %d\n", liste->longueur);

    printf("\nAffichage apres la suppression de lelement a la position 2 (millieu) :\n\t");
    suppSelonPosition(liste, 2);
    afficher(liste);
    printf("\tLongueur de la liste : %d", liste->longueur);

    return 0;
}
