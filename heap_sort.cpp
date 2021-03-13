#include<iostream>
#include<time.h>
#include<cstdlib>
using namespace std;
int c,cc[98],m=0;
void heapify(int a[],int n,int i)
{
    int large=i;
    int lf=2*i+1;
    int rt=2*i+2;
    if(lf<n)
    {
        c++;
        if(a[lf] > a[large])
            large=lf;
    }
    if(rt<n)
    {
        c++;
        if(a[rt] > a[large])
            large=rt;
    }
    if(large!=i)
    {
        swap(a[i],a[large]);
        heapify(a,n,large);
    }
}
void heapsort(int a[],int n)
{
    c=0;
    for(int i=(n/2)-1;i>=0;i--)
        heapify(a,n,i);
    for(int i=n-1;i>0;i--)
    {
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
    cc[m++]=c;
}
void repeat(int n)
{

	int a[n];

    cout<<"BEST CASE..............\n";
    for(int i=0;i<n;i++)
        a[i]=i+1;
    heapsort(a,n);

    cout<<"WORST CASE..............\n";
    for(int i=0;i<n;i++)
        a[i]=n-i;
    heapsort(a,n);*/

    cout<<"AVERAGE CASE..............\n";
    srand(time(0));
    for(int i=0;i<n;i++)
        a[i]=rand();
    heapsort(a,n);
}
int main()
{
    int n=30;
    for(int i=0;n<=1000;i++)
    {
        repeat(n);
        n=n+10;
    }
    for(int i=0;i<98;i++)
    cout<<cc[i]<<"\n";
    return 0;
}
