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
	  
void OpenAccount()
{	
	printf("How much money would  you like to deposit to your new account :\n" );
	double amount;
	if (scanf("%lf",&amount)==1)
	{
	if (_openAccounts>=50)
	{
	printf("Sorry, the bank is full, can't open new account.");
	return;
	}
	if(amount<0)
	{
	printf("Can't withdraw money you dont have.");
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
	else
	{
	printf("Wrong type, Insert new transaction type.");
	return;
	}
}


void CheckBalance()
{	
        printf("Please insert your account number:\n");
	if (scanf("%d",&account_number)==1)
	{
	if (account_number<901 || account_number>950)
	{
	printf("There is no such account");
	return;
	}
	if(accounts[(account_number-901)][0] != CLOSED_ACCOUNT)
	{
 	printf("Your account balance is: %0.2lf \n",accounts[(account_number - 901)][1]);
	}
	else {
	printf("This account does not exist\n");
	}
	}
	return;	
}

	
void Deposit()
{   
	printf("Please insert your account number: \n" );
	scanf("%d",&account_number);
	if (account_number<901 || account_number>950)
	{
	printf("There is no such account");
	return;
	}
	if(accounts[(account_number-901)][0] == ((double) OPENED_ACCOUNT))
	{
        printf("Your deposit amount? \n");
        double DepositAmount;
        scanf("%lf",&DepositAmount);
	if(DepositAmount<0)
	{
	printf("Can't deposit negative value");
	return;
	}
	accounts[(account_number - 901)][1] = (((double)(accounts[(account_number - 901)][1])) + (DepositAmount));
	(accounts[account_number - 901][1]) = ((int)((accounts[account_number - 901][1])*100))/100.0;
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
	if (account_number<901 || account_number>950)
	{
	printf("There is no such account");
	return;
	}
	printf("How much money would you like to withdraw ? \n");
        double WithdrawalAmount;
        scanf("%lf",&WithdrawalAmount);
	if(WithdrawalAmount<0)
	{
	printf("Can't withdraw negative amount.");
	return;
	}
	if (WithdrawalAmount > (accounts[account_number - 901][1]))
	{
	printf("Can't withdraw this amount, not enough money in the bank account.\n");
	return;
	}
	accounts[(account_number - 901)][1] = accounts[account_number - 901][1] -  WithdrawalAmount ;
	(accounts[account_number - 901][1]) = ((int)((accounts[account_number - 901][1])*100))/100.0;
	printf("Your new balance is: %0.2lf\n", accounts[account_number - 901][1]);
	return;
}

void CloseAccount()
{
	printf("Please insert the account number you would like to close: \n" );
	scanf("%d",&account_number);
	if (account_number<901 || account_number>950)
	{
	printf("There is no such account");
	return;
	}
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

void AddInterest()
{
	int interest=0;	
	printf("What percentage of interest you want to add?\n");
	if(scanf("%d",&interest)==1)
	{
	if(interest<0)
	{
	printf("Can't add negative percent");
	return;
	}
	for(int i=0;i<50;i++)
	{
	(accounts[i][1]) += ((accounts[i][1])*(interest/100.0));
	(accounts[i][1]) = ((int)((accounts[i][1])*100))/100.0;
	}
	printf("Successfully added '%d' percent interest!", interest);
	return;	
	}
	printf("Something went wrong");
 	return;
}
	

void AllAccounts()
{
	if(_openAccounts==0)
	{
	printf("There are no open accounts");
	return;
	}
	for(int i=0; i<50; i++) 
	{
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
