#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class player
{
    string name;
    char guesschar='\0';        //the current character guessed by the person.. and append it to the current given string..
    string guessString;    
    int guessNo=1;


    public:
    void getdata()
    {
        cout<<"Enter the Name of the player\n\n";
        getline(cin,name);
    }


    void getinput()
    {   
        cout<<"\nenter your guess no "<<guessNo<<":"; 
        cin>>guesschar;cout<<endl;
        if(isalpha(guesschar))
        {
            guessString.push_back(guesschar);
            guessNo++;
        }
        else
        { 
            cout<<"invalid Input";
            getinput();
        }

    }
    
    void showGuessString()
    {
        cout<<guessString;
    }
    friend class questioner;
}P;




class questioner
{
    string qstring;
    string chkstring;
    int slen;
    char arr[5][5];

   public:
    
    void getquest()
    {
        cout<<"\n\nEnter the question STRING :\n";
        getline(cin,qstring);    // takes the input of the question string
        slen=qstring.size();
        checkquest();
    }

    void checkquest()
    {   
        int k=0;
        for(int i=0;i<slen;i++)
        {
            if(isalpha(qstring[i])||qstring[i]==' ')
            {
               k++;
            } 
        }
        if(k!=slen)
        {
            cout<<"Invalid Sting\n\nPlease enter AGAIN\n";
            getquest();
        } 
        else
        {
            chkstring=qstring;
            chkstringInit();
        }
    }
    
    void chkstringInit()
    {
        for(int i=0;i<slen;i++)
        {
            if(qstring[i]==' ')
                chkstring[i]=' ';
            else
                chkstring[i]='_';
        }
    }

      
    int checkinput(player *obj)
    { 
        int flag=0;
        for(int i=0;i<slen;i++)
        {
            if(qstring[i]== obj->guesschar)
            { 
                chkstring[i]=obj->guesschar;
                flag=1;
            } 
        }
        cout<<chkstring;
        return flag;
    }

    void checkWin()
    { 
        if(chkstring==qstring)
        {
            cout<<P.name<<" WON the Game :-)";
            exit(0);
        }
    }

    void hangInit()
    {
        fill(&arr[0][0], &arr[5][5],' ');  //intializes using fill('initial add', 'final add'/{&arr[0][0]+sizeof(arr)},'value')
    }

    void mkHang(int a)                  //change the function to change the hanging style
    {
        switch(a)
        {
            case 0:
                for(int i=0;i<5;i++)
                    arr[0][i]='_';
                break;
            case 1:
                arr[1][2]='|'; 
                break;

            case 2:
                arr[2][1]='(';
                break;
            case 3:
                arr[2][3]=')'; 
                break;
            case 4:
                arr[3][2]='|';
                break;
            case 5:
                arr[3][1]='/'; 
                break;
            case 6:
                arr[3][3]='\\'; 
                break;
            case 7:
                arr[4][1]='/';
                break;
            case 8:
                arr[4][3]='\\';
        }

    }
   
    void showhangman()
    {cout<<"\n\n\n\n";
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
                cout<<arr[i][j];
            cout<<endl;
        }
    } 
   
}Q;




int main()
{  
    int over=0,chkbt,Erno=0;
    system("clear");               //change argument to "CLS" in windows
    cout<<"\n\n=========================$$ WELCOME TO THE GAME $$=========================";
    cout<<"\n                                  HANGMAN\n\n\n"; 
    P.getdata();
    system("clear");
    Q.getquest();
    Q.hangInit();
    system("clear");
    cout<<"The dashed string is : \n";
    cout<<"  ";Q.checkinput(&P);cout<<endl; 
    while(over!=1)
    {
       P.getinput();
       system("clear");
       cout<<"\n\n";
       chkbt=Q.checkinput(&P);
       if(chkbt==0)
       { 
           Q.mkHang(Erno);
           Erno++;
           Q.showhangman();
       }
       cout<<"\n\nyour guesses are :  ";P.showGuessString();
       cout<<endl;
       Q.checkWin();
       if(Erno==9)
           over=1;
    }
    Q.showhangman();
    cout<<"GAME OVER";
    cout<<"\nYou couldn't save the HANGMAN";

return 0;
}
	
