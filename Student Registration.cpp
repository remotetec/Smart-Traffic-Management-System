// STUDENT REGISTRATION

#include <iostream>
#include <conio.h>
#include <fstream>
#include <time.h>
#include <iomanip>
#include <cstdlib>
#include <string.h>
using namespace std;

int i, choice, dd=0, mm=0, yy=0, hr=0, mint=0;  
void date_time();

class Display{
	public:
		void password(); 
		void loading();
		void menu();
		int itm();				
};

class functions{
	public:
		void student_menu();
};

class student {
	private:
    	int long long smo;
		int sem ;
	 
		char rollno[20], name[40], father_name[50], dob[30], cadd[100], padd[100]  ,rdate[20], emailid[50], session[20], issue_date[34];
	public:
		student(){strcpy(rollno, "ABXXXXXXXX");
		          strcpy(dob, " XX-XX-XXXX");
				  strcpy(emailid, "ABXXXXXXX@gmail.com");
				  strcpy(session, "ABXXXXXXXX");
				  strcpy(cadd, "ABXXXXXXXX");
				  strcpy(padd, "ABXXXXXXXX");}
		
		void header();		  
		void add_record();
		int store_record();
		void display_record();
		void show_record(); 
		void delete_record(char *);
		void search_record(char *);
};

int main() {
	Display od;
	od.password();
	return 0;
}
 
void student::add_record() {
	system("cls");
	
	cout <<"\n\n\n\n\n\t\t\t\t\t\t\t\t";
    for(i=0; i<=41; i++)
	cout << "_";
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t\xB3\xB3"; 
	for(i=0; i<=37; i++)
	cout << "\xC1";
	cout << "\xB3\xB3";
	cout << "\n\t\t\t\t\t\t\t\t\xB3\xB3 ---ENTER THE STUDENT INFORMATION---  \xB3\xB3";
	cout << "\n\t\t\t\t\t\t\t\t\xB3\xB3";
	for(i=0; i<=37; i++)
	cout << "_";
	cout << "\xB3\xB3";
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t";
	for(i=0; i<=41; i++)
    cout << "\xC1";
	cout << "\n\n";
	
	cout << "\n\t\t\t\t\t\t\t\t\xB2\xB2 ROLL NUMBER       : ";
    cin.ignore();
    cin.getline(rollno, 19);
	cout << "\n\t\t\t\t\t\t\t\t\xB2\xB2 STUDENT NAME      : ";
   // cin.ignore();
    cin.getline(name, 39);
    cout << "\n\t\t\t\t\t\t\t\t\xB2\xB2 MOBILE NO         : ";
    cin >> smo;
    cout << "\n\t\t\t\t\t\t\t\t\xB2\xB2  EMAIL ID         : ";
    cin.ignore();
    cin.getline(emailid, 49);
    cout << "\n\t\t\t\t\t\t\t\t\xB2\xB2 D.O.B             : ";
   // cin.ignore();
    cin.getline(dob, 29);
   cout <<  "\n\t\t\t\t\t\t\t\t\xB2\xB2 SEMESTER          : ";
    cin >> sem;
    cout << "\n\t\t\t\t\t\t\t\t\xB2\xB2 SESSION           : ";
    cin.ignore();
    cin.getline(session, 19);
    cout << "\n\t\t\t\t\t\t\t\t\xB2\xB2 FATHER'S NAME     : ";
   // cin.ignore();
    cin.getline(father_name, 49);
    //cout << "\n\t\t\t\t\t\t\t\t\xB2\xB2 FATHER'S MOBILE NO : ";
    //cin >> fmo;
	cout << "\n\t\t\t\t\t\t\t\t\xB2\xB2 CURRENT ADDRESS   : ";
 //   cin.ignore();
    cin.getline(cadd, 99);
    cout << "\n\t\t\t\t\t\t\t\t\xB2\xB2 PERMANENT ADDRESS : ";
 //   cin.ignore();
    cin.getline(padd, 99);  
	//Date and Time
	date_time();
	sprintf(issue_date, "%d:%d %d/%d/%d", hr, mint, dd, mm, yy);
}

