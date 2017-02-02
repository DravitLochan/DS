#include<iostream>
using namespace std;

struct rb_node
{
	int val;
	char c;					//c = color of node. n = no color, r = red, b = black//
	struct rb_node *left,*right,*parent;
}

class RbTree
{
	rb_node *root;
	public:
		RbTree() : root(NULL){ }
		
		rb_node * get_root()
		{
			return root;
		}
		
		void setRoot(rb_node * root)
		{
			this.root=root;
		}
		
		void createNode(int val)
		{
			rb_node *ptr= new rb_node;
			ptr->val=val;
			ptr->c='r';
			ptr->parent=NULL;
			ptr->left=NULL;
			ptr->right=NULL;	
			bstInsert(ptr);
		}
		
		void bstInsert(rb_node *ptr)
		{
			rb_node *r = root;
			if(r==NULL)
			{
				r = ptr;
				ptr->c='b';
				return;
			}
			while(true)
			{
				if(r->left==NULL&&r->val>ptr->val)	
				{
					r->left=ptr;
					ptr->parent=r;
					break;
				}
				else if(r->left!=NULL&&r->val>ptr->val)	r=r->left;
				else if(r->right==NULL&&r->val<ptr->val) 
				{
					r->right=ptr;
					ptr->parent=r;
					break;
				}
				else	r=r->right;
			}
			if(ptr->c==ptr->parent->c&&ptr->c=='r')
				solveRedRed(ptr);
			else
				return;	
		}
		
		void solveRedRed(rb_node *ptr)
		{								
			if(ptr->parent==ptr->parent->parent->left)							//condition to find if ptr's parent is left or right child of it's gand parent
			{
				if()															//ptr's uncle doe not exist
				{
					
				}
				else if(ptr->parent->parent->left->c=='r')						//ptr's uncle is red
				{														//here error will come for those cases where ptr->parent->parent does not even exits						
					ptr->parent->c='b';
					ptr->parent->parent->right->c='b';
					ptr->parent->parent->c='r';
					//make a recursive call to check ptr->parent->parent
				}
				else if()														//ptr's uncle is black
				{
					
				}
			}
			else if(ptr==ptr->parent->right)									//condition to find if ptr->parent is left or right child of it's grand parent
			{
								//~ to above, check all the conditions here also
			}
		}
}

int main()
{
	
}
