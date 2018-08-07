// O(n)
int height(Node *root, int *d){
	if(!root)
		return 0;
	int l = height(root->left, d);
	int r = height(root->right, d);
	d = max(1 + l +r, d);
	return max(l, r) + 1;
}

int diameter(Node *root){
	int d = INT_MIN;
	height(root, &d);
	return d;
}


// O(n^2)
int diameter(Node* root)
{
	if(!root)
		return 0;
	return max({1 + height(root->left) + height(root->right), diameter(root->left), diameter(root->right)});
}