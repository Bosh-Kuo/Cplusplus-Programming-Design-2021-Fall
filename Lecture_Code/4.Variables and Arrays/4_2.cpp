// ============================================
// Variables and Arrays (p. 8)

#include <iostream>
using namespace std; 

int main()
{
    cout << "int " << sizeof(int) << "\n";
    cout << "char " << sizeof(char) << "\n";
    cout << "bool " << sizeof(bool) << "\n";

    short s = 0;
    cout << "short int " << sizeof(s) << "\n";
    long l = 0;
    cout << "long int " << sizeof(l) << "\n";

    cout << "unsigned short int " << sizeof(unsigned short) << "\n";
    cout << "unsigned int " << sizeof(unsigned) << "\n";
    cout << "unsigned long int " << sizeof(unsigned long) << "\n";
    return 0; 
}