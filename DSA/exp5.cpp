/*
Write C++ program for storing binary number using doubly linked lists. Write functionsa) to compute 1‘s and 2‘s complement b) add two binary numbers
*/
#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *addr_next,*addr_prev;
};
class Binaryo
{
	public:
	node *start,*end;
	Binaryo()
	{
		start=NULL;
		end=NULL;
	}	
	void conversion(int);
	void display();
	void complement1();
	void complement2();
	void addition(struct node * end1,struct node *end2);
};
void Binaryo::conversion(int no)
{
	node *tmp,*q;
	for(int i=0;no>0;i++)
	{
		tmp=new node;
		tmp->data=no%2;
		tmp->addr_prev=NULL;
		

		no=no/2;
		if(end==NULL)
		{
			tmp->addr_next=NULL;
			end=tmp;

		}
		else
		{
			q=end;
			while(q->addr_prev!=NULL)
			{
				q=q->addr_prev;

			}
			tmp->addr_next=q;
			q->addr_prev=tmp;
		}
	}
	start=tmp;
	display();
}
void Binaryo::display()
{
	node *q;
	q=start;
	while(q!=NULL)
	{
		cout<<" [<"<<q->data<<">|"<<q->addr_next<<"]  --> ";
		q=q->addr_next;

	}
}
void Binaryo::complement1()
{
	node *q;
	q=start;
	while(q!=NULL)
	{
		if(q->data==1)
		{
			q->data=0;

		}
		else
		{
			q->data=1;
		}
		q=q->addr_next;

	}
	cout<<"\n\n```````````````````1'S complement``````````````````````\n\n\n";
	display();
}
void Binaryo::complement2()
{
	node *q;
	q=end;
	while(q!=NULL)
	{
		if(q->data==1)
		{
			q->data=0;

		}
		else
		{
			q->data=1;
			break;
		}
		q=q->addr_prev;
	}
	if(q==NULL)
	{
		node *tmp=new node;
		tmp->data=1;
		tmp->addr_prev=NULL;
		tmp->addr_next=start;
		tmp=start;
	}
	cout<<"\n\n```````````````````2'S complement``````````````````````\n\n\n";
	display();
}
void Binaryo::addition(struct node * end1,struct node *end2)
{
	node *q,*p,*ptr,*tmp;
	p=end1;
	q=end2;
	int carry=0,sum=0;
	while(p!=NULL && q!=NULL)
	{
		 if (p->data + q->data + carry == 0)
		 	{ sum=0;
		 		carry=0;}
        else if (p->data + q->data + carry == 1)
        	{sum=1;
        		carry=0;}
        else if ( p->data + q->data + carry == 2)
        {
            sum=0;
            carry=1;
          }
        else if (p->data + q->data + carry == 3)
        {
            sum =1;
            carry=1;
        }
		tmp=new node;
		tmp->data=sum;
		tmp->addr_prev=NULL;
		if(end==NULL)
		{
		tmp->addr_next=NULL;
		end=tmp;
		}
		else
		{
		    ptr=end;
		    while(ptr->addr_prev!=NULL)
			{	

				ptr=ptr->addr_prev;
			}
			tmp->addr_next=ptr;
			ptr->addr_prev=tmp;
		}
        p=p->addr_prev;
        q=q->addr_prev;
        if(p==NULL)
        {
        		node *newtmp=new node;
        		newtmp->data=0;
        		newtmp->addr_prev=NULL;
        		newtmp->addr_next=NULL;
        		p=newtmp;
		}
        else if(q==NULL)
        {
        		node *newtmp=new node;
        		newtmp->data=0;
        		newtmp->addr_prev=NULL;
        		newtmp->addr_next=NULL;
        		q=newtmp;
        }
      }
      start=tmp;
      if(carry==1)
		{
		tmp=new node;
		tmp->data=carry;
		tmp->addr_next=start;
		tmp->addr_prev=NULL;
		start=tmp;
		}
        display();
}
int main()
{
	int ch,no;
	Binaryo b1;
	cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~|Binary Represention|~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";
			cout<<"Enter decimal no::\n";
			cin>>no;
			b1.conversion(no);
			b1.complement1();//1's complement
			b1.complement2();//2's complement
			cout<<"\n\nEnter two Numbers::\n";
			int a,b;
			cin>>a>>b;
			Binaryo b2,b3,b4;
			b2.conversion(a);
			cout<<"\n\t\t+\n\n";
			b3.conversion(b);
			cout<<"\n\t\t=\n\n";
			b4.addition(b2.end,b3.end);//addition of 2 binary no
}
