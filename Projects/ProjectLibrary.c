#include<stdio.h>

typedef struct 
{
 char bookname[50], authorname[50];
 int bookcode, bookissued;
} Book;

typedef struct 
{
 char name[50];
 int id;
} Student;

typedef struct 
{
 Book book[10];
 int bookcount;
 Student student[10]; 
 int studentcount;   
} Library; 

void saveLibrary(Library *library)
{
 FILE *file = fopen("library.dat","wb");
 if(file==NULL)
 {
  printf("Error opening file for writing!\n");
  return;  
 }  
 fwrite(library,sizeof(Library),1,file);
 fclose(file);
 printf("Library saved successfully!\n"); 
}

void loadLibrary(Library *library)
{
 FILE *file = fopen("library.dat","rb");
 if(file==NULL)
 {
  printf("Error opening file for reading!\n"); 
  return; 
 }   
 fread(library,sizeof(Library),1,file);
 fclose(file);
 printf("Library loaded successfully!\n");
}

void studentregistration(Library *library)
{
 if((*library).studentcount>=10)
 {
  printf("Maximum number of students get registered\n"); 
  return; 
 }
 printf("Enter student name: ");
 scanf(" %[^\n]%*c",(*library).student[(*library).studentcount].name); //Or library->student[library->studentcount].name
 printf("Enter college id: ");
 scanf(" %d",&library->student[library->studentcount].id);
 library->studentcount++;
 printf("Student registered successfully!\n");
}

void addbook(Library *library)
{ 
 if(library->bookcount>=10)
 {
  printf("Maximum number of books are added\n");
  return;  
 }
 printf("Enter book name: ");
 scanf(" %[^\n]%*c",library->book[library->bookcount].bookname);
 printf("Enter author name: ");
 scanf(" %[^\n]%*c",library->book[library->bookcount].authorname);
 printf("Enter book code: ");
 scanf(" %d",&library->book[library->bookcount].bookcode);
 library->book[library->bookcount].bookissued=0;
 library->bookcount++;
 printf("Book added successfully!\n");
}

void availablebook(Library *library)
{
 if(library->bookcount==0)
 {
  printf("No books in the library!\n");
  return;  
 }   
 for(int i=0; i<library->bookcount; i++)
 {
  printf("Book name: %s\n",library->book[i].bookname);
  printf("Author name: %s\n",library->book[i].authorname);
  printf("Book code: %d\n",library->book[i].bookcode);  
  if(library->book[i].bookissued)
  {
   printf("Book is not available\n\n");
  }
  else
  {
   printf("Book is available\n\n"); 
  }
 }
}

void bookissue(Library *library)
{
 int CollegeId, BookCode;
 printf("Enter college ID: ");
 scanf(" %d",&CollegeId);
 printf("Enter Book Code: ");
 scanf(" %d",&BookCode);
 for(int i=0; i<library->studentcount; i++)
 {
  if(library->student[i].id==CollegeId)
  {
   for(int j=0; j<library->bookcount; j++)
   {
    if(library->book[j].bookcode==BookCode)
    {
     if(library->book[j].bookissued)
     {
      printf("Book is already issued!\n");  
     }   
     else
     {
      library->book[j].bookissued=1;
      printf("Book Issued Successfully!\n"); 
     }
     return;
    }
   }
   printf("Book not found!\n");
   return; 
  }  
 }
 printf("Student not registered!\n");
}

void returnbook(Library *library)
{
 int BookCode, CollegeId;
 printf("Enter college id: ");
 scanf(" %d",&CollegeId);
 printf("Enter book code: ");
 scanf(" %d",&BookCode);
 for(int i=0; i<library->studentcount; i++)
 {
  if(library->student[i].id==CollegeId)
  {
   for(int j=0; j<library->bookcount; j++)
   {
    if(library->book[j].bookcode==BookCode)
    {
     if(library->book[j].bookissued)
     {
      library->book[j].bookissued=0;
      printf("Book returned successfully!\n");  
     }   
     else
     {
      printf("Book was not issued!\n"); 
     }
     return;
    }
   }
   printf("Book not found!\n");
   return; 
  }  
 }
 printf("Student not registered!\n");  
}

int main()
{
 system("cls");
 Library library = {0};
 loadLibrary(&library);
 int n;
 printf("Welcome to the Global Library\n"); 
 l1:
 printf("Choose an option\n");
 printf("1. Register Student\n");
 printf("2. Add Book(Admin Only)\n");
 printf("3. Book Issue\n");
 printf("4. Return Book\n");
 printf("5. List Books\n");
 printf("6. Save & Exit\n");
 scanf("%d",&n);
 if(n==1)
 {
  studentregistration(&library);
  goto l1;
 }
 else if(n==2)
 {
  addbook(&library);
  goto l1;
 }
 else if(n==3)
 {
  bookissue(&library);
  goto l1;
 }
 else if(n==4)
 {
  returnbook(&library);
  goto l1;
 }
 else if(n==5)
 {
  availablebook(&library);
  goto l1;
 }
 else if(n==6)
 {
  saveLibrary(&library);
  return 0;  
 }
 else
 {
  printf("Invalid Input!\n");
  goto l1;  
 }
 return 0;   
}