int student::store_record() {
	functions f;
	if(rollno == 0) {
		cout<<"\nDATA NOT INTIAlIZED";

	} else {
		ofstream fout;
		fout.open("file1.dat", ios::app|ios::binary);
		fout.write((char*)this, sizeof(*this));
		fout.close();
		cout << "\n\t\t\t\t\t\t\t\tDATA STORED SUCCESSFULLY";
 
	}
	cout << "\n\t\t\t\t\t\t\t\tPress any key to continue...";
	getch();
	f.student_menu();
}

void student::display_record() {
	system("cls");
	Display d;
	
	cout <<"\n\t\t\t\t\t\t\t\t";
    for(i=0; i<=41; i++)
	cout << "_";
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t\xB3\xB3"; 
	for(i=0; i<=37; i++)
	cout << "\xC1";
	cout << "\xB3\xB3";
	cout << "\n\t\t\t\t\t\t\t\t\xB3\xB3\t----RECORD OF STUDENT----\t\xB3\xB3";
	cout << "\n\t\t\t\t\t\t\t\t\xB3\xB3";
	for(i=0; i<=37; i++)
	cout << "_";
	cout << "\xB3\xB3";
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t";
	for(i=0; i<=41; i++)
	cout << "\xC1";
	cout << "\n\n";
  	for(i=0; i<=210; i++)
	cout << "_";
	
	header();
	ifstream fin;
	fin.open("file1.dat", ios::in|ios::binary);
	if(!fin)
		cout << "\n\t File Not Found !";
	else {
		fin.read((char*)this, sizeof(*this));
		while(!fin.eof()) {
			show_record();
			fin.read((char*)this, sizeof(*this));	
		}
		fin.close();
	}
	
	for(i=0; i<=210; i++)
	cout << "_";
	cout << "\n\n\n\n\t\t\t\t\t\t\t\t  Press any key to continue...";
	getch();
	d.menu();    
}

void student::header() {
	cout << endl;
	cout<<setw(15)<<"Roll No\xB3"<<setw(21)<<"Student Name\xB3"<<setw(15)<<"Mobile no.\xB3"<<setw(30)<<"Email\xB3"<<setw(16)<<"DOB\xB3"<<setw(12)<<"Semester\xB3"<<setw(13)<<"Session\xB3"<<setw(20)<<"Father Name\xB3"<<setw(25)<<"Current Address\xB3"<<setw(25)<<"Permanent Address\xB3"<<setw(18)<<"Issued Date\xB3";
    cout<<"\n";
	for(i=0; i<=210; i++)
	cout << "=";
}
	
void student::show_record() {
	
    cout<<setw(14)<<rollno<<"\xB3"<<setw(20)<<name<<"\xB3"<<setw(14)<<smo<<"\xB3"<<setw(29)<<emailid<<"\xB3"<<setw(15)<<dob<<"\xB3"<<setw(11)<<sem<<"\xB3"<<setw(12)<<session<<"\xB3"<<setw(19)<<father_name<<"\xB3"<<setw(24)<<cadd<<"\xB3"<<setw(24)<<padd<<"\xB3"<<setw(17)<<issue_date<<"\xB3";
    cout<<"\n";
	
/*	cout<<"\n\t\t\t\t\t\t\t\t \xB2\xB2 ROLLNO                :- "<<rollno;
	cout<<endl; 
	cout<<"\n\t\t\t\t\t\t\t\t \xB2\xB2 STUDENT NAME          :- "<<name;
	cout<<"\n\t\t\t\t\t\t\t\t \xB2\xB2 MOBILE NUMBER         :- "<<smo;
    cout<<"\n\t\t\t\t\t\t\t\t \xB2\xB2 EMAIL ID              :- "<<emailid;
	cout<<"\n\t\t\t\t\t\t\t\t \xB2\xB2 D.O.B                 :- "<<dob;
	cout<<"\n\t\t\t\t\t\t\t\t \xB2\xB2 SEMESTER              :- "<<sem;
    cout<<"\n\t\t\t\t\t\t\t\t \xB2\xB2 SESSION               :- "<<session;
	cout<<"\n\t\t\t\t\t\t\t\t \xB2\xB2 FATHER'S NAME         :- "<<father_name;
	cout<<"\n\t\t\t\t\t\t\t\t \xB2\xB2 FATHER'S PHONE NUMBER :- "<<fmo;
	cout<<"\n\t\t\t\t\t\t\t\t \xB2\xB2 CURRENT ADDRESS       :- "<<cadd;
	cout<<"\n\t\t\t\t\t\t\t\t \xB2\xB2 PERMANENT ADDRESS     :- "<<padd;
	cout<<"\n\t\t\t\t\t\t\t\t \xB2\xB2 Issued Date           :- "<<issue_date;
    cout<<endl;  
  	for(i=0; i<=210; i++)
	cout << "_";
*/
	
}

