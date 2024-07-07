#include<stdio.h>

struct Bank
{
 char name[30], fname[30], dob[15], ifsc[11];
 int amount, accountnumber, pin;
};

int savecustomerdata(struct Bank customer[], int count)
{
 FILE *file=fopen("customers.dat","wb");
 if(file==NULL)
 {
  printf("Error file opening!\n");     
  return -1;
 }
 fwrite(customer,sizeof(struct Bank),count,file);
 fclose(file);
 return 0;
}

int loadcustomerdata(struct Bank customer[])
{
 FILE *file=fopen("customers.dat","rb");
 if(file==NULL)
 {
  printf("Error Opening File!\n");
  return 0;     
 }     
 int count=fread(customer,sizeof(struct Bank),10,file); 
 fclose(file);
 return count;
}

void createaccount(struct Bank *customer, int i)
{
 int pin1, pin2, n, d, j;
 char IFSC[11] = "UBCN001441";
 printf("\nWhich type of account do you want to open\n");
 printf("Enter '1' for Saving Account\nEnter '2' for Current Account\n");
 scanf("%d",&n);
 if(n==1)
 {
  printf("\nEnter some basic details:\n");
  printf("Enter your name: ");
  scanf(" %[^\n]%*c",customer[i].name);
  printf("Enter fathers name: ");
  scanf(" %[^\n]%*c",customer[i].fname);
  printf("Enter DOB: ");
  scanf(" %[^\n]%*c",customer[i].dob);
  printf("Deposite initial amount more than 1000\n");
  l4:
  printf("Enter amount to deposite: ");
  scanf("%d",&customer[i].amount);
  d=customer[i].amount;
  if(d<1000)
  {
   printf("Initial deposite amount is too low please deposite amount more than 1000\n");
   goto l4;
  }
  customer[i].accountnumber=1440;
  customer[i].accountnumber=customer[i].accountnumber*10+i;
  for(j=0; IFSC[j]!='\0'; j++)
  {
   customer[i].ifsc[j]=IFSC[j];
  }
  customer[i].ifsc[j]='\0';
  printf("Create a new transaction pin\n");
  l6:
  printf("Enter PIN:\n");
  scanf("%d",&pin1);
  printf("Re Enter PIN: ");
  scanf("%d",&pin2);
  if(pin1!=pin2)
  {
   printf("PIN Mismatch!\n");
   goto l6;
  }
  else 
  {
   printf("Your PIN is successfully created\n"); 
   customer[i].pin=pin1; 
  }
  printf("\nYour Account is successfully opened\n");
  printf("Your Account details are shown below\n");
  printf("Your Account Number is: %d\n",customer[i].accountnumber);
  printf("IFSC Code: %s\n",customer[i].ifsc);
  printf("Account type: Saving Account\n");
  printf("Name: %s\n",customer[i].name);
  printf("Father Name: %s\n",customer[i].fname);
  printf("DOB: %s\n",customer[i].dob);
  printf("Available Amount: %d\n",customer[i].amount);
 }
} 

