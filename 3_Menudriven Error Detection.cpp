#include<iostream>
#include<cstdlib>
#include<math.h>
#include<ctime>

using namespace std;

int findRandom()
{
    int num = ((int)rand() % 2);
    return num;
}

void parity_check()
{
    
    int n,ones=0,parity=0;
    int data_bits[20];
    cout<<"\nEnter the size of data bits : ";
    cin>>n;
    cout<<"Enter the data bit : ";
    for(int i = 0; i < n; i++)
    {
    	cin>>data_bits[i];
	}
    int i=0;
    for(i = 0; i < n; i++)
    {
        if(data_bits[i]==1)
        {
            ones++;
        }
    }
    if(ones%2==0)
    {
        parity=0;  	
	}
    else
    {
    	parity=1;
	}
      
    for(int i = 0; i < n; i++)
    {
    	cout<<data_bits[i]<<" ";
	}  
    cout<<parity;
}

void hamming_code()
{
    int data_bits[20],m,r = 0,parity;    

    cout<<"\nEnter the size of data bits : ";
    cin>>m;

    while(pow (2,r) < m + r + 1)
	{
        r++;
    }

    cout<<"Enter the data bit : ";
    for(int i = 1; i <= m; i++)
    {
    	cin>>data_bits[i];
	}

    int hamming[m + r],j = 0,k = 1;

    for(int i = 1; i <= m + r; i++)
	{
        if( i == pow( 2, j ))
		{
            hamming[i] = -1;    
            j++;
        }
        else
		{
            hamming[i] = data_bits[k];
            k++;
        }
    }

    k = 0;
    int x, min, max = 0;
   
    for (int i = 1; i <= m + r; i = pow (2, k))
	{
        k++;
        parity = 0;
        j = i;
        x = i;
        min = 1;
        max = i;
        while ( j <= m + r)
		{
            for (x = j; max >= min && x <= m + r; min++, x++)
			{
                if (hamming[x] == 1)
                {
                	  parity = parity + 1;
				}
            }
		    j = x + i;
            min = 1;
        }

        if (parity % 2 == 0)
		{
        	hamming[i] = 0;
        }
        else
		{
        	hamming[i] = 1;
        }
    }

    cout<<"\nHamming code is: ";
    for(int i = 1; i <= m + r; i++)
    {
    	cout<<hamming[i]<<" ";
	}     
}

void division(int temp[],int gen[],int n,int r)
{
	for(int i=0;i<n;i++)
	{
    	if (gen[0]==temp[i])
    	{
        	for(int j=0,k=i;j<r+1;j++,k++)
        	{
        		if(!(temp[k]^gen[j]))
        		{
        			temp[k]=0;
				}
                else
				{
					temp[k]=1;
				}
			}     
    	}
	}
}

void cyclic_redundancy_check()
{
	int n,r,message[50],gen[50],temp[50];
	cout<<"\nAt Sender's End "<<endl;
	cout<<"Enter the number of message bits : ";
	cin>>n;
	cout<<"Enter the number of generator bits : ";
	cin>>r;
	cout<<"Enter the message : ";
	for(int i=0;i<n;i++)
	{
		cin>>message[i];
	}
     
	cout<<"Enter the generator : ";
	for(int i=0;i<r;i++)
	{
		cin>>gen[i];
	}
	
     
	for(int i=0;i<r;i++)
	{
		message[n+i] = 0;
	}
	for(int i=0;i<n+r;i++)
	{
		temp[i] = message[i];
	}
	division(temp,gen,n,r);
	cout<<"CRC : ";
	for(int i=0;i<r;i++)
	{
    	cout<<temp[n+i]<<" ";
    	message[n+i] = temp[n+i];
	}
    cout<<endl<<"Transmitted Message : ";
    for(int i=0;i<n+r;i++)
    {
    	cout<<message[i]<<" ";
	}
    cout<<endl<<endl<<"At Receiver's End "<<endl;
	cout<<"Enter the received message : ";
	for(int i=0;i<n+r;i++)
	{
		cin>>message[i];
	}
	for(int i=0;i<n+r;i++)
	{
		temp[i] = message[i];
	}
    
	division(temp,gen,n,r);
    for(int i=0;i<r;i++)
	{
    	if(temp[n+i])
    	{
        	cout<<"Error detected in received message.";

    	} 
	}
	cout<<"No error in received Message.\nReceived Message : ";
	for(int i=0;i<n;i++)
	{
		cout<<message[i]<<" ";	
	}
}

int main(int argc, char** argv) 
{
    int ch, a=1;
    
    while(a)
	{
    	cout<<"\n*********Error Detection************* \n";
    	cout<<"\n1.Cyclic redundancy check.\n2.Hamming code\n3.Parity check\n";
    	cout<<"\nEnter your choice : ";
    	cin>>ch;
    	
    	switch(ch)
	    {
    	    case 1:
        		cyclic_redundancy_check();
        	    break;
        	case 2:
				hamming_code();
        	    break;
        	case 3:
			    parity_check();
            	break;
        	default:
			    cout<<"\nWrong choice.";
    	}
    	
   		cout<<"\n\nDo you want to continue(1/0) : ";
    	cin>>a;
    }
    return 0;
}
