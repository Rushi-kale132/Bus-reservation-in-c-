#include <conio.h>
#include <cstdlib>
#include <string.h>
#include <iostream>
#include <cstdio>
#include<windows.h>
using namespace std;

static int p = 0;

class a
{
    char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];
public:
    void install();
    void reservation();
    void empty();
    void show();
    void available();
    void payment( int i,int sn);
    void position(int i);
}bus[10];




void a::install()   //Install Function
{
     system("cls");

   string email,pass,ch;
   cout<<"\n---------------------- Security are Required ----------------------\n\n";
 cout<<"\nEnter Username ->";
   cin>>email;
   cout<<"\n Enter Password ->";
   for(int i=1;i<=4;i++)
   {
       ch=getch();
       pass=pass+ch;
       cout<<"*";
   }


   if(email == "bus123@gmail.com" && pass == "1234")
   {
       cout<<"\n\n\n\n\n\t\t\t\t Loading";
       for(int i=1;i<=5;i++)
       {
           Sleep(500);
           cout<<".";
       }
       system("cls");
       cout<<"\n******************** successfully Login ********************\n\n";
    cout<<"Enter bus no: ";
    cin>>bus[p].busn;
    cout<<"\nEnter Driver's name: ";
    cin>>bus[p].driver;
    cout<<"\nArrival time: ";
    cin>>bus[p].arrival;
    cout<<"\nDeparture: ";
    cin>>bus[p].depart;
    cout<<"\nFrom: ";
   cin>>bus[p].from;
    cout<<"\nTo: ";
   cin>>bus[p].to;
    bus[p].empty();
    p++;
    system("cls");
    cout<<"\n---------------------- Data successfully inserted ----------------------\n\n";
}
else
{
   system("cls");
     cout<<"\n\n\n\n\n\n\t\t\t\t Loading";
       for(int i=1;i<=5;i++)
       {
           Sleep(500);
           cout<<".";
       }
system("cls");
    cout<<"\n\n  Email or Password is Wrong.....\n\n\n";
}
}

void a::available()   //available Function
{
    system("cls");
    cout<<"\n\n --------------------all available buses--------------------";
    for(int n=0;n<p;n++)
    {



        cout<<"\n\n Bus no: "<<bus[n].busn;
        cout<<"\n\n Driver: "<<bus[n].driver;
        cout<<"\n\n Arrival time: "<<bus[n].arrival;
        cout<<"\n\n Departure time: "<<bus[n].depart;
        cout<<"\n\n From: "<<bus[n].from;
        cout<<"\t\tTo: "<<bus[n].to<<"\n";
        cout<<"------------------------------------------\n";


    }
}

void a::show()   //show Function
{

     system("cls");
    int n;
    char number[5];
    cout<<"Enter bus no: ";
    cin>>number;
    for(n=0; n<=p; n++)
    {
        if(strcmp(bus[n].busn, number)==0)
            break;
    }
    while(n<=p)
    {
        cout<<"       ------------------------------------------";
        cout<<"\nBus no:"<<bus[n].busn;
        cout<<"\nDriver: "<<bus[n].driver;
        cout<<"\nArrival time: "<<bus[n].arrival;
        cout<<"\nDeparture time: "<<bus[n].depart;
        cout<<"\n From: "<<bus[n].from;
        cout<<"\t\tTo: "<<bus[n].to<<"\n";
        cout<<"        ------------------------------------------\n\n";
        cout<<"available seats : \n ";


    bus[0].position(n);
        int a=1;

        for(int i=0; i<8; i++)
        {
            for(int j=0;j<4;j++)
            {
                a++;
                if(strcmp(bus[n].seat[i][j], "Empty")!=0)
                    cout<<"\nThe seat no "<<(a-1)<<"is reserved for "<<bus[n].seat[i][j]<<"."<<"\n\n\n";
            }
        }

        break;
    }
    if(n>p)
        cout<<"Enter correct bus no: ";
}

