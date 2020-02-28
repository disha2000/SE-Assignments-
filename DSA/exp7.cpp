/*. In any language program mostly syntax error occurs due to unbalancing delimiter such as
(),{},[]. Write C++ program using stack to check whether given expression is well
parenthesized or not. */
#include<iostream>
using namespace std;
char exp[30];
struct node
{
	char data;
	struct node *addr_prev;
	struct node *addr_next;
};
class stack
{
public:
	node *top;
	stack()
	{
		top=NULL;
	}
	void check();
	void push(char c);
	char pop();
};
void stack::check()
{
	for(int i=0;exp[i]!='\0';i++)
	{
		if(exp[i]=='['||exp[i]=='('||exp[i]=='{')
		{
			push(exp[i]);
		}
		else
		{
			if(top!=NULL)
			{
			   char present=pop();

				switch(exp[i])
				{
					case ')':
					if(present!='(')
						goto one;						
					break;
					case ']':
					if(present!='[')
					goto one;
					break;
					case '}':
					if(present!='{')
						goto one;
					break;
				}
			}
			else
			{
				goto one;
			}
		}
	}
	if(top==NULL)
	{
		cout<<"valid Expression.";
	}
	else
	{
		one:
		cout<<"invalid Expression.";
	}
}
void stack::push(char c)
{
	node *tmp=new node;
	node *q;
	tmp->data=c;
	tmp->addr_next=NULL;
	tmp->addr_prev=NULL;
	if(top==NULL)
	{
		tmp->addr_prev=NULL;
		top=tmp;
    }
	else
	{	
		tmp->addr_prev=top;
		top->addr_next=tmp;
		top=tmp;
	}
}
char stack::pop()
{
	node *tmp;
	tmp=top;
	char data=top->data;
	top=top->addr_prev;
	delete(tmp);
	return data;
}
int main()
{
	stack s;
	cout<<"\n~~~~~~~~STACK OPERATION~~~~~~~\nEnter Expression:\n";
	cin>>exp;
	s.check();
	return 0;
}
