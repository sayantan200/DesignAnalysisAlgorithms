#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
int c=0;
void merge(int l[],int lsize,int r[],int rsize,int a[])
{
    int i=0,j=0,k=0;
    while(i<lsize && j<rsize)
    {
        if(l[i]<=r[j])
            a[k++]=l[i++];
        else
            a[k++]=r[j++];
        c++;
    }
    while(j<rsize)
        a[k++]=r[j++];
    while(i<lsize)
        a[k++]=l[i++];
}
void mergesort(int a[],int n)
{
    int mid;
    mid=n/2;
    if(n<2)
    return;
    int rsize=n-mid;
    int lsize=mid;
    int l[lsize],r[rsize];
    for(int i=0;i<mid;i++)
        l[i]=a[i];
    for(int i=mid;i<n;i++)
        r[i-mid]=a[i];
    mergesort(l,lsize);
    mergesort(r,rsize);
    merge(l,lsize,r,rsize,a);
}
void count(int n)
{
    
}
int main()
{
    int n;
    cout<<"Enter the number of elements : ";
    cin>>n;
    int a[n];
    
    cout<<"\nThe Best Case.......\n";
    for(int i=0;i<n;i++)
        a[i]=i+1;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    mergesort(a,n);
    cout<<"\nNumber of Comparision :- "<<c;
    
    
    cout<<"\n\n\nThe Worst Case.......\n";
    for(int i=0;i<n;i++)
        a[i]=n-i;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    mergesort(a,n);
    cout<<"\nNumber of Comparision :- "<<c;
    
    
    cout<<"\n\n\nThe Average Case.......\n";
    srand(time(0));
    for(int i=0;i<n;i++)
        a[i]=rand();
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    mergesort(a,n);
    cout<<"\nNumber of Comparision :- "<<c;
    

}
