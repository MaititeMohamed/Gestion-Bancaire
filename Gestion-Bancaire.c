#include<stdio.h>


int main()
{
//MENU
int choix; //for switch case
do{
printf("************MENU*************************\n");
printf("1.  creer un compte bancaire            \n");
printf("2.  creer plusieurs comptes bancaires   \n");
printf("3.  Retrait                             \n");
printf("4.  Depot                               \n");
printf("5.  Affichage Par Ordre Ascendant       \n");
printf("6.  Affichage Par Ordre Descendant      \n");
printf("7.  Par Ordre Ascendant                 \n");
printf("8.  Par Ordre Descendant                \n");
printf("9.  Recherche par CIN                   \n");
printf("10. Fidelisation                        \n");
printf("11. Quitter l application               \n");
printf("*****************************************\n");
//for take the value of choix
printf("Donner votre choix :\n");
scanf("%d",&choix);
 //switch case 
 switch (choix)
   {
        case 1:

              break;
        case 2:
                /* code */
              break;
        case 3:
                /* code */
              break;    
         case 4:
                /* code */
              break;
        case 5:
                /* code */
              break;
        case 6:
                /* code */
              break;    
         case 7:
                /* code */
              break;
        case 8:
                /* code */
              break;
        case 9:
                /* code */
              break;    
        case 10:
                /* code */
              break;
        case 11:break;//EXIT FROM APPLICATION    
       default:
              break;
    }
}while(choix!=11);


return 0;
}

