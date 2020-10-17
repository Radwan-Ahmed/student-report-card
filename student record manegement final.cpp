#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;
struct student
{
char name[100];
char id[100];
int roll;
float N,J,M,A,N_C,J_C,M_C,A_C,credit,GPA,point,sum;
};
void intro();
void mainmenu();
void acceptdata();
void teachers();
void students();
void view_Specific(int);
void viewall();
void result(int);
void deleterecord(int);
void modify(int);

int main()
{
    system("color a");
    char c;
    system("cls");
    intro();

    do{
   system("cls");
   system("color e");
   cout<<"\n\n";
   cout<<"\t====================STUDENT REPORT CARD MANEGEMENT SYSTEM===================="<<endl;
   cout<<endl;
   Sleep(300);
   cout<<"\t\t\t\t1. MAIN MENU\n\n";
   Sleep(300);
   cout<<"\t\t\t\t2. EXIT\n\n";
   Sleep(300);
   cout<<"ENTER YOUR CHOICE :";
   cin>>c;
   system("cls");
   switch(c)
   {
   case '1':
    {
        mainmenu();
        break;
    }
   }
    }while(c!='2');
    return 0;
}
void acceptdata()
{
    system("cls");
    student s;
    ofstream outfile;
    outfile.open("Student_record.txt",ios::app|ios::binary);
    if(outfile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPEN...press enter key";
        cin.ignore();
        cin.get();
    }
    cout<<"\n\n";
    cout<<"\t\t\t\t=======CREATE A REPORT CARD========\n\n";
    cout<<"ENTER YOUR FULL NAME :";
    cin.ignore();
    cin.getline(s.name,100);
    cout<<"ENTER YOUR ID NUMBER :";
    cin.get(s.id,100);
    cout<<"ENTER YOUR ROLL NUMBER :";
    cin>>s.roll;
    cout<<"ENTER YOUR Obtained Numerical Subject Point :";
    cin>>s.N;
    cout<<"Enter your numerical subject credit: ";
    cin>>s.N_C;
    cout<<"ENTER YOUR Obtained Java Subject Point :";
    cin>>s.J;

    cout<<"ENTER YOUR Java Subject credit :";
    cin>>s.J_C;

    cout<<"ENTER YOUR Obtained MATH Subject Point :";
    cin>>s.M;

    cout<<"ENTER YOUR MATH Subject credit :";
    cin>>s.M_C;
    cout<<"ENTER YOUR Obtained Algorithm Subject Point :";
    cin>>s.A;
    cout<<"ENTER YOUR Algorithm Subject Credit :";
    cin>>s.A_C;
    //cout<<"Enter your Total Credit :";
    //cin>>s.credit;
    s.sum=(s.N*s.N_C)+(s.J*s.J_C)+(s.M*s.M_C)+(s.A*s.A_C);
    s.credit=(s.N_C+s.J_C+s.M_C+s.A_C);
    s.GPA=(s.sum/s.credit);
    outfile.write(reinterpret_cast<char *> (&s), sizeof(student));
    outfile.close();
    cout<<endl;
    cout<<"\t\t\t\tTHE FILE IS SUCCESSFULLY SAVED"<<endl;
    cout<<endl;
    cout<<"press any key to continue...";
    cin.ignore();
    cin.get();
}

void intro()

{

    cout << "\n\n\n";
    cout<<"\t\t\t\t============================================="<<endl;
    Sleep(300);
    cout<<"\t\t\t\tSTUDENT REPORT CARD MANEGEMENT SYSTEM"<<endl;
    Sleep(300);
    cout<<"\t\t\t\t============================================="<<endl;
    Sleep(300);
    cout<<"press any key two times to continue...\n";
    Sleep(300);
    cin.ignore();
    cin.get();
}

void mainmenu()

