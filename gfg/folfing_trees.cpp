bool isFoldable(struct node *root)
{
    if(!root || (!root ->left && !root -> right))
        return true;
    return ans(root -> left, root -> right);
  // Your code goes here
}

bool ans(struct node *r1, struct node *r2){
    if(r1 == r2 && r1 == NULL)
        return true;
    if((r2->left&&!r1->right) || (!r2->left&&r1->right)){
        // cout << "here1";
        return false;
    }
    if((r1->left && !r2->right) || (!r1->left && r2->right)){
        // cout << "here2";
        return false;
    }
    return ans(r1->left, r2->right) && ans(r2->left, r1->right);  
}