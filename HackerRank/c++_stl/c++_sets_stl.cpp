#include <iostream>
#include <set>

using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;

    cin >> n;
    set <int> elements;
    int value;
    int action;


    for (int i = 0; i < n; i++) {
        //Get the values.
        cin >> action >> value;
        if (action == 1) {
         //Add the element to the set.   
            elements.insert(value);
         }
        //Delete an element from the set
        if (action == 2) {              
       
            elements.erase(value);
        }
        if (action == 3) {
           //print yes or no.
           cout << (elements.count(value)? "Yes" : "No") << endl;
       }
    }
    return 0;
}
