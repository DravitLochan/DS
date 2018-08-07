#include <iostream>
#include <vector>

// you simply cannot use push_back and erase all together in a program

using namespace std;
vector <int> a;
int n;
int main() {
	// your code goes here
	int t = 2;
	while(t--){
		cin >> n;
		for(int i = 0; i < 10; ++i)	a.push_back(i);
		
		for(int i = 0; i < 10; ++i)	a.erase(a.begin() + i);
	}
	/*a.push_back(200);
	a.clear();
	cout << a.size() << "\n";
	a.resize(20);
	cout << a.size() << "\n";*/
	return 0;
}