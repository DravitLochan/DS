// C/C++ program to print corner node at each level
// of binary tree
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has key, pointer to left
child and a pointer to right child */
struct Node
{
	int key;
	struct Node* left, *right;
};
/* To create a newNode of tree and return pointer */
struct Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return (temp);
}
/* Function to print corner node at each level */
void printCorner(Node *root);
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
// Driver program to test above function
int main ()
{
	int t;
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
    printCorner(root);
	cout<<endl;
    }
	return 0; 
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Function to print corner node at each level */
void printCorner(Node *root){
    if(!root)
        return ;
    std::queue <Node *> q;
    q.push(root);
    q.push(NULL);
    int l_nodes = 1, ctr = 0;
    while(!q.empty()){
        // cout << "here\n";
        struct Node *ptr = q.front();
        q.pop();
        if(!ptr)
          continue;
        if(!ctr){
            cout << ptr->key << " ";
            ++ctr;
        } else
          ++ctr;
        if(ctr == l_nodes && ctr != 1)
            cout << ptr->key << " ";
        if(ptr->left)
            q.push(ptr->left);
        if(ptr->right)
            q.push(ptr->right);
        if(!q.front()){
            l_nodes = q.size() - 1;
            q.push(NULL);
            ctr = 0;
        }
    }
}