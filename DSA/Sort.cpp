/*Write C++ program to store first year percentage of students in array. Write function for
sorting array of floating point numbers in ascending order using
a) Selection Sort b) Bubble sort and display top five scores*/
#include<iostream>
using namespace std;
class Sort
{
public:
	int m,n;
	float array[30];
	void accept();
	void bubbleSort();
	void selectionSort();
	void display(int);
	void top5();
};
void Sort::accept()
{
	cout<<"\nEnter student strength:";
	cin>>m;	
	cout<<"\nEnter First year scores:";
	for(int i=0;i<m;i++)
	{
		cin>>array[i];
	}
}
void Sort::bubbleSort()
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m-1-i;j++)
		{
			if(array[j]>array[j+1])
			{
				float temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}
	display(m);
}
void Sort ::selectionSort()
{
	for(int i=0;i<m-1;i++)
	{
		for(int j=i+1;j<m;j++)
		{
			if(array[i]>array[j])
			{
				float temp=array[i];
				array[i]=array[j];
				array[j]=temp;
			}
		}
	}
	display(m);
}
void Sort:: display(int m)
{
	for(int i=0;i<m;i++)
	{
		cout<<array[i]<<" ";
	}
}
void Sort:: top5()
{
	int n=m;
	if(m>=5)
	{
		n=5;
	}
	display(n);
}
int main()
{
	Sort s,s1;
	int con,ch;
	s.accept();
	s1= s;
	cout<<"\n\n~~~~~~~~~~~~~~~~~Sorting operation~~~~~~~~~~~~~~~~\n\n------BUBBLE SORT-------\n";
	s.bubbleSort();
	cout<<"\n\n---------SELECTION SORT-------\n";
	s1.selectionSort();
	cout<<"\n\n-------TOP 5 scores--------\n";
	s.top5();
	return 0;
}
