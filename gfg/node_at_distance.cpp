#include<bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 10000
struct Node
{
	int key;
	Node *left, *right;
};

Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return (node);
}

int printKDistantfromLeaf(Node* node, int k);
 void insert(struct Node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->key==n1)
     {
         switch(lr)
         {
          case 'L': root->left=newNode(n2);
                    break;
          case 'R': root->right=newNode(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
int main()
{
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct Node *root=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=newNode(n1);
            switch(lr){
                    case 'L': root->left=newNode(n2);
                    break;
                    case 'R': root->right=newNode(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
    cin>>k;
    cout<<printKDistantfromLeaf(root, k)<<endl;
    }
    return 0;
}

int printKDistantfromLeaf(Node* node, int k){
    // cout << "here\n";
    if(k < 0){
        return 0;
    }
    if(!k && !node->left && !node->right)
        return 1;
    if(!node)
      return 0;  
    if(node->left){    
        int a = printKDistantfromLeaf(node->left, k - 1);    
        if(!a){
            return printKDistantfromLeaf(node->right, k - 1);
        } else
            return a + printKDistantfromLeaf(node -> right, k - 2);
    } else if(node->right){
        return printKDistantfromLeaf(node->right, k - 1);
    }
    return 0;
}