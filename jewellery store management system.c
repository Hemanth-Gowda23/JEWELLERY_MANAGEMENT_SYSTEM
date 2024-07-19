#include<windows.h>

#include<stdio.h>

#include<conio.h>

#include <stdlib.h>

#include<string.h>

#include<ctype.h>

#include<dos.h>

#include<time.h>



#define RETURNTIME 15



char catagories[][15]={"Rings","Ear Rings","Bracelet","Pendant","Chain","Jewelry Set"};

void returnfunc(void);

void mainmenu(void);

void additem(void);

void deleteitem(void);

void edititem(void);

void searchitem(void);

void viewitem(void);

void closeapplication(void);

void calculatebill(void);

int  getdata();

int  checkid(int);

int t(void);



void Password();

void issuerecord();

void loaderanim();





FILE *fp,*ft,*fs;





COORD coord = {0, 0};



int s;

char findstaff;

char password[10]={"pass"};


void gotoxy (int x, int y)

{

coord.X = x; coord.Y = y;

SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}



struct meroDate

{

int mm,dd,yy;

};

struct staff

{

int id;

char stname[20];

char name[20];

char Material[20];

int Quantity;

int count;

int weight;

int karat;

char *cat;

struct meroDate issued;

struct meroDate duedate;

};

struct staff a;

int main()

{

Password();

getch();

return 0;



}

void mainmenu()

{

system("cls");

int i;

gotoxy(20,3);

printf(" \t\tMAIN MENU \n ");

printf("\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");



gotoxy(20,5);

printf("<1> Add Jewellery Items   ");

gotoxy(20,7);

printf("<2> Remove Items");

gotoxy(20,9);

printf("<3> Search Items");

gotoxy(20,11);

printf("<4> View Item's List'");

gotoxy(20,13);

printf("<5> Edit Items");

gotoxy(20,15);

printf("<6> Calculate Bill");

gotoxy(20,17);

printf("<7> Close Application");

gotoxy(20,2);

t();

gotoxy(20,20);

printf("Enter your choice:");




switch(getch())

{

case '1':

additem();

break;

case '2':

deleteitem();

break;

case '3':

searchitem();

break;

case '4':

viewitem();

break;

case '5':

edititem();

break;

case '7':

{

system("cls");

gotoxy(16,3);

printf("\tJewelry Store Management System");

gotoxy(16,4);




exit(0);

}

case '6':
	calculatebill();
break;

default:

{

gotoxy(10,25);

printf("\aWrong Entry!!Please re-entered correct option");

if(getch())


mainmenu();

}



}

}

void additem(void)

{

system("cls");

int i;

gotoxy(20,5);

printf("SELECT CATEGOIES");

gotoxy(20,7);

printf("<1> Rings");

gotoxy(20,9);

printf("<2> Ear Rings");

gotoxy(20,11);

printf("<3> Bracelet");

gotoxy(20,13);

printf("<4> Pendant");

gotoxy(20,15);

printf("<5> Chain");

gotoxy(20,17);

printf("<6> Jewellery Set");

gotoxy(20,19);

printf("<7> Back to main menu");

gotoxy(20,21);



printf("Enter your choice:");

scanf("%d",&s);

if(s==7)



mainmenu() ;

system("cls");

fp=fopen("stf.dat","ab+");

if(getdata()==1)

{

a.cat=catagories[s-1];

fseek(fp,0,SEEK_END);

fwrite(&a,sizeof(a),1,fp);

fclose(fp);

gotoxy(21,14);

printf("The record is sucessfully saved");

gotoxy(21,15);

printf("Save any more?(Y / N):");

if(getch()=='n')

mainmenu();

else

system("cls");

additem();

}

}

void deleteitem()

{

system("cls");

int d;

char another='y';

while(another=='y')

{

system("cls");

gotoxy(10,5);

printf("Enter the Item Code to  delete:");

scanf("%d",&d);

fp=fopen("stf.dat","rb+");

rewind(fp);

while(fread(&a,sizeof(a),1,fp)==1)

{

if(a.id==d)

{



gotoxy(10,7);

printf("The Item is available");

gotoxy(10,8);

printf("Item's name is %s",a.name);

gotoxy(10,9);

findstaff='t';

}

}

if(findstaff!='t')

{

gotoxy(10,10);

printf("No record is found modify the search");

if(getch())

mainmenu();

}

if(findstaff=='t' )

{

gotoxy(10,9);

printf("Do you want to delete it?(Y/N):");

if(getch()=='y')

{

ft=fopen("test.dat","wb+");

rewind(fp);

while(fread(&a,sizeof(a),1,fp)==1)

{

if(a.id!=d)

{

fseek(ft,0,SEEK_CUR);

fwrite(&a,sizeof(a),1,ft);

}

}

fclose(ft);

fclose(fp);

remove("stf.dat");

rename("test.dat","stf.dat");

fp=fopen("stf.dat","rb+");

if(findstaff=='t')

{

gotoxy(10,10);

printf("The record is sucessfully deleted");

gotoxy(10,11);

printf("\n\tDelete another record?(Y/N)");

}

}

else

mainmenu();

fflush(stdin);

another=getch();

}

}

gotoxy(10,15);

mainmenu();

}

