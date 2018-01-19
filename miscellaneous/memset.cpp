#include<iostream>
#include<string.h>
using namespace std;

/*
	o/p will be 
	0 0 2147483392 2147483647 2147483647 2147483647 2147483647 2147483647 2147483647 2147483647
	1 4
	memset(ptr, value, n)
	Though memset sets left n number of Bytes of ptr to value, here it is setting first 8 Bytes to 0 and then 12th Byte to 0.

*/

int main() {
	int a[10];
	for(int i = 0; i < 10; ++i)
		a[i] = 2147483647;
	memset(a, 0, 9);	
	for(int i = 0; i < 10; ++i)
		cout<<a[i] << " ";
	cout<<"\n";
	cout<<sizeof(char) << " " <<sizeof(int) << "\n";	
	return 0;
}
