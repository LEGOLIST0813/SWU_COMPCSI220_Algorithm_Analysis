#include<bits/stdc++.h>
using namespace std;

void MERGE(int a[],int l,int r)
{
    int tmp[r-l+1];     //tmp array
    int m=(l+r)/2, i=l,j=m+1,k=0;
    while(i<=m && j<=r)
    {
        if(a[i]<=a[j]) tmp[k++]=a[i++];
        else tmp[k++]=a[j++];
    }
    while(i<=m) tmp[k++]=a[i++];
    while(j<=r) tmp[k++]=a[j++];

    for(int i=l,k=0;i<=r;) a[i++]=tmp[k++];
}
void MERGESORT(int a[],int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        MERGESORT(a,l,m);
        MERGESORT(a,m+1,r);
        MERGE(a,l,r);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    MERGESORT(a,0,n-1);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}
