#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
void menu();
void search();
void cardetails();
void empdetails();
void salesdetails();
void addcar();
void updatecar();
void deletecar();
void viewcardetails();
void byname();
void byprice();
void viewall();
void addemployee();
void updateemployee();
void deleteemployee();
void viewemployeedetails();
void ownername();
void address();
void ph_no();
void range();
void customersale();
void viewsalesdetails();
void updatesale();
void salesearch();
void bycustomername();
void bycarmodel();
int check(int);
void cname();
void password();
void blank();
void name();
int phcheckpt1(char []);
int phcheckpt(char []);
void delsale();
int pricecheck(double,double);
int nmcheck(char []);
int checknumber(double);
int checkmodel(char []);

char choice;
struct date d;

//---------CAR ATTRIBUTES---------------------

struct car
{
int sno;
char model[30];
long mileage;
long fcap;
char pst[20];
double price;
}car;

//----------EMPLOYEE ATTRIBUTES----------------

struct employee
{
int id;
char name[30];
char address[50];
char phno[11];
char post[20];
double salary;
}emp,emp2,emp3;


//-----------SALES ATTRIBUTES------------------

struct sales
{
char sname[30];
int sno;
char name[30];
char address[50];
char phno[11];
char model[30];
double price;
}sale1,sale2,sale3;


//--------------------------------MENU()----------------------------------


void menu()
{
char choice;
clrscr();
gotoxy(26,6);printf("WELCOME TO VOLKSWAGEN DAS AUTO\n");
gotoxy(26,7);printf("------------------------------\n");
gotoxy(35,9);printf("MAIN MENU");
gotoxy(26,11);printf("1.Search");
gotoxy(26,13);printf("2.Car Details");
gotoxy(26,15);printf("3.Employee Details");
gotoxy(26,17);printf("4.Sales Details");
gotoxy(26,19);printf("5.Exit");
gotoxy(26,21);printf("Enter Your Choice:-.....");
fflush(stdin);
scanf("%c",&choice);
switch(choice)
{
case '1':
search();
break;
case '2':
cardetails();
break;
case '3':
empdetails();
break;
case '4':
salesdetails();
break;
case '5':
blank();
break;
default:
gotoxy(25,23);printf("Plz Select The Best Option From The Choices Provided");
getch();
}
menu();
}


//------------------SEARCH()-------------------


void search()
{
char choice;
clrscr();
gotoxy(26,5);printf("Search Car Menu");
gotoxy(26,6);printf("---------------");
gotoxy(26,8);printf("1.By Name");
gotoxy(26,10);printf("2.By Price");
gotoxy(26,12);printf("3.View All");
gotoxy(26,14);printf("4.Back To Main Menu");
gotoxy(26,16);printf("Please Enter Your Choice:-.....");
fflush(stdin);
scanf("%c",&choice);
switch(choice)
{
case '1':
byname();
break;
case '2':
byprice();
break;
case '3':
viewall();
break;
case '4':
menu();
break;
default:
gotoxy(25,18);printf("Plz Select The Best Option From The Choices Provided");
getch();
}
search();
}

//-----------------nmchech()------------------------

int nmcheck(char p[])
{
int i,c=0;
for(i=0;p[i]!='\0';i++)
{
if((p[i]>=65 && p[i]<=90) || (p[i]>=97 && p[i]<=122) || (p[i]==32))
{
}
else
c++;
}
if(c==0)
return 0;
return 1;
}

//-----------------BY NAME()-------------------

void byname()
{
FILE *p;
char m[20];
int res2=0,res1=0;
fflush(stdin);
x:
clrscr();
fflush(stdin);
gotoxy(12,7);printf("Please Choose The Vehicle You Are Intrested In :-> ");
fflush(stdin);
gets(m);

res2=nmcheck(m);
if(res2==1)
{
gotoxy(12,9);printf("Plz Enter Only Alphabhets...");
getch();
goto x;
}

res1=checkmodel(m);
if(res1==0)
{
gotoxy(12,9);printf("We're Sorry The Vehicle You Have Chosen Is Not In The List!");
getch();
gotoxy(12,11);printf("Do You Want To Re-Entered Your Vehicle Again (Y/N):--- ");
fflush(stdin);
choice=getchar();
if(choice=='Y' || choice=='y')
{
clrscr();
byname();
}
else if(choice=='N' || choice=='n')
{
gotoxy(20,17);printf("--:Going Back to Search Menu:--");
gotoxy(20,19);printf("--:Please Press Enter Button To Go Back:--");
getch();
search();
}
else
gotoxy(20,23);printf("Sorry Wrong Choice.Please Kindly Enter Again...");
getch();
byname();
}

clrscr();
gotoxy(33,4);printf("[ RESULT FOUND ]");
gotoxy(33,5);printf("******** *******\n\n");
textcolor(YELLOW);
p=fopen("car.dat","rb+");
fflush(stdin);
while(fread(&car,sizeof(car),1,p)==1)
{
if(strcmp(m,car.model)==0)
{
printf("\n");
printf("SLNO               :-- %d\n",car.sno);
printf("MODEL              :-- %s\n",car.model);
printf("MILEAGE            :-- %ld\n",car.mileage);
printf("FUEL TANK CAPACITY :-- %ld\n",car.fcap);
printf("POWER STEERING     :-- %s\n",car.pst);
printf("PRICE              :-- %lf\n",car.price);
getch();
}
}
fclose(p);
getch();
search();
}

