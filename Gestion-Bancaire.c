#include<stdio.h>
#include<stdlib.h>
 



 //function for add new user 
 void Add_count(FILE *f)
 {
  //struct for defin data
                typedef struct 
                {
                 char CIN[9];
                 char NOM[10];
                 char PRENOM[10];
                 double MONTANT;
                }users;
                users user;
                printf("CIN :\n");
                scanf("%s",&user.CIN);
                printf("NOM :\n");
                scanf("%s",&user.NOM);
                printf("PRENOM :\n");
                scanf("%s",&user.PRENOM);
                printf("MONTANT :\n");
                scanf(" %lf",&user.MONTANT);
                //for stock info in fille 
                f=fopen("BancData.txt", "a");//make fille.txt  
                fprintf(f," CIN   :%s \n NOM    :%s\n PRENOM  :%s \n MONTANT  :%.2lf \n",user.CIN,user.NOM,user.PRENOM,user.MONTANT);//for stock data in the fill
                fclose(f);//close the fill
 }
 //function for add plusieurs count 
 void Add_plusieurs_count(FILE *f)
 {
     typedef struct 
                {
                 char CIN[9];
                 char NOM[10];
                 char PRENOM[10];
                 double MONTANT;
                }users;
                users user[100];
                int nbr,i;
                f=fopen("BancData.txt", "a");//make fille.txt  
                printf("Donner le nomber de count :\n");
                scanf("%d",&nbr);//nbr for condition loop
                for(i=0;i<=nbr;i++){
                printf("acount number  %d \n",i);
                printf("CIN :\n");
                scanf("%s",&user[i].CIN);
                printf("NOM :\n");
                scanf("%s",&user[i].NOM);
                printf("PRENOM :\n");
                scanf("%s",&user[i].PRENOM);
                printf("MONTANT :\n");
                scanf(" %lf",&user[i].MONTANT);
                //for stock info in fille 
                fprintf(f," CIN   :%s \n NOM    :%s\n PRENOM  :%s \n MONTANT  :%.2lf \n",user[i].CIN,user[i].NOM,user[i].PRENOM,user[i].MONTANT);//for stock data in the fill
                }
                fclose(f);//close the fill

               }

int main()
{
  //FILE 
  FILE *fichier; 

//MENU
int choix; //for switch case
do{
printf("*******************MENU******************\n");
printf("[1].  creer un compte bancaire            \n");
printf("[2].  creer plusieurs comptes bancaires   \n");
printf("[3].  Retrait                             \n");
printf("[4].  Depot                               \n");
printf("[5].  Affichage Par Ordre Ascendant       \n");
printf("[6].  Affichage Par Ordre Descendant      \n");
printf("[7].  Par Ordre Ascendant                 \n");
printf("[8].  Par Ordre Descendant                \n");
printf("[9].  Recherche par CIN                   \n");
printf("[10]. Fidelisation                        \n");
printf("[11]. Quitter l application               \n");
printf("*****************************************\n");
//for take the value of choix
printf("Donner votre choix :\n");
scanf("%d",&choix);
//switch case 
 switch (choix)
   {
        case 1:
          
              Add_count(fichier);//function for add solo acount
              break;
        case 2:
              Add_plusieurs_count(fichier);//function for add plsuer acount
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

