/*
Implement C++ program for expression conversiona) infix to prefix, b)prefix to postfix,
c) prefix to infix, d) postfix to infix and e) postfix to prefix. */
#include<iostream>
#include<string.h>
using namespace std;
struct node
{
	char data;
	struct node *addr_prev;
	struct node *addr_next;
};
class Expression
{
	public:
	node *start,*top;
	Expression()
	{
		start=top=NULL;
	}
	void postfixconversion(Expression &,char expression[30]);
	void push(char);
	char pop();
	int stackp(char);
	int incomingp(char);
	void display();
	void postfixevalution(Expression&);
	void prefixconversion(Expression &,char expression[30]);
};
void Expression::postfixconversion(Expression &e,char expression[30])
{
	if(top==NULL)
	{
		push('~');
	}
	for(int i=0;expression[i]!='\0';i++)
	{
		while(stackp(top->data)>incomingp(expression[i]))
		{
			char c=pop();
			e.push(c);
		}
		if(stackp(top->data)!=incomingp(expression[i]))
		{
			push(expression[i]);
		}
		else
		{
			pop();
		}
	}
	while(top->data!='~')
	{
		e.push(top->data);
		top=top->addr_prev;
	}
	cout<<"\n~~~~~~~~~~~~~~~~~~~~~POSTFIX EVALUTION~~~~~~~~~~~~~~~~~~~~~\n";
	postfixevalution(&e);
}
void postfixevalution(Expression &e)
{
	Expression tmp;
	node *q=e.top;
	while(q!=NULL)
	{
		if(q->data=='+' ||q->data=='-' ||q->data=='*'||q->data=='/')
		{
			char a=e.pop();
			char b=e.pop();
			if(q->data=='+')
			{
				e.push(a+b);
			}
			else if(q->data=='-' )
			{
				e.push(a-b);
			}
			else if(q->data=='*')
			{
				e.push(a*b);
			}
			else
			{
				e.push(a/b);

			}
		}
		q=q->addr_next;
	}
	display();
}
void Expression:: push(char c)
{
	node *tmp,*q;
	tmp=new node;
	tmp->data=c;
	tmp->addr_next=NULL;
	tmp->addr_prev=NULL;
	if(start==NULL)
	{
		start=tmp;
		top=start;
	}
	else
	{
		tmp->addr_prev=top;
		top->addr_next=tmp;
		top=tmp;
	}
}
char Expression::pop()
{
		node *tmp;
		tmp=top;
		char data=top->data;//before deleting store the value
		top=top->addr_prev;
		delete(tmp);
		return data;
}
int Expression::stackp(char c)
{
	switch(c)
	{
		case '+':
		case '-':return 2;
		case '*':
		case '/':return 4;
		case '^':return 5;
		case '(':return 0;
		case '~':return -1;
		default:return 8;
	}
}
int Expression::incomingp(char c)
{
	switch(c)
	{
		case '+':
		case '-':return 1;
		case '*':
		case '/':return 3;
		case '^':return 6;
		case ')':return 0;
		case '(':return 9;
		default:return 7;
	}
}
void Expression:: display()
{
	if(start==NULL)
	{cout<<"stack is empty :-(\n";}
	else
	{
		node *q;
		q=start;
		while(q!=NULL)
		{
			cout<<q->data;
			q=q->addr_next;
		}
	}
}
void Expression:: prefixconversion(Expression &e,char expression[30])
{
	char reversestr[30];
	int j=0;
	for(int i=strlen(expression)-1;i>=0;i--)
	{
		if(expression[i]=='(')
		{
			reversestr[j]=')';

		}
		else if(expression[i]==')')
		{
			reversestr[j]='(';
		}
		else
		{
			reversestr[j]=expression[i];
		}
		j++;
	}
	reversestr[j]='\0';
	postfixconversion(e,reversestr);
	node *q;
	cout<<"\n~~~~~~~~~~~~~~~~~~~INFIX TO PREFIX~~~~~~~~~~~~~~~~~~~~~\n";
	q=e.top;
	while(q!=NULL)
	{
		cout<<q->data;
		q=q->addr_prev;
	}
}
int main() 
{
	Expression e,e1,e2,e3;
	cout<<"\nEnter the valid expression(space not allowed)::\n";
	char expression[30];
	cin>>expression;
	cout<<"\n~~~~~~~~~~~~~~~~~~~~~INFIX TO POSTFIX~~~~~~~~~~~~~~~~~~~~~\n";
	e.postfixconversion(e1,expression);//infix to postfix convertion
	e1.display();//display postfix expression which is stored in e1 object.
	e2.prefixconversion(e3,expression);

	

	return 0;
}