{
    system("color a");
    char c;
    system("cls");
   do{
   system("cls");
   system("color e");
    cout<<"\t\t\t\t=================MAIN MENU================\n\n"<<endl;
    cout<<endl;
    Sleep(300);
    cout<<"\t\t\t\t1. TEACHERS ONLY \n\n"<<endl;
    Sleep(300);
    cout<<"\t\t\t\t2. STUDENTS  \n\n"<<endl;
    Sleep(300);
    cout<<"\t\t\t\t3.MAIN MENU \n\n"<<endl;
    Sleep(300);
    cout<<"\t\t\t\t=============================="<<endl;
    Sleep(300);
    cout<<"\t\t\t\tENTER YOUR CHOICE...:) <1-3> :\n";
    cin>>c;
    system("cls");
    switch(c)
{
    case '1':
        {
            teachers();
            break;
        }
        case '2':
          {
              students();
              break;
           }
   //     case '3':
     //       {
       //         return intro();
         //   }
}
}
while(c!='3');
    //return 0;
}
void teachers()
{
    system("color c");
    char cc;
    cout<<"\t\t\t\t=================TEACHERS MENU================\n\n"<<endl;
    Sleep(300);
    cout<<"\t\t\t\t1. CREATE STUDENT REPORT CARD\n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t\t2.VIEW A SINGLE STUDENT REPORT CARD \n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t\t3.VIEW ALL STUDENTs REPORT CARD \n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t\t4. MODIFY REPORT CARD\n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t\t5. RESULT\n\n"<<endl;
     Sleep(300);
     cout<<"\t\t\t\t6. DELETE RECORD\n\n"<<endl;
     Sleep(300);
     cout<<"\t\t\t\t7. Exit Previous (press 0)\n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t\t=============================="<<endl;
     Sleep(300);
    cout<<"\t\t\t\tENTER YOUR CHOICE...:) <1-6> :\n";
     Sleep(300);
    cin>>cc;
    cout<<endl;
    switch(cc)
    {
    case '1':
        {
            acceptdata();
            break;
        }
        case '2':
          {
              int n;
              cout<<"ENTER YOUR ROLL NUMBER :";
              cin>>n;
              view_Specific(n);
              break;
    case '3':
        {
            viewall();
            break;
        }

          }
    case '4':
        {
            int n;
            cout<<"ENTER YOUR ROLL NUMBER :";
            cin>>n;
            modify(n);
            break;
        }

    case '5':
        {
            int n;
            cout<<"ENTER YOUR ROLL NUMBER :";
            cin>>n;
            cout<<endl;
            result(n);
            break;
        }
    case '6':
        {
            int n;
            cout<<"ENTER YOUR ROLL NUMBER :";
            cin>>n;
            cout<<endl;
            deleterecord(n);
            break;
        }
    }
}
void students()
{
system("color c");
    char cc;
    cout<<"\t\t\t\t=================STUDENTS MENU================\n\n"<<endl;
    Sleep(300);
    //cout<<"\t\t\t\t1. CREATE STUDENT REPORT CARD\n\n"<<endl;
     //Sleep(300);
    cout<<"\t\t\t\t1.VIEW A SINGLE STUDENT REPORT CARD \n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t\t2.VIEW ALL STUDENTs REPORT CARD \n\n"<<endl;
     Sleep(300);
    //cout<<"\t\t\t\t4. MODIFY REPORT CARD\n\n"<<endl;
     //Sleep(300);
    cout<<"\t\t\t\t3. RESULT\n\n"<<endl;
     Sleep(300);
     cout<<"\t\t\t\t4. EXIT Previous(press 0)\n\n"<<endl;
     Sleep(300);
     //cout<<"\t\t\t\t6. DELETE RECORD\n\n"<<endl;
     //Sleep(300);
    cout<<"\t\t\t\t=============================="<<endl;
     Sleep(300);
    cout<<"\t\t\t\tENTER YOUR CHOICE...:) <1-3> :\n";
     Sleep(300);
    cin>>cc;
    cout<<endl;
    switch(cc)
    {
        case '1':
          {
              int n;
              cout<<"ENTER YOUR ROLL NUMBER :";
              cin>>n;
              view_Specific(n);
              break;
    case '2':
        {
            viewall();
            break;
        }

          }

    case '3':
        {
            int n;
            cout<<"ENTER YOUR ROLL NUMBER :";
            cin>>n;
            cout<<endl;
            result(n);
            break;
        }
    }
}
void viewall()

