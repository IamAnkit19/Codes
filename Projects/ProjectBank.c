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
 l10:
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
  l1:
  printf("Enter amount to deposite: ");
  scanf("%d",&customer[i].amount);
  d=customer[i].amount;
  if(d<1000)
  {
   printf("Initial deposite amount is too low please deposite amount more than 1000\n");
   goto l1;
  }
  customer[i].accountnumber=1440;
  customer[i].accountnumber=customer[i].accountnumber*10+i;
  for(j=0; IFSC[j]!='\0'; j++)
  {
   customer[i].ifsc[j]=IFSC[j];
  }
  customer[i].ifsc[j]='\0';
  printf("Create a new transaction pin\n");
  l2:
  printf("Enter PIN:\n");
  scanf("%d",&pin1);
  printf("Re Enter PIN: ");
  scanf("%d",&pin2);
  if(pin1!=pin2)
  {
   printf("PIN Mismatch!\n");
   goto l2;
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
 else if(n==2)
 {
  printf("\nEnter some basic details:\n");
  printf("Enter your name: ");
  scanf(" %[^\n]%*c",customer[i].name);
  printf("Enter fathers name: ");
  scanf(" %[^\n]%*c",customer[i].fname);
  printf("Enter DOB: ");
  scanf(" %[^\n]%*c",customer[i].dob);
  printf("Deposite initial amount more than 3000\n");
  l3:
  printf("Enter amount to deposite: ");
  scanf("%d",&customer[i].amount);
  d=customer[i].amount; 
  if(d<3000)
  {
   printf("Initial deposite amount is too low please deposite amount more than 3000\n");
   goto l3;
  }
  customer[i].accountnumber=1441;
  customer[i].accountnumber=customer[i].accountnumber*10+i;
  for(j=0; IFSC[j]!='\0'; j++)
  {
   customer[i].ifsc[j]=IFSC[j];
  }
  customer[i].ifsc[j]='\0';
  printf("Create a new transaction pin\n");
  l4:
  printf("Enter PIN:\n");
  scanf("%d",&pin1);
  printf("Re Enter PIN: ");
  scanf("%d",&pin2);
  if(pin1!=pin2)
  {
   printf("PIN Mismatch!\n");
   goto l4;
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
 }    
 else
  printf("Invalid Input!\n");
  goto l10;
} 

void performtransaction(struct Bank *customer, int i)
{
 int n, pin, deposite, withdraw;
 l6:
 printf("\nEnter '1' to deposite amount\nEnter '2' to withdraw amount\n");
 scanf("%d",&n);
 if(n==1)
 {
  printf("Enter amount to deposite: ");
  scanf("%d",&deposite);
  l5:
  printf("Enter transaction PIN: ");
  scanf("%d",&pin);
  if(pin!=customer[i].pin)
  {
   printf("PIN Mismatch!\nRe ");
   goto l5;
  }
  customer[i].amount=customer[i].amount+deposite;
  printf("\nAmount %d deposited successfully\n",deposite);
  printf("Total Available Balance: %d\n",customer[i].amount);
  l14:
  printf("\nDo you want to do more transaction\n");
  printf("If yes then enter '1'\nIf no then enter '2'\n");
  scanf("%d",&n);
  if(n==1)
  {
   goto l6;
  }
  else if(n==2)
  {
   printf("Thank you for choosing UBC");
  }
  else
  {
   printf("Invalid Input\n");
   goto l14; 
  }
 }
 else if(n==2)
 {
  l7:
  printf("Enter amount to withdraw: ");
  scanf("%d",&withdraw);
  l8:
  printf("Enter transaction PIN: ");
  scanf("%d",&pin);
  if(pin!=customer[i].pin)
  {
   printf("PIN Mismatch!\nRe ");
   goto l8;
  }
  if(withdraw>customer[i].amount)
  {
   printf("Insufficent Amount!\n");
   printf("Enter amount less than available amount\n");
   goto l7;      
  }
  customer[i].amount=customer[i].amount-withdraw;
  printf("\nAmount %d deducted successfully",withdraw);
  printf("\nTotal Available Balance: %d\n",customer[i].amount);
  l13:
  printf("\nDo you want to do more transaction\n");
  printf("If yes then enter '1'\nIf no then enter '2'\n");
  scanf("%d",&n);
  if(n==1)
  {
   goto l6;
  }
  else if(n==2)
  {
   printf("Thank you for choosing UBC");
  }
  else
  {
   printf("Invalid Input\n");
   goto l13; 
  }    
 }
 else
 {
  printf("Invalid Input\n");
  goto l6;
 }
}  

void existingcustomer(struct Bank customer[], int customercount)
{
 int accountnumber, i, n, found;
 found=0;
 printf("Enter your account number: ");
 scanf("%d",&accountnumber);
 for(i=0; i<customercount; i++)
 {
  if(accountnumber==customer[i].accountnumber)
  {
   found=1;    
   performtransaction(customer,i);
   break;    
  }  
 } 
 if(found==0)
  {
   printf("Account not found!\n");
  }         
}

int main()
{
 int i, j, n, d, pin;
 struct Bank customer[10];
 int customercount=loadcustomerdata(customer); 

 printf("Welcome to the Universal Bank Of College\n");
 printf("Are you new to our bank?\n");
 l11:
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
    createaccount(customer,i);
    customercount++;

    l12:
    printf("\nDo you want to do any transaction\n");
    printf("Enter '1' for Yes\nEnter '2' for No\n");
    scanf("%d",&n);
    if(n==1)
    {
     performtransaction(customer,i);
     savecustomerdata(customer,customercount);
     goto l9;
    }
    else if(n==2)
    {
     printf("Thank you for choosing UBC");
     savecustomerdata(customer,customercount);
     goto l9;
    }
    else
    {
     printf("Invalid Input\n");
     goto l12;
    }
   }
   else
   {
    printf("Thank you for visiting UBC");
    goto l9;
   }
  } 
 }         
 else if(n==2)
 {
  existingcustomer(customer,customercount);
  savecustomerdata(customer,customercount);
 }
 else
 {
  printf("Invalid Input\n");
  goto l11;
 }
 l9:
 return 0;
}