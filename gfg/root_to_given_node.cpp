#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};

struct Node* newNode(int data)
{
	struct Node *newNode = new Node;
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

bool printPath(Node *root, int x){
	if(!root)
		return false;
	if(root->data == x){
		cout << root->data << " ";
		return true;
	}
	if(printPath(root->left, x)){
		cout << root -> data << " ";
		return true;
	} else if(printPath(root -> right, x)){
		cout << root -> data << " ";
		return true;
	}
	return false;
}


int main()
{
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->left = newNode(6);
	root->left->right->right = newNode(7);
	root->left->left->right = newNode(8);
	root->left->left->right->left = newNode(9);
		
	int x = 9;
	printPath(root, x);
	return 0;
} 
