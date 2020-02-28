/*Write C++ program to store roll numbers of student in array who attended training program
in random order. Write function fora) Searching whether particular student attended training program or not using linear search
and sentinel search. b) Searching whether particular student attended training program or
not using binary search and Fibonacci search. */
#include<iostream>
using namespace std;
class Search
{
public:
		int m,array[30],fibbo[30];
		void accept();
		void sort();
		void linearSearch(int);
		void sentinelSearch(int);
		void binarySearch(int);	
		void fibonacciSearch(int start,int end,int index,int item);
		void fibbogen(int);
};
void Search:: accept()
{
	cout<<"\nEnter size:";
	cin>>m;	
	cout<<"\nEnter Roll-no:";
	for(int i=0;i<m;i++)
	{
		cin>>array[i];
	}
	sort();
}
void Search:: sort()
{
	for(int i=0;i<m-1;i++)
	{
		for(int j=i+1;j<m;j++)
		{
				if(array[i]>array[j])
				{
					int temp=array[i];
					array[i]=array[j];
					array[j]=temp;
				}
		}
	}
	cout<<"\n\n--------------------NEW SORTED Roll-no---------------\n";
	for(int i=0;i<m;i++)
	{
		cout<<array[i]<<" ";
	}
}
void Search::linearSearch(int item)
{
	int flag=0,i;
	for(i=0;i<m;i++)
	{
		if(array[i]==item)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		cout<<item<<" found at location "<<i+1<<"\n";
	}
	else
	{
		cout<<"Not attended :-(";
	}
}
void Search::sentinelSearch(int item)
{
	array[m]=item;
	int i=0;
	do
	{}while(array[i++]!=item);
	if(i==m+1)
	{
		cout<<"Not attended :-(";
	}
	else
	{	cout<<item<<" found at location "<<i;
	}
}

void Search:: binarySearch(int item)
{
	int lb=0,ub=m-1,mid=lb+ub/2,flag=0;
	while(lb<=ub)
	{
		if(array[mid]>item)
		{
				ub=mid-1;
		}
		else if(array[mid]<item)
		{
				lb=mid+1;
		}
		else if(array[mid]==item)
		{
				flag=1;
				break;
		}
		mid=(ub+lb)/2;
	}
	if(flag==1)
	{
		cout<<item<<" found at location "<<mid+1<<"\n";
	}
	else
	{
		cout<<"Not found :-(";
	}
}
void Search::fibbogen(int item)
{
	fibbo[0]=0;
	fibbo[1]=1;
	int i=1;
	while(m>i)
	{
		i++;
		fibbo[i]=fibbo[i-1]+fibbo[i-2];

	}

	fibonacciSearch(0,m-1,i,item);

}
void Search:: fibonacciSearch(int start,int end,int index,int item)
{
	if(index<=1)
	{
		goto jump;

	}	
	int i, mid;
 	mid = start+fibbo[index-2];
	if(item == array[mid])
	{
		cout<<item<<" found at location "<<mid+1;
		return;
	}
	else if(item == array[start])
	{
		cout<<item<<"found at location "<<start+1;
		return;
	}
	else if(item == array[end])
	{
		cout<<item<<" found at location "<<end+1;
		return;
	}
	else if(mid == start || mid == end)
	{
		jump:
		cout<<"\nNot attended";
		return;
	}
	else if(item > array[mid])
		fibonacciSearch(mid, end, index-1, item);
	else
		fibonacciSearch(start, mid,index-2, item);

}
int main()
{
	Search s;
	int con,ch,item;
	s.accept();

	do
	{
		cout<<"\n~~~~~~~~~~~~~ARRAY OPERATION~~~~~~~~~~~\n\n1.Linear Search.\n2.Sentinel Search.\n3.Binary Search\n4.fibonacci Search\nEnter ur choice::-";
		cin>>ch;
		cout<<"\n\nEnter rollno which u want to search::-";
		cin>>item;
		switch(ch)
		{
				case 1:s.linearSearch(item);
				break;
				case 2:s.sentinelSearch(item);
				break;
				case 3:s.binarySearch(item);
				break;
				case 4:s.fibbogen(item);
		}
		cout<<"\n\ndo you want to continue??press 1::";
		cin>>con;
	}while(con==1);
	return 0;
}
