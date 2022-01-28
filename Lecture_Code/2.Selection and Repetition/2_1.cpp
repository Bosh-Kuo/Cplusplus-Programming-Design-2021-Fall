// ============================================
// Control Statements (p. 12)

#include <iostream>
using namespace std;

int main()
{
    double income = 0, tax = 0; 

    cout << "Please enter the taxable income: ";
    cin  >> income;

    if(income <= 10000)
    tax = 0.02 * income;
    else
    tax = 0.08 * (income - 10000) + 10000 * 0.02;

    cout << "Tax amount: $" << tax << "\n";
    return 0;
}