void searchitem()

{

system("cls");

int d;

printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2Search Item\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");


gotoxy(20,10);

printf("1. Search By Code");

gotoxy(20,14);

printf("2. Search By Name");

gotoxy( 15,20);

printf("Enter Your Choice");

fp=fopen("stf.dat","rb+");

rewind(fp);

switch(getch())

{

case '1':

{

system("cls");

gotoxy(25,4);

printf("\xB2\xB2\xB2\xB2\xB2\xB2Search Item By Code\xB2\xB2\xB2\xB2\xB2\xB2");

gotoxy(20,5);

printf("Enter the Item Code:");

scanf("%d",&d);

gotoxy(20,7);

while(fread(&a,sizeof(a),1,fp)==1)

{

if(a.id==d)

{

Sleep(2);

gotoxy(20,6);

printf("The Item is available\n");

gotoxy(20,8);

printf("Item Code:%d",a.id);

gotoxy(20,9);

printf("Category:%s",a.cat);

gotoxy(20,10);

printf("Name:%s",a.name);

gotoxy(20,11);

printf("Material:%s ",a.Material);

gotoxy(20,12);

printf("Quantity:%i ",a.Quantity);

gotoxy(20,13);

printf("Weight:%i",a.weight);

gotoxy(20,14);

printf("Karat:%i",a.karat);

gotoxy(20,d+15);

findstaff='t';

}



}

if(findstaff!='t')

{

printf("\aNo Record Found");

}

gotoxy(20,17);

printf("Try another search?(Y/N)");

if(getch()=='y')

searchitem();

else

mainmenu();

break;

}

case '2':

{

char s[15];

system("cls");

gotoxy(25,4);

printf("\xB2\xB2\xB2\xB2\xB2\xB2Search Item By Name\xB2\xB2\xB2\xB2\xB2\xB2");

gotoxy(20,5);

printf("Enter Item's Name:");

scanf("%s",s);

int d=0;

while(fread(&a,sizeof(a),1,fp)==1)

{

if(strcmp(a.name,(s))==0)

{

	gotoxy(20,d+7);

	//printf("The Staff is available");

	gotoxy(20,d+8);

	printf("Item Code:%d",a.id);

	gotoxy(20,d+10);

	printf("Name:%s",a.name);

	gotoxy(20,d+11);

	printf("Material:%s",a.Material);

	gotoxy(20,d+12);

	printf("Quantity:%i",a.Quantity);

	gotoxy(20,d+13);

    printf("Weight:%i",a.weight);

	gotoxy(20,d+14);

	printf("Karat:%i",a.karat);

	gotoxy(20,d+15);

	getch();

	d+=6;

}



}

if(d==0)



printf("\aNo Record Found");



gotoxy(20,d+11);

printf("Try another search?(Y/N)");

if(getch()=='y')

	searchitem();

else

	mainmenu();

break;

}

default :

getch();

searchitem();

}

fclose(fp);

}



void viewitem(void)

{

int i=0,j;

system("cls");

gotoxy(1,1);

printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2Item's List\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

gotoxy(2,2);

printf(" CATEGORY  ITEM CODE  ITEM NAME      MATERIAL    QUANTITY   WEIGHT RANGE  KARAT (K)");


j=4;

fp=fopen("stf.dat","rb");

while(fread(&a,sizeof(a),1,fp)==1)

{

gotoxy(3,j);

printf("%s",a.cat);

gotoxy(16,j);

printf("%d",a.id);

gotoxy(24,j);

printf("%s",a.name);

gotoxy(39,j);

printf("%s",a.Material);

gotoxy(51,j);

printf("%i",a.Quantity);

gotoxy(62,j);

printf("%i",a.weight);

gotoxy(76,j);

printf("%i",a.karat);

gotoxy(81,j);

printf("\n\n");

j++;

}

fclose(fp);

gotoxy(35,25);

returnfunc();

}

void edititem(void)

{

system("cls");

int c=0;

int d,e;

gotoxy(20,4);

printf("\xB2\xB2\xB2\xB2\xB2\xB2 Edit Items Section \xB2\xB2\xB2\xB2\xB2\xB2");

char another='y';

while(another=='y')

{

system("cls");

gotoxy(15,6);

printf("Enter Item's code to be edited:");

scanf("%d",&d);

fp=fopen("stf.dat","rb+");

while(fread(&a,sizeof(a),1,fp)==1)

{

if(checkid(d)==0)

{

gotoxy(15,7);

printf("The Item is availble");

gotoxy(15,8);

printf("The Item's Code:%d",a.id);

gotoxy(15,9);

printf("Enter new name:");

scanf("%s",a.name);

gotoxy(15,10);

printf("Enter new Material:");

scanf("%s",a.Material);

gotoxy(15,11);

printf("Enter new Quantity:");

scanf("%i",&a.Quantity);

gotoxy(15,12);

printf("Enter new Weight Range:");

scanf("%i",&a.weight);

gotoxy(15,13);

printf("Enter new Karat:");

scanf("%i",&a.karat);

gotoxy(15,14);

printf("The record is modified");

fseek(fp,ftell(fp)-sizeof(a),0);

fwrite(&a,sizeof(a),1,fp);

fclose(fp);

c=1;

}

if(c==0)

{

gotoxy(15,9);

printf("No record found");

}

}

gotoxy(15,16);

printf("Modify another Record?(Y/N)");

fflush(stdin);

another=getch() ;

}

returnfunc();

}

