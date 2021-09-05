// CPP program to illustrate the
// list::erase() function
#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Creating a list
	list<int> demoList;

	// Add elements to the List
	demoList.push_back(10);
	demoList.push_back(20);
	demoList.push_back(30);
	demoList.push_back(40);
	demoList.push_back(50);
  	demoList.push_back(60);
  	demoList.push_back(70);
  	demoList.push_back(80);
  	demoList.push_back(90);
  	demoList.push_back(100);
  	demoList.push_back(110);
  	demoList.push_back(120);
  

	// Printing elements of list before deleting
	// any element
  	cout << "first element in queue is " << *demoList.begin() << "\n";
  
    cout << "last element in queue is " << *demoList.rbegin() << "\n";
  
	cout << "List before deleting any element: ";
	for (auto itr = demoList.begin();
		itr != demoList.end(); itr++) {
		cout << *itr << " ";
	}

	// Creating iterators of the list
	list<int>::iterator itr1, itr2, itr3, itr4;
	itr1 = demoList.begin();
	itr2 = demoList.begin();
  
  	itr3 = demoList.begin();

  	advance(itr3, 10);
  	
  	cout << "\n\nitr3 points to " << *itr3 << " before delete\n\n";
	// Incrementing itr2 by 3 positions
  	advance(itr1, 2);
  	advance(itr2, 3);

	// deleting range of elements from index [0, 3)
	demoList.erase(itr1, itr2);

  	cout << "itr3 points to " << *itr3 << " after delete\n\n";

  	itr1 = demoList.begin();
	itr2 = demoList.begin();
  
  	advance(itr1, 6);
  	advance(itr2, 7);
    	cout << "2 \n\nitr3 points to " << *itr3 << " before delete\n\n";

  	demoList.erase(itr1, itr2);
  
    	cout << "2 itr3 points to " << *itr3 << " after delete\n\n";
  
  		cout << "advancing itr 4 by 1\n";
  
  		itr4 = itr3;
  		advance(itr4, 1);
  
      	cout << "3 itr3 points to " << *itr3 << "\n";
        
        cout << "3 itr4 points to " << *itr4 << "\n";

	// Printing elements of list after deleting
	// range of elements from [0, 3)
	cout << "\nList after deleting first three elements: ";
	for (auto itr = demoList.begin();
		itr != demoList.end(); itr++) {
		cout << *itr << " ";
	}

	return 0;
}

/**
first element in queue is 10
last element in queue is 120
List before deleting any element: 10 20 30 40 50 60 70 80 90 100 110 120 

itr3 points to 110 before delete

itr3 points to 110 after delete

2 

itr3 points to 110 before delete

2 itr3 points to 110 after delete

advancing itr 4 by 1
3 itr3 points to 110
3 itr4 points to 120

List after deleting first three elements: 10 20 40 50 60 70 90 100 110 120 
*/
