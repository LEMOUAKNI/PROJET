#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

char nom[MAX][MAX];
char prenom[MAX][MAX];
char phone[MAX][MAX];
int age[MAX];
char status[MAX][MAX];
char date[MAX][MAX];
int referencecount[MAX];
int reservationCount = 0;
char rechnom[MAX];
int rechref;
int found = 0;

int initialisition()
{
    referencecount[0] = 1;
    strcpy(nom[0], "AZIZ");
    strcpy(prenom[0], "BENMELOUK");
    strcpy(phone[0], "0601020304");
    age[0] = 22;
    strcpy(status[0], "valide");
    strcpy(date[0], "2024-10-01");

    referencecount[1] = 2;
    strcpy(nom[1], "HAMZA");
    strcpy(prenom[1], "LEM");
    strcpy(phone[1], "0601020304");
    age[1] = 20;
    strcpy(status[1], "reporte");
    strcpy(date[1], "2024-10-09");

    referencecount[2] = 3;
    strcpy(nom[2], "KAWTER");
    strcpy(prenom[2], "REG");
    strcpy(phone[2], "0601020304");
    age[2] = 17;
    strcpy(status[2], "annule");
    strcpy(date[2], "2024-09-04");

    referencecount[3] = 4;
    strcpy(nom[3], "AYMEN");
    strcpy(prenom[3], "AYMEN");
    strcpy(phone[3], "0601020304");
    age[3] = 24;
    strcpy(status[3], "traite");
    strcpy(date[3], "2024-09-28");

    referencecount[4] = 5;
    strcpy(nom[4], "MALAK");
    strcpy(prenom[4], "MALAK");
    strcpy(phone[4], "0605060708");
    age[4] = 19;
    strcpy(status[4], "valide");
    strcpy(date[4], "2024-10-06");

    referencecount[5] = 6;
    strcpy(nom[5], "RAJAA");
    strcpy(prenom[5], "BEL");
    strcpy(phone[5], "0601020304");
    age[5] = 30;
    strcpy(status[5], "reporte");
    strcpy(date[5], "2024-08-03");

    referencecount[6] = 7;
    strcpy(nom[6], "ILYASS");
    strcpy(prenom[6], "MO");
    strcpy(phone[6], "0601020304");
    age[6] = 45;
    strcpy(status[6], "annule");
    strcpy(date[6], "2024-06-20");

    referencecount[7] = 8;
    strcpy(nom[7], "ANWAR");
    strcpy(prenom[7], "ANU");
    strcpy(phone[7], "0601020304");
    age[7] = 27;
    strcpy(status[7], "traite");
    strcpy(date[7], "2024-07-01");

    referencecount[8] = 9;
    strcpy(nom[8], "RAHIL");
    strcpy(prenom[8], "LEM");
    strcpy(phone[8], "0601020304");
    age[8] = 3;
    strcpy(status[8], "valide");
    strcpy(date[8], "2024-10-14");

    referencecount[9] = 10;
    strcpy(nom[9], "YOU");
    strcpy(prenom[9], "CODE");
    strcpy(phone[9], "0601020304");
    age[9] = 6;
    strcpy(status[9], "annule");
    strcpy(date[9], "2024-10-18");

    reservationCount = 10;
    return reservationCount;
}
void Ajouter() {
    int n;
    printf("\nCombien de reservations vous voulez ajouter : ");
    scanf("%d", &n);

    if (reservationCount + n > MAX) {
        printf("\nLe maximum de reservations a ete atteint.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("\nAjouter le Nom: ");
        scanf("%s", nom[reservationCount]);
        printf("Ajouter le Prenom: ");
        scanf("%s", prenom[reservationCount]);
        printf("Ajouter le Telephone (xxxx-xx-xxxx): ");
        scanf("%s", phone[reservationCount]);
        printf("Ajouter Age: ");
        scanf("%d", &age[reservationCount]);
        printf("Ajouter le Statut (valide, reporte, annule, traite): ");
        scanf("%s", status[reservationCount]);
        printf("Ajouter la Date de reservation (DD-MM-YYYY): ");
        scanf("%s", date[reservationCount]);

        referencecount[reservationCount] = reservationCount + 1;
        reservationCount++;
        printf("\n*Reservation ajoutee avec succes*\n");
    }
}

void Modifier() {
    int ref;
    printf("\nEntrez la reference de la reservation que vous voulez modifier : ");
    scanf("%d",&ref);
    ref--;

    if (ref < 0 || ref >= reservationCount) {
        printf("\nReference non disponible.\n");
        return;
    }

    printf("\nVeuillez choisir ce que vous voulez modifier :\n");
    printf("1. Nom\n");
    printf("2. Prenom\n");
    printf("3. Telephone\n");
    printf("4. Age\n");
    printf("5. Statut\n");
    printf("6. Date de reservation\n");
    printf("7. Modifier tous les donnee.\n");

    int choix;
    printf("Veuillez entrer un choix : ");
    scanf("%d", &choix);

    switch (choix) {
        case 1:
            printf("Entrer le nom a modifier: ");
            scanf("%s", nom[ref]);
            break;
        case 2:
            printf("Entrer le prenom a modifier: ");
            scanf("%s", prenom[ref]);
            break;
        case 3:
            printf("Entrer le telephone à modifier: ");
            scanf("%s", phone[ref]);
            break;
        case 4:
            printf("Entrer l'age a modifier: ");
            scanf("%d", &age[ref]);
            break;
        case 5:
            printf("Modifier le statut: ");
            scanf("%s", status[ref]);
            break;
        case 6:
            printf("Modifier la date : ");
            scanf("%s", date[ref]);
            break;
        case 7:
            printf("Entrer le nom à modifier: ");
            scanf("%s", nom[ref]);
            printf("Entrer le prenom à modifier: ");
            scanf("%s", prenom[ref]);
            printf("Entrer le telephone à modifier: ");
            scanf("%s", phone[ref]);
            printf("Entrer l'age à modifier: ");
            scanf("%d", &age[ref]);
            printf("Modifier le statut: ");
            scanf("%s", status[ref]);
            printf("Modifier la date : ");
            scanf("%s", date[ref]);
            break;

        default:
            printf("Choix invalide.\n");
            return;
    }
    printf("\n Reservation mise a jour avec succes.\n");
}

void Supprimer() {
    int ref;
    printf("Entrer la reference de la reservation que vous voulez supprimer : ");
    scanf("%d", &ref);
    ref--;

    if (ref < 0 || ref >= reservationCount) {
        printf("Reference non disponible.\n");
        return;
    }

    for (int i = ref; i < reservationCount - 1; i++) {
        strcpy(nom[i], nom[i + 1]);
        strcpy(prenom[i], prenom[i + 1]);
        strcpy(phone[i], phone[i + 1]);
        age[i] = age[i + 1];
        strcpy(status[i], status[i + 1]);
        strcpy(date[i], date[i + 1]);
        referencecount[i] = referencecount[i + 1];

    }
    reservationCount--;
    printf("La reservation a ete supprimee.\n");
}

void Afficher() {
    int ref;
    printf("Entrer la reference que vous voulez afficher : ");
    scanf("%d", &ref);
    ref--;

    if (ref < 0 || ref >= reservationCount) {
        printf("Reference non disponible.\n");
        return;
    }

    printf("\nReference : %d\n", referencecount[ref]);
    printf("Nom : %s\n", nom[ref]);
    printf("Prenom : %s\n", prenom[ref]);
    printf("Telephone : %s\n", phone[ref]);
    printf("age : %d\n", age[ref]);
    printf("Statut : %s\n", status[ref]);
    printf("Date : %s\n", date[ref]);
}
void Recherch()
{
    int choix3 ;
    printf("\n Veuillez choisir :\n");
    printf("1. Recherche d'une reservation par nom.\n");
    printf("2. Recherche d'une reservation par reference.\n");

      printf("Entrer votre :");
      scanf("%d",&choix3);
      switch(choix3){
          case 1 :

    printf("Entrer le nom que vous voulez rechercher : ");
    scanf("%s", rechnom);
    int found = 0;
    for (int i = 0; i < reservationCount; i++) {
        if (strcmp(nom[i], rechnom) == 0) {
            printf("\n Reference : %d\n", referencecount[i]);
            printf("Nom : %s\n", nom[i]);
            printf("Prenom : %s\n", prenom[i]);
            printf("Telephone : %s\n", phone[i]);
            printf("age : %d\n", age[i]);
            printf("Statut : %s\n", status[i]);
            printf("Date : %s\n", date[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("\nAucune reservation trouvee pour le nom : %s\n", rechnom );
}
break;

    case 2:
            printf("Entrer la reference que vous voulez rechercher : ");
            scanf("%d",&rechref);
            found = 0;
            for (int i = 0; i < reservationCount; i++) {
                if (referencecount[i] == rechref) {
                    printf("\nReference : %d\n", referencecount[i]);
                    printf("Nom : %s\n", nom[i]);
                    printf("Prenom : %s\n", prenom[i]);
                    printf("Telephone : %s\n", phone[i]);
                    printf("age : %d\n", age[i]);
                    printf("Statut : %s\n", status[i]);
                    printf("Date : %s\n", date[i]);
                    found = 1;
                }
            }
            if (!found) {
                printf("\n Aucune reservation trouvee pour la reference : %d\n", rechref);
            }
            break;

          default :
            printf("\n choix invalide .\n");
            break;
}
}
void Statistiques() {
     int totalAge = 0;
     int moyenneAge;
     int tranches[3] = {0};
     int statuts[4] = {0};
     int choix4 ;

    printf("1. \nCalculer la moyenne d'age des patients ayant reserve.\n");
    printf("2. Afficher le nombre de patients par tranche d'age.\n");
    printf("3. Generer des statistiques pour connaitre le nombre total de reservations par statut.\n");
    printf("Entrer votre choix :");
    scanf("%d",&choix4);
    switch(choix4){
case 1:

    if (reservationCount == 0) {
        printf("\nAucune reservation disponible pour generer des statistiques.\n");
        return;
    }
  for (int i = 0; i < reservationCount; i++) {
        totalAge += age[i];
    moyenneAge = totalAge / reservationCount;
  }
    printf("Moyenne d'age des patients ayant reserve : %d ans\n", moyenneAge);
    break;

case 2:

for (int i = 0; i < reservationCount; i++) {


        if (age[i] <= 18) {
            tranches[0]++;
        } else if (age[i] <= 35) {
            tranches[1]++;
        } else {
            tranches[2]++;
        }
}
    printf("Nombre de patients par tranche d'age :\n");
    printf("0-18 ans : %d\n", tranches[0]);
    printf("19-35 ans : %d\n", tranches[1]);
    printf("36+ ans : %d\n", tranches[2]);
    break;

case 3 :
    for (int i = 0; i < reservationCount; i++) {

        if (strcmp(status[i], "valide") == 0) {
            statuts[0]++;
        } else if (strcmp(status[i], "reporte") == 0) {
            statuts[1]++;
        } else if (strcmp(status[i], "annule") == 0) {
            statuts[2]++;
        } else if (strcmp(status[i], "traite") == 0) {
            statuts[3]++;
        }
    }

    printf("Nombre de reservations par statut :\n");
    printf("Valide : %d\n", statuts[0]);
    printf("Reporte : %d\n", statuts[1]);
    printf("Annule : %d\n", statuts[2]);
    printf("Traite : %d\n", statuts[3]);
}
}
    int main() {
        initialisition();
    int choix;
    do {
        printf("\n===== Menu principal =====\n");
        printf("1. Ajouter une reservation.\n");
        printf("2. Modifier une reservation.\n");
        printf("3. Supprimer une reservation.\n");
        printf("4. Afficher les details d'une reservation.\n");
        printf("5. Recherche des reservations.\n");
        printf("6. Statistiques.\n");
        printf("7. Quitter.\n");
        printf("Entrer votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                Ajouter();
                break;
            case 2:
                Modifier();
                break;
            case 3:
                Supprimer();
                break;
            case 4:
                Afficher();
                break;
            case 5:
                Recherch();
                break;
            case 6:
                Statistiques();
                break;
            case 7:
                printf("\n Au revoir !\n");
                break;
            default:
                printf("\n Veuillez reessayer.\n");
                break;
}
} while (choix != 7);

    return 0;
}
