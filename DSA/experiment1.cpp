/*In Second year Computer Engineering class of M students, set A of students play cricket and
set B of students play badminton. Write C/C++ program to find and displayi. Set of students who play either cricket or badminton or both
ii. Set of students who play both cricket and badminton
iii. Set of students who play only cricket
iv. Set of students who play only badminton
v. Number of students who play neither cricket nor badminton
 (Note- While realizing the set duplicate entries are to avoided)*/
#include<iostream>
using namespace std;

class Set
{
int cricket[50],badminton[50],student[50],m,n,N;
public:	void accept();
		void Union();
		void intersection();
		void onlyCricket();
		void onlyBadminton();
		void neitherCB();

	
};
void Set::accept()
{
	int i;
	cout<<"Enter how many student:\n";
	cin>>N;
	for(int i=0;i<N;i++)
	{
		student[i]=i+1;
		
	}
	cout<<"\n----------------------CRICKET----------------\n";
	cout<<"Enter how many student plays cricket:\n";
	cin>>m;
	cout<<"Enter Roll No:\n";
	for(i=0;i<m;i++)
    {
     
        cin>>cricket[i];
    }
    cout<<"\n---------------------BADMINTON----------------\n";
  	cout<<"Enter how many student plays badminton:\n";
	cin>>n;
	cout<<"Enter Roll No:\n";
	for(int i=0;i<n;i++)
	{
		cin>>badminton[i];

	}
	
}
void Set::Union()
{
	int A[50];
	int k=0;
	for(int i=0;i<m;i++)
	{
		
		A[k]=cricket[i];
		
		k++;
		
	}
	int j;
	int flag=0;
	for(int i=0;i<n;i++)
	{
		flag=0;
		for( j=0;j<m;j++)
		{
			if(cricket[j]==badminton[i])
			{
				flag=1;
				break;
				
			}
			
			
		}
		if(flag!=1)
			{
				A[k]=badminton[i];
				k++;				
			}
		
	}
	for(int i=0;i<k;i++)
	{
		cout<<A[i]<<" ";
		
	}
	
}
void Set:: intersection()
{
	int A[50];
	int k=0;

	int j;
	int flag=0;
	for(int i=0;i<n;i++)
	{
		flag=0;
		for( j=0;j<m;j++)
		{
			if(cricket[j]==badminton[i])
			{
				flag=1;
				break;
				
			}
			
			
		}
		if(flag==1)
			{
				A[k]=badminton[i];
				k++;				
			}
		
	}

	for(int i=0;i<k;i++)
	{
		cout<<A[i]<<" ";
		
	}
	
}
void Set::onlyCricket()
{
	int A[50],flag=0,k=0;
	for(int i=0;i<m;i++)
	{
		flag=0;
		for(int j=0;j<n;j++)
		{
			if(cricket[i]==badminton[j])
			{
				flag=1;
				break;
			}
			
		}
		if(flag!=1)
		{
			A[k]=cricket[i];
			k++;
		}
		
	}

	for(int i=0;i<k;i++)
	{
		cout<<A[i]<<" ";
		
	}
	
}
void Set::onlyBadminton()
{
	int A[50],flag=0,k=0;
	for(int i=0;i<n;i++)
	{
		flag=0;
		for(int j=0;j<m;j++)
		{
			if(cricket[j]==badminton[i])
			{
				flag=1;
				break;
			}
			
		}
		if(flag!=1)
		{
			A[k]=badminton[i];
			k++;
		}
		
	}

	for(int i=0;i<k;i++)
	{
		cout<<A[i]<<" ";
		
	}
	
}
void Set::neitherCB(){
	int A[50];
	int k=0;
	for(int i=0;i<m;i++)
	{
		
		A[k]=cricket[i];
		
		k++;
		
	}
	int j;
	int flag=0;
	for(int i=0;i<n;i++)
	{
		flag=0;
		for( j=0;j<m;j++)
		{
			if(cricket[j]==badminton[i])
			{
				flag=1;
				break;
				
			}
			
			
		}
		if(flag!=1)
			{
				A[k]=badminton[i];
				k++;				
			}
		
	}
	flag=0;
	int cb[50],index=0;
	for(int i=0;i<N;i++)
	{
		flag=0;
		for(int j=0;j<k;j++)
		{
			if(student[i]==A[j])
			{
				flag=1;
				break;
				
			}
			
		}
		if(flag!=1)
		{
			cb[index]=student[i];
			index++;
			
		}
		
	}
	cout<<"\n neither circkert and badminton\n";
	for(int i=0;i<index;i++)
	{
		cout<<cb[i]<<" ";
		
	}
	
}

int main()
{
	Set s;
		char ans;
	
	//clear;
	s.accept();
	do
	{
	
	cout<<"\n\n------------------------OPERATION---------------------\n";
	cout<<"1.Union\n2.Intersection\n3.only cricket \n4.only badminton \n5.neither cirket & badminton\n";
	int choice;
	cout<<"Enter your choice:";
	cin>>choice;

	switch(choice)
	{
		case 1:	s.Union();
		break;
		case 2:
		s.intersection();
		break;
		case 3:
		s.onlyCricket();
		break;
		case 4:
		s.onlyBadminton();
		break;
		case 5:
		s.neitherCB();
			
			
			
			
	}
	cout<<"\n Do you want to continue?? PRESS Y:";
	cin>>ans;
	
	
}
while(ans=='y');

	
	
	
	
	return 0;

}