void student::delete_record(char *t) {
	functions f;
	int counter=0;
	ifstream fin;
	ofstream fout;
	fin.open("file1.dat", ios::in|ios::binary);
	if(!fin)
		cout << "\nFile NOT Found";
	else {
		fout.open("tempFile.dat", ios::out|ios::binary);
		fin.read((char*)this, sizeof(*this));
		while(!fin.eof()) {
			if(strcmp(t, rollno)) {
				fout.write((char*)this, sizeof(*this)); counter++;
			}fin.read((char*)this, sizeof(*this));
		}
		fin.close();
		fout.close();
		remove("file1.dat");
		rename("tempFile.dat", "file1.dat");
		if(counter==0) 
		cout<<"\n\n\n\t\t\t\t\t\t\t\t  DELETED SUCCESSFULLLY";
		else 
		cout << "\n\n\n\t\t\t\t\t\t\t\t  UNABLLE TO DELETE";
	}
	cout << "\n\t\t\t\t\t\t\t\t  Press any key to continue...";
	getch();
	f.student_menu(); 
}

void student::search_record(char *t) {
	Display d;
	int counter=0;
	ifstream fin;
	fin.open("file1.dat", ios::in|ios::binary);
	if(!fin)
		cout << "\nFile NOT Found !";
	else {
		fin.read((char*)this, sizeof(*this));
		while(!fin.eof()) {
			if(!strcmp(t, rollno)) {
				show_record();
				counter++;
			}
			fin.read((char*)this, sizeof(*this));
		}
		if(counter==0)
			cout << "\n\n\n\t\t\t\t\t\t\t\t  Record NOT Found";
		fin.close();
	}
	cout << "\n\t\t\t\t\t\t\t\t  Press any key to continue...";
    getch();
	d.menu();
}

