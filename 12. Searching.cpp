#include<iostream>
using namespace std;

class search
{
	int arr[10],n;
	int first,last,mid;
	
	public:	
	void get()
	{
		cout<<"\nEnter elements in the array: ";
		for(int i=0;i<10;i++)
			cin>>arr[i];
	}
	
	void seq_s()
	{
		int key,i;
		cout<<"\nEnter the element you want to search: ";
		cin>>n;
		for(i=0;i<10;i++)
		{
			if(arr[i]==n)
				{
					key=1;
					break;
				}
			else
				key=0;
		}
		if(key==1)
			cout<<"\nElement "<<n<<" found in the sequence at "<<i+1<<" position..!!!";
		else
			cout<<"\nElement "<<n<<" NOT found in the sequence..!!";
	}
	
	void s()
		{
			mid=(first+last)/2;
			while(first<=last)
			{
				if(arr[mid]==n)
				{	
					cout<<"\nElement "<<n<<" found in the sequence at "<<mid+1<<" position..!!!";
					break;
				}
				else if(arr[mid]<n)
					{
						mid++;
						first=mid;
						s();
						break;
					}
				else if(arr[mid]>n)
					{
						mid--;
						last=mid;
						s();
						break;
					}
			}
		}
	void bin_s()
	{
		cout<<"\nEnter the element you want to search: ";
		cin>>n;
		
		first=0;
		last=9;
		s();
	}
	
	void fibbonaci_s()
	{
		int n;
		cout<<"\nEnter the number of elements: ";
		cin>>n;
		int fib[n];
		fib[0]=0;
		fib[1]=1;
		for(int i=2;i<n;i++)
		{
			fib[i]=fib[i-1]+fib[i-2];
		}

		int arr[n];
		cout<<"\nEnter the elements in the array: ";
		for(int i=0;i<n;i++)
			cin>>arr[i];
		
		int key,f,b,a,pos,flag=0;
		f=n-1;
		b=fib[n-1];
		a=fib[n-2];
		cout<<"\nEnter the key element you want to search: ";
		cin>>key;
		
		do
		{
			if(key<arr[f])
			{
				int temp;
				f=f-a;
				temp=b-a;
				b=a;
				a=temp;
				break;
			}
			else if(key>arr[f])
			{
				f=f+a;
				b=b-a;
				a=a-b;
				break;
			}
						
		}while(key!=arr[f]);
		
		if(key==arr[f])
			flag=1;
		else flag=0;	
		
		if(flag==1)
		{
			cout<<"\nElement found at "<<f+1<<" location..!!!";
		}
		
		else
		{
			cout<<"\nElement NOT found..!!!";
		}
	}
	
};

int main()
{
	int c,ch;
	search s;
	do
	{
		cout<<"\n1.Sequential Search\n2.Binary Search\n3.Fibbonaci Search\n";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				{	
					s.get();
					s.seq_s();
					break;
				}
			case 2:
				{
					s.get();
					s.bin_s();
					break;
				}
			case 3:
				{
					s.fibbonaci_s();
					break;
				}
		}
	cout<<"\nEnter 1 if you want to continue: ";
	cin>>c;
	}while(c==1);
		
	return 0;
}
