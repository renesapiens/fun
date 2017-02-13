#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


//Using a function
bool check(string &test) {
    return test.size() == 3;
}


//Using a functor.
class Check {
public:
    bool operator()(string &test) {
        return test.size() == 5;
    }
}check1;


//Using function<>
void run(function<bool(string&)> check) {
    string test = "dog";
    cout << check(test) << endl;
}


int main() {

    int size = 5;
    vector<string> vec{"one", "two", "three"};

    int count = count_if(vec.begin(), vec.end(),
            [size](string test){return test.size() == 3;});
    cout << count << endl;

    count = count_if(vec.begin(), vec.end(), check);
    cout << count << endl;


    count = count_if(vec.begin(), vec.end(), check1);
    cout << count << endl;

    auto lambda = [size](string test) {return test.size() == size;};
    int count2 = count_if(vec.begin(), vec.end(), lambda);


    run(lambda);
    run(check1);

    function<int(int, int)> add =  [](int one, int two){return one+two;};
    cout << add(7, 3) << endl;

    return 0;
}

