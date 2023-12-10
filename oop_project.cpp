#include<iostream>
#include <fstream>
#include<string.h>
using namespace std;

class team1 {
    public:
        static int noOfPlayers1,pointsA;                      //static members 
        string name[7];
        int i;

        virtual void title() {                                 //Virtual function used[Polymorphism]
            cout<<"This is info of Team A players "<<endl;
        }

        // team1() {                                              //Default constructor      
        //     cout<<"Enter names of players of team A :"<<endl;
        //     for(i=0;i<7;i++) {
        //         cin>>name[i];
        //     }
        //     cout<<"Players of team A are :"<<endl;
        //     for(i=0;i<7;i++) {
        //         cout<<name[i]<<endl;
        //     }
        // }

       

        
};

class team2 {
    public:
        static int noOfPlayers2,pointsB;                            //static members 
        string name[7];
        int i;
        // team2() {                                                    //Default constructor
        //     cout<<"Enter names of players of team B :"<<endl;
        //     for(i=0;i<7;i++) {
        //         cin>>name[i];
        //     }
        //     cout<<"Players of team A are :"<<endl;
        //     for(i=0;i<7;i++) {
        //         cout<<name[i]<<endl;
        //     }
        // }
};

int team1::noOfPlayers1=7;
int team2::noOfPlayers2=7;

int team1::pointsA=0;
int team2::pointsB=0;

class pointings:public team1,public team2 {                           //Multiple Inheritance
    
    public:
        inline void line();                                            //INLINE FUNCTION
        void title () {
            line();
            cout<<"This is Kabaddi Match Points Table"<<endl;
            data();
            
            
            
    }  

        
    
        int raid,glitch=0;
        string isBonus1,isBonus2,tackle,isSuperTackle;
        string whoseraid,str;
        
    
        
        
        
        /* code */
        void data() {
            int choice;
           do 
         {
                cout<<"Enter 1 for entry in points table :"<<endl;
                cout<<"Enter zero to exit\n";
                cin>>choice;
        try{                                                           //    Exception Handling
        
        if(cin.fail())
        {
            
            throw choice;
        }
        
    }
    
         catch(int choice )
        {   

            cout<<"****************** W R O N G   I N P U T ************************"<<endl;
            choice = 0;
            glitch=1;
        
        }
                switch(choice)
                case 1: 
                {
            cout<<"Enter team who is going to raid"<<endl;
            cin>>whoseraid;
            
       // try{


        // if (whoseraid=="a" || whoseraid!="A"||whoseraid!="b" || whoseraid!="B")
        // {
        //     throw whoseraid;
        // }
        
        
        
        
        
        
    
        // }
        //  catch(string whoseraid)
        // {   

        //     cout<<"****************** W R O N G   I N P U T ************************"<<endl;
            
        //     cout<<"**************** Technical  error Equal points given *********************"<<endl;

        //     pointsA++;
        //     pointsB++;

            
            
        
        // }
            

            if(whoseraid=="a" || whoseraid=="A")
        {
            
             cout<<"Enter raid points taken by the player : ";
                cin>>raid;
                cout<<"Whether player touched the bonus line , if yes then enter yes else enter no : ";
                cin>>isBonus1;
                if(raid == 0 ) {
                    cout<<"Does player get knocked out , yes or no :";
                    cin>>tackle;
                }
           
           
            if(raid>0 && raid<3) {
                pointsA+=raid;
                while(raid>0 && noOfPlayers1<=7 && noOfPlayers2 >= 0) {
                   if(noOfPlayers1<7) {
                    noOfPlayers1++;
                        if(noOfPlayers1 == 7) {
                            break;
                        }
                    }
                    if(noOfPlayers2>0) {
                    noOfPlayers2--;
                    }
                    else if(noOfPlayers2==0) {
                        cout<<endl<<"*****************************Team B all out*******************************"<<endl;
                        pointsA+=3;
                        break;
                    }
                   
                    raid--;
                }
            }
            else if (raid >= 3 && raid <= 7) {
                cout<<endl<<"*************************************SUPER RAID*****************************************"<<endl;
                pointsA+=raid;
                while(raid>0 && noOfPlayers1<=7 ) {
                   if(noOfPlayers1<7) {
                        noOfPlayers1++;
                    if(noOfPlayers1 == 7) {

                            break;
                        }
                    }
                    if(noOfPlayers2>0) {
                    noOfPlayers2--;
                    }
                    else if(noOfPlayers2==0) {
                        cout<<endl<<"********************************************Team B all out***********************************"<<endl;
                        pointsA+=3;
                        break;
                    }
                   
                    raid--;
                }
            }
           

            if(isBonus1=="Yes" || isBonus1=="YES" || isBonus1=="yes") {
                pointsA++;
            }

           
            if((tackle=="Yes" || tackle=="YES" || tackle=="yes" ) && noOfPlayers2<=3 ) {
                cout<<endl<<"**********SUPER TACKLE**********"<<endl;
                pointsB+=2;
                noOfPlayers1--;
                if(noOfPlayers1==0) {
                        cout<<endl<<"**********Team A all out**********"<<endl;
                        pointsB+=3;
                        noOfPlayers1+=7;
                       
                    }
                if(noOfPlayers2<7) {
                    noOfPlayers2++;
                }


            }
            else if(tackle=="Yes" || tackle=="YES" || tackle=="yes" ) {
                noOfPlayers1--;
                if(noOfPlayers1==0) {
                        cout<<endl<<"**********Team A all out**********"<<endl;
                        pointsB+=3;
                        noOfPlayers1+=7;
                       
                    }
                pointsB++;
                if(noOfPlayers2<7) {
                    noOfPlayers2++;
                }
                }
               

        }      
            
            else if(whoseraid=="b" || whoseraid=="B")
            {
                cout<<"Enter raid points taken by the player : ";
                cin>>raid;
                cout<<"Whether player touched the bonus line , if yes then enter yes else enter no : ";
                cin>>isBonus2;
                if(raid == 0 ) {
                    cout<<"Does player get knocked out , yes or no :";
                    cin>>tackle;
                }

            
            if(raid>0 && raid<3) {
                pointsB+=raid;
                while(raid>0 && noOfPlayers2<=7 && noOfPlayers1 >= 0) {
                   
                    if(noOfPlayers2<7) {
                    noOfPlayers2++;
                        if(noOfPlayers2 == 7) {
                            break;
                        }
                    }
                    if(noOfPlayers1>0) {
                    noOfPlayers1--;
                    }
                    else if(noOfPlayers1==0) {
                        cout<<endl<<"**********Team A all out**********"<<endl;
                        pointsB+=3;
                        break;
                    }
                   
                    raid--;
                }
            }
            else if (raid >= 3 && raid <= 7) {
                cout<<"**********SUPER RAID**********"<<endl;
                pointsB+=raid;
                while(raid>0 && noOfPlayers2<=7 ) {
                   
                    if(noOfPlayers2<7) {
                    noOfPlayers2++;
                        if(noOfPlayers2 == 7) {
                            break;
                        }
                    }
                    if(noOfPlayers1>0) {
                    noOfPlayers1--;
                    }
                    else if(noOfPlayers1==0) {
                        cout<<endl<<"**********Team A all out**********"<<endl;
                        pointsB+=3;
                        break;
                    }
                   
                    raid--;
                }
            }
           

            if(isBonus2=="Yes" || isBonus2=="YES" || isBonus2=="yes") {
                pointsB++;
            }

           
            if((tackle=="Yes" || tackle=="YES" || tackle=="yes" ) && noOfPlayers1<=3 ) {
                cout<<endl<<"**********SUPER TACKLE**********"<<endl;
                pointsA+=2;
                noOfPlayers2--;
                if(noOfPlayers2==0) {
                        cout<<endl<<"**********Team B all out**********"<<endl;
                        pointsA+=3;
                        noOfPlayers2+=7;
                       
                    }
                if(noOfPlayers1<7) {
                    noOfPlayers1++;
                }


            }
            else if(tackle=="Yes" || tackle=="YES" || tackle=="yes" ) {
                noOfPlayers2--;
                if(noOfPlayers2==0) {
                        cout<<endl<<"**********Team B all out**********"<<endl;
                        pointsA+=3;
                        noOfPlayers2+=7;
                       
                    }
                pointsA++;
                if(noOfPlayers1<7) {
                    noOfPlayers1++;
                }
                }
            }
                display();

                break;
                }
         }while(choice !=0);   
        }
      
        
        
            
        

