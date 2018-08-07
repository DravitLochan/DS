void deletionBT(struct Node* root, int key){
    Node *t, *ptr = NULL, *dptr;
    queue <Node *> q;
    q.push(root);
    while(!q.empty()){
        t = q.front();
        q.pop();
        if(t->key == key)
            ptr = t;
        if(t -> left)
            q.push(t -> left);
        if(t -> right)
            q.push(t -> right);
    }
    if(!ptr)
        return ;
        dptr = t;
    ptr->key = dptr -> key;
    q.push(root);
    while(!q.empty()){
        t = q.front();
        q.pop();
        // cout << t -> key << " ";
        if(t->left && t->left == dptr){
            t -> left = NULL;
            // cout << dptr->key;
            free(dptr);
            break;
        } else if(t->left)
            q.push(t->left);
        if(t->right && t->right == dptr){
            t -> right = NULL;
            // cout << dptr->key;
            free(dptr);
            break;
        } else if(t->right)
            q.push(t->right);
    }
}
