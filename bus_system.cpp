#include <conio.h>

#include <cstdio>

#include <iostream>

#include <string.h>

#include <cstdlib>

using namespace std;

static int p = 0;

class a

{

  char busnum[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[9][4][10];

public:

  void registration();

  void allotment();

  void empty();

  void show();

  void avail();

  void position(int i);

}

bus[10];

void vline(char ch)

{

  for (int i=80;i>0;i--)

  cout<<ch;

}

void a::registration()

{

  cout<<"Enter bus no: "<<endl;

  cin>>bus[p].busnum;                        //bus number can be of 5 characters

  cout<<"Enter Driver's name: "<<endl;

  cin>>bus[p].driver;                       //enter the bus driver name you want to register

  cout<<"Arrival time: "<<endl;

  cin>>bus[p].arrival;                      //time the bus will arrive in station

  cout<<"Departure: "<<endl;

  cin>>bus[p].depart;                       //time bus will depart from station  

  cout<<"From: \t\t\t";

  cin>>bus[p].from;                         //journey begins from

  cout<<"To: \t\t\t";

  cin>>bus[p].to;                           //last stop

  bus[p].empty();

  p++;

}

void a::allotment()                          //function for reservation of seats

{

  int seat;

  char number[5];

  top:                                        //using stack 

  cout<<"Bus no: ";

  cin>>number;

  int n;

  for(n=0;n<=p;n++)                        //

  {

    if(strcmp(bus[n].busnum, number)==0)

    break;

  }

  while(n<=p)

  {

    cout<<"\nSeat Number: ";

    cin>>seat;

    if(seat>36)

    {

      cout<<"\nThere are only 36 seats available in this bus.";

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

      cout<<"The seat no. is already reserved.\n";

      }

      }

    if(n>p)

    {

      cout<<"Enter correct bus no."<<endl;

      goto top;

    }

  }


void a::empty()                 //function if the bus had all seats available

{

  for(int i=0; i<9;i++)

  {

    for(int j=0;j<4;j++)

    {

      strcpy(bus[p].seat[i][j], "Empty");

    }

  }

}

void a::show()                             //function for showing your reservation details

{

  int n;

  char number[5];

  cout<<"Enter bus no: ";

  cin>>number;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busnum, number)==0)

    break;

  }

while(n<=p)

{

  vline('*');

  cout<<"Bus no: \t"<<bus[n].busnum

  <<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"

  <<bus[n].arrival<<"\tDeparture time:"<<bus[n].depart

  <<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<

  bus[n].to<<"\n";

  vline('*');

  bus[0].position(n);

  int a=1;

  for (int i=0; i<9; i++)

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

void a::position(int l)

{

  int s=0;p=0;

  for (int i =0; i<9;i++)

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

  cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].busnum;

  }

void a::avail()

{

cout<<"p equals "<< p <<endl;
  for(int n=0;n<p;n++)

  {

    vline('*');
    vline('*');

    cout<<"\nBus no: \t\t"<<bus[n].busnum<<"\nDriver: \t"<<bus[n].driver;

    cout<<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture Time: \t"<<bus[n].depart;
    cout<<"\n\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t" <<bus[n].to<<"\n";

    vline('*');

       vline('*');

    cout<<endl;

  }

}

int main()

{

system("cls");

int w;

while(1)

{


  cout<<"\n1.Bus Registration"<<endl;

   cout<<"2.Reservation"<<endl;

 cout<<"3.Show"<<endl;

   cout<<"4.Buses Available."<<endl;

   cout<<"5.Exit"<<endl;

  cout<<"\n\t\t\tEnter your choice := ";

  cin>>w;

  switch(w)

  {

    case 1:  bus[p].registration();

      break;

    case 2:  bus[p].allotment();

      break;

    case 3:  bus[0].show();

      break;

    case 4:  bus[0].avail();

      break;

    case 5:  exit(0);

  }

}

return 0;

}
