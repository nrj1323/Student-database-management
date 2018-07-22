#include<fstream.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include<stdio.h>
class lib
{
char name[20];
int clas,rollno;
public:
void get()
{
cout<<"\nEnter the details of the student:"<<endl;
cout<<"enter the name:"<<endl;
gets(name);
cout<<"enter the class:"<<endl;
cin>>clas;
cout<<"enter the rollno:"<<endl;
cin>>rollno;
}
void show()
{
textcolor(5);
cprintf("Name - ");cout<<name<<endl;
cprintf("Class - ");cout<<clas<<endl;
cprintf("Roll no - ");cout<<rollno<<endl<<endl;
}
int grollno()
{
return rollno;
}
char* gname()
{
return(name);
}
int gclas()
{
return clas;
}
};
void ADD()
{
fstream t;
t.open("Record.txt",ios::app);
lib s;
char ch='y';
while(ch=='y'||ch=='Y')
{
s.get();
t.write((char*)&s,sizeof(lib));
cout<<"do you want to add more(y/n)....: "<<endl;
cin>>ch;
}
}
void SHOW()
{
fstream t;
t.open("Record.txt",ios::in);
lib s;
if(!t.read((char*)&s,sizeof(lib)))
{
cout<<"\nThere is no Record in the database\n\n";
delay(1500);
return;
}
else
{
char ch;
t.seekg(0);
textcolor(4);
cout<<endl<<endl;
cprintf( " **!!!*** RECORDS **!!!***: ");
cout<<endl<<endl;
while(t.read((char*)&s,sizeof(lib)))
{
s.show();
delay(1500);
}
getch();
}
}
void SEARCH()
{
fstream t;
t.open("Record.txt",ios::in);
lib s;
t.seekg(0);
int res=0;
int ch;
cout<<"\n 1:Search by Name ";
cout<<"\n 2:Search by Class";
cout<<"\n 3:Search by Roll No\n";
cout<<"\n Your choice ";
cin>>ch;
if(ch==1)
{
char name[30];
cout<<"\nEnter the Name ";
gets(name);
cout<<"\nSearching .......please wait......."<<endl;
delay(1000);
while(t.read((char*)&s,sizeof(lib)))
{
if((strcmpi(name,s.gname()))==0)
{
res=1;
cout<<"\nRecord found !!!\n";
delay(1000);
s.show();
getch();
}
}
}
else if(ch==2)
{
int clas;
cout<<"\nEneter the Class ";
cin>>clas;
cout<<"\nSearching......please wait .........\n";
delay(1000);
while(t.read((char*)&s,sizeof(lib)))
{
if(clas==s.gclas())
{
res=1;
cout<<"\nRecord found !!!\n" ;
delay(1000);
s.show();
getch();
}
}
}
else
{
int rolno;
cout<<"\nEnter the Roll No. ";
cin>>rolno;
cout<<"\nSearching........please wait.....\n";
delay(1000);
while(t.read((char*)&s,sizeof(lib)))
{
if(rolno==s.grollno())
{
res=1;
cout<<"\nRecord found !!!\n";
delay(1000);
s.show();
getch();
}
}
}
if(res==0)
cout<<"\nRecord NOT found \n";
delay(1000);
}
void UPDATE()
{
int pos;
fstream t;
t.open("Record.txt",ios::in|ios::out);
lib s;
t.seekg(0);
int res=0;
int ch;
cout<<"\nSelect the wrong Record by";
cout<<"\n1:By Name \n2:By Class \n3:By Roll No\n\n";
cout<<" Your Choice ";
cin>>ch;
if(ch==1)
{
char name[30];
cout<<"\nEnter the wrong name ";
gets(name);
while(t.read((char*)&s,sizeof(lib)))
{
if(!(strcmpi(name,s.gname())))
{
res=1;
cout<<"\nEnter the Modified Record ";
s.get();
t.seekg(t.tellg() - sizeof(lib));
t.write((char*)&s,sizeof(lib));
cout<<"\nRecord Updated\n";
delay(1500);
}
}
}
else if(ch==2)
{
int clas;
cout<<"\nEneter the Class ";
cin>>clas;
cout<<"\nSearching......please wait .........\n";
delay(1000);
while(t.read((char*)&s,sizeof(lib)))
{
if(clas==s.gclas())
{
res=1;
cout<<"\nEnter the modified Record";
s.get();
t.seekg(t.tellg() - sizeof(lib));
t.write((char*)&s,sizeof(lib));
cout<<"\nRecord Updated\n";
delay(1500);
}
}
}
else
{
int rolno;
cout<<"\nEnter the Roll No. ";
cin>>rolno;
cout<<"\nSearching........please wait.....\n";
delay(1000);
while(t.read((char*)&s,sizeof(lib)))
{
if(rolno==s.grollno())
{
res=1;
cout<<"\nEnter the modified Record ";
s.get();
t.seekg(t.tellg() - sizeof(lib));
t.write((char*)&s,sizeof(lib));
cout<<"\nRecord Updated\n";
delay(1500);
}
}
}
if(res==0)
cout<<"\nRecord does NOT exist";
delay(1500);
}
void DELETE()
{
fstream t;
t.open("Record.txt",ios::in);
lib s;
t.seekg(0);
fstream m;
m.open("New.txt",ios::out);
int res=0;
int ch;
cout<<"\nSelect the Record to be deleted ";
cout<<"\n1:By Name \n2:By Class \n3:By Roll No\n\n";
cout<<"Your Choice ";
cin>>ch;
if(ch==1)
{
char name[30];
cout<<"\nEnter the name ";
gets(name);
while(t.read((char*)&s,sizeof(lib)))
{
if(!(strcmpi(name,s.gname())))
{
res=1;
cout<<"\n Record DELETED !! \n";
delay(1500);
}
else
{
m.write((char*)&s,sizeof(lib));
}
}
}
else if(ch==2)
{
int clas;
cout<<"\nEneter the Class ";
cin>>clas;
cout<<"\nSearching......please wait .........\n";
delay(1000);
while(t.read((char*)&s,sizeof(lib)))
{
if(clas==s.gclas())
{
res=1;
cout<<"\n Record DELETED !! \n";
delay(1500);
}
else
{
m.write((char*)&s,sizeof(lib));
}
}
}
else
{
int rolno;
cout<<"\nEnter the Roll No.";
cin>>rolno;
cout<<"\nSearching........please wait.....\n";
delay(1000);
while(t.read((char*)&s,sizeof(lib)))
{
if(rolno==s.grollno())
{
res=1;
cout<<"\n Record DELETED !! \n";
delay(1500);
}
else
{
m.write((char*)&s,sizeof(lib));
}
}
}
if(res==0)
{
cout<<"\nRecord does not exist ";
delay(1500);
}
if(res==1)
{
t.close();
m.close();
remove("Record.txt");
rename("New.txt","Record.txt");
}
}
void main()
{
clrscr();
int x;
char pass[30];
textcolor(1);
cout<<"\n";cprintf(" ***************************************************************************");
textcolor(4);
cout<<"\n";cprintf(" ***************************************************************************");
textcolor(1);
cout<<"\n";cprintf(" * ii ii I i iiiiii ii iiiiiiii iiiiiiii iiiiiiiiiiii iiiiii *");
cout<<"\n";cprintf(" * ii ii ii ii ii ii ii ii ii ii ii ii ii *");
cout<<"\n";cprintf(" * ii ii ii ii ii ii ii ii ii ii ii ii *");
cout<<"\n";cprintf(" * ii ii ii iiiiii ii ii ii ii ii ii ii iiiiii *");
cout<<"\n";cprintf(" * ii ii ii ii ii ii ii ii ii ii ii ii *");
cout<<"\n";cprintf(" * ii ii ii ii ii ii ii ii ii ii ii ii ii *");
cout<<"\n";cprintf(" * iiiiiiiiiiii iiiiii iiiiiii iiiiiiii iiiiiiii ii ii ii iiiiii *");
textcolor(4);
cout<<"\n";cprintf(" ***************************************************************************");
textcolor(1);
cout<<"\n";cprintf(" ***************************************************************************");
cout<<endl<<endl;
textcolor(5);
cprintf(" T H E S T U D E N T D A T A M A N A G E M A E N T ");
cout<<"\n\n\n\n\n\n Enter the Password please ";
gets(pass);
if(strcmp(pass,"123")==0)
{
while(1)
{
clrscr();
textcolor(1);
cout<<"\n";cprintf(" *************************************************");
textcolor(4);
cout<<"\n";cprintf(" *************************************************");
textcolor(1);
cout<<"\n";cprintf(" * Enter your choice: *");
cout<<"\n";cprintf(" * [1] TO ADD: *");
cout<<"\n";cprintf(" * [2] TO SHOW: *");
cout<<"\n";cprintf(" * [3] TO SEARCH: *");
cout<<"\n";cprintf(" * [4] TO MODIFY: *");
cout<<"\n";cprintf(" * [5] TO DELETE: *");
cout<<"\n";cprintf(" * [6] TO EXIT: *");
textcolor(4);
cout<<"\n";cprintf(" *************************************************");
textcolor(1);
cout<<"\n";cprintf(" *************************************************");
cout<<endl<<endl;
cout<<"Your Choice ";
cin>>x;
if(x==1)
{
ADD();
}
else if(x==2)
{
SHOW();
}
else if(x==3)
{
SEARCH();
}
else if(x==4)
{
UPDATE();
}
else if(x==5)
{
DELETE();
}
else
{
clrscr();
textcolor(2);
cout<<"\n"; cprintf("iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii");
cout<<"\n"; cprintf("*****************************************************************************");
textcolor(4);
cout<<"\n"; cprintf("_____________________________________________________________________________");
cout<<"\n"; cprintf("_____________________________________________________________________________");
textcolor(2);
cout<<"\n"; cprintf(" IIIIIIII II  II IIIIIII II    II II II   II  II  II IIIIII II  II");
cout<<"\n"; cprintf(" 	II     II  II II   II III   II II II  II   II  II II  II II  II");
cout<<"\n"; cprintf(" 	II     II  II II   II IIII  II II II II     I  I  II  II II  II");
cout<<"\n"; cprintf(" 	II     IIIIII IIIIIII II II II II IIII       II   II  II II  II");
cout<<"\n"; cprintf(" 	II     II  II II   II II  IIII II II II      II   II  II II  II");
cout<<"\n"; cprintf(" 	II     II  II II   II II   III II II  II     II   II  II II  II");
cout<<"\n"; cprintf(" 	II     II  II II   II II    II II II   II    II   IIIIII IIIIII");
textcolor(4);
cout<<"\n"; cprintf("_____________________________________________________________________________");
cout<<"\n"; cprintf("_____________________________________________________________________________");
textcolor(2);
cout<<"\n"; cprintf("*****************************************************************************");
cout<<"\n"; cprintf("iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii");
textcolor(5);
cout<<"\n\n\n\n\n\n\n ";
cout<<"\n"; cprintf("\nA PROJECT BY ");
cout<<"\n"; cprintf("\nNeeraj Kumar");
break;
}
}
}
else
{
textcolor(4);
cout<<"\n"; cprintf("\n\n I N V A L I D U S E R !!!!!!");
cout<<"\n"; cprintf(" wrong password");
}
}
