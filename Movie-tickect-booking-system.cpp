#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

typedef struct node
{
char row_no;
int seat_no,pin;
char book;
struct node *next,*prev;
}node;

struct book
{
	char code[20];
	char name[20];
	char date[20];
	int cost;
        char type[20];
	

}b;

int seat = 60 ;

void insert_details();//for inserting movie details
void viewAll(); // for view all data 
void find(); // for finding data




class dcll
{
public:
node *hn;
dcll()
{
hn=NULL;
}
public:
void create()
{
//printf ("======================================");
node *nn,*cn;
int j=1;
volatile int k=2;
char c ='A';

do
{
int i=1;
do
{
k=(k*k)/10+100-k/2;
nn=new node();
nn->next=nn->prev=NULL;
nn->row_no=c;
nn->seat_no=i;
nn->pin=k;
nn->book='a';
if(hn==NULL)
{
hn=nn;
nn->next=nn->prev=hn;
}
else
{
cn=hn;

while(cn->next!=hn)
 cn=cn->next;

cn->next=nn;
nn->prev=cn;
nn->next=hn;
hn->prev=nn;
}
i++;
}while(i<=7);
j++;
c++;
}while(j<=10);
}

void display()
{
node *cn;
cn=hn;
cout<<"=================================================================\n";
cout<<"\033[1;33;49m  movie ticket booking system  \033[0m              \n";
cout<<"=================================================================\n";
cout<<"\n\n";
cout<<"------------------------------------------------------------------\n";
cout<<"|                            Platinum                            |\n";
while(cn->next!=hn)
{
if((cn->prev)->row_no!=cn->row_no)
cout<<"| ";
cout<<cn->row_no;
cout<<cn->seat_no;
if(cn->book=='a')
cout << "\033[32;40m -> a  \033[0m";  //green text with black background
else
cout << "\033[1;31;43m -> b  \033[0m";  //red text
if((cn->next)->row_no!=cn->row_no)
cout<<"|\n";
if(cn->row_no=='C'&&cn->seat_no==7)
{
cout<<"------------------------------------------------------------------\n";
cout<<"|                             gold                               |\n";
}
if(cn->row_no=='H'&&cn->seat_no==7)
{
cout<<"------------------------------------------------------------------\n";
cout<<"|                            Silver                              |\n";
}
cn=cn->next;
}
cout<<cn->row_no;
cout<<cn->seat_no;
if(cn->book=='a')
cout << "\033[32;40m -> a  \033[0m";  //green text with black background

else
cout << "\033[1;31;43m -> b  \033[0m";  //red text
cout<<"|\n";

cout<<"------------------------------------------------------------------\n\n";
cout<<"\033[1;33;49mPLATINUM-> 150              GOLD-> 100                  SILVER->60\033[0m\n";
}

void display1(node *tmp[20],int n)
{
if(n!=1)
{
cout<<"------------------------------------------------------------------\n";
cout<<"THANK YOU!\nYOU HAVE SUCCESFULLY BOOKED THE SEATS\n";
for(int i=1;i<n;i++)

cout<<tmp[i]->row_no<<tmp[i]->seat_no<<"    PIN : "<<tmp[i]->pin<<"\n";

cout<<"!!!!!!!!!!!!!!!!!!KEEP PIN SAFELY!!!!!!!!!!!!!!!!!!!\n";
cout<<"PINS ARE REQUIRED AT THE TIME OF CANCELATION OF SEATS\n";
cout<<"------------------------------------------------------------------\n";
}
}
void book_seat()
{
node *cn,*temp[20];
int n,z,flag;
char row;
int seat;
float time;
char ch;
do
{
z=1;
cout<<"\nEnter No Of Tickets u Want To Buy: ";
cin>>n;
cout<<"\n select the time of moive watching \n";
cin>>time;

cout<<"\nEnter Seat Number(s): \n";

for(int i=1;i<=n;i++)
{
cout<<"NO "<<i<<" = "; 
cin>>row>>seat;
cn=hn;
while(cn->next!=hn)
{
if(cn->row_no==row && cn->seat_no==seat)
{
if(cn->book=='a')
{
cn->book='b';
temp[z]=cn;
z++;
}
else
{
cout<<"INVALID CHOISE!\n";
cout<<cn->row_no<<cn->seat_no<<" Seat is alredy reserved \n";

}
}
cn=cn->next;
}
if(cn->row_no==row && cn->seat_no==seat)
{
if(cn->book=='a')
{
cn->book='b';
temp[z]=cn;
z++;
}
else
{
cout<<"INVALID CHOISE!\n";
cout<<cn->row_no<<cn->seat_no<<" Seat is alredy reserved\n";
}
}


}

display1(temp,z);
cout<<"\n\nPRESS 1 To check Seat Status\n";
cout<<"PRESS 2 To book other seat\n";
cout<<"PRESS 3 To Exit BOOKING PORTAL\n";
cout<<"\ninput: ";
cin>>ch;
if(ch==1)
display();
}while(ch=='2');
}

void cancle()
{
char row,ch;
int seat,pin;
node *cn;
do
{
ch='a';
cn=hn;
cout<<"SEAT NUMBRE :";
cin>>row>>seat;
cout<<"PIN :";
cin>>pin;
while(cn->next!=hn)
{
if(cn->row_no==row && cn->seat_no==seat && cn->pin==pin)
{
cout<<"Are you sure u want to cancle the Seat (y/n) ";
char c;
cin>>c;
if(c=='y'||c=='Y')
{
cout<<"SEAT CANCELED SUCCESFULLY!\n";
cn->book='a';
}
}
else if(cn->row_no==row && cn->seat_no==seat && cn->pin!=pin)
{
cout<<"invalid SEAT NUMBER && PIN combination!!!!\n";
}
cn=cn->next;
}
if(cn->row_no==row && cn->seat_no==seat && cn->pin==pin)
{
cout<<"Are you sure u want to cancle (y/n) ";
char c;
cin>>c;
if(c=='y'||c=='Y')
{
cout<<"SEAT CANCELED SUCCESFULLY!\n";
cn->book='a';
}
}
else if(cn->row_no==row && cn->seat_no==seat && cn->pin!=pin)
{
cout<<"invalid SEAT NUMBER && PIN combination!!!!\n";
}
cout<<"\n\nPRESS 1 To Check Seat Status\n"; 
cout<<"PRESS 2 To Cancle More Tickets\n";
cout<<"PRESS 3 To Exit CANCELATION PORTAL\n";
cout<<"\ninput: ";
cin>>ch;
if(ch==1)
display();
}while(ch=='2');
}
};
class Login
{

public:
void login()
{
    string uname,pass;
    int loginAttempt=0;

cout<<" \t @@@@@@@@ enter your login details @@@@@@@@@"<<endl;
//cout<<"if logging in as a guest,type guest as the user name."<<endl<<endl;
while(loginAttempt < 2)
{
  cout<<"enter the username:";
  cin>>uname;
  cout<<"enter the password:";
  cin>>pass;
  

  if((uname == "kajal") && (pass == "pooja"))
  {
    cout<<"login is successfully\t\n";
    cout<<"welcome kajal \n";
    break;
  
  }
  else if((uname =="pooja") && (pass == "kajal"))
  {
    cout <<"welcome pooja \t\n";
    break;
  }
  else
  {
    cout<<"invalid login attempt,please try again.\n "<< '\n';
    loginAttempt++;
  }
}
  if(loginAttempt == 2)
  {
    cout<<"too many login attempts! the program will now terminate.";
    exit (EXIT_FAILURE);
  }
  cout<<"thanks you for logging in.\n";
}
};

