#include<bits/stdc++.h>
using namespace std;
#define ws "\t"
class employee{
    public:
    string name,id;
    int age;
    double salary;
    int yearsofexp;
    string salarygivenornot;
};

void add_employee(){
    employee e;
    cout<<"enter the employee details: "<<endl;
    cout<<"id: ";
    cin>>e.id;
    cout<<"name: ";
    cin>>e.name;
    cout<<"age: ";
    cin>>e.age;
    cout<<"Years of working together: ";
    cin>>e.yearsofexp;
    cout<<"salary: ";
    cin>>e.salary;
    cout<<"this month salary recieved or not: ";
    cin>>e.salarygivenornot;
    //fflush(stdout);
    fstream f;
    f.open("data.txt",ios::out | ios::app);
    f<<e.id<<endl;
    f<<e.name<<endl;
    f<<e.age<<endl;
    f<<e.yearsofexp<<endl;
    f<<e.salary<<endl;
    f<<e.salarygivenornot<<endl;
    f.close();
    
}

void delete_employee(string id){
    fstream f1;
    f1.open("data.txt",ios::in);
    fstream f2;
    f2.open("tem2.txt",ios::out);
    string line;
    bool flag = false;
    while(getline(f1,line)){
        if(line == id){
            for(int i=0;i<6;i++){
                getline(f1,line);
            }
            flag = true;
        }
        if(line!="")
            f2<<line<<endl;
    }
    if(flag==false){
        cout<<"There is no employee with the given id to delete."<<endl;
    }
    else{
        cout<<"The employee record is deleted from the database."<<endl;
    }
    f1.close();
    f2.close();
    remove("data.txt");
    rename("tem2.txt","data.txt");
    cin.get();
    
}

void display_all(){

    fstream f;
    string line;
    f.open("data.txt",ios::in);
    getline(f,line);
    if(line==""){
        cout<<"There are no records to display."<<endl;
        f.close();
	    cin.get();
        return ;
    }
    f.close();
    
    f.open("data.txt",ios::in);
    
    cout<<"The total employee list:"<<endl;
    while(getline(f,line)){
        cout<<"Id: "<<line<<ws;
        getline(f,line);
        cout<<"\tName: "<<line<<endl;
        for(int i = 0;i<4;i++){
            getline(f,line);
        }
    }
    f.close();
	cin.get();
    
}

void display_sp(string id){
    fstream f1;
    f1.open("data.txt",ios::in);
    string line;
    bool flag = false;
    while(getline(f1,line)){
        if(line == id){
            flag = true;
            cout<<"The employees details are: "<<endl;
            cout<<"\tId: "<<line<<endl;
            getline(f1,line);
            cout<<"\tName: "<<line<<endl;
            getline(f1,line);
            cout<<"\tAge: "<<line<<endl;
            getline(f1,line);
            cout<<"\tYear of working together: "<<line<<endl;
            getline(f1,line);
            cout<<"\tSalary: "<<line<<endl;
            getline(f1,line);
            cout<<"\tThis month's Salary recived or not: "<<line<<endl;
            break;
        }
        else
         for(int i = 0;i<5;i++){
            getline(f1,line);
            }
    }
    if(flag==false){
        cout<<"There is no employee with the given id."<<endl;
    }
    f1.close();
    cin.get();
    
}

