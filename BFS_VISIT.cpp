/*Author:Hellen_Lee*/
#include<bits/stdc++.h>

using namespace std;

queue<int> Q;
int a[100][100];
char color[100];
int pred[100];
int d[100];
void BFSVISIT(int s,int n);

int main()
{
    int n;
    scanf("%d",&n);//the order of a graph

    /*store the graph:adjacent matrix*/
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
                scanf("%d",&a[i][j]);
        }
        color[i]='W';    //initialize every node in graph is white
        d[i]=0; //initialize every node distance from source is 0
    }

    /*traverse the graph*/
    for(int s=0;s<n;s++)
        if(color[s]=='W') BFSVISIT(s,n);

    /*return the pred[],seen[],done[]*/
    printf("pred[i]:\n");
    for(int i=0;i<n;i++) printf("%d ",pred[i]);

    printf("\nd[i]:\n");
    for(int i=0;i<n;i++) printf("%d ",d[i]);

    return 0;
}

void BFSVISIT(int s,int n)
{
    int u,v;
    /*operations on the first node s*/
    color[s]='G';
    pred[s]=-1;
    Q.push(s);  //push the first node s in the queue

    while(!Q.empty())
    {
        /*choose the oldest node in the queue*/
        u=Q.front();
        /*for each v adjacent to u,turn all v to grey*/
        for(v=0;v<n;v++)
        {
            if(a[u][v]==1 && color[v]=='W')
            {
                color[v]='G';   //turn it to grey
                pred[v]=u;  //record the parent
                d[v]=d[u]+1;    //update the distance of node v
                Q.push(v);  //insert it to the queue
            }
        }

        /*no white node adjacent to the u*/
        Q.pop();    //delete the node in the queue
        color[u]='B';   //turn the node to black
    }
}
