#include <iostream>
#include <string>
 using namespace std;
 
 /*This function convertIPToDecimal takes an IP address in the form of a string and converts it to a decimal representation. 
 It uses bitwise operations to combine the octets into a single integer. The function returns the resulting decimal representation.*/
int convertIPToDecimal(string ip) {
    int octet, result = 0;
    size_t pos = 0;

    for (int i = 0; i < 4; ++i) {
        octet = 0;
        while (pos < ip.size() && ip[pos] != '.') {
            octet = octet * 10 + (ip[pos] - '0');
            ++pos;
        }
        result = (result << 8) | octet;
        ++pos;  
    }

    return result;
}

void subnetCalculator(string ipAddress,string subnetMask) {
    int ip = convertIPToDecimal(ipAddress);
    int subnet = convertIPToDecimal(subnetMask);

    // Calculate network address
    int network = ip & subnet;

    // Calculate broadcast address
    int invertedSubnet = ~subnet;
    int broadcast = ip | invertedSubnet;

    // Calculate usable IP range
    int firstUsable = network + 1;
    int lastUsable = broadcast - 1;

    // Display results
    std::cout << "Network Address: " << ((network >> 24) & 0xFF) << '.' << ((network >> 16) & 0xFF) << '.' << ((network >> 8) & 0xFF) << '.' << (network & 0xFF) << std::endl;
    std::cout << "Broadcast Address: " << ((broadcast >> 24) & 0xFF) << '.' << ((broadcast >> 16) & 0xFF) << '.' << ((broadcast >> 8) & 0xFF) << '.' << (broadcast & 0xFF) << std::endl;
    std::cout << "Usable IP Range: " << ((firstUsable >> 24) & 0xFF) << '.' << ((firstUsable >> 16) & 0xFF) << '.' << ((firstUsable >> 8) & 0xFF) << '.' << (firstUsable & 0xFF) << " - " << ((lastUsable >> 24) & 0xFF) << '.' << ((lastUsable >> 16) & 0xFF) << '.' << ((lastUsable >> 8) & 0xFF) << '.' << (lastUsable & 0xFF) << std::endl;
}

int main() {
    std::string ipAddress, subnetMask;
    std::cout << "Enter IP Address: ";
    std::cin >> ipAddress;
    std::cout << "Enter Subnet Mask: ";
    std::cin >> subnetMask;

    subnetCalculator(ipAddress, subnetMask);//subnetCalculator function

    return 0;
}