/*Menu of student Data*/
void functions::student_menu() {
	system("cls");
	Display d;
    student st;
	char get[15];
	
	cout <<"\n\n\n\n\n\t\t\t\t\t\t\t\t";
    for(i=0; i<=41; i++)
	cout << "_";
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t\xB3\xB3";
	for(i=0; i<=37; i++)
	cout << "\xC1";
	cout << "\xB3\xB3";
	cout << "\n\t\t\t\t\t\t\t\t\xB3\xB3\t---CHOOSE YOUR OPTION---\t\xB3\xB3";
	cout << "\n\t\t\t\t\t\t\t\t\xB3\xB3";
	for(i=0; i<=37; i++)
	cout << "_";
	cout << "\xB3\xB3";
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t";
	for(i=0; i<=41; i++)
	cout << "\xC1";
	cout << "\n\n";
	
	cout << "\n\t\t\t\t\t\t\t  ";
	for(i=0; i<=54; i++)
	cout << "_";
	cout << "\n\t\t\t\t\t\t\t  \xB3 1.\xB3 I N S E R T  A STUDENT REGISTRATION  \t\t\xB3";
	cout << "\n\t\t\t\t\t\t\t  \xB3___\xB3";
	for(i=0; i<=48; i++)
	cout << "_";
	cout << "\xB3";
	cout << "\n\t\t\t\t\t\t\t  \xB3 2.\xB3 D E L E T E  A STUDENT REGISTRATION\t\t\xB3";
	cout << "\n\t\t\t\t\t\t\t  \xB3___\xB3";
	for(i=0; i<=48; i++)
	cout << "_";
	cout << "\xB3";
	cout << "\n\t\t\t\t\t\t\t  \xB3 3.\xB3 B A C K   TO  MAIN  MENU    \t\t\t\xB3";
	cout << "\n\t\t\t\t\t\t\t  \xB3___\xB3";
	for(i=0; i<=48; i++)
	cout << "_";
	cout << "\xB3";	
	
	while(choice != 3) {
	cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t ENTER YOUR CHOICE : ";
	cin >> choice;
	switch(choice) {
    case 1: {
			 st.add_record();
			 st.store_record();
			 break;
			}
    case 2: {
			 system("cls");
			 cout <<"\n\n\n\n\n\t\t\t\t\t\t\t\t";
             for(i=0; i<=41; i++)
	         cout << "_";
	         cout << endl;
	         cout << "\t\t\t\t\t\t\t\t\xB3\xB3"; 
	         for(i=0; i<=37; i++)
	         cout << "\xC1";
	         cout << "\xB3\xB3";
	         cout << "\n\t\t\t\t\t\t\t\t\xB3\xB3\t----DELETE THE RECORD----\t\xB3\xB3";
	         cout << "\n\t\t\t\t\t\t\t\t\xB3\xB3";
	         for(i=0; i<=37; i++)
	         cout << "_";
	         cout << "\xB3\xB3";
	         cout << endl;
	         cout << "\t\t\t\t\t\t\t\t";
	         for(i=0; i<=41; i++)
	         cout << "\xC1";
	  
	  
	         cout << "\n\n";
			 cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  Enter the Vehicle No to delete : ";
			 cin.ignore();
    		 cin.getline(get, 14);
			 st.delete_record(get);
			 break;
			}
	case 3: d.menu();
		} 
	}
}

