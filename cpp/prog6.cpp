#include <iostream>
using namespace std;

int main()
{   int sum = 0;
    int val;
    cout << "Enter the number " << endl;
    cin >> val;
    for(int i=1; i<=val; i++)
    {
        sum += i; 
    }
    cout << "Sum of 1 to "<< val << " = " << sum << endl;
    return 0;
}