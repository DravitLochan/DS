#include<bits/stdc++.h>

using namespace std;

vector <int> pre;
vector <char> preln;
int n, i;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node* newNode (int data)
{
	struct node *temp = new struct node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void printInorder (struct node* node)
{
	if (node == NULL)
		return;
	printInorder (node->left);
	printf("%d ", node->data);
	printInorder (node->right);
}

struct node * constructTree(){
	if(i >= n)
		return NULL;
	struct node *root = newNode(pre[i]);
	char c = preln[i++];
	if(c=='n'){
		root -> left = constructTree();
		root -> right = constructTree();
	}
	return root;
}

int main()
{
	struct node *root = NULL;
	cin >> n;
	pre.resize(n);
	preln.resize(n);
	for(i = 0; i < n; ++i)	cin >> pre[i];
	for(i = 0; i < n; ++i)	cin >> preln[i];	
	i = 0;
	root = constructTree();

	printf("Following is Inorder Traversal of the Constructed Binary Tree: \n");
	printInorder (root);

	return 0;
}
