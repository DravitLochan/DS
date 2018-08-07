
vector <vector <int>> p;

void rec(Node *root, vector <int> v){
    if(!root)
        return ;
    v.push_back(root->data);
    if(!root->left && !root->right)
        p.push_back(v);
    rec(root->left, v);
    rec(root->right, v);
} 
 
void printPaths(Node* root){
    if(!root)
        return ;
    p.clear();
    vector <int> v;
    rec(root, v);
    for(int i = 0; i < p.size(); ++i){
        v = p[i];
        for(int j = 0; j < v.size(); ++j)
            cout << v[j] << " ";
        cout << "#";    
    }
    cout << "\n";
}