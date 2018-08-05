#include<iostream>
using namespace std;
int main()
{
	int proc,res;
	cout<<"Enter number of processes and resources: ";
	cin>>proc>>res;
	int max[proc][res];int alloc[proc][res];int avail[res];int need[proc][res];int work[res];
	
	for(int i=0;i<proc;i++)
	{
		for(int j=0;j<res;j++)
		{
			cout<<"Enter "<<i<<" "<<j<<" "<<"max element"<<endl; 
			cin>>max[i][j]; /*Maximum matrix input*/
		}
	}
	
	for(int i=0;i<proc;i++)
	{
		for(int j=0;j<res;j++)
		{
			cout<<"Enter "<<i<<" "<<j<<" "<<"allocation element"<<endl;
			cin>>alloc[i][j]; /*Allocation matrix input*/
		}
	}
	
	for(int i=0;i<res;i++)
	{
		cout<<"Enter "<<i<<" "<<"available element"<<endl;
		cin>>avail[i]; /*Available matrix input*/
	}
	
	/*Need Matrix*/
	for(int i=0;i<proc;i++)
	{
		for(int j=0;j<res;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];/*Need matrix input*/
		}
	}
	
	/*Print Need matrix*/
	cout<<"Need Matrix: \n";
	for(int i=0;i<proc;i++)
	{
		for(int j=0;j<res;j++)
		{
			cout<<need[i][j]<<" ";
		}
		cout<<endl;
	}
	
	/*Safe condition*/
	bool finish[proc]={0};
	int seq[proc];
	for(int i=0;i<res;i++)
	{
		work[i]=avail[i];
	}
	int count=0;
	while(count<proc)
	{
		bool found=false;
		for(int i=0;i<proc;i++)
		{
			if(finish[i]==0)
			{
				int j;
				for(j=0;j<res;j++)
				{
					if(need[i][j]>work[j])
					{
						break;
					}
				}
				if(j==res)
				{
					for(int k=0;k<res;k++)
					{
						work[k] +=alloc[i][k];
					}
					seq[count++]=i;
					finish[i]=1;
					found=true;
				}
			}
		}
		if(found==false)
		{
			cout<<"System is not in safe mode";
			return false;
		}
		
	}
	cout<<"System is in safe state.\nSafe sequence is: ";
			for(int i=0;i<proc;i++)
			{
				cout<<seq[i]<<" ";
			}
	return 0;
}
