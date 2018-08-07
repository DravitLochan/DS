	#include <iostream>
#include <algorithm>

#define loop(i, x, y)   for(int i = int(x); i < int(y); ++i)
#define inf 1e9+7

using namespace std;

int ans(int a[], int x, int l, int r){
	// cout << l << " " << r << "\n";
    if(l > r)
        return inf;
    int mid = (l + r) / 2;
    // cout << a[mid] << "\n";
    if(a[mid] == x)
        return mid;
    if(mid != l && mid != r){
        if(a[mid] > a[mid - 1] && a[mid] > a[mid + 1]){
            if(a[mid] < x)
                return inf;
            else
                return min(ans(a, x, l, mid - 1), ans(a, x, mid + 1, r));
        } else if(a[mid] > a[mid - 1] && a[mid] < a[mid + 1]){
            if(a[mid] < x)
                return ans(a, x, mid + 1, r);
            else
                return min(ans(a, x, l, mid - 1), ans(a, x, mid + 1, r));
        } else if(a[mid] < a[mid - 1] && a[mid] > a[mid + 1]){
            if(a[mid] < x)
                return ans(a, x, l, mid - 1);
            else
                return min(ans(a, x, l, mid - 1), ans(a, x, mid + 1, r));
        }
    } else {
    	if(mid == l)
    		return ans(a, x, mid + 1, r);
    	else if(mid == r)
    		return ans(a, x, l ,mid - 1);
    }
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n, x, i;
	    cin >> n >> x;
	    int a[n];
	    loop(i, 0, n){
	        cin >> a[i];
	    }
	    int r = ans(a, x, 0, n - 1);
	    r == inf ? cout << "OOPS! NOT FOUND" : cout << r;
	    cout << "\n";
	}
	return 0;
}