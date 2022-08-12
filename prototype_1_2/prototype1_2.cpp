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
    cout << "Enter your choice : ";
    cin>>who;
    
    
    if(who=="1"||who=="2"||who=="3")          //check if the input is right or wrong
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
        else{
            cout<<endl<<"Wrong input !!!!!!"<<endl<<"choose from 1,2,3"<<endl;
            return(4);
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
        else if(pointer==4){                                                 //login as a employee       
            pointer=0;
        }
        
        else cout<<endl<<"Either your ID or Password is wrong"<<endl<<"If facing dificulities contact the tech department"<<endl<<"If your a student then call your TG"<<endl;        //wrong password or username
        
    }
    return(0);
}

};




int main()
{
      int test=100;  
      auth signin;
        test = signin.login();
        if(test==1){
            cout<<"student";
        }
        else if(test=2){
            cout<<"Teacher";
        }
        else if(test=3){
            cout<<"Finance Dept.";
        }
    return 0;   
}