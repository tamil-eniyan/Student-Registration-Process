#include <bits/stdc++.h>
using namespace std;

class auth{
    public:
//data members
    string line=" "; 
//constructor
     auth()
     {                     //constructor       
    ifstream fsdata ("sdata.txt");               
    
    if (fsdata.is_open())                 //opening from sdata
    {
        cout<<"getting data from file 'sdata.txt'"<<endl;
    }
    else cout << "can't open the sdata.txt";      
    

                                 
    ifstream fedata ("edata.txt");                //opening from edata
    
    if (fedata.is_open()) 
    {
        
           cout<<"getting data from file 'edata.txt' "<<endl;
            
        
        fedata.close(); 
    }
    else cout << "can't open the edata.txt";      
    
    
                                 
    ifstream ffdata ("fdata.txt");       //opening for fdata
    
    if (ffdata.is_open()) 
    {
        
            cout<<"getting data from file 'fdata.txt' "<<endl;
        
        ffdata.close(); 
    }
    else cout << "can't open the fdata.txt";      
    

         
    }

//who fuction

    int who(){                              // to check who is using the program
       string who;
       cout<<endl;
    cout << "      MENU     "<<endl;
    cout << "  1.Student"<<endl;
    cout << "  2.Teacher"<<endl;
    cout << "  3.Finance Dept."<<endl;
    cout << "  4.Admin"<<endl;
    cout << "Enter your choice : ";
    cin>>who;
    
    
    if(who=="1"||who=="2"||who=="3"||who=="4")          //check if the input is right or wrong
        return(stoi(who));                    //right then send the data recived
    else
        return(0);                      //else return 0
    
    
}

int verify()
{       
        string space=" ";
        string tempid;
        string tempp;
        int whoid=0;
        int count=100;
        int i;
        whoid=who();
       
        if(whoid==1)                                    //if student
        {

            cout<<endl<<"Enter the Student ID : ";
            cin>>tempid;
            cout<<endl<<"Enter the password : ";
            cin>>tempp;
            tempid=tempid + space + tempp;
           
           
            ifstream fsdata ("sdata.txt");               
    
            if (fsdata.is_open())                 
            {
                while (! fsdata.eof() ) {

                    getline (fsdata,line); 
                    
            
                    if(line == tempid){
                
                        return(1);
                        break;
                    
                    }
                    if(fsdata.eof()!=0){
                        return(0);
                        break;
                    }
                    
                    
        
                }   fsdata.close();            
            }    
        }

        if(whoid==2)                                    
        {

            cout<<endl<<"Enter the Faculty ID : ";
            cin>>tempid;
            cout<<endl<<"Enter the password : ";
            cin>>tempp;
            tempid=tempid + space + tempp;
           
          
            ifstream ffdata ("fdata.txt");               
    
            if (ffdata.is_open())                 
            {
                while (! ffdata.eof() ) {

                    getline (ffdata,line); 
                    
            
                    if(line == tempid){
                
                        return(2);
                        break;
                    
                    }
                    if(ffdata.eof()!=0){
                        return(0);
                        break;
                    }
                    
                    
        
                }   ffdata.close();            
            }    
        }

        if(whoid==3)                                    
        {

            cout<<endl<<"Enter the Employee ID : ";
            cin>>tempid;
            cout<<endl<<"Enter the password : ";
            cin>>tempp;
            tempid=tempid + space + tempp;
           
            
            ifstream fedata ("edata.txt");               
    
            if (fedata.is_open())                 
            {
                while (! fedata.eof() ) {

                    getline (fedata,line); 
                    
            
                    if(line == tempid){
                
                        return(3);
                        break;
                    
                    }
                    if(fedata.eof()!=0){
                        return(0);
                        break;
                    }
        
                }   fedata.close();            
            }    
        }

        if(whoid==4)                                    
        {

            cout<<endl<<"Enter the Employee ID : ";
            cin>>tempid;
            cout<<endl<<"Enter the password : ";
            cin>>tempp;
            tempid=tempid + space + tempp;
           
            
            ifstream fadmin ("admin.txt");               
    
            if (fadmin.is_open())                 
            {
                while (! fadmin.eof() ) {

                    getline (fadmin,line); 
                    
            
                    if(line == tempid){
                
                        return(4);
                        break;
                    
                    }
                    if(fadmin.eof()!=0){
                        return(0);
                        break;
                    }
        
                }   fadmin.close();            
            }    
        }        

        else{
            cout<<endl<<"Wrong input !!!!!!"<<endl<<"choose from 1,2,3"<<endl;
            return(5);
        }
        

        return(0);
        }

///login function        

int login()
{
    int pointer=0;
    while(pointer==0){
        pointer=verify();
        if(pointer==1){                                                     //login as a student
            cout<<endl<<"Succussfuly logined as a Student"<<endl;
            return(1);
            break;
        }
        else if(pointer==2){                                                //login as a teacher/faculty
            cout<<endl<<"Succussfuly logined as a Faculty"<<endl;
            return(2);
            break;
        }
        else if(pointer==3){                                                 //login as a employee       
            cout<<endl<<"Succussfuly logined as a Finance Dept."<<endl;
            return(3);
            break;
        }
        else if(pointer==4){                                                 //login as a admin       
            cout<<endl<<"Succussfuly logined as a admin"<<endl;
            return(4);
            break;
        }
        else if(pointer==5){                                                 //wrong input     
            pointer=0;
        }
        
        else cout<<endl<<"Either your ID or Password is wrong"<<endl<<"If facing dificulities contact the tech department"<<endl<<"If your a student then call your TG"<<endl;        //wrong password or username
        
    }
    return(0);
}

};










