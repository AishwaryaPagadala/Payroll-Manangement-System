#include<stdio.h>
#include<conio.h>
struct employee
{
char name[20];
char idno[20];
char adrs[20];
char mn[20];
char dat[20];
char desg[20];
long int sa;
long int lo;
};
typedef struct employee NODE;
void write()
{
FILE *fp;
char ename[20];
char eid[20];
char eadrs[20];
char mno[20];
char date[20];
char designation[20];
long int sal;
long int loan;
NODE p;
printf("\n name of the employee(capital letters): ");
scanf("%s",&ename);
printf("\n id number:");
scanf("%s",&eid);
printf("\n address: ");
scanf("%s",&eadrs);
printf("\n mobile number: ");
scanf("%s",&mno);
printf("\n date of joining: ");
scanf("%s",&date);
printf("\n designation: ");
scanf("%s",&designation);
printf("\n basic salary: ");
scanf("%ld",&sal);
printf("\n loan: ");
scanf("%ld",&loan);
fp=fopen("employee.txt","a");
fprintf(fp,"\n %s %s %s %s %s %s %ld %ld",ename,eid,eadrs,mno,date,designation,sal,loan);
printf("\n written  successfully");
fclose(fp);

}

void display(char n[])
{
FILE *fp;
int r;
NODE p;
fp=fopen("employee.txt","r");
while(fscanf(fp,"%s %s %s %s %s %s %ld %ld \n",p.name,p.idno,p.adrs,p.mn,p.dat,p.desg,&p.sa,&p.lo)!=EOF)
{
r=strcmp(p.name,n);
if(r==0)
{
printf("\n employee name=%s",p.name);
printf("\n employee id number=%s",p.idno);
printf("\n employee address=%s",p.adrs);
printf("\n employee mobile number=%s",p.mn);
printf("\n date of joining=%s",p.dat);
printf("\n designation=%s",p.desg);
printf("\n basic salary=%ld",p.sa);
printf("\n loan=%ld",p.lo);
}
else
{
printf("\n not found");
}}
fclose(fp);
getch();
}

void display1(char idn[])
{
FILE *fp;
int r;
NODE p;
fp=fopen("employee.txt","r");
while(fscanf(fp,"%s %s %s %s %s %s %ld %ld \n",p.name,p.idno,p.adrs,p.mn,p.dat,p.desg,&p.sa,&p.lo)!=EOF)
{
r=strcmp(p.idno,idn);
if(r==0)
{
printf("\n employee name=%s",p.name);
printf("\n employee id number=%s",p.idno);
printf("\n employee address=%s",p.adrs);
printf("\n employee mobile number=%s",p.mn);
printf("\n date of joining=%s",p.dat);
printf("\n designation=%s",p.desg);
printf("\n basic salary=%ld",p.sa);
printf("\n loan=%ld",p.lo);
}
else
{
printf("\n not found");
}
}
fclose(fp);
getch();
}

void list()
{
FILE *fp;
NODE p;
fp=fopen("employee.txt","r");
fscanf(fp,"%s %s %s %s %s %s %ld %ld \n",p.name,p.idno,p.adrs,p.mn,p.dat,p.desg,&p.sa,&p.lo);
printf("\n %s %s %s %s %s %s %ld %ld",p.name,p.idno,p.adrs,p.mn,p.dat,p.desg,p.sa,p.lo);
fclose(fp);
getch();
}
void delete()
{
char z[20];
int r;
NODE p;
FILE *fp,*fp1;
fp=fopen("employee.txt","r");
fp1=fopen("emp.txt","a");
printf("\n enter id number of the employee to be deleted");
scanf("%s",&z);
rewind(fp);
while(!feof(fp))
{
fscanf(fp,"%s %s %s %s %s %s %ld %ld \n",p.name,p.idno,p.adrs,p.mn,p.dat,p.desg,&p.sa,&p.lo);
if(p.idno==z)
{
fprintf(fp1,"%s %s %s %s %s %s %ld %ld \n",p.name,p.idno,p.adrs,p.mn,p.dat,p.desg,p.sa,p.lo) ;
}
}
fclose(fp);
fclose(fp1);
remove("enp.txt");
rename("employee.txt","emp.txt ");
printf("\n deleted successfully");
getch();
}

void modify()
{
NODE p;
FILE *fp;
int n,d;
int c;
fp=fopen("employee.txt","r+");
printf("\n enter id number");
scanf("%s",n);
rewind(fp);
while(!feof(fp))
{
fscanf(fp,"%s %s %s %s %s %s %ld %ld",p.name,p.idno,p.adrs,p.mn,p.dat,p.desg,&p.sa,&p.lo);
d=strcmp(p.idno,n) ;
if(d==0)
{
printf("\n 1.modify name of an employee \n 2.modify address of an employee \n 3.modify mobile number of an employee \n 4.modify designation of an employee \n 5.modify salary of an employee \n 6.modify loan of an employee \n 7.exit \n");
printf("\n enter your choice: ");
scanf("%d",&c);
if(c==1)
{
printf("\n enter new name: ");
scanf("%s",&p.name);
}
if(c==2)
{
printf("\n enter new address:");
scanf("%s",&p.adrs);
}
if(c==3)
{
printf("\n enter new mobile number: ");
scanf("%s",&p.mn);
}
if(c==4)
{
printf("\n enter new designation: ");
scanf("%s",&p.desg);
}
if(c==5)
{
printf("\n enter new salary: ");
scanf("%ld",&p.sa);
}
if(c==6)
{
printf("\n enter new loan: ");
scanf("%ld",&p.lo);
}
if(c==7)
{
exit(0);
}
fseek(fp,sizeof(p),SEEK_SET);
fprintf(fp,"%s %s %s %s %s %s %ld %ld \n",p.name,p.idno,p.adrs,p.mn,p.desg,p.sa,p.lo);
}
}
fclose(fp);
printf("\n details modified successfully");
}


void main()
{
char ch,op,b;
char na[20];
char m[20];
do
{
clrscr();
printf("\t *** employee payroll system ***\n");
printf("\n 1.new employee \n  2.display employee \n 3.list of employees \n 4.edit menu \n 5.exit");
printf("\n\n enter choice");
scanf("%d",&ch);
switch(ch)
{
case 1:
write();
break;
case 2:
printf("\n 21.search by name \n 22.search by id number \n 23.exit");
printf("\n enter choice");
scanf("%d",&op);
switch(op)
{
case 21:
printf("\n enter name(capital letters):");
scanf("%s",&na);
display(na); break;
case 22:
printf("\n enter id number:");
scanf("%s",&m);
display1(m);
break;
case 23:
exit(0);
}
 break;
 case 3:
 list();
 break;
case 4:
printf("\n 41.delete record \n 42.modify record \n 43.exit");
printf("\n enter your choice");
scanf("%d",&b);
switch(b)
{
case 41:
delete();
break;
case 42:
modify();
break;
case 43:
exit(0);
}
break;
case 5:
exit(0) ;
}
getch();
}
while(1);
}