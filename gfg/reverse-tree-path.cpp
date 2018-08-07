#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};


vector <Node *> v;
bool reverseTreePathInit(struct Node *root, int data){
    /*if(!root)
        return false;*/
	if(root->data == data){
		v.push_back(root);
		return true;
	}
	if(root->left){
		if(reverseTreePathInit(root->left, data)){
			v.push_back(root);
			return true;
		}
	}
	if(root->right){
		if(reverseTreePathInit(root->right, data)){
			v.push_back(root);
			return true;
		}
	}
	// v.pop_back();
	return false;
}


Node* reverseTreePathUtil(Node* root, int data,
	map<int, int>& temp, int level, int& nextpos)
{
	if (root == NULL)
		return NULL;
	if (data == root->data) {
		temp[level] = root->data;
		root->data = temp[nextpos];
		nextpos++;
		return root;
	}
	temp[level] = root->data;
	Node *left, *right;
	left = reverseTreePathUtil(root->left, data, temp, 
								level + 1, nextpos);
	if (left == NULL)
		right = reverseTreePathUtil(root->right, data, 
							temp, level + 1, nextpos);
	if (left || right) {
		root->data = temp[nextpos];
		nextpos++;
		return (left ? left : right);
	}
	return NULL;
}
void reverseTreePath(Node* root, int data)
{
	map<int, int> temp;
	int nextpos = 0;
	reverseTreePathUtil(root, data, temp, 0, nextpos);
}
int checkInV(struct Node *ptr){
	for(int i = 0; i < v.size(); ++i){
		if(v[i] == ptr)
			return i;
	}
	return -1;
}

void inorderModified(struct Node *root){
	if(!root)
		return ;
	inorderModified(root->left);
	int pos = checkInV(root);
	if(pos == -1)
		cout << root -> data << " ";
	else
		cout << v[v.size() - pos - 1]-> data << " ";
	inorderModified(root -> right);
}

Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
int main()
{
	Node* root = newNode(7);
	root->left = newNode(6);
	root->right = newNode(5);
	root->left->left = newNode(4);
	root->left->right = newNode(3);
	root->right->left = newNode(2);
	root->right->right = newNode(1);
	int data = 6;

	reverseTreePathInit(root, data);
	// for(int i = 0; i < v.size(); ++i)   cout << v[i]->data << " ";

	// Traverse inorder
	inorderModified(root);
	return 0;
}
