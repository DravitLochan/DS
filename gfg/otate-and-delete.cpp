#include <iostream>
#include <vector>

#define loop(i, x, y)   \
    for(int i = int(x); i < int(y); ++i)

#define inf 1e9+7
#define pb push_back

using namespace std;

void rotate(int a[], int sz){
    vector<int> t;
    t.pb(a[sz - 1]);
    loop(i, 0, sz - 1){
        t.pb(a[i]);
    }
    loop(i, 0, sz){
        a[i] = t[i];
    }
}

void del(int a[], int &sz, int pos){
    int j = 0;
    while(j < pos){
        ++j;
    }
    while(j < sz - 1){
        a[j] = a[j + 1];
        ++j;
    }
    --sz;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int sz;
        cin >> sz;
        int a[sz];
        int x;
        for(int i = 0; i < sz; ++i){
            cin >> a[i];
        }
        int j = 1;
        while(sz != 1){
            // cout << "#\n";
            rotate(a, sz);
            /*loop(i, 0, sz){
                cout << a[i] << " ";
            }
            cout << "\n";*/
            del(a, sz, sz - j);
            /*loop(i, 0, sz){
                cout << a[i] << " ";
            }
            cout << "\n";*/
            if(sz - j < 0)
                j = sz;
            else
                ++j;
        }
        cout << a[0] << "\n";
    }
    return 0;
}