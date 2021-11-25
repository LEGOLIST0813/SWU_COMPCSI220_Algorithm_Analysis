#include<bits/stdc++.h>
using namespace std;

/*Binary Search in a sorted list of records*/
int binary_search(int a[],int key,int l,int r)
{
    int mid=0;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(a[mid]<key) l=mid+1; //search right tail
        else if(a[mid]>key) r=mid-1;    //search left tail
        else return mid;
    }
    return -1;
}

int main()
{
    int a[16]={7,14,27,33,42,49,51,53,67,70,77,81,89,94,95,99};
    int number=binary_search(a,51,0,15);
    printf("%d",number);
    return 0;
}
