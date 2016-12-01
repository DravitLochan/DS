#include<iostream>
#include<string>
using namespace std;

struct cnv{						//cnv=column n value
	int c,v;
	struct cnv *next;
};

struct row{
	int r;
	struct cnv *link;
};

struct rnv{						//rnv=row n value
	int r,v;
	struct rnv *next;
};

struct col{
	int c;
	struct rnv *link;
};

struct row push(row c,cnv *b)								//push() is overloaded
{															//first element of each row list is left empty for convenience
	cnv *d= new cnv;
	d=c.link;
	//cout<<"1\n";
	while(d->next!=NULL)
	{
		d=d->next;
	}
	d->next=b;
	b->next=NULL;
	return c;
}

struct col push(col e,rnv *b)								//push() is overloaded
{															//first element of each row list is left empty for convenience
	rnv *d= new rnv;
	d=e.link;
	//cout<<"1\n";
	while(d->next!=NULL)
	{
		d=d->next;
	}
	d->next=b;
	b->next=NULL;
	return e;
}


void print(row pr[],int sr)								//print() is overloaded
{
	int i;
	for(i=0;i<sr;++i)
	{
		cnv *b = new cnv;
		b=pr[i].link;
		b=b->next;
		cout<<"\n";
		cout<<pr[i].r;
		while(b!=NULL)
		{
			cout<<"->"<<b->c<<"|"<<b->v;
			b=b->next;
		}
		cout<<"->NULL";
	}		
}

void print(col pc[],int sc)								//print() is overloaded
{
	int i;
	for(i=0;i<sc;++i)
	{
		rnv *b = new rnv;
		b=pc[i].link;
		b=b->next;
		cout<<"\n";
		cout<<pc[i].c;
		while(b!=NULL)
		{
			cout<<"->"<<b->r<<"|"<<b->v;
			b=b->next;
		}
		cout<<"->NULL";
	}		
}

void fill(row fr[],int sr)							//fill() is overloaded
{
	int i,j;
	for(i=0;i<sr;++i)
	{
		int no_of_non_z;
		fr[i].r=i;
		cnv *a = new cnv;
		fr[i].link=a;
		a->next=NULL;
		cout<<"\nEnter the number of columns in row "<<i<<" with non-zero vaalue\n";
		cin>>no_of_non_z;
		for(j=0;j<no_of_non_z;++j)
		{
			cnv *b = new cnv;
			b->next=NULL;
			cout<<"Enter the index of column in this row with non zero value\n";
			cin>>b->c;
			cout<<"Enter the value of this element\n";
			cin>>b->v;
			fr[i]=push(fr[i],b);
		}
		cout<<"list filled of element "<<i<<"\n";
	}
}

void fill(col fc[],int sc)							//fill() is overloaded
{
	int i,j;
	for(i=0;i<sc;++i)
	{
		int no_of_non_z;
		fc[i].c=i;
		rnv *a = new rnv;
		fc[i].link=a;
		a->next=NULL;
		cout<<"\nEnter the number of rows in column "<<i<<" with non-zero value\n";
		cin>>no_of_non_z;
		for(j=0;j<no_of_non_z;++j)
		{
			rnv *b = new rnv;
			b->next=NULL;
			cout<<"Enter the index of row in this column with non zero value\n";
			cin>>b->r;
			cout<<"Enter the value of this element\n";
			cin>>b->v;
			fc[i]=push(fc[i],b);
		}
		cout<<"list filled of element "<<i<<"\n";
	}
}

void multiply(row r1[],col c1[], row r2[], int sr1,int sr2,int sc1,int sc2)
{
	int i,j,sum,k;
	for(i=0;i<sr1;++i)							//instead of i<sr1, i<sr2 can also be used as a test condition for the for loop
	{
		//sum=0;
		cnv *e = new cnv;
		rnv *f = new rnv;
		cnv *a = new cnv;
		e=r1[i].link;
		e=e->next;
		a->next=NULL;
		r2[i].link=a;
		r2[i].r=i;
		for(k=0;k<sc1;++k)
		{
			sum=0;
			f=c1[k].link;
			f=f->next;
			cnv *b = new cnv;
			b->next=NULL;
			j=0;
			while(e!=NULL&&f!=NULL)
			{
				if(j==e->c&&j==f->r)
				{
					b->c=j;
					sum+=e->v*f->v;
					b->next=NULL;
						e=e->next;
					f=f->next;
					//cout<<"(1-1)\n";
				}
				else if(j==e->c&&j!=f->r)
				{
					e=e->next;
				}
				else if(j!=e->c&&j==f->r)
				{
					f=f->next;
				}
				else
				{
					++j;
				}
			}
			b->v=sum;
			b->next=NULL;
			if(sum!=0)
			r2[i]=push(r2[i],b);			
		}

	}
}

