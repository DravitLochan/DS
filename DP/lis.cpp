#include<iostream>
using namespace std;
//{10 22 9 33 21 50 41 60};
//{22 9 10 11 12 13 14 15 16 17 18 19 20 21 22 33 50 41 60}
int lis(int arr[], int indices[], int size)
{
	int i, j, lis;
	for( i = 0; i < size; ++i)
	{
		//cout<<arr[i]<<"-> ";
		for (j = 0; j < i; ++j)
		{
			if( arr[j] < arr[i] )
			{
				lis = indices[i];
				int a = indices[j] + 1;
				indices[i] = a > lis ? a : lis;
				//cout << indices[i];
			}
		}
		//cout<<"\n";
	}
	lis = indices[0];
	for( i = 1; i < size; ++i)
		lis = indices[i] > lis ? indices[i] : lis;
	return lis;	
}

int main()
{
	int i, n;
	cin>>n;
	int arr[n], indices[n] ;
	for (i=0; i<n; ++i)
	{
		cin>>arr[i];
		indices[i]=1;
	}
	cout<<lis(arr, indices, n);	
	return 0;
}
