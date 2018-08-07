// C code to modify binary tree for
// traversal using only right pointer
#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// A binary tree node has data,
// left child and right child
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

// function that allocates a new node
// with the given data and NULL left
// and right pointers.
struct Node* newNode(int data)
{
	struct Node* node = new struct Node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

// Function to modify tree
struct Node* modifytree(struct Node* root){
	struct Node *ptr = root;
	while(ptr){
		// cout << 1;
		if(ptr->left){
			struct Node *t = ptr->left;
			while(t->right){
				t = t -> right;
			}
			t -> right = ptr -> right;
			ptr -> right = ptr -> left;
			// cout << 1;
		}
		ptr = ptr -> right;
	}
	return root;
}

// printing using right pointer only
void printpre(struct Node* root)
{
	while (root != NULL) {
		cout << root->data << " ";
		root = root->right;
	}
}

// Driver program to test above functions
int main()
{
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	// cout << "erfg";
	modifytree(root);
	printpre(root);
	return 0;
}