int checkmodel(char p[])
{
FILE *fcar;
fcar=fopen("car.dat","rb+");
fflush(stdin);
while(fread(&car,sizeof(car),1,fcar)==1)
{
if(strcmp(p,car.model)==0)
{
fclose(fcar);
return 1;
}
}
fclose(fcar);
return 0;
}

//--------------BY PRICE()-----------------


void byprice()
{
double min=0,max=0,res=0;
FILE *p;
clrscr();
fflush(stdin);
clrscr();
gotoxy(12,7);printf("Enter Min Range:--");
scanf("%lf",&min);
gotoxy(12,9);printf("Enter Max range:--");
scanf("%lf",&max);
res=pricecheck(min,max);
if(res==0)
{
gotoxy(12,11);printf("Sorry No match Found At this Range...");
getch();
search();
}


textcolor(YELLOW);
p=fopen("car.dat","rb+");
fflush(stdin);clrscr();
gotoxy(32,4);printf("YOUR SEARCH RESULT:-");
gotoxy(32,5);printf("**** ****** ******");

while(fread(&car,sizeof(car),1,p)==1)
{
if(car.price>=min && car.price<=max)
{
printf("\n");
printf("SLNO		:--%d\n",car.sno);
printf("MODEL		:--%s\n",car.model);
printf("MILEAGE		:--%ld\n",car.mileage);
printf("FUEL CAPACITY	:--%ld\n",car.fcap);
printf("POWER STEERING	:--%s\n",car.pst);
printf("PRICE		:--%lf\n",car.price);
getch();
}
}
getch();
search();
}


//--------------------price check()-------------------------

int pricecheck(double x, double y)
{
FILE *fp;
fp=fopen("car.dat","rb+");
fflush(stdin);
while(fread(&car,sizeof(car),1,fp)==1)
{
if(car.price>=x && car.price<=y)
{
fclose(fp);
return 1;
}
}
fclose(fp);
return 0;
}

//-----------------VIEW ALL()-----------------


void viewall()
{
FILE *p;
clrscr();
textcolor(YELLOW);
p=fopen("car.dat","rb+");
fflush(stdin);
clrscr();
gotoxy(32,5);printf("( LISTS OF THE MODELS )\n");
gotoxy(32,6);printf("******* ** *** ********\n");
while(fread(&car,sizeof(car),1,p)==1)
{
printf("\n");
printf("SLNO                :-- %d.\n",car.sno);
printf("MODEL               :-- %s\n",car.model);
printf("MILEAGE             :-- %ld\n",car.mileage);
printf("FUEL TANK CAPACITY  :-- %ld\n",car.fcap);
printf("POWER STEERING      :-- %s\n",car.pst);
printf("PRICE               :-- %f\n",car.price);
getch();
}
fclose(p);
getch();
search();
}


//-----------------CAR DETAILS()---------------------


void cardetails()
{
char choice;
clrscr();
gotoxy(26,6);printf("Car Details\n");
gotoxy(26,7);printf("------------\n");
gotoxy(26,9);printf("1.Add Car\n");
gotoxy(26,11);printf("2.Update Car\n");
gotoxy(26,13);printf("3.Delete Car\n");
gotoxy(26,15);printf("4.View Car Details\n");
gotoxy(26,17);printf("5.Back To Main Menu\n");
gotoxy(26,19);printf("Please Enter Your Choice:-....");
fflush(stdin);
scanf("%c",&choice);
switch(choice)
{
case '1':
addcar();
break;
case '2':
updatecar();
break;
case '3':
deletecar();
break;
case '4':
viewcardetails();
break;
case '5':
menu();
break;
default:
gotoxy(25,21);printf("Plz Select The Best Option From The Choices Provided");
getch();
}
cardetails();
}


//-----------------ADD CAR()----------------------


void addcar()
{
FILE *p;
int res,res1=0,res2=0,sno;
char op,choice;
clrscr();
p=fopen("car.dat","ab+");
gotoxy(15,5);printf("ADD CAR HERE...........");
fflush(stdin);
gotoxy(15,9);printf("Enter Serial No              :- ");
scanf("%d",&sno);
res=check(sno);
if(res==0)
{
car.sno=sno;

m:
fflush(stdin);
gotoxy(15,11);printf("Enter Model Name             :- ");
gets(car.model);
res1=nmcheck(car.model);
if(res1==1)
{
gotoxy(47,11);
clreol();
gotoxy(15,12);printf("Plz Enter Only Alphabhets...");
getch();
gotoxy(15,12);
clreol();
goto m;
}




fflush(stdin);
gotoxy(15,13);printf("Enter Mileage                :- ");
scanf("%ld",&car.mileage);

fflush(stdin);
gotoxy(15,15);printf("Enter Fuel Tank Capacity     :- ");
scanf("%ld",&car.fcap);

p:
fflush(stdin);
gotoxy(15,17);printf("Enter Powersteering (Yes/No) :- ");
gets(car.pst);
res2=nmcheck(car.pst);
if(res2==1)
{
gotoxy(47,17);
clreol();
gotoxy(15,18);printf("Plz Enter Only Alphabhets...");
getch();
gotoxy(15,18);
clreol();
goto p;
}



fflush(stdin);
gotoxy(15,19);printf("Enter Price (Rs.)            :- ");
scanf("%lf",&car.price);
fwrite(&car,sizeof(car),1,p);
fclose(p);
gotoxy(15,21);printf("--:One record Succesfully Added:--\n");
getch();
gotoxy(15,23);printf("Do You want to add More Records (Y/N):-- ");
fflush(stdin);
op=getchar();
if(op=='y'|| op=='Y')
{
clrscr();
addcar();
}
}
else
{
gotoxy(15,11);printf("-:This Serial No Is Already Exists:-");
getch();
gotoxy(15,13);printf("Do U Want To Re-Entered The Sl.No Again (Y/N):--- ");
fflush(stdin);
choice=getchar();
if(choice=='Y' || choice=='y')
{
clrscr();
addcar();
}
cardetails();
getch();
}
}

