#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main(){
	int n, m, q, i, j;
	string s, t;
	while(q--){
		int ctr = 0;
		int l, r;
		cin >> l >> r;
		for(i = l - 1; i < r; ++i){
			if(r - i < t.length()){
				break;
			}
			if(s.substr(i, t.length()) == t)
				++ctr;
		}
		cout << ctr << "\n";
	}
	return 0;
}