class Search_Movie
{
public:

void find() //find details
{
	struct book b;
	FILE *fp;
	
	char ch[20];
	printf("Enter movie code :");
	scanf("%s",ch);
	//system("clear");
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		while(getc(fp) != EOF)
		{
			fscanf(fp,"%s %s %s %d %s",b.code,b.name,b.date,&b.cost,b.type);
			if(strcmp(b.code,ch) == 0)
			{	
				//printf("%s / %s / %s / %d\n",b.code,b.name,b.date,b.cost);
				printf("\n Record Found\n");
				printf("\n\t\tCode ::%s",b.code);
				printf("\n\t\tmovie name ::%s",b.name);
				printf("\n\t\tmovie date ::%s",b.date);
				printf("\n\t\tprice of ticket ::%d",b.cost);
                                printf("\n\t\ttype of movie ::%s",b.type);
				break;
			}
		}
		
	}

	fclose(fp);
}
};

class functions:public Search_Movie
{
public:

 void insert_details()
{
	
	FILE *fp;
	struct book b;
	printf("Enetr movie code :- ");	
	scanf("%s",b.code);
	printf("Enetr  name :- ");	
	scanf("%s",b.name);
	printf("Enetr Relice Date:- ");	
	scanf("%s",b.date);
	printf("Enetr Ticket Price:- ");	
	scanf("%d",&b.cost);
	printf("enter the movie type:- ");
        scanf("%s",b.type);
	fp=fopen("data.txt","a");

	if(fp == NULL)
	{
		printf("FIle not Found");
	}
	else
	{
		fprintf(fp,"%s %s %s %d %s\n",b.code,b.name,b.date,b.cost,b.type);
		printf("Record insert Sucessfull");
	}
		printf("\n");
	fclose(fp);
}

void viewAll()
{
	char ch;
	FILE *fp;

	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{	
		system("clear");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
		
	}
	fclose(fp);
}
void cash()
{
 cout<<" the payment is submitted  in cash form";
 cout<<"thanks";
}

void card()
{
   char final;
   string name;
   int cardnumber,expirymm,expiryyy;
   cout<<"\n\n\t\t\t\t Do you have DTcard(y/n): ";
   cin>>final;

  /*(final=='y')
  {*/
    int cid;
    
    cout<<"\n\t\t\t\tEnter the card number[10 digits]: ";
    cin>>cid;			
    
     cout<<"\t\t\t\tName of the card holder: ";
     cin>>name;
     
     cout<<"\n\t\t\t\tEnter the card number: ";
     cin>>cardnumber;
     
     cout<<"\t\t\t\tExpiry(MM/YYYY)";
     
     cin>>expirymm;
     cout<<"\t\t\t\t/";
     cin>>expiryyy;
  
 			
}



 
void pay()
{
int ncommand1;
cout<<"please select the payment mode:"<<endl;
cout<<"[1] cash "<<endl;
cout<<"[2] card payment"<<endl;
cout<<endl;
cout<<"please select your choice:";
cin>>ncommand1;
switch(ncommand1)
{
case 1: cash();
        break;
case 2: card();
        break;
case 3:
        exit(3);
        break;
default:
        printf("Wrong choice !");
        break;

}

}
};

