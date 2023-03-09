#include<iostream>
#include<fstream>

using namespace std;
int ID;
class student
{
public:
    int id,age;
    string name;
    string stream;



    


    void printAll()
    {
    ifstream fin;//for read the file
    fin.open("E:/ccpp projects/student management/student.txt");
    student s;
    while(!fin.eof())//eof(end of the file ) it returns true if file ended and returnd false if file is not ended
    {
        fin>>s.id;
        fin.ignore();//for clean buffer in file
        getline(fin,s.name);
        fin>>s.age;
        fin.ignore();
        getline(fin,s.stream);


        cout<<"\nID  =  "<<s.id;
        cout<<"\nName  =  "<<s.name;
        cout<<"\nAge  =  "<<s.age;
        cout<<"\nstream  =  "<<s.stream;
         cout<<endl;
         cout<<endl;

    }
    fin.close();


    }



   void searchStudent( int id )
   {

    ifstream fin;//for read the file
    fin.open("E:/ccpp projects/student management/student.txt");
    student s;
    while(!fin.eof())//eof(end of the file ) it returns true if file ended and returnd false if file is not ended
    {
        fin>>s.id;
        fin.ignore();//for clean buffer in file
        getline(fin,s.name);
        fin>>s.age;
        fin.ignore();
        getline(fin,s.stream);

        if(id==s.id)
        {
            // cout<<"\n_______________________________________\n";
             cout<<"\nID  =  "<<s.id;
             cout<<"\nName  =  "<<s.name;
             cout<<"\nAge  =  "<<s.age;
             cout<<"\nstream  =  "<<s.stream;
             //cout<<"\n_______________________________________\n";
             break;

        }

    }
    fin.close();

   }
   void updateStudent(int id)//combination of two functions deleteStudent()+addStudent()
   {
    deleteStudent(id);
    cout<<"\nenter details of the student:\n";
    cout<<"Enter name: "<<endl;
        cin.get();//for cleaning the buffer of keyboard
        getline(cin,name);
        cout<<"Enter your age: "<<endl;
        cin>>age;
        cout<<"Enter your stream: "<<endl;
        cin.get();
        getline(cin,stream);


        ofstream fout;//for write inside the file
        fout.open("E:/ccpp projects/student management/student.txt",ios::app);
        fout<<"\n"<<id;
        fout<<"\n"<<name;
        fout<<"\n"<<age;
        fout<<"\n"<<stream;
        fout.close();

        fout.open("E:/ccpp projects/student management/id.txt",ios::app);
        fout<<"\n"<<ID;
        fout.close();

        cout<<"record added succesfully"<<endl;;

   }
   void deleteStudent(int id)
   {
    ifstream fin;
    fin.open("E:/ccpp projects/student management/student.txt");
    ofstream fout;
    fout.open("E:/ccpp projects/student management/temp.txt");

    student s;
    while(!fin.eof())
    {
        fin>>s.id;
        fin.ignore();//for clean buffer in file
        getline(fin,s.name);
        fin>>s.age;
        fin.ignore();
        getline(fin,s.stream);

        if(id!=s.id)//transfer content from old file to new file temp accept that id which we are going to delete
        {
        fout<<"\n"<<s.id;
        fout<<"\n"<<s.name;
        fout<<"\n"<<s.age;
        fout<<"\n"<<s.stream;
        }
    }
   fin.close();
   fout.close();

   remove("E:/ccpp projects/student management/student.txt");
   rename("E:/ccpp projects/student management/temp.txt","E:/ccpp projects/student management/student.txt");

   cout<<"record deleted succesfully";
   }



};

int main()
{
    int choice;
    ifstream fin;
    fin.open("E:/ccpp projects/student management/id.txt");
    if(!fin)
    {
        cout<<"file not found";
    }
    else
    {
        while(!fin.eof())
        {
            fin>>ID;
        }
    }
    fin.close();

    while(true)
    {
        cout<<"\n_______________________________________\n";
        cout<<"enter your choice:"<<endl;
        cout<<"1.Add student"<<endl;
        cout<<"2.print all student"<<endl;
        cout<<"3.search a student"<<endl;
        cout<<"4.update  student"<<endl;
        cout<<"5.Delete a student"<<endl;
       // cout<<"\n_______________________________________\n";

        cin>>choice;
        student s;
        switch(choice)
        {
        case 1:
            s.addStudent();
            break;
        case 2:
            s.printAll();
            break;
        case 3:
            int id;
            cout<<"\nEnter student's id:";
            cin>>id;
            s.searchStudent(id);
            break;

        case 4:
            cout<<"\nEnter student's id:";
            cin>>id;
            s.updateStudent(id);
            break;
        case 5:
            cout<<"\nEnter student's id:";
            cin>>id;
            s.deleteStudent(id);

            break;


        }
    }
    return 0;
}
