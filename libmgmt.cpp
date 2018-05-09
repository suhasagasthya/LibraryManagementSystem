#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<stdlib.h>
#include<iomanip.h>
#include<time.h>
#include<ctype.h>
#include<process.h>
#include<stdio.h>

 class lib
 {
    protected:
        char name[25][25];
        char wn[25][25];
        char code[25][15];
        char copy[25][15];

 };

 class fn:public lib
 {
        int z;
    public:
        fn()
        {
            z=0;
        }
        void add_(void);
        void delete_(void);
        void plus_(void);
        void display_(void);
        void srch();
        void details();
        void borrow();
        void returnbook();
        void display_borrow();
 };

 class student
{
	public: char name[20], usn[11], branch[20], email[30];
		int year,libid;
		void getdata()
		{
			cout<<"Enter the name of the student\n";
			gets(name);
			cout<<"Enter the USN of the student\n";
			gets(usn);
			cout<<"Enter the year the student is studying in\n";
			cin>>year;
			cout<<"Enter the branch the student belongs to\n";
			gets(branch);
			cout<<"Enter the library ID card number for the new student\n";
			cin>>libid;
			cout<<"Enter the email id of the student\n";
			gets(email);
		}
		void putdata()
		{
		    cout<<"Name: "<<name<<" USN: "<<usn<<" Lib ID: "<<libid<<endl;
		}
		void displaydata()
		{
		    cout<<"Name : "<<name<<endl;
		    cout<<"USN : "<<usn<<endl;
		    cout<<"Library Card Number : "<<libid<<endl;
		    cout<<"Email : "<<email<<endl;
		    cout<<endl<<endl;
		}
	int retid()
	{
	    return libid;
	}
	void writerec();
	void deleterec();
	void displayprofile();
};
void student::writerec()
{
   student a;
   char ch;
   clrscr();
   fstream out("student.dat",ios::binary|ios::in|ios::app);
    do
    {
      a.getdata();
      out.seekg(0);
      out.write((char*)&a,sizeof(a));
      cout<<"Do you want to enter another record?\n";
      cin>>ch;
   }while(toupper(ch)=='Y');
   out.close();
}
void student::deleterec()
{
    student s1;
    clrscr();
    ifstream fio("student.dat",ios::in|ios::binary);
    ofstream file("temp3.dat",ios::out|ios::app|ios::binary);
    int rno; char found='f',confirm='n';
    cout<<"Enter the Library ID no of student whose record is to be deleted: \n";
    cin>>rno;
    while(fio.read((char*)&s1,sizeof(s1)))
    {
    if(s1.retid()==rno)
    {
	 s1.putdata();
	 found='t';
	 cout<<"Are you sure want to delete this record(y/n) \n";
	 cin>>confirm;
	 if(toupper(confirm)=='N')// if confirm is y then record is not written
	 file.write((char*)&s1,sizeof(s1));
    }
    else
	 file.write((char*)&s1,sizeof(s1));
    }
    if(found=='f')
    cout<<"Record not found!\n";
    fio.close();
    file.close();
    remove("student.dat");
    rename("temp3.dat","student.dat");
}

 void fn :: add_(void)         //To add a new book
 {
    int m,n,k;

    clrscr();

    fstream f1;
    f1.open("book1.txt",ios::out|ios::app);

    cout<<"\n\nEnter the book name   :";
    cin>>name[z];
    cout<<"Enter writter name    :";
    cin>>wn[z];
    cout<<"Enter the book code   :";
    cin>>code[z];
    cout<<"Enter the no. of copy :";
    cin>>copy[z];

    int i;

    m=strlen(name[z]);
    n=strlen(wn[z]);
    k=strlen(code[z]);

    f1.seekg(0,ios::end);
    f1<<endl;

    f1<<name[z];
    for(i=0;i<26-m;i++)
    f1<<"\ ";
    f1 <<wn[z];
    for(i=0;i<22-n;i++)
    f1<<"\ ";
    f1 <<code[z];
    for(i=0;i<17-k;i++)
    f1<<"\ ";
    f1 <<copy[z];
    f1.close();

    z++;
 }
 void fn :: delete_(void)         //To delete a copy of book from list
 {
    int i;

    clrscr();

    cout<<"\nPlease enter the book code:";
    cin>>i;

    fstream f2;
    f2.open("book1.txt",ios::in|ios::out|ios::nocreate);

    f2.seekg(0);

    char b[20],r[20];
    int m,n,o;
    char *l;

    while(f2.eof()==0)
    {
        f2>>b;
        f2>>r;
        f2>>m;
        f2>>l;

        n=atoi(l);
        o=strlen(l);

        if(m==i)
        {
            f2.seekg(-o,ios::cur);

            if (n>0)
            {
                n--;
                f2<<n;
                cout<<"\nOne copy of this book is deleted from list.";
                getch();
                break;
            }
            else
            {
                cout<<"Not available copy.";
                break;
            }
        }
    }
    f2.close();
 }

 void fn :: plus_(void)           //To add a copy of book to list
 {
    int j;

    clrscr();

    cout<<"\nPlease enter the book code:";
    cin>>j;

    fstream f6;
    f6.open("book1.txt",ios::in|ios::out|ios::nocreate);

    f6.seekg(0);

    char c[30];
    int e,r,t;
    char *p;

    while(f6.eof()==0)
    {
        f6>>c;
        f6>>c;
        f6>>r;
        f6>>p;

        e=atoi(p);
        t=strlen(p);

        if(r==j)
        {
            f6.seekg(-t,ios::cur);

            if(e>=0)
             {
                e++;
                f6<<e;
                cout<<"\nOne copy of this book is added to list.";
                getch();
                break;
              }
            else
              {
                cout<<"Invalid book code.";
                break;
              }
        }
    }

    f6.close();

 }

 void fn :: display_(void)          //To show the book list
 {
    clrscr();

    fstream f3;
    f3.open("book1.txt",ios::in|ios::app);
    f3.seekg(0);

    char a;

    cout<<"\n\n";
    cout<<"\t*************** BOOK LIST ***************";
    cout<<"\n\n";
    cout<<"Bookname"<<setw(25)<<"Writter"<<setw(18)<<"Code"<<setw(17)<<"No Of Copies"<<endl;
    cout<<"--------"<<setw(25)<<"-------"<<setw(18)<<"----"<<setw(17)<<"------------"<<endl;

    while(f3)
    {
        f3.get(a);
        cout<<a;
    }
    f3.close();
    getch();
 }

 void fn :: srch ()          //To search a book with its code from list
 {
    int i,j,k=0;

    clrscr();

    cout<<"\nPlease enter the Book code: ";
    cin>>j;

    fstream f4;
    f4.open("book1.txt",ios::in|ios::app);
    f4.seekg(0);

    char c[20],d[20];
    int n,p;

    while(f4.eof()==0)
    {
        f4>>c;
        f4>>d;
        f4>>n;
        f4>>p;

        if(n==j)
        {
            cout<<"  Book name      : "<<c<<endl;
            cout<<"  Writter name   : "<<d<<endl;
            cout<<"  Book code      : "<<n<<endl;
            cout<<"  Available copy : "<<p<<endl<<endl;
            getch();
            k++;
        }
        if(k==1)
            break;
    }

 }

