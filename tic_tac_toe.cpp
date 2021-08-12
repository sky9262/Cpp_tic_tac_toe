//============================================================================
//                
//                     PROJECT TITLE :  TIC-TAC-TOE GAME
//                    CREATED BY    :  AKASH KUMAR SRIVASTAVA
//                  CREATED ON    :  25.06.2021
//
//============================================================================



#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
using namespace std;

void show()
{
    system("CLS"); 
    cout << "==============================================" << endl;
    cout << "\tWELCOME TO TIC TAC TOE GAME"<< endl;
    cout << "==============================================" << endl;
    cout<<"| 1 | 2 | 3 |"<<endl<<"| 4 | 5 | 6 |"<<endl<<"| 7 | 8 | 9 |"<<endl<<"These are the block numbers. Enter your choices accordingly."<<endl<<endl;;
    cout << "\n\n Press any key to start the game....";
    getch();
}

void initialize(char a[3][3])
{
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            a[i][j]='_';
        }
    }    
}

void display(char a[3][3])
{
    cout<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<" | "<<a[i][j];
        }
        cout<<" |"<<endl;
    }
}

void start(char a[3][3])
{
    int a1,a2;
    srand((unsigned)time(0));
       a1=rand()%3;
    a2=rand()%3;
    a[a1][a2]='x';
    display(a);
}

int check(char a[3][3])
{
    int x,y,empty=0;
    bool winner=false;
    for(int i=0;i<3;i++)          //Check row-wise
    {
        if(((a[i][0]==a[i][1])&&(a[i][1]==a[i][2])&&(a[i][2]=='x'))||((a[i][0]==a[i][1])&&(a[i][1]==a[i][2])&&(a[i][2]=='0')))
        {
            x=i;y=0;
            winner=true;
            break;
        }
    }
    if(winner==true)
    {
        if(a[x][y]=='x')
            return 1;
        else
            return 2;
    }
    for(int i=0;i<3;i++)          //Check column-wise
    {
        if(((a[0][i]==a[1][i])&&(a[1][i]==a[2][i])&&(a[2][i]=='x'))||((a[0][i]==a[1][i])&&(a[1][i]==a[2][i])&&(a[2][i]=='0')))
        {
            x=0;y=i;
            winner=true;
            break;
        }
    }
    if(winner==true)
    {
        if(a[x][y]=='x')
            return 1;
        else
            return 2;
    }
    if(((a[0][0]==a[1][1])&&(a[1][1]==a[2][2]))||((a[0][2]==a[1][1])&&(a[1][1]==a[2][0])))          //Check diagonally
    {
        if(a[1][1]=='x')
            return 1;
        else 
            return 2;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(a[i][j]=='_')
            {
                empty++;
            }
        }
    }
    if(empty==0)
        return 3;    
    return 0;    
}