int main()
{
		
dcll o;
Login l;
int choice,ncommand;
char c;
cout<<"[1] login "<<endl;
cout<<"[2] exit application"<<endl;
cout<<endl;
cout<<"please select your choice:";
cin>>ncommand;
functions f;
switch(ncommand)
{
case 1: l.login();
        break;
case 2:
        exit(2);
        break;
default:
        printf("Wrong choice !");
        break;

}

cout<<"\n\n\n";
cout<<"                 @@@@@@   CITY PRIDE  @@@@@@\n";
cout<<"                vvvvvv ARRANGEMENT vvvvvv\n\n";
o.create();
o.display();

do
{
printf("\n====================================================================");
	printf("\n");	
	printf("\t \tMoive Ticket booking ");
	printf("\n");
	printf("\n====================================================================");
	
cout<<"\n\n\n";
cout<<"PRESS 1-> Book Tickets\n";
cout<<"PRESS 2-> Payment\n";
cout<<"PRESS 3-> Cancel Tickets\n";
//cout<<"PRESS 3-> EXIT\n";
//cout<<"\ninput: ";

printf("\nPRESS 4-> Insert Movie");
printf("\nPRESS 5-> View All Movie");
printf("\nPRESS 6-> Find Movie ");
printf("\nPRESS 0->Exit");
printf("\nEnter your Choice ::");
scanf("%d",&choice); 	

functions f;
//cin>>ch;
switch(choice)
{
case 1:
o.book_seat();

o.display();
break;
case 2:
f.pay();
break;
case 3:
o.cancle();
o.display();
break;
case 4 :
f.insert_details();
break;
case 5:
f.viewAll();
break;
    		
case 6:
f.find();
break;



case 0:
exit(0);
break;

default:
printf("Wrong choice !");
break;
}
//}while(choice!=0);

//}
if(choice!=6)
{
cout<<"\n\nPRESS 1 To Main Menu\n";
cout<<"PRESS 2 To Exit CINEMAX PORTAL\n";
cout<<"\ninput: ";
cin>>c;
}
}while(c=='1');
cout<<"\n\n\n";
	//functions f;
	 //int choice;
 	//do{
	
	
   	//switch (choice)
   	//{
    		
return 0;
}


