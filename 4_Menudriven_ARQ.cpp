#include<iostream>
#include<ctime>
#include<cstdlib>
#include <time.h>
#include <unistd.h>
using namespace std;
class timer {
private:
unsigned long begTime;
public:
void start() {
begTime = clock();
}
unsigned long elapsedTime() {
return ((unsigned long) clock() - begTime) / CLOCKS_PER_SEC;
}
bool isTimeout(unsigned long seconds) {
return seconds >= elapsedTime();
}
};
int stopAndWait()
{
int n;
cout<<"\nEnter number of frames: ";
cin>>n;
int frames[n];
cout<<"\nEnter Frames: ";
for(int i=0;i<n;i++)
{
cin>>frames[i];
}
//int frames[] = {1,2,3,4,5,6,7,8,9,10};
unsigned long seconds = 5;
srand(time(NULL));
timer t;
cout<<"Sender has to send frames : ";
for(int i=0;i<n;i++)
cout<<frames[i]<<" ";
cout<<endl;
int count = 0;
bool delay = false;
cout<<endl<<"Sender\t\t\t\t\tReceiver"<<endl;
do
{
bool timeout = false;
cout<<"Sending Frame : "<<frames[count];
cout.flush();
cout<<"\t\t";
t.start();
if(rand()%2)
{
int to = 24600 + rand()%(64000 - 24600) + 1;
for(int i=0;i<640;i++)
for(int j=0;j<to;j++) {}
}
if(t.elapsedTime() <= seconds)
{
cout<<"Received Frame : "<<frames[count]<<" ";
if(delay)
{
cout<<"Duplicate";
delay = false;
}
cout<<endl;
count++;
}
else
{
cout<<"---"<<endl;
cout<<"Timeout"<<endl;
timeout = true;
}
t.start();
if(rand()%2 || !timeout)
{
int to = 24600 + rand()%(64000 - 24600) + 1;
for(int i=0;i<640;i++)
for(int j=0;j<to;j++) {}
if(t.elapsedTime() > seconds )
{
cout<<"Delayed Ack"<<endl;
count--;
delay = true;
}
else if(!timeout)
cout<<"Acknowledgement : "<<frames[count]-1<<endl;
}
} while(count!=10);
return 0;
}
int goBackN()
{
int nf,N;
int no_tr=0;
srand(time(NULL));
cout<<"Enter the number of frames : ";
cin>>nf;
cout<<"Enter the Window Size : ";
cin>>N;
int i=1;
while(i<=nf)
{
int x=0;
for(int j=i;j<i+N && j<=nf;j++)
{
cout<<"Sent Frame "<<j<<endl;
no_tr++;
}
for(int j=i;j<i+N && j<=nf;j++)
{
int flag = rand()%2;
if(!flag)
{
cout<<"Acknowledgment for Frame "<<j<<endl;
x++;
}
else
{ cout<<"Frame "<<j<<" Not Received"<<endl;
cout<<"Retransmitting Window"<<endl;
break;
}
}
cout<<endl;
i+=x;
}
cout<<"Total number of transmissions : "<<no_tr<<endl;
return 0;
}
int selectiveRepeat()
{
int w,i,f,frames[50];
cout<<"Enter window size: ";
cin>>w;
cout<<"\nEnter number of frames to transmit: ";
cin>>f;
cout<<"\nEnter "<<f<<" frames: ";
for(i=1;i<=f;i++)
cin>>frames[i];
cout<<"\nWith sliding window protocol the frames will be sent in the following manner(assuming no corruption of frames)\n\n";
cout<<"After sending "<<w<<" frames at each stage sender waits for acknowledgement sent by the receiver\n\n";
for(i=1;i<=f;i++)
{
if(i%w==0)
{
cout<<frames[i]<<"\n";
cout<<"Acknowledgement of above frames sent is received by sender\n\n";
}
else
cout<<frames[i]<<" ";
}
if(f%w!=0)
cout<<"\nAcknowledgement of above frames sent is received by sender\n";
return 0;
}
int main()
{
int choice;
do{
cout<<"\n\n1. Stop and Wait ARQ\n2. Go Back N ARQ\n3. Selective Repeat\n4.exit\n";
cout<<"\nEnter your choice:- ";
cin>>choice;
switch(choice)
{
case 1: cout<<"\nStop and Wait ARQ\n";
stopAndWait();
break;
case 2: cout<<"\nGo Back N ARQ\n";
goBackN();
break;
case 3:cout<<"\nSelective Repeat\n";
selectiveRepeat();
case 4:
exit(0);
break;
default: cout<<"Enter correct choice.";
}
}while(true);
return 0;
}

/*

Enter your choice:- 1

Stop and Wait ARQ

Enter number of frames: 4

Enter Frames: 1 2 3 4
Sender has to send frames : 1 2 3 4

Enter your choice:- 2

Go Back N ARQ
Enter the number of frames : 5
Enter the Window Size : 3

Enter your choice:- 3

Selective Repeat
Enter window size: 3

Enter number of frames to transmit: 2

Enter 2 frames: 1 2
*/

