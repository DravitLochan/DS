#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct node {
    char ch;
    bool wordEnd;
    struct node* children[26];
    node(char val) {
        ch = val;
        wordEnd = false;
        for(int i = 0; i < 26; ++i) {
            children[i] = NULL;
        }
    }
};

bool isTerminalNode(node* r) {
    for(int i = 0; i < 26; ++i){
        if(r->children[i])
            return false;
    }
    return true;
}

void iterateTrie(node* root, vector<vector<node*> > &allPaths, vector<node*> path) {
    if(!root)
        return;
    path.push_back(root);
    if(isTerminalNode(root) || root->wordEnd == true) {
        allPaths.push_back(path);
    }
    for(int i = 0; i < 26; ++i){
        iterateTrie(root->children[i], allPaths, path);
    }
}

// node *root = new node('*');

void addWordToTrie(node* root, string word) {
    node* p;
    node* t = root;
    for(int i = 0; i < word.size(); ++i) {
        if(!(t->children[word[i] - 'a'])) {
            p = new node(word[i]);
            t->children[word[i] - 'a'] = p;
        }
        t = t->children[word[i] - 'a'];
    }
    t->wordEnd = true;
}

node* prepareRepoTrie(vector<string> repo) {
    node* root = new node('*');
    node* t;
    for(int i = 0; i < repo.size(); ++i) {
        addWordToTrie(root, repo[i]);
    }
    return root;
}

void printTrie(node* root) {
    vector<vector<node*> > paths;
    vector<node*> path;
    iterateTrie(root, paths, path);
    cout << "\n\n\n\n";
    for(int i = 0; i < paths.size(); ++i) {
        for(int j = 0; j < paths[i].size(); ++j) {
            cout << paths[i][j]->ch;
        }
        cout << " -> NULL\n";
    }
}

vector<vector<string> > solution(vector<string> repo, string query) {
    vector<vector<string> > ans;
    node* root = prepareRepoTrie(repo);
    printTrie(root);
    return ans;
}

int main() {
    int n;
    vector<string> repo;
    string temp, query;
    
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> temp;
        repo.push_back(temp);
    }
    cin >> query;
    solution(repo, query);
    return 1;    
}
