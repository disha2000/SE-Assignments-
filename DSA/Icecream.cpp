/*Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set B
of students like butterscotch ice-cream. Write C/C++ program to store two sets using linked
list. compute and displayi. Set of students who like either vanilla or butterscotch or both
ii. Set of students who like both vanilla and butterscotch
iii. Set of students who like only vanilla not butterscotch
iv. Set of students who like only butterscotch not vanilla
v. Number of students who like neither vanilla nor butterscotch*/
#include<iostream>
using namespace std;
int totalno;
struct node
{
	int Rollno;
	struct node *addr_next;
	
};

class Ice
{
	node *start;
public:
	Ice()
	{
		start=NULL;
	}
	void create(int Rollno);
	void display();
	void intersection(Ice &);
	void Union(Ice &);
	void only(Ice&);
	
};
void Ice:: create(int Rollno)
{
	node *tmp=new node;
	tmp->Rollno=Rollno;
	tmp->addr_next=NULL;
	if(start==NULL)
	{
		start=tmp;
	}
	else
	{
		node *q=start;
		while(q->addr_next!=NULL)
		{
			q=q->addr_next;
		}
		q->addr_next=tmp;

	}
}
void Ice:: display()
{
	if(start==NULL)
	{
		cout<<"None of students\n\n";
	}
	else
	{
		node *q;
		q=start;
	
		while(q!=NULL)
		{
			cout<<" [<"<<q->Rollno<<">|"<<q->addr_next<<"]  --> ";
			q=q->addr_next;
		}
	}
}
void Ice::intersection(Ice &i)
{
	Ice temp;
	node *q=start;
	int flag=0;
	while(q!=NULL)
	{
		node *p=i.start;
		flag=0;
		while(p!=NULL)
		{
			if(q->Rollno==p->Rollno)
			{
				flag=1;
				break;
			}
			p=p->addr_next;
		}
		if(flag==1)
		{
				temp.create(q->Rollno);

		}
		q=q->addr_next;
	}
	cout<<"\n\nSet of students who like both vanilla and butterscotch\n\n";
	
	temp.display();
}
void Ice::Union(Ice &i)
{
	Ice temp;
	node *q=start;
	int flag=0;
	while(q!=NULL)
	{
		temp.create(q->Rollno);
		q=q->addr_next;

	}
	q=i.start;
	
	while(q!=NULL)
	{
		node *p=start;
		flag=0;
		while(p!=NULL)
		{
			if(q->Rollno==p->Rollno)
			{
				flag=1;
				break;
			}
			p=p->addr_next;
		}
		if(flag==0)
		{
			temp.create(q->Rollno);
		}
		q=q->addr_next;
	}
	cout<<"\n\nSet of students who like either vanilla or butterscotch or both\n\n";
	temp.display();
	Ice temp2;
	for(int i=1;i<=totalno;i++)
	{
		flag=0;
		q=temp.start;
		while(q!=NULL)
		{
			if(q->Rollno==i)
			{
				flag=1;
				break;
			}
			q=q->addr_next;
		}
		if(flag==0)
		{
			temp2.create(i);
		}
	}
	cout<<"\n\nNumber of students who like neither vanilla nor butterscotch\n\n";
	temp2.display();
}

void Ice:: only(Ice &i)
{
	Ice temp;
	node *q,*p;
	q=start;
	int flag=0;
	while(q!=NULL)
	{
		p=i.start;
		flag=0;
		while(p!=NULL)
		{
			if(p->Rollno==q->Rollno)
			{
				flag=1;
				break;
			}
			p=p->addr_next;
		}
		if(flag==0)
		{
			temp.create(q->Rollno);

		}
		q=q->addr_next;
	}
	cout<<"\n\n";
	temp.display();
}

int main()
{
	Ice i1,i2,i;
	int vno,bno,Rollno;
	cout<<"\n\n~~~~~~~~~~~~~~~~SECOND YEAR STUDENTS~~~~~~~~~~~~~~~~~\n\n";
	cout<<"\n\nEnter total no of student:";
	cin>>totalno;
	
	cout<<"\n\nEnter no of students like Vanilla Ice-cream:";
	cin>>vno;
	cout<<"\nEnter Rollno's:";

	for(int i=0;i<vno;i++)
	{
		cin>>Rollno;
		i1.create(Rollno);
	}
	cout<<"Enter no of students like butterscotch ice-cream.";
	cin>>bno;
	cout<<"\nEnter Rollno's:";
	for(int i=0;i<bno;i++)
	{
		cin>>Rollno;
		i2.create(Rollno);
	}
	i1.display();
	cout<<"\n";
	i2.display();
	i1.intersection(i2);
	i1.Union(i2);
	cout<<"\n\nSet of students who like only vanilla not butterscotch";
	i1.only(i2);
	cout<<"\n\nSet of students who like only butterscotch not vanilla";
	i2.only(i1);
	
	return 0;
}
