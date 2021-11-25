#include<bits/stdc++.h>
using namespace std;
int const N=10e6;
int a[N];
void DeleteMax(int a[],int n)
{
    swap(a[0],a[n-1]);
    int k=0,i=0,j=0;    //初始位置,i,j为左右子节点
    while((2*k+1)<n)       //自顶向下调整,到叶子节点停止
    {
        i=2*k+1;
        j=2*k+2;
        if(a[k]<a[i] || a[k]<a[j])  //如果当前节点比左右两边的节点小，交换一个更大的
        {
            if(a[i]>=a[j]){swap(a[i],a[k]);k=i;}
            else{swap(a[j],a[k]);k=j;}
        }
        else{break;}
    }
}
int main()
{
    int a[10]={39,25,37,18,20,32,13,3,14,6};
    DeleteMax(a,10);
    for(int i=0;i<9;i++) printf("%d ",a[i]);
    return 0;
}
