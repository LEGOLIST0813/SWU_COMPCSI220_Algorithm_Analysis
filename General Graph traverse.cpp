#include<bits/stdc++.h>
using namespace std;
int a[100][100];
char color[100];
int pred[100];
int grey=0,white=0,choose_grey;
void VISIT(int a[][100],int n,int s);

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
        if(color[s]=='W') VISIT(a,n,s);

    /*return the pred[]*/
    for(int i=0;i<n;i++) printf("%d",pred[i]);
    return 0;
}

void VISIT(int a[][100],int n,int s)    //node s of digraph G
{
    int k,i;
    /*color[s]=grey,pred[s]=NULL*/

    color[s]='G';
    pred[s]=-1;
    grey++;     //record the remaining amount of grey node
    choose_grey=s; //the previous grey node is recorded;

    /*if there exists grey node*/
    while(grey>0)
    {
        //choose a grey node choose_grey
        for(i=0;i<n;i++)
            if(color[i]=='G')
            {
                choose_grey=i;
                break;
            }
        //find the white node of choose_grey
        for(k=0;k<n;k++)
        {
            //if choose_grey has white out-neighbour v
            if(a[choose_grey][k]==1 && color[k]=='W')
            {
                color[k]='G'; //turn v to grey
                grey++;
                pred[k]=choose_grey; //pred[v]=u
                break;
            }
        }
        if(k==n)    //如果遍历完这个grey node的所有邻接点没有白色的话，就变成黑色，灰色的点数就少1
        {
            color[choose_grey]='B';
            grey--;
        }
    }

}


