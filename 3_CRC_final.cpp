#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

char exor(char a,char b) //xor operation                                    
{
	if(a==b)
		return '0'; //equal-o, unequal-1
	else
		return '1';
}

void crc(char data[], char key[]) //The crc function takes two character arrays, data and key
{
	int datalen = strlen(data); //It calculates the lengths of both arrays using strlen() func
	int keylen = strlen(key);

	for(int i=0;i<keylen-1;i++)    //function appends zeros to the end of the data array.number of zeros appended is keylen - 1.           
		data[datalen+i]='0';
		data[datalen+keylen-1]='\0';

		int codelen = datalen+keylen-1; //codelen is the length of the final codeword after appending zeros. 
	char temp[20],rem[20];  //temp and rem are temporary arrays used in the CRC calculation.               

	for(int i=0;i<keylen;i++) //rem is initialized with the initial values of the data array.
		rem[i]=data[i];                    

	for(int j=keylen;j<=codelen;j++)
	{
    	for(int i=0;i<keylen;i++)
    		temp[i]=rem[i];      //The outer loop runs from keylen to codelen, and in each iteration,
									// the temporary array temp is updated with the current values of rem.
									         
		
    	if(rem[0]=='0')                
    	{
        	for(int i=0;i<keylen-1;i++)
            	rem[i]=temp[i+1];
    	}
    	else                    
    	{    
        	for(int i=0;i<keylen-1;i++)
            	rem[i]=exor(temp[i+1],key[i+1]);
            
    	} //This above block of code simulates the XOR operation in the CRC algorithm.
		// If the leftmost bit of rem is '0', it performs a shift. Otherwise, it performs XOR with the key.
    	
    	if(j!=codelen)
        	rem[keylen-1]=data[j];        
    	else
        	rem[keylen-1]='\0'; //After the inner loop, the last bit of rem is updated based on the corresponding bit of the data array.
	}
    
	for(int i=0;i<keylen-1;i++)
		data[datalen+i]=rem[i];                
		data[codelen]='\0';
	cout<<"CRC="<<rem<<"\nDataword="<<data;

}//Finally, the function updates the data array with the remainder (rem) and prints the CRC and the modified dataword.


int main()
{
	char key[20],data[20];

	cout<<"Enter the data:";
	cin>>data;
	cout<<"Enter the key:";
	cin>>key;
	
	crc(data,key);                        

	return 0;
} //The main function takes user input for the data and the key, and then it calls the crc function with these inputs. 
//The CRC result and modified dataword are then printed.


/*
Enter the data:101101  - input
Enter the key:010
CRC=00
Dataword=10110100
--------------------------------
*/
