#include<iostream>
using namespace std;

struct t_node{
	int value;
	struct t_node *left,*right;
};

class bs_t{
	t_node *root;
	
	public:
	bs_t(t_node *h)
	 {
			root=h;
	 }
	t_node* get_root()
	{
		return root;
	}
	void put_root(t_node *p)
	{
		root=p;
	}
	
	void inOrder(t_node *r)
	{
		if(r->left)
		inOrder(r->left);
		cout<<r->value<<" ";
		if(r->right)
		inOrder(r->right);
	}
	
		void preOrder(t_node *r)
	{
		cout<<r->value;
		if(r->left)
		preOrder(r->left);
		if(r->right)
		preOrder(r->right);
	}

	void postOrder(t_node *r)
	{
		if(!r->left)
		postOrder(r->left);
		cout<<r->value;
		if(!r->right)
		cout<<r->value;
	}
	t_node* create_n(int v)
	{
		t_node *n= new t_node;
		n->left=NULL;
		n->right=NULL;
		n->value=v;
		return n;
	}
	
	int add_n(t_node *r, int v)
	{
		if(r==NULL)
		{
			t_node *n=create_n(v);
			r=n;
			return 1;
		}
		if(!r->left&&r->value>v)
		{
			t_node *n=create_n(v);
			r->left=n;
			return 1;
		}
		else if(!r->right&&r->value<v)
		{
			t_node *n=create_n(v);
			r->right=n;
			return 1;
		}
		else if(r->value>v)
		{
			add_n(r->left,v);
			return 1;
		}
		else
		{
			add_n(r->right,v);
			return 1;
		}
	}
	int kth_smallest(int k)
	{
		if(!k)
		return r->value;
		if(r->left)
		kth_smallest(k-1);
		cout<<r->value;
		if(r->right)
		kth_smallest(k-1);
	}
};

int main()
{
	t_node *head=new t_node;
	head->left=NULL;
	head->right=NULL;
	bs_t tree(head);
	int val,i,num_of_nodes;
	cin>>num_of_nodes;
	for(i=0;i<num_of_nodes;++i)
	{
		cin>>val;
		tree.add_n(tree.get_root(),val);
	}
	tree.inOrder(tree.get_root());
	return 0;
}
