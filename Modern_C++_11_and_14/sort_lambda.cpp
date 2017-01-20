#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

#define NUM_VECTORS 4
#define NUM_ELEMENTS 2

using namespace std;

int main() {
    srand(time(NULL));
    vector<vector<int> > a(NUM_VECTORS, vector<int>(NUM_ELEMENTS));
    for (int i =0; i < NUM_VECTORS; i++) {
        a[i][0] = rand() % 100 + 1;
        a[i][1] = rand() % 100 + 1;
    }
    cout << "Printing before sorting." << endl;
    for (int i = 0; i < NUM_VECTORS; i++)
        cout << a[i][0] << " " << a[i][1] << endl;

    // Take a deep look to the below 3 lines of code. You can observe the
    // next 3 things:
    // 1. We are using the STL's sort version with 3 parameters.
    // 2. We have three parameters:
    //    - Parameter 1 and 2 are the start and end of the vector to sort.
    //      In our case is a vector of vectors.
    //    - Parameter 3 is the lambda function used as helper to sort the
    //      vectors, which is indeed a function.
    // 3. The lambda function present the next characteristics:
    //     - Definition:
    //         [](const std::vector<int>& a, const std::vector<int>& b)
    //            { return a[0] > b[0];});
    //     - We can observe the next:
    //        - The body of the lambda function doesn't access variables
    //          others than the passed as parameters.
    //            check the "capture clause topic".
    //        - It receives the first and last positions of the vector to sort.
    //        - We define the sorting strategy with: "return a[0] > b[0];",
    //          basically it compares each first element of the vectors to sort
    //          and order them in descending order. Take a look to std::sort()
    //          to understand a little bit better how it works.
    sort(a.begin(), a.end(),
       [](const std::vector<int>& a, const std::vector<int>& b)
       { return a[0] > b[0];});


    cout << "Printing after sorting." << endl;
    for (int i = 0; i < NUM_VECTORS; i++) {
        cout << a[i][0] << " " << a[i][1] << endl;
    }

    return 0;
}
