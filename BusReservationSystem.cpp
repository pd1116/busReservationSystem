#include <iostream>
#include <conio.h>
#include <cstdio>
#include <string.h>
#include <cstdlib>

using namespace std;
static int p = 0;

class BusReservationSystem
{
    char BusNo[5], driverName[10], ArrivalTime[5], departTime[5], from[10], to[10], seat[8][4][10];

    public:

      void install();
      void allotment();
      void empty();
      void show();
      void avail();
      void position(int i);

};

BusReservationSystem bus[10];

void vline(char ch)
{
  for(int i=80;i>0;i--)
  {
      cout<<ch;
  }
}

void BusReservationSystem::install()
{
    cout<<"Enter bus no: ";
    cin>>bus[p].BusNo;
    cout<<"\nEnter Driver name: ";
    cin>>bus[p].driverName;
    cout<<"\nArrival time: ";
    cin>>bus[p].ArrivalTime;
    cout<<"\nDeparture: ";
    cin>>bus[p].departTime;
    cout<<"\nFrom: \t\t\t";
    cin>>bus[p].from;
    cout<<"\nTo: \t\t\t";
    cin>>bus[p].to;
    bus[p].empty();

    p++;
}

void BusReservationSystem::allotment()

{

    int seat;
    char number[5];
    top:
    cout<<"Bus no: ";
    cin>>number;
    int n;
    for(n=0;n<=p;n++)
    {
      if(strcmp(bus[n].BusNo, number)==0)
      break;
    }
    while(n<=p)
    {
      cout<<"\nSeat Number: ";
      cin>>seat;
      if(seat>32)
      {
            cout<<"\nThere are only 32 seats available in this bus.";
      }
      else
      {
          if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
          {
                cout<<"Enter passanger's name: ";
                cin>>bus[n].seat[seat/4][(seat%4)-1];
                break;  
          }
          else
          {
            cout<<"The seat no. is already reserved.\n";
          }
      }

    }

    if(n>p)
    {
        cout<<"Enter correct bus no.\n";
        goto top;
    }
}

void BusReservationSystem::empty()
{
    for(int i=0; i<8;i++)
    {
        for(int j=0;j<4;j++)
        {
            strcpy(bus[p].seat[i][j], "Empty");
        }
    }
}

void BusReservationSystem::show()
{
    int n;
    char number[5];
    cout<<"Enter bus no: ";
    cin>>number;
    for(n=0;n<=p;n++)
    {
      if(strcmp(bus[n].BusNo, number)==0)
      break;
    }
    while(n<=p)
    {

        vline('*');
        cout<<endl;
        cout<<"Bus no: \t"<<bus[n].BusNo<<endl;
        cout<<"Driver: \t"<<bus[n].driverName<<"\t\tArrival time: \t"<<bus[n].ArrivalTime<<"\tDepartTimeure time:"<<bus[n].departTime<<endl;
        cout<<"From: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<bus[n].to<<endl;
        vline('*');
        cout<<endl;
        bus[0].position(n);
        int a=1;
        for (int i=0; i<8; i++)
        {
            for(int j=0;j<4;j++)
            {
                a++;
                if(strcmp(bus[n].seat[i][j],"Empty")!=0)
                cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
            }
        }
        break;
    }
    if(n>p)
        cout<<"Enter correct bus no: ";
}

void BusReservationSystem::position(int l)
{
  int s=0;p=0;
  for (int i =0; i<8;i++)
  {
    cout<<"\n";
    for (int j = 0;j<4; j++)
    {
      s++;
      if(strcmp(bus[l].seat[i][j], "Empty")==0)
      {
          cout.width(5);
          cout.fill(' ');
          cout<<s<<".";
          cout.width(10);
          cout.fill(' ');
          cout<<bus[l].seat[i][j];
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
  cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].BusNo;
}

void BusReservationSystem::avail()
{
  for(int n=0;n<p;n++)
  {
    vline('*');
    cout<<endl;
    cout<<"Bus no: \t"<<bus[n].BusNo<<"\nDriverName: \t"<<bus[n].driverName
    <<"\t\tArrivalTime time: \t"<<bus[n].ArrivalTime<<"\tDepartTimeure Time: \t"
    <<bus[n].departTime<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"
    <<bus[n].to<<"\n";
    vline('*');
    cout<<endl;
    vline('_');
    cout<<endl;
  }
}

int main()
{
system("cls");
int w;
while(1)
{

    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t1.Install"<<endl;
    cout<<"\t\t\t2.Reservation"<<endl;
    cout<<"\t\t\t3.Show"<<endl;
    cout<<"\t\t\t4.Buses Available"<<endl;
    cout<<"\t\t\t5.Exit"<<endl;
    cout<<"\t\t\tEnter your choice:-> ";
    cin>>w;
    switch(w)
    {
      case 1:  
          bus[p].install();
          break;
      case 2:  
        bus[p].allotment();
        break;
      case 3:  
        bus[0].show();
        break;
      case 4:  
        bus[0].avail();
        break;
      case 5:  
        exit(0);
        break;
      default:
        cout<<"Invalid Option!!"<<endl;    }

    }

  return 0;

}
