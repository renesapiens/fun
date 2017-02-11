#include <iostream>
using namespace std;

/*
Lambda examples.
1. Capture all local variables by value.
2. Capturing  two variables by value.
3. Capturing one variable by value and one by reference.
4. By default capture all local variables by reference.
5. Capture all local variables by reference except two,
   those two capture them by value.
*/
int main() {
    int var1 = 1;
    int var2 = 2;
    int var3 = 3;


    // 1. Capture all local vairables by value.
    // The '=' symbol meands that even if we modify var1 and
    // var2 their value won't change after the lambda expression.
    // Since both were passed by value.
    [=](){cout << var1 << ", " << var2 << endl;}();

    // 2. Capture two variables by value:
    // By not using = or & and adding specific variables into the bracktes []
    // We are making those variables to be passed by value.
    [var1, var2](){cout << var1 << ", " << var2 << endl;}();



    // 3. Capturing one variable by value and one by reference.
    [=, &var3]() {var3 = 333; cout << var1 << ", " << var2 << endl;}();
    cout << var3 << endl; // Observe how its value has changed.

    // 4. By default capture all local variables by reference.
    [&](){var2=22; var1 = 313; cout << var1 << ", " << var3 << endl;}();
    cout << var2 << endl;

    // 5. Capture all local variables by reference except two,
    // those two capture them by value.
    [&, var3, var2](){var1=111; cout << var1 <<", " << var2 << endl;}();
    cout << var1 << endl;
    return 0;
}