void fn::details()             //Displays details by taking libcard number
{
    char n[25],b[25],d[9],a[25],e[25],f[10],g[10],h[10];
    int libnum,j,l,flag=0;

    clrscr();

    cout<<"Enter the Library Card Number: ";
    cin>>libnum;

    fstream f5;
    f5.open("details.txt",ios::in|ios::app);
    f5.seekg(0);

    while(f5>>n>>l>>b>>a>>d>>e>>f>>g>>h)
    {


	if(l==libnum)
        {
            flag=1;
            cout<<"  Student name    : "<<n<<endl;
            cout<<"  Card Number     : "<<l<<endl;
            cout<<"  Book Name       : "<<b<<endl;
            cout<<"  Author          : "<<a<<endl;
            cout<<"  Due Date        : "<<d<<" "<<e<<" "<<f<<" "<<g<<" "<<h<<endl<<endl;
            getch();
        }
    }
    if(flag==0)
    {
        cout<<"Not Found\n";
        getch();
    }
    f5.close();
}


void fn::borrow()       //borrow a book
{
    char name[25],b[25],a[25];
    int libnum,n,o,i;
    int flag=0,flag1=0;
    char duedate,*c;
    float bcs,bcode;
    time_t current;
    time(&current);

    struct tm* ptr=localtime(&current);
    ptr->tm_mday+=15;
    time_t next=mktime(ptr);


    clrscr();

    cout<<"Enter Student Name : "<<endl;
    cin>>name;
    cout<<"Enter Library Card Number : "<<endl;
    cin>>libnum;
    cout<<"Enter the Book Code : "<<endl;
    cin>>bcode;

    fstream data("student.dat",ios::in|ios::out|ios::binary);
    student s4;

    fstream f6;
    f6.open("book1.txt",ios::in|ios::out|ios::nocreate);
    f6.seekg(0);

    while(data.read((char*)&s4,sizeof(s4)))
    {
    if(s4.retid()==libnum)
    {
    flag=1;

     while(f6.eof()==0)
    {
        f6>>b;
        f6>>a;
        f6>>bcs;
        f6>>c;

        n=atoi(c);
        o=strlen(c);

        if(bcs==bcode)
        {
            flag1=1;
            f6.seekg(-o,ios::cur);

            if (n>0)
            {
                n--;
                f6<<n;
                cout<<"\nOne copy of this book issued from the list.";
                fstream f7;
                f7.open("borrow.txt",ios::out|ios::app);     //Write Data to borrow list


                f7.seekg(0);
                f7<<name;
                for(i=0;i<5;i++)
                f7<<"\ ";
                f7 <<b;
                for(i=0;i<5;i++)
                f7<<"\ ";
                f7 <<a;
                for(i=0;i<5;i++)
                f7<<"\ ";
                f7<<libnum;
                for(i=0;i<5;i++)
                f7<<"\ ";
                f7<<bcode;
                for(i=0;i<5;i++)
                f7<<"\ ";
                f7<<ctime(&current);
                f7.close();


                f7.open("details.txt",ios::in|ios::app);      //Write data to profile details
                f7.seekg(0);
                f7<<name;
                for(i=0;i<5;i++)
                f7<<"\ ";
                f7<<libnum;
                for(i=0;i<5;i++)
                f7<<"\ ";
                f7<<b;
                for(i=0;i<5;i++)
                f7<<"\ ";
                f7<<a;
                for(i=0;i<5;i++)
                f7<<"\ ";
                f7<<ctime(&next);
                f7.close();

                getch();
                break;
	    }
	    else
	    {
		cout<<"Book Copy Not Avaiable"<<endl;
		getch();
		break;
	    }
	}
	}
	if(flag1==0)
    {
        cout<<"Book code invalid"<<endl;
        getch();
    }
    }
    }
    if(flag==0)
    {
    cout<<"Library Card Number Invalid"<<endl;
      getch();
    }
    data.close();
    f6.close();
 }


 void fn::returnbook()       //Returning a book
{
    char b[15],a[15],name[15];
    int lib,bcode,r,t,code,e,libnum,w=0,d=0;
    char l[10],m[10],n[10],o[10],q[10];
    int flag=0,flag1=0;
    char *p;

    clrscr();

    cout<<"Enter Library Card Number : "<<endl;
    cin>>lib;
    cout<<"Enter the Book Code : "<<endl;
    cin>>bcode;

    fstream f6;
    f6.open("book1.txt",ios::in|ios::out|ios::nocreate);
    f6.seekg(0);

    fstream f8;
    f8.open("borrow.txt",ios::in|ios::out|ios::nocreate);
    f8.seekg(0);


    while(f8>>name>>b>>a>>libnum>>code>>l>>m>>n>>o>>q)
    {
    while(f6.eof()==0)
    {

	f6>>b;
	f6>>a;
	f6>>r;
	f6>>p;

	e=atoi(p);
	t=strlen(p);

	if(code==r)
    {
        flag=1;
	if(r==bcode)
	{
        flag1=1;
	    f6.seekg(-t,ios::cur);

	    if(e>=0)
	     {
		e++;
		f6<<e;
		cout<<"\nOne copy of this book is added to list."<<endl;
		getch();
		break;
	      }
	}
    }
    }
    }
    if(flag==0)
    {
        flag1=1;
        cout<<"Book not borrowed Or Invalid Library card number"<<endl;
        getch();
    }
    if(flag1==0)
    {
        cout<<"Book code doesnt exist"<<endl;
        getch();
    }

    f6.close();
    f8.close();


    f6.open("borrow.txt",ios::in|ios::out|ios::nocreate);
    f6.seekg(0);
    fstream f7;
    remove("temp.txt");
    f7.open("temp.txt",ios::in|ios::app);
    f7.seekg(0);
    while(f6>>name>>b>>a>>libnum>>code>>l>>m>>n>>o>>q)
    {
        {
            cout<<"bcode\t"<<bcode<<"\tcode from files\t"<<code<<endl;
            cout<<"lib\t"<<lib<<"\tlibnum from files\t"<<libnum<<endl<<endl;
            getch();
        }

	if(!((bcode==code) && (lib==libnum)))
    {
	    f7<<name<<"   "<<b<<"   "<<a<<"   "<<libnum<<"   "<<code<<"   "<<l<<" "<<m<<" "<<n<<" "<<o<<" "<<q<<endl;
    }
    else if(!((bcode!=code) && (lib!=libnum))){
	    w=1;
    }
    }
    f6.clear();
    f6.seekg(0,ios::beg);
    f6.close();
    f7.close();
    remove("borrow.txt");
    rename("temp.txt","borrow.txt");
    if(w==0)
    {
	cout<<"\nNo record deleted from Borrow list"<<endl;
	getch();
    }
    else{
	cout<<"\nRecord deleted from Borrow List"<<endl;
	getch();
    }


    f6.open("details.txt",ios::in|ios::out|ios::nocreate);
    f6.seekg(0);
    remove("temp2.txt");
    f7.open("temp2.txt",ios::in|ios::app);
    f7.seekg(0);
    while(f6>>name>>libnum>>b>>a>>l>>m>>n>>o>>q)
    {

	if(!(lib==libnum))
	    f7<<name<<"   "<<libnum<<"   "<<b<<"   "<<a<<"   "<<l<<" "<<m<<" "<<n<<" "<<o<<" "<<q<<endl;
    if(!(lib!=libnum))
	    d=1;
    }

    f6.clear();
    f6.seekg(0,ios::beg);
    f6.close();
    f7.close();
    remove("details.txt");
    rename("temp2.txt","details.txt");
    if(d==0){
        cout<<"\nNo record deleted from Profile list"<<endl;
        getch();
    }
    else{
        cout<<"\nRecord deleted from Profile List"<<endl;
        getch();
    }
}


