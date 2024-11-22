#include <iostream>
using namespace std;

int main()
{
      int choice;
      cout << "Enter the choice " << endl << "1 - Tea" << endl << "2 - Coffee" << endl;
      cin >> choice;
      if(choice == 1)
      {
        cout << " Your Tee is on the way. Thank You" << endl;
      }
      else if (choice == 2)
      {
        cout << "Your coffee is on the way. Thank You" << endl;
      }
      else 
        cout << "You enter wrong info" << endl;
      return 0;
}