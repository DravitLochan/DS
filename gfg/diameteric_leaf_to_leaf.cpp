#include <bits/stdc++.h>
using namespace std;

int m = -1;
vector <int> le, ri;

struct Node {
	int data;
	Node *left, *right;
};

struct Node* newNode(int data)
{
	struct Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;

	return (node);
}

int height(Node *root, int *d, Node **p){
	if(!root)
		return 0;
	int l = height(root->left, d, p);
	int r = height(root->right, d, p);
	if(1 + l + r > *d){
	    *d = 1 + l + r;
		*p = root;
	}
	return 1 + max(l, r);
}

void printLeftSide(Node *root, vector <int> v1){
	if(!root){
		int s = v1.size();
		if(s > m){
		    m = v1.size();
			le.resize(v1.size());
			for(int i = 0; i < v1.size(); ++i){
				le[i] = v1[i];
			}
		}
		return ;
	}
	v1.push_back(root->data);
	printLeftSide(root->left, v1);
	printLeftSide(root->right, v1);
}



void diameteric_ltl(Node *root){
	vector <int> l, r;
	Node *p;
	int d = INT_MIN;
	int h = height(root, &d, &p);
	l.push_back(p->data);
	printLeftSide(p->left, l);
	for(int i = 0; i < le.size(); ++i)
		cout << le[i] << " ";
	// cout << m;
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

	diameteric_ltl(root);

	return 0;
}