/*PASSWORD*/
void Display::password() { 
	functions f;system("color 02");
	system("cls");
	system("color 02");
	{ 
   
cout<<"\n\n\n\n\n\n";

cout<<"\n\t\t\t\t\t\t\t";       // (1)
for(i=0; i<=5; i++)
cout << "_";
for(i=0; i<=10; i++)
cout << "\xB2";
for(i=0; i<=5; i++)
cout << "_";
for(i=0; i<=32; i++)
cout << "\xb2";
for(i=0; i<=5; i++)
cout << "_";
for(i=0; i<=11; i++)
cout << "\xb2";
for(i=0; i<=10; i++)
cout << "_";
for(i=0; i<=11; i++)
cout << "\xb2";
for(i=0; i<=5; i++)
cout << "_";
cout<<"\n\t\t\t\t\t\t\t";
for(i=0; i<=102; i++)
cout << "_";

cout<<"\n\t\t\t\t\t\t\t";       // (2)
for(i=0; i<=5; i++)
cout << "_";
for(i=0; i<=10; i++)
cout << "\xB2";
for(i=0; i<=5; i++)
cout << "_";
for(i=0; i<=32; i++)
cout << "\xb2";
for(i=0; i<=5; i++)
cout << "_";
for(i=0; i<=12; i++)
cout << "\xb2";
for(i=0; i<=8; i++)
cout << "_";
for(i=0; i<=12; i++)
cout << "\xb2";
for(i=0; i<=5; i++)
cout << "_";
cout<<"\n\t\t\t\t\t\t\t";
for(i=0; i<=102; i++)
cout << "_";

cout<<"\n\t\t\t\t\t\t\t";       // (3)
for(i=0; i<=5; i++)
cout << "_";
for(i=0; i<=10; i++)
cout << "\xB2";
for(i=0; i<=5; i++)
cout << "_";
for(i=0; i<=32; i++)
cout << "\xb2";
for(i=0; i<=5; i++)
cout << "_";
for(i=0; i<=13; i++)
cout << "\xb2";
for(i=0; i<=6; i++)
cout << "_";
for(i=0; i<=13; i++)
cout << "\xb2";
for(i=0; i<=5; i++)
cout << "_";
cout<<"\n\t\t\t\t\t\t\t";
for(i=0; i<=102; i++)
cout << "_";

cout<<"\n\t\t\t\t\t\t\t";       // (4)
for(i=0; i<=5; i++)
cout << "_";
for(i=0; i<=10; i++)
cout << "\xB2";
for(i=0; i<=16; i++)
cout << "_";
for(i=0; i<=10; i++)
cout << "\xb2";
for(i=0; i<=16; i++)
cout << "_";
for(i=0; i<=14; i++)
cout << "\xb2";
for(i=0; i<=4; i++)
cout << "_";
for(i=0; i<=14; i++)
cout << "\xb2";
for(i=0; i<=5; i++)
cout << "_";
cout<<"\n\t\t\t\t\t\t\t";
for(i=0; i<=102; i++)
cout << "_";

cout<<"\n\t\t\t\t\t\t\t";       // (5)
for(i=0; i<=5; i++)
cout << "_";
for(i=0; i<=10; i++)
cout << "\xB2";
for(i=0; i<=16; i++)
cout << "_";
for(i=0; i<=10; i++)
cout << "\xb2";
for(i=0; i<=16; i++)
cout << "_";
for(i=0; i<=15; i++)
cout << "\xb2";
for(i=0; i<=2; i++)
cout << "_";
for(i=0; i<=15; i++)
cout << "\xb2";
for(i=0; i<=5; i++)
cout << "_";
cout<<"\n\t\t\t\t\t\t\t";
for(i=0; i<=102; i++)
cout << "_";

cout<<"\n\t\t\t\t\t\t\t";       // (6)
for(i=0; i<=5; i++)
cout << "_";
for(i=0; i<=10; i++)
cout << "\xB2";
for(i=0; i<=16; i++)
cout << "_";
for(i=0; i<=10; i++)
cout << "\xb2";
for(i=0; i<=16; i++)
cout << "_";
for(i=0; i<=8; i++)
cout << "\xb2";
for(i=0; i<=0; i++)
cout << "_";
for(i=0; i<=6; i++)
cout << "\xb2";
for(i=0; i<=0; i++)
cout << "_";
for(i=0; i<=6; i++)
cout << "\xb2";
for(i=0; i<=0; i++)
cout << "_";
for(i=0; i<=8; i++)
cout << "\xb2";
for(i=0; i<=5; i++)
cout << "_";
cout<<"\n\t\t\t\t\t\t\t";
for(i=0; i<=102; i++)
cout << "_";

cout<<"\n\t\t\t\t\t\t\t";       // (7)
for(i=0; i<=5; i++)
cout << "_";
for(i=0; i<=10; i++)
cout << "\xB2";
for(i=0; i<=16; i++)
cout << "_";
for(i=0; i<=10; i++)
cout << "\xb2";
for(i=0; i<=16; i++)
cout << "_";
for(i=0; i<=8; i++)
cout << "\xb2";
for(i=0; i<=1; i++)
cout << "_";
for(i=0; i<=12; i++)
cout << "\xb2";
for(i=0; i<=1; i++)
cout << "_";
for(i=0; i<=8; i++)
cout << "\xb2";
for(i=0; i<=5; i++)
cout << "_";
cout<<"\n\t\t\t\t\t\t\t";
for(i=0; i<=102; i++)
cout << "_";

cout<<"\n\t\t\t\t\t\t\t";       // (8)
for(i=0; i<=5; i++)
cout << "_";
for(i=0; i<=10; i++)
cout << "\xB2";
for(i=0; i<=16; i++)
cout << "_";
for(i=0; i<=10; i++)
cout << "\xb2";
for(i=0; i<=16; i++)
cout << "_";
for(i=0; i<=8; i++)
cout << "\xb2";
for(i=0; i<=2; i++)
cout << "_";
for(i=0; i<=10; i++)
cout << "\xb2";
for(i=0; i<=2; i++)
cout << "_";
for(i=0; i<=8; i++)
cout << "\xb2";
for(i=0; i<=5; i++)
cout << "_";
cout<<"\n\t\t\t\t\t\t\t";
for(i=0; i<=102; i++)
cout << "_";

cout<<"\n\t\t\t\t\t\t\t";       // (9)
for(i=0; i<=5; i++)
cout << "_";
for(i=0; i<=10; i++)
cout << "\xB2";
for(i=0; i<=16; i++)
cout << "_";
for(i=0; i<=10; i++)
cout << "\xb2";
for(i=0; i<=16; i++)
cout << "_";
for(i=0; i<=8; i++)
cout << "\xb2";
for(i=0; i<=3; i++)
cout << "_";
for(i=0; i<=8; i++)
cout << "\xb2";
for(i=0; i<=3; i++)
cout << "_";
for(i=0; i<=8; i++)
cout << "\xb2";
for(i=0; i<=5; i++)
cout << "_";
cout<<"\n\t\t\t\t\t\t\t";
for(i=0; i<=102; i++)
cout << "_";

cout<<"\n\t\t\t\t\t\t\t";       // (10)
for(i=0; i<=5; i++)
cout << "_";
for(i=0; i<=10; i++)
cout << "\xB2";
for(i=0; i<=16; i++)
cout << "_";
for(i=0; i<=10; i++)
cout << "\xb2";
for(i=0; i<=16; i++)
cout << "_";
for(i=0; i<=8; i++)
cout << "\xb2";
for(i=0; i<=4; i++)
cout << "_";
for(i=0; i<=6; i++)
cout << "\xb2";
for(i=0; i<=4; i++)
cout << "_";
for(i=0; i<=8; i++)
cout << "\xb2";
for(i=0; i<=5; i++)
cout << "_";
cout<<"\n\t\t\t\t\t\t\t";
cout<<"\n\t\t\t\t\t\t\t\t\t    G  R  O  U  P      O  F      I  N  S  T  I  T  U  T  I  O  N  S ";  
}
	cout<<"\n\n\t\t\t\t\t\t\t  ";
	for(int i=0;i<98;i++)
	{
    cout<<"\xb2";
	}
	cout<<"\n";
	cout<<"\t\t\t\t\t\t\t  \xb2\xb2----------------------------------------------------------------------------------------------\xb2\xb2  \n";
	cout<<"\t\t\t\t\t\t\t  \xb2\xb2-------W E L C O M E----T O----S T U D E N T----R E G I S T R A T I O N----S Y S T E M--------\xb2\xb2  \n";
	cout<<"\t\t\t\t\t\t\t  \xb2\xb2----------------------------------------------------------------------------------------------\xb2\xb2  \n";
	cout<<"\t\t\t\t\t\t\t  ";
	for(int i=0;i<98;i++)
	{
    cout<<"\xb2";
	}
	cout<<"\n"; 
	
	/*cout<<"\n\n\n\n";
	cout<<"\t\t\t\t\t";
	for(int i=0;i<100;i++)
	{
    cout<<"\xC5";
	}
	cout<<"\n\t\t\t\t\t";
	for(int i=0;i<100;i++)
	{
    cout<<"\xC5";
	}
	cout<<"\n";
	cout<<"\t\t\t\t\t\xC5\xC5\xC5\xC5\t\t\t\t\t\t\t\t\t\t                 \xC5\xC5\xC5\xC5"<<endl;
	cout<<"\t\t\t\t\t\xC5\xC5\xC5\xC5\t\t\t\t\t\t\t\t\t\t                 \xC5\xC5\xC5\xC5"<<endl;
	cout<<"\t\t\t\t\t\xC5\xC5\xC5\xC5   \t   \t   \xB2\xB2       I . T . M         G O I        G W A L I O R       \xB2\xB2\t        \xC5\xC5\xC5\xC5"<<endl;
	cout<<"\t\t\t\t\t\xC5\xC5\xC5\xC5\t\t\t\t\t\t\t\t\t\t                 \xC5\xC5\xC5\xC5"<<endl;
    cout<<"\t\t\t\t\t\xC5\xC5\xC5\xC5\t\t\t\t\t\t\t\t\t\t                 \xC5\xC5\xC5\xC5"<<endl;
    cout<<"\t\t\t\t\t\xC5\xC5\xC5\xC5\t\t\t\t\t\t\t\t\t\t                 \xC5\xC5\xC5\xC5"<<endl;
    cout<<"\t\t\t\t\t\xC5\xC5\xC5\xC5   \t           S T U D E N T        R E G I S T R A T I O N         P O R T A L  \t        \xC5\xC5\xC5\xC5"<<endl;
    cout<<"\t\t\t\t\t\xC5\xC5\xC5\xC5\t\t\t\t\t\t\t\t\t\t                 \xC5\xC5\xC5\xC5"<<endl;
    cout<<"\t\t\t\t\t\xC5\xC5\xC5\xC5\t\t\t\t\t\t\t\t\t\t                 \xC5\xC5\xC5\xC5"<<endl;
    cout<<"\t\t\t\t\t\xC5\xC5\xC5\xC5\t\t\t\t\t\t\t\t\t\t                 \xC5\xC5\xC5\xC5"<<endl;
    cout<<"\t\t\t\t\t";
	for(int i=0;i<100;i++)
	{
    cout<<"\xC5";
	}
	cout<<"\n\t\t\t\t\t";
	for(int i=0;i<100;i++)
	{
    cout<<"\xC5";
	}
    cout<<"\n\n\n"; */
    
    int pin;
    static int i=3;
    int pass = 1234;
	cout<<"\n\t\t\t\t\t\t\t\t\t\t     |#| PLEASE ENTER YOUR PASSWORD : "; 
	cin>>pin;
	if(pin==pass)
	{
		system("color 02");
		loading();	
		menu();
	}else {
		system("color 4");
		cout<<"\n";
		cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\t  \xB2\xB2 SORRY, PASSWORD IS NOT CORRECT......";
		cout << "Attempts left " << i;i--; 
		getch();
		password();
	    if(i==-1)
		{
		cout<<"\n\n\t\t\t\t\t\t  \xB2\xB2 BETTER LUCK NEXT TIME";
		exit(0);
		}
	}
}