int check(int sno)
{
char op;
FILE *p;
p=fopen("car.dat","rb+");
rewind(p);
while(fread(&car,sizeof(car),1,p)==1)
{
if(sno==car.sno)
return 1;
}
return 0;
}

//----------------UPDATE CAR()-----------------


void updatecar()
{
int sno,res=0,res1=0,res2=0;
FILE *p;
char choice;
long size=sizeof(car);
clrscr();
gotoxy(15,3);printf("UPDATE CAR HERE........");
gotoxy(15,9);printf("Please Enter The Sl.No Of The Car To Be Updated:--- ");
fflush(stdin);
scanf("%d",&sno);
res=check(sno);
if(res==0)
{
gotoxy(15,13);printf("Sorry The Sl.No You Entered Is NoT In The LisTs!");
getch();
gotoxy(15,15);printf("Do U Want To Re-Entered The Sl.No Again (Y/N):--- ");
fflush(stdin);
choice=getchar();
if(choice=='Y' || choice=='y')
{
clrscr();
updatecar();
}
cardetails();
}

p=fopen("car.dat","rb+");
fflush(stdin);
while(fread(&car,sizeof(car),1,p)==1)
{
fflush(stdin);
if(car.sno==sno)
{
car.sno=sno;
m:
fflush(stdin);
gotoxy(15,11);printf("Enter New Model                 :- ");
gets(car.model);
res1=nmcheck(car.model);
if(res1==1)
{
gotoxy(50,11);
clreol();
gotoxy(15,12);printf("Plz Enter Only Alphabhets...");
getch();
gotoxy(15,12);
clreol();
goto m;
}


fflush(stdin);
gotoxy(15,13);printf("Enter New Mileage               :- ");
scanf("%ld",&car.mileage);

fflush(stdin);
gotoxy(15,15);printf("Enter New Fuel Tank Capacity    :- ");
scanf("%ld",&car.fcap);

p:
fflush(stdin);
gotoxy(15,17);printf("Enter New Powersteering(Yes/No) :- ");
gets(car.pst);
res2=nmcheck(car.pst);
if(res2==1)
{
gotoxy(50,17);
clreol();
gotoxy(15,18);printf("Plz Enter Only Alphabhets...");
getch();
gotoxy(15,18);
clreol();
goto p;
}


fflush(stdin);
gotoxy(15,19);printf("Enter New Price (Rs.)           :- ");
scanf("%lf",&car.price);

fflush(stdin);
fseek(p,-size,1);
fwrite(&car,sizeof(car),1,p);
}
}
fclose(p);
gotoxy(15,21);printf("[---One Succefully Upated---]");
getch();
cardetails();
}


//-----------DELETE CAR()----------------

void deletecar()
{
int sno,res;
char choice,op;
FILE *p1,*p2;
clrscr();
gotoxy(15,3);printf("DELETE CAR HERE...........\n");
gotoxy(15,9);printf("Please Enter The Sl.No Of The Car To Be Deleted:--- ");
scanf("%d",&sno);
res=check(sno);
if(res==0)
{
gotoxy(15,13);printf("Sorry The Sl.No You Entered Is NoT In The Lists!");
getch();
gotoxy(15,15);printf("Do U Want To Re-Entered The Sl.No Again (Y/N):--- ");
fflush(stdin);
op=getchar();
if(op=='Y' || op=='y')
{
clrscr();
deletecar();
}
cardetails();
}

p1=fopen("car.dat","rb+");
rewind(p1);
p2=fopen("temp.dat","wb+");
while(fread(&car,sizeof(car),1,p1)==1)
{
if(car.sno!=sno)
fwrite(&car,sizeof(car),1,p2);
}
fclose(p1);
fclose(p2);
remove("car.dat");
rename("temp.dat","car.dat");
gotoxy(15,11);printf("Record Succefully Deleted\n");
gotoxy(15,13);printf("Delete Another Record (Y/N):--- ");
fflush(stdin);
choice=getchar();
if(choice=='Y'|| choice=='y')
{
clrscr();
deletecar();
}
cardetails();
}

//------------VIEW CAR DETAILS()--------------


void viewcardetails()
{
FILE *p;
clrscr();
textcolor(YELLOW);
p=fopen("car.dat","rb+");
fflush(stdin);clrscr();
gotoxy(32,4);printf("( LISTS OF THE MODELS )");
gotoxy(32,5);printf("******* ** *** ********");
while(fread(&car,sizeof(car),1,p)==1)
{
fflush(stdin);
printf("\n");
printf("SLNO               :-- %d\n",car.sno);
printf("MODEL              :-- %s\n",car.model);
printf("MILEAGE            :-- %ld\n",car.mileage);
printf("FUEL TANK CAPACITY :-- %ld\n",car.fcap);
printf("POWER STEERING     :-- %s\n",car.pst);
printf("PRICE (Rs.)        :-- %lf\n",car.price);
getch();
}
fclose(p);
getch();
{
cardetails();
}
}

