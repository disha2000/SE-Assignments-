/*Department library has N books. Write C/C++ program to store the cost of books in array in
ascending order. Books are to be arranged in descending order of their cost. Write function
for
a) Reverse the contents of array without using temporary array.
b) Copy costs of books those with cost less than 500 in new array
c) Delete the duplicate entries using temporary array
d) Delete duplicate entries without using temporary array
e) Count number of books with cost more than 500.*/
#include<iostream>
using namespace std;
class books
{
	int book[50],N;
	public:
	void accept();
	void reverse();
	void less500();
	void duplicatetemp();
	void duplicatetempwithout();
	void more500();
};
void books::accept()
{
	cout<<"\n\n\nEnter the no of Books ::\n";
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cout<<"\ncost of Book"<<i+1<<"::";
		cin>>book[i];
	}
}
void books::reverse()
{
	cout<<"Reverse:\n";
	for(int i=N-1;i>=0;i--)
	{
		cout<<book[i]<<" ";

	}
}
void books::less500()
{
	int temp[50],k=0;
	for(int i=0;i<N;i++)
	{
		if(book[i]<500)
		{
			temp[k]=book[i];
			k++;
		}
	}
	cout<<"\ncosts of books those with cost less than 500 are:\n";
	for(int i=0;i<k;i++)
	{
		cout<<temp[i]<<" ";

	}
}
void books::duplicatetemp()
{
	int booknod[50],count=0,k=0;
	for(int i=0;i<N;i++)
	{
		count=0;
		for(int j=0;j<k;j++)
		{
			if(book[i]==booknod[j])
			{
				count=1;
				break;
			}
		}
		if(count==0)
		{
			booknod[k]=book[i];
			k++;

		}
	}
	cout<<"\n Delete duplicate using temp array:\n";
	for(int i=0;i<k;i++)
	{
		cout<<booknod[i]<<" ";
	}
	cout<<endl;
}
void books::duplicatetempwithout()
{
	int k=0,count=1;
	cout<<"Delete duplicate without temp array:\n";
	for(int i=0;i<N;i++)
	{
		count=0;
		for(int j=i-1;j>=0;j--)
		{
			if(book[i]==book[j])
			{
				count=1;
				break;
			}
		}
		if(count==0)
		{
			cout<<book[i]<<endl;
		}
	}
}
void books::more500()
{
	int temp[50],k=0;
	for(int i=0;i<N;i++)
	{
		if(book[i]>500)
		{
			temp[k]=book[i];
			k++;

		}
	}
	cout<<"\ncosts of books those with cost less than 500 are:\n";
	for(int i=0;i<k;i++)
	{
		cout<<temp[i]<<" ";
	}
}
int main()
{
	books b;
	b.accept();
	char ans;
	do{
	cout<<"\n^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	cout<<"\n1.Reverse.\n2.Less than 500.\n3.Delete the duplicate entries using temporary arrays.\n4.Delete duplicate entries without using temporary array.\n5.More than 500\n.";
	cout<<"Enter ur choice:\n";
	int ch;
	cin>>ch;
	switch(ch)
	{
		case 1:
	b.reverse();
	break;
	case 2:
	b.less500();
	break;
	case 3:
	b.duplicatetemp();;
	break;
	case 4:
	b.duplicatetempwithout();
	break;
	case 5:
	b.more500();
	break;
	}
	cout<<"\nDo you want to continue???? press y:";
	cin>>ans;
	}while(ans=='y');
	return 0;
	return 0;
}
