#include <iostream>
#include <vector>

#define loop(i, x, y)	for(int i = int(x); i < int(y); ++i)

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, i, d;
		cin >> n;
		int a[n];
		for(i = 0; i < n; ++i)	cin >> a[i];
		cin >> d;
		vector<int> temp;
		loop(i, d, n){
			temp.push_back(a[i]);
		}
		loop(i, 0, d){
			temp.push_back(a[i]);
		}
		loop(i, 0, n){
			cout << temp[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}