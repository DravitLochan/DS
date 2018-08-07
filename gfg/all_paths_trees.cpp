/*program to print all of its root-to-leaf paths for a tree*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

void printPathsRecur(struct node* node) 
{
if (node==NULL) return;

if (node->left==NULL && node->right==NULL) 
{
	cout << "\n";
}
else
{
    cout << node -> data << " ";
	printPathsRecur(node->left);
	printPathsRecur(node->right);
}
}


struct node* newNode(int data)
{
struct node* node = (struct node*)
					malloc(sizeof(struct node));
node->data = data;
node->left = NULL;
node->right = NULL;

return(node);
}


int main()
{
struct node *root = newNode(1);
root->left	 = newNode(2);
root->right	 = newNode(3);
root->left->left = newNode(4);
root->left->right = newNode(5); 

printPathsRecur(root);

getchar();
return 0;
}
