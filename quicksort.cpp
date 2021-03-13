#include<iostream>
using namespace std;
int partition(int a[],int l,int h)
{
    int pivot=a[l],i=l,j=h;
    while(i<j)
    {
        while(a[i]<=pivot)
        {
            i++;
        }
        while(a[j]>pivot)
        {
            j--;    
        }
        if(i<j)
            swap(a[i],a[j]);
    }
    swap(a[l],a[j]);
    return j;
}
void Qsort(int a[],int l,int h)
{
    if(l<h)
    {
        int j=partition(a,l,h);
        Qsort(a,l,j-1);
        Qsort(a,j+1,h);
    }
}
int main()
{
    int n=0;
    int a[30];
    cout<<"enter the number of elements : ";
    cin>>n;
    cout<<"\nenter the elements : ";
    for(int i=0 ; i<n ; i++)
    {
    	cin>>a[i];
    	cout<<"\n";
	}
    Qsort(a,0,n-1);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}
