#include<stdio.h>
#include"myBank.h"

int main()
{
	OpenTheBank();
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

	if(scanf(" %1c",&t)==1)
	{
	switch(t)
		{
		case 'O':
		OpenAccount();
		break;

	 	case 'B':
		CheckBalance();
		break;
	
		case 'D':
	        Deposit();
		break;
	
		case 'W':
		CashWithdrawal();
		break;
		
		case 'C':
		CloseAccount();
	        break;
	
	        case 'I':
		AddInterest();
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
	}
}while(t != 'E');  

return 0;
}