/*LOADING SCREEN*/
void Display::loading() {
	system("cls");
    int r,c,q;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout <<"\t\t\t\t\t\t\t\t\t\t\tLoading...\n";
    cout <<"\t\t\t\t\t\t\t\t\t\t"; 
    for(i=0; i<=30; i++)
	cout << "_";
    cout <<"\n\t\t\t\t\t\t\t\t\t\t\xB3";
    for(r=1; r<=30; r++) {
        for(q=0; q<=8888888; q++); //to display the character slowly
    		printf("%c", 177); 		 	
    }
}

/*MENU SCREEN*/
void Display::menu() {
	system("cls");
	char srch[15];
	functions f; student st;
	system("color 02");
    system("cls");
    cout <<"\n\n\n\n\n\t\t\t\t\t\t\t\t";
    for(i=0; i<=40; i++)
	cout << "_";
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t\xB3\xB3";
	for(i=0; i<=36; i++)
	cout << "\xC1";
	cout << "\xB3\xB3";
	cout << "\n\t\t\t\t\t\t\t\t\xB3\xB3R E G I S T R A T I O N  P O R T A L \xB3\xB3";
	cout << "\n\t\t\t\t\t\t\t\t\xB3\xB3";
	for(i=0; i<=36; i++)
	cout << "_";
	cout << "\xB3\xB3";
	cout << endl;
	cout << "\t\t\t\t\t\t\t\t";
	for(i=0; i<=40; i++)
	cout << "\xC1";
	cout << "\n\n";
	cout << "\n\t\t\t\t\t\t\t  ";
	for(i=0; i<=54; i++)
	cout << "_";
	cout << "\n\t\t\t\t\t\t\t  \xB3 1.\xB3 S T U D E N T  REGISTRATION               \t\xB3";
	cout << "\n\t\t\t\t\t\t\t  \xB3___\xB3";
	for(i=0; i<=48; i++)
	cout << "_";
	cout << "\xB3";
	cout << "\n\t\t\t\t\t\t\t  \xB3 2.\xB3 R E C O R D  OF STUDENT REGISTRATION            \xB3";
	cout << "\n\t\t\t\t\t\t\t  \xB3___\xB3";
	for(i=0; i<=48; i++)
	cout << "_";
	cout << "\xB3";
	cout << "\n\t\t\t\t\t\t\t  \xB3 3.\xB3 S E A R C H  THE STUDENT REGISTRATION           \xB3";
	cout << "\n\t\t\t\t\t\t\t  \xB3___\xB3";
	for(i=0; i<=48; i++)
	cout << "_";
	cout << "\xB3";	
	cout << "\n\t\t\t\t\t\t\t  \xB3 4.\xB3 E X I T                                         \xB3";
	cout << "\n\t\t\t\t\t\t\t  \xB3___\xB3";
	for(i=0; i<=48; i++)
	cout << "_";
	cout << "\xB3";

	while(choice!=4) {
		cout << "\n\n\n\t\t\t\t\t\t\t\t\t ENTER YOUR CHOICE : ";
		cin >> choice; 
		switch(choice) {
			case 1:	f.student_menu(); break;
			case 2:	st.display_record(); break;
			case 3:	{
			    system("cls");
			    cout <<"\n\n\n\n\n\t\t\t\t\t\t\t\t";
                for(i=0; i<=41; i++)
	            cout << "_";
	            cout << endl;
	            cout << "\t\t\t\t\t\t\t\t\xB3\xB3"; 
	            for(i=0; i<=37; i++)
	            cout << "\xC1";
	            cout << "\xB3\xB3";
	            cout << "\n\t\t\t\t\t\t\t\t\xB3\xB3\t----SEARCH THE RECORD----\t\xB3\xB3";
	            cout << "\n\t\t\t\t\t\t\t\t\xB3\xB3";
	            for(i=0; i<=37; i++)
	            cout << "_";
	            cout << "\xB3\xB3";
	            cout << endl;
	            cout << "\t\t\t\t\t\t\t\t";
	            for(i=0; i<=41; i++)
	            cout << "\xC1";
	            cout << "\n\n";
			    cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  ENTER THE ROLL NO. TO SEARCH :- ";			 
				cin.ignore();
    			cin.getline(srch, 14);
    			for(i=0; i<=210; i++)
	            cout << "_";
    			st.header();
				st.search_record(srch);
				break;
			}
			case 4: {
				cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t     Thanks for using our Service, hope this helps you in your daily life";
				getch();exit(0);break;
			}
		} 
	}
}

/*DATE and TIME*/
void date_time() {
	time_t t = time(NULL);
  	struct tm tm = *localtime(&t);
	dd = tm.tm_mday; mm = tm.tm_mon + 1; yy = tm.tm_year + 1900-2000;
  	hr = tm.tm_hour; mint = tm.tm_min;
} 



