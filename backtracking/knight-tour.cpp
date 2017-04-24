#include<iostream>

using namespace std;

int sol_pos(int **board, int r, int c, int n)
{
	if(r>=n||c>=n||r<0||c<0)
		return 0;
	if(*(*(board+c)+r)==-1)
		return 1;
	return 0;		
}

int solution(int **board, int row, int col, int ctr, int n)
{
	static int flag = 0;
	if(ctr==n*n)
		return 1;
	int Y[8]={1,2,2,1,-1,-2,-2,-1},X[8]={-2,-1,1,2,2,1,-1,-2},i,j;
	for(i=0;i<8&&!flag;++i)
	{
		//cout<<"1";
		if(sol_pos(board, row+X[i], col+Y[i], n))
		{
			//cout<<"1\n";
			*(*(board+row)+col) = ctr;
			if(solution(board, row+X[i], col+Y[i], ctr+1, n))
			{
				flag=1;
				return 1;
			}
			*(*(board+row)+col) = -1;
		}
	}
	return 0;	
}

void print_board(int **board,int n)
{
	int i,j;
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			cout<<*(*(board+i)+j)<<" ";
		}
		cout<<"\n";
	}
}


int main()
{
	int n;
	cout<<"Enter the value of n (number of rows in the chess board) : ";
	cin>>n;
	int **board;
	board=new int *[n];
	for(int i=0;i<n;++i)
	board[i]=new int[n];
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		*(*(board+i)+j)=-1;
	}
	if(solution(board, 0, 0, 0, n))
	print_board(board,n);
	else
	cout<<"no possible solution\n";
	return 0;
}