int main()
{
 int i, j, n, deposite, withdraw, d, pin, pin1, pin2;
 char IFSC[11] = "UBCN001441";
 struct Bank customer[10];
 int customercount=loadcustomerdata(customer); 

 printf("Welcome to the Universal Bank Of College\n");
 printf("Are you new to our bank?\n");
 printf("If you are new to our bank then enter '1'\n");
 printf("If you are already a customer then enter '2'\n");
 scanf("%d",&n);
 if(n==1)
 {
  for(i=customercount; i<10; i++)
  {
   printf("\nDo you want to open a bank account?\n");
   printf("If yes then enter '1'\nIf no then enter '2'\n");
   scanf("%d",&n);
   if(n==1)
   {
    printf("\nWhich type of account do you want to open\n");
    printf("Enter '1' for Saving Account\nEnter '2' for Current Account\n");
    scanf("%d",&n);
    if(n==1)
    {
     printf("\nEnter some basic details:\n");
     printf("Enter your name: ");
     scanf(" %[^\n]%*c",customer[i].name);
     printf("Enter fathers name: ");
     scanf(" %[^\n]%*c",customer[i].fname);
     printf("Enter DOB: ");
     scanf(" %[^\n]%*c",customer[i].dob);
     printf("Deposite initial amount more than 1000\n");
     l4:
     printf("Enter amount to deposite: ");
     scanf("%d",&customer[i].amount);
     d=customer[i].amount;
     if(d<1000)
     {
      printf("Initial deposite amount is too low please deposite amount more than 1000\n");
      goto l4;
     }
     customer[i].accountnumber=1440;
     customer[i].accountnumber=customer[i].accountnumber*10+i;
     for(j=0; IFSC[j]!='\0'; j++)
     {
      customer[i].ifsc[j]=IFSC[j];
     }
     customer[i].ifsc[j]='\0';
     printf("Create a new transaction pin\n");
     l6:
     printf("Enter PIN:\n");
     scanf("%d",&pin1);
     printf("Re Enter PIN: ");
     scanf("%d",&pin2);
     if(pin1!=pin2)
     {
      printf("PIN Mismatch!\n");
      goto l6;
     }
     else 
     {
      printf("Your PIN is successfully created\n"); 
      customer[i].pin=pin1; 
     }
     printf("\nYour Account is successfully opened\n");
     printf("Your Account details are shown below\n");
     printf("Your Account Number is: %d\n",customer[i].accountnumber);
     printf("IFSC Code: %s\n",customer[i].ifsc);
     printf("Account type: Saving Account\n");
     printf("Name: %s\n",customer[i].name);
     printf("Father Name: %s\n",customer[i].fname);
     printf("DOB: %s\n",customer[i].dob);
     printf("Available Amount: %d\n",customer[i].amount);
     customercount++;

     printf("\nDo you want to do any transaction\n");
     printf("Enter '1' for Yes\nEnter '2' for No\n");
     scanf("%d",&n);
     if(n==1)
     {
      l1:
      printf("\nEnter '1' to deposite amount\nEnter '2' to withdraw amount\n");
      scanf("%d",&n);
      if(n==1)
      {
       printf("Enter amount to deposite: ");
       scanf("%d",&deposite);
       l7:
       printf("Enter transaction PIN: ");
       scanf("%d",&pin);
       if(pin!=customer[i].pin)
       {
        printf("PIN Mismatch!\nRe ");
        goto l7;
       }
       customer[i].amount=customer[i].amount+deposite;
       printf("\nAmount %d deposited successfully\n",deposite);
       printf("Total Available Balance: %d\n",customer[i].amount);
       printf("\nDo you want to do more transaction\n");
       printf("If yes then enter '1'\nIf no then enter '2'\n");
       scanf("%d",&n);
       if(n==1)
       {
	goto l1;
       }
       else
       {
	printf("Thank you for choosing UBC");
       savecustomerdata(customer,customercount);
	goto l2;
       }
      }
      else
      {
       l15:
       printf("Enter amount to withdraw: ");
       scanf("%d",&withdraw);
       l10:
       printf("Enter transaction PIN: ");
       scanf("%d",&pin);
       if(pin!=customer[i].pin)
       {
        printf("PIN Mismatch!\nRe ");
        goto l10;
       }
       if(withdraw>customer[i].amount)
       {
        printf("Insufficent Amount!\n");
        printf("Enter amount less than available amount\n");
        goto l15;      
       }
       customer[i].amount=customer[i].amount-withdraw;
       printf("\nAmount %d deducted successfully",withdraw);
       printf("\nTotal Available Balance: %d\n",customer[i].amount);
       printf("\nDo you want to do more transaction\n");
       printf("If yes then enter '1'\nIf no then enter '2'\n");
       scanf("%d",&n);
       if(n==1)
       {
	goto l1;
       }
       else
       {
	printf("Thank you for choosing UBC");
       savecustomerdata(customer,customercount);
	goto l2;
       }
      }
     }
     else
     {
      printf("Thank you for choosing UBC");
      savecustomerdata(customer,customercount);
      goto l2;
     }
    }
    else
    {
     printf("\nEnter some basic details:\n");
     printf("Enter your name: ");
     scanf(" %[^\n]%*c",customer[i].name);
     printf("Enter fathers name: ");
     scanf(" %[^\n]%*c",customer[i].fname);
     printf("Enter DOB: ");
     scanf(" %[^\n]%*c",customer[i].dob);
     printf("Deposite initial amount more than 3000\n");
     l5:
     printf("Enter amount to deposite: ");
     scanf("%d",&customer[i].amount);
     d=customer[i].amount;
     if(d<3000)
     {
      printf("Initial deposite amount is too low please deposite amount more than 3000\n");
      goto l5;
     }
     customer[i].accountnumber=1441;
     customer[i].accountnumber=customer[i].accountnumber*10+i;
     for(j=0; IFSC[j]!='\0'; j++)
     {
      customer[i].ifsc[j]=IFSC[j];
     }
     customer[i].ifsc[j]='\0';
     printf("Create a new transaction pin\n");
     l8:
     printf("Enter PIN:\n");
     scanf("%d",&pin1);
     printf("Re Enter PIN: ");
     scanf("%d",&pin2);
     if(pin1!=pin2)
     {
      printf("PIN Mismatch!\n");
      goto l8;
     }
     else 
     {
      printf("Your PIN is successfully created\n"); 
      customer[i].pin=pin1; 
     }
     printf("\nYour Account is successfully opened\n");
     printf("Your Account details are shown below\n");
     printf("Your Account Number is: %d\n",customer[i].accountnumber);
     printf("IFSC Code: %s\n",customer[i].ifsc);
     printf("Account type: Current Account\n");
     printf("Name: %s\n",customer[i].name);
     printf("Father Name: %s\n",customer[i].fname);
     printf("DOB: %s\n",customer[i].dob);
     printf("Available Amount: %d\n",customer[i].amount);
     customercount++;

     printf("\nDo you want to do any transaction\n");
     printf("Enter '1' for Yes\nEnter '2' for No\n");
     scanf("%d",&n);
     if(n==1)
     {
      l3:
      printf("\nEnter '1' to deposite amount\nEnter '2' to withdraw amount\n");
      scanf("%d",&n);
      if(n==1)
      {
       printf("Enter amount to deposite: ");
       scanf("%d",&deposite);
       l9:
       printf("Enter transaction PIN: ");
       scanf("%d",&pin);
       if(pin!=customer[i].pin)
       {
        printf("PIN Mismatch!\nRe ");
        goto l9;
       }
       customer[i].amount=customer[i].amount+deposite;
       printf("\nAmount %d deposited successfully\n",deposite);
       printf("Total Available Balance: %d\n",customer[i].amount);
       printf("\nDo you want to do more transaction\n");
       printf("If yes then enter '1'\nIf no then enter '2'\n");
       scanf("%d",&n);
       if(n==1)
       {
	goto l3;
       }
       else
       {
	printf("Thank you for choosing UBC");
       savecustomerdata(customer,customercount);
	goto l2;
       }
      }
      else
      {
       l16:
       printf("Enter amount to withdraw: ");
       scanf("%d",&withdraw);
       l11:
       printf("Enter transaction PIN: ");
       scanf("%d",&pin);
       if(pin!=customer[i].pin)
       {
        printf("PIN Mismatch!\nRe ");
        goto l11;
       }
       if(withdraw>customer[i].amount)
       {
        printf("Insufficent Amount!\n");
        printf("Enter amount less than available amount\n");
        goto l16;      
       }
       customer[i].amount=customer[i].amount-withdraw;
       printf("\nAmount %d deducted successfully",withdraw);
       printf("\nTotal Available Balance: %d\n",customer[i].amount);
       printf("\nDo you want to do more transaction\n");
       printf("If yes then enter '1'\nIf no then enter '2'\n");
       scanf("%d",&n);
       if(n==1)
       {
	goto l3;
       }
       else
       {
	printf("Thank you for choosing UBC");
       savecustomerdata(customer,customercount);
	goto l2;
       }
      }
     }
     else
     {
      printf("Thank you for choosing UBC");
      savecustomerdata(customer,customercount);
      goto l2;
     }
    }
   }
   else
   {
    printf("Thank you for visiting UBC");
    goto l2;
   }
  }
 }
 else
 {
  printf("Enter your account number: ");
  int a;
  scanf("%d",&a);
  for(i=0; i<customercount; i++)
  {
   if(a==customer[i].accountnumber)  
   {
    l13:   
    printf("\nEnter '1' to deposite amount\nEnter '2' to withdraw amount\n");
    scanf("%d",&n);
    if(n==1)
    {
     printf("Enter amount to deposite: ");
     scanf("%d",&deposite);
     l12:
     printf("Enter transaction PIN: ");
     scanf("%d",&pin);
     if(pin!=customer[i].pin)
     {
      printf("PIN Mismatch!\nRe ");
      goto l12;
     } 
    }
    customer[i].amount=customer[i].amount+deposite;
    printf("\nAmount %d deposited successfully\n",deposite);
    printf("Total Available Balance: %d\n",customer[i].amount);
    printf("\nDo you want to do more transaction\n");
    printf("If yes then enter '1'\nIf no then enter '2'\n");
    scanf("%d",&n);
    if(n==1)
    {
     goto l13;
    }
    else
    {
     printf("Thank you for choosing UBC");
     savecustomerdata(customer,customercount);
     goto l2;
    }
   }
   else
   {
    l17:   
    printf("Enter amount to withdraw: ");
    scanf("%d",&withdraw);
    l14:
    printf("Enter transaction PIN: ");
    scanf("%d",&pin);
    if(pin!=customer[i].pin)
    {
     printf("PIN Mismatch!\nRe ");
     goto l14;
    }
    if(withdraw>customer[i].amount)
    {
     printf("Insufficent Amount!\n");
     printf("Enter amount less than available amount\n");
     goto l17;      
    }
    customer[i].amount=customer[i].amount-withdraw;
    printf("\nAmount %d deducted successfully",withdraw);
    printf("\nTotal Available Balance: %d\n",customer[i].amount);
    printf("\nDo you want to do more transaction\n");
    printf("If yes then enter '1'\nIf no then enter '2'\n");
    scanf("%d",&n);
    if(n==1)
    {
     goto l13;
    }
    else
    {
     printf("Thank you for choosing UBC");
     savecustomerdata(customer,customercount);
     goto l2;
    }
   }
  }  
 }  
 l2:
 return 0;
}