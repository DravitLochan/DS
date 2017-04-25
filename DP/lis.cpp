#include<iostream>
using namespace std;

int lis(int arr[], int indices[], int size, int i)
{
	if(i == 0)
	{
		indices[i] = 1;
	}
	if()
}

int main()
{
	int i, n;
	cin>>n;
	int arr[n], indices[n];
	for (i=0; i<n; ++i)
		cin>>arr[i];
	cout<<lis(arr, indices, n, 0);	
}
