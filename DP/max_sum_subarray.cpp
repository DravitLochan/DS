#include<iostream>
#include<limits.h>
using namespace std;
//{5 15 -30 10 -5 40 10}

int maxSubArray(int arr[], int n)
{
	int  i, max = INT_MIN, max_iterate = 0;
	for(i = 0; i<n; ++i)
	{
		max_iterate += arr[i];
		if(max_iterate < 0)
			max_iterate = 0;
		else if(max < max_iterate)
			max = max_iterate;
				
	}
	
	return max;
}

int main()
{
	int i, n;
	cin>>n;
	int arr[n];
	for (i=0; i<n; ++i)
		cin>>arr[i];
	cout<<maxSubArray(arr, n);	
	return 0;
}
