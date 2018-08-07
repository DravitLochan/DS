#include<bits/stdc++.h>
using namespace std;
#define MAX 100

struct Node{
	int data;
	Node *left, *right;
};

int n;
int mat[MAX][MAX];

void ancestorMatrix(Node *root){
	if(!root)
		return ;
	if(root -> left){
		int j = root->data, k = root->left->data;
		for(int i = 0; i < n; ++i){
			mat[i][k] = mat[i][j];
		}
		mat[j][k] = 1;
		ancestorMatrix(root->left);
	}
	if(root -> right){
		int j = root -> data, k = root->right->data;
		for(int i = 0; i < n; ++i){
			mat[i][k] = mat[i][j];
		}
		mat[j][k] = 1;
		ancestorMatrix(root->right);
	}
}

Node* newnode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

int main()
{
	/* Construct the following binary tree
				5
			/ \
			1	 2
		/ \ /
		0 4 3 */
	Node *root	 = newnode(5);
	root->left	 = newnode(1);
	root->right	 = newnode(2);
	root->left->left = newnode(0);
	root->left->right = newnode(4);
	root->right->left = newnode(3);
	n = 6;
	memset(mat, 0, sizeof mat);
	ancestorMatrix(root);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j)
			cout << mat[i][j] << " ";
		cout << "\n";	 
	}
	return 0;
}
