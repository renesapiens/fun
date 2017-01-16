#include <iostream>
#include <cstring>

//Triple step. A child is running up a staircase with n steps and can hop
//either 1 step, 2 step or 3 steps at a time. Implement a method to count
//how many possible ways the child can run up the stairs.

int step(int* arr, int n)
{
    if (n < 0)
        return 0;
    else if (n == 0) //Base case, 0 means we ran out of steps
        return 1;
    else if (arr[n] == -1) //Value doesn't exist in the array,  calcule it.
        arr[n] = step(arr, n-1) + step(arr, n-2) + step(arr, n-3);
    return arr[n];
}

int steps(int n)
{
    //Use an array to store the value being calculated (memoization).
    int arr[n + 1];

    std::fill_n(arr, n + 1, -1);
    return step(arr, n);
}

int main()
{
    int n;

    std::cout << "Enter the number of steps." << std::endl;
    std::cin >> n;
    std::cout << "The steps for " << n << " is: " << steps(n) << std::endl;
}
