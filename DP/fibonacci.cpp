#include<iostream>
using namespace std;
int arr[50]={-1};

int fibonacci (int n) 
{
	if(n == 1)
	{
		arr[n] = 0;
	}
	else if(n == 2 || n == 3)
	{
		arr[n] = 1 ;
	}
	else if(arr[n] == -1)
	{
		return arr[n];		
	}
	else
	{
		arr[ n ] = fibonacci( n-1 ) + fibonacci ( n-2 );
	}
	return arr[n];
}

int main() {
	int n;
	cout<<"Enter a number smaller than 49 : \n";
	cin>>n;
	cout<<fibonacci(n);
}