void fn :: display_borrow()          //To show the book borrow list
 {
    clrscr();

    fstream f3;
    f3.open("borrow.txt",ios::in|ios::app);
    f3.seekg(0);

    char a;

    cout<<"\n\n";
    cout<<"\t*************** BORROW LIST ******************";
    cout<<"\n\n";
    cout<<setw(5)<<"Name"<<setw(15)<<"BookName"<<setw(10)<<"Writer"<<setw(8)<<"Card"<<setw(6)<<"Code"<<setw(15)<<"Issue Date"<<endl;
    cout<<setw(5)<<"----"<<setw(15)<<"--------"<<setw(10)<<"------"<<setw(8)<<"----"<<setw(6)<<"----"<<setw(15)<<"----------"<<endl;

    while(f3)
    {
        f3.get(a);
        cout<<a;
    }
    f3.close();
    getch();
 }

 void student::displayprofile()
 {
    clrscr();
    student s2;
    char s[100];
    fstream out("student.dat",ios::in|ios::app|ios::binary);
    while(out.read((char *)&s2,sizeof(s2)))
    {
        s2.displaydata();
    }
    cout<<"\n ";
    out.close();
    getch();
 }



int main()             //Main function
 {
    int j;
    student s3;
    fn f;

    clrscr();

    while(1)
    {
	clrscr();

	cout<<"\n\n***----- WELCOME TO LIBRARY MANAGEMENT SYSTEM -----***";
	cout<<"\n\nWhat do you want to do?"<<endl;
	cout<<"\n 1: Add a new book to the list.";
	cout<<"\n 2: Delete a copy of book from list.";
	cout<<"\n 3: Add a copy of book to list.";
	cout<<"\n 4: See the book list.";
	cout<<"\n 5: Search a Book from list.";
	cout<<"\n 6: Card details.";
	cout<<"\n 7: Borrow Book.";
	cout<<"\n 8: Return Book.";
	cout<<"\n 9: Display Borrow Details.";
	cout<<"\n10: New Student Profile.";
	cout<<"\n11: Delete Student Profile.";
	cout<<"\n12: Display Student Profiles.";
	cout<<"\n13: Exit ."<<endl;
	cout<<"\nInput your choice: "<<endl;
	cin>>j;

	switch(j)
	{
	    case 1:
	    {
		f.add_();
		break;
	    }

	    case 2:
	    {
        f.delete_();
		break;
	    }

	    case 3:
	    {
		f.plus_();
		break;
	    }

	    case 4:
	    {
		f.display_();
		break;
	    }

	    case 5:
	    {
		f.srch();
		break;
	    }

	    case 6:
	    {
		f.details();
		break;
	    }

	    case 7:
	    {
		f.borrow();
		break;
	    }

	    case 8:
	    {
		f.returnbook();
		break;
	    }

	    case 9:
	    {
		f.display_borrow();
		break;
	    }

	    case 10:
	    {
		s3.writerec();
		break;
	    }

	    case 11:
	    {
		s3.deleterec();
		break;
	    }

	    case 12:
	    {
		s3.displayprofile();
		break;
	    }

	    case 13:
	    {
		cout<<"Thank you."<<endl;
		getch();
		break;
	    }
	    default:
            {
                cout<<"Invalid choice";
                getch();
                break;
            }
	}
    if(j==13)
        break;
    }
    return 0;
 }
