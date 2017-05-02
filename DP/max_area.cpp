#include<iostream>
#include<limits.h>
using namespace std;

/*
	Suppose you are given an m× n bitmap, represented by an array M [1 .. n,1 .. n] of 0s and 1s. A solid block
	in M is a sub array of the form M [i .. i’ , j .. j’] containing only 1-bits. A solid block is square if it has the same
	number of rows and columns.
	(a) Describe an algorithm to find the maximum area of a solid square block in M
	(b) Describe an algorithm to find the maximum area of a solid block in M
*/


int main()
{
	int i, j, n, r, c, max_r = INT_MIN, min_r = INT_MIN;
	cin>>n;
	int arr[n][n], solid_square[n][n];
	
	for(i = 0; i < n ; ++i)
		for(j = 0; j < n; ++j)
		{
			cin>>arr[i][j];
			solid_square[i][j] = -1;
		}
	
	if(arr[0][0] == 1)
		solid_square[0][0] = 1;
	else
		solid_square[0][0] = 0;	
				
			
	for(i = 1 ; i < n ; ++i)
		if(arr[i][0]==1)
			solid_square[i][0] = max(arr[i][0], solid_square[i-1][0]+1);		
	
	for(j=0; j<n;++j)
		if(arr[0][j] == 1)
			solid_square[0][j] = max(arr[0][j], solid_square[0][j-1]+1);						
	
	//a -> square
	for(i = 1; i<n ;++i)
	{
		for(j = 1; j<n; ++j)
		{
			if(arr[i][j])
				solid_square[i][j] = (arr[i-1][j-1]==1&&arr[i][j-1]==1&&arr[i-1][j]==1)?solid_square[i-1][j-1]+1:1;
		}
	}
	
	int max = INT_MIN;		
	for(i=0; i<n; ++i)
	{
		for(j= 0; j<n; ++j)
		{
			if(solid_square[i][j]>max)
				max = solid_square[i][j];
		}
	}
	
	cout<<max;
}
