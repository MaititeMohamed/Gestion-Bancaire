#include <stdio.h>
#include <string.h>

void Add_count();
void Add_plusieurs_count();
void recherch_par_cin();
void fidelisation();
void Affichage();
void Operations();
void MENU();
typedef struct
{
    char CIN[9];
    char NOM[10];
    char PRENOM[10];
    double MONTANT;
} users;
users user[100];
int nber = 0, nbr, j = 0, i;
void Add_count()
{
    printf("CIN :\n");
    scanf("%s", user[nber].CIN);
    printf("NOM :\n");
    scanf("%s", user[nber].NOM);
    printf("PRENOM :\n");
    scanf("%s", user[nber].PRENOM);
    printf("MONTANT :\n");
    scanf(" %lf", &user[nber].MONTANT);
    nber++;
}
void Add_plusieurs_count()
{
    int a = nber;

    printf("Donner le nomber de count :\n");
    scanf("%d", &nbr); //nbr for condition loop
    for (i = a; i < nbr + a; i++)
    {
        printf("Donner les information de coount :\n");
        printf("CIN :\n");
        scanf("%s", user[i].CIN);
        printf("NOM :\n");
        scanf("%s", user[i].NOM);
        printf("PRENOM :\n");
        scanf("%s", user[i].PRENOM);
        printf("MONTANT :\n");
        scanf(" %lf", &user[i].MONTANT);
        nber++;
    }
}
void MENU()
{
    int choix;
    do
    {

        printf("*******************MENU******************\n");
        printf("[1].  creer un compte bancaire            \n");
        printf("[2].  creer plusieurs comptes bancaires   \n");
        printf("[3].  Operation                           \n");
        printf("[4].  Affichage                           \n");
        printf("[5].  Recherche par CIN                   \n");
        printf("[6].  Fidelisation                        \n");
        printf("[7].  Quitter l application               \n");
        printf("*****************************************\n");
        //for take the value of choix
        printf("Donner votre choix :\n");
        scanf("%d", &choix);
        //switch case
        switch (choix)
        {
        case 1:
            //function for add solo acount
            Add_count();
            break;
        case 2:
            //function for add plsuer acount
            Add_plusieurs_count();
            break;
        case 3:
            Operations();
            break;
        case 4:
        {
            Affichage();
        }
        break;
        case 5:
            //recherch par cin
            recherch_par_cin();
            break;
        case 6:
            //fidelisation
            fidelisation();
            break;
        case 7:
            break; //EXIT FROM APPLICATION
        default:
            break;
        }
    } while (choix != 7);
}
void Operations()
{
    char op;
    char CIN_user[10];
    do
    {

        printf("************ Operations ************\n");
        printf(" [1]  Retrait  Montant \n");
        printf(" [2]  Depot    Montant\n");
        printf(" [3]  MENU prancipal  \n");
        printf("************************************\n");
        printf("choisir une operation: \n");
        scanf("%d", &op);

        switch (op)
        {
            //Retrait
        case 1:
        {
            float so1;

            printf("entre votre Cin :\n");
            scanf("%s", CIN_user);
            for (i = 0; i < nber; i++)
            {
                if (strcmp(CIN_user, user[i].CIN) == 0)
                {
                    printf("entre votre solde :\n");
                    scanf("%f", &so1);
                    if (so1 > user[i].MONTANT)
                    {
                        printf("\n impossible votre solde inferieur a %.2f\n", so1);
                        break;
                    }
                    user[i].MONTANT -= so1;
                }
            }
        }
        break;
        //Depot
        case 2:
        {
            float so2;
            printf("entre votre Cin :\t");
            scanf("%s", CIN_user);
            for (i = 0; i < nber; i++)
            {
                if (strcmp(CIN_user, user[i].CIN) == 0)
                {
                    printf(" entre votre solde :\n");
                    scanf("%f", &so2);
                    user[i].MONTANT += so2;
                }
            }
        }
        break;
            break;
        case 3:
            MENU();
            break;

        default:
            break;
        }
    } while (op != 3);
}
void Affichage()
{
    int choix;
    do
    {
        printf("************** Affichage **************\n");
        printf("[1] Ordre Ascendant \n");
        printf("[2] Ordre Descendant\n");
        printf("[3] Ordre Ascendant par MAX\n");
        printf("[4] Ordre Descendant par MIN\n");
        printf("[5] MENU prancipal\n");
        printf("  Affichage  par: ");
        printf("***************************************\n");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
        {
            // Ordre Ascendant  par MONTANT
            int a = nber;
            users tmp;

            for (j = 0; j < nber; j++)
            {
                for (i = 0; i < a - 1; i++)
                {
                    if (user[i].MONTANT > user[i + 1].MONTANT)
                    {
                        tmp = user[i + 1];
                        user[i + 1] = user[i];
                        user[i] = tmp;
                    }
                }
            }

            printf("*****************L'ffichage Par Ordre Ascendant *****************\n");

            for (i = 0; i < a; i++)
            {
                printf(" Cin : %s  ||\tNom: %s  ||\t Prenom: %s  ||\t Montant : %.2f \n\n", user[i].CIN, user[i].NOM, user[i].PRENOM, user[i].MONTANT);
            }
        }
        break;
        case 2:
        {
            //Ordre Descendant par MONTANT
            int a = nber;
            users tmp;
            for (j = 0; j < nber; j++)
            {
                for (i = 0; i < a - 1; i++)
                {
                    if (user[i].MONTANT < user[i + 1].MONTANT)
                    {
                        tmp = user[i + 1];
                        user[i + 1] = user[i];
                        user[i] = tmp;
                    }
                }
            }

            printf("*****************L'ffichage Par Ordre Descendant*****************\n");

            for (i = 0; i < a; i++)
            {
                printf(" Cin : %s  ||\tNom: %s  ||\t Prenom: %s  ||\t Montant : %.2f \n\n", user[i].CIN, user[i].NOM, user[i].PRENOM, user[i].MONTANT);
            }
        }
        break;
        case 3:
        {
            // Ordre Ascendant par MAX
            int a = nber;
            int con = 0;
            float MONT;
            printf(" donner un MONTANT : \n");
            scanf("%f", &MONT);
            users st[100];
            for (i = 0; i < a; i++)
            {
                if (user[i].MONTANT > MONT)
                {
                    st[con] = user[i];
                    con++;
                }
            }
            //affichage Ordre Ascendant par MAX
            for (i = 0; i < con; i++)
            {
                printf(" Cin : %s  ||\tNom: %s  ||\t Prenom: %s ||\t Montant : %.2f \n\n", st[i].CIN, st[i].NOM, st[i].PRENOM, st[i].MONTANT);
            }
        }
        break;
        case 4:
        {
            // Ordre Ascendant par min
            int a = nber;
            int con = 0;
            float MONT;
            printf(" donner un MONTANT : \n");
            scanf("%f", &MONT);
            users st[100];
            for (i = 0; i < a; i++)
            {
                if (user[i].MONTANT < MONT)
                {
                    st[con] = user[i];
                    con++;
                }
            }
            //affichage Ordre Ascendant par min
            for (i = 0; i < con; i++)
            {
                printf(" Cin : %s  ||\tNom: %s  ||\t Prenom: %s ||\t Montant : %.2f \n\n", st[i].CIN, st[i].NOM, st[i].PRENOM, st[i].MONTANT);
            }
        }
        break;

        case 5:

            MENU();

            break;
        }
    } while (choix != 6);
}
void fidelisation()
{
    int a = nber;
    users tmp;
    
    for (j = 0; j < nber; j++)
    {
        for (i = 0; i < a - 1; i++)
        {
            if (user[i].MONTANT < user[i + 1].MONTANT)
            {
                tmp = user[i + 1];
                user[i + 1] = user[i];
                user[i] = tmp;
            }
        }
    }

    printf("*********************les 3 premier  fidelisation  *********************\n");
    for (i = 0; i < 3; i++)
    {
        printf(" Cin : %s  ||\tNom: %s  ||\t Prenom: %s  ||\t Montant : %.2f \n", user[i].CIN, user[i].NOM, user[i].PRENOM, user[i].MONTANT);
        user[i].MONTANT += ((user[i].MONTANT * 1.3) / 100);
    }
}
void recherch_par_cin()
{
    char R_CIN[20];
    printf("Entrer votre Cin: \n");
    scanf("%s", R_CIN);
    int existe = 0;
    for (i = 0; i < nber; i++)
    {
        if (strcmp(R_CIN, user[i].CIN) == 0)
        {
            existe = 1;
            break;
        }
        else
            existe = 0;
    }
    if (existe == 1)
        printf(" Cin : %s  ||\tNom :  %s ||\t Prenom : %s||\t Montant: %.2f \n", user[i].CIN, user[i].NOM, user[i].PRENOM, user[i].MONTANT);
    else
        printf("\n votre  cin n existe pas \n");
    
}



int main()
{
    MENU();
    return 0;
}