void add(row r1[],row r2[], row r3[], int sr1,int sr2,int sc1,int sc2)
{
	int i,j;
	for(i=0;i<sr1;++i)							//instead of i<sr1, i<sr2 can also be used as a test condition for the for loop
	{
		cnv *e = new cnv;
		cnv *f = new cnv;
		cnv *a = new cnv;
		e=r1[i].link;
		e=e->next;
		f=r2[i].link;
		f=f->next;
		a->next=NULL;
		r3[i].link=a;
		r3[i].r=i;
		for(j=0;j<sc1;++j)
		{
			cnv *b = new cnv;
			b->next=NULL;
			while(e!=NULL&&f!=NULL)
			{
				if(j==e->c&&j==f->c)
				{
					b->c=j;
					b->v=e->v+f->v;
					b->next=NULL;
					r3[i]=push(r3[i],b);
					e=e->next;
					f=f->next;
					//cout<<"(1-1)\n";
				}
				else if(j==e->c&&j!=f->c)
				{
					b->c=j;
					b->v=e->v;
					b->next=NULL;
					r3[i]=push(r3[i],b);
					e=e->next;
					//cout<<"(1-2)\n";
				}
				else if(j!=e->c&&j==f->c)
				{
					b->c=j;
					b->v=f->v;
					b->next=NULL;
					r3[i]=push(r3[i],b);
					f=f->next;
					//cout<<"(1-3)\n";
				}
				else
				{
					//cout<<"got it\n";
					break;
				}
			}
			while(e!=NULL&&f==NULL)
			{
				cnv *b = new cnv;
				b->next=NULL;
				b->c=e->c;
				b->v=e->v;
				r3[i]=push(r3[i],b);
				e=e->next;
				//cout<<"(2)\n";
			}
			while(f!=NULL&&e==NULL)
			{
				cnv *b = new cnv;
				b->next=NULL;
				b->c=f->c;
				b->v=f->v;
				r3[i]=push(r3[i],b);
				f=f->next;
				//cout<<"(3)\n";							
			}
		}
	}	
}

int main()					//out of 2 matrices, one is stored row wise and the other is stored column wise only in the case of multiplication.
{
	int sr1,sr2,sc1,sc2,perform,i,j,k,l,n,m;
	char choice;
	cout<<"Enter the order of 2 sparce matrix seperately (first the values of sparce mat1 \nthen of sparce mat2) :\n";
	cin>>sr1>>sc1>>sr2>>sc2;
	cout<<"Enter what do you want to do:\n";
	cout<<"\t\t 1. ADD\n\t\t2. MULTIPLY\n";
	cin>>perform;
	switch(perform)
	{
		case 1:
		{
			if(sc1!=sc2||sr1!=sr2)
			{
				cout<<"these matrix cannot be added!!\n\n\t\tEXITING!!!!";
				exit(1);
			}
			else
			{
				row r1[sr1],r2[sr2];
				// r1 being filled
				cout<<"\n\n\nMatrix 1 :\n";				
				fill(r1,sr1);
				cout<<"MAT 1 :\n";
				print(r1,sr1);
				//r2 being filled
				cout<<"\n\n\nMatrix 2 :\n";
				fill(r2,sr2);
				cout<<"MAT 2 :\n";
				print(r2,sr1);
				//r3 created
				row r3[sr1];
				//add function called
				add(r1,r2,r3,sr1,sr2,sc1,sc2);								
				//print the resultant row matrix
				
				cout<<"MAT 3 :\n";
				print(r3,sr1);
			}
			break;
		}
		case 2:					//out of 2 matrices, one is stored row wise and the other is stored column wise for this case
		{
			if(sc1!=sr2)
			{
				cout<<"these matrix cannot be multiplied!!\n\n\t\tEXITING!!!!";
				exit(1);
			}
			else
			{
				row r1[sr1],r2[sr1];
				//r1 being filled
				cout<<"\n\n\nEnter Matrix 1 (row wise):\n";		
				fill(r1,sr1);
				//c1 being filled
				
				col c1[sc1];				
				cout<<"\n\n\nEnter Matrix 2 (column wise):\n";		
				fill(c1,sc1);	
				//multiply function called	
				multiply(r1,c1,r2,sr1,sr2,sc1,sc2);
				//print the resultant multiplied matrix
				print(r2,sr1);
			}
			break;
		}	
		default:
		cout<<"Invalid choice!!\n\t\tEXITING!!!!";
		exit(1);	
	}
	return 0;
}
