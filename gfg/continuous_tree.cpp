Node dp[1000][1000];
// memset(dp, NULL, )
bool checkContinuous(Node *root){
	if((root && !root ->left && !root->right) || !root)
		return 1;
	if(root && root -> left && !root -> left -> left && !root->left->right
		&& root -> right && !root->right ->left && !root -> right ->right)
		if(abs(root->key - root->left->key) == 1 && abs(root->key - root -> right -> key) == 1)
			return 1;
		else
			return 0;
	if(root && root ->left && !root -> left -> left && !root ->left -> right
		&& !root -> right)
		if(abs(root->key - root->left -> key))
			return 1;
		else
			return 0;
	if(root && root -> right && !root -> right -> left && !root -> right -> right
		&& !root -> left)
		if(abs(root->key - root->right->key))
			return 1;
		else
			return 0;
	return checkContinuous(root->left) || checkContinuous(root->right);
}	