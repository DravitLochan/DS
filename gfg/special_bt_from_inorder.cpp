#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node* left;
	struct node* right;
};

vector <int> in;
int n;

struct node* newNode (int data){
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

struct node* buildTree (int l, int r){
	if(l > r)
		return NULL;
	int pos = max(l, r);
	struct node *root = newNode(in[pos]);
	root->left = buildTree(l, pos - 1);
	root -> right = buildTree(pos + 1, r);
	return root;
}

int max(int strt, int end){
	int i, max = in[strt], maxind = strt;
	for(i = strt+1; i <= end; i++)
	{
		if(in[i] > max)
		{
			max = in[i];
			maxind = i;
		}
	}
	return maxind;
}

void printInorder (struct node* node){
	if (node == NULL)
		return;
	printInorder (node->left);
	printf("%d ", node->data);
	printInorder (node->right);
}

/* Driver program to test above functions */
int main()
{
/* Assume that inorder traversal of following tree is given
		40
	/ \
	10	 30
	/		 \
	5		 28 */
	int n, i;
	cin >> n;
	in.resize(n);
	for(i = 0; i < n; ++i)	cin >> in[i];
	struct node *root = buildTree(0, n - 1);
	printf("\n Inorder traversal of the constructed tree is \n");
	printInorder(root);
	return 0;
}
