#include <iostream>
#include <algorithm>

using namespace std;

void parityChecker() {
    // Declare a string to store the sender's message
    string str_sender;
    
    // Prompt the user to enter the string for the sender
    cout << "Enter the string for sender: ";
    cin >> str_sender;

    // Declare variables to store parity information and count of '1's
    int parity, count_ones = 0;

    // Prompt the user to select parity (even or odd)
    cout << "Select parity: 1) Even 2) Odd : ";
    cin >> parity;

    // Count the number of '1's in the sender's message
    for (size_t i = 0; i < str_sender.length(); ++i)
        if (str_sender[i] == '1')
            count_ones++;

    // Check the parity and append a '1' if necessary
    if ((parity == 1 && count_ones % 2 != 0) || (parity == 2 && count_ones % 2 == 0))
        str_sender += '1';
    else{
    	str_sender += '0';
	}

    // Display the final string that will be sent
    cout << "Final string that will be sent is: " << str_sender << endl;

    // Declare a string to store the received message
    string str_received;

    // Prompt the user to enter the received string
    cout << "Enter string received: ";
    cin >> str_received;

    // Count the number of '1's in the received string
    int count_ones_rec = count(str_received.begin(), str_received.end(), '1');

    // Check for errors based on parity
    if (parity == 1) {
        cout << (count_ones_rec % 2 == 0 ? "No error detected!" : "Error detected!") << endl;
    } else {
        cout << (count_ones_rec % 2 != 0 ? "No error detected!" : "Error detected!") << endl;
    }
}


int main() {
	parityChecker();
    return 0;
}