class studentlogin{
    public: 
    string regno,name,semester,year,contactno,email,transactionid;
    string temp,date;
    string tab=("\t");
    char value;


    int studentdatainput(){

            int counter=0;
            int x,y,z;

        while(counter==0){
        cout<<"\nEnter your Regestration Number : ";
        cin>>regno; 
       
        cout<<"\nEnter your Name(without space) : ";
        cin>>name;
       
        cout<<"\nEnter your Semester : ";
        cin>>semester;

        cout<<"\nEnter your year : ";
        cin>>year; 
       
        cout<<"\ncontact no : ";
        cin>>contactno;
       
        cout<<"\nEnter your email : ";
        cin>>email;

        cout<<"\nEnter the transactionid : ";
        cin>>transactionid; 

//check
        cout<<"\n I this the data you have entered ";
        cout<<"\nEnter your Regestration Number : "<<regno;   
        cout<<"\nEnter your Name : "<<name;    
        cout<<"\nEnter your Semester : "<<semester;
        cout<<"\nEnter your year : "<<year;
        cout<<"\ncontact no : "<<contactno;
        cout<<"\nEnter your email : "<<email;
        cout<<"\nEnter the transactionid : "<<transactionid;
        cout<<"\n[Y/N] : ";
        cin>>value;

        if(value == 'y'||value=='Y'){
            counter=2;
        }
      
        

        if(counter==2){
        time_t now = time(0);
        date=ctime(&now);
        
        
        x=transactioncheck();
            if(x==1){

                y=datacheck();
                if(y==1){

                        ofstream file1("reg.txt",ios::app);
                        file1<<"\n"<<regno;   //write data to the file student
                        file1.close();

                        cout<<endl<<"Your data have been taken :) "<<endl;
                        ofstream file("registeredstudents.txt",ios::app);
                        file<<"\n"<<regno<<"\t"<<name<<"\t"<<date;   //write data to the file registered students.txt
                        file.close();
                        return (1);
                }
                else
                {
                    cout<<endl<<"The data you inputed is wrong"<<endl<<"if facing diffulcaties call your TG"<<endl;
                    return(0);
                }
            }
            
            else{
                cout<<"Transaction id is wrong";
                return(0);
            }}
        }

    return (0);
            
    }


    int datacheck(){
        string line,temp;
        //temp=regno+"\t"+name+"\t"+semester+"\t"+year+"\t"+contactno+"\t"+email;
         ifstream data ("studentdata.txt");               
    
            if (data.is_open())                 
            {
                while (! data.eof() ) {

                    getline (data,line); 
                    
                    if(line == regno+"\t"+name+"\t"+semester+"\t"+year+"\t"+contactno+"\t"+email){
                        
                        cout<<line;
                        cout<<regno+"\t"+name+"\t"+semester+"\t"+year+"\t"+contactno+"\t"+email;


                        return(1);
                        break;
                    
                    }
                    if(data.eof()!=0){
                        return(0);
                        break;
                    }
        
                }   data.close();            
            } return(0);   
    }


