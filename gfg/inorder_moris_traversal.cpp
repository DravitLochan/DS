#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct tNode
{
   int data;
   struct tNode* left;
   struct tNode* right;
};

void MorrisTraversal(tNode *root){
  tNode *ptr, *t = root;
  while(t){
    if(t->left){
      ptr = t;
      t = t->left;
      while(t->right && t -> right != ptr){
        // cout << "here\n";
        t = t -> right;
      }
      if(!t->right){
        // cout << t -> data << " ";
        t -> right = ptr;
        t = ptr -> left;
      } else if(t->right == ptr){
        t = ptr;
        cout << t -> data << " ";
        t =t -> right;
      }

    } else {
      cout << t-> data << " ";
      t = t -> right;
    }
  }
}
 
struct tNode* newtNode(int data)
{
  struct tNode* tNode = (struct tNode*)
                       malloc(sizeof(struct tNode));
  tNode->data = data;
  tNode->left = NULL;
  tNode->right = NULL;
 
  return(tNode);
}

int main()
{
  struct tNode *root = newtNode(1);
  root->left        = newtNode(2);
  root->right       = newtNode(3);
  root->left->left  = newtNode(4);
  root->left->right = newtNode(5); 
 
  MorrisTraversal(root);
 
  getchar();
  return 0;
}