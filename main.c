#include<stdio.h>
#include"myBank.h"


int main()
{
	OpenTheBank();
        double interest=0.0;
        int account_number=0;
    	char t;
do 
{  
	printf("\n\n***** Hello and Welcome to myBank *****\n"
	"1)To open a new accout please press O \n"
	"2)To Check the account  Balance  please press B \n"
	"3)To deposit money please press D \n"
	"4)To withdraw money please press W\n"
	"5)To close account please press C\n"
	"6)To add interest to all the accounts please press I\n"
	"7)To view all of the accounts please press P\n"
	"8)To close al of the accounts please press E \n \n" );

	scanf(" %c",&t);

    switch(t)
    {
    
	case 'O':
    
	printf("How much money would  you like to deposit to your new account :\n\n  " );
	double amount;
	scanf("%lf",&amount);
	OpenAccount(amount);
	break;

 	case 'B':
    
        printf("Please insert your account number\n\n"  );
	scanf("%d",&account_number);
	CheckBalance(account_number);
	break;

	case 'D':
   
        Deposit();
	break;

	case 'W':
   
	CashWithdrawal();
	break;
	
	case 'C':
        
	printf("Please insert the account number you would like to close: \n" );
	scanf("%d",&account_number);
	CloseAccount(account_number);
        break;

        case 'I':

	printf("What percentage of interest you want to add?\n");
	interest=0.0;
	scanf("%lf",&interest);
	AddInterest(interest);
	break; 
       
	case 'P':

        AllAccounts();
        break;

	case 'E':

	CloseAll();
	break;

	default :

	printf("Not legal transaction type, try again \n");
        break;

    }     
}while(t != 'E');  

return 0;
}









