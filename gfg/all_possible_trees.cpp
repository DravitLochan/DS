#include <bits/stdc++.h>

using namespace std;

vector <int> a;
  
struct Node
{
    int key;
    struct Node *left, *right;
};

struct Node *newNode(int item)
{
    struct Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
  
void preorder(Node *root)
{
    if (root != NULL)
    {
        // cout << "here\n";
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

vector <Node *> allTrees(int l, int r){
	vector <Node *> v;
	if(l > r){
		v.push_back(NULL);
		return v;
	}
	for(int i = l; i <= r; ++i){
        vector <Node *> left = allTrees(l, i - 1);
        vector <Node *> right = allTrees(i + 1, r);
		Node *t = newNode(a[i]);
		for(int j = 0; j < left.size(); ++j){
			for(int k = 0; k < right.size(); ++k){
				t -> left = left[j];
				t -> right = right[k];
				v.push_back(t);
			}
		}
	}
	return v;
}
  
int main()
{
    int n, i;
    cin >> n;
    a.resize(n);
    for(i = 0; i < n; ++i)	cin >> a[i];
    vector<Node *> trees = allTrees(0, n - 1);
    cout << "Preorder traversals of different "
         << "possible Binary Trees are \n";// << trees.size();
    for (int i = 0; i < trees.size(); i++)
    {
        preorder(trees[i]);
        printf("\n");
    }
    return 0;
}