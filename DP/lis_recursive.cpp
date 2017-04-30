#include<iostream>
using namespace std;

//{10 22 9 33 21 50 41 60};
//{22 9 10 11 12 13 14 15 16 17 18 19 20 21 22 33 50 41 60}

int lis(int arr[], int n, int *max_len)
{
	if(n == 1)
	{
		return 1;
	}
	int cur_len = 1;
	for(int i = 0; i < n-1; ++i)
	{
		int len = lis(arr, i, max_len);
		if((len + 1 > cur_len) && (arr[i]<arr[n-1]))
			cur_len = len + 1;	
	}
	if(cur_len > *max_len)
		*max_len = cur_len ;
	cout<<*max_len<<"\n";
	return cur_len;	
}

int _lis(int arr[], int n)
{
	int max_len = 1; 
	lis(arr, n, &max_len);
	return max_len;
}

int main()
{
	int i, n;
	cin>>n;
	int arr[n];
	for (i=0; i<n; ++i)
		cin>>arr[i];
	cout<<_lis(arr, n);	
	return 0;
}
