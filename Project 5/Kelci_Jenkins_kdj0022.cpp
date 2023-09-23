//
//  secure_coding.cpp
//

#include <iostream>

using namespace std;
int main(void)
{
    int tests[10];
    int test;
    int num_elems;
   
    while (true) {
            cout << "How many numbers? ";
            cin >> num_elems;
            
            if (num_elems <= 10) { // confirms if the inputted number is less than or equal to 10.
                break; // begins the for loop when confirmed.
            } else {
                cout << "Error: Must be less than or equal to 10. Try again" << endl;
            }
        }
    
    for (int i = 0; i < num_elems; i++)
    {
        cout << "Please type a number: ";
        cin >> test;
        tests[i] = test;
    // if "i" is less than 10 test will update. else an error message will appear
        if (i < 10) {
            tests[i] = test;
        }
        else {
            cout << "Error: Must be less than or equal to 10" << endl;
        }
    }
    return 0;
}
