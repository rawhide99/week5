#include <iostream>
using namespace std;

int main() 
{
    int sum=0;
    int count=1;
    int val;
    cout << "Enter the number will the sum has to be calculate" << endl;

    cin >> val;
    while(count<=val)
    {
        sum += count;
        count += 1;
        
    }
    cout << sum << endl;
    return 0;
}