void modify_employee(string id){
    employee e;
    fstream f1;
    f1.open("data.txt",ios::in);
    fstream f2;
    f2.open("tem2.txt",ios::out);
    string line;
    bool flag = false;
    while(getline(f1,line)){
        if(line == id){
            f2<<line<<endl;
            for(int i=0;i<6;i++){
                getline(f1,line);
            }
            flag = true;
            cout<<"enter the employee details: "<<endl;
            cout<<"name: ";
            cin>>e.name;
            cout<<"age: ";
            cin>>e.age;
            cout<<"Years of working together: ";
            cin>>e.yearsofexp;
            cout<<"salary: ";
            cin>>e.salary;
            cout<<"this month salary recieved or not: ";
            cin>>e.salarygivenornot;
            f2<<e.name<<endl;
            f2<<e.age<<endl;
            f2<<e.yearsofexp<<endl;
            f2<<e.salary<<endl;
            f2<<e.salarygivenornot<<endl;
        }
        if(line!="")
            f2<<line<<endl;
    }
    if(flag==false){
        cout<<"There is no employee with the given id to modify."<<endl;
    }
    else{
        cout<<"The employee record is modified from the database."<<endl;
    }
    cin.get();
    f1.close();
    f2.close();
    remove("data.txt");
    rename("tem2.txt","data.txt");
}
void print_payroll(string id){
    
    fstream f1;
    f1.open("data.txt",ios::in);
    string line;
    bool flag = false;
    while(getline(f1,line)){
        if(line == id){
            flag = true;
            cout<<"Employee Id: "<<line<<endl;
            getline(f1,line);
            cout<<"\nName: "<<line<<endl;
            getline(f1,line);
            cout<<"\nAge: "<<line<<endl;
            getline(f1,line);
            cout<<"\nYear of working together: "<<line<<endl;
            getline(f1,line);
            cout<<"\nBasic Salary: "<<line<<endl;
            int x=0;
            for(int i=0;i<line.size();i++){                
                x = x*10 + (int(line[i])-48);
            }
            cout<<endl;
            cout<<"\n\t\tAllowances(18%): "<<x*0.18<<endl;
            cout<<"\t\tDeductions(6%): "<<x*0.06<<endl;
            cout<<"\nNet Total Salary is: "<<x+x*0.12<<endl;
            getline(f1,line);
            cout<<"\n\tThis Pay Slip is authorised by SRMAP University. "<<endl;
            break;
        }
    }
    if(flag==false){
        cout<<"There is no employee with the given id to delete."<<endl;
    }
    f1.close();
    cin.get();
    
}
void intro()
{
	cout<<"\n\n\n\t\t  SRM PAYROLL";
	cout<<"\n\n\t\t  MANAGEMENT";
	cout<<"\n\n\t\t  PROJECT";

	cin.get();
}
int main(){
    employee e;
	intro();
    char inp;
	do
	{
		
		cout<<"\n\n\n\tMAIN MENU";
        cout<<"\n\n\t1.CREATE EMPLOYEE RECORD";
        cout<<"\n\n\t2.DISPLAY ALL EMPLOYEE RECORDS";
        cout<<"\n\n\t3.SEARCH EMPLOYEE RECORD ";
        cout<<"\n\n\t4.MODIFY EMPLOYEE RECORD";
        cout<<"\n\n\t5.DELETE EMPLOYEE RECORD";
        cout<<"\n\n\t6.PRINT PAY SLIP OF THE EMPLOYEE";
        cout<<"\n\n\t7.EXIT";
        cout<<"\n\n\tPlease Enter Your Choice (1-7) ";
        cin>>inp;
        
        string idinp;
        switch(inp)
        {
            case '1':	add_employee(); break;
            case '2':	display_all(); break;
            case '3':	cout<<"\n\n\tPlease Enter The id number "; cin>>idinp;
                        display_sp(idinp); break;
            case '4':	cout<<"\n\n\tPlease Enter The id number "; cin>>idinp;
                        modify_employee(idinp);break; 
            case '5':	cout<<"\n\n\tPlease Enter The id number "; cin>>idinp;
                        delete_employee(idinp);break;
            case '6':   cout<<"\n\n\tPlease Enter The id number "; cin>>idinp;
                        print_payroll(idinp);break;
            case '7':	break;
        default:	cout<<"\n\n\tPlease enter a vaild option to proceed."<<endl; cin.get();
        }
    }while(inp!='7');
	
    return 0;
}