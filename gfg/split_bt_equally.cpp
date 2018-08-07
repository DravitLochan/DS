// C++ program to check if there exist an edge whose
// removal creates two trees of same size
#include<bits/stdc++.h>
using namespace std;
int n;
struct Node
{
	int data;
	struct Node* left, *right;
};

struct Node* newNode(int x)
{
	struct Node* temp = new Node;
	temp->data = x;
	temp->left = temp->right = NULL;
	return temp;
};

int countNodes(struct Node *root){
	if(!root)
		return 0;
	int s = 0;
	if(root -> left)
		s += 1 + countNodes(root -> left);
	if(root -> right)
		s += 1 + countNodes(root->right);
	return s;
}

bool checkSplit(struct Node *root, int a){
	if(!root)
		return n == 0;
	bool x = checkSplit(root -> right);
	
}

int main()
{
	struct Node* root = newNode(5);
	root->left = newNode(1);
	root->right = newNode(6);
	root->left->left = newNode(3);
	root->right->left = newNode(7);
	root->right->right = newNode(4);
	n = countNodes(root);
	if(n % 2)
		cout << "NO\n";
	else
		cout << checkSplit(root, 0);
	// check(root, status)? printf("YES") : printf("NO");

	return 0;
}
