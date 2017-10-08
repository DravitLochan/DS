#include<iostream>
#include<stdlib.h>
#include<limits.h>
#include<algorithm>

using namespace std;

int * findXPos(int goal[3][3], int x) {												// takes 2 parameters, returns a ptr where *pos = x coordinate
	int *pos = new int();															// and *(pos + 1) = y coordinate of element x in the goal state
	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 3; ++j){
			if(goal[i][j] == x){
				*pos = i;
				*(pos + 1) = j;
				return pos;
			}
		}	
}

int canTraverse(int moveX, int moveY, int moveFromX, int moveFromY){
	if((moveFromX + moveX >= 0) && (moveFromY + moveY >= 0) && (moveFromX + moveX < 3) && (moveFromY + moveY < 3))
		return 1;
	return 0;
}

int manhatanDistance(int goal[3][3], int current[3][3]){							// function to find manhatan distance
	int manDistance = 0;
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			if(current[i][j] == 0)
				continue;
			int *pos = findXPos(goal, current[i][j]);
			// cout<<*pos << "," << *(pos + 1) << ",";
			manDistance += (i - *pos < 0 ? *pos - i : i - *pos) + (j - *(pos + 1) < 0 ? *(pos + 1) - j : j - *(pos + 1));
			// cout<<manDistance<<"; ";
		}
		// cout<< "\n";
	}
	return manDistance;
}

void move(int current[3][3], int moveX, int moveY, int moveFromX, int moveFromY){
	int x = moveFromX + moveX;
	int y = moveFromY + moveY;
	swap(current[x][y], current[moveFromX][moveFromY]);
}

int main(){
	int goal[][3] = {1, 2, 3, 8, 0, 4, 7, 6, 5};
	int current[][3] = {2, 8, 3, 1, 6, 4, 7, 0, 5};
	// int current[][3] = {8, 1, 2, 7, 0, 3, 6, 5, 4};
	int fill[2][4] = {-1, 0, 1, 0, 0, 1, 0, -1};									// fill[0] = movement along the rows, fill[1] = movement along columns
	// manhatanDistance(goal, current);												// these movement are applied on 0.
	int manDistance = manhatanDistance(goal, current);
	// cout<< manDistance<<"\n";
	while(manDistance){
		int *pos = findXPos(current, 0);
		int manDistanceArray[4], tempArr[4];
		int i, tempCurrent[3][3];
		for(i = 0; i < 4; ++i){
			for(int j = 0; j<3; ++j)
				for(int k = 0; k<3; ++k)
					tempCurrent[j][k] = current[j][k];
			if(canTraverse(fill[0][i], fill[1][i], *pos, *(pos + 1))){
				move(tempCurrent, fill[0][i], fill[1][i], *pos, *(pos + 1));
				manDistanceArray[i]  = manhatanDistance(tempCurrent, goal);
			} else {
				manDistanceArray[i] = INT_MAX;
			}
		}
		cout<<"manDistanceArray : \n";
		for (int j = 0; j < 4; ++j)
		{
			tempArr[j] = manDistanceArray[j];
			cout<<manDistanceArray[j]<<" ";
		}
		sort(manDistanceArray, manDistanceArray + 4);
		cout<<"\n";
		for(int j = 0; j < 4; ++j){
				if(tempArr[j] == manDistanceArray[0])
					i =j;
		}
		if(manDistanceArray[0] > manDistance){
			cout << "no possible solution\n";
			exit(1);
		} else {
			cout<<"manDistanceArray[0] = "<<manDistanceArray[0]<<"\n";
			cout<<"i is "<<i<<"\n";
			manDistance =  manDistanceArray[0];
			move(current, fill[0][i], fill[1][i], *pos, *(pos + 1));
			cout<<"current : \n";
			for(int a = 0; a < 3; ++a)
				for(int b = 0; b < 3; ++b)
					cout<<current[a][b]<<" ";
			cout<<"\n";	
		}
	}
	return 0;
}
