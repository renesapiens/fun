#include <iostream>
#include <vector>

using namespace std;

void clean_cin()
{
    while (cin.get() != '\n')
       continue;    
}

int main()
{

    int n;
    int queries;
    int q;
    vector <int> vqueries;

    cin >> n;
    clean_cin();

    vector<int> values(n);

    for (auto& element : values) {
       cin >> element;
    }

    cin >> queries;

    for (int i = 0; i < queries ; i++) {
        cin >> q;
        auto begin = values.begin();
        auto end =  values.end();
        auto lower = lower_bound(begin, end, q);

        cout << (*lower == q ? "Yes " : "No ") << lower - begin + 1  << "\n";
     }
     return 0;
 }
