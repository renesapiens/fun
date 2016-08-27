#include <iostream>
#include <deque>

using namespace std;

// This is a very well known problem that can easily be found
// in google as 'maximum sliding window' where basically we are
// moving over an array printing each max value for each sub-array
// (or window). You can take a look to the explanation and
// code from:
// http://articles.leetcode.com/sliding-window-maximum/

void printKMax(int arr[], int n, int k){
   deque <int> q;

    // First we need to take care of the first window.
    // We will ensure that the highest element of the window is always in
    // the front of the deque, for that reason on each iteration (i) we
    // remove all the elements in the back of the deque with lower that
    // the current element in the array. This is done in this first while
    // loop.
    for (int i = 0; i < k; i++) {
        while(!q.empty() && arr[i] >= arr[q.back()]) {
            q.pop_back();
        }
        //Each element in the array 'arr' is added at some time into the
        // queue elements with lower value that the current maximum one
        // are removed with the previous while loop.
        q.push_back(i);
    }

    // Section 2.
    // By this point we already checked the first window and all the remaining
    // sections will be taken care in the next for loop.
    for (int i = k; i < n; i++) {
        cout << arr[q.front()] << " ";
        while (!q.empty() && arr[i] >= arr[q.back()])
            q.pop_back();
        //let's remove the elements that are out of the window from the front.
        // As you can see we are attacking the deque in the front as well, but
        // now we only remove the elements that are not part of the subarray
        // and for that reason not valid.
        while(!q.empty() && q.front() <= i-k)
            q.pop_front();
        q.push_back(i);
    }
    cout << arr[q.front()] << " ";
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t>0) {
        int n,k;
        cin >> n >> k;
        int i;
        int arr[n];
        for(i=0;i<n;i++)
            cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}
