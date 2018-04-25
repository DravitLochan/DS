#include <iostream>

using namespace std;

struct Node {
	int value;
	Node *next;
};

void insert(struct Node *head, int v){
	struct Node *ptr = new Node;
	while(head -> next)
		head = head -> next;
	ptr -> value = v;
	ptr -> next = NULL;
	head -> next = ptr;
}

void printList(struct Node *head){
	head = head -> next;
	while(head){
		cout << " -> " << head -> value;
		head = head -> next;
	}
}

void swap(struct Node *head, int x, int y){
	struct Node *p1, *p2, *p3, *p4, *prev;
	prev = head;
	head = head -> next;
	while(head){
		if(head -> value == x){
			p2 = head;
			p1 = prev;
		}
		if(head -> value == y){
			p4 = head;
			p3 = prev;
		}
		prev = head;
		head = head -> next;
	}
	p1 -> next = p4;
	p3 -> next = p2;
	struct Node *temp = p4 -> next;
	p4 -> next = p2 -> next;
	p2 -> next = temp;
}

int main(){
	struct Node *head = new Node;
	head -> next = NULL;
	insert(head, 1);
	insert(head, 2);
	insert(head, 3);
	// insert(head, 4);
	// insert(head, 5);
	// insert(head, 6);
	// insert(head, 7);
	// insert(head, 8);
	printList(head);
	cout << "\n";
	swap(head, 1, 3);
	printList(head);
	return 0;
}