//--------------EMPLOYEE DETAILS()------------------

void empdetails()
{
char choice;
clrscr();
gotoxy(26,6);printf("Employee Details\n");
gotoxy(26,7);printf("----------------\n");
gotoxy(26,9);printf("1.Add Employee\n");
gotoxy(26,11);printf("2.Update Employee\n");
gotoxy(26,13);printf("3.Delete Employee\n");
gotoxy(26,15);printf("4.View Employee Details\n");
gotoxy(26,17);printf("5.Back To Main Menu\n");
gotoxy(26,19);printf("Please Enter Your Choice:-.....");
fflush(stdin);
scanf("%c",&choice);
switch(choice)
{
case '1':
addemployee();
break;
case '2':
updateemployee();
break;
case '3':
deleteemployee();
break;
case '4':
viewemployeedetails();
break;
case '5':
menu();
break;
default:
gotoxy(25,21);printf("Plz Select The Best Option From The Choices Provided");
getch();
}
empdetails();
}

//----------------ADD EMPLOYEE()------------------

void addemployee()
{
FILE *p;
int res,id,res1,res2,res3=0,res4=0,res5=0;
char op;
clrscr();
p=fopen("emp.dat","ab+");
gotoxy(15,6);printf("ADD OF EMPLOYEE DONE HERE.....");
fflush(stdin);
gotoxy(15,9);printf("Enter Id No             :- ");
scanf("%d",&id);
res=empcheck(id);
if(res==0)
{
emp.id=id;

n:
fflush(stdin);
gotoxy(15,11);printf("Enter Employee name     :- ");
gets(emp.name);
res3=nmcheck(emp.name);
if(res3==1)
{
gotoxy(42,11);
clreol();
gotoxy(15,12);printf("Plz Enter Only Alphabhets...");
getch();
gotoxy(15,12);
clreol();
goto n;
}

ad:
fflush(stdin);
gotoxy(15,13);printf("Enter Employee Address  :- ");
gets(emp.address);
res4=nmcheck(emp.address);
if(res4==1)
{
gotoxy(42,13);
clreol();
gotoxy(15,14);printf("Plz Enter Only Alphabhets...");
getch();
gotoxy(15,14);
clreol();
goto ad;
}


fflush(stdin);
no:
gotoxy(15,15);printf("Enter Employee Phone No :- ");
gets(emp.phno);

res1=phcheckpt(emp.phno);
if(res1==1)
{
gotoxy(42,15);
clreol();
gotoxy(15,16);printf("Enter Numbers Only..");
getch();
gotoxy(15,16);
clreol();
goto no;
}

res2=phcheckpt1(emp.phno);
if(res2==1)
{
gotoxy(42,15);
clreol();
gotoxy(15,17);printf("Enter Within 10 Digit..");
getch();
gotoxy(15,17);
clreol();
goto no;
}

p:
fflush(stdin);
gotoxy(15,17);printf("Enter Employee Post     :- ");
gets(emp.post);
res5=nmcheck(emp.post);
if(res5==1)
{
gotoxy(42,17);
clreol();
gotoxy(15,18);printf("Plz Enter Only Alphabhets...");
getch();
gotoxy(15,18);
clreol();
goto p;
}


fflush(stdin);
gotoxy(15,19);printf("Enter Employee Salery   :- ");
scanf("%lf",&emp.salary);

fflush(stdin);
fwrite(&emp,sizeof(emp),1,p);
fclose(p);
gotoxy(15,21);printf("--:One Record Succesfully Added:--\n");
getch();
gotoxy(15,23);printf("Do You Want To Add More Records (Y/N):--- ");
fflush(stdin);
op=getchar();
if(op=='y'|| op=='Y')
{
clrscr();
addemployee();
}
}
else
{
gotoxy(15,11);printf("-:This Id.No Is Already Exists:-");
getch();
gotoxy(15,13);printf("Do U Want To Re-Entered The ID.No Again (Y/N):--- ");
fflush(stdin);
choice=getchar();
if(choice=='Y' || choice=='y')
{
clrscr();
addemployee();
}
empdetails();
}
}


int phcheckpt(char p[])
{
int i,c=0;
for(i=0;p[i]!='\0';i++)
{
if(p[i]>=48 && p[i]<=57)
{
}
else
c++;
}
if(c==0)
return 0;
return 1;
}

int phcheckpt1(char ph[])
{
int len=0;
len=strlen(ph);
if(len<10 || len>10)
return 1;
return 0;
}


int empcheck(int id)
{
char op;
FILE *p;
p=fopen("emp.dat","rb+");
rewind(p);
while(fread(&emp2,sizeof(emp2),1,p)==1)
{
if(id==emp2.id)
return 1;
}
fclose(p);
return 0;

}



//---------------UPDATE EMPLOYEE()---------------


