#include<iostream> 
#include<cstdlib> 
#include<ctime> 
using namespace std; 
// Simulate frame transmission and return true if the frame is received, false otherwise. bool 
transmitFrame() 
{ 
// Simulate frame transmission and random acknowledgment (50% chance of success) 
	return rand() % 2 == 0; // 0=true , 1=false
} 
int main() 
{
	int totalFrames; 
	srand(time(0)); // Seed the random number generator int totalFrames; 
	cout<<"\n\n\n\t\t =========== STOP AND WAIT ARQ =============\n\n\n\n"; 
	cout << "--> Enter the total number of frames to simulate: "; 
	cin >> totalFrames; 
	int frameNumber = 0; 
	cout << "\n==> Simulating Stop-and-Wait ARQ:\n\n"; 
	while (frameNumber < totalFrames) 
	{ 
		cout << "\nSender sends frame " << frameNumber << endl; 
		bool received = transmitFrame(); 
		if (received) 
		{ 
			cout << "Receiver acknowledges frame " << frameNumber+1 << endl; 
			cout<<"______________________________________________________________________"; 
			frameNumber++; // Move to the next frame 
		} 
		else 
		{ 
		 	cout << "Receiver does not acknowledge frame " << frameNumber << ", retransmitting...\n"; 
		} 
		cout << endl; 
	} 
	cout << "\n\n\n\t\t !!! All frames have been sent and acknowledged. !!!\n\n\n\n"; 
	return 0; 
}
