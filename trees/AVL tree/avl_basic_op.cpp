#include<iostream>
using namespace std;
//template<class t>
struct t_node{
	int val;
	int h;
	struct t_node *left,*right;
};
//template<class t>
class avl{
    struct t_node *root=new t_node;
public:
	avl()
	{
		root->h=0;
		root->left=NULL;
		root->right=NULL;
	}
	
	void levelOrder_h(t_node *r)
	{
		int he=-1,fr1=0,i=0,re1=0,fr2=0,re2=0;
		t_node *q1[100],*q2[100],*curr;	
		q1[re1++]=r;
		while(fr1!=re1)
		{
			curr=q1[fr1];
			if(curr->left)
			q1[re1++]=curr->left;
			if(curr->right)
			q1[re1++]=curr->right;
			q2[++re2]=q1[fr1];	
			++fr1;
		}
		// last element of 2nd q will be a garbage value. so for q2, traverse till/from re-1 only
		for(i=re2-1;re2>0;--i)
		{
			++he;
			while(q2[i]->val>q2[i-1]->val&&i>0)
			{
				q2[i]->h=he;
				--i;
			}
			q2[i]->h=he;
		}
		q2[0]->h=++he;
	}	
	
    t_node* create_n(int v)
    {
        t_node *n = new t_node;
        n->val=v;
        n->h=0;
        n->left=NULL;
        n->right=NULL;
        return n;
    }
    void inOrder(t_node *root)
    {
        if(root->left)
            inOrder(root->left);
        cout<<root->val<<" ";
        if(root->right)
            inOrder(root->right);
    }
	
	void left_cases(t_node *curr)
	{
		//first of all find which sub case it is. and then process it accordingly.
		/*
			if it is a LL case, value of curr->left->left->h>curr->left->right->h
			else it will be LR case (i.e. curr->left->left->h<curr->left->right->h)
			
			there will never be a case when both of them are equal because the function
			will only be called when there is a difference.
		*/
		t_node *t1=curr;
		t_node *t2=curr->left;
		if(curr->left->left->h>curr->left->right->h)
		{
			t1->left=t2->right;
			t2->right=t1;
		}
		else
		{
			t_node *t3=curr->left->right;
			t2->right=t3->left;
			t1->left=t3;
			t3->left=t2;
		}
		//upd_h(curr);
	}
	
	void right_cases(t_node *curr)
	{
		//first of all find which sub case it is. and then process it accordingly.
		/*
			if it is a RR case, value of curr->right->right->h>curr->right->left->h
			else it will be LR case (i.e. curr->right->right->h<curr->right->left->h)
			
			there will never be a case when both of them are equal because the function
			will only be called when there is a difference.
		*/
		t_node *t1=curr;
		t_node *t2=curr->right;
		if(curr->right->right->h>curr->right->left->h)
		{
			t1->right=t2->left;
			t2->left=t1;
		}
		else
		{
			t_node *t3=curr->left->right;
			t2->left=t3->right;
			t3->right=t2;
			t1->right=t3;
		}
	}
	
	void ass_h(t_node *stack[],int top)
	{
		while(top>-1)
		{
			t_node *curr=stack[top--];
			if(curr->left&&curr->right)
			{
				if(curr->left->h-curr->right->h>1)
				{
					left_cases(curr);
				}
				else if(curr->left->h-curr->right->h>1<-1)
				{
					right_cases(curr);
				}
				curr->h=max(curr->left->h,curr->right->h)+1;
			}
			else
			{
				if(curr->left)
				{
					if(curr->left->h>1)
					{
						left_cases(curr);
					}
					curr->h=curr->left->h+1;
				}
				else if(curr->right)
				{
					if(curr->right)
					{
						if(curr->right->h>1)
						{
							right_cases(curr);
						}
						curr->h=curr->right->h+1;
					}
				}
				else
				{
					curr->h=0;
				}
			}
		}
	}
    void insert(int n_v)
    {
    	t_node *n;
		n=create_n(n_v);
        int ins_at,top=-1;    //variable ins_at can have only 2 values. 0 or 1. 0 denotes insertion at left and 1 at right of r
        t_node *r=root;
        t_node *stack[100]={NULL};
        if(r==NULL)
        {
            r=n;
            return ;
        }
        while(true)
        {
            if(r->left&&r->val>=n->val)
            {
                r=r->left;
                stack[++top]=r;
                continue;
            }
            else if(!r->left&&r->val>=n->val)
            {
                ins_at=0;
                break;
            }
            else if(r->right&&r->val<n->val)
            {
                r=r->right;
                stack[++top]=r;
                continue;
            }
            else if(!r->right&&r->val<n->val)
            {
                ins_at=1;
                break;
            }
        }
        if(!ins_at)
            r->left=n;
        else
            r->right=n;
        r=root;
        stack[++top]=n;
        ass_h(stack,top);
    }
    t_node* get_root()
    {
    	return root;
	}
    
};              //AVL class ends here

int main()
{
	avl a;
	a.insert(10);
	a.insert(15);
	a.insert(5);
	a.inOrder(a.get_root());
    return 0;
}
