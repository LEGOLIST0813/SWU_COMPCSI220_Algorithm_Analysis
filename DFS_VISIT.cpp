//Author: Hellen Lee
#include<bits/stdc++.h>
using namespace std;

stack<int> S;
int a[100][100];
char color[100];
int pred[100],seen[100],done[100];
int t;
void DFSVISIT(int s,int n);

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
    }
    /*traverse the graph*/
    for(int s=0;s<n;s++)
        if(color[s]=='W') DFSVISIT(s,n);

    /*return the pred[],seen[],done[]*/
    printf("pred[i]:\n");
    for(int i=0;i<n;i++) printf("%d ",pred[i]);

    printf("\n\nseen[i]/done[i]:\n");
    for(int i=0;i<n;i++) printf("%d/%d ",seen[i],done[i]);

    return 0;
}

void DFSVISIT(int s,int n)
{
    int u,v;

    color[s]='G';
    seen[s]=t;t++;
    pred[s]=-1;
    S.push(s);

    while(!S.empty())
    {
        u=S.top();
        for(v=0;v<n;v++)
        {
            /*if there is a white out-neighbour v*/
            if(a[u][v]==1 && color[v]=='W')
            {
                color[v]='G';
                pred[v]=u;
                seen[v]=t;t++;
                S.push(v);
                break;
            }
        }
        if(v==n)
        {
            S.pop();
            color[u]='B';
            done[u]=t;t++;
        }

    }

}
