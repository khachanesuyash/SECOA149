#include<iostream>
using namespace std;

class quicksort
{
	int arr[10];
	int high,low,i,j,pivot;
	public:
            int n;
	
	void get()
	{
		cout<<"\nEnter how many elements : ";
		cin>>n;
		cout<<"\nEnter the elements to be sorted: \n";
		for(i=0;i<n;i++)
                    cin>>arr[i];
	}
	
	int partition(int low,int high)
	{
		pivot=arr[low];
		i=low;
		j=high;
		while(i<=j)
		{
                    do{
                            i++;
                      }while(arr[i]<pivot);
                    do{
                            j--;
					  }while(arr[j]>pivot);    
                        
			if(i<j)
			{
				int temp;
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
			int temp1;
			temp1=arr[j];
			arr[j]=arr[low];
			arr[low]=temp1;	
		return j;
	}
	
	void quick(int low,int high)
	{
		int m;
		if(low<high)
		{
			m=partition(low,high);
			quick(low,m-1);
			quick(m+1,high);
		}
	}
	
	void display()
	{
		cout<<"\nSorted array is: \n";
		for(i=0;i<n;i++)
			cout<<arr[i]<<" ";
                cout<<"\nTop Five Scores are : ";
                for(i=n;i>n-6;i--)
			cout<<arr[i]<<" ";
	}
};
int main()
{
	quicksort q;
		q.get();
		q.quick(0,q.n);
		q.display();
	return 0;
}