int system(char a[3][3])
{
    int n1,n2,empty=0;
    for(int i=0;i<3;i++)        //Check row-wise
    {
        if((a[i][0]==a[i][1])&&(a[i][0]=='x')&&(a[i][2]=='_'))
        {
            a[i][2]='x';
            return 1;
        }   
        if((a[i][0]==a[i][2])&&(a[i][0]=='x')&&(a[i][1]=='_'))
        {
            a[i][1]='x';
            return 1;
        }   
        if((a[i][1]==a[i][2])&&(a[i][1]=='x')&&(a[i][0]=='_'))
        {
            a[i][0]='x';
            return 1;
        }   
    }
    for(int i=0;i<3;i++)        //Check column-wise
    {
        if((a[0][i]==a[1][i])&&(a[0][i]=='x')&&(a[2][i]=='_'))
        {
            a[2][i]='x';
            return 1;
        }   
        if((a[0][i]==a[2][i])&&(a[0][i]=='x')&&(a[1][i]=='_'))
        {
            a[1][i]='x';
            return 1;
        }   
        if((a[1][i]==a[2][i])&&(a[1][i]=='x')&&(a[0][i]=='_'))
        {
            a[0][i]='x';
            return 1;
        }   
    }
    //Check diagonal 1
        if((a[0][0]==a[1][1])&&(a[0][0]=='x')&&(a[2][2]=='_'))
        {
            a[2][2]='x';
            return 1;
        }   
        if((a[0][0]==a[2][2])&&(a[0][0]=='x')&&(a[1][1]=='_'))
        {
            a[1][1]='x';
            return 1;
        }  
        if((a[1][1]==a[2][2])&&(a[1][1]=='x')&&(a[0][0]=='_'))
        {
            a[0][0]='x';
            return 1;
        }
    //Check diagonal 2  
        if((a[0][2]==a[1][1])&&(a[0][2]=='x')&&(a[2][0]=='_'))
        {
            a[2][0]='x';
            return 1;
        }   
        if((a[0][2]==a[2][0])&&(a[0][2]=='x')&&(a[1][1]=='_'))
        {
            a[1][1]='x';
            return 1;
        }   
        if((a[1][1]==a[2][0])&&(a[1][1]=='x')&&(a[0][2]=='_'))
        {
            a[0][2]='x';
            return 1;
        }     
        for(int i=0;i<3;i++)        //Check row-wise
        {
            if((a[i][0]==a[i][1])&&(a[i][0]=='0')&&(a[i][2]=='_'))
            {
            a[i][2]='x';
            return 1;
            }  
            if((a[i][0]==a[i][2])&&(a[i][0]=='0')&&(a[i][1]=='_'))
            {
                a[i][1]='x';
                return 1;
            }   
            if((a[i][1]==a[i][2])&&(a[i][1]=='0')&&(a[i][0]=='_'))
            {
                a[i][0]='x';
                return 1;
            }   
        }
    for(int i=0;i<3;i++)        //Check column-wise
    {
        if((a[0][i]==a[1][i])&&(a[0][i]=='0')&&(a[2][i]=='_'))
        {
            a[2][i]='x';
            return 1;
        }   
        if((a[0][i]==a[2][i])&&(a[0][i]=='0')&&(a[1][i]=='_'))
        {
            a[1][i]='x';
            return 1;
        }   
        if((a[1][i]==a[2][i])&&(a[1][i]=='0')&&(a[0][i]=='_'))
        {
            a[0][i]='x';
            return 1;
        }   
    }
    //Check diagonal 1
        if((a[0][0]==a[1][1])&&(a[0][0]=='0')&&(a[2][2]=='_'))
        {
            a[2][2]='x';
            return 1;
        }   
        if((a[0][0]==a[2][2])&&(a[0][0]=='0')&&(a[1][1]=='_'))
        {
            a[1][1]='x';
            return 1;
        }   
        if((a[1][1]==a[2][2])&&(a[1][1]=='0')&&(a[0][0]=='_'))
        {
            a[0][0]='x';
            return 1;
        } 
    //Check diagonal 2  
        if((a[0][2]==a[1][1])&&(a[0][2]=='0')&&(a[2][0]=='_'))
        {
            a[2][0]='x';
            return 1;
        }   
        if((a[0][2]==a[2][0])&&(a[0][2]=='0')&&(a[1][1]=='_'))
        {
            a[1][1]='x';
            return 1;
        }   
        if((a[1][1]==a[2][0])&&(a[1][1]=='0')&&(a[0][2]=='_'))
        {
            a[0][2]='x';
            return 1;
        }     
    do{
        srand((unsigned)time(0));
        n1=rand()%3;
        n2=rand()%3;
        if(a[n1][n2]=='_')
            empty=1;     
    }while(empty!=1);
    empty=0;
    a[n1][n2]='x';    
    return 0;
}

void user(char a[3][3])
{
    int n,entered=0;
    bool found;
    do
    {
        
        cout<<endl<<"Your turn. \n\nEnter the block number (Enter a number 1 to 9) :";
        cin>>n;
        switch(n)
        {
            case 1:
                if(a[0][0]=='_')
                {
                    a[0][0]='0';
                    entered=1;
                }
                break;
            case 2:
                if(a[0][1]=='_')
                {
                    a[0][1]='0';
                    entered=1;
                }
                break;
            case 3:
                 if(a[0][2]=='_')
                {
                    a[0][2]='0';
                    entered=1;
                }
                break;    
            case 4:
                if(a[1][0]=='_')
                {
                    a[1][0]='0';
                    entered=1;
                }
                break;
            case 5:
                 if(a[1][1]=='_')
                {
                    a[1][1]='0';
                    entered=1;
                }
                break;                
            case 6:
                  if(a[1][2]=='_')
                {
                    a[1][2]='0';
                    entered=1;
                }
                break;                
            case 7:
                if(a[2][0]=='_')
                {
                    a[2][0]='0';
                    entered=1;
                }
                break;                
            case 8:
                  if(a[2][1]=='_')
                {
                    a[2][1]='0';
                    entered=1;
                }
                break;                
            case 9:
                 if(a[2][2]=='_')
                {
                    a[2][2]='0';
                    entered=1;
                }
                break;                
            default:
                break;
                                                       
        }
        system("CLS"); 
    }while(n>9||entered==0);
}

void play()
{
    int p=0,win=0,empty=0;
    char arr[3][3],again;
    show();
    initialize(arr);
    system("CLS"); 
    display(arr);
    start(arr);
    while(win==0)
    {
        user(arr);
        display(arr);
        p++;
        if(p>4)
            win=check(arr);
        if(win>0)
            break;
        system(arr);
        display(arr);
        p++;
        if(p>4)
            win=check(arr);
    }
    if(win==1)
        cout<<"System Wins"<<endl;
    else if(win==2)
        cout<<"You Win"<<endl;
    else
        cout<<"It is a Tie";
	
	
}

int main()
{	string again;
    cout<<"   **   TIC-TAC-TOE GAME   **"<<endl<<endl;
    play();
	cout<<"\n\nDo you want to play again (y/n): ?";
	cin>>again;
	if(again=="y")
		play();
    return 0;
}