#include<stdio.h>
#include<stdlib.h>



typedef struct 
                 {
                 char CIN[9];
                 char NOM[10];
                 char PRENOM[10];
                 double MONTANT;
                 }users;
       static users user[100];
       static int nber=0,j=0,nbr,i;//nomber de count

 void Add_count()
               {    
                printf("CIN :\n");
                scanf("%s",user[i].CIN);
                printf("NOM :\n");
                scanf("%s",user[i].NOM);
                printf("PRENOM :\n");
                scanf("%s",user[i].PRENOM);
                printf("MONTANT :\n");
                scanf(" %lf",&user[i].MONTANT);
                i++;
                nber ++;
                //printf(" CIN   :%s \n NOM    :%s\n PRENOM  :%s \n MONTANT  :%.2lf \n",user.CIN,user.NOM,user.PRENOM,user.MONTANT);//for stock data in the fill           
              }
              
 void Add_plusieurs_count()
 {
       int a=nber;
              
                printf("Donner le nomber de count :\n");
                scanf("%d",&nbr);//nbr for condition loop
                for(i=a;i<nbr+a;i++){
                printf("acount number  %d \n",i);
                printf("CIN :\n");
                scanf("%s",user[i].CIN);
                printf("NOM :\n");
                scanf("%s",user[i].NOM);
                printf("PRENOM :\n");
                scanf("%s",user[i].PRENOM);
                printf("MONTANT :\n");
                scanf(" %lf",&user[i].MONTANT);
                
                //printf(" CIN   :%s \n NOM    :%s\n PRENOM  :%s \n MONTANT  :%.2lf \n",user[i].CIN,user[i].NOM,user[i].PRENOM,user[i].MONTANT);//for stock data in the fill
                }
               

               }

int main()
{
 
 char CIN_user[20] ;
//MENU
int choix; //for switch case
do{
      menu:
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
scanf("%d",&choix);
//switch case 
 switch (choix)
   {
        case 1:
          
              Add_count();//function for add solo acount
              break;
        case 2:
              Add_plusieurs_count();//function for add plsuer acount
              break;
        case 3:  
              char op;
          	do{
        		  
        	       printf("************ Operations ************\n");
                   printf(" [1]- Retrait \n");
                   printf(" [2]- Depot\n");
                   printf(" [3]- retour a menu  \n");
                   printf("Veuillez choisir une operation: \n");
                   scanf("%d",&op);
		
                        switch (op)
					{
 						//Retrait
                               case 1:
                                   {
                        float so1;

                        printf("entre votre Cin :\n");
                        scanf("%s",CIN_user);
                        for(i=0;i<nber;i++)
                        {
                            if(strstr(CIN_user,user[i].CIN))
                            {
                                printf("combien :\n");
                                scanf("%f",&so1);
                                if(so1>user[i].MONTANT)
                                {
                                    printf("\n impossible votre sold inferieur a %.2f\n",so1);
                                    break;
                                }
                                user[i].MONTANT-=so1;
                            }

                        }

                    }break;
                             //Depot
                             case 2:{
                        float so2;
                         printf("entre votre Cin :\t");
                        scanf("%s",CIN_user);
                        for(i=0;i<nber;i++)
                        {
                            if(strstr(CIN_user,user[i].CIN))
                            {
                                printf("combien :\n");
                                scanf("%f",&so2);
                                user[i].MONTANT+=so2;
                            }
                        }

                    }break;
                             break;
    					   case 3:
    					   	 goto menu;
    					   break;
 
 						default:
     				    break;
 						    } 
               	}while(op!=3);
              
              break;    
         case 4:
                          {
               do{
                   printf("************** Affichage **************\n");
                   printf("[1]- Par Ordre Ascendant \n");
                   printf("[2]- Par Ordre Descendant\n");
                   printf("[3]- Par Ordre Ascendant (les comptes bancaires ayant un montant superieur a un chiffre introduit)\n");
                   printf("[4]- Par Ordre Descendant (les comptes bancaires ayant un montant superieur a un chiffre introduit)\n");
                   printf("[6]- retour a menu\n");
                   printf(" choisir une Affichage: ");
                   scanf("%d",&choix);
                   switch(choix)
                   {
                   case 1:
                    {
                       int a=nber;
                       users tmp;
                       int  ech=0;
                        do
                        {
                             for(i=0;i<a-1;i++)
                        {
                            if(user[i].MONTANT>user[i+1].MONTANT)
                            {
                                tmp=user[i+1];
                                user[i+1]=user[i];
                                user[i]= tmp;
                            }
                             ech++;
                        }

                        }while(ech>0);

                        printf("*****************L'ffichage Par Ordre Ascendant *****************\n");

                        for(i=0;i<a;i++)
                        {
                          printf(" Cin : %s  ,\tNom: %s  ,\t Prenom: %s  ,\t Montant : %.2f dh\n\n",user[i].CIN,user[i].NOM,user[i].PRENOM,user[i].MONTANT);

                        }
                    }break;
                  case 2:
                    {
                        int a=nber;
                        users tmp;
                        int ech=0;
                        do
                        {
                             for(i=0;i<a-1;i++)
                        {
                            if(user[i].MONTANT<user[i+1].MONTANT)
                            {
                                tmp=user[i+1];
                                user[i+1]=user[i];
                                user[i]= tmp;

                            }
                             ech++;
                        }

                        }while(ech>0);
                       
                               printf("***************** L'ffichage Par Ordre Descendant  *****************\n");

                        for(i=0;i<a;i++)
                        {
                            printf(" Cin : %s  ,\tNom: %s  ,\t Prenom: %s  ,\t Montant : %.2f dh\n\n",user[i].CIN,user[i].NOM,user[i].PRENOM,user[i].MONTANT);
                        }
                    }break;
                  case 3:
                    {
                        

                    }break;
                  case 4:
                    {

                    }break;
                  case 5:
                    {

                    }break;
                  case 6:
                    {
                        goto menu;

                    }break;

                   }
               }while(choix!=6);
     
                   }
              break;    
         case 5:
                 for(i=0;i<nber+nbr;i++){
              printf(" CIN   :%s \n NOM    :%s\n PRENOM  :%s \n MONTANT  :%.2lf \n",user[i].CIN,user[i].NOM,user[i].PRENOM,user[i].MONTANT);//for stock data in the fill
                                 }
              break;
              case 6:
                
              break;
        case 7:break;//EXIT FROM APPLICATION    
       default:
              break;
    }
}while(choix!=7);
 
return 0;
}