{
    system("cls");
    student s;
    ifstream infile;
    bool check=false;
    infile.open("Student_record.txt",ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED.....press enter key...";
        cin.ignore();
        cin.get();
    }
     cout<<"\n\n";
     cout<<"\t\t\t\tALL STUDENTS REPORT CARDS"<<endl;
     cout<<"=================================================================================="<<endl;
    while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
    {
        cout<<"\t\t\t\tSTUDENT NAME :"<<s.name<<endl<<endl;
        cout<<"\t\t\t\tSTUDENT ID NUMBER :"<<s.id<<endl<<endl;
        cout<<"\t\t\t\tSTUDENT ROLL NUMBER :"<<s.roll<<endl<<endl;
        cout<<"\t\t\t\tYOUR Numerical Subject Point :"<<s.N<<endl<<endl;
        cout<<"\t\t\t\tYOUR Java Subject Point :"<<s.J<<endl<<endl;
        cout<<"\t\t\t\tYOUR MATH Subject Point :"<<s.M<<endl<<endl;
        cout<<"\t\t\t\tYOUR Algorithm Subject Point :"<<s.A<<endl<<endl;
        //cout<<"\t\t\t\tyour Total Credit :"<<s.sum<<endl<<endl;
        //cout<<"\t\t\t\tSum of your POINT :"<<s.point<<endl<<endl;
        //cout<<"\t\t\t\t CGPA :"<<s.GPA<<endl<<endl;
        cout<<"=================================================================================="<<endl;
        check=true;
    }
    infile.close();
    if(check==false)
    cout<<"\t\t\t\tNO RECORD FOUND..."<<endl<<endl;
    cout<<"press any key to continue....";
    cin.ignore();
    cin.get();
}

void view_Specific(int n)

{
    system("cls");
    student s;
    ifstream infile;
    infile.open("Student_record.txt",ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED...";

        cin.ignore();
        cin.get();
    }
    bool equality=false;
    cout<<"\t\t\t\t==========VIEW A SINGLE STUDENT REPORT==========\n\n";
    while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
    {
        if(s.roll==n)
        {
        cout<<"\t\t\t\t STUDENT NAME :"<<s.name<<endl<<endl;
        cout<<"\t\t\t\t STUDENT ID NUMBER :"<<s.id<<endl<<endl;
        cout<<"\t\t\t\t STUDENT ROLL NUMBER :"<<s.roll<<endl<<endl;
        cout<<"\t\t\t\t YOUR Numerical Subject Point :"<<s.N<<endl<<endl;
        cout<<"\t\t\t\t YOUR Java Subject Point :"<<s.J<<endl<<endl;
        cout<<"\t\t\t\t YOUR MATH Subject Point :"<<s.M<<endl<<endl;
        cout<<"\t\t\t\t YOUR Algorithm Subject Point :"<<s.A<<endl<<endl;
       // cout<<"\t\t\t\t your Total Credit :"<<s.credit<<endl<<endl;
        //cout<<"\t\t\t\t YOUR TOTAL POINT :"<<s.point<<endl<<endl;
        //cout<<"\t\t\t\t CGPA :"<<s.CGPA<<endl<<endl;
        cout<<"\t\t\t\t================================================"<<endl;
        equality=true;
        }
    }
        infile.close();
        if(equality==false)
            cout<<"\t\t\t\tRECORD NOT FOUND..."<<endl;
            cout<<endl;
            cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
}

void result(int n)

{
    system("cls");
    student s;
    ifstream infile;
    infile.open("Student_record.txt",ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
        cin.ignore();
        cin.get();
    }
    bool eq=false;
    cout<<"\t\t\t\t===========VIEW A SINGLE STUDENT RESULT==========\n\n";
    while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
    {
        if(s.roll==n)
        {
        cout<<"\t\t\t\tSTUDENT NAME :"<<s.name<<endl<<endl;
        //cout<<"\t\t\t\t YOUR Numerical Subject Point :"<<s.P<<endl<<endl;
        //cout<<"\t\t\t\t YOUR Java Subject Point :"<<s.J<<endl<<endl;
        //cout<<"\t\t\t\t YOUR MATH Subject Point :"<<s.M<<endl<<endl;
        //cout<<"\t\t\t\t YOUR Algorithm Subject Point :"<<s.A<<endl<<endl;
        cout<<"\t\t\t\t YOUR Total Credit :"<<s.credit<<endl<<endl;
        //cout<<"\t\t\t\tSum of your POINT :"<<s.point<<endl<<endl;
        cout<<"\t\t\t\t YOUR GPA :"<<s.GPA<<endl<<endl;
        cout<<"\t\t\t\t=================================================="<<endl;
        eq=true;
        }
    }
        infile.close();
        if(eq==false)
            cout<<"\t\t\t\tRECORD NOT FOUND..."<<endl;
            cout<<endl;
            cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
}

void modify(int n)

