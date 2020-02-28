/*
A double-ended queue(deque) is a linear list in which additions and deletions may be made
at either end. Obtain a data representation mapping a deque into a one-dimensional array.
Write C++ program to simulate deque with functions to add and delete elements from either
end of the deque.
*/
#include<iostream>
#define size 30
using namespace std;
class Dequeue
{
		int dequeue[size],rear,front;
		public:
			Dequeue()
			{
				rear=front=-1;
			}
		void insertrear();
		void display();
		void insertfront();
		void Deletefront();
		void Deleterear();
};
void Dequeue:: insertrear()
{
	int item;
	cout<<"\nEnter element:";
	cin>>item;
	if(rear==-1)
	{
			rear++;
			front++;
			dequeue[rear]=item;
	}
	else
	{
		rear++;
		dequeue[rear]=item;
	}
}
void Dequeue:: display()
{
	if(front==-1 || rear==-1)
	{
			cout<<"\nqueue is empty :-(\n";
	}
	else
	{	
			for(int i=front;i<=rear;i++)
			{
				cout<<dequeue[i]<<endl;
			}
	}
}
void Dequeue::insertfront()
{
		int item,i;
		cout<<"\nEnter element:";
		cin>>item;
		if(front==-1)
		{
			front++;
			rear++;
			dequeue[front]=item;

		}
		else
		{	
			for( i=rear;i>=0;i--)
			{
				dequeue[i+1]=dequeue[i];
				
			}
			rear++;
				dequeue[front]=item;
		}
}
void Dequeue:: Deletefront()
{
	if(front==-1)
	{
			cout<<"\nqueue is empty :-(\n";
	}
	else if(rear==front)
	{
		
		cout<<"\nFront deleted:"<<dequeue[front]<<endl;
		front=-1;
		rear=-1;
	}	
	else
	{	cout<<"\nFront deleted:"<<dequeue[front]<<endl;
		front++;
	}
}
void Dequeue:: Deleterear()
{
	if(rear==-1)
	{
			cout<<"\nqueue is empty :-(\n";
	}
	else if(rear==front)
	{
		
		cout<<"\nRear deleted:"<<dequeue[rear]<<endl;
		rear=-1;
		front=-1;
	}	
	else
	{	
		cout<<"\nRear deleted:"<<dequeue[rear]<<endl;
		rear--;
	}
}
int main()
{
	Dequeue q;
	int ch, con;
	do
	{
	cout<<"\n\n\n~~~~~~~~~QUEUE OPERATION~~~~~~~~\n\n\n1.Insert front\n2.Insert rear\n3.Delete front\n4.delete rear\n5.display\nEnter your choice::";
	cin>>ch;
	switch(ch)
	{
		case 1:q.insertfront();
		break;
		case 2:	q.insertrear();
		break;
		case 3:
		q.Deletefront();
		break;
		case 4:
		q.Deleterear();
		break;
		case 5:
		q.display();
		break;
	}
	cout<<"\nDo you want to continue???press 1:";
	cin>>con;
	}while(con==1);
	return 0;
}
