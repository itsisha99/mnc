#include <iostream>
#include <unistd.h>
using namespace std;
int n, r;
class frame
{
public:
 char ack;
 int data;
};
void resendFrame(frame frm[]) //resendFrame that takes an array of frame objects as a parameter
{
 cout << "Resending frame " << r << " .";
 sleep(2);
 cout << " .";
 // It simulates the process of resending a frame, waits for a few seconds using the sleep function, updates the acknowledgment, 
 //and then displays the received frame and the entire message received at the receiver side.
 sleep(2);
 cout << " ." << endl;
 frm[r].ack = 'y';
 cout << "Received frame is : " << frm[r].data << endl;
 cout << "The message received at the receiver side is: ";
 for (int i = 1; i <= n; i++)
 {
 cout << frm[i].data;
 }
 cout << endl;
}

//Definition of a function receiver that takes an array of frame objects as a parameter. It initializes the acknowledgment for a specific frame, checks if the acknowledgment for that frame is 'n' (indicating that it was not received), 
//and if so, it prints a message and calls the resendFrame function.
void receiver(frame frm[])
{
 r = n / 2;
 frm[r].ack = 'n';
 for (int i = 1; i <= n; i++)
 {
 if (frm[i].ack == 'n')
 {
 cout << "The frame number " << r << " is not received." << endl;
 }
 }
 resendFrame(frm);//resend frame func
}
int main()
{
 frame frm[10];
 int i;
 cout << "Enter the number of frames to be sent: " << endl;
 cin >> n;
 for (int i = 1; i <= n; i++)
 {
 int j;
 cout << "Enter the frame: " << endl;
 cin >> j;
 frm[i].data = j;
 frm[i].ack = 'y';
 }
 receiver(frm);//receiver func
}