    int transactioncheck(){

        string line,temp1;
        temp1=regno+"\t"+transactionid;
         ifstream feedata ("studentfeedata.txt");               
    
            if (feedata.is_open())                 
            {
                while (! feedata.eof() ) {

                    getline (feedata,line); 
                    
            
                    if(line == temp1){
                
                        return(1);
                        break;
                    
                    }
                    if(feedata.eof()!=0){
                        return(0);
                        break;
                    }
        
                }   feedata.close();            
            }   
            return(0); 
    }


/*
    int backlog()
    {   

        int n=0;
        int i=0;
        string backlogdata;
        cout<<"how many Rejoining Subjects you have : ";
        cin>>n;
        string blsubj[n];
        for(i = 0;i<=n-1;i++ )
        {
            cout<<"Enter the subject code of rejoining subject "<<i<<" : ";
            cin>>blsubj[i];
        }
        ofstream file("studentbacklod.txt",ios::app);
   
      file<<regno<<"\t";   //write back lofdata to the file studentbacklog.txt

        for(i = 0;i<=n;i++ )
        {
            file<<blsubj[i]<<"\t";
        }
      file.close();

      cout<<endl<<"Your data have been taken :) "<<endl;
    return (0);

    }*/

    int regestrationprocess(){
                char input;
                int i=0;
                int l=0;
                while(i==0){
                    cout<<"\n                  Menu                     \n";
                    cout<<"\n 1.Form A(No backlog/rejoining subjects)";
                    cout<<"\n 2.Form B(backlog/rejoining subjects)";
                    cout<<"\n Your choise : ";
                    cin>>input;
                
                    if(input=='a'||input=='A'){
                            while(l==0){
                        l=studentdatainput();
                            }
                        i=2;
                    }
                    else if(input=='b'||input=='B'){
                                while(l==0){
                        l=studentdatainput();
                            }
                            cout<<"Mail the list of rejoining subjects to your TG ";
                                i=3;
                    }
                    else{
                        cout<<"\n wrong input!!!"<<endl;
                    }
                }
                return(0);
    }

};


class teacher{
    public:

    int menu(){
                int input;
                int i=0;
                int l=0;
                while(i==0){
                    cout<<"\n                  Menu                     \n";
                    cout<<"\n 1.Check Who all have registered";
                    cout<<"\n 2.Student detailes";
                    cout<<"\n 3.password check";
                    cout<<"\n 4.exit";
                    cout<<"\n Your choise : ";
                    cin>>input;

                    switch(input){

                        case 1:
                            {
                               check_reg();
                               break;
                            }
                            case 2:
                            {
                               studentdet() ;     
                               break;
                            }
                            case 3:
                            {
                                password_check() ;     
                               break;
                            }
                            case 4:
                            {
                               i==100;
                               cout<<"logdout";
                               return (2);
                               break;
                            }
                            default : cout<<"Wrong input!!";

                    }
                }
                return(0);
    }


    int studentdet()
    {
        string name ;
        ifstream dataFile("studentdata.txt");
        while (!dataFile.fail() && !dataFile.eof() )
        {
            dataFile >> name ;
            cout << name << endl;
        }   
        return 0;                 

    }

    int password_check()
    {
        string name ;
        ifstream dataFile("sdata.txt");
        while (!dataFile.fail() && !dataFile.eof() )
        {
            dataFile >> name ;
            cout << name << endl;
        }    
        return 0;                

    }

    int check_reg()
    {
        string name ;
        ifstream dataFile("registeredstudents.txt");
        while (!dataFile.fail() && !dataFile.eof() )
        {
            dataFile >> name ;
            cout << name << endl;
        }                    
    return 0;
    }


};


class finance{
    public:

int menu(){
                int input;
                int i=0;
                int l=0;
                while(i==0){
                    cout<<"\n                  Menu                     \n";
                    cout<<"\n 1.Read transacrtion file";
                    cout<<"\n 2.append transaction file";
                    cout<<"\n 3.exit";
                    cout<<"\n Your choise : ";
                    cin>>input;

                    switch(input){

                        case 1:
                            {
                                tranc();
                                break;
                            }
                            case 2:
                            {
                                appendtranc() ;     
                                break;
                            }
                            case 3:
                            {
                                i==100;
                                cout<<"logdout";
                                return (2);
                                break;
                            }
                            case 4:
                            {
                               
                            }
                            default : cout<<"Wrong input!!";

                    }
                }
                return(0);
    }





