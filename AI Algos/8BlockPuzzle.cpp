#include<iostream>

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

int main(){
	int goal[][3] = {1, 2, 3, 8, 0, 4, 7, 6, 5};
	int current[][3] = {2, 8, 3, 1, 6, 4, 7, 0, 5};
	// int current[][3] = {8, 1, 2, 7, 0, 3, 6, 5, 4};
	int fill[2][4] = {-1, 0, 1, 0, 0, 1, 0, -1};
	// manhatanDistance(goal, current);
	int manDistance = manhatanDistance(goal, current);
	cout<< manDistance<<"\n";
	return 0;
}
