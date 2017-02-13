#include <iostream>
using namespace std;


/* Example of using 'mutable'
*/
int main() {

    int items = 3;

    // Use mutable to modify the variable items even
    // it it was passed by value.
    [items]() mutable {
        // Only the copy of items is changed. mutable is needed
        // to change it even if after leaving the lambda expression
        // Its values will return to 3.
        items = 4;
        cout << "Val of items inside lambda: " << items << endl;
    }();

    // Observe how the value of items did not change after leaving the
    // Lambda expression. Still mutable was needed to be able to change
    // its value inside the lambda expression.
    cout << "Val of item after: " << items << endl;
    return 0;
}
