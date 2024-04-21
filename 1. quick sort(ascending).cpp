#include<bits/stdc++.h>
using namespace std;
int part(int a[], int l, int h)
{
    int pivot=a[l];
    int count=0;
    for(int i=l+1;i<=h;i++)
    {
        if(a[i]<=pivot) //for ascending
       // if(a[i]>=pivot) //for  descending
            count++;
    }
    int pivIndex= l+count;
    swap(a[pivIndex],a[l]);
    int i= l,j=h;
    while(i<pivIndex && j>pivIndex)
    {
          while(a[i]<=pivot) //ascending
        //while(a[i]>=pivot) //descending
            i++;
        while(a[j]>pivot) //ascending
        //while(a[j]<pivot) //descending
         j--;
        if(i<pivIndex && j>pivIndex) swap(a[i++],a[j--]);
    }
    return pivIndex;
}
void quicksort(int a[],int l, int h)
{
    if(l>=h) return;
    int p= part(a,l,h); //2 part
    quicksort(a,l,p-1); //left sort
    quicksort(a,p+1,h); //right sort
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
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++) cout<<a[i]<< " ";
    return 0;
}
