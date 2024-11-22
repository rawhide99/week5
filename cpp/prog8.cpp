#include <iostream>
using namespace std;

int main() 
{
    int num=0;
    cout << "Enter the number " << endl;
    cin >> num;
    if(num > 10)
    {
        cout << "The number is greater than 10 " << endl;
    }
    else if (num < 10)
    {
        cout << "The number is less than 10" << endl;
    }
    
    else    
        cout << "The number is equal to 10" << endl;
    return 0;
}