{
    system("cls");
    student s;
    fstream infile;
    infile.open("Student_record.txt",ios::binary|ios::in|ios::out);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
        cin.ignore();
        cin.get();
    }
     bool checker=false;
     cout<<"\t\t\t\t==========MODIFY A REPORT CARD==========\n\n";
     while(!infile.eof() && checker==false)
     {
     infile.read(reinterpret_cast<char*>(&s),sizeof(student));
     {
         if(s.roll==n)
         {
        cout<<"\t\t\t\tSTUDENT NAME :"<<s.name<<endl<<endl;
        cout<<"\t\t\t\tSTUDENT ID NUMBER :"<<s.id<<endl<<endl;
        cout<<"\t\t\t\tSTUDENT ROLL NUMBER :"<<s.roll<<endl<<endl;
        cout<<"\t\t\t\tENTER YOUR Obtained Numerical Subject Point :"<<s.N<<endl<<endl;
        cout<<"\t\t\t\tENTER YOUR  Numerical Subject Credit :"<<s.N_C<<endl<<endl;
        cout<<"\t\t\t\tENTER YOUR Obtained Java Subject Point :"<<s.J<<endl<<endl;
        cout<<"\t\t\t\tENTER YOUR  Java Subject Credit :"<<s.J_C<<endl<<endl;
        cout<<"\t\t\t\tENTER YOUR Obtained MATH Subject Point :"<<s.M<<endl<<endl;
        cout<<"\t\t\t\tENTER YOUR  MATH Subject Credit :"<<s.M_C<<endl<<endl;
        cout<<"\t\t\t\tENTER YOUR Obtained Algorithm Subject Point :"<<s.A<<endl<<endl;
        cout<<"\t\t\t\tENTER YOUR  Algorithm Subject Credit :"<<s.A_C<<endl<<endl;


        cout<<"============================================="<<endl;
        cout<<"\t\tENTER THE NEW INFORMATION"<<endl;
        cout<<"============================================="<<endl;
        cout<<"ENTER YOUR FULL NAME :";
    cin.ignore();
    cin.getline(s.name,100);
    cout<<"ENTER YOUR ID NUMBER : ";
    cin.get(s.id,100);
    cout<<"ENTER YOUR ROLL NUMBER :";
    cin>>s.roll;
    cout<<"ENTER YOUR Obtained Numerical Subject Point :";
    cin>>s.N;
    cout<<"ENTER YOUR  Numerical Subject Credit :";
    cin>>s.N_C;
    cout<<"ENTER YOUR Obtained Java Subject Point :";
    cin>>s.J;
    cout<<"ENTER YOUR  Java Subject Credit :";
    cin>>s.J_C;
    cout<<"ENTER YOUR Obtained MATH Subject Point :";
    cin>>s.M;
    cout<<"ENTER YOUR  MATH Subject Credit :";
    cin>>s.M_C;
    cout<<"ENTER YOUR Obtained Algorithm Subject Point :";
    cin>>s.A;
    cout<<"ENTER YOUR  Algorithm Subject Credit :";
    cin>>s.A_C;
    s.sum=(s.N*s.N_C)+(s.J*s.J_C)+(s.M*s.M_C)+(s.A*s.A_C);
    s.credit=(s.N_C+s.J_C+s.M_C+s.A_C);
    s.GPA=(s.sum/s.credit);
    //cout<<"Enter your Total Credit :";
    //cin>>s.credit;
    //s.point=s.P+s.J+s.M+s.A;
    //s.CGPA=(s.point/s.credit);
    int pos=(-1)*static_cast<int>(sizeof(student));
    infile.seekp(pos,ios::cur);
    infile.write(reinterpret_cast<char *> (&s), sizeof(student));
    cout<<endl;
    cout<<"\t\t\t\tTHE FILE IS SUCCESSFULLY updated"<<endl;
    checker=true;
         }
     }
     }
     infile.close();
         if(checker==false)
            cout<<"\t\t\t\tRECORD NOT FOUND"<<endl;
            cout<<endl;
            cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
  }

  void deleterecord(int n)

  {
     system("cls");
     student s;
     ifstream infile;
     infile.open("Student_record.txt",ios::binary);
     if(!infile)
     {
         cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
         cin.ignore();
         cin.get();
     }
     ofstream outfile;
     outfile.open("Student_record2.txt",ios::binary);
     infile.seekg(0,ios::beg);
     cout<<"\t\t\t\t===========DELETE A REPORT CARD==========\n\n";
     while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
     {
         if(s.roll!=n)
         {
             outfile.write(reinterpret_cast<char*>(&s),sizeof(student));
         }
     }
     infile.close();
     outfile.close();
     remove("Student_record.txt");
     rename("Student_record2.txt","");
     cout<<endl;
     cout<<"\t\t\t\tRECORD SUCCESSFULLY DELETED"<<endl;
     cout<<"press any key to continue...";
     cin.ignore();
     cin.get();
  }