void returnfunc(void)

{

{

gotoxy(15,20);

printf("Press ENTER to return to main menu");

}

a:

if(getch()==13)

mainmenu();

else

goto a;

}

int getdata()

{

int t;

gotoxy(20,3);

printf("Enter the Information Below");

gotoxy(20,4);

printf("Category:");

gotoxy(31,5);

printf("%s",catagories[s-1]);

gotoxy(21,6);

printf("Item Code:\t");

gotoxy(31,6);

scanf("%d",&t);

if(checkid(t) == 0)

{

gotoxy(21,13);

printf("\aThe Item Code already exists\a");

getch();

mainmenu();

return 0;

}

a.id=t;

gotoxy(21,7);

printf("Item's Name:");

gotoxy(33,7);

scanf("%s",a.name);

gotoxy(21,8);

printf("Material:");

gotoxy(30,8);

scanf("%s",a.Material);

gotoxy(21,9);

printf("Quantity:");

gotoxy(31,9);

scanf("%i",&a.Quantity);

gotoxy(21,10);

printf("Weight Range:");

gotoxy(34,10);

scanf("%i",&a.weight);

gotoxy(21,11);

printf("Karat:");

gotoxy(27,11);

scanf("%i",&a.karat);

gotoxy(21,11);





return 1;

}

int checkid(int t)

{

rewind(fp);

while(fread(&a,sizeof(a),1,fp)==1)

if(a.id==t)

return 0;

return 1;

}

int t(void)

{

time_t t;

time(&t);

printf("Date and time:%s\n",ctime(&t));



return 0 ;

}



void Password(void)

{



system("cls");

char d[25]="Password Protected";

char ch,pass[10];

int i=0,j;





	printf("\t\t\t\t\tWELCOME\n\t\t\t\t\t  To \n\t\t   \xB2\xB2\xB2\xB2\xB2\xB2 Jewelry Store Management System \xB2\xB2\xB2\xB2\xB2\xB2\n");

	printf("\t \n\n\n Enter Password:");



while(ch!=13)

{

ch=getch();



if(ch!=13 && ch!=8){

putch('*');

pass[i] = ch;

i++;

}

}

pass[i] = '\0';

if(strcmp(pass,password)==0)

{

printf("\n\n\n\t\tPassword matched!!");

printf("\n\n\tPress any key to countinue.....");

getch();

mainmenu();

}

else

{

printf("\n\n\n\t\t\aWarning!! \n\t   Incorrect Password");

getch();

Password();

}

}

void calculatebill()
{
   int custid, wgh, chr, rte, dis;
   float chg, surchg=0, gramt,netamt;
   char connm[25];
   system("CLS");
   printf("================================================================");
   printf("\n");
   printf("\tEnter Customer ID :");
   scanf("%d",&custid);
   printf("\n");
   printf("\tEnter the Name of the Customer :");
   scanf("%s",connm);
   printf("\n");
   printf("\tEnter the Weight (In Gram) : ");
   scanf("%d",&wgh);
   printf("\n");
   printf("\tEnter Making Charges : ");
   scanf("%d",&chr);
   printf("\n");
   printf("\tEnter Current Gold/Silver  rate : ");
   scanf("%d",&rte);
   printf("\n");
   printf("\tDiscount Amount $: ");
   scanf("%d",&dis);
   printf("================================================================");

   printf("\n");
   printf("\t Press Enter To Display Total Bill of Mr/Mrs :%s",connm);
  getch();
  system("CLS");
   surchg = (rte*wgh)+chr-dis;
   netamt = surchg;

   printf("\n\t\t===============Jewelry Bill================\n");
   printf("\t\tCustomer IDNO                       :%d\n",custid);
   printf("\n");
   printf("\t\tCustomer Name                       :%s\n",connm);
   printf("\n");
   printf("\t\tTotal Weight                        :%d\n",wgh);
   printf("\n");
   printf("\t\tDiscount Amount                     :%d\n",dis);
   printf("\n");
   printf("\t\tSurchage Amount                     :%8.2f\n",surchg);
   printf("\n");
   printf("\t\tNet Amount Paid By the Customer     :%8.2f\n",netamt);
      printf("\t\t=============================================\n");

getch();
mainmenu();
}