void updateemployee()
{
int id,res;
FILE *p1;
char choice;
int res1,res2,res3=0,res4=0,res5=0;
long size=sizeof(emp);
clrscr();
gotoxy(15,3);printf("Update Employee Here..........");
gotoxy(15,9);printf("Please Enter Id Of The Employee To Be Updated:-- ");
fflush(stdin);
scanf("%d",&id);
res=empcheck(id);
if(res==0)
{
gotoxy(15,13);printf("Sorry The Id.No You Entered Is NoT In The LisTs!");
getch();
gotoxy(15,15);printf("Do You Want To Re-Entered The Id.No Again (Y/N):--- ");
fflush(stdin);
choice=getchar();
if(choice=='Y' || choice=='y')
{
clrscr();
updateemployee();
}
empdetails();
}

p1=fopen("emp.dat","rb+");
fflush(stdin);
while(fread(&emp,sizeof(emp),1,p1)==1)
{
if(emp.id==id)
{
emp.id=id;
clrscr();

n:
fflush(stdin);
gotoxy(20,7);printf("Enter New Employee Name     :- ");
gets(emp.name);
res3=nmcheck(emp.name);
if(res3==1)
{
gotoxy(51,7);
clreol();
gotoxy(20,8);printf("Plz Enter Only Alphabhets...");
getch();
gotoxy(20,8);
clreol();
goto n;
}


ad:
fflush(stdin);
gotoxy(20,9);printf("Enter New Address           :- ");
gets(emp.address);
res4=nmcheck(emp.address);
if(res4==1)
{
gotoxy(51,9);
clreol();
gotoxy(20,10);printf("Plz Enter Only Alphabhets...");
getch();
gotoxy(20,10);
clreol();
goto ad;
}


fflush(stdin);
no:
gotoxy(20,11);printf("Enter New Phone No          :- ");
gets(emp.phno);
res1=phcheckpt(emp.phno);
if(res1==1)
{
gotoxy(51,11);
clreol();
gotoxy(20,12);printf("Enter Numbers Only..");
getch();
gotoxy(20,12);
clreol();
goto no;
}


res2=phcheckpt1(emp.phno);
if(res2==1)
{
gotoxy(51,11);
clreol();
gotoxy(20,13);printf("Enter Within 10 Digit..");
getch();
gotoxy(20,13);
clreol();
goto no;
}

p:
fflush(stdin);
gotoxy(20,13);printf("Enter New Employee Post     :- ");
gets(emp.post);
res5=nmcheck(emp.post);
if(res5==1)
{
gotoxy(51,13);
clreol();
gotoxy(20,15);printf("Plz Enter Only Alphabhets...");
getch();
gotoxy(20,15);
clreol();
goto p;
}

fflush(stdin);
gotoxy(20,15);printf("Enter New Employee Salery   :- ");
scanf("%lf",&emp.salary);

fflush(stdin);
fseek(p1,-size,1);
fwrite(&emp,sizeof(emp),1,p1);
}
}
fclose(p1);
gotoxy(20,18);printf("-:One Record successfully Updated:-");
getch();
empdetails();
}


//-------------DELETE EMPLOYEE()----------------


void deleteemployee()
{
int id,res;
char ch,choice;
FILE *fp1,*fp2;
clrscr();
gotoxy(15,3);printf("DELETE EMPLOYEE RECORDS HERE..........\n");
gotoxy(15,9);printf("Please Enter Id Of The Employee To Be Deleted:--- ");
scanf("%d",&id);
res=empcheck(id);
if(res==0)
{
gotoxy(15,13);printf("SorrY The Id.No You Entered Is Not In The Lists!");
getch();
gotoxy(15,15);printf("Do You Want To Re-Entered The Id.No Again (Y/N):--- ");
fflush(stdin);
choice=getchar();
if(choice=='Y' || choice=='y')
{
clrscr();
deleteemployee();
}
empdetails();
}

fp1=fopen("emp.dat","rb+");
rewind(fp1);
fp2=fopen("tmp.dat","wb+");
while(fread(&emp,sizeof(emp),1,fp1)==1)
{
if(emp.id!=id)
fwrite(&emp,sizeof(emp),1,fp2);
}
fclose(fp1);
fclose(fp2);
remove("emp.dat");
rename("tmp.dat","emp.dat");
gotoxy(20,13);printf("Record Succefully Deleted\n");
gotoxy(20,15);printf("Delete Another Record(Y/N):--- ");
fflush(stdin);
ch=getchar();
if(ch=='Y'|| ch=='y')
{
clrscr();
deleteemployee();
}
empdetails();
}

//-------------VIEW EMPLOYEE DETAILS()-------------

void viewemployeedetails()
{
FILE *p;
clrscr();
textcolor(YELLOW);
p=fopen("emp.dat","rb+");
fflush(stdin);clrscr();
gotoxy(30,4);printf("( LISTS OF THE EMPLOYER )");
gotoxy(30,5);printf("******* ** *** **********");
fflush(stdin);
while(fread(&emp,sizeof(emp),1,p)==1)
{
printf("\n");
printf("ID NO                     :-- %d\n",emp.id);
printf("NAME                      :-- %s\n",emp.name);
printf("RESIDENTIAL ADDRESS       :-- %s\n",emp.address);
printf("POSITION TITLE            :-- %s\n",emp.post);
printf("PHONO NO (+91)            :-- %s\n",emp.phno);
printf("SALERY (Rs.)              :-- %lf\n",emp.salary);
getch();

}
fclose(p);
getch();
{
empdetails();
}
}

//--------------SALES DETAILS()----------------


