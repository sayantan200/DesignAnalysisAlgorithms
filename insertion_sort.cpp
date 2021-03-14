#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
void i_sort(int a[],int n)
{
    int j,i,key,c=0;
    //cout<<"Array to be Sorted......\n";
    //for(int i=0;i<n;i++)
      //  cout<<a[i]<<" ";
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key)
        {
            c++;
            a[j+1]=a[j];
            j=j-1;
        }
        if(j>=0)
            c++;
        a[j+1]=key;
    }
    cout<<"\nNumber of Comparisions :- "<<c<<"\n\n\n";
}
int main()
{   
    int n;
    cout<<"Enter the size of the array :- ";
    cin>>n;
    int a[n];
    cout<<"Best Case : \n";
    for(int i=0;i<n;i++)
        a[i]=i+1;
    i_sort(a,n);
    cout<<"Worst Case : \n";
    for(int i=0;i<n;i++)
        a[i]=n-i;
    i_sort(a,n);
    cout<<"Average Case : \n";
    srand(time(0));
    for(int i=0;i<n;i++)
        a[i]=rand();
    i_sort(a,n);
    return 0;
}