    int tranc(){

        string name ;
        ifstream dataFile("studentfeedata.txt");
        while (!dataFile.fail() && !dataFile.eof() )
        {
            dataFile >> name ;
            cout << name << endl;
        }                    
    return 0;

    }


    int appendtranc(){

         int regno = 0;
         int trancid = 0;
            cout<<"Enter the regestration no of the student : ";
            cin>>regno;
            cout<<"Enter the transaction detailes : ";
            cin>>trancid;

                        ofstream file1("reg.txt",ios::app);
                        file1<<regno<<" "<<trancid<<endl;   //write data to the file student
                        file1.close();
    return 0;

    }

};


class admin{
public:

    int menu(){
                int input;
                int i=0;
                int l=0;
                while(i==0){
                    cout<<"\n                  Menu                     \n";
                    cout<<"\n 1.Read student password file";
                    cout<<"\n 2.append student password file";
                    cout<<"\n 3.Read faculty password file";
                    cout<<"\n 4.append faculty password file";
                    cout<<"\n 5.Read employee password file";
                    cout<<"\n 6.append employee password file";

                    cout<<"\n 7.exit";
                    cout<<"\n Your choise : ";
                    cin>>input;

                    switch(input){

                        case 1:
                            {
                                sdata();
                                break;
                            }
                        case 2:
                            {
                                appendsp()
                                break;
                            }    
                        case 3:
                            {
                                fdata();
                                break;
                            }    
                        case 4:
                            {
                                appendfp()
                                break;
                            }        
                        case 5:
                            {
                                edata();
                                break;
                            }
                        case 6:
                            {
                                appendep()
                                break;
                            }           
                    
                            case 7:
                            {
                                i==100;
                                cout<<"logdout";
                                return (2);
                                break;
                            }
                            case 4:
                            {
                               
                            }
                            default : cout<<"Wrong input!!";

                    }
                }
                return(0);
    }


int sdata(){

        string name ;
        ifstream dataFile("sdata.txt");
        while (!dataFile.fail() && !dataFile.eof() )
        {
            dataFile >> name ;
            cout << name << endl;
        }                    
    return 0;

    }
    int fdata(){

        string name ;
        ifstream dataFile("fdata.txt");
        while (!dataFile.fail() && !dataFile.eof() )
        {
            dataFile >> name ;
            cout << name << endl;
        }                    
    return 0;

    }
    int edata(){

        string name ;
        ifstream dataFile("edata.txt");
        while (!dataFile.fail() && !dataFile.eof() )
        {
            dataFile >> name ;
            cout << name << endl;
        }                    
    return 0;

    }
    
    int appendsp(){

         int id = 0;
         int pd = 0;
            cout<<"Enter the regestration no of the student : ";
            cin>>id;
            cout<<"Enter the password : ";
            cin>>pd;

                        ofstream file1("sdata.txt",ios::app);
                        file1<<id<<" "<<pd<<endl;   
                        file1.close();
    return 0;

    }

    int appendfp(){

         int id = 0;
         int pd = 0;
            cout<<"Enter the Faculty id of the student : ";
            cin>>id;
            cout<<"Enter the password : ";
            cin>>pd;

                        ofstream file1("fdata.txt",ios::app);
                        file1<<id<<" "<<pd<<endl;   
                        file1.close();
    return 0;

    }

    int appendep(){

         int id = 0;
         int pd = 0;
            cout<<"Enter the Employee id of the student : ";
            cin>>id;
            cout<<"Enter the password : ";
            cin>>pd;

                        ofstream file1("edata.txt",ios::app);
                        file1<<id<<" "<<pd<<endl;   
                        file1.close();
    return 0;

    }


    
};


int main()
{
      int test=100;  
      auth signin;
      
        test = signin.login();
       
        if(test==1){
            studentlogin readdata;
            test = readdata.regestrationprocess();  
            
        }
        else if(test==2){
            teacher menu1;
            test = menu1.menu();
            cout<<"Teacher";
        }
        else if(test==3){
            finance finc;
            test = finc.menu();
            cout<<"Finance Dept.";
        }
        else if(test==4){
            admin menu;
            test = menu.menu;
            cout<<"Admin";

        }

        

    return 0;   
}