void salesdetails()
{
char ch;
clrscr();
gotoxy(26,6);printf(" Sales Details");
gotoxy(26,7);printf(".................");
gotoxy(26,9);printf("1. Customer Sale");
gotoxy(26,11);printf("2. View Sales Details");
gotoxy(26,13);printf("3. Update Sale");
gotoxy(26,15);printf("4. Sale Search");
gotoxy(26,17);printf("5. Delete Sale");
gotoxy(26,19);printf("6. Back To Main Menu");
gotoxy(26,21);printf("Enter Your Choice:-....");
fflush(stdin);
scanf("%c",&ch);
switch(ch)
{
case '1':
customersale();
break;
case '2':
viewsalesdetails();
break;
case '3':
updatesale();
break;
case '4':
salesearch();
break;
case '5':
delsale();
break;
case '6':
menu();
break;
default:
gotoxy(25,23);printf("Plz Select The Best Option From The Choices Provided");
getch();
}
salesdetails();
}


//---------------CUSTOMER SALES()---------------

void customersale()
{
char op;
int res1,res2,res3,res4=0,res5=0,res6=0;
FILE *fp2;
clrscr();
fp2=fopen("sale.dat","ab+");
strcpy(sale1.sname,"VolksWagen Das Auto");
fflush(stdin);gotoxy(15,9);printf("Enter Serial No :-....");
scanf("%d",&sale1.sno);
res3=salescheck(sale1.sno);
if(res3==1)
{
gotoxy(15,11);printf("This Slno. already exists");
getch();
clrscr();
salesdetails();
}
o:
fflush(stdin);gotoxy(15,11);printf("Enter Owner Name:-....");
gets(sale1.name);
res4=nmcheck(sale1.name);
if(res4==1)
{
gotoxy(37,11);
clreol();
gotoxy(15,12);printf("Plz Enter Only Alphabhets...");
getch();
gotoxy(15,12);
clreol();
goto o;
}

a:
fflush(stdin);gotoxy(15,13);printf("Enter Address   :-....");
gets(sale1.address);
res5=nmcheck(sale1.address);
if(res5==1)
{
gotoxy(37,13);
clreol();
gotoxy(15,14);printf("Plz Enter Only Alphabhets...");
getch();
gotoxy(15,14);
clreol();
goto a;
}



no:
fflush(stdin);gotoxy(15,15);printf("Enter Ph.no.    :-....");
gets(sale1.phno);
res1=phcheckpt(sale1.phno);
if(res1==1)
{
gotoxy(37,15);
clreol();
gotoxy(15,17);printf("Enter Numbers only..");
getch();
gotoxy(15,17);
clreol();
goto no;
}
res2=phcheckpt1(sale1.phno);
if(res2==1)
{
gotoxy(37,15);
clreol();
gotoxy(15,18);printf("Enter within 10 digit..");
getch();
gotoxy(15,18);
clreol();
goto no;
}
mdel:
fflush(stdin);gotoxy(15,17);printf("Enter Model     :-....");
gets(sale1.model);
res6=nmcheck(sale1.model);
if(res6==1)
{
gotoxy(37,17);
clreol();
gotoxy(15,18);printf("Plz Enter Only Alphabhets...");
getch();
gotoxy(15,18);
clreol();
goto mdel;
}

fflush(stdin);gotoxy(15,19);printf("Enter Price     :-....");
scanf("%lf",&sale1.price);
fwrite(&sale1,sizeof(sale1),1,fp2);
fclose(fp2);
gotoxy(15,21);printf("one record succesfully added");
gotoxy(15,23);printf("Do You want to add More Records (y/n)");
getch();
fflush(stdin);
scanf("%c",&op);
if(op=='y'|| op=='Y')
{
clrscr();
customersale();
}
salesdetails();
}

//------------salescheck()-----------------

int salescheck(int id)
{
char op;
FILE *p;
p=fopen("sale.dat","rb+");
rewind(p);
while(fread(&sale2,sizeof(sale2),1,p)==1)
{
if(id==sale2.sno)
return 1;
}
fclose(p);
return 0;

}


//-----------------DELETE SALES()-----------------

void delsale()
{
int sl,res;
char ch;
FILE *fp1,*fp2;
clrscr();
gotoxy(20,11);printf("Please Enter Serial No Of Sale..--");
scanf("%d",&sl);
res=salescheck(sl);
if(res==1)
{
fp1=fopen("sale.dat","rb+");
rewind(fp1);
fp2=fopen("tmp.dat","wb+");
while(fread(&sale3,sizeof(sale3),1,fp1)==1)
{
if(sale3.sno!=sl)
fwrite(&sale3,sizeof(sale3),1,fp2);
}
fclose(fp1);
fclose(fp2);
remove("sale.dat");
rename("tmp.dat","sale.dat");
gotoxy(20,13);printf("Record succefully deleted\n");
gotoxy(20,15);printf("Delete another record:---(Y/N)");
fflush(stdin);
ch=getchar();
if(ch=='Y'|| ch=='y')
{
clrscr();
delsale();
}
}
else
{
gotoxy(20,13);printf("Sl.No. Doesn't Exists");
getch();
}
salesdetails();
}

//----------------VIEW SALES DETAILS()-------------------

