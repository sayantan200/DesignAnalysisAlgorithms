#include<iostream>
using namespace std;
int getmax(int a[],int n)
{
    int max=a[0];
    for(int i=1;i<n;i++)
        if(max<a[i])
            max=a[i];
    return max;
}
void countsort(int a[],int n,int pos)
{
    int count[10]={0},b[n],i;
    for(i=0;i<n;i++)
    {
        count[(a[i]/pos)%10]++;
    }
    for(i=1;i<n;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for(i=n-1;i>=0;i--)
    {
        b[--count[(a[i]/pos)%10]]=a[i];
    }
    for(i=0;i<n;i++)
    {
        a[i]=b[i];
    }
}
void radixsort(int a[],int n)
{
    int max=getmax(a,n);
    for(int pos=1;max/pos>0;pos=pos*10)
    {
        countsort(a,n,pos);
    }
}
int main()
{
    int n=10;
    int a[10];
    cout<<"Enter 10 element : ";
	for(int j = 0 ; j<10 ; j++) 
    { 
	   cin>>a[j];
	   cout<<"\t";
          
    } 
    radixsort(a,n);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}
