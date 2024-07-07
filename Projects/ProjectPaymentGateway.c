#include<stdio.h>
#include<time.h>

typedef struct 
{
 int userID;
 char username[30];
 char password[30];
 char email[30];
 char name[30];
 char phone[30];
 char DOB[30];
 char creditcard[16];
 char debitcard[16];
 char UPI[20];
 int creditcardpin;
 int debitcardpin;
 int upipin;
} User;

typedef struct 
{
 int transactionID;
 int userID;
 char paymentmethod[30];
 int amount;
 char date[30];
 char status[30];
} Transaction;

typedef struct 
{
 User user[10];
 int usercount;
 Transaction transaction[100];
 int transactioncount;
} PaymentGateway;

void saveGateway(PaymentGateway *gateway)
{
 FILE *file = fopen("gateway.dat","wb");
 if(file==NULL)
 {
  printf("Error opening file for writing!\n");
  return;  
 }  
 fwrite(gateway,sizeof(PaymentGateway),1,file);
 fclose(file);
 printf("Gateway saved successfully!\n"); 
}

void loadGateway(PaymentGateway *gateway)
{
 FILE *file = fopen("gateway.dat","rb");
 if(file==NULL)
 {
  printf("Error opening file for reading!\n"); 
  return; 
 }   
 fread(gateway,sizeof(PaymentGateway),1,file);
 fclose(file);
 printf("Gateway loaded successfully!\n");
}

void registeruser(PaymentGateway *gateway)
{
 if(gateway->usercount>=10)
 {
  printf("Cannot add more users!\n");
  return;  
 }   
 char password1[30], password2[30];
 int i, n;
 printf("Enter your name: ");
 scanf(" %[^\n]%*c",gateway->user[gateway->usercount].name);
 printf("Enter DOB (DD-MM-YYYY): ");
 scanf(" %[^\n]%*c",gateway->user[gateway->usercount].DOB);
 printf("Enter Mobile Number: ");
 scanf(" %[^\n]%*c",gateway->user[gateway->usercount].phone);
 printf("Enter email ID: ");
 scanf(" %[^\n]%*c",gateway->user[gateway->usercount].email);
 printf("Enter username: ");
 scanf(" %[^\n]%*c",gateway->user[gateway->usercount].username);
 l2:
 printf("Enter password: ");
 scanf(" %[^\n]%*c",password1);
 printf("Re Enter password: ");
 scanf(" %[^\n]%*c",password2);
 for(i=0; password1[i]!='\0'; i++)
 {
  if(password1[i]!=password2[i])
  {
   printf("Password Mismatch!\n");
   goto l2; 
  }
 }
 for(i=0; password1[i]!='\0'; i++)
 {
  gateway->user[gateway->usercount].password[i]=password1[i];
 }
 gateway->user[gateway->usercount].password[i]='\0'; 
 gateway->user[gateway->usercount].userID=12171+gateway->usercount;
 printf("User registered successfully\n");
 printf("Your user id is: %d\n",gateway->user[gateway->usercount].userID);
 l3:
 printf("Do you want to add more Payment Credential\n");
 printf("1. Yes\n");
 printf("2. No\n");
 scanf(" %d",&n);
 if(n==1)
 {
  printf("Choose what to add\n");
  printf("1. Credit Card\n");
  printf("2. Debit card\n");
  printf("3. UPI\n");
  scanf(" %d",&n);
  if(n==1)
  {
   char creditcard[16];
   l4:
   printf("Enter Credit Card Number: ");
   scanf(" %[^\n]%*c",creditcard);
   if(sizeof(creditcard)==16)
   {
    for(i=0; creditcard[i]!='\0'; i++)
    {
     gateway->user[gateway->usercount].creditcard[i]=creditcard[i];   
    }
    gateway->user[gateway->usercount].creditcard[i]='\0';
    printf("Enter credit card pin: ");
    scanf(" %d",&gateway->user[gateway->usercount].creditcardpin);
    printf("Credit Card Added Successfully!\n");
    goto l3;
   }
   else
   {
    printf("Invalid Credit Card Number!\n");
    printf("Re ");
    goto l4;
   }
  }  
  else if(n==2)
  { 
   char debitcard[16]; 
   l5:
   printf("Enter Debit Card Number: ");
   scanf(" %[^\n]%*c",debitcard); 
   if(sizeof(debitcard)==16)
   {
    for(i=0; debitcard[i]!='\0'; i++)
    {
     gateway->user[gateway->usercount].debitcard[i]=debitcard[i];   
    }
    gateway->user[gateway->usercount].debitcard[i]='\0';
    printf("Enter debit card pin: ");
    scanf(" %d",&gateway->user[gateway->usercount].debitcardpin);
    printf("Debit Card Added Successfully!\n");
    goto l3;
   }
   else
   {
    printf("Invalid Debit Card Number!\n");
    printf("Re ");
    goto l5;
   }
  }
  else if(n==3)
  {
   printf("Enter UPI number: ");
   scanf(" %[^\n]%*c",gateway->user[gateway->usercount].UPI);
   printf("Enter upi pin: ");
   scanf(" %d",&gateway->user[gateway->usercount].upipin);
   printf("UPI Added Successfully!\n");
   goto l3; 
  }
 }
 else if(n==2)
 {
  goto l6;  
 }
 else
 {
  printf("Invalid Input!\n");
  goto l3;  
 }
 l6:
 gateway->usercount++;
}

