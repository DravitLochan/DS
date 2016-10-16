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
