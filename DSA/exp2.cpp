/*Write C/C++ program to store marks scored for first test of subject 'Data Structures and
Algorithms' for N students. Compute
I. The average score of class
ii. Highest score and lowest score of class
iii. Marks scored by most of the students
iv. list of students who were absent for the test*/

#include<iostream>
using namespace std;

class Student
{
	int student[30],N,higher[30];
	public:
	void accept();
	void avarage();
	void higest();
	void lowest();	
	void absent();
	void most();
};
void Student::accept()
{
	cout<<"Enter how many student in class-room:";
	cin>>N;
	//student[N];
	cout<<N;
	cout<<"\n\nEnter DSA marks & if absent then enter -1:\n";
	for(int i=0;i<N;i++)
	{
		cout<<"Enter Roll-No "<<i+1<<":";
		cin>>student[i];

	}
}
void Student::avarage()
{
	int count=1;
	int sum=0;
	for(int i=0;i<N;i++)
	{
		if(student[i]!=-1)
		{
			sum=sum+student[i];
			count++;

		}

	}
	cout<<"\nAverage of student is:"<<sum/count;
}
void Student:: higest()
{
	int k=0;
	for(int i=0;i<N-1;i++)
	{
		higher[i]=student[i];

	}
	for(int i=0;i<N-1;i++)
	{
		if(higher[i]>higher[i+1])
		{
			int temp=higher[i];
			higher[i]=higher[i+1];
			higher[i+1]=temp;

		}

	}
	cout<<"\nhigest marks is:\n"<<higher[N-1];

}
void Student::lowest(){
	
	for(int i=0;i<N;i++)
	{
		if(higher[i]!=-1)
		{

			cout<<"\nlowest marks is:\n"<<higher[i];
			break;


		}


	}

}
void Student::absent()
{
	cout<<"\n\nAbsent student are::";
	for(int i=0;i<N;i++)
	{
		if(student[i]==-1)
		{
			cout<<i+1<<" ";
		}

	}
}
void Student::most()
{
	int count=0,previous=0,item;
	for(int i=0;i<N-1;i++)
	{
		count=0;
		for(int j=i+1;j<N;j++)
		{
			if(higher[i]==higher[j])
			{

				count++;
				if(previous>count)
				{
					previous=count;
					item=higher[i];

				}

				
			}

		}
		
	}
	cout<<item<<" "<<previous;
}
int main()
{
	Student s;
	s.accept();
	s.avarage();
	s.higest();
	s.lowest();
	s.absent();
	s.most();
	return 0;
}
