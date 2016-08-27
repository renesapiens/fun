#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int main() {
    int q;
    string mstring;
    int val_num;
    int marky;
    map<string, int> mmap;
    map<string, int>::iterator it;

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> val_num; cin>>mstring;

        if (val_num == 1) {
            cin >> marky;
            it = mmap.find(mstring);
            if (it == mmap.end())
                mmap.insert(make_pair(mstring, marky));
            else
                mmap[mstring] = mmap[mstring] + marky;
        }

        if (val_num == 2) {
            mmap.erase(mstring);
        }

        if (val_num == 3) {
            it = mmap.find(mstring);

            if (it == mmap.end())
                cout <<"0" << endl;
            else
                cout << mmap[mstring] << endl;
        }
    }
    return 0;
}
