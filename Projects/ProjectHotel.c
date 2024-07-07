#include<stdio.h>

typedef struct
{
 int roomnumber;
 int pricepernight;
 int isavailable;
 char type[50]; //single bed or double   
} Room;

typedef struct
{
 int customerid;
 char name[50];
 char phone[15];
 char email[50];
} Customer;

typedef struct 
{
 int bookingid;
 int roomnumber;
 int customerid;
 char checkindate[20];
 char checkoutdate[20];
} Booking;

typedef struct 
{
 int staffId;
 char staffname[50];
 char position[50];
 char staffphone[15];
 char staffemail[50];   
} Staff;

typedef struct 
{
 Room rooms[10];
 int roomcount;
 Customer customer[10];
 int customercount;
 Booking booking[10];
 int bookingcount;
 Staff staff[10];
 int staffcount;
} Hotel;

void saveHotel(Hotel *hotel)
{
 FILE *file = fopen("hotel.dat","wb");
 if(file==NULL)
 {
  printf("Error opening file for writing!\n");
  return;  
 }  
 fwrite(hotel,sizeof(Hotel),1,file);
 fclose(file);
 printf("Hotel saved successfully!\n"); 
}

void loadHotel(Hotel *hotel)
{
 FILE *file = fopen("hotel.dat","rb");
 if(file==NULL)
 {
  printf("Error opening file for reading!\n"); 
  return; 
 }   
 fread(hotel,sizeof(Hotel),1,file);
 fclose(file);
 printf("Hotel loaded successfully!\n");
}

void addroom(Hotel *hotel)
{
 if(hotel->roomcount>=10)
 {
  printf("Cannot add more rooms\n");
  return;  
 }   
 printf("Enter room number: ");
 scanf(" %d",&hotel->rooms[hotel->roomcount].roomnumber);
 printf("Enter room type: ");
 scanf(" %[^\n]%*c",hotel->rooms[hotel->roomcount].type);
 printf("Enter price per night: ");
 scanf(" %d",&hotel->rooms[hotel->roomcount].pricepernight);
 hotel->rooms[hotel->roomcount].isavailable=1;
 hotel->roomcount++;
 printf("Room Added Successfully!\n");
}

void addcustomer(Hotel *hotel)
{
 if(hotel->customercount>=10)
 {
  printf("Cannot add more customers\n");
  return;  
 }   
 printf("Enter customer id: ");
 scanf(" %d",&hotel->customer[hotel->customercount].customerid);
 printf("Enter customer name: ");
 scanf(" %[^\n]%*c",hotel->customer[hotel->customercount].name);
 printf("Enter customer phone number: ");
 scanf(" %[^\n]%*c",hotel->customer[hotel->customercount].phone);
 printf("Enter customer email id: ");
 scanf(" %[^\n]%*c",hotel->customer[hotel->customercount].email);
 hotel->customercount++;
 printf("Customer added successfully!\n");
}

void addbooking(Hotel *hotel)
{
 if(hotel->bookingcount>=10)
 {
  printf("Cannot add more bookings\n");
  return;  
 }   
 int customerid, roomnumber;
 printf("Enter booking id: ");
 scanf(" %d",&hotel->booking[hotel->bookingcount].bookingid);
 printf("Enter customer id: ");
 scanf(" %d",&customerid);
 printf("Enter room number: ");
 scanf(" %d",&roomnumber);
 for(int i=0; i<hotel->roomcount; i++)
 {
  if(hotel->rooms[i].roomnumber==roomnumber && hotel->rooms[i].isavailable)
  {
   hotel->rooms[i].isavailable=0;
   hotel->booking[hotel->bookingcount].roomnumber=roomnumber;
   hotel->booking[hotel->bookingcount].customerid=customerid;
   printf("Enter check-in date (DD-MM-YYYY): ");
   scanf(" %[^\n]%*c",hotel->booking[hotel->bookingcount].checkindate);
   printf("Enter check-out date (DD-MM-YYYY): ");
   scanf(" %[^\n]%*c",hotel->booking[hotel->bookingcount].checkoutdate);
   hotel->bookingcount++;
   printf("Booking Added Sccessfully!\n"); 
   return;
  }  
 }
 printf("Room not available or invalid room number!\n");
}

void listrooms(Hotel *hotel)
{
 if(hotel->roomcount==0)
 {
  printf("No rooms available!\n");
  return;  
 }   
 for(int i=0; i<hotel->roomcount; i++)
 {
  printf("Room number: %d\n",hotel->rooms[i].roomnumber);
  printf("Room type: %s\n",hotel->rooms[i].type);
  printf("Price per night: %d\n",hotel->rooms[i].pricepernight);
  printf("Availability: ");
  if(hotel->rooms[i].isavailable)
  {
   printf("Room is available\n\n"); 
  }
  else
  {
   printf("Room not available\n\n"); 
  }
 }
}

void listbookings(Hotel *hotel)
{
 if(hotel->bookingcount==0)
 {
  printf("No bookings!\n");
  return;
 }   
 for(int i=0; i<hotel->bookingcount; i++)
 {
  printf("Booking ID: %d\n",hotel->booking[i].bookingid);
  printf("Room number: %d\n",hotel->booking[i].roomnumber);
  printf("Customer id: %d\n",hotel->booking[i].customerid);
  printf("Check-in date: %s\n",hotel->booking[i].checkindate);
  printf("Check-out date: %s\n\n",hotel->booking[i].checkoutdate);
 }
}

void registerstaff(Hotel *hotel)
{
 if(hotel->staffcount>=10)
 {
  printf("Cannot add more staff\n");
  return;  
 }   
 printf("Enter staff ID: ");
 scanf(" %d",&hotel->staff[hotel->staffcount].staffId);
 printf("Enter staff name: ");
 scanf(" %[^\n]%*c",hotel->staff[hotel->staffcount].staffname);
 printf("Enter position: ");
 scanf(" %[^\n]%*c",hotel->staff[hotel->staffcount].position);
 printf("Enter phone number: ");
 scanf(" %[^\n]%*c",hotel->staff[hotel->staffcount].staffphone);
 printf("Enter email id: ");
 scanf(" %[^\n]%*c",hotel->staff[hotel->staffcount].staffemail);
 hotel->staffcount++;
 printf("Staff Member Added Successfully!\n");
}

int main()
{
 system("cls");
 Hotel hotel = {0};
 int n;
 loadHotel(&hotel);
 printf("Welcome to the Global Hotel\n");
 l1:
 printf("Choose an option\n");
 printf("1. Add Room\n");
 printf("2. Add Customer\n");
 printf("3. Add Booking\n");
 printf("4. List Rooms\n");
 printf("5. List Bookings\n");
 printf("6. Register Staff\n");
 printf("7. Exit\n");
 scanf("%d",&n);
 if(n==1)
 {
  addroom(&hotel);
  goto l1;
 }
 else if(n==2)
 {
  addcustomer(&hotel);
  goto l1;
 }
 else if(n==3)
 {
  addbooking(&hotel);
  goto l1;
 }
 else if(n==4)
 {
  listrooms(&hotel);
  goto l1;
 }
 else if(n==5)
 {
  listbookings(&hotel);
  goto l1;
 }
 else if(n==6)
 {
  registerstaff(&hotel);
  goto l1;
 }
 else if(n==7)
 {
  printf("Thank You For Visiting\n");
  saveHotel(&hotel);
  return 0;
 }
 else
 {
  printf("Invalid input\n");
  goto l1;  
 }
 return 0;
}