void viewsalesdetails()
{
char sno;
FILE *fp;
clrscr();
textcolor(YELLOW);
fp=fopen("sale.dat","rb+");
fflush(stdin);
while(fread(&sale2,sizeof(sale2),1,fp)==1)
{
printf("\n");
printf("ShowRoom Name:-%s\n\n",sale2.sname);
printf("Sl.No	     :-%d\n\n",sale2.sno);
printf("Cust Name    :-%s\n\n",sale2.name);
printf("Cust Address :-%s\n\n",sale2.address);
printf("Cust PhoneNO :-%s\n\n",sale2.phno);
printf("Car.model    :-%s\n\n",sale2.model);
printf("Car.price    :-%lf\n\n",sale2.price);
getch();
}
fclose(fp);
getch();
salesdetails();
}

//------------UPDATE SALE()--------------


void updatesale()
{
int sno,count=0,res1,res2,res3=0,res4=0,res5=0;
FILE *fp;
long size=sizeof(sale3);
clrscr();
gotoxy(20,2);printf("Please Enter sl.no Updated:-");
scanf("%d",&sno);
fp=fopen("sale.dat","rb+");
while(fread(&sale3,sizeof(sale3),1,fp)==1)
{
if(sale3.sno==sno)
{
count++;
sale3.sno=sno;

n:
gotoxy(20,5);
fflush(stdin);
printf("Enter new owner name:-");
gets(sale3.name);
res3=nmcheck(sale3.name);
if(res3==1)
{
gotoxy(42,5);
clreol();
gotoxy(20,6);printf("Plz Enter Only Alphabhets...");
getch();
gotoxy(20,6);
clreol();
goto n;
}


add:
gotoxy(20,7);
fflush(stdin);
printf("Enter new address:-");
gets(sale3.address);
res4=nmcheck(sale3.address);
if(res4==1)
{
gotoxy(39,7);
clreol();
gotoxy(20,8);printf("Plz Enter Only Alphabhets...");
getch();
gotoxy(20,8);
clreol();
goto add;
}



no:
fflush(stdin);
gotoxy(20,9);printf("Enter new phone no:-");
gets(sale3.phno);
res1=phcheckpt(sale3.phno);
if(res1==1)
{
gotoxy(40,9);
clreol();
gotoxy(20,11);printf("Enter Numbers Only..");
getch();
gotoxy(20,11);
clreol();
goto no;
}

res2=phcheckpt1(sale3.phno);
if(res2==1)
{
gotoxy(40,9);
clreol();
gotoxy(20,11);printf("Enter within 10 digit..");
getch();
gotoxy(20,11);
clreol();
goto no;
}

mod:
gotoxy(20,11);
fflush(stdin);
printf("Enter new model:-");
gets(sale3.model);
res5=nmcheck(sale3.model);
if(res5==1)
{
gotoxy(37,11);
clreol();
gotoxy(20,12);printf("Plz Enter Only Alphabhets...");
getch();
gotoxy(20,12);
clreol();
goto mod;
}


gotoxy(20,13);
fflush(stdin);
printf("Enter new price:-");
scanf("%lf",&sale3.price);
fseek(fp,-size,1);
fwrite(&sale3,sizeof(sale3),1,fp);
fclose(fp);
gotoxy(20,15);printf("One Record Successfully Update");
getch();
}
}
if(count==0)
{
gotoxy(20,4);printf("SlNo. Doesn't Exists");
getch();
}
salesdetails();
}


//----------------SALES SEARCH()-----------------


void salesearch()
{
char choice;
clrscr();
gotoxy(26,5);printf("Sales Search");
gotoxy(26,6);printf("------------");
gotoxy(26,8);printf("1.By Customer Name");
gotoxy(26,10);printf("2.By Car model");
gotoxy(26,12);printf("3.Back To Previous Menu");
gotoxy(26,14);printf("Please Enter Your Choice:-.....");
fflush(stdin);
scanf("%c",&choice);
switch(choice)
{
case '1':
bycustomername();
break;
case '2':
bycarmodel();
break;
case '3':
salesdetails();
break;
default:
gotoxy(25,16);printf("Plz Select The Best Option From The Choices Provided");
getch();
}
salesearch();
}

//----------BY CUSTOMER NAME()-----------

void  bycustomername()
{
FILE *fp;
char name[30];
int count=1,res1=0;
cust:
clrscr();
fflush(stdin);
gotoxy(15,6);printf("Enter Customer Name:--");
gets(name);
res1=nmcheck(name);
if(res1==1)
{
gotoxy(37,6);
clreol();
gotoxy(15,7);printf("Plz Enter Only Alphabhets...");
getch();
gotoxy(15,7);
clreol();
goto cust;
}

fp=fopen("sale.dat","rb+");
fflush(stdin);
clrscr();
printf("\nYour search result\n");
gotoxy(1,5);printf("S.No");
gotoxy(9,5);printf("Name");
gotoxy(16,5);printf("Address");
gotoxy(27,5);printf("Phno");
gotoxy(41,5);printf("Model");
gotoxy(52,5);printf("Price");
while(fread(&sale1,sizeof(sale1),1,fp)==1)
{
if(strcmp(name,sale1.name)==0)
{
printf("\n");
printf("%d.\t",count);
printf("%s\t",sale1.name);
printf("%s\t",sale1.address);
printf("%s\t",sale1.phno);
printf("%s\t",sale1.model);
printf("%lf\t",sale1.price);
count++;
}
}
fclose(fp);
getch();
}

