#include <bits/stdc++.h>
using namespace std;
class auth{
    public:
//data members
    string sid[100];    //student id
    string eid[100];    //employee id
    string sp[100];     //student password
    string ep[100];     //employee password
    string fid[100];    //faculty id
    string fp[100];     //faculty password
    short loop=0;
    string line; 
//constructor
     auth(){                     //constructor       
    ifstream fsid ("sid.txt");               //copy from sid.txt
    
    if (fsid.is_open()) 
    {
        while (! fsid.eof() ) 
        {
            getline (fsid,line); 
            sid[loop] = line;
            loop++;
            cout<<"getting data from file "<<endl<<sid[loop]<<endl;
        }
        fsid.close(); 
    }
    else cout << "can't open the sid.txt";      //end of copiying form sid.txt
    

                                 
    ifstream feid ("eid.txt");                //copy from eid.txt
    
    if (feid.is_open()) 
    {
        loop=0;
        while (! feid.eof() ) 
        {
            getline (feid,line); 
            eid[loop] = line;
            loop++;
            cout<<"getting data from file "<<endl<<eid[loop]<<endl;
        }
        feid.close(); 
    }
    else cout << "can't open the eid.txt";      //end of copying from eid.txt
    
    
                                 
    ifstream fep ("ep.txt");       //copying for ep.txt
    
    if (fep.is_open()) 
    {
        loop=0;
        while (! fep.eof() ) 
        {
            getline (fep,line); 
            ep[loop] = line;
            loop++;
        }
        fep.close(); 
    }
    else cout << "can't open the ep.txt";       //end of copying from eid.txt
    

                                //copying from sid.txt
    ifstream fsp ("sp.txt"); 
    
    if (fsp.is_open()) 
    {
        loop=0;
        while (! fsp.eof() ) 
        {
            getline (fsp,line); 
            sp[loop] = line;
            loop++;
        }
        fsp.close(); 
    }
    else cout << "can't open the sp.txt";       //end of copying from sid.txt
    

                                //copying from fid.txt
    ifstream ffid ("fid.txt"); 
    
    if (ffid.is_open()) 
    {
        loop=0;
        while (! ffid.eof() ) 
        {
            getline (ffid,line); 
            fid[loop] = line;
            loop++;
        }
        ffid.close(); 
    }
    else cout << "can't open the ffid.txt";       //end of copying from fp.txt
    
    //copying from fp.txt
    ifstream ffp ("fp.txt"); 
    
    if (ffp.is_open()) 
    {
        loop=0;
        while (! ffp.eof() ) 
        {
            getline (ffp,line); 
            fp[loop] = line;
            loop++;
        }
        ffp.close(); 
    }
    else cout << "can't open the ffp.txt";       //end of copying from fp.txt


    }

//who fuction

    int who(){                              // to check who is using the program
       int who;
       cout<<endl;
    cout << "      MENU     "<<endl;
    cout << "  1.Student"<<endl;
    cout << "  2.Teacher"<<endl;
    cout << "  3.Finance Dept."<<endl;
    cout << "Enter your choice : ";
    cin>>who;
    
    if(who==1||who==2||who==3)          //check if the input is right or wrong
        return(who);                    //right then send the data recived
    else
        return(0);                      //else return 0
    
}

int verify()
{
        string tempid;
        string tempp;
        int whoid;
        int count=100;
        int i;
        int j;
        whoid=who();
        
        if(whoid==1)                                    //if student
        {

            cout<<endl<<"Enter the Student ID : ";
            cin>>tempid;
            cout<<endl<<"Enter the password : ";
            cin>>tempp;

            for(i = 0; i < count; i++){
            
                if(sid[i] == tempid){
                
                    if(sp[i] == tempp){
                        return(1);
                        break;
                    }
                    else{
                        return(0);
                        break;
                    }
                }
                if(i == count){
                return(0);
                break;
                }
            }    
        }

        else if(whoid==3)                                        // if an employee
        {

            cout<<endl<<"Enter the Employment ID : ";
            cin>>tempid;
            cout<<endl<<"Enter the password : ";
            cin>>tempp;

            for(i = 0; i < count; i++){
            
                if(eid[i] == tempid){
                
                    if(ep[i] == tempp){
                        return(3);
                        break;
                    }
                    else{
                        return(0);
                        break;
                    }
                }
                if(i == count){
                return(0);
                break;
                }
            }    
        }
            

        else if(whoid==2)                                        // if an faculty
        {

            cout<<endl<<"Enter the Faculty ID : ";
            cin>>tempid;
            cout<<endl<<"Enter the password : ";
            cin>>tempp;

            for(i = 0; i < count; i++){
            
                if(fid[i] == tempid){
                
                    if(fp[i] == tempp){
                        return(2);
                        break;
                    }
                    else{
                        return(0);
                        break;
                    }
                }
                if(i == count){
                return(0);
                break;
                }
            }    
        }


        else{                       //wrong input
            cout<<endl<<"Wrong input!!!";
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
        else if(pointer==4){                                                  //wrong choice  
            cout<<"Choose either 1 , 2 or 3 !!!!"<<endl;
            pointer=0;
        }
        else cout<<endl<<"Either ID id password is wrong"<<endl<<"If facing dificulities contact the tech department"<<endl;        //wrong password or username
        
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