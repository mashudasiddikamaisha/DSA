#include<bits/stdc++.h>
using namespace std;
void mergesort(int a[], int l,int m, int h)
{
    int n1=m-l+1;
    int n2=h-m;
    int x[n1], y[n2];
    for(int i=0;i<n1;i++) x[i]=a[l+i];
    for(int i=0;i<n2;i++) y[i]=a[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(x[i]<=y[j]) //ascending
        //if(x[i]>=y[j]) //descending
        {
            a[k]=x[i];
            i++;
        }
        else{
            a[k]=y[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=x[i];
        i++;
        k++;
    }
}
void part(int a[],int l,int r)
{
    if(l<r) {
        int m= l+(r-l)/2;
        part(a,l,m);
        part(a,m+1,r);
        mergesort(a,l,m,r);
        }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    part(a,0,n-1);
    for(int i=0;i<n;i++) cout<<a[i]<< " ";
    return 0;
}