void a::reservation()
{
    system("cls");
    int seat;
    char number[5];
    top:
        cout<<"Bus no: ";
        cin>>number;
        int n;
        for(n=0; n<=p; n++)
        {
            if(strcmp(bus[n].busn, number)==0)
                break;
        }
        while(n<=p)
        {
            cout<<"\nSeat Number: ";
            cin>>seat;
           int sn=seat;
            if(seat>32)
            {
                cout<<"\nThere are only 32 seats available in this bus.";
            }
            else
            {
                if(strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
                {
                    cout<<"\nEnter passenger's name: ";
                    cin>>bus[n].seat[seat/4][(seat%4)-1];
                    bus[0].payment(n,sn);


                    break;
                }
                else

                    cout<<"The seat no. is already reserved. \n";
            }
        }

            if(n>p)
            {
                cout<<"Enter correct bus number \n";
                goto top;
            }
        }

void a::empty()
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<4; j++)
        {
            strcpy(bus[p].seat[i][j], "Empty");
        }
    }
}



void a::position(int l)
{
    int s=0; p=0;
    for(int i=0; i<8; i++)
    {
        cout<<"\n";
        for(int j=0;j<4;j++)
        {
           s++;
           if(strcmp(bus[l].seat[i][j],"Empty")==0)
           {
               cout.width(5);
               cout.fill(' ');
               cout<<s<<".";
               cout.width(10);
               cout.fill(' ');
               cout<<bus[1].seat[i][j];
               p++;
           }
           else
            {
                cout.width(5);
           cout.fill(' ');
           cout<<s<<".";
           cout.width(10);
           cout.fill(' ');
           cout<<bus[l].seat[i][j];

            }
        }
    }
    cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].busn<<"\n\n";
}


void a::payment(int n, int seat)
{
    int s;
     string bankname,accnum,ch,name;
    system("cls");
     cout<<"\n------------- Select Payment mode -------------\n\n";
     cout<<"\t\t1. For Online\n\n";
     cout<<"\t\t2. For Offline \n\t\t";
     cout<<"\n\n\t\tEnter your choice:->  ";
     cin>>s;
     switch(s)
      {
    case 1:
         cout<<"\t\t\n Enter Passenger Name As per Bank Passbook : ";
         cin>>name;
        cout<<"\t\t\n Enter Bank Name : ";
        cin>>bankname;
        cout<<"\t\t\nEnter Account Number : ";
        cin>>accnum;
        system("cls");
        cout<<"\n---------------------- Reservation done successfully ----------------------\n\n";

        cout<<" ***Ticket*** \n";
        cout<<"--------------------------------------\n";
        cout<<"\nPassenger name : "<<name;
        cout<<"\nBank Name :"<<bankname;
         cout<<"\nPayment Mode: Online";
        cout<<"\nSeat no:"<<seat;
        cout<<"\nBus no:"<<bus[n].busn;
        cout<<"\nArrival time: "<<bus[n].arrival;
        cout<<"\nDeparture time: "<<bus[n].depart;
        cout<<"\n From: "<<bus[n].from;
        cout<<"\t\tTo: "<<bus[n].to<<"\n";
        cout<<"--------------------------------------\n\n";

            break;
        case 2:
            cout<<"\n---------------------- Reservation done successfully ----------------------\n\n";
            cout<<"\n---Collect Ticket From Counter---\n\n";

            break;

             default:
                 cout<<"\n Wrong choice... \n\n\t\t";
      }

}


int main()
{
    system("cls");
    int w;
    system("color 72");
    cout<<"\n******************** Welcome to Bus Reservation System ********************\n\n";
    while(1)
    {

    cout<<"\n";
cout<<"\t\t1.Enter bus details\n\n\t\t";
cout<<"2.Show  all buses. \n\n\t\t";
cout<<"3.Show  particular bus\n\n\t\t";
cout<<"4.Reservation\n\n\t\t";
cout<<"5.Exit";
cout<<"\n\n\t\tEnter your choice:->  ";
cin>>w;
        switch(w)
        {
        case 1:
            bus[p].install();
            break;
        case 2:
            bus[p].available();
            break;
        case 3:
            bus[0].show();
            break;
        case 4:
            bus[0].reservation();
            break;
        case 5:
            exit(0);
        }
    }
    return 0;
}