void payment(PaymentGateway *gateway)
{
 if(gateway->transactioncount>=100)
 {
  printf("Cannot perform more transactions!\n");
  return;  
 } 
 int userid, n, i, j; 
 char status[]="Completed"; 
 l2:
 printf("Enter user ID: ");
 scanf(" %d",&userid);
 for(i=0; i<=gateway->usercount; i++)
 {
  if(userid==gateway->user[i].userID)
  {
   goto l1;
  }
 }
 printf("User not found1\n");
 printf("Re ");
 goto l2;
 l1:
 printf("Choose payment method\n");
 printf("1. Credit Card\n");
 printf("2. Debit Card\n");
 printf("3. UPI\n");
 printf("4. Netbanking(Currently Not Working)\n");
 scanf(" %d",&n);
 printf("Enter amount: ");
 scanf(" %d",&gateway->transaction[gateway->transactioncount].amount);
 if(n==1)
 {
  int pin;
  char method[]="Credit Card";
  l7:
  printf("Enter pin: ");
  scanf(" %d",&pin);
  if(pin!=gateway->user[i].creditcardpin) 
  {
   printf("Pin Mismatch!\n");
   printf("Re ");
   goto l7; 
  }
  for(j=0; method[j]!='\0'; j++)
  {
   gateway->transaction[gateway->transactioncount].paymentmethod[j]=method[j];
  } 
  gateway->transaction[gateway->transactioncount].paymentmethod[j]='\0';
 }
 else if(n==2)
 {
  int pin;
  char method[]="Debit Card";
  l8:
  printf("Enter pin: ");
  scanf(" %d",&pin);
  if(pin!=gateway->user[i].debitcardpin) 
  {
   printf("Pin Mismatch!\n");
   printf("Re ");
   goto l8; 
  } 
  for(j=0; method[j]!='\0'; j++)
  {
   gateway->transaction[gateway->transactioncount].paymentmethod[j]=method[j];
  } 
  gateway->transaction[gateway->transactioncount].paymentmethod[j]='\0';
 }
 else if(n==3)
 {
  int pin;
  char method[]="UPI";
  l9:
  printf("Enter pin: ");
  scanf(" %d",&pin);
  if(pin!=gateway->user[i].upipin) 
  {
   printf("Pin Mismatch!\n");
   printf("Re ");
   goto l9; 
  }   
  for(j=0; method[j]!='\0'; j++)
  {
   gateway->transaction[gateway->transactioncount].paymentmethod[j]=method[j];
  } 
  gateway->transaction[gateway->transactioncount].paymentmethod[j]='\0';
 }
 else
 {
  printf("Invalid Input!\n");
  goto l1;  
 }
 time_t t = time(NULL);
 struct tm tm = *localtime(&t);
 sprintf(gateway->transaction[gateway->transactioncount].date,"%02d-%02d-%04d %02d:%02d:%02d",tm.tm_mday,tm.tm_mon + 1,tm.tm_year + 1900,tm.tm_hour,tm.tm_min,tm.tm_sec);
 gateway->transaction[gateway->transactioncount].userID=userid;
 gateway->transaction[gateway->transactioncount].transactionID=21171+gateway->transactioncount;
 for(i=0; status[i]!='\0'; i++)
 {
  gateway->transaction[gateway->transactioncount].status[i]=status[i]; 
 }
 gateway->transaction[gateway->transactioncount].status[i]='\0';
 gateway->transactioncount++;
 printf("Payment processed successfully!\n");
}

void viewtransaction(PaymentGateway *gateway)
{
 if(gateway->transactioncount==0)
 {
  printf("No transactions!\n");
  return;  
 }   

 printf("%-15s %-10s %-10s %-20s %-25s %-15s","Transaction ID","User ID","Amount","Payment Method","Date","Status\n");
 printf("----------------------------------------------------------------------\n");  
 for(int i=0; i<=gateway->transactioncount; i++)
 {
  printf(" %-15d",gateway->transaction[i].transactionID);
  printf(" %-10d",gateway->transaction[i].userID);
  printf(" %-10d",gateway->transaction[i].amount);
  printf(" %-20s",gateway->transaction[i].paymentmethod);
  printf(" %-25s",gateway->transaction[i].date);
  printf(" %-15s\n",gateway->transaction[i].status);
 }

//   for(int i=0; i<gateway->transactioncount; i++)
//  {
//   printf("Transaction Id: %d\n",gateway->transaction[i].transactionID);
//   printf("User Id: %d\n",gateway->transaction[i].userID);
//   printf("Amount: %d\n",gateway->transaction[i].amount);
//   printf("Payment Method: %s\n",gateway->transaction[i].paymentmethod);
//   printf("Date: %s\n",gateway->transaction[i].date);
//   printf("Status: %s\n\n",gateway->transaction[i].status);
//  }
}

int main()
{
 system("cls");
 PaymentGateway gateway = {0};
 int n;
 loadGateway(&gateway);
 printf("Welcome to the Payment Gateway\n");
 l1:
 printf("1. Register User\n");
 printf("2. User Login (Currently Not Working Under Maintenance)\n");
 printf("3. Payment\n");
 printf("4. View Transaction\n");
 printf("5. Exit\n");
 printf("Choose an option\n");
 scanf(" %d",&n);
 if(n==1)
 {
  registeruser(&gateway);
  goto l1;
 }
 else if(n==2)
 {
  goto l1;
 }  
 else if(n==3)
 {
  payment(&gateway);
  goto l1;
 } 
 else if(n==4)
 {
  viewtransaction(&gateway);
  goto l1;
 }
 else if(n==5)
 {
  printf("Thank You\n");
  saveGateway(&gateway);
  return 0;
 }
 else
 {
  printf("Invalid Input\n");
  goto l1;  
 }
 return 0;
}