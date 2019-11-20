#include<stdio.h>
#include "myBank.h"

int _openAccounts=0;
enum Account_Status{ CLOSED_ACCOUNT , OPENED_ACCOUNT };
double accounts[50][2];
int account_number;


void OpenTheBank(){
	for(int i=0; i< 50;i++){
		(accounts[i][0]) = (double) (CLOSED_ACCOUNT);
		(accounts[i][1]) = 0.0;
	
	}
    return;
}
	  
void OpenAccount(double amount)
{	
	if (_openAccounts>=50)
	{
	printf("Sorry, the bank is full, can't open new account.");
	return;
	}

	account_number=0;
	int j=0;
	while (j<50){
	
		if (accounts[j][0] == CLOSED_ACCOUNT)
		{
		accounts[j][0] = (double) OPENED_ACCOUNT;
		account_number = j+901;
		_openAccounts++;
		break;
		}
		j++;
	}
	accounts[(account_number-901)][1] = amount;	
	printf("Congratulations, you have a new bank account,\nYour new account number is: %d\nYour balance is: %0.2lf\n  ", account_number, amount);
}


void CheckBalance(int account_number)
{
	if(accounts[(account_number-901)][0] != CLOSED_ACCOUNT)
	{
 	printf("Your account balance is: %0.2lf \n",accounts[(account_number - 901)][1]);
	}
	else {
	printf("This account does not exist\n");
	}
	return;	
}

	
void Deposit()
{   
	printf("Please insert your account number: \n" );
	scanf("%d",&account_number);
	if(accounts[(account_number-901)][0] == ((double) OPENED_ACCOUNT))
	{
        printf("Your deposit amount? \n");
        double DepositAmount;
        scanf("%lf",&DepositAmount);
	accounts[(account_number - 901)][1] = (((double)(accounts[(account_number - 901)][1])) + (DepositAmount));
	printf("Your new balance is: %0.2lf \n",(accounts[(account_number - 901)][1]));
	return;
	}
	else
	{
	printf("This account does not exist\n");
	}
	return;
}


void CashWithdrawal()
{
	printf("Please insert your account number: \n" );
	scanf("%d",&account_number);
	if (accounts[(account_number - 901)][0]==CLOSED_ACCOUNT)
	{
	printf("This account does not exist\n");
	return;
	}
	printf("How much money would you like to withdraw ? \n");
        double WithdrawalAmount;
        scanf("%lf",&WithdrawalAmount);
	if (WithdrawalAmount > (accounts[account_number - 901][1]))
	{
	printf("Can't withdraw this amount, not enough money in the bank account.\n");
	return;
	}
	accounts[(account_number - 901)][1] = accounts[account_number - 901][1] -  WithdrawalAmount ;
	printf("Your new balance is: %0.2lf\n", accounts[account_number - 901][1]);
	return;
}

void CloseAccount(int account_number)
{
	if (accounts[(account_number - 901)][0] == CLOSED_ACCOUNT)
	{
	printf("There is no such account");
	return;
	}
	accounts[(account_number - 901)][0] = CLOSED_ACCOUNT;
	accounts[(account_number - 901)][1] =0 ;
	printf("Account successfully deleted. \n");
	_openAccounts--;
	return;
}

void AddInterest(double interest)
{
	for(int i=0;i<50;i++)
	{
	(accounts[i][1]) = accounts[i][1] + ((accounts[i][1])*(interest/100));
	}
 	return;
}
	

void AllAccounts()
{
	if(_openAccounts==0)
	{
	printf("There are no open accounts");
	return;
	}
	for(int i=0; i<50; i++) {
	double a1=(i + 901);
	double a2=accounts[i][1];
	if (accounts[i][0]==OPENED_ACCOUNT)
		{
		printf("Account number: %0.0lf \nAmount of money in the accout: %0.2lf\n\n",a1,a2);
		}
	}
	return;
}

void CloseAll()
{
	for(int i=0; i<50 ;i++){
	accounts[i][0] =  CLOSED_ACCOUNT;
	accounts[i][1] = 0;
	
	}
	printf("All accounts are closed\n ");
	return;

}
