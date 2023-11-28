#include<bits/stdc++.h> 
#include<ctime> 
#define ll long long int 
using namespace std; 
//i=current frame index, N=window size, tf=total frames, and tt=total transmitted frames 


/*This function transmission simulates the Go-Back-N Automatic Repeat reQuest (ARQ) protocol. It takes parameters 
for the current frame index (i), window size (N), total frames (tf), and total transmitted frames (tt).

It loops until the current frame index is less than or equal to the total frames (tf).
It then sends frames in the current window, printing the frame numbers and incrementing the total transmitted frames.
It simulates receiving acknowledgments for the sent frames. If an acknowledgment is not received (simulated by a random condition), 
it prints a timeout message and breaks from the loop to simulate retransmitting the window.
The function increments the current frame index based on the number of acknowledgments received.*/ 
void transmission(ll & i, ll & N, ll & tf, ll & tt) 
{ 
	while (i <= tf) 
	{ 
		int z = 0; 
		for (int k = i; k < i + N && k <= tf; k++) 
		{ 
			cout << "Sending Frame " << k << "..." << endl; 
			tt++; 
		} 
		for (int k = i; k < i + N && k <= tf; k++) 
		{ 
//			int f = ; 
			if (rand() % 2==0) 
			{ 
				cout << "\nAcknowledgment for Frame " << k << "...\n" << endl; 
				z++; 
			} 
			else 
			{ 
				cout << "\nTimeout!!\n--> Frame Number : " << k << " Not Received" << endl; 
				cout << "** Retransmitting Window...\n" << endl; 
				break; 
			} 
		} 
		cout << "\n"; 
		i = i + z; 
	} 
} 

/* The main function initializes variables for the total frames (tf), window size (N), and total transmitted frames (tt).
It seeds the random number generator based on the current time.
The user is prompted to enter the total number of frames and the window size.
The transmission function is called with the initial frame index, window size, total frames, and total transmitted frames.
Finally, the program prints the total number of frames sent and resent.
The program simulates the Go-Back-N ARQ protocol, where a sender transmits a window of frames, and the receiver sends acknowledgments. 
If an acknowledgment is not received within a simulated timeout, the sender retransmits the entire window.*/
int main() 
{ 
	ll tf, N, tt = 0; 
	srand(time(NULL)); 
	cout<<"\n\n\t\t ======== GO BACK N ARQ ========\n\n\n"; 
	cout << "--> Enter the Total number of frames : "; 
	cin >> tf; 
	cout << "\n --> Enter the Window Size : "; 
	cin >> N; 
	ll i = 1; 
	transmission(i, N, tf, tt); 
	cout << "\n\n\t Total number of frames which were sent and resent are : " << tt << endl; 
	return 0; 
} 