    void display() {
        line();
        cout<<"          Team A                         Team B          "<<endl;
        cout<<"             "<<pointsA<<"                              "<<pointsB<<"          "<<endl;
        line();
        cout<<"     No of Players of A                No of Players of B          "<<endl;
        cout<<"                "<<noOfPlayers1<<"                         "<<noOfPlayers2<<"          "<<endl;
        line();
        

        
    }
    void winner()
    {
        if(pointsA>pointsB)
        {   
             line();

    cout<<endl<<"Whistle blown !!! Match over .\nThe results are as follows :"<<endl;

            line();
        cout<<"          Team A                         Team B          "<<endl;
        cout<<"             "<<pointsA<<"                              "<<pointsB<<"          "<<endl;
        str="**********************Congratulations Team A you won the match !!!**************************";
            cout<<endl<<str<<endl;
        }
        else if(pointsA==pointsB)
        {   
             line();

    cout<<endl<<"Whistle blown !!! Match over .\nThe results are as follows :"<<endl;

            line();
        cout<<"          Team A                         Team B          "<<endl;
        cout<<"             "<<pointsA<<"                              "<<pointsB<<"          "<<endl;

        str="**********************Congratulations to both Team match DRAW !!!**************************";
            cout<<endl<<str<<endl;
        }
        else{

             line();

    cout<<endl<<"Whistle blown !!! Match over .\nThe results are as follows :"<<endl;

            line();
        cout<<"          Team A                         Team B          "<<endl;
        cout<<"             "<<pointsA<<"                              "<<pointsB<<"          "<<endl;

        str="**********************Congratulations Team B you won the match !!!**************************";
            cout<<endl<<str<<endl;
        }
    }
};

void pointings::line() {                                       //Abstract Data Types [ADT]
            cout<<"\n_______________________________________________________________________________________________\n";
        }

int main() {

    team1 a;
    team2 b;
    pointings p;
    
    
    // p.line();
    // cout<<endl<<"Enter the no of raids in the match :"<<endl;
    // cin>>a;
    // for (int i = 0; i < a; i++)
    // {
    //     /* code */
    //     p.title();
    // }
    p.title();
    
    
     ofstream out("record.txt");                                // FILE HANDLING
    
    if(p.glitch<1)
    {
         p.winner();

         p.line();

        cout<<endl<<"******************************* T H A N K    Y O U *************************************"<<endl;
    }
    else
    {
         p.line();

        cout<<endl<<"******************************* T H A N K    Y O U *************************************"<<endl;
    }
    string str2;

    
    out<<p.str<<" \n  Final score of Team A :"<<p.pointsA<<"  Final scaore of Team B :"<<p.pointsB;

    
    // a.title();

    // p.data();

    
    return 0;
}