//----------BY CAR MODEL()------------

void bycarmodel()
{
FILE *fp;
char model[30];
int count=1,c=0,res1=0;
fflush(stdin);

cm:
clrscr();
gotoxy(10,6);printf("Enter Car Model:---");
gets(model);
res1=nmcheck(model);
if(res1==1)
{
gotoxy(29,6);
clreol();
gotoxy(10,7);printf("Plz Enter Only Alphabhets...");
getch();
gotoxy(10,7);
clreol();
goto cm;
}


clrscr();
textcolor(YELLOW);
fp=fopen("sale.dat","rb+");
fflush(stdin);
printf("Your Search Result");
gotoxy(1,5);printf("S.No");
gotoxy(9,5);printf("Name");
gotoxy(16,5);printf("Address");
gotoxy(27,5);printf("Phno");
gotoxy(41,5);printf("Model");
gotoxy(52,5);printf("Price");
while(fread(&sale1,sizeof(sale1),1,fp)==1)
{
if(strcmp(model,sale1.model)==0)
{
c++;
printf("\n\n");
printf("%d.\t",count);
printf("%s\t",sale1.name);
printf("%s\t",sale1.address);
printf("%s\t",sale1.phno);
printf("%s\t",sale1.model);
printf("%lf\t",sale1.price);
count++;
}
}
if(c==0)
{
gotoxy(1,8);printf("Name doesn't exists");
getch();
salesearch();
}
fclose(fp);
getch();
salesearch();
}

//------------COMPUTER DATE()-------------

void cdate()
{
int day,month,year;
getdate(&d);
day=d.da_day;
month=d.da_mon;
year=d.da_year;
gotoxy(70,1);printf("%d-%d-%d",day,month,year);
}

//-------------------NAME()------------------------

void name()
{
clrscr();
cdate();
gotoxy(23,5);printf("DEVELOPED AND DESIGNED BY");
gotoxy(22,6);printf("_____________________________");
gotoxy(20,10);printf("NAME       :-- BIBEK NANDI");
gotoxy(20,12);printf("FROM       :-- School Of Computer Application,");
gotoxy(20,13);printf("               Kiit University,Bhubaneswar,Odisha.");
gotoxy(20,15);printf("DEPARTMENT :-- M.C.A (L.E)");
gotoxy(20,17);printf("ROLL NO    :-- 1739072");
gotoxy(20,19);printf("YEAR       :-- 2017-2019");

getch();
password();
}

//-------------PASSWORD()---------------

void password()
{
char pass[3]="111",etr[3],option31;
int i,c=0;
clrscr();
cdate();
textcolor(YELLOW);
gotoxy(25,7);printf("LOG IN");
gotoxy(25,8);printf("______");
gotoxy(25,10);printf("USERNAME:- ADMINISTRATOR");
gotoxy(25,12);printf("PASSWORD:- ");
for(i=0;i<3;i++)
{
etr[i]=getch();
printf("*");
}
for(i=0;i<3;i++)
{
if(etr[i]==pass[i])
c++;
}
getch();
gotoxy(25,15);printf("-: Password Matched :-");
if(c==3)
{
getch();
menu();
}
else
{
gotoxy(20,15);printf("Oops! Password did not match! Try Again.");
getch();
gotoxy(20,18);printf("Do You Want To Re enter The Password(Y/N):-");
fflush(stdin);
scanf("%c",&option31);
if(option31=='Y' || option31=='y'/* || option31==15*/)
{
password();
}

else if(option31=='N' || option31=='n')
{
gotoxy(20,20);printf("Existing From The Screen...");
gotoxy(20,22);printf("PLease Press '#Enter_Button' To Close It....");
getch();
exit(0);
}

else
gotoxy(20,23);printf("Sorry Wrong Choice.Please Kindly Enter Again...");
getch();
password();
}
}

//-----------------------BLANK()------------------
void blank()
{
char option31;
clrscr();
textcolor(YELLOW);
gotoxy(18,10);printf("Do You Want To Go Back Again To The Login Page.");
gotoxy(20,12);printf("Tpye (Y / N)----> ");
fflush(stdin);
scanf("%c",&option31);
if(option31=='Y' || option31=='y'/* || option31==15*/)
{
password();
}

else if(option31=='N' || option31=='n')
{
gotoxy(20,17);printf("So You Selected No");
gotoxy(20,19);printf("Now We Are Existing From The Screen");
gotoxy(20,21);printf("Please Press '#Enter_Button' To Close It...");
getch();
exit(0);
}

else
gotoxy(20,23);printf("Sorry Wrong Choice.Please Kindly Enter Again...");
getch();
blank();
}





//------------------------MAIN()----------------------------


void main()
{
textcolor(YELLOW);
clrscr();
gotoxy(24,5);printf("WELCOME TO VOLKSWAGEN DAS AUTO");
gotoxy(10,6);printf("------------------------------------------------------------");
gotoxy(10,12);printf("Address:");
gotoxy(20,12);printf("Bharat Motors Ltd, Nh-5,Pahal,");
gotoxy(20,14);printf("S-3/61,Mancheswar Industrial Estate");
gotoxy(20,16);printf("Bhubaneswar,Odisha-752101");
gotoxy(20,18);printf("Phone: 08599011454");
gotoxy(20,20);printf("Founded In :-- 2017 --:");
getch();
name();
}


/*--------------------------THE END-